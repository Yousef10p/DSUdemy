#include<iostream>
using namespace std;

class node
{
private:
    int data;
    node *next;
public:
    node(int x)
    {
        data = x;
        next = NULL;
    }

    node()
    {
        next = NULL;
    }
    void setdata(int x)
    {
        data = x;
    }
    int getdata()
    {
        return data;
    }

    node *getnext()
    {
        return next;
    }

    void setnext(node *ptr)
    {
        next = ptr;
    }    
};

class list
{
    private:
    node *head;

public:
    list()
    {
        head = NULL; // emptey intially
    }
    void create(int input)
    {
        node *p = new node(input);
        head = p;
    }
    void addNewElementasHead(int input)
    {
        node *p = new node(input);
        p->setnext(head); // p->next = head;
        head = p;
    }

    void removeElement() // remove head
    {
        node *ptr = head;
        head = head->getnext(); // head = head->next;
        ptr->setnext(NULL);
        delete ptr;
    }

    void display()
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->getdata() << ' ';
            ptr = ptr->getnext();
        }
        cout << endl;
    }

    int countNodes()
    {
        int count = 0;
        node *ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->getnext();
        }
        return count;
    }

    void setHead(node *ptr)
    {
        head = ptr;
    }
};

class queue
{
private:
    node* front;
    node* rare;
    list q;
public:
    queue()
    {
        front = rare = NULL;//empety
    }

    bool emptey()
    {
        if(front == NULL)
            return true;
        else 
            return false;    
    }

    bool full()
    {
        node *ptr = new node;
        if(ptr == NULL)
            return true;
        else 
            return false;    
        
    }

    void enqueue(int x)
    {
        
        if(full())
            cout << "Error Full" << endl;
        else
            {
                node *n = new node(x);
                if(front == NULL)//means empety
                {
                    front = rare = n;
                    q.setHead(n);
                }
                else
                {
                    rare->setnext(n);
                    rare = n;
                    
                }
            }
    }

    int dequeue()
    {
        int x = -1;
        node *temp;
        if(emptey())
        {
            cout << "Empety " << endl;
        }
        else
        {
            temp = front;
            front = front->getnext();
            q.setHead(front);
            x = temp->getdata();
            delete temp;
            return x;
        }
    }

    void display()
    {
        q.display();
    }

};

int main()
{
    queue k;
    k.enqueue(10);
    k.enqueue(20);
    k.enqueue(30);
    k.display();
    
    cout << "Quit: " <<  k.dequeue() << endl;
    //k.display();

    cout << "Quit: " <<  k.dequeue() << endl << "Display: ";
    k.display();

    cout << "Quit: " <<  k.dequeue() << endl;
    //k.display();

}