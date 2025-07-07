#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Prototype
{
public:
    virtual Prototype *clone() const = 0;
    virtual string getDetails() const = 0;
    virtual ~Prototype() = default;
};

class RectanglePrototype : public Prototype
{
private:
    string color;
    int width;
    int height;

public:
    RectanglePrototype(string color, int width, int height) : color(color), width(width), height(height) {}
    Prototype *clone() const override
    {
        return new RectanglePrototype(*this);
    }
    string getDetails() const override
    {
        return "color: " + color + ", width: " + to_string(width) + ", height: " + to_string(height);
    }
};

int main()
{
    vector<Prototype *> rectangles;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string color;
        int width, height;
        cin >> color >> width >> height;
        Prototype *originalrectangle = new RectanglePrototype(color, width, height);
        rectangles.push_back(originalrectangle);
    }
    for (const auto &rectangle : rectangles)
    {
        Prototype *clonerectangle = rectangle->clone();
        cout << clonerectangle->getDetails() << endl;
        delete clonerectangle;
    }

    for (const auto &rectangle : rectangles)
    {
        delete rectangle;
    }
    system("pause");
    return 0;
}
