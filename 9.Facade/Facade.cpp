#include <iostream>
#include <vector>
using namespace std;

class AirConditioner
{
public:
    void turnoff()
    {
        cout << "air conditioner is turned off" << endl;
    }
};

class DeskLamp
{
public:
    void turnoff()
    {
        cout << "desklamp is turned off" << endl;
    }
};

class Television
{
public:
    void turnoff()
    {
        cout << "television is turned off" << endl;
    }
};

class PowerSwitchFacade
{
private:
    DeskLamp desklamp;
    AirConditioner airconditioner;
    Television television;

public:
    PowerSwitchFacade() {}
    void turnoffDevice(int code)
    {
        switch (code)
        {
        case 1:
            airconditioner.turnoff();
            break;
        case 2:
            desklamp.turnoff();
            break;
        case 3:
            television.turnoff();
            break;
        default:
            break;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    PowerSwitchFacade powerswitch;
    for (int i = 0; i < n; i++)
    {
        powerswitch.turnoffDevice(input[i]);
    }
    system("pause");
    return 0;
}
