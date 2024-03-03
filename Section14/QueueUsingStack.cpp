#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *s;
    int size;
public:
    Stack(int size)
    {
        this->size = size;
        s = new int[this->size];
        top = -1;
    }    
    Stack(){top = -1;}
    void create(int size)
    {
        this->size = size;
        s = new int[this->size];
        top = -1;
    }    
    bool isEmpety()
    {
        if(top == -1)return true;
        else return false;
    }
    bool isFull()
    {
        if(top == size-1)
            return true;
        else 
            return false;    
    }
    void push(int x)
    {
        if(isFull())
            cout << "Stack overflow" << endl;
        else
            s[++top] = x;
            
    }
    int pop()
    {
        if(isEmpety())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }    
        else    
            return s[top--];   
    }
    int peek(int position)
    {
        if(position <= top && position > 0)
            return s[top-position+1]; //considering top is element 1
        else
        { 
            cout << "Error out of index" << endl;
            return -1;    
        }
    }

    void display()
    {
       for(int i = top; i >= 0; i--)
        {
        cout << "-----------" << endl;//11 top of first block
            for(int j = 0; j < 1; j++)
                cout << "|         |" << endl;//10 loop 1 times,  
        cout << "|   " << s[i];
        if(s[i] >= 10)cout << "    |" << endl;
        else cout << "     |" << endl;
            for(int k = 0; k < 1; k++)
        cout << "|         |" << endl;//10 loop 1 times 
        }
        cout << "-----------" << endl << endl << endl;//11 bottom of last block down

    }

    void BasicDisplay()
    {
        for(int i = 0; i < size; i++)
            cout << s[i] << ' ';
        cout << endl;    
    }
};

class Queue
{
private:
    Stack s1,s2;
    //s2 for poping and s1 for pushing
public:
    void create(int s)
    {
        s1.create(s);
        s2.create(s);
    }
    void enqueue(int x)
    {
        if(s1.isFull())
            cout << "Overflow" << endl;
        else
        {
            s1.push(x);
        }    
    }

    int dequeue()
    {
        if(!s2.isEmpety())
        {
            return s2.pop();
        }
        
        else if(s2.isEmpety() && !s1.isEmpety())
        {
            while(!s1.isEmpety())
            {
                s2.push(s1.pop());
            }
            return s2.pop();
        }
        
        else if(s2.isEmpety() && s1.isEmpety())
            cout << "UnderFlow" << endl;
    }    

    void display()
    {
        cout << "S1: "; s1.BasicDisplay();
        cout << "S2: "; s2.BasicDisplay();
    }
};

int main()
{
    Queue q;
    q.create(10);
    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);

    cout << q.dequeue() << endl; // 6
    q.enqueue(4);
    q.enqueue(2);
    cout << q.dequeue() << endl; // 3
    
    
    cout << q.dequeue() << endl; // 9
    cout << q.dequeue() << endl; // 5
    cout << q.dequeue() << endl; // 4
    cout << q.dequeue() << endl; // 2

}