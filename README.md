=>Overview

This is a simple Address Book application implemented in C.
It allows users to store, search, update, and delete contact information such as name, phone number, and email.
The project demonstrates basic file handling, data structures, and modular programming in C.

---

=> Features

Add a new contact
Display all contacts
Search a contact by name or phone number
Edit/Update existing contact
Delete a contact
Data stored in a CSV file for persistence

---

=> Technologies Used

C Language
File Handling (CSV)
Modular approach using header files

---

=> Project Structure

Address-Book/
│── main.c          # Entry point
│── contact.c       # Contact management functions
│── contact.h       # Header file for contact.c
│── file.c          # File handling functions
│── file.h          # Header file for file.c
│── contact.csv     # Stores saved contacts

---

=> How to Run

1. Clone the repository:

git clone https://github.com/Nagaraj2244/Address-Book.git
cd Address-Book

2. Compile the program:

gcc main.c contact.c file.c -o addressbook

3. Run the program:

./addressbook

---

=> Learning Outcomes

Hands-on practice with C programming
Understanding of file handling
Use of modular programming (header files)
