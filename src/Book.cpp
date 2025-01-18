#include "../include/Book.h"

Book::Book(int id, const std::string &title, const std::string &author, bool isIssued)
    : id(id), title(title), author(author), isIssued(isIssued) {}

int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

bool Book::getIsIssued() const
{
    return isIssued;
}

void Book::issue()
{
    isIssued = true;
}

void Book::returnBook()
{
    isIssued = false;
}
