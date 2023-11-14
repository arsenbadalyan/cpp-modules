#pragma once
#ifndef ARRAY__HPP__
#define ARRAY__HPP__

#include <iostream>

template <typename T>
class Array {

    public:
        Array( void )
        {
            this->list = new T[0];
            this->length = 0;
        }
        Array( unsigned int n )
        {
            T *temp = new T();
            this->list = new T[n];
            for (unsigned int i = 0; i < n; i++)
                this->list[i] = *temp;
            this->length = n;

            delete temp;
        }
        Array( const Array<T>& copy )
        {
            if (this == &copy)
                return ;
            (*this) = (*copy);
        }
        ~Array()
        {
            if (*(this->list))
                delete[] this->list;
        }

    public:
        Array<T>& operator=( const Array<T>& rhs )
        {
            if (this->list)
                delete[] this->list;

            this->list = new T[rhs.size()];
            for (unsigned int i = 0; i < this->length; i++)
                this->list[i] = rhs.list[i];
            this->length = rhs.length;

            return (*this);
        }

        T& operator[]( unsigned int index )
        {
            if (index >= this->size())
                throw std::runtime_error("Index is out of bounds!");
            return (this->list[index]);
        }

    public:
        unsigned int size( void ) const
        {
            return (this->length);
        }

    private:
        T* list;
        unsigned int length;
};

template<typename T>
std::ostream& operator<<( std::ostream & os, const T& item )
{
    os << item;
    return (os);
}

#endif // !ARRAY__HPP__