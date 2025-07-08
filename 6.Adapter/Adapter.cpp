#include <iostream>
using namespace std;
// 让一个TypeC口的电脑适应USB口
class USB
{
public:
    virtual void charge() = 0;
};

class TypeC
{
public:
    virtual void chargewithTypeC() = 0;
};

class USBcomputer : public USB
{
public:
    void charge() override
    {
        cout << "USB computer (Adapter)" << endl;
    }
};

class TypeCcomputer : public TypeC
{
public:
    void chargewithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

class TypeCAdapter : public USB
{
private:
    TypeC *typeC;

public:
    TypeCAdapter(TypeC *typeC) : typeC(typeC) {}
    void charge() override
    {
        typeC->chargewithTypeC();
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            TypeC *typeccomputer = new TypeCcomputer();
            typeccomputer->chargewithTypeC();
            delete typeccomputer;
        }
        else if (choice == 2)
        {
            USB *usbadapter = new USBcomputer();
            usbadapter->charge();
            delete usbadapter;
        }
    }
    system("pause");
    return 0;
}
