#include<iostream>
using namespace std;

class node
{
int coffecient;
int power;
node *next;

public:
    node(){}
    void setCoffecient(int input)
    {
        coffecient = input;
    }
    void setPower(int input)
    {
        power  = input;
    }
    void setNext(node *ptr)
    {
        next = ptr;
    }

    int getcoffecient(){return coffecient;}
    int getPower(){return power;}
    node *getNext(){return next;}
};

class poly
{

node *head;
public:
    void create(int coffecient,int power)
    {
        node *ptr = new node;
        ptr->setCoffecient(coffecient);
        ptr->setPower(power);
        ptr->setNext(NULL);
        head = ptr;
    }

    void inseart(int coffecient,int power)
    {
        node *ptr = new node;
        ptr->setCoffecient(coffecient);
        ptr->setPower(power);
        ptr->setNext(head);
        head = ptr;
    }

    void remove()
    {
        node *temp = head;
        head = head->getNext();
        delete temp;
    }

    int eval(int R)
    {
        int result = 0,p = 1;
        node *temp = head;
        while(temp != NULL)
        {   
            p = 1;
            for(int i = 1; i <= temp->getPower() ;i++)
            {
                p *= R; 
            }
            result += p * temp->getcoffecient();
            temp = temp->getNext();
        }
        return result;
    }

    void display()
    {
        node *ptr = head;
        while(ptr != NULL)
        {   
            if(ptr->getcoffecient() > 0)    
                cout << " +"  << ptr->getcoffecient();
            else    
                cout << " -"  << ptr->getcoffecient();
            cout << '*' << "X^" << ptr->getPower(); 
            ptr = ptr->getNext();
        }
    }

};

int main()
{   
    poly myPol;
    int choice,input1,input2;
    bool check = true;

    do
    {   
        cout << "0 to terminate: " << endl;
        cout << "1 to create function: " << endl;
        cout << "2 to add term: " << endl;
        cout << "3 to remove first term: " << endl;
        cout << "4 to evaluate the function: " << endl;
        cout << "5 to display: " << endl;
        cout << "Input: ";
        cin >> input1;

        switch (input1)
        {
        case 1:
            cout << "Enter coffecient: ";
            cin >> input1;
            cout << "Enter power: ";
            cin >> input2;
            myPol.create(input1,input2);
            break;
        case 2:
            cout << "Enter coffecient: ";
            cin >> input1;
            cout << "Enter power: ";
            cin >> input2;
            myPol.inseart(input1,input2);
            break;    
        case 3:
            myPol.remove();
            break;
        case 4:
            myPol.display();
            cout << "Enter value for X: ";
            cin >> input1;
            cout << "Result = " << myPol.eval(input1) << endl;
            break;
        case 5:
            myPol.display();
            break;    
        case 0:
            check = false;
            break;
        default:
            cout << "Error" << endl;

        }
            cout << endl << endl << "-----------------------------------------------" << endl;
    } while (check);
    
}