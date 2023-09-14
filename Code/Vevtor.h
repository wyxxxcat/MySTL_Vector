#pragma once
#include<iostream>
#include<memory>
#include<type_traits>

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
    using iterator = T*;
    using const_iterator = const T*;
public:
    Vector(unsigned count);
    Vector(const std::initializer_list<T>& list);
    Vector(const std::initializer_list<T>&& list);
    ~Vector();
    iterator begin();
    const_iterator cbegin() const;
    T* data;
    T& operator[](unsigned count)
    {
        return data[count];
    }
};
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
        unsigned cnt = 0;
        data = new T[list.size()]();
        if(std::is_pointer<T>::value)
        {
            for(auto item : list)
            {
                data[cnt++] = new typename get_type<T>::type(*item);
            }
        }else
        {
            for(const auto& item : list)
            {
                data[cnt++] = item;
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
        unsigned cnt = 0;
        data = new T[list.size()]();
        for(const auto& item : list)
        {   
            data[cnt++] = item;
        }
    }else
    {
        data = nullptr;
    }
}