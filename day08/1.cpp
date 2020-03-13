#include <iostream>
#include <memory>

struct Task
{
    int mId;
    Task(int id) : mId(id)
    {
        std::cout << "Task::Constructor" << std::endl;
    }
    ~Task()
    {
        std::cout << "Task::Destructor" << std::endl;
    }
};

int main()
{
    // 空对象 unique_ptr
    std::unique_ptr<int> ptr1;

    // 检查 ptr1 是否为空
    if (!ptr1)
        std::cout << "ptr1 is empty" << std::endl;

    // 检查 ptr1 是否为空
    if (ptr1 == nullptr)
        std::cout << "ptr1 is empty" << std::endl;

    // 不能通过赋值初始化unique_ptr
    // std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error

    // 通过原始指针创建 unique_ptr
    std::unique_ptr<Task> taskPtr(new Task(23));

    // 检查 taskPtr 是否为空
    if (taskPtr != nullptr)
        std::cout << "taskPtr is  not empty" << std::endl;

    // 访问 unique_ptr关联指针的成员
    std::cout << taskPtr->mId << std::endl;

    std::cout << "Reset the taskPtr" << std::endl;
    // 重置 unique_ptr 为空，将删除关联的原始指针
    taskPtr.reset();

    // 检查是否为空 / 检查有没有关联的原始指针
    if (taskPtr == nullptr)
        std::cout << "taskPtr is  empty" << std::endl;

    // 通过原始指针创建 unique_ptr
    std::unique_ptr<Task> taskPtr2(new Task(55));

    if (taskPtr2 != nullptr)
        std::cout << "taskPtr2 is  not empty" << std::endl;

    // unique_ptr 对象不能复制
    //taskPtr = taskPtr2; //compile error
    //std::unique_ptr<Task> taskPtr3 = taskPtr2;

    {
        // 转移所有权（把unique_ptr中的指针转移到另一个unique_ptr中）
        std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
        // 转移后为空
        if (taskPtr2 == nullptr)
            std::cout << "taskPtr2 is  empty" << std::endl;
        // 转进来后非空
        if (taskPtr4 != nullptr)
            std::cout << "taskPtr4 is not empty" << std::endl;

        std::cout << taskPtr4->mId << std::endl;

        //taskPtr4 超出下面这个括号的作用于将delete其关联的指针
    }

    std::unique_ptr<Task> taskPtr5(new Task(66));

    if (taskPtr5 != nullptr)
        std::cout << "taskPtr5 is not empty" << std::endl;

    // 释放所有权
    Task *ptr = taskPtr5.release();

    if (taskPtr5 == nullptr)
        std::cout << "taskPtr5 is empty" << std::endl;

    std::cout << ptr->mId << std::endl;

    delete ptr;

    return 0;
}