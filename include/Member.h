#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
    Member(int id, const std::string &name, const std::string &address);

    int getId() const;
    std::string getName() const;
    std::string getAddress() const;

private:
    int id;
    std::string name;
    std::string address;
};

#endif
