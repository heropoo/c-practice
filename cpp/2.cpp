#include <iostream>

using namespace std;

<<<<<<< HEAD
class Box
{
public:
    double length;
    double width;
    double height;
    Box();  //构造函数 与类同名
    void say(char *msg);    
};

// 成员函数定义，包括构造函数
Box::Box()
{
    cout << "Object is being created" << endl;
}

void Box::say(char *msg){
    cout << msg <<endl;
}



int main()
{
    Box Box1;            // 声明 Box1，类型为 Box
    Box Box2;            // 声明 Box2，类型为 Box
    double volume = 0.0; // 用于存储体积



     // box 1 详述
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.width = 7.0;
 
   // box 2 详述
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.width = 13.0;

   // box 1 的体积
   volume = Box1.height * Box1.length * Box1.width;
   cout << "Box1 的体积：" << volume <<endl;

    // box 2 的体积
   volume = Box2.height * Box2.length * Box2.width;
   cout << "Box2 的体积：" << volume <<endl;

   Box1.say("fsdfsdf");
=======
// 基类
class Shape
{
public:
    // 提供接口框架的纯虚函数
    virtual int getArea() = 0;
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    int getArea()
    {
        return (width * height) / 2;
    }
};

int main(void)
{
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;
>>>>>>> 1c63da0264ac08aadc4f95bf76b5340b6ddd5a09

    return 0;
}