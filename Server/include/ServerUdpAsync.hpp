/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ServerUdpAsync
*/

#ifndef SERVERUDPASYNC_HPP_
#define SERVERUDPASYNC_HPP_

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include <vector>

#include "ConnectionUdp.hpp"
#include "Connection.hpp"
#include "Message.hpp"

class Server;

//typedef struct packet packet_t;

class ServerUdpAsync {
    public:
    /**
     * @brief Construct a new Server Udp Async object
     * 
     * @param context 
     * @param port 
     */
        ServerUdpAsync(boost::asio::io_context &context, int port);
        /**
         * @brief Destroy the Server Udp Async object
         * 
         */
        
        ~ServerUdpAsync();

        /**
         * @brief Reiceive a message
         * 
         */

        void receiveMsgAsync();
        /**
         * @brief Send a message
         * 
         * 
         * 
         * @param message 
         */
        void sendMsgAsync(std::string message);
        /**
         * @brief callback when a message is received
         * 
         * @param error 
         */
        void handleReceive(const boost::system::error_code& error);
        /**
         * @brief callback when a message is sent
         * 
         * @param error 
         */
        void handleSend(boost::shared_ptr<std::string> message, boost::system::error_code const &error, std::size_t bytes_transferred);
        
        /**
         * @brief run the udp server
         * 
         */
        void run();


        /**
         * @brief register a connection to the server
         * 
         * @param endpoint 
         * @return std::shared_ptr<Connection> 
         */
        std::shared_ptr<Connection> getClient(const unsigned char id, boost::asio::ip::udp::endpoint &endpoint);
        

        /**
         * @brief remove a connection from the server
         * 
         * @param id
         */
        void rmClient(unsigned char &id);
        /**
         * @brief send a packet to a client
         * 
         * @param cli 
         * @param packet 
         */
        void sendPacketAsync(std::shared_ptr<Connection> cli, packet_t &packet);


        std::vector<std::shared_ptr<ConnectionUdp>> _connections;
        std::vector<boost::asio::ip::udp::endpoint> _endpClient;

    protected:
    private:
        int idmax = 1;
        boost::asio::io_context _ioc;
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
        boost::array<char, 512> _recvBuffer;
        boost::array<char, 512> _sendBuffer;

};

#endif /* !SERVERUDPASYNC_HPP_ */
