// linked-list
#include <iostream>
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
    void create()
    {
        int input;
        cout << "Enter data: ";
        cin >> input;
        node *p = new node(input);
        head = p;
    }
    void addNewElement()
    {
        int input;
        cout << "Enter data: ";
        cin >> input;
        node *p = new node(input);
        p->setnext(head); // p->next = head;
        head = p;
    }
    void removeElement()
    {
        node *ptr = head;
        head = head->getnext(); // head = head->next;
        ptr->setnext(NULL);     // ptr->next = NULL;
    }

    void removeElementByKey()
    {
        int key;
        cout << "Enter data value: ";
        cin >> key;

        node *ptr = head;
        node *prev;
        if (ptr->getdata() == key)
            removeElement();
        else
            while (ptr->getnext() != NULL)
            {
                prev = ptr;
                ptr = ptr->getnext();
                if (ptr->getdata() == key)
                {
                    prev->setnext(ptr->getnext());
                    ptr->setnext(NULL);
                }
            }
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

    void reverseDisplay()
    {
        recursiveDisplay(head);
        cout << endl;
    }

private:
    void recursiveDisplay(node *h)
    {
        if (h)
        {
            recursiveDisplay(h->getnext());
            cout << h->getdata() << ' ';
        }
    }
public:
    void countNodes()
    {
        int count = 0;
        node *ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->getnext();
        }
        cout << "Number of nodes: " << count << endl;
    }    
};

int main()
{
    list mylist;
    int choice = 1;

    do
    {
        cout << "--------------------------------------------------" << endl;
        cout << "1 To create Linked-List" << endl;
        cout << "2 To add new element to the list" << endl;
        cout << "3 To remove an element from the list" << endl;
        cout << "4 TO remove an element from the list by Key value" << endl;
        cout << "5 To display the list" << endl;
        cout << "6 TO display reverse " << endl;
        cout << "7 To count number of nodes(Elements)" << endl;
        cout << "0 To terminate the program" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            mylist.create();
            break;
        case 2:
            mylist.addNewElement();
            break;
        case 3:
            mylist.removeElement();
            break;
        case 4:
            mylist.removeElementByKey();
            break;
        case 5:
            mylist.display();
            break;
        case 6:
            mylist.reverseDisplay();
            break;
        case 7:
            mylist.countNodes();
            break;    
        default:
            cout << "Number entered not correct" << endl;
            break;
        }
        if (!choice)
            break;

    } while (true);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "@US10F" << endl;
}