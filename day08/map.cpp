#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{

    //定义一个map对象
    map<int, string> mapStudent;

    //第一种 用insert函數插入pair
    mapStudent.insert(pair<int, string>(000, "student zero"));

    //第二种 用insert函数插入value_type数据
    mapStudent.insert(map<int, string>::value_type(001, "student one"));

    //第三种 用"array"方式插入
    mapStudent[123] = "student 123";
    mapStudent[456] = "student 456";

    return 0;
}