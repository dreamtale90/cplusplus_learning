#include <iostream>

//1. 自动类型推导
//2. template使用中函数后返回值占位
//Note: auto作为函数返回值时，只能用于定义函数，不能用于声明函数

//g++ note: deduced return type only available with -std=c++1y or -std=gnu++1y
auto AddTest(int a, int b)
{
    return a + b;
}

int main()
{
    auto index = 10;
    auto str = "abc";
    auto ret = AddTest(1,2);
    std::cout << "index:" << index << std::endl;
    std::cout << "str:" << str << std::endl;
    std::cout << "res:" << ret << std::endl;
}

#if 0
template <typename Creator>
auto processProduct(const Creator& creator) -> decltype(creator.makeObject()) {
    auto val = creator.makeObject();
    // do somthing with val
}
#endif
