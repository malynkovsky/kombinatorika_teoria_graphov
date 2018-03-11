#include "priorityQueueL.h"
#include <iostream> 

PriorityQueueL::PriorityQueueL(const PriorityQueueL& rhs){
    Node* node(rhs.pHead_);
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
    if (isEmpty())
    {
        pHead_ = new Node(nullptr, rhs);
        pTail_ = pHead_;
    }
    else
    {
        Node* head = pHead_;
        if (pTail_ == pHead_)
        {
            if (pHead_->data_ < rhs) {
                pHead_->pNext_ = new Node(nullptr, rhs);
                pTail_ = pHead_;
                pHead_ = pHead_->pNext_;
            }
            else {
                pTail_ = new Node(pHead_, rhs);
            }
            return;
        }
        if (pTail_->data_ > rhs) {
            pTail_ = new Node(pTail_, rhs);
            return;
        }
        while (head->pNext_->data_ < rhs)
        {
            head = head->pNext_;
            if (head->pNext_ == nullptr) {
                head->pNext_ = new Node(nullptr, rhs);
                pHead_ = head->pNext_;
                return;
            }
        }
        head->pNext_ = new Node(head->pNext_, rhs);
    }
    /*if (isEmpty() || rhs > pHead_->data_)
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
    start->pNext_ = new Node(start->pNext_, rhs);*/
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
    return  (pHead_ == nullptr);
}

std::ostream & PriorityQueueL::writeTo(std::ostream & ostrm){
    if (!isEmpty()) {
        PriorityQueueL showQ(*this);
        while (!showQ.isEmpty()) {

            ostrm << " " << showQ.top() << "  ";
            showQ.pop();
        }
    }
    return ostrm;
}

std::ostream & operator<<(std::ostream& ostrm, PriorityQueueL& rhs){
    return rhs.writeTo(ostrm);
}

PriorityQueueL::Node::Node(Node* pNext, const int& rhs)
    :pNext_{ pNext }, data_{ rhs }{
}

PriorityQueueL::Node::Node(Node * pNext)
    : pNext_(pNext),
    data_(double(0.0)){
}
