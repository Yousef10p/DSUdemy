#include<iostream>
using namespace std;

class node
{
private:
    node *prev;
    int data;
    node *next;
public:
    node()
    {
        prev = NULL;
        next = NULL;
    }
    node(int input)
    {
        prev = NULL;
        data = input;
        next = NULL;
    }

    void setNext(node *ptr)
    {next = ptr;}
    void setPrev(node *ptr)
    {prev = ptr;}
    node *getNext()
    {return next;}
    node *getPrev()
    {return prev;}
    void setData(int input)
    {data = input;}
    int getData()
    {return data;}
};

class list
{
private:
    node *head;
public:
    list()
    {
        head = NULL;
    }

    void create(int input)
    {
        node *ptr = new node(input);
        head = ptr;
    }

    void inseartHead(int input)
    {
        node *p = new node(input);
        p->setPrev(NULL);
        p->setNext(head);
        head->setPrev(p);
        head = p;
    }

    int count()
    {
        int counter = 0;
        node *temp = head;
        while(temp != NULL)
        {
            counter++;
            temp = temp->getNext();
        }
        return counter;
    }
    void inseartIndex(int input,int index)
    {   
        node *p = new node(input);
        node *temp = head;
        int counter = 1;
        if(index == 0)
            inseartHead(input);
        else if (index == count())//last element    
        {
            while(temp->getNext() != NULL)
            {   
                temp = temp->getNext();
            }
            temp->setNext(p);
            p->setPrev(temp);
            p->setNext(NULL);
        }

        else if(index < count() && index > 0)
        {
           while(counter != index)
           {
            temp = temp->getNext();
            counter++;
           }
           temp->getNext()->setPrev(p);
           temp->setNext(p);     
        }
    }

    void deleteHead()
    {
        node *ptr = head;
        head = head->getNext();
        head->setPrev(NULL);
        ptr->setNext(NULL);
        delete ptr;
    }

    void deleteByIndex(int index)
    {
        int counter = 1;
        node *ptr = head;

        while(counter != index)
        {
            counter++;
            ptr = ptr->getNext();
        }
        ptr->getPrev()->setNext(ptr->getNext());
        ptr->getNext()->setPrev(ptr->getPrev());
        delete ptr;
    }

    void display()
    {
        node *ptr = head;
        while(ptr != NULL)
        {
            cout << ptr->getData() << ' ';
            ptr = ptr->getNext();
        }
        cout << endl << endl;
    }

};

int main()
{
    list mylist;
    int choice;
    int input;
    int index;
    bool check = true;

    do
    {
        cout << "Enter 1 to create list: " << endl;
        cout << "Enter 2 to inseart in head: "<< endl;
        cout << "Enter 3 to inseart in index: "<< endl;
        cout << "Enter 4 to delete head: "<< endl;
        cout << "Enter 5 to delete index: "<< endl;
        cout << "Enter 6 to display: "<< endl;
        cout << "Enter 0 to terminate: "<< endl;
        cout << "input: ";
        cin >> input;

        switch (input)
        {
            case 0: 
                check = false;
                break;
            case 1: 
                cout << "Enter input: ";
                cin >> input;
                mylist.create(input);
                break;
            case 2:
                cout << "Enter input: ";
                cin >> input;
                mylist.inseartHead(input);
                break;
            case 3:
                cout << "Enter input: ";
                cin >> input;
                cout << "Enter index: ";
                cin >> index;
                mylist.inseartIndex(input,index);
                break;
            case 4:
                mylist.deleteHead();
                break;
            case 5:
                cout << "Enter index: ";
                cin >> index;
                mylist.deleteByIndex(index);
                break;
            case 6:
            mylist.display();
            break;
            default: 
                cout << "Error" << endl;                                      
                break;
        }
    } while (check);
    
}