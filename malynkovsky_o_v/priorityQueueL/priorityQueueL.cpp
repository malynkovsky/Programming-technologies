#include "priorityQueueL.h"
#include <iostream> 

PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs){
    Node* node = rhs.pHead_;
    while (!isEmpty()) {
        push(node->data_);
        node = node->pNext_;
    }
}

PriorityQueueL::~PriorityQueueL(){
    while (!isEmpty()){
        pop();
    }
    //pTail_ = nullptr;
}

PriorityQueueL & PriorityQueueL::operator=(const PriorityQueueL & rhs){
    Node* node = rhs.pHead_;
    while (node != nullptr) {
        push(node->data_);
        node = node->pNext_;
    }
    return *this;
}

void PriorityQueueL::push(const int & rhs){
    if (isEmpty() || rhs > pHead_->data_)
    {
        pHead_ = new Node(pHead_, rhs);
        return;
    }
    Node* start = pHead_;
    Node* end = pHead_->pNext_;
    while (end != nullptr && end->data_ > rhs)
    {
        start = end;
        end = end->pNext_;
    }
    start->pNext_ = new Node(start->pNext_, rhs);
}

void PriorityQueueL::pop(){
    if (!isEmpty())
    {
        Node* pDel(pHead_);
        pHead_ = pHead_->pNext_;
        delete pDel;
    }
    else {
        throw std::runtime_error("PriorityQueueL is empty already");
    }
}

int & PriorityQueueL::top(){
    if (!isEmpty()) {
        return pHead_->data_;
    } else {
        throw std::runtime_error("PriorityQueueL is empty already");
    }
}

const int & PriorityQueueL::top() const{
    if (!isEmpty()) {
        return pHead_->data_;
    }
    else {
        throw std::runtime_error("PriorityQueueL is empty already");
    }
}

bool PriorityQueueL::isEmpty() const{
    return  pHead_ == nullptr;
}

std::ostream & PriorityQueueL::writeTo(std::ostream & ostrm){
    if (!isEmpty()) {
        PriorityQueueL writing(*this);

        while (!writing.isEmpty()) {

            ostrm << " " << writing.top() << "  ";
            writing.pop();
        }
    }
    return ostrm;
}

std::ostream & operator<<(std::ostream& ostrm, PriorityQueueL& rhs){
    return rhs.writeTo(ostrm);
}

PriorityQueueL::Node::Node(Node* pNext, const int& rhs)
    :pNext_{ pNext }, data_{ rhs }
{
}
