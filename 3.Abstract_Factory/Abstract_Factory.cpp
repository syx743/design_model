#include <iostream>
#include <string>
using namespace std;

class Chair
{
public:
    virtual void showInfo() = 0;
};

class ModernChair : public Chair
{
public:
    void showInfo() override
    {
        cout << "modern chair" << endl;
    }
};

class ClassicalChair : public Chair
{
public:
    void showInfo() override
    {
        cout << "classical chair" << endl;
    }
};

class Sofa
{
public:
    virtual void displayInfo() = 0;
};

class ModernSofa : public Sofa
{
public:
    void displayInfo() override
    {
        cout << "modern sofa" << endl;
    }
};

class ClassicalSofa : public Sofa
{
public:
    void displayInfo() override
    {
        cout << "classical sofa" << endl;
    }
};

class FurnitureFactory
{
public:
    virtual Chair *createChair() = 0;
    virtual Sofa *createSofa() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ModernChair();
    }
    Sofa *createSofa() override
    {
        return new ModernSofa();
    }
};

class ClassicalFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ClassicalChair();
    }
    Sofa *createSofa() override
    {
        return new ClassicalSofa();
    }
};

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string furnituretype;
        cin >> furnituretype;

        FurnitureFactory *factory = nullptr;
        if (furnituretype == "modern")
        {
            factory = new ModernFurnitureFactory();
        }
        else if (furnituretype == "classical")
        {
            factory = new ClassicalFurnitureFactory();
        }

        Chair *chair = factory->createChair();
        Sofa *sofa = factory->createSofa();

        chair->showInfo();
        sofa->displayInfo();

        delete chair;
        delete sofa;
        delete factory;
    }
    system("pause");
    return 0;
}
