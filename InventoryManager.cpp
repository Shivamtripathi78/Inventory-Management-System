#include "InventoryManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

InventoryManager::InventoryManager() {
    loadInventory();
}

int InventoryManager::findProductIndex(int id) const {
    for (int i = 0; i < static_cast<int>(products.size()); i++) {
        if (products[i].getProductId() == id) {
            return i;
        }
    }

    return -1;
}

void InventoryManager::loadInventory() {
    ifstream file("inventory.txt");
    string line;

    while (getline(file, line)) {
        try {
            stringstream ss(line);

            string id, name, quantity, price;

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, quantity, '|');
            getline(ss, price);

            int productId = stoi(id);
            int stock = stoi(quantity);
            double productPrice = stod(price);

            if (productId > 0 && stock >= 0 &&
                productPrice >= 0 && !name.empty() &&
                findProductIndex(productId) == -1) {

                products.emplace_back(
                    productId, name, stock, productPrice
                );
            }
        }
        catch (...) {
            continue;
        }
    }

    file.close();
}

void InventoryManager::saveInventory() const {
    ofstream file("inventory.txt");

    if (!file) {
        cout << "Error saving inventory!\n";
        return;
    }

    for (const Product& product : products) {
        file << product.getProductId() << "|"
             << product.getName() << "|"
             << product.getQuantity() << "|"
             << fixed << setprecision(2)
             << product.getPrice() << "\n";
    }

    file.close();
}

void InventoryManager::addProduct() {
    int id, quantity;
    string name;
    double price;

    cout << "\nEnter Product ID: ";

    if (!(cin >> id) || id <= 0) {
        cout << "Invalid Product ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (findProductIndex(id) != -1) {
        cout << "Product ID already exists!\n";
        return;
    }

    cout << "Enter Product Name: ";
    getline(cin >> ws, name);

    if (name.find('|') != string::npos) {
        cout << "Invalid product name!\n";
        return;
    }

    cout << "Enter Quantity: ";

    if (!(cin >> quantity) || quantity < 0) {
        cout << "Invalid quantity!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter Unit Price: ";

    if (!(cin >> price) || price < 0) {
        cout << "Invalid price!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    products.emplace_back(id, name, quantity, price);

    saveInventory();

    cout << "\nProduct added successfully!\n";
}

void InventoryManager::displayProducts() const {
    if (products.empty()) {
        cout << "\nNo products found!\n";
        return;
    }

    cout << "\n"
         << left
         << setw(12) << "Product ID"
         << setw(22) << "Name"
         << setw(12) << "Quantity"
         << setw(18) << "Unit Price"
         << "Total Value\n";

    cout << string(75, '-') << "\n";

    for (const Product& product : products) {
        product.display();
    }
}

void InventoryManager::searchProduct() const {
    int choice;

    cout << "\nSearch By:\n";
    cout << "1. Product ID\n";
    cout << "2. Product Name\n";
    cout << "Enter Choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (choice == 1) {
        int id;

        cout << "Enter Product ID: ";

        if (!(cin >> id)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        int index = findProductIndex(id);

        if (index != -1) {
            products[index].display();
        } else {
            cout << "Product not found!\n";
        }
    }
    else if (choice == 2) {
        string name;

        cout << "Enter Product Name: ";
        getline(cin >> ws, name);

        bool found = false;

        for (const Product& product : products) {
            if (product.getName().find(name) != string::npos) {
                product.display();
                found = true;
            }
        }

        if (!found) {
            cout << "Product not found!\n";
        }
    }
    else {
        cout << "Invalid choice!\n";
    }
}

void InventoryManager::updateProduct() {
    int id;

    cout << "\nEnter Product ID to Update: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findProductIndex(id);

    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }

    string name;
    double price;

    cout << "Enter New Product Name: ";
    getline(cin >> ws, name);

    if (name.empty() || name.find('|') != string::npos) {
        cout << "Invalid product name!\n";
        return;
    }

    cout << "Enter New Unit Price: ";

    if (!(cin >> price) || price < 0) {
        cout << "Invalid price!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    products[index].setName(name);
    products[index].setPrice(price);

    saveInventory();

    cout << "\nProduct updated successfully!\n";
}

void InventoryManager::deleteProduct() {
    int id;

    cout << "\nEnter Product ID to Delete: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findProductIndex(id);

    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }

    products.erase(products.begin() + index);

    saveInventory();

    cout << "\nProduct deleted successfully!\n";
}

void InventoryManager::addStock() {
    int id, amount;

    cout << "\nEnter Product ID: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findProductIndex(id);

    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter Quantity to Add: ";

    if (!(cin >> amount) || amount <= 0 ||
        amount > numeric_limits<int>::max() -
                 products[index].getQuantity()) {
        cout << "Invalid quantity!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    products[index].addStock(amount);

    saveInventory();

    cout << "\nStock added successfully!\n";
}

void InventoryManager::removeStock() {
    int id, amount;

    cout << "\nEnter Product ID: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findProductIndex(id);

    if (index == -1) {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter Quantity to Remove: ";

    if (!(cin >> amount)) {
        cout << "Invalid quantity!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (!products[index].removeStock(amount)) {
        cout << "Invalid quantity or insufficient stock!\n";
        return;
    }

    saveInventory();

    cout << "\nStock removed successfully!\n";
}

void InventoryManager::displayLowStock() const {
    const int LOW_STOCK_LIMIT = 5;
    bool found = false;

    cout << "\nLow Stock Products (5 or fewer units):\n";

    for (const Product& product : products) {
        if (product.getQuantity() <= LOW_STOCK_LIMIT) {
            product.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No low-stock products found.\n";
    }
}

void InventoryManager::calculateInventoryValue() const {
    double total = 0;

    for (const Product& product : products) {
        total += product.getTotalValue();
    }

    cout << "\nTotal Inventory Value: Rs. "
         << fixed << setprecision(2) << total << "\n";
}