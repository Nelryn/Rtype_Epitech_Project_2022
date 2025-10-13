#include "MessageTcp.hpp"


MessageTcp::MessageTcp(std::shared_ptr<ServerClient> client)
{
    _client = client;
}

MessageTcp::~MessageTcp()
{

}