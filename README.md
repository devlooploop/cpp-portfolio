# C++ Portfolio

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

A collection of **console-based C++ projects** demonstrating key programming concepts such as **file I/O**, **data structures**, **game logic**, **input validation**, and **menu-driven applications**.

---

## 📁 Repository Structure

```text
CPP-Projects/
├── 01-Bank-Clients-Management-cpp/
│   ├── BankClientsManagement.cpp
│   └── Clients.txt
│
├── 02-Bank-Project-2-Extension-cpp/
│   ├── BankSystemWithTransactions.cpp
│   └── Clients.txt
│
├── 03-Bank-Management-System-With-Users-cpp/
│   ├── BankManagementSystem_WithUsers.cpp
│   ├── Users.txt
│   └── Clients.txt
│   
├── 04-Rock-Paper-Scissors-cpp/
│   └── RockPaperScissors.cpp
│
├── 05-Math-Quiz-Game-cpp/
│   └── MathQuizGame.cpp
│
├── README.md
└── LICENSE
```

---

## 🚀 Featured Projects

### 01 – Bank Clients Management

A complete **console-based bank client management system** written in C++.

**Highlights:**

- Persistent data storage using `Clients.txt` (file I/O)
- Main menu with 6 options: List, Add, Delete, Update, Find, Exit
- Add new clients with **unique account number validation**
- View all clients in a formatted table
- Find clients by account number
- Update client information
- Delete clients with confirmation
- Clean, modular code using `struct`, `vector`, and functions

**Skills practiced:**  
File handling, structs, vectors, string manipulation, input validation, and menu-driven design.

---

### 02 – Bank Project (Extension with Transactions)

An **extended version** of the bank system with transaction support.

**Highlights:**

- Builds on the basic client management system
- Supports financial transactions (Deposit, Withdraw, Transfer)
- Persistent storage includes balance data
- Enhanced menu with transaction options
- Balance checks and error handling for insufficient funds
- Modular and reusable functions

**Skills practiced:**  
Advanced file I/O, transaction logic, data persistence, and extending existing systems.

---

### 03 – Bank Management System with Users & Permissions

A full-featured banking system with user authentication and role-based access control.

**Highlights:**

- Login screen with username/password validation
- Support for multiple users stored in Users.txt
- Bit-wise permissions system controlling access to features
- Admin can manage users: List, Add, Delete, Update, Find
- **Permissions include:**
  - Show Clients
  - Add/Delete/Update Clients
  - Find Clients
  - Perform Transactions
  - Manage Users *(only for Admins)*

- **Logout** functionality (returns to login screen)
- Access denied messages for unauthorized actions
- Protection against deleting the main "Admin" user
- Full permission selection (full access or granular)

**Skills practiced:**

User authentication, bit-wise operations, permissions system, multi-file data management, secure access control, advanced menu navigation, and modular architecture.

---

### 04 – Rock Paper Scissors

A classic **console-based Rock-Paper-Scissors** game against the computer.

**Features:**

- Player vs Computer gameplay
- Input validation
- Score tracking
- Win/lose/draw detection
- Play again option
- Clean and beginner-friendly code

**Skills practiced:**

enum, random number generation (rand()), game logic, loops, input validation, conditional logic, and modular functions.

---

### 05 – Math Quiz Game

An interactive **math quiz game** with difficulty levels and visual feedback.

**Highlights:**

- Choose number of questions (1–10)
- 3 difficulty levels: Easy, Medium, Hard + Mix mode
- 4 operations: Add, Subtract, Multiply, Divide + Mix mode
- Green screen + smiley for correct answers
- Red screen + beep + sad face for wrong answers
- Integer-only division (e.g., `5 ÷ 2 = 2`)
- Final score with Pass/Fail result
- Replay option with full screen reset

**Skills practiced:**  
`enum`, `struct`, functions, random numbers, loops, and `system("color")`.

---

## 🛠️ How to Run the Code

### Using **g++** (Linux / macOS)

```bash
g++ filename.cpp -o program
./program
```

### Using **Visual Studio** (Windows)

- Open the project folder or `.sln` file
- Build the project
- Run the program normally

---

## 📜 License

This project is released under the **MIT License**.  
See the `LICENSE` file for more details.

⭐ **Star this repository** if you find it helpful!
