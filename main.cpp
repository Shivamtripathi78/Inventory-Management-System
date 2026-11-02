#include <iostream>
#include <limits>
#include "InventoryManager.h"

using namespace std;

int main() {
    InventoryManager inventory;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "       INVENTORY MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Add Product\n";
        cout << "2. Display All Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Add Stock\n";
        cout << "7. Remove Stock / Record Sale\n";
        cout << "8. Display Low Stock Products\n";
        cout << "9. Calculate Inventory Value\n";
        cout << "0. Exit\n";

        cout << "========================================\n";
        cout << "Enter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;

            case 2:
                inventory.displayProducts();
                break;

            case 3:
                inventory.searchProduct();
                break;

            case 4:
                inventory.updateProduct();
                break;

            case 5:
                inventory.deleteProduct();
                break;

            case 6:
                inventory.addStock();
                break;

            case 7:
                inventory.removeStock();
                break;

            case 8:
                inventory.displayLowStock();
                break;

            case 9:
                inventory.calculateInventoryValue();
                break;

            case 0:
                cout << "\nThank you for using Inventory Management System!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}