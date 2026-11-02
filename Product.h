#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    int productId;
    string name;
    int quantity;
    double price;

public:
    Product();
    Product(int id, string productName, int stock, double productPrice);

    int getProductId() const;
    string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setName(string productName);
    void setPrice(double productPrice);
    void addStock(int amount);
    bool removeStock(int amount);

    double getTotalValue() const;
    void display() const;
};

#endif