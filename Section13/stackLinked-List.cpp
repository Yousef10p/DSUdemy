#include<iostream>
using namespace std;

class node
{
    int data;
    node *next;
public:

    node(){next = NULL;};
    node(int d){data = d;
                next = NULL;
    }

    void setData(int x){data = x;}
    int getData(){return data;}
    void setNext(node *ptr){next = ptr;}
    node *getNext(){return next;}
};

class Stack
{
private:
        node *top;
public:
        Stack(){top = NULL;}
        void create(int input)
        {
            node *ptr = new node(input);
            top = ptr;
        } 

        bool isEmpety()
        {
            if(top == NULL)return true;
            else return false;
        }    

        void push(int input)
        {
            node *ptr = new node(input);
            ptr->setNext(top);
            top = ptr;
        } 

        int pop()
        {
            if(isEmpety())
            {
                cout << "underflow" << endl;
                return -1;
            }    
            else 
                {
                    int x = top->getData();
                    node *ptr = top;
                    top = top->getNext();
                    delete ptr;
                    return x;
                }    
        }

        int peek(int position)
        {
            int counter =  0;
            node *ptr = top;
            if(counter != position)
                while(ptr != NULL)
                {   
                    if(++counter == position)
                        break;
                    ptr = ptr->getNext();
                }
            if(position != counter)
            {
                cout << "Position out of boundery" << endl;
                return -1;
            }
            else return ptr->getData();
        }

        
        
             void display()
    {
            node *ptr = top;       
       while(ptr != NULL)
        {
        cout << "-----------" << endl;//11 top of first block
            for(int j = 0; j < 1; j++)
                cout << "|         |" << endl;//10 loop 1 times,  
        cout << "|   " << ptr->getData();
        if(ptr->getData() >= 10)cout << "    |" << endl;
        else cout << "     |" << endl;
            for(int k = 0; k < 1; k++)
        cout << "|         |" << endl;//10 loop 1 times 
        ptr = ptr->getNext();
        }
        cout << "-----------" << endl << endl << endl;//11 bottom of last block down
    }
        

};


int main()
{
    int input;
    Stack myStack;
    bool check = true;
    do
    {   
        cout << "Enter 0 to create Stack: " << endl;
        cout << "Enter 1 to push: " << endl;
        cout << "Enter 2 to pop: " << endl;
        //cout << "Enter 3 to check is it full: " << endl;
        cout << "Enter 3 to check is it empety: " << endl;
        cout << "Enter 4 to peek: " << endl;
        cout << "Enter 5 to display: " << endl;
        cout << "Enter 99 to terminate: " << endl;
        cout << "input: ";
        cin >> input;

        switch (input)
        {
        case 0:
            cout << "Enter first element for the stack: ";
            cin >> input;
            myStack.create(input);
            break;
        case 1:
            cout << "Enter value to push: ";
            cin >> input;
            myStack.push(input);
            break;

        case 2:
            cout << "Poped element: " << myStack.pop() << endl;
            break;

        case 3:
            if(myStack.isEmpety())cout << "Stack is empety" << endl;
            else cout << "Stack is not empety " << endl;
            break;

        case 4:
            cout << "Enter position to get its value: ";
            cin >> input;
            input = myStack.peek(input);
            if(input == -1)
                cout << "error index out of boundry" << endl;
            else 
                cout << "element is: " << input << endl;             
            break; 

        case 5:
            myStack.display();
            break;
        case 99:
            check = false;    
            break;    
        default:
            cout << "Error not valid choice: " << endl;    
            break;
        }
        cout << endl << "--------------------------------------------" << endl;
    } while (check);
    

}