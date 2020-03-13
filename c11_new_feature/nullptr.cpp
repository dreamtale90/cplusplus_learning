#include <iostream>

class Test
{
    public:
        void TestWork(int index)
        {
            std::cout << "TestWork 1" << std::endl;
        }
        void TestWork(int * index)
        {
            std::cout << "TestWork 2" << std::endl;
        }
};

//NULL在c++里表示空指针，看到问题了吧，我们调用test.TestWork(NULL)，
//其实期望是调用的是void TestWork(int * index)，但结果调用了
//void TestWork(int index)。但使用nullptr的时候，我们能调用到正确的函数。
int main()
{
    Test test;
    //test.TestWork(NULL);    //TestWork 1
    test.TestWork(nullptr); //TestWork 2
}
