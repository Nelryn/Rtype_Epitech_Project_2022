
#pragma once

#include <string>

#include "Serialiser.hpp"

struct MessageTEST : public Serialisable {

    

    MessageTEST() : Serialisable(0) {}

    std::vector<uint8_t> serialise() override {
        Serialiser serialiser;
        serialiser << type;
        return serialiser._data;
    }

    void deserialise(std::vector<uint8_t> data) override {
        Serialiser serialiser(data);
        serialiser >> type;
    }

};
