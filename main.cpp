#include "./include/Library.h"
#include <iostream>
#include <string>

void showMenu()
{
    std::cout << "Library Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add Member\n";
    std::cout << "3. Issue Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Show All Books\n";
    std::cout << "6. Show All Members\n";
    std::cout << "7. Save Data\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main()
{
    Library library("data/books.txt", "data/members.txt", "data/transactions.txt");

    library.loadData();

    int choice;
    bool running = true;
    while (running)
    {
        showMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Add book
            int id;
            std::string title, author;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            std::cin.ignore(); // to ignore the leftover newline character
            std::cout << "Enter Book Title: ";
            std::getline(std::cin, title);
            std::cout << "Enter Book Author: ";
            std::getline(std::cin, author);

            library.addBook(Book(id, title, author));
            std::cout << "Book added successfully!\n";
            break;
        }
        case 2:
        {
            // Add member
            int id;
            std::string name, address;
            std::cout << "Enter Member ID: ";
            std::cin >> id;
            std::cin.ignore(); // Ignore leftover newline after reading id
            std::cout << "Enter Member Name: ";
            std::getline(std::cin, name); // Read the entire name
            std::cout << "Enter Member Address: ";
            std::getline(std::cin, address); // Read the entire address

            library.addMember(Member(id, name, address));
            std::cout << "Member added successfully!\n";
            break;
        }

        case 3:
        {
            // Issue book
            int bookId, memberId;
            std::cout << "Enter Book ID to issue: ";
            std::cin >> bookId;
            std::cout << "Enter Member ID to issue book to: ";
            std::cin >> memberId;

            if (library.issueBook(bookId, memberId))
            {
                std::cout << "Book issued successfully.\n";
            }
            else
            {
                std::cout << "Failed to issue book.\n";
            }
            break;
        }
        case 4:
        {
            // Return book
            int bookId, memberId;
            std::cout << "Enter Book ID to return: ";
            std::cin >> bookId;
            std::cout << "Enter Member ID to return book from: ";
            std::cin >> memberId;

            if (library.returnBook(bookId, memberId))
            {
                std::cout << "Book returned successfully.\n";
            }
            else
            {
                std::cout << "Failed to return book.\n";
            }
            break;
        }
        case 5:
            // Show all books
            std::cout << "Books in the library:\n";
            for (const auto &book : library.getAllBooks())
            {
                std::cout << "ID: " << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << "\n";
            }
            break;
        case 6:
            // Show all members
            std::cout << "Library members:\n";
            for (const auto &member : library.getAllMembers())
            {
                std::cout << "ID: " << member.getId() << ", Name: " << member.getName() << ", Address: " << member.getAddress() << "\n";
            }
            break;
        case 7:
            // Save data
            library.saveData();
            std::cout << "Data saved successfully!\n";
            break;
        case 8:
            // Exit
            running = false;
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
