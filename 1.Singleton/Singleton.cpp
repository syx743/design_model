#include <iostream>
#include <map>
#include <mutex>
using namespace std;

class ShoppingCarManager
{
private:
    // 购物车存储商品和数量的映射
    map<string, int> cart;
    static mutex mtx;

    ShoppingCarManager() {}
    ShoppingCarManager(const ShoppingCarManager &) = delete;
    void operator=(const ShoppingCarManager &) = delete;

public:
    static ShoppingCarManager &getInstance()
    {
        static ShoppingCarManager instance;
        return instance;
    }
    void addToCart(const string &itemName, int quantity)
    {
        lock_guard<mutex> lock(mtx);
        cart[itemName] += quantity;
    }
    void viewCart() const
    {
        lock_guard<mutex> lock(mtx);
        for (const auto &item : cart)
        {
            cout << item.first << " " << item.second << endl;
        }
    }
};
mutex ShoppingCarManager::mtx;
int main()
{
    string itemName;
    int quantity;
    while (cin >> itemName >> quantity)
    {
        ShoppingCarManager &cart = ShoppingCarManager::getInstance();
        cart.addToCart(itemName, quantity);
    }
    const ShoppingCarManager &cart = ShoppingCarManager::getInstance();
    cart.viewCart();
    system("pause");
    return 0;
}
