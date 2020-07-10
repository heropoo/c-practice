#include <iostream>
<<<<<<< HEAD
 
using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line(double len); // 这是构造函数

private:
    double length;
};

// 成员函数定义，包括构造函数
Line::Line(double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}
// 程序的主函数
int main()
{
    Line line(10.0);

    // 获取默认设置的长度
    cout << "Length of line : " << line.getLength() << endl;
    // 再次设置长度
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

=======
using namespace std;

class Adder
{
public:
    Adder(int i = 0) : total(i) {}

    void addNum(int i)
    {
        total += i;
    }

    int getTotal()
    {
        return total;
    }

private:
    int total;
};

int main()
{
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total " << a.getTotal() << endl;
>>>>>>> 1c63da0264ac08aadc4f95bf76b5340b6ddd5a09
    return 0;
}