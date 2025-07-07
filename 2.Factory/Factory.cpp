#include <iostream>
#include <vector>
using namespace std;

// 抽象类必须有虚析构函数
class Block
{
public:
    virtual void produce() = 0;
    virtual ~Block() = default;
};

class CircleBlock : public Block
{
public:
    void produce() override
    {
        cout << " circle block " << endl;
    }
};

class SquareBlock : public Block
{
public:
    void produce() override
    {
        cout << " square block " << endl;
    };
};

class BlockFactory
{
public:
    virtual Block *createBlock() = 0;
    virtual ~BlockFactory() = default;
};

class CircleBlockFactory : public BlockFactory
{
public:
    Block *createBlock() override
    {
        return new CircleBlock();
    }
};

class SquareBlockFactory : public BlockFactory
{
public:
    Block *createBlock() override
    {
        return new SquareBlock();
    }
};

class BlockFactorySystem
{
private:
    vector<Block *> blocks;

public:
    void produceBlocks(BlockFactory *factory, int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            Block *block = factory->createBlock();
            blocks.push_back(block);
            block->produce();
        }
    }
    const vector<Block *> &getBlocks() const
    {
        return blocks;
    }
    ~BlockFactorySystem()
    {
        for (Block *block : blocks)
        {
            delete block;
        }
    }
};

int main()
{
    BlockFactorySystem factorysystem;
    int productionCount;
    cin >> productionCount;
    for (int i = 0; i < productionCount; i++)
    {
        string blockType;
        int quantity;
        cin >> blockType >> quantity;
        if (blockType == "Circle")
        {
            factorysystem.produceBlocks(new CircleBlockFactory(), quantity);
        }
        else if (blockType == "Square")
        {
            factorysystem.produceBlocks(new SquareBlockFactory(), quantity);
        }
    }
    system("pause");
    return 0;
}
