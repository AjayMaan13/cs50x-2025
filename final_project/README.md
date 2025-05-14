# 🍽️ Digital Dine-In– Restaurant Management System
#### Video Demo: https://www.youtube.com/watch?v=LoEyFqCMi0U
#### Description:

## Basic Information
- **Name:** Ajaypartap Singh Maan
- **EDX ID:** Ajay_maan19  
- **Github ID:** AjayMaan13
- **City, Country:** Toronto, Canada
- **Recording Date:** May 12, 2025

## Description:

**Language:** C++  
**Core Concepts:** OOP, Polymorphism, Dynamic Memory, File Handling, CLI UX

---

## 📖 Comprehensive Overview

**Digital Dine-In** is a sophisticated console-based C++ application that simulates the complete dine-in experience of a restaurant through an intuitive command-line interface. This project was specifically designed to aid waitstaff in efficiently managing restaurant operations, including taking comprehensive food and drink orders, generating detailed bills with tax calculations, and automatically storing transaction records in uniquely named files for future reference.

The project was meticulously developed over five progressive milestones, each building upon the previous one to incorporate increasingly complex features and industry-relevant software engineering techniques. This incremental approach allowed for thorough testing and refinement of each component, resulting in a robust and reliable system that handles various edge cases and user scenarios.

The application demonstrates advanced object-oriented programming principles, showcasing proper use of inheritance, polymorphism, and encapsulation to create a maintainable and extensible codebase. The project particularly emphasizes memory management best practices, ensuring that all dynamically allocated memory is properly handled without leaks or dangling pointers.

---

## ✨ Detailed Features

- 📋 **Interactive Ordering System** – Navigate through hierarchical menus with ease, customize orders according to customer preferences, and select from various item sizes (Small, Medium, Large, Extra Large for drinks; Adult and Child portions for food).

- 🧾 **Automated Bill Generation** – Automatically calculate itemized totals, apply appropriate tax rates (13% as configured), and generate professional-looking receipts that can be printed to console or saved to files.

- 🔐 **Robust Input Validation** – Implement comprehensive error checking that prevents crashes due to invalid user input, provides clear feedback messages, and guides users toward valid choices through intuitive prompts.

- 💾 **CSV-Driven Menu Management** – Dynamically load food and drink data from external CSV files, allowing for easy menu updates without recompiling the application. This feature makes the system highly adaptable to changing restaurant offerings.

- 🧠 **Sophisticated Object-Oriented Architecture** – Utilize advanced polymorphism with an abstract base class `Billable`, enabling seamless handling of different item types (Food and Drink) through a unified interface.

- 🛠️ **Memory-Safe Design** – Implement rigorous dynamic memory management strategies with clear allocation and deallocation patterns, including proper copy constructors and assignment operators to handle the Rule of Three.

---

## 🧰 Technical Stack & Concepts

The project leverages modern C++11 standards and incorporates several advanced programming concepts:

- **C++11 Standard Compliance** – Ensures compatibility and utilizes modern language features
- **Class Hierarchies & Polymorphism** – Demonstrates advanced OOP principles through well-designed inheritance structures
- **Encapsulation & Const-Correctness** – Maintains data integrity and prevents unintended modifications
- **Dynamic Memory Allocation** – Handles runtime memory requirements efficiently and safely
- **CSV File Parsing & File I/O** – Implements robust file handling for data persistence and menu loading
- **CLI Menu Design & UX Flow** – Creates an intuitive user interface that guides users through complex operations
- **Exception-Free Error Handling** – Uses traditional C-style error checking for maximum compatibility and clarity

---

## 🏗️ Architectural Design

The project follows a modular design pattern with clear separation of concerns:

### Core Components:

1. **Derived Classes (Food & Drink)** – Implement specific behaviors for different menu categories, including pricing strategies (child portions at 50% price, drink sizes affecting cost), ordering workflows, and display formatting.

2. **Menu System** – Provides a reusable, flexible menu framework that can be easily adapted for different contexts throughout the application, featuring automatic numbering, indentation support, and customizable prompts.

3. **Order Management** – Handles the complete lifecycle of an order, from item selection through bill generation and file storage, maintaining proper object relationships and memory management.
---

## 🚀 Build Process & Execution

### Standard Compilation:
```bash
g++ -Wall -std=c++11 -g -o dinein main.cpp *.cpp
./dinein
### Memory Leak Detection (Linux/macOS):
```bash
valgrind --leak-check=full --track-origins=yes ./dinein
### Windows MinGW:
```bash
g++ -Wall -std=c++11 -o dinein.exe main.cpp *.cpp
dinein.exe
## 🎓 Key Learning Outcomes
This project provided hands-on experience with several critical programming concepts:
Applied clean object-oriented design through real-world modeling of restaurant operations, demonstrating how abstract concepts translate into practical applications.
Mastered dynamic memory management by implementing proper allocation and deallocation strategies, including handling complex scenarios with nested objects and arrays.
Developed CLI-based user experience design skills by creating intuitive navigation flows and clear feedback mechanisms that guide users through complex operations.
Strengthened file I/O and data processing abilities through implementation of CSV parsing and automated file generation systems.
Reinforced understanding of class inheritance hierarchies and how proper design facilitates future extensions and modifications.
