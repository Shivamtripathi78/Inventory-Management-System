#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Product.h"
#include <vector>

class InventoryManager {
private:
    vector<Product> products;

    int findProductIndex(int id) const;
    void loadInventory();
    void saveInventory() const;

public:
    InventoryManager();

    void addProduct();
    void displayProducts() const;
    void searchProduct() const;
    void updateProduct();
    void deleteProduct();
    void addStock();
    void removeStock();
    void displayLowStock() const;
    void calculateInventoryValue() const;
};

#endif