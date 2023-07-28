// task-29.7.1-20230726.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mutex>

struct Node
{
    int value;
    Node* next;
    std::mutex* node_mutex;
};

class FineGrainedQueue
{
    Node* head;
    std::mutex* queue_mutex;

public:
    void insertIntoMiddle(int value, int pos)
    {
        queue_mutex->lock();

        Node* prev = this->head;
        Node* cur = this->head->next;

        prev->node_mutex->lock();
        queue_mutex->unlock();

        if (cur != nullptr)
        {
            cur->node_mutex->lock();
        }
        while (cur != nullptr)
        {
            for (int i = 0; i < pos; ++i)
            {
                Node* old_prev = prev;
                prev = cur;
                cur = cur->next;
                old_prev->node_mutex->unlock();
            }
            if (cur != nullptr)
            {
                cur->node_mutex->lock();
            }
        }
        Node* node = new Node;
        node->value = value;
        node->next = cur;
        prev->next = node;
        prev->node_mutex->unlock();
        cur->node_mutex->unlock();
    }
};


int main()
{
    return 0;
}