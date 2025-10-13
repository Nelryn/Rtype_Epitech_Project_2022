#include "Message.hpp"

Message::Message(std::shared_ptr<Connection> cli)
{
    this->_client = cli;
}

Message::~Message()
{

}
