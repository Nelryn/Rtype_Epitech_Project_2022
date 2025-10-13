/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ClientTcpAsync
*/

#include "ClientTcpAsync.hpp"

ClientTcpAsync::ClientTcpAsync(std::string addr, int port) : _socket(_ioc),
    _endpoint(boost::asio::ip::make_address(addr.c_str()), port)
{
    //_endpoint.address(boost::asio::ip::make_address(addr.c_str()));
    //_endpoint.port(port);
    this->_th = std::make_shared<std::thread>(&ClientTcpAsync::run, this);
    this->_th->detach();
    //std::cout << "begin" << std::endl;
    this->connexion();
    //std::cout << "end" << std::endl;
}

ClientTcpAsync::~ClientTcpAsync()
{
}

void ClientTcpAsync::connexion()
{
    //std::cout << "begin connection" << std::endl;
    _socket.async_connect(_endpoint, boost::bind(&ClientTcpAsync::handleConnexion,
            this, _endpoint, boost::asio::placeholders::error));
    //std::cout << "end connection" << std::endl;
}

void ClientTcpAsync::handleConnexion(tcp::endpoint endpoint, const boost::system::error_code& error)
{
    //std::cout << "handle connexion" << std::endl;
    if (!_socket.is_open()) {
        //std::cout << "close" << std::endl;
        this->connexion();
    } else if (error) {
        this->stop();
        this->connexion();
        //std::cout << "Error: " << error.message() << std::endl;
    } else {
        //std::cout << "yes" << std::endl;
        this->write("connexion");
        this->read();
    }
}

void ClientTcpAsync::read()
{
    boost::asio::async_read_until(_socket, _readBuffer, '\n',
        boost::bind(&ClientTcpAsync::handleRead, this, boost::asio::placeholders::error));
}

void ClientTcpAsync::handleRead(const boost::system::error_code& error)
{
    if (!error) {
        std::string line;
        std::istream is(&_readBuffer);
        std::getline(is, line);

        if (!line.empty()) {
            ////std::cout"Received: " << line << std::endl;
        }
        this->read();
    } else {
        std::cerr << "Error on receive: " << error.message() << std::endl;
        stop();
    }
}

void ClientTcpAsync::write(std::string message)
{
    boost::asio::async_write(_socket, boost::asio::buffer(message),
        boost::bind(&ClientTcpAsync::handleWrite, this, boost::asio::placeholders::error));
}

void ClientTcpAsync::handleWrite(const boost::system::error_code& error)
{

}


void ClientTcpAsync::stop()
{
    _socket.close();
}

void ClientTcpAsync::run()
{
    _ioc.run();
}