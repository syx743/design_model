#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class TV
{
public:
    virtual void turnon() = 0;
    virtual void turnoff() = 0;
    virtual void switchchannel() = 0;
};

class SonyTV : public TV
{
public:
    void turnon()
    {
        cout << "sony tv is turned on" << endl;
    }
    void turnoff()
    {
        cout << "sony tv is turned off" << endl;
    }
    void switchchannel()
    {
        cout << "switch sony tv channels" << endl;
    }
};

class TCLTV : public TV
{
public:
    void turnon() override
    {
        std::cout << "TCL TV is ON" << std::endl;
    }

    void turnoff() override
    {
        std::cout << "TCL TV is OFF" << std::endl;
    }

    void switchchannel() override
    {
        std::cout << "Switching TCL TV channel" << std::endl;
    }
};

class RemoteControl
{
protected:
    TV *tv;

public:
    RemoteControl(TV *tv) : tv(tv) {}
    virtual void performOperation() = 0;
};

class PowerOperation : public RemoteControl
{
public:
    PowerOperation(TV *tv) : RemoteControl(tv) {}

    void performOperation() override
    {
        tv->turnon();
    }
};

class OffOperation : public RemoteControl
{
public:
    OffOperation(TV *tv) : RemoteControl(tv) {}

    void performOperation() override
    {
        tv->turnoff();
    }
};

class ChannelSwitchOperation : public RemoteControl
{
public:
    ChannelSwitchOperation(TV *tv) : RemoteControl(tv) {}

    void performOperation() override
    {
        tv->switchchannel();
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; i++)
    {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        int brand, operation;
        iss >> brand >> operation;

        TV *tv;
        if (brand == 0)
        {
            tv = new SonyTV();
        }
        else
        {
            tv = new TCLTV();
        }

        RemoteControl *remoteControl;
        if (operation == 2)
        {
            remoteControl = new PowerOperation(tv);
        }
        else if (operation == 3)
        {
            remoteControl = new OffOperation(tv);
        }
        else
        {
            remoteControl = new ChannelSwitchOperation(tv);
        }

        remoteControl->performOperation();

        delete tv;
        delete remoteControl;
    }
    system("pause");
    return 0;
}
