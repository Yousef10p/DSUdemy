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
        cout << "Enter 3 to check is it full: " << endl;
        cout << "Enter 4 to check is it empety: " << endl;
        cout << "Enter 5 to peek: " << endl;
        cout << "Enter 6 to display: " << endl;
        cout << "Enter 99 to terminate: " << endl;
        cout << "input: ";
        cin >> input;

        switch (input)
        {
        case 0:
            cout << "Enter size for the stack: ";
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
            if(myStack.isFull())cout << "Stack is full" << endl;
            else cout << "Stack is not full " << endl;
            break;

        case 4:
            if(myStack.isEmpety())cout << "Stack is empety" << endl;
            else cout << "Stack is not empety " << endl;
            break;

        case 5:
            cout << "Enter position to get its value: ";
            cin >> input;
            input = myStack.peek(input);
            if(input == -1)
                cout << "error index out of boundry" << endl;
            else 
                cout << "element is: " << input << endl;             
            break; 

        case 6:
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