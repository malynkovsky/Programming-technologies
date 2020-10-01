#include "array.h"
#include <iostream>
#include <stdexcept>

Array::~Array()
{
    delete[] pdata;
    pdata = nullptr;
    size = 0;
    length = 0;
}

Array::Array(const ptrdiff_t & s)

{
    pdata = new int[s];
    size = s;
}

Array::Array(const Array & rhs)

{
    pdata = new int[rhs.size];
    for (ptrdiff_t i(0); i < rhs.length; i++)
    {
        pdata[i] = rhs[i];
    }
    size = rhs.size;
    length = rhs.length;
}

int & Array::operator[](const ptrdiff_t index)
{
    return pdata[index];
}

const int & Array::operator[](const ptrdiff_t index) const
{
    return pdata[index];
}

void Array::Resize(const int & a)
{
    if (length < a) {
        int *newarr = new int[a];
        for (ptrdiff_t i(0); i < length; i++) {
            newarr[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newarr;
        size = a;
    }
    else {
        int *newarr = new int[a];
        for (ptrdiff_t i(0); i < a; i++) {
            newarr[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newarr;
        size = a;
        length = a;
    }
}

void Array::Add(const int & a)
{
    if (length < size) {
        pdata[length++] = a;
        /*return;*/
    }
    else {
        Resize(size * 2);
        pdata[length++] = a;
        /*return;*/
    }
}

std::ostream & Array::writeTo(std::ostream & ostr)
{
    for (ptrdiff_t i(0); i < length; i++)
        ostr << "A[" << i << "] = " << pdata[i] << "    ";
    return ostr;
}

Array & Array::operator=(const Array & a)
{
    if (pdata == a.pdata
        && a.size == size
        && a.length == length) return *this;
    pdata = new int[a.size];
    for (ptrdiff_t i(0); i < a.length; i++)
    {
        pdata[i] = a[i];
    }
    size = a.size;
    length = a.length;
    return *this;
}
