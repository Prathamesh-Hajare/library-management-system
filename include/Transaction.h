#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
public:
    Transaction(int bookId, int memberId, const std::string &type); // "issue" or "return"

    int getBookId() const;
    int getMemberId() const;
    std::string getType() const;

private:
    int bookId;
    int memberId;
    std::string type;
};

#endif
