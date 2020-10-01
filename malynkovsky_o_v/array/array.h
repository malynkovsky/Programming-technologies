#ifndef ARRAY_CAT
#define ARRAY_CAT

#include<iostream>
using namespace std;

class Array 
{
public:
    Array() = default;
    Array(const ptrdiff_t& s);
    Array(const Array& rhs);
    ~Array();
    Array& operator=(const Array& a);
    int& operator[](const ptrdiff_t index);
    const int& operator[](const ptrdiff_t index) const;
    ptrdiff_t Size() const { return size; }
    ptrdiff_t Length() const { return length; }
    void Resize(const int& a);
    void Add(const int& a);
    std::ostream& writeTo(std::ostream& ostr);
private:
    ptrdiff_t size{ 0 };
    ptrdiff_t length{ 0 };
    int* pdata{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, Array& b)
{
    return b.writeTo(ostrm);
}

#endif