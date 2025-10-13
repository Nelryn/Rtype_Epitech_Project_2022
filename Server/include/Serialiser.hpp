
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/endian/conversion.hpp>


enum SerialType {
    NONE
};


class Serialisable {
    public:
        uint8_t type = NONE;
        Serialisable() = default;
        Serialisable(uint8_t type) : type(type) {}

        virtual std::vector<uint8_t> serialise() = 0;
        virtual void deserialise(std::vector<uint8_t> data) = 0;

};

class Serialiser
{
public:
    size_t offset = 0;
    std::vector<uint8_t> _data;



    Serialiser() = default;
    Serialiser(const std::vector<uint8_t>&data) : _data(std::move(data)), offset(0)
    {

    }
    ~Serialiser() {
        _data.clear();
    }

    void serialize(const uint8_t *data, std::size_t size) {
        checkSize(size);
        _data.insert(_data.end(), data, data + size);
        offset += size;
    }

    std::vector<uint8_t> getBytes(std::size_t size) {
        checkSize(size);
        std::vector<uint8_t> bytes(_data.begin() + offset, _data.begin() + offset + size);
        offset += size;
        return bytes;
    }

    template<typename T, std::enable_if<std::is_integral<T>::value, int>::type = 0>
    Serialiser& operator<<(const T& data) {
        T _data = boost::endian::native_to_big(data);
        serialize(reinterpret_cast<const uint8_t*>(&data), sizeof(T));
        return *this;
    }

    template<typename T, std::enable_if<std::is_integral<T>::value, int>::type = 0>
    Serialiser& operator>>(T& data) {
        checkSize(sizeof(T));
        data = boost::endian::big_to_native(*reinterpret_cast<T*>(_data.data() + offset));
        return *this;
    }


private:
    void checkSize(size_t size) {
        if (offset + size > _data.size()) {
            throw std::runtime_error("Not space in buffer");
        }
    }

};
