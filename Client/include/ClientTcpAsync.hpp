/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ClientTcpAsync
*/

#ifndef CLIENTTCPASYNC_HPP_
#define CLIENTTCPASYNC_HPP_

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

using boost::asio::ip::tcp;

class ClientTcpAsync {
    public:
        ClientTcpAsync(std::string addr, int port);
        ~ClientTcpAsync();

        void connexion();
        void handleConnexion(tcp::endpoint endpoint, const boost::system::error_code& error);
        void read();
        void handleRead(const boost::system::error_code& error);
        void write(std::string message);
        void handleWrite(const boost::system::error_code& error);
        void stop();
        void run();

        std::shared_ptr<std::thread> _th;

    protected:
    private:
        boost::asio::io_context _ioc;
        tcp::socket _socket;
        tcp::endpoint _endpoint;
        boost::asio::streambuf _readBuffer;
        boost::asio::streambuf _writeBuffer;
};

#endif /* !CLIENTTCPASYNC_HPP_ */
