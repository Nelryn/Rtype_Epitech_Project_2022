/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ServerTcpAsync
*/

#ifndef SERVERTCPASYNC_HPP_
#define SERVERTCPASYNC_HPP_

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <string>
#include <list>
#include <vector>
#include <queue>

class ServerClient;
class Server;

class ServerTcpAsync {
    public:
    /**
     * @brief Construct a new Server Tcp Async object
     * 
     * @param context 
     * @param port 
     */
        ServerTcpAsync(boost::asio::io_context& context, std::uint64_t port);
       

       /**
        * @brief Destroy the Server Tcp Async object
        * 
        */
        ~ServerTcpAsync();

        /**
         * @brief callback when a message is received
         * 
         * @param conn 
         * @param err 
         * @param byte_type 
         */

        
        void handle_read(std::list<std::shared_ptr<ServerClient>>::iterator conn, boost::system::error_code const & err, size_t byte_type);
        /**
         * @brief callback when a message is sent
         * 
         * @param conn 
         * @param err 
         * @param byte_type 
         */
        void handle_write(std::list<std::shared_ptr<ServerClient>>::iterator, std::shared_ptr<std::string> msg_buffer, boost::system::error_code const &err);
        
        /**
         * @brief callback when a client is accepted
         * 
         * @param conn 
         * @param err 
         */
        void handle_accept(std::list<std::shared_ptr<ServerClient>>::iterator conn, boost::system::error_code const &err);


        /**
         * @brief send a message to a client
         * 
         * @param conn 
         * @param message 
         * @param ec 
         */
        void async_write(std::list<std::shared_ptr<ServerClient>>::iterator conn, std::string message, boost::system::error_code ec);
        
        /**
         * @brief read a message from a client
         * 
         * @param conn 
         */
        void async_read(std::list<std::shared_ptr<ServerClient>>::iterator conn);
        
        /**
         * @brief accept a new client
         * 
         */
        void start_accept();

        std::string pollEvent();

        void run();

    protected:
    private:
        std::queue<std::string> msg_queue;
        boost::asio::ip::tcp::acceptor acceptor_;
        boost::asio::io_context& io_context_;
};


#endif /* !SERVERTCPASYNC_HPP_ */
