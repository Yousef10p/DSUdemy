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
    void addNewElementInIndex(int input, int index)
    {
        int count = 1;

        node *ctrl = head;
        if (index == 0)
        {
            addNewElementasHead(input);
        }
        else
        {
            node *p = new node(input);
            while (count != index)
            {
                ctrl = ctrl->getnext();
                count++;
            }
            p->setnext(ctrl->getnext());
            ctrl->setnext(p);
        }
    }
    void inseartatlast(int input)
    {
        node *q = new node(input);
        node *p = head;
        while (p->getnext() != NULL)
            p = p->getnext();
        p->setnext(q);
    }
    void removeElement() // remove head
    {
        node *ptr = head;
        head = head->getnext(); // head = head->next;
        ptr->setnext(NULL);
        delete ptr;
    }
    void removeElementByKey(int key)
    {
        node *ptr = head;

        if (head->getdata() == key)
        {
            removeElement();
        }
        else
        {
            node *ptr = head;
            node *prev = NULL;
            while (ptr->getnext() != NULL)
            {
                prev = ptr;
                ptr = ptr->getnext();
                if (ptr->getdata() == key)
                {
                    prev->setnext(ptr->getnext());
                    ptr->setnext(NULL);
                    delete ptr;
                    break;
                }
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
    void removebyobject(node *p)
    {
        node *c = head;
        while (c->getnext() != p)
        {
            c = c->getnext();
        }
        c->setnext(p->getnext());
        p->setnext(NULL);
        delete p;
    }
public:
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
    int sum()
    {
        int sum = 0;
        node *x = head;
        while (x != NULL)
        {
            sum += x->getdata();
            x = x->getnext();
        }
        return sum;
    }
    int maximum()
    {
        int max = -9999;
        node *x = head;
        while (x != NULL)
        {
            if (x->getdata() > max)
                max = x->getdata();
            x = x->getnext();
        }
        return max;
    }
    int minimum()
    {
        int min = 9999;
        node *x = head;
        while (x != NULL)
        {
            if (x->getdata() < min)
                min = x->getdata();
            x = x->getnext();
        }
        return min;
    }
    bool searchHead(int key) // replace found node to be head for next search
    {
        node *p = head;
        node *q = NULL;
        while (p != NULL)
        {
            if (p->getdata() == key)
            {
                q->setnext(p->getnext());
                p->setnext(head);
                head = p;
                return true;
            }
            else
            {
                q = p;
                p = p->getnext();
            }
        }
        return false;
    }
    bool isSortedIncreasing()
    {
        int x = head->getdata();
        node *ptr = head->getnext();
        while (ptr != NULL)
        {
            if (ptr->getdata() < x)
            {
                return false;
            }
            else
            {
                x = ptr->getdata();
                ptr = ptr->getnext();
            }
        }
        return true;
    }
    void removeDuplicates()
    {
        node *i = head;
        node *j;
        while (i != NULL)
        {
            j = i->getnext();
            while (j != NULL)
            {
                if (i->getdata() == j->getdata())
                {
                    removebyobject(j);
                    break;
                }
                j = j->getnext();
            }
            i = i->getnext();
        }
    }
    void reverseList()
    {
        node *i = head;
        node *j = head->getnext();
        node *k = j->getnext();
        while (true)
        {
            j->setnext(i);
            i = j;
            j = k;
            if (j)
                k = k->getnext();
            else
            {
                head->setnext(NULL);
                head = i;
                break;
            }
        }
    }
};

int main()
{
    list mylist;
    int choice = 1, input;

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
        cout << "8 To get the sum" << endl;
        cout << "9 To get the maximum data" << endl;
        cout << "10 To get the minimum data" << endl;
        cout << "11 TO search for an element(Note that order will change !)" << endl;
        cout << "12 To insert an element by index" << endl;
        cout << "13 To insert an element at last" << endl;
        cout << "14 To check wether list is sorted in increasing order" << endl;
        cout << "15 To remove duplicates in list" << endl;
        cout << "16 To reverse the list" << endl;
        cout << "0 To terminate the program" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter data: ";
            cin >> input;
            mylist.create(input);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> input;
            mylist.addNewElementasHead(input);
            break;
        case 3:
            mylist.removeElement();
            break;
        case 4:
            cout << "Enter key value: ";
            cin >> input;
            mylist.removeElementByKey(input);
            break;
        case 5:
            mylist.display();
            break;
        case 6:
            mylist.reverseDisplay();
            break;
        case 7:
            cout << "Number of nodes: " << mylist.countNodes() << endl;
            break;
        case 8:
            cout << "sum: " << mylist.sum() << endl;
            break;
        case 9:
            cout << "Maximum: " << mylist.maximum() << endl;
            break;
        case 10:
            cout << "Minimum: " << mylist.minimum() << endl;
            break;
        case 11:
            cout << "Enter key: ";
            cin >> input;
            if (mylist.searchHead(input))
                cout << "Key found" << endl;
            else
                cout << "Key not found" << endl;
            break;
        case 12:
            int index;
            cout << "Enter index (head is 1): ";
            cin >> index;
            cout << "Enter data: ";
            cin >> input;
            mylist.addNewElementInIndex(input, index);
            break;
        case 13:
            cout << "Enter data: ";
            cin >> input;
            mylist.inseartatlast(input);
            break;
        case 14:
            if (mylist.isSortedIncreasing())
                cout << "List is sorted" << endl;
            else
                cout << "List is not sorted" << endl;
            break;
        case 15:
            mylist.removeDuplicates();
            break;
        case 16:
            mylist.reverseList();
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