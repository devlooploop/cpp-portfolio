# C++ Portfolio

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=cplusplus&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

A collection of C++ projects demonstrating practical programming, problem-solving, file handling, data persistence, authentication, and console application development.

The repository contains four C++ projects, ranging from a comprehensive Currency Exchange & Bank Management System and an ATM Simulator to console-based games.

The projects demonstrate concepts such as **Object-Oriented Programming (OOP), file I/O, data persistence, data structures, user authentication, permissions, transaction processing, input validation, error handling, and menu-driven application design**.

---

## 📁 Repository Structure

```text
CPP-Projects/

├── 01-CurrencyExchange-Bank-Management-cpp/
│   ├── *.cpp
│   ├── *.h
│   ├── Currencies.txt
│   ├── LoginRegister.txt
│   ├── TransfersLog.txt
│   └── Users.txt
│
│
├── 02-ATM-Simulator-cpp/
│   ├── ATMSimulator.cpp
│   └── Clients.txt
│
│
├── 03-Rock-Paper-Scissors-cpp/
│   │
│   └── RockPaperScissors.cpp
│
│
├── 04-Math-Quiz-Game-cpp/
│   └── MathQuizGame.cpp
│
│
├── README.md
└── LICENSE
```

---

## 🚀 Featured Projects

### 01 – Bank Management System

A larger **C++ banking management application** designed to bring together client management, banking transactions, authentication, permissions, and logging into one structured system.

The project uses a modular architecture with multiple classes and screens to separate responsibilities and organize the application's functionality.

#### 🔐 User Authentication

- Username and password login
- Login validation
- Failed login handling
- System lockout after repeated failed attempts
- Logout functionality

#### 👥 Client Management

- List clients
- Add new clients
- Delete clients
- Update client information
- Find clients
- Account number validation
- Persistent client data

#### 💰 Banking Transactions

- Deposit
- Withdraw
- Transfer between accounts
- Balance validation
- Transaction confirmation
- Updated account balances
- Transfer history

#### 👤 User Management

- List users
- Add users
- Delete users
- Update users
- Find users
- User permissions
- Access control

#### 📋 Login & Transfer Logs

- Login register/history
- Transfer history
- Date and time records
- Source and destination account information
- Transaction amounts
- Account balances after transfers
- User responsible for the operation

#### 🧠 Technical Concepts

- Object-Oriented Programming (OOP)
- Classes and objects
- Encapsulation
- Inheritance
- Static members and methods
- Enumerations
- Structures
- Vectors
- File I/O
- Data persistence
- Input validation
- Error handling
- User authentication
- Authorization and permissions
- Bitwise operations
- Transaction processing
- Modular application design
- Menu-driven console applications

#### 📂 Project Structure

```text
01-Bank-Management-System-cpp/

├── *.cpp
├── *.h
├── Clients.txt
├── Users.txt
└── README.md
```

The project is organized into separate classes and screens for different responsibilities, making the application easier to maintain, extend, and understand.

---

### 02 – ATM Simulator

A console-based **ATM simulation system** with authentication and basic banking operations.

- Account number and PIN authentication
- Quick withdrawal
- Normal withdrawal
- Deposit functionality
- Balance checking
- Logout functionality
- Persistent client data
- Input validation
- Balance verification
- Transaction processing
- Menu-driven interface

---

### 03 – Bank Project – Transactions Extension

An extended version of the bank client management system with **financial transaction functionality**.

- Builds on the client management system
- Deposit functionality
- Withdraw functionality
- Transfer functionality
- Persistent account balances
- Balance validation
- Insufficient funds handling
- Transaction-oriented menu system
- Reusable and modular functions

---

### 04 – Bank Management System with Users & Permissions

A more advanced banking application introducing **user authentication and permission management**.

- Username and password authentication
- Multiple users stored in `Users.txt`
- Client management
- User management
- Role-based access control
- Bitwise permission system
- Granular permissions for different operations
- Access denied handling
- Admin user protection
- Logout functionality
- Transaction operations

#### 🔑 Permissions Include

- Show Clients
- Add Clients
- Delete Clients
- Update Clients
- Find Clients
- Perform Transactions
- Manage Users

---

### 05 – Rock Paper Scissors

A classic **console-based Rock-Paper-Scissors game** where the player competes against the computer.

- Player vs Computer gameplay
- Random computer choices
- Input validation
- Win / Lose / Draw detection
- Score tracking
- Play-again functionality
- Game result display

---

### 06 – Math Quiz Game

An interactive **console-based mathematics quiz game** with multiple difficulty levels and operations.

- Select the number of questions
- Multiple difficulty levels
- Easy, Medium, Hard, and Mix modes
- Addition
- Subtraction
- Multiplication
- Division
- Mixed operations mode
- Automatic score calculation
- Pass / Fail result
- Replay functionality
- Visual feedback for correct and incorrect answers

---

### 07 – Bank Clients Management

A console-based **bank client management system** developed in C++.

- Persistent client data using `Clients.txt`
- List all clients
- Add new clients
- Delete clients
- Update client information
- Find clients by account number
- Unique account number validation
- Menu-driven application
- Structured client data using `struct`
- Data management using `vector`

---

## 🛠️ How to Run

### Visual Studio 2022

The projects can be opened and built using **Visual Studio 2022**.

Recommended configuration:

```text
IDE:              Visual Studio 2022
Platform Toolset: v143
Language:         C++
```

#### Steps

1. Clone or download the repository.
2. Open the Visual Studio solution/project.
3. Make sure the required C++ workload and build tools are installed.
4. Select the desired project.
5. Build the solution.
6. Run the application.

---

### Using g++

For individual `.cpp` files, the programs can also be compiled using `g++`.

```bash
g++ filename.cpp -o program
./program
```

For example:

```bash
g++ RockPaperScissors.cpp -o RockPaperScissors
./RockPaperScissors
```

---

## 📜 License

This project is released under the **MIT License**.

See the [`LICENSE`](LICENSE) file for more details.

---

⭐ **If you find this portfolio useful, feel free to star the repository.**