#include<memory>
#include<functional>
#include<type_traits>
#include<string>
#include"Vector.h"
int main()
{
    Vector<int> arr{1,2,3,4};
    std::cout << *arr.begin() << std::endl;
    std::cout << *arr.cbegin() << std::endl;
    std::cout << arr[2] << std::endl;
}