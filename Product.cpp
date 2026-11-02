#include "Product.h"
#include <iostream>
#include <iomanip>

Product::Product() {
    productId = 0;
    name = "";
    quantity = 0;
    price = 0;
}

Product::Product(int id, string productName, int stock,
                 double productPrice) {
    productId = id;
    name = productName;
    quantity = stock;
    price = productPrice;
}

int Product::getProductId() const {
    return productId;
}

string Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::setName(string productName) {
    name = productName;
}

void Product::setPrice(double productPrice) {
    price = productPrice;
}

void Product::addStock(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}

bool Product::removeStock(int amount) {
    if (amount <= 0 || amount > quantity) {
        return false;
    }

    quantity -= amount;
    return true;
}

double Product::getTotalValue() const {
    return quantity * price;
}

void Product::display() const {
    cout << left
         << setw(12) << productId
         << setw(22) << name
         << setw(12) << quantity
         << "Rs. " << fixed << setprecision(2)
         << setw(12) << price
         << "Rs. " << getTotalValue()
         << endl;
}