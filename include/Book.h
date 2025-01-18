#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book(int id, const std::string &title, const std::string &author, bool isIssued = false);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getIsIssued() const;

    void issue();
    void returnBook();

private:
    int id;
    std::string title;
    std::string author;
    bool isIssued;
};

#endif
