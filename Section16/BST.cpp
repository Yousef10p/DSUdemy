#include <iostream>
using namespace std;



class Node
{
public:
    Node *left, *right;
    int data;

    Node()
    {
        left = right = NULL;
        data = -1;
    }
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};

class Stack
{
public:
    int size;
    int top;
    Node* *arr;
    Stack()
    {
        size = 50;
        top = -1;
        arr = new Node*[size];
    }
    bool isFull()
    {
        if(top == size-1)
            return true;
        else    
            return false;    
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        else return false;    
    }
    void push(Node* p)
    {
        if(isFull())
            cout << "overflow error" << endl;
        else
            arr[++top] = p;    
    }
    Node* pop()
    {
        if(isEmpty())
        {
            cout << "Error underflow" << endl;
            return NULL;
        }
        else
            return arr[top--];    
    }
};

class Queue
{
public:
    int fst,lst,size;
    Node* *array;
    Queue()
    {
        fst = lst = -1;
        size = 50;
        array = new Node*[size];
    }

    bool isFull()
    {
        if(lst == size-1)
            return true;
        else
            return false;    
    }

    bool isEmpty()
    {
        if(fst == lst)
            return true;
        else 
            return false;

    }


    void enqueue(Node *p)
    {
        if(isFull())
            cout << "Error Overflow" << endl;
        else
            array[++lst] = p;    
    }
    Node* dequeue()
    {
        if(isEmpty())
        {
            cout << "Error Underflow" << endl;
        }
        else
        {
            return array[++fst];
        }
    }
};


class BST
{
public:
    Node *root;

    bool search(Node *r, int key)
    {
        if (r == NULL)
            return NULL;
        else if (r->data == key)
            return r;
        else if (r->data < key)
            return search(r->right, key);
        else if (r->data > key)
            return search(r->left, key);
    }

    Node *Delete(Node *p, int key)
    {
        Node *q = NULL;
        if (p == NULL)
            return NULL;
        if (p->left == NULL && p->right == NULL)
        {
            if (p == root)
                root = NULL;
            delete p;
            return NULL;
        }

        if (key < p->data)
        {
            // p->setLeft(Delete(p->getLeft(),key));
            p->left = Delete(p->left, key);
        }

        else if (key > p->data)
        {
            // p->setRight(Delete(p->getLeft(),key));
            p->right = Delete(p->right, key);
        }
        else
        {
            if (Height(p->left) > Height(p->right))
            {
                q = InPre(p->left);
                p->data = q->data;
                p->left = Delete(p->left, q->data);
            }
            else
            {
                q = InSucc(p->right);
                p->data = q->data;
                p->right = Delete(p->right, q->data);
            }
        }
        return p;
    }

public:
    BST() { root = NULL; }
    BST(int data)
    {
        root = new Node(data);
    }
    void create(int data) { root = new Node(data); }
    Node *getRoot() { return root; }
    bool search(int key) { return search(root, key); }

    void Delete(int key)
    {
        Delete(root, key);
    }

    void insert(int key)
    {
        
       if(root == NULL)
       {
        root = new Node(key);
       }
       
       
       else{
        Node *r = NULL, *t = root;
        while (t != NULL)
        {
            r = t;
            if (key == t->data)
                return;
            else if (key < t->data)
                t = t->left;
            else
                t = t->right;
        }

        t = new Node(key);
        if (t->data < r->data)
            r->left = t;
        else
            r->right = t;
        }    
    }

    int Height(Node *p)
    {
        int x, y;
        if (p == NULL)
            return 0;
        else
            x = Height(p->left);
        y = Height(p->right);
        return x > y ? x + 1 : y + 1;
    }

    Node *InPre(Node *p)
    {
        while (p && p->right != NULL)
            p = p->right;
        return p;
    }

    Node *InSucc(Node *p)
    {
        while (p && p->left != NULL)
            p = p->left;
        return p;
    }

    void display()
    {
        Node *t = root;
        
    }

    void generatingPre(int A[] , int n)
    {
        Stack stk;
        Node *t = NULL,*p;
        int i = 0;

        root = new Node;
        root->data = A[i++];
        p = root;

        while(i < n)
        {
            if(A[i] < p->data)
            {
                t = new Node(A[i++]);
                p->left = t;
                stk.push(p);
                p = t;
            }
            
            
            else
            { 
                    if(A[i] < stk.arr[stk.top]->data && !stk.isEmpty())
                    {
                        t = new Node(A[i++]);
                        p->right = t;
                        p = t;
                    }
                    else if(!stk.isEmpty())
                    {
                         p = stk.pop();
                    }
                    else if(stk.isEmpty())
                    {
                        t = new Node(A[i++]);
                        p->right = t;
                        p = t; 
                    }
            }
        }
    }

    void displayByLevel()
    {   
        if(root == NULL)
            return;

        Node *p = root;
        Queue q;
        q.enqueue(p);

        while(!q.isEmpty())
        {
            p = q.dequeue();
            if(p->left != NULL)
                q.enqueue(p->left);
            if(p->right != NULL)
                q.enqueue(p->right);
            cout << p->data << ' ';    

        }
        cout << endl;
    }

    void Ygenerate(int A[],int n)
    {
        int i = 0;
        while(i < n)
            insert(A[i++]);

    }
};

int main()
{   
    
}
