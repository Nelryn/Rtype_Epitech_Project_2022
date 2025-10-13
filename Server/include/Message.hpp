#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>
#include "Connection.hpp"


typedef struct packet {
    char magic[3];
    unsigned char uid;
    unsigned char idCommand;
    unsigned char data;
} packet_t;

class Message
{
    public:
        Message(std::shared_ptr<Connection> client);
        ~Message();
        std::shared_ptr<Connection> _client;
        packet_t packet;
};

#endif