#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include <vector>
#include <string>

class Library
{
public:
    Library(const std::string &bookFile, const std::string &memberFile, const std::string &transactionFile);

    void addBook(const Book &book);
    void addMember(const Member &member);

    bool issueBook(int bookId, int memberId);
    bool returnBook(int bookId, int memberId);

    std::vector<Book> getAllBooks() const;
    std::vector<Member> getAllMembers() const;
    std::vector<Transaction> getAllTransactions() const;

    void saveData() const;
    void loadData();

private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Transaction> transactions;

    std::string bookFile;
    std::string memberFile;
    std::string transactionFile;
};

#endif
