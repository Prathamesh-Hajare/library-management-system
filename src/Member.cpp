#include "../include/Member.h"

Member::Member(int id, const std::string &name, const std::string &address)
    : id(id), name(name), address(address) {}

int Member::getId() const
{
    return id;
}

std::string Member::getName() const
{
    return name;
}

std::string Member::getAddress() const
{
    return address;
}
