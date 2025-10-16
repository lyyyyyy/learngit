#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

class Product{
    private:
    string name;
    double price;
    int stock;
    public :
    //初始化列表参数化
    Product(string n,double p,int s) : name(n),price(p),stock(s){} 
    //展示商品价格
    void show() const {
        cout<<name<<"的价格是"<<price<<endl;
        cout<<name<<"的库存是"<<stock<<endl;
    }
    string GetName()  const{return name;}
    int GetStock() const {return stock;}
    bool sell(int num){
        if(stock<num){
            return false;
        }
        stock-=num;
        return true;
    }
};
class Store{
    private:
    vector<Product> products;
    const size_t MaxCount=100;
    public:
    //添加商品
    void AddProduct(const Product& p){
        if(products.size()<MaxCount){
        products.push_back(p);
        cout<<"当前商品种类是"<<products.size()<<endl;
        }
        else{
            cout<<"当前商品种类已满"<<endl;
        }
    }
    void ShowProduct(){
        for(auto& prod:products)
            {cout<<prod.GetName()<<"当前的库存是"<<prod.GetStock()<<endl;}
        
    }
    void SellProduct(string n,int num){
        bool found=false;
        for(auto& prod:products){
            if(prod.GetName()==n){
                if(prod.sell(num)){
                    found=true;
                    cout<<"销售成功!"<<prod.GetName()<<"当前库存是"<<prod.GetStock()<<endl;}
                else cout<<"当前库存不足"<<endl;
                break;
            }
            
        }
         if(found==false)cout<<"当前库存没此类商品"<<endl;
      
    
        }

    };

int main() {
    SetConsoleOutputCP(65001);  // 输出编码（关键）
    SetConsoleCP(65001);        // 输入编码（可选，如需读取中文输入）
    Product banana("香蕉",10,100);//构造商品
    banana.show();
    Product apple("苹果",100,100);//构造商品
    apple.show();
    Store store;
    store.AddProduct(banana);
    store.AddProduct(apple);
    store.SellProduct("苹果",50);
    store.SellProduct("香蕉",50);
    store.ShowProduct();
    system("pause");


    return 0;
}