#pragma once

class QueueArray
{
    private:
        int *arr;
        int cap;
        int count;
        int front;
        int rear;
    public:
        void enqueue(int data);
        void dequeue();
        int peekFront();
        int peekRear();
        int circArr(int index);
        void circArr(int index, int val);
        bool isEmpty();
        bool isFull();
        int size();
        void print();

        QueueArray(int cap);
        ~QueueArray();
};