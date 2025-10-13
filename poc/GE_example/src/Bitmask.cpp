/*
** EPITECH PROJECT, 2022
** TGG
** File description:
** Bitmask
*/

#include "../include/Bitmask.hpp"

Bitmask::Bitmask() : _bits(0)
{
}

Bitmask::~Bitmask()
{
}

void Bitmask::SetMask(Bitmask &other)
{
    _bits = other.GetMask();
}

uint32_t Bitmask::GetMask() const
{
    return _bits;
}

bool Bitmask::GetBit(int pos) const
{
    return (_bits & (1 << pos)) != 0; // 1
}

// A simple helper method that calls set or clear bit
void Bitmask::SetBit(int pos, bool on)
{
    if (on) {
        SetBit(pos);
    } else {
        ClearBit(pos);
    }
}

void Bitmask::SetBit(int pos)
{
    _bits = _bits | 1 << pos; // 2
}

void Bitmask::ClearBit(int pos)
{
    _bits = _bits & ~(1 << pos); // 3
}

void Bitmask::Clear()
{
    _bits = 0;
}