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
};

int main()
{
    return 0;
}