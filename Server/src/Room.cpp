#include "Room.hpp"
#include "Server.hpp"



Room::Room()
{
    this->_uuid = "";
    start();
}

Room::~Room()
{

}

std::string const &Room::get_uuid()
{
    return this->_uuid;
}

void Room::run()
{
    while (true) {
        if (!this->_message_queue.empty()) {
            ////std::cout << this->getNbPlayer() <<  " users "  << std::endl;
            for (auto &cl : this->_clients) {
                //std::cout << "client id " << int(cl->idCli) << " packet uuid: " << int(this->_message_queue.front().packet.uid) << std::endl;
                if (cl->idCli != this->_message_queue.front().packet.uid) {
                    srv::Server::getInstance()->_server_udp->sendPacketAsync(cl, this->_message_queue.front().packet);
                }

            }
            if (int(this->_message_queue.front().packet.idCommand) == 1) {
                std::shared_ptr<Connection> conn;
                for (auto &cli : this->_clients) {
                    if (cli->idCli == this->_message_queue.front().packet.uid) {
                        conn = std::make_shared<Connection>(cli->idCli, cli->_endpoint);
                        break;
                    }
                }
                for (auto &cli : this->_clients) {
                    if (cli->idCli != this->_message_queue.front().packet.uid) {
                        packet_t packet;
                        packet.magic[0] = 'E';
                        packet.magic[1] = 'L';
                        packet.magic[2] = 'F';
                        packet.uid = cli->idCli;
                        packet.idCommand = 1;
                        packet.data = 0;
                        //unsigned char com = 1;
                        //unsigned char data = 0;
                        //std::memcpy(&packet.uid, &cli->idCli, sizeof(unsigned char));
                        //std::memcpy(&packet.idCommand, &com, sizeof(unsigned char));
                        //std::memcpy(&packet.data, &data, sizeof(unsigned char));
                        srv::Server::getInstance()->_server_udp->sendPacketAsync(conn, packet);
                        //std::cout << "add this client: cmd " << int(packet.idCommand) << " uid " << int(packet.uid) << " data " << int(packet.data) << std::endl;
                    }
                }
            }
            this->_message_queue.pop();
        }
    }

}

int Room::getNbPlayer()
{
    return this->_clients.size();
}

void Room::start()
{
    _thread = std::thread(&Room::run, this);
    _thread.detach();
}

void Room::stop()
{
    _thread.join();
}

void Room::addMessage(Message msg)
{
    this->mtx.lock();
    ////std::cout"je push" << std::endl;
    this->_message_queue.push(msg);
    this->mtx.unlock();
}

void Room::addConnection(std::shared_ptr<Connection> connection)
{
    this->_clients.push_back(connection);
}

void Room::addMessageTcp(MessageTcp msg)
{
    this->_message_tcp.push(msg);
}

void Room::addClientTcp(std::shared_ptr<ServerClient> client)
{
    _clientTcp.push_back(client);
}