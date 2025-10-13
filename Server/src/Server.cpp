#include "Server.hpp"
#include "Room.hpp"

namespace srv
{


Server *Server::_instance = nullptr;



Server::Server(int port) : _io_context(), _port(port)
{
    _instance = this;
    _clients.clear();
    _threads.clear();
    //_server_tcp = std::make_shared<ServerTcpAsync>(this->_io_context, port);
    _server_udp = std::make_shared<ServerUdpAsync>(this->udp_context, port);
    //_thread_context = std::make_unique<std::thread>([this](){this->_io_context.run();});
    _thread_context_udp = std::make_unique<std::thread>([this](){this->udp_context.run();});

    this->_room = std::make_shared<Room>();
    _thread_context_udp->detach();
    //_thread_context->detach();
}

Server::~Server()
{

}

void Server::run()
{
    this->_io_context.run();
    //_server_tcp = std::make_shared<sfge::ServerTcpAsync>(this->_io_context, this->_port);
    //_server_udp = std::make_shared<ServerUdpAsync>(this->_port);
}


bool Server::executeCommandTCP()
{
    if (this->_msg_queue_tcp.empty()) {
        return false;
    } else {
        
        if (this->_msg_queue_tcp.front().message.find("exit") != std::string::npos) {
            this->_io_context.stop();
            return true;
        } else if (this->_msg_queue_tcp.front().message.find("create room") != std::string::npos) {
            this->createRoom(this->_msg_queue_tcp.front()._client);
            return false;
        }
        this->_msg_queue_tcp.pop();
    }
    return false;
}



void Server::start(void)
{
    while (true)
    {
        ////////std::coutthis->_udpconnection.size() << std::endl;
        if (this->executeCommandTCP() == true) {
            break;
        }
        if (!this->_msg_queue_udp.empty()) {
            //////std::cout"je push" << std::endl;
    
            this->_room->addMessage(this->_msg_queue_udp.front());
            this->_msg_queue_udp.pop();
            //////std::cout"j'ai fini de pop" << std::endl;
        }
        if (!this->_msg_queue_tcp.empty()) {
            this->_room->addMessageTcp(this->_msg_queue_tcp.front());
            this->_msg_queue_tcp.pop();
        }
    }
}


Server *Server::getInstance(int port)
{
    if (_instance == nullptr) {
        //////std::cout"instance is null" << std::endl;
        new Server(port);
        //////std::cout"instance created" << std::endl;
    }
    return _instance;
}


void Server::joinRoom(std::shared_ptr<Connection> cli)
{
    if (this->_room.get() == nullptr) {
        this->_room = std::make_shared<Room>();
        //////std::cout"create room" << std::endl;
        if (this->_room.get() != nullptr) {
            //////std::cout"ptdr je suis nill" << std::endl;
            this->_room->_clients.push_back(cli);
            ////std::cout"client added to room" << std::endl;
        }

    } else {
        this->_room->_clients.push_back(cli);
        //////std::cout"client added to room" << std::endl;
    }
}


Server *Server::getInstance(void)
{
    if (_instance == nullptr) {
        //////std::cout" recup instance is null" << std::endl;;
    }
    return _instance;
}

void Server::createRoom(std::shared_ptr<ServerClient> client)
{


}
}

void ServerClient::operator=(ServerClient &client)
{

}

ServerClient::ServerClient(boost::asio::io_context &context) : socket(context)
{

}

ServerClient::~ServerClient()
{

}

