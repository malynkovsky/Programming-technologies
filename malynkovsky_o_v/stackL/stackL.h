#ifndef ABCDEFG
#define ABCDEFG
#include <iosfwd>

class StackL 
{
public:
    StackL() = default;
    StackL(const StackL& rhs);
    ~StackL();
    StackL& operator=(const StackL& rhs);
    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;
    std::ostream& writeTo(std::ostream& ostrm);
private:
    struct Node 
    {
        Node(Node* pNext, const int& rhs);
        Node* pNext_{ nullptr };
        int data_{ int(0) };
    };
    Node* pHead_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, StackL& rhs);
#endif
