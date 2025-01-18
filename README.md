# Library Management System

## Overview

The **Library Management System** is a C++ based console application that helps in managing a library by providing features like adding books, adding members, issuing and returning books, and saving data. The system supports dynamic loading and saving of data from and to text files.

## Features

- **Add Books:** Add new books to the library with details such as title, author, and book ID.
- **Add Members:** Add new library members with details like name, address, and member ID.
- **Issue Books:** Issue books to members, ensuring that a book is available before issuing it.
- **Return Books:** Return books that are issued and update their status accordingly.
- **Save and Load Data:** Automatically save library data (books, members, and transactions) to text files and load data when the application starts.

## Requirements

- C++ Compiler (e.g., g++, MinGW)
- Standard C++ Libraries

## File Structure

```bash
LibraryManagementSystem/
│
├── src/                    # Source files
│   ├── Library.cpp          # Implementation of Library class
│   ├── Book.cpp             # Implementation of Book class
│   ├── Member.cpp           # Implementation of Member class
│   └── Transaction.cpp      # Implementation of Transaction class
│
├── include/                 # Header files
│   ├── Library.h            # Declaration of Library class
│   ├── Book.h               # Declaration of Book class
│   ├── Member.h             # Declaration of Member class
│   └── Transaction.h        # Declaration of Transaction class
│
├── data/                    # Text files for storing data
│   ├── books.txt            # Stores book information
│   ├── members.txt          # Stores member information
│   └── transactions.txt     # Stores transaction history
│
├── main.cpp                 # Main application entry point
└── README.md                # Project overview and instructions
```

---

## Setup and Installation

Follow these steps to set up and run the Library Management System on your local machine.

### 1. Clone or Download the Repository

- Clone the repository using Git:
  ```bash
  git clone https://github.com/Prathamesh-Hajare.git
  ```

### 2. Compile the Code

```bash
    g++ main.cpp src/Library.cpp src/Book.cpp src/Member.cpp src/Transaction.cpp -o library_management
```

### 3. Run the Application

```bash
    ./library_management
```

---

## Usage

After running the application, you will be prompted to choose an option from a menu:

### 1. Add Book:

Add a new book by providing its ID, title, and author.

### 2. Add Member:

Add a new library member with an ID, name, and address.

### 3. Issue Book:

Issue a book to a member by specifying their member ID and the book ID.

### 4. Return Book:

Return a previously issued book by specifying the member ID and book ID.

### 5. Exit:

Exit the application and save all data.

---

## Data Files

The system uses the following text files to persist data:

### 1. books.txt: Contains the list of books in the library.

### 2. members.txt: Contains the list of library members.

### 3. transactions.txt: Contains records of issued and returned books.

The data is automatically loaded when the application starts and saved when the application exits.

---
