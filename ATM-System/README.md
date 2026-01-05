# ATM System – Console-Based Banking Application (C++ / OOP)

## Overview

## 🎥 Demo Video


Uploading demo.mp4…


▶️ This short demo (≈2 minutes) shows the complete workflow of the ATM system:

- Card authentication
- Balance inquiry
- Withdrawal & deposit
- Money transfer
- Transaction history

https://github.com/USERNAME/REPO/assets/XXXX/atm-demo.mp4

This project is a console-based ATM system implemented in C++ using Object-Oriented Programming (OOP) principles.
It simulates core banking operations such as authentication, balance inquiry, cash withdrawal, deposit, money transfer, and transaction history management.

The primary goal of this project is to demonstrate clean software design, proper separation of concerns, and realistic system modeling, rather than simply implementing features.

## Key Features

Secure card-based authentication with PIN validation

Balance inquiry

Cash withdrawal and deposit with validation

Money transfer between accounts

Transaction history tracking per account

Clear separation between UI and business logic

Fully object-oriented design (no procedural shortcuts)

## System Architecture

The system follows a layered design with clear responsibility boundaries:

ATM (UI Layer)
|
v
BankSystem (Business Logic / Controller)
|
v
Account (Domain Model)
|
├── Card (Authentication)
└── Transaction (History)

## Architectural Highlights

**ATM**
Handles user interaction only (input/output, menus).
Contains no business rules.

**BankSystem**
Acts as the controller and orchestrates system logic.
Manages authentication and money transfer between accounts.
Contains no UI code.

**Account**
Represents a bank account and encapsulates all financial rules.
Owns a Card for authentication and a list of Transaction objects.

**Card**
Responsible only for credential verification (card number & PIN).

**Transaction**
Represents an immutable record of an operation with timestamping.

This design enforces Single Responsibility, Encapsulation, and Low Coupling, making the system easier to extend and maintain.

## Object-Oriented Design Principles Applied

**Encapsulation**
Internal data (balance, PIN, card number) is never accessed directly.

**Separation of Concerns**
UI logic is isolated from business logic.

**Composition over Inheritance**
Accounts own Cards and Transactions.

**High Cohesion**
Each class has a focused and well-defined responsibility.

**Scalability-Oriented Design**
The system can be extended to support:

Persistent storage

Multiple cards per account

GUI or Web interfaces

Role-based access

## UML Diagrams

Class Diagram

The project includes the following core relationships:

BankSystem manages multiple Account objects

Account has one Card

Account has many Transaction records

ATM depends on BankSystem

Sequence Diagrams

Complete sequence diagrams were designed for:

Login flow

Balance inquiry

Withdraw & deposit

Money transfer

Transaction history

Logout

These diagrams reflect the actual runtime behavior of the system.

Technologies Used

Language: C++

Paradigm: Object-Oriented Programming (OOP)

Libraries:

<iostream>

<vector>

<string>

<ctime>

No external frameworks were used to emphasize core language mastery.

## How to Run

Clone the repository:

git clone https://github.com/your-username/atm-system-cpp.git

Compile:

g++ main.cpp -o atm

Run:

./atm

Sample Credentials (Demo)
Card Number PIN Initial Balance
111111 1111 2000
222222 2222 3000
Why This Project Matters

This project is not just a feature implementation; it reflects:

Thoughtful system design

Correct use of OOP principles

Awareness of real-world software architecture

Readiness to scale beyond academic requirements

It was intentionally designed to resemble professional backend logic, even though it is console-based.

## Future Enhancements

File or database persistence

Encryption for sensitive data

Multi-session handling

GUI / Web interface

Unit testing
