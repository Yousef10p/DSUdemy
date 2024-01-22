#include <iostream>
using namespace std;

int pow(int base, int exp)
{
    if (exp == 0)
        return 1;
    else
    {
        int result = 1;
        for (int i = 0; i < exp; i++)
        {
            result *= base;
        }
        return result;
    }
}

class Term
{
private:
    int coffecient;
    int exp;

public:
    void setCoffecient()
    {
        cout << "Enter coffecient: ";
        cin >> coffecient;
    }

    void setCoffecient2(int x)
    {
        coffecient = x;
    }

    void setexp()
    {
        cout << "Enter exponenet: ";
        cin >> exp;
    }
    void setexp2(int x)
    {
        exp = x;
    }

    int getcoffecient() { return coffecient; }
    int getexp() { return exp; }
};
class ploy
{
private:
    int n;   // number of terms;
    Term *t; // dynamic array
public:
    void create()
    {
        cout << "Enter number of terms: ";
        cin >> n;
        t = new Term[n];
        int i = 0;
        while (i < n)
        {
            t[i].setCoffecient();
            t[i].setexp();
            i++;
        }
    }

    int eval()
    {
        int x;
        cout << "Assign to Variable: ";
        cin >> x;
        int i = 0;
        int result = 0;
        while (i < n)
        {
            result += t[i].getcoffecient() * pow(x, t[i].getexp());
            i++;
        }
        return result;
        
    }
    void display()
    {
        int i = 0;
        while(i < n)
        {   
            cout << "coffecient (" << i << "): " << t[i].getcoffecient() << "\t";
            cout << "Exponent (" << i <<"): " << t[i].getexp() << endl;
            i++;
        }
    }

    ploy add(ploy p)
    {   
        ploy sum;
        sum.t = new Term[n + p.n];
        int i = 0,j =0,k = 0;
        while(i < n && j < p.n)
        {
            if(t[i].getexp() < p.t[j].getexp()) sum.t[k++] = p.t[j++];
            else if(t[i].getexp() > p.t[j].getexp()) sum.t[k++] = t[i++];
            else 
            {
                sum.t[k].setexp2(t[i].getexp());
                sum.t[k++].setCoffecient2(t[i++].getcoffecient() + p.t[j++].getcoffecient());
            }
        }
        
        sum.n = k;
        return sum;
    }
};

int main()
{
    ploy mypoly;
    int choice;
    int result = 0;

    do
    {   
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 to create poly" << "\n2 to eval" << "\n3 to add" << "\n4 to display" << endl;
        cout << "99 to finish" << endl;
        cout << "choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // create
            mypoly.create();
            break;
        case 2: //eval
            result = mypoly.eval();
           cout << "Result: " << result << endl;
            break;
        case 3: //add
            ploy p1,p2,sum;
            p1.create();
            p2.create();
            sum = p1.add(p2);
            sum.display();
            break;
        case 4: //display
                mypoly.display();
            break;            
        default:
            break;
        }
        if(choice == 99)break;
    } while (true);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "@US10F" << endl;
    
}