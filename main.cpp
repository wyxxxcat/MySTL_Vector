#include<memory>
#include<functional>
#include<type_traits>
#include<string>
#include"Vector.h"
int main()
{
    Vector<int> arr{1,2,3,4};
    std::cout  << "arr.size() is " << arr.size() << std::endl;
    std::cout  << " *arr.begin() is " << *arr.begin() << std::endl;
    std::cout << "*arr.cbegin() is " << *arr.cbegin() << std::endl;
    std::cout  << "arr[2] is " << arr[2] << std::endl;
    
    arr.push_back(3);
    std::cout  << "arr.size() is " << arr.size() << std::endl;
    for(int i = 0;i < 4;i ++)
    {
        std::cout << arr[i] << ' ' << i << std::endl;
    }
    return 0;
}