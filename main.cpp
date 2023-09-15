#include<memory>
#include<iostream>
#include<functional>
#include<type_traits>
#include<string>
#include<algorithm>
#include"Vector.h"
int main()
{
    Vector<int> a{1,2,4,5,6};
    std::cout << a.size() << std::endl;
    for_each(a.begin(),a.end(),[](int& x) ->void
    {
        x%=2;
    });
    for_each(a.begin(),a.end());
    return 0;
}