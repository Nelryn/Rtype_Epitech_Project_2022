/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ServerUdpAsync
*/

#include "ServerUdpAsync.hpp"
#include "Server.hpp"
#include "Message.hpp"


ServerUdpAsync::ServerUdpAsync(boost::asio::io_context &_context, int port) : 
    _socket(_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
{
    //////std::cout"udp listening on port: " << port << std::endl;
    //_socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    idmax = 1;
    this->receiveMsgAsync();
}

ServerUdpAsync::~ServerUdpAsync()
{

}

void ServerUdpAsync::receiveMsgAsync()
{
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer), _endpoint, boost::bind(&ServerUdpAsync::handleReceive, this, boost::asio::placeholders::error));
}

void ServerUdpAsync::handleReceive(const boost::system::error_code& error)
{

    std::shared_ptr<Connection> conn;

    if (!error) {
        const packet_t *pack = (packet_t *)_recvBuffer.c_array();

        std::cout << "received : magic " << pack->magic << " cmd " << int(pack->idCommand) << " from " << int(pack->uid) << " data " << int(pack->data) << std::endl;

        if (pack->magic[0] == 'E' &&  pack->magic[1] == 'L' && pack->magic[2] == 'F') {
            if (int(pack->idCommand) == 0) {
                packet_t assign;
                assign.magic[0] = 'E';
                assign.magic[1] = 'L';
                assign.magic[2] = 'F';
                assign.idCommand = 0;
                assign.uid = this->idmax;
                assign.data = 0;
                std::shared_ptr<Connection> newconn = this->getClient(assign.uid, _endpoint);
                sendPacketAsync(newconn, assign);
                packet_t add;
                add.idCommand = 1;
                add.uid = this->idmax;
                add.data = 0;
                Message mess(newconn);
                mess.packet.magic[0] = 'E';
                mess.packet.magic[1] = 'L';
                mess.packet.magic[2] = 'F';
                mess.packet.uid = this->idmax;
                mess.packet.idCommand = 1;
                mess.packet.data = 0;
                this->idmax++;
                srv::Server::getInstance()->_room->addMessage(mess);
            } else {
                std::shared_ptr<Connection> conn = this->getClient(pack->uid, _endpoint);
                Message msg(conn);
                std::memcpy(&msg.packet.magic, &pack->magic, 3);
                std::memcpy(&msg.packet.uid, &pack->uid, 1);
                std::memcpy(&msg.packet.idCommand, &pack->idCommand, 1);
                std::memcpy(&msg.packet.data, &pack->data, 1);
                srv::Server::getInstance()->_room->addMessage(msg);
            }
        }
        _recvBuffer.assign(0);
    } else {
        std::cerr << "Error message: " << error.message() << std::endl;
    }
    this->receiveMsgAsync();
}

void ServerUdpAsync::sendMsgAsync(std::string message)
{
    boost::shared_ptr<std::string> msg(new std::string(message));
    _socket.async_send_to(boost::asio::buffer(*msg), _endpoint, boost::bind(&ServerUdpAsync::handleSend, this, msg, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void ServerUdpAsync::sendPacketAsync(std::shared_ptr<Connection> cli, packet_t &packet)
{
    boost::shared_ptr<std::string> msg(new std::string((char *)&packet, sizeof(packet_t)));
    std::cout << "send packet: magic " << packet.magic << " cmd " <<  int(packet.idCommand) <<  " to " << int(packet.uid) << " data " << int(packet.data) << std::endl;
    ////std::cout << "send pac: " <<  packet.idCommand <<  " to " << packet.uid << std::endl;
    ////std::cout << "message send: " << msg->data() << std::endl;
    this->_socket.async_send_to(boost::asio::buffer(*msg), cli->_endpoint, boost::bind(&ServerUdpAsync::handleSend, this, msg, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void ServerUdpAsync::handleSend(boost::shared_ptr<std::string> message, boost::system::error_code const &error, std::size_t bytes_transferred)
{
    if (!error) {
        this->receiveMsgAsync();
        return;
    } else {
        std::cerr << "Error: " << error.message() << std::endl;
        //rmClient();
    }
}

void ServerUdpAsync::run()
{
    _ioc.run();
}

std::shared_ptr<Connection> ServerUdpAsync::getClient(const unsigned char id, boost::asio::ip::udp::endpoint &endpoint)
{
    for (auto &cli : srv::Server::getInstance()->_udpconnection)  {
        ////std::coutint(cli->id) <<  " : " << int(id) << std::endl;
        if (cli->idCli == id) {
            //std::cout << "endpoint no change: " << cli->_endpoint << std::endl;
            cli->_endpoint = endpoint;
            //std::cout << "endpoint change: " << cli->_endpoint << std::endl;
            return (cli);
        }
    }
    ////std::cout"new conn" << std::endl;
    std::shared_ptr<Connection> conn = std::make_shared<Connection>(id, endpoint);
    conn->idCli = id;
    ////std::cout"| " << int(conn->id) << " | " << std::endl;
    srv::Server::getInstance()->_udpconnection.push_back(conn);
    srv::Server::getInstance()->_room->_clients.push_back(conn);
    return (conn);
}

void ServerUdpAsync::rmClient(unsigned char &id)
{
    for (auto &cli : srv::Server::getInstance()->_udpconnection)  {
        if (cli->idCli == id) {
            return;
        }
    }
}