#include "stackL.h"
#include <iostream>

StackL::StackL(const StackL & rhs)
{
    StackL obj;
    Node* node = rhs.pHead_;
    while (node != nullptr) {
        obj.push(node->data_);
        node = node->pNext_;
    }
    node = obj.pHead_;
    while (!obj.isEmpty()) {
        push(obj.top());
        obj.pop();
    }
}

StackL::~StackL(){
    while (!isEmpty())
        pop();
    pHead_ = nullptr;
}

StackL & StackL::operator=(const StackL& rhs){
    StackL obj;
    Node* node(rhs.pHead_);

    while (node != nullptr) {
        obj.push(node->data_);
        node = node->pNext_;
    }
    while (!obj.isEmpty()) {
        push(obj.top());
        obj.pop();
    }

    return *this;
}

void StackL::push(const int & rhs){
    pHead_ = new Node(pHead_, rhs);
}

void StackL::pop(){
    if (!isEmpty()) {
        Node* Del(pHead_);
        pHead_ = Del->pNext_;
        delete Del;
    }
}

int & StackL::top(){
    if (!isEmpty()) {
        return  pHead_->data_;
    }
}

const int & StackL::top() const{
    if (!isEmpty()) {
        return  pHead_->data_;
    }
}

bool StackL::isEmpty() const
{
    return pHead_ == nullptr;
}

std::ostream & StackL::writeTo(std::ostream & ostrm){
    StackL rhs(*this);
    while (!rhs.isEmpty()) {
        ostrm << " " << rhs.top() << ",  ";
        rhs.pop();
    }
    return ostrm;
}

StackL::Node::Node(Node* pNext, const int& rhs)
    :pNext_(pNext), data_(rhs)
{
}

std::ostream & operator<<(std::ostream & ostrm, StackL & rhs){
    return rhs.writeTo(ostrm);
}
