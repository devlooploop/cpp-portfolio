# C++ Portfolio

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)
![Visual
Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visualstudio&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

A collection of console-based C++ projects demonstrating key programming concepts like file I/O, data structures, game logic, input validation, and menu-driven applications.

------------------------------------------------------------------------

## 📁 Repository Structure

```CPP-Projects/
├── 01-Bank-Clients-Management-cpp/
│   ├── BankClientsManagement.cpp
│   └── Clients.txt
│
├── 02-Bank-Project-2-Extension-cpp/
│   ├── BankSystemWithTransactions.cpp
│   └── Clients.txt
│
├── 03-Rock-Paper-Scissors-cpp/
│   └── RockPaperScissors.cpp
│
├── 04-Math-Quiz-Game-cpp/
│   └── MathQuizGame.cpp
│
├── README.md
└── LICENSE
```

------------------------------------------------------------------------

## 🚀 Featured Projects

### 01-Bank-Clients-Management

A complete console-based bank client management system written in C++.  
**Highlights:**

- Persistent data storage using `Clients.txt` (file I/O)
- Main menu with 6 options: List, Add, Delete, Update, Find, Exit
- Add new clients (with unique account number validation)
- View all clients in a formatted table
- Find client by account number
- Update client information
- Delete clients with confirmation
- Clean, modular code using structs, vectors, and functions

Perfect project to practice: file handling, structs, vectors, string manipulation, user input validation, and menu-driven applications.

### 02-Bank-Project-2-Extension

An extended version of the bank system with added transaction capabilities.
**Highlights:**

- Builds on the basic client management system
- Supports financial transactions (e.g., deposit, withdraw, transfer)
- Updated persistent storage in Clients.txt to include balance and transaction history
- Enhanced menu with transaction options
- Balance checks, transaction logging, and error handling for insufficient funds
- Modular functions for reusability

Great for learning: advanced file I/O, transaction logic, data persistence across sessions, and extending existing projects.

### 03-Rock-Paper-Scissors

A classic console-based Rock-Paper-Scissors game written in C++.  
Features:

- Player vs Computer gameplay
- Input validation
- Score tracking
- Clean and commented code (great for beginners)

### 04-Math-Quiz-Game

Interactive math quiz with levels and colorful feedback!  
**Highlights:**

- Choose number of questions (1–10)
- 3 difficulty levels: Easy (1-digit), Medium, Hard (2-digit) + Mix mode
- 4 operations: Add / Subtract / Multiply / Divide + Mix mode
- Green screen + smiley for correct answers
- Red screen + beep + sad face for wrong answers
- Integer-only answers (5÷2 = 2 → school-style math)
- Final score + Pass/Fail result
- Play again? Y/N with full screen reset

Perfect project to practice: `enum`, `struct`, functions, random numbers, game loops, and `system("color")`.

------------------------------------------------------------------------

## 🛠️ How to Run Code

### **Using g++ (Linux/Mac):**

``` bash
g++ filename.cpp -o program
./program
```

### **Using Visual Studio (Windows):**

- Open the `.sln` file inside the project folder\

- Build → Run the project normally

------------------------------------------------------------------------

## 📜 License

This project is released under the **MIT License**.\
See the `LICENSE` file for more details.

⭐ Star this repo if you find it helpful!
