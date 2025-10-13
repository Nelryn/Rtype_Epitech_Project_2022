/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ClientUdpAsync
*/

#ifndef CLIENTUDPASYNC_HPP_
#define CLIENTUDPASYNC_HPP_

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <vector>
#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include "Message.hpp"

class ClientUdpAsync {
    public:
        ClientUdpAsync(std::string addr, int port);
        ~ClientUdpAsync();

        void receiveMsgAsync();
        void sendMsgAsync(std::string message);
        void handleReceive(const boost::system::error_code& error);
        void handleSend(boost::shared_ptr<std::string> message, boost::system::error_code const &error, std::size_t bytes_transferred);
        packet_t pollEvent();
        void sendPacket(packet_t packet);
        void addPacket(packet_t packet);
        std::mutex mtx;
        void run();
        std::shared_ptr<std::thread> thx;
        std::queue<packet_t> getPacket() const;
        unsigned char getId() const;
        void manageEvent(sf::Event event);
    protected:
    private:
        unsigned char id = 0;
        boost::asio::io_context _ioc;
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
        std::queue<packet_t> pkt_queue;
        boost::array<char, 512> _recvBuffer;
        boost::array<char, 512> _sendBuffer;
};

#endif /* !CLIENTUDPASYNC_HPP_ */
