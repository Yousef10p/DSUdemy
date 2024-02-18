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
        p->setnext(head);
    }
    void addNewElementasHead(int input)
    {
        node *p = new node(input);
        p->setnext(head);
        node *temp = head;
        while(true)
            if(temp->getnext() == head)
            {
                temp->setnext(p);
                head = p;
                break;
            }
            else 
                temp = temp->getnext();
        
    }

    void display()
    {
        node *x = head;
        do
        {
            cout << x->getdata() << ' ';
            x = x->getnext();
        }while(x != head);
        cout << endl << endl;
    }

    void deleteHead()
    {
        node *temp = head;
        while(temp->getnext() != head)
            temp = temp->getnext();
        temp->setnext(head->getnext());
        temp = head;
        head = head->getnext();
        delete temp;    
    }

    void deleteByKey(int key)
    {
        node *temp = head , *temp2;
        while(temp->getnext()->getdata() != key)
            temp = temp->getnext();
        if(temp->getnext()->getnext() == head)
            {
                temp2 = temp->getnext();
                temp->setnext(head);
                delete temp2;
            } 
        else if(temp->getnext() == head)
            deleteHead();
        else 
            {   
                temp2 = temp->getnext();
                temp->setnext(temp->getnext()->getnext());
                delete temp2;
            }           
    }

};

int main()
{
    list myList;
    int choice,input;
    bool bbb = true;
    do
    {
        cout << "Enter 0 to terminate" << endl;
        cout << "Enter 1 to create a list: " << endl;
        cout << "Enter 2 to add new element: " << endl;
        cout << "Enter 3 to delete head: " << endl;
        cout << "Enter 4 to delete by key: " << endl;
        cout << "Enter 5 to display: " << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
                bbb = false;
            break;    
        case 1:
            cout << "Enter data for the first element: ";
            cin >> input;
            myList.create(input);
            break;
        
        case 2:
            cout << "Enter data for the new element: ";
            cin >> input;
            myList.addNewElementasHead(input);
            break;

        case 3:
            myList.deleteHead();
            break;

        case 4:
            cout << "Enter key for the element to delete it: ";
            cin >> input;
            myList.deleteByKey(input);
            break;

        case 5:
            myList.display();
            break;            
        default:
            cout << "Error" << endl;
            break;
        }
        cout << endl <<  "--------------------------------------------------------------------------" << endl;
    } while (bbb);
        //some missing functions not needed to be here since its same the singly linked list in other file
}   