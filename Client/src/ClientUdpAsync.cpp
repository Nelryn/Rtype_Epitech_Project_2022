/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ClientUdpAsync
*/

#include "ClientUdpAsync.hpp"
#include "EntityManager.hpp"
#include "Core.hpp"

ClientUdpAsync::ClientUdpAsync(std::string addr, int port) :
    _socket(_ioc), _endpoint(boost::asio::ip::make_address(addr.c_str()), port)
{
    _socket.connect(_endpoint);
    while (_socket.is_open() == false) {
        _socket.open(boost::asio::ip::udp::v4());
    }
    packet_t pac;
    pac.magic[0] = 'E';
    pac.magic[1] = 'L';
    pac.magic[2] = 'F';
    pac.uid = 0;
    pac.idCommand = 0;
    pac.data = 0;
    //std::memset(&pac, 0, sizeof(packet_t));
    std::cout << "creé moi" << std::endl;
    sendPacket(pac);
    this->thx = std::make_shared<std::thread>(&ClientUdpAsync::run, this);
    this->thx->detach();
    this->receiveMsgAsync();
}

ClientUdpAsync::~ClientUdpAsync()
{

}

void ClientUdpAsync::receiveMsgAsync()
{
    //////std::cout_endpoint << std::endl;
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer), _endpoint, boost::bind(&ClientUdpAsync::handleReceive, this, boost::asio::placeholders::error));
}

void ClientUdpAsync::sendMsgAsync(std::string message)
{
    boost::shared_ptr<std::string> msg(new std::string(message));
    _socket.async_send_to(boost::asio::buffer(*msg), _endpoint, boost::bind(&ClientUdpAsync::handleSend, this, msg, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void ClientUdpAsync::handleReceive(const boost::system::error_code& error)
{
    // std::cout << "handleReceive: " << std::endl;
    if (error == boost::asio::error::eof)
        _ioc.stop();
    else if (error)
        std::cerr << "Error message: " << error.message() << std::endl;

    if (error.message().compare("Connection refused") == 0)
        exit(84);

    if (!error) {
        packet_t *packet = (packet_t *)_recvBuffer.c_array();
        std::cout << "je recois : magic " <<  packet->magic << " cmd " << int(packet->idCommand) << " data " << int(packet->data)  << " uid " << int(packet->uid) << std::endl;
        std::string magic = packet->magic;
        if (packet->magic[0] == 'E' &&  packet->magic[1] == 'L' && packet->magic[2] == 'F' && int(packet->idCommand) == 0) {
            //std::cout << "set id : " << int(packet->uid) << std::endl;
            std::memcpy(&this->id, &packet->uid, sizeof(unsigned char));
            for (auto &i: sfge::EntityManager::getInstance()->getEntities()) {
                if (i->getId() == sfge::Core::getInstance()->idPlayer) {
                    sfge::EntityManager::getInstance()->getEntity(i->getId())->setUid(packet->uid);
                    //std::cout << " uid " << int(packet->uid) << std::endl;
                }
            }
            //std::cout << "set id : " << int(this->id) << std::endl;
        } else {
            std::cout << "add stack" << std::endl;
            this->addPacket(*packet);
        }
        //std::cout << "myId: " << int(id) << std::endl;
        _recvBuffer.assign(0);
    }
    this->receiveMsgAsync();
}

void ClientUdpAsync::addPacket(packet_t packet)
{
    //////std::cout"je push" << std::endl;
    this->mtx.lock();
    this->pkt_queue.push(packet);
    this->mtx.unlock();
}

void ClientUdpAsync::sendPacket(packet_t packet)
{
    packet.magic[0] = 'E';
    packet.magic[1] = 'L';
    packet.magic[2] = 'F';
    packet.uid = this->id;
    ////std::cout"sending packet: " <<  packet.id << std::endl;
    boost::shared_ptr<std::string> msg(new std::string((char *)&packet, sizeof(packet_t)));
    //std::cout << "j'envoie : magic " << packet.magic << " cmd " << int(packet.idCommand) << " data " << int(packet.data)  << " uid " << int(packet.uid) << std::endl;
    _socket.async_send_to(boost::asio::buffer(*msg), _endpoint, boost::bind(&ClientUdpAsync::handleSend, this, msg, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

packet_t ClientUdpAsync::pollEvent()
{
    if (!this->pkt_queue.empty()) {
        packet_t pack = this->pkt_queue.front();
        this->pkt_queue.pop();
        return (pack);
    } else {
        packet_t pack;
        std::memset(&pack, -1, sizeof(packet_t));
        return pack;
    }
}

void ClientUdpAsync::handleSend(boost::shared_ptr<std::string> message, boost::system::error_code const &error, std::size_t bytes_transferred)
{
    if (error == boost::asio::error::eof)
        _ioc.stop();
    else if (error)
        std::cerr << "Error message: " << std::endl;
    else
        this->receiveMsgAsync();
}

void ClientUdpAsync::run()
{
    _ioc.run();
}

std::queue<packet_t> ClientUdpAsync::getPacket() const
{
    return this->pkt_queue;
}

unsigned char ClientUdpAsync::getId() const
{
    return id;
}

void ClientUdpAsync::manageEvent(sf::Event event)
{
    packet_t packet;
    packet.idCommand = 3;

    if (event.type == event.KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            packet.data = 'a';
            this->sendPacket(packet);
        }
        if (event.key.code == sf::Keyboard::Down) {
            packet.data = 'b';
            this->sendPacket(packet);
        }
        if (event.key.code == sf::Keyboard::Right) {
            packet.data = 'c';
            this->sendPacket(packet);
        }
        if (event.key.code == sf::Keyboard::Left) {
            packet.data = 'd';
            this->sendPacket(packet);
        }
    }
}