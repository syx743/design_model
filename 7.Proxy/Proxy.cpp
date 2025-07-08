#include <iostream>
using namespace std;

class HomePurchase
{
public:
    virtual void requestPurchase(int area) = 0;
};

class HomeBuyer : public HomePurchase
{
public:
    void requestPurchase(int area) override
    {
        cout << "yes" << endl;
    }
};

class HomeAgentProxy : public HomePurchase
{
private:
    HomeBuyer homebuyer;

public:
    void requestPurchase(int area) override
    {
        if (area > 100)
        {
            homebuyer.requestPurchase(area);
        }
        else
        {
            cout << "no" << endl;
        }
    }
};

int main()
{
    HomePurchase *buyerProxy = new HomeAgentProxy();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int area;
        cin >> area;
        buyerProxy->requestPurchase(area);
    }
    delete buyerProxy;
    system("pause");
    return 0;
}
