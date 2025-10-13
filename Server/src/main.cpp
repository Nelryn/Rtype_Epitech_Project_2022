
#include "StateManager.hpp"
#include "ServerUdpAsync.hpp"
#include "ServerTcpAsync.hpp"
#include "Server.hpp"

int main()
{
    srv::Server *server = srv::Server::getInstance(4242);

    server->start();
    return 0;
}