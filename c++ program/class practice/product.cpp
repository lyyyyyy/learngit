class Product
{
private:
    /* data */
    char name;
    double price;
    int stock;
public:
    display();
    ~Product();
};

Product::display()
{
}

Product::~Product()
{
}
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int stock;

public:
    Product(string n, double p, int s) : name(n), price(p), stock(s) {}

    void display() {
        cout << name << "\t￥" << price 
             << "\t库存：" << stock << endl;
    }

    bool sell(int quantity) {
        if(stock >= quantity) {
            stock -= quantity;
            return true;
        }
        return false;
    }

    string getName() { return name; }
};

class Store {
private:
    Product products[100];
    int count = 0;

public:
    void addProduct(Product p) {
        if(count < 100) {
            products[count++] = p;
        } else {
            cout << "库存已满！" << endl;
        }
    }

    void processSale(string name, int qty) {
        for(int i = 0; i < count; i++) {
            if(products[i].getName() == name) {
                if(!products[i].sell(qty)) {
                    cout << "库存不足！" << endl;
                }
                return;
            }
        }
        cout << "商品不存在！" << endl;
    }

    void listProducts() {
        for(int i = 0; i < count; i++) {
            products[i].display();
        }
    }
};