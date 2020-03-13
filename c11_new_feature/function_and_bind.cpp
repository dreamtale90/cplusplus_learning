#include <iostream>
#include <functional>

class Test
{
    public:
        //std::function<int(int,int)>表示std::function封装的可执行对象返回值和两个参数均为int类型
        void Add(std::function<int(int, int)> fun, int a, int b)
        {
            int sum = fun(a, b);
            std::cout << "sum:" << sum << std::endl;
        }
};

//traditional usage
int add(int a,int b)
{
    std::cout << "add" << std::endl;
    return a + b;
}

//c11 new usage
class TestAdd
{
    public:
        int Add(int a,int b)
        {
            std::cout << "TestAdd::Add" << std::endl;
            return a + b;
        }
};

int main()
{
    Test test;
    test.Add(add, 1, 2);

    TestAdd testAdd;
    /*
     * std::bind第一个参数为对象函数指针，表示函数相对于类的首地址的偏移量；
     * testAdd为对象指针；
     * std::placeholders::_1和std::placeholders::_2为参数占位符，表示std::bind封装的可执行对象可以接受两个参数。
     */
    test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

    //lamda
    test.Add([](int a, int b)->int {
            std::cout << "lamda add fun" << std::endl;
            return a + b;
            },1,2);

    return 0;
}
