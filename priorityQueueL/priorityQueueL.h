#pragma once
#ifndef PRIORITYQUEUEL_KOSHKA
#define PRIORITYQUEUEL_KOSHKA
#include <iosfwd>

class PriorityQueueL
{
public:
    PriorityQueueL() = default;
    PriorityQueueL(const PriorityQueueL& rhs);
    ~PriorityQueueL();
    PriorityQueueL&operator=(const PriorityQueueL& rhs);
    void push(const int& rhs);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;
    std::ostream& writeTo(std::ostream& ostrm);
private:
    struct Node
    {
        Node(Node* pNext, const int& rhs);
        Node(Node *pNext);
        Node* pNext_{ nullptr };
        int data_{ 0 };
    };
    Node* pHead_{ nullptr };
    Node* pTail_{ nullptr };
};
std::ostream& operator<<(std::ostream& ostrm, PriorityQueueL& rhs);
#endif
