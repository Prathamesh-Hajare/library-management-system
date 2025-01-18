#include "../include/Transaction.h"

Transaction::Transaction(int bookId, int memberId, const std::string &type)
    : bookId(bookId), memberId(memberId), type(type) {}

int Transaction::getBookId() const
{
    return bookId;
}

int Transaction::getMemberId() const
{
    return memberId;
}

std::string Transaction::getType() const
{
    return type;
}
