#include <iostream>
#include <memory>
using namespace std;

class Coffee
{
public:
    virtual void brew() = 0;
    virtual ~Coffee() = default;
};

class BlackCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "brew black coffee" << endl;
    }
};

class Latte : public Coffee
{
public:
    void brew() override
    {
        cout << "brew latte" << endl;
    }
};

class Decorator : public Coffee
{
protected:
    unique_ptr<Coffee> coffee;

public:
    Decorator(unique_ptr<Coffee> coffee) : coffee(move(coffee)) {}

    void brew() override
    {
        if (coffee)
        {
            coffee->brew();
        }
    }
};

class MilkDecorator : public Decorator
{
public:
    MilkDecorator(unique_ptr<Coffee> coffee) : Decorator(move(coffee)) {}
    void brew() override
    {
        Decorator::brew();
        cout << "add milk" << endl;
    }
};

class SugarDecorator : public Decorator
{
public:
    SugarDecorator(unique_ptr<Coffee> coffee) : Decorator(move(coffee)) {}
    void brew() override
    {
        Decorator::brew();
        cout << "add sugar" << endl;
    }
};

int main()
{
    int coffeetype, condimenttype;
    while (cin >> coffeetype >> condimenttype)
    {
        unique_ptr<Coffee> coffee;
        if (coffeetype == 1)
        {
            coffee = make_unique<BlackCoffee>();
        }
        else if (coffeetype == 2)
        {
            coffee = make_unique<Latte>();
        }

        if (condimenttype == 1)
        {
            coffee = make_unique<MilkDecorator>(move(coffee));
        }
        else if (condimenttype == 2)
        {
            coffee = make_unique<SugarDecorator>(move(coffee));
        }

        coffee->brew();
    }

    system("pause");
    return 0;
}
