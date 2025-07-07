#include <iostream>
using namespace std;

class Bike
{
public:
    string frame;
    string tires;

    void setFrame(const string &frame)
    {
        this->frame = frame;
    }
    void setTires(const string &tires)
    {
        this->tires = tires;
    }
    friend ostream &operator<<(ostream &os, const Bike &bike)
    {
        os << bike.frame << " " << bike.tires;
        return os;
    }
};

class BikeBuilder
{
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getResult() = 0;
};

class MountainBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Aluminum Frame");
    }
    void buildTires() override
    {
        bike.setTires("Knobby Tires");
    }
    Bike getResult() override
    {
        return bike;
    }
};

class RoadBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Carbon Frame");
    }
    void buildTires() override
    {
        bike.setTires("Slim Tires");
    }
    Bike getResult() override
    {
        return bike;
    }
};

class BikeDirector
{
public:
    Bike construct(BikeBuilder &builder)
    {
        builder.buildFrame();
        builder.buildTires();
        return builder.getResult();
    }
};

int main()
{
    int n;
    cin >> n;
    BikeDirector director;
    for (int i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        BikeBuilder *builder;
        if (type == "mountain")
        {
            builder = new MountainBikeBuilder();
        }
        else
        {
            builder = new RoadBikeBuilder();
        }
        Bike bike = director.construct(*builder);
        cout << bike << endl;
        delete builder;
    }
    system("pause");
    return 0;
}
