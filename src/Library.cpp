#include "../include/Library.h"
#include <fstream>
#include <iostream>
#include <sstream>

Library::Library(const std::string &bookFile, const std::string &memberFile, const std::string &transactionFile)
    : bookFile(bookFile), memberFile(memberFile), transactionFile(transactionFile) {}

void Library::addBook(const Book &book)
{
    books.push_back(book);
}

void Library::addMember(const Member &member)
{
    members.push_back(member);
}

bool Library::issueBook(int bookId, int memberId)
{
    for (auto &book : books)
    {
        if (book.getId() == bookId && !book.getIsIssued())
        {
            book.issue();
            transactions.push_back(Transaction(bookId, memberId, "issue"));
            return true;
        }
    }
    return false;
}

bool Library::returnBook(int bookId, int memberId)
{
    for (auto &book : books)
    {
        if (book.getId() == bookId && book.getIsIssued())
        {
            book.returnBook();
            transactions.push_back(Transaction(bookId, memberId, "return"));
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::getAllBooks() const
{
    return books;
}

std::vector<Member> Library::getAllMembers() const
{
    return members;
}

std::vector<Transaction> Library::getAllTransactions() const
{
    return transactions;
}

void Library::saveData() const
{
    // Save books
    std::ofstream bookFileOut(bookFile);
    for (const auto &book : books)
    {
        bookFileOut << book.getId() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getIsIssued() << "\n";
    }

    // Save members
    std::ofstream memberFileOut(memberFile);
    for (const auto &member : members)
    {
        memberFileOut << member.getId() << " " << member.getName() << " " << member.getAddress() << "\n";
    }

    // Save transactions
    std::ofstream transactionFileOut(transactionFile);
    for (const auto &transaction : transactions)
    {
        transactionFileOut << transaction.getBookId() << " " << transaction.getMemberId() << " " << transaction.getType() << "\n";
    }
}

void Library::loadData()
{
    // Load books
    std::ifstream bookFileIn(bookFile);
    int id;
    std::string title, author;
    bool isIssued;
    while (bookFileIn >> id >> title >> author >> isIssued)
    {
        books.push_back(Book(id, title, author, isIssued));
    }

    // Load members
    std::ifstream memberFileIn(memberFile);
    std::string name, address;
    while (memberFileIn >> id >> name >> address)
    {
        members.push_back(Member(id, name, address));
    }

    // Load transactions
    std::ifstream transactionFileIn(transactionFile);
    std::string type;
    int memberId;
    while (transactionFileIn >> id >> memberId >> type)
    {
        transactions.push_back(Transaction(id, memberId, type));
    }
}
