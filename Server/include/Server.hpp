#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <list>
#include <memory>
#include <thread>
#include <queue>
#include <mutex>
#include <string>
#include "ServerTcpAsync.hpp"
#include "ServerUdpAsync.hpp"
#include "Connection.hpp"
#include "Room.hpp"
#include "Message.hpp"
#include "MessageTcp.hpp"


//class MessageTcp
//{
//    public:
//        MessageTcp(std::shared_ptr<ServerClient> client);
//        ~MessageTcp();
//        std::shared_ptr<ServerClient> _client;
//        Type type;
//        std::string message;
//
//};

namespace srv {

class Server
{
    public:

        std::list<std::shared_ptr<ServerClient>> _clients;
        std::queue<MessageTcp> _msg_queue_tcp;
        std::queue<Message> _msg_queue_udp;
        std::vector<std::thread> _threads;
        std::unique_ptr<std::thread> _thread_context;
        std::unique_ptr<std::thread> _thread_context_udp;

        std::vector<std::shared_ptr<Connection>> _udpconnection;

        boost::asio::io_context _io_context;
        boost::asio::io_context udp_context;

        std::shared_ptr<Room> _room;



        int _port;

        std::shared_ptr<ServerTcpAsync> _server_tcp;

        std::shared_ptr<ServerUdpAsync> _server_udp;

        /**
         * @brief Destroy the Server object
         * 
         */

        ~Server();

        //void operator=(Server &server) = delete;


        /**
         * @brief Get the Instance object
         * 
         * @param port 
         * @return Server* 
         */
        static Server *getInstance(int port);

        /**
         * @brief Get the Instance object
         * 
         * @return Server* 
         */
        static Server *getInstance();



        /**
         * @brief add the client to the list of client
         * 
         * @param client 
         */
        void addClient(std::shared_ptr<ServerClient> client);
        /**
         * @brief remove the client from the list of client
         * 
         * @param client 
         */
        void removeClient(std::shared_ptr<ServerClient> client);


        /**
         * @brief Add tcp message to the queue
         * 
         * @param msg 
         */
        void addTcpMessage(Message msg);
        /**
         * @brief add a udp message to the queue
         * 
         * @param msg 
         */
        void addUdpMessage(Message msg);

        /**
         * @brief Create a Room
         * 
         * @param client 
         */

        void createRoom(std::shared_ptr<ServerClient> client);
        /**
         * @brief connect a player to a room
         * 
         * @param client 
         */
        void joinRoom(std::shared_ptr<Connection> client);
        /**
         * @brief remove a player from a room
         * 
         * @param client 
         */
        void leaveRoom(std::shared_ptr<ServerClient> client);


        /**
         * @brief execute a tcp (not used already use by run)
         * 
         * @return true 
         * @return false 
         */

        bool executeCommandTCP(void);

        /**
         * @brief start the server
         * 
         */
        void start();

        //Server(Server &server) = delete;
        static Server *_instance;
        /**
         * @brief Construct a new Server object
         * 
         * @param port 
         */
        Server(int port);

        /**
         * @brief run the server
         * 
         */
        void run();


    private:

    protected:




};
}





