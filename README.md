# Inventory Management System

A console-based Inventory Management System developed using C++. It helps manage product records, track stock levels, update inventory, and calculate total inventory value.

## Features

* Add and display products.
* Search products by ID or name.
* Update and delete product records.
* Add and remove product stock.
* Display low-stock products.
* Calculate total inventory value.
* Store inventory data using file handling.

## Technologies Used

* **Language:** C++
* **Concepts:** OOP, Classes, Encapsulation, Vectors, File Handling, Searching, CRUD Operations.
* **Compiler:** GCC (G++)

## Project Structure

```text
Inventory-Management-System/
│
├── main.cpp
├── Product.h
├── Product.cpp
├── InventoryManager.h
├── InventoryManager.cpp
├── inventory.txt
└── README.md
```

## How to Run

**1. Clone the repository**

```bash
git clone https://github.com/Shivamtripathi78/Inventory-Management-System.git
```

**2. Navigate to the project directory**

```bash
cd Inventory-Management-System
```

**3. Compile the project**

```bash
g++ -std=c++17 main.cpp Product.cpp InventoryManager.cpp -o InventorySystem.exe
```

**4. Run the application**

```powershell
.\InventorySystem.exe
```

## Learning Outcomes

* Understanding OOP principles in C++.
* Implementing CRUD operations.
* Managing product records using vectors.
* Performing stock calculations and validation.
* Using file handling for persistent data storage.

## Author

**Shivam Tripathi**

GitHub: [Shivamtripathi78](https://github.com/Shivamtripathi78)

## License

This project is intended for educational and learning purposes.
