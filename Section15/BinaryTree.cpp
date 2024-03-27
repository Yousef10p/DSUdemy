#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
public:
    Node *lchild, *rchild;
    int data;
};

class Queue
{
public:
    int front, rear, size;
    Node **Q;
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        Q = new Node *[size];
    }
    void enqueue(Node *x)
    {
        if (rear == size - 1)
            cout << "Queue is full" << endl;
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    Node *dequeue()
    {
        Node *x = NULL;
        if (front == rear)
        {
            cout << "Queue is emptey" << endl;
        }
        else
        {
            x = Q[front + 1];
            front++;
        }
        return x;
    }
    void display()
    {
        for (int i = front + 1; i <= rear; i++)
            cout << Q[i]->data << ' ';
        cout << endl;
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
};

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }//constructor
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node *p);
    void Postorder() { Postorder(root); }
    void Postorder(Node *p);
    void Inorder() { Inorder(root); }
    void Inorder(Node *p);
    void Levelorder() { Levelorder(root); }
    void Levelorder(Node *p);
    int Height() { return Height(root); }
    int Height(Node *p);
    int countNodes(){return countNodes(root);}
    int countNodes(Node *p);

};
void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    printf("Eneter root value ");
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "enter left child of  " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "enter right child of  " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder( Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder( Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}
void Tree::Levelorder( Node *root)
{
    Queue q(100);
    cout << root->data;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild << ' ';
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->lchild << ' ';
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height( Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int Tree :: countNodes(Node *p)
{
    if(p)
        return countNodes(p->lchild) + countNodes(p->rchild) + 1;
}




int main()
{

    return 0;
}