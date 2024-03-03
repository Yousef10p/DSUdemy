/*
program 1 to check paranthesis balanced or not (for every openning one must there be a closing one or give error)
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Stack
{
private:
    int top;
    char *s;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        s = new char[this->size];
        top = -1;
    }
    Stack() { top = -1; }
    void create(int size)
    {
        this->size = size;
        s = new char[this->size];
        top = -1;
    }
    bool isEmpety()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }
    void push(int x)
    {
        if (isFull())
            cout << "Stack overflow" << endl;
        else
            s[++top] = x;
    }
    char pop()
    {
        if (isEmpety())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
            return s[top--];
    }
    int peek(int position)
    {
        if (position <= top && position > 0)
            return s[top - position + 1]; // considering top is element 1
        else
        {
            cout << "Error out of index" << endl;
            return -1;
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << "-----------" << endl; // 11 top of first block
            for (int j = 0; j < 1; j++)
                cout << "|         |" << endl; // 10 loop 1 times,
            cout << "|   " << s[i];
            if (s[i] >= 10)
                cout << "    |" << endl;
            else
                cout << "     |" << endl;
            for (int k = 0; k < 1; k++)
                cout << "|         |" << endl; // 10 loop 1 times
        }
        cout << "-----------" << endl
             << endl
             << endl; // 11 bottom of last block down
    }

    friend void infixToPostfix(char *expr);
    friend void infixToPostfix2(char *expr, string &post);
};

void infixToPostfix2(char *expr, string &post)
{
    Stack s;
    s.create(strlen(expr));
    int k = 0;
    for (int i = 0; expr[i] != '\0'; i++)
    {

        if (expr[i] == ' ')
            continue;

        if (expr[i] == '+' || expr[i] == '-')
        {
            while (true)
            {
                if (s.isEmpety())
                {
                    s.push(expr[i]);
                    break;
                }
                else
                    {
                        post[k++] = s.pop();
                        post[k++] = ' ';
                    }
            }
        }

        else if (expr[i] == '*' || expr[i] == '/')
        {
            while (true)
            {
                if (s.s[s.top] != '*' && s.s[s.top] != '/')
                {
                    s.push(expr[i]);
                    break;
                }
                else
                {
                    post[k++] = s.pop();
                    post[k++] = ' ';
                }
            }
        }

        else
        {
            post[k++] = expr[i];
            post[k++] = ' ';
        }
    }

    while (!s.isEmpety())
        {
            post[k++] = s.pop();
            post[k++] = ' ';
        }


}

bool isBalance(char *expr)
{
    Stack s;
    char temp;
    s.create(strlen(expr));
    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            s.push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s.isEmpety())
            {
                return false;
            }
            else
            {
                temp = s.pop();
                if (temp == '(' && expr[i] == ')')
                    continue;
                else if (temp == '{' && expr[i] == '}')
                    continue;
                else if (temp == '[' && expr[i] == ']')
                    continue;
                else
                    return false;
            }
        }
    }
    return s.isEmpety() ? true : false;
}

void infixToPostfix(char *expr)
{
    Stack s;
    s.create(strlen(expr));

    for (int i = 0; expr[i] != '\0'; i++)
    {

        if (expr[i] == ' ')
            continue;

        if (expr[i] == '+' || expr[i] == '-')
        {
            while (true)
            {
                if (s.isEmpety())
                {
                    s.push(expr[i]);
                    break;
                }
                else
                    cout << s.pop() << ' ';
            }
        }

        else if (expr[i] == '*' || expr[i] == '/')
        {
            while (true)
            {
                if (s.s[s.top] != '*' && s.s[s.top] != '/')
                {
                    s.push(expr[i]);
                    break;
                }
                else
                {
                    cout << s.pop() << ' ';
                }
            }
        }

        else
        {
            cout << expr[i] << ' ';
        }
    }

    while (!s.isEmpety())
        cout << s.pop() << ' ';

    cout << endl;
}

int main()
{
    char *infix = "a + b * c - d / e";
    string post;
    infixToPostfix2(infix, post);
    cout << post;
    cout << endl
         << "-------------------------------" << endl
         << endl;
    char *user2 = "a + b * c - d / e";
    infixToPostfix(user2);
}