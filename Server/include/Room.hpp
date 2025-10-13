


#pragma once

#include <string>
#include <boost/asio.hpp>
#include <iostream>
#include <boost/bind.hpp>
#include "Connection.hpp"
#include <queue>
#include "Message.hpp"
#include "MessageTcp.hpp"

class Server;

class Room
{
    public:
        /**
         * @brief Construct a new Room object
         *
         * 
         */
        Room();

        
        std::thread _thread;
        std::string _uuid;
        std::vector<std::shared_ptr<Connection>> _clients;
        std::vector<std::shared_ptr<ServerClient>> _clientTcp;
        std::queue<Message> _message_queue;
        std::queue<MessageTcp> _message_tcp;
        std::mutex mtx;
        std::mutex mtx_msg;

        /**
         * @brief Destroy the Room object
         *
         */
        ~Room();

        /**
         * @brief Get the Uuid of the room
         *
         * @return std::string const& 
         */

        std::string const &get_uuid();

        /**
         * @brief Get the Nb Player in the room
         * 
         * @return int 
         */

        int getNbPlayer();
        /**
         * @brief Connext a player to the room
         * 
         * @param connection 
         */
        void addConnection(std::shared_ptr<Connection> connection);
        /**
         * @brief Run the room thread (already called in the constructor)
         * 
         */
        void run();
        /**
         * @brief add a message to the room
         * 
         * @param msg 
         */
        void addMessage(Message msg);
        /**
         * @brief Start the room thread
         * 
         */
        void start();
        /**
         * @brief Stop the room thread
         * 
         */
        void stop();
        void join();
        void leave();
        void addMessageTcp(MessageTcp msg);
        void addClientTcp(std::shared_ptr<ServerClient> client);
};

