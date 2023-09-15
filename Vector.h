#pragma once
#include<iostream>
#include<memory>
#include<type_traits>
using void_func_type = std::function<void(int&)>;
template<typename iter_type,typename func_type = void_func_type>
void for_each(iter_type first,iter_type last,func_type func = [](int& elem){
    std::cout<<elem<<' ';
    ++elem;
})
{
    for(auto iter = first;iter <= last;++iter)
    {
        func(*iter);
    }
}
template<typename T>
struct get_type
{
    using type = T;
};

template<typename T>
struct get_type<T*>
{
    using type = T;
};

template<typename T>
class Vector
{
    using void_func_type = std::function<void(int&)>;
    using iterator = T*;
    using const_iterator = const T*;
public:
    T* data;
    unsigned size_ = 0;
    Vector(unsigned count);
    Vector(const std::initializer_list<T>& list);
    Vector(const std::initializer_list<T>&& list);
    ~Vector();
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    void push_back(const T& dt);
    unsigned size();
    T& operator[](unsigned count)
    {
        return data[count];
    }
};
template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return data + this->size_ - 1;
}
template<typename T>
unsigned Vector<T>::size()
{
    return this->size_;
}
template<typename T>
Vector<T>::Vector(unsigned count)
{
    if(count)
    {
        data = new T[count]();
    }else
    {
        data = nullptr;
    }
}
template<typename T>
void Vector<T>::push_back(const T& dt)
{
    data[this->size_] = std::move(dt);
    this->size_++;
}
template<typename T>
Vector<T>::~Vector()
{
    if(data)
    {
        delete[] data;
        data = nullptr;
    }
}
template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return data;
}
template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin()const
{
    return data;
}
template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& list)
{
    if(list.size())
    {
        data = new T[list.size() * 2]();
        if(std::is_pointer<T>::value)
        {
            for(auto item : list)
            {
                data[this->size_ ++] = new typename get_type<T>::type(*item);
            }
        }else
        {
            for(const auto& item : list)
            {
                data[this->size_ ++] = std::move(item);
            }
        }
    }else
    {
        data = nullptr;
    }
}
template<typename T>
Vector<T>::Vector(const std::initializer_list<T>&& list)
{
    if(list.size())
    {
        data = new T[list.size() * 2]();
        for(const auto& item : list)
        {   
            data[this->size_++] = item;
        }
    }else
    {
        data = nullptr;
    }
}