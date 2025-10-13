/*
** EPITECH PROJECT, 2022
** B-CPP-500-RUN-5-1-rtype-emilie.baunifais
** File description:
** ServerTcpAsync
*/

#include "ServerTcpAsync.hpp"
#include "Server.hpp"


ServerTcpAsync::ServerTcpAsync(boost::asio::io_context& context, std::uint64_t port) :
    io_context_(context), acceptor_(context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    //////std::cout"Server started on port " << port << std::endl;
    start_accept();
}

ServerTcpAsync::~ServerTcpAsync()
{
}

void ServerTcpAsync::handle_write(std::list<std::shared_ptr<ServerClient>>::iterator conn, std::shared_ptr<std::string> msg_buff, boost::system::error_code const &err)
{
    if (!err) {
        if (conn->get()->socket.is_open()) {
            //////std::cout"j'écris" << std::endl;
        }
    } else {
        std::cerr << "error: " << err.message() << std::endl;
        srv::Server::getInstance()->_clients.erase(conn);
    }

}

void ServerTcpAsync::handle_read(std::list<std::shared_ptr<ServerClient>>::iterator conn, boost::system::error_code const & err, size_t byte_transferd)
{
    
    if (byte_transferd > 0) {
        MessageTcp msg(*conn);
        std::istream is(&conn->get()->buff);
        std::string line;
        std::getline(is, line);
        msg.message = line;
        //std::cout << "message: " << line << std::endl;
        //std::cout << line << std::endl;
        srv::Server::getInstance()->_msg_queue_tcp.push(msg);
    }
    if (!err) {
        async_read(conn);
    } else {
        std::cerr << "error: " << err.message() << std::endl;
        srv::Server::getInstance()->_clients.erase(conn);
    }
}

void ServerTcpAsync::async_read(std::list<std::shared_ptr<ServerClient>>::iterator conn)
{
    auto handler = boost::bind(&ServerTcpAsync::handle_read, this, conn, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred);
    boost::asio::async_read_until(conn->get()->socket, conn->get()->buff, "\n", handler);
}

void ServerTcpAsync::start_accept()
{
    auto conn_handle = srv::Server::getInstance()->_clients.emplace(srv::Server::getInstance()->_clients.begin(), std::make_shared<ServerClient>(io_context_));
    auto handler = boost::bind(&ServerTcpAsync::handle_accept, this, conn_handle, boost::asio::placeholders::error);
    acceptor_.async_accept(conn_handle->get()->socket, handler);
}

void ServerTcpAsync::handle_accept(std::list<std::shared_ptr<ServerClient>>::iterator conn, boost::system::error_code const &err)
{
    if (!err) {
        auto buff = std::make_shared<std::string>("hello world\n");
        auto handler = boost::bind(&ServerTcpAsync::handle_write, this, conn, buff, boost::asio::placeholders::error);
        boost::asio::async_write(conn->get()->socket, boost::asio::buffer( *buff), handler);
        async_read(conn);
    } else {
        std::cerr << "Error: " << err.message() << std::endl;
        srv::Server::getInstance()->_clients.erase(conn);
    }
    start_accept();
}

void ServerTcpAsync::run()
{
    io_context_.run();
}

//std::string ServerTcpAsync::pollEvent()
//{
//    if (!this->msg_queue.empty()) {
//
//    }
//}
