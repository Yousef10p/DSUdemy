#include<iostream>
using namespace std;


class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(){}
    void create(int size)
    {
        this->size = size;
        Q = new int[this->size];
        rear = -1;
        front = -1;
    }

    bool isFull()
    {
        if((rear + 1) % size == front)//if in any case rear is before full in one element then its full, note here 1 element must be not used which front ponints to
            return true;
        else
            return false;

    }

    bool isEmptey()
    {
        if(rear == front)
            return true;
        else 
            return false;    
    }

    void enqueue(int x)
    {
        if(isFull())
            cout << "Error overflow" << endl;
        else
        {
            rear = (rear + 1) % size;     
            Q[rear] = x;
        }    
    }

    int dequeue()
    {
        if(isEmptey())
            return -1;
        else
        {   
            front  = (front + 1)%size;
            return Q[front];    
        }    
    } 

    void display()
    {   
        int i = (front+1) % size;
        do{
            
            cout << Q[i] << ", ";
            i = (i + 1) % size;
        }while(i != (rear + 1) % size);
        cout << endl;
    }   
};

int main()
{
    Queue q;
    q.create(5);
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i);
    }
    q.display();  
    q.dequeue();
    q.dequeue();  
    q.display();
}