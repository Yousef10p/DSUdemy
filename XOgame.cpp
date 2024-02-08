#include<iostream>
using namespace std;

void displayField(int arr[3][3])
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j =  0; j < 3; j++)
            {
                if(arr[i][j] == 0)
                {    
                if(j == 0 || j == 1 )cout << "   | ";
                }
                else if (arr[i][j] == 1)
                { 
                cout << 'x' << ' ';
                if(j == 0 || j == 1 )cout << " | ";
                }
                else 
                {
                cout << 'o' << ' ';
                if(j == 0 || j == 1 )cout << " | ";
                }    
            }
           cout << endl;
           if(i != 2)
           cout << "-------------" << endl;
        }
        cout << endl << endl << endl;
    }
bool winner(int field[3][3])
    {
        if((field[0][0] == field[0][1]) && (field[0][1] == field[0][2]) && (field[0][2] != 0))return true;
        else if((field[1][0] == field[1][1]) && (field[1][1] == field[1][2]) && (field[1][2] != 0))return true;
        else if((field[2][0] == field[2][1]) && (field[2][1] == field[2][2]) && (field[2][2] != 0))return true;
       
        else if((field[0][0] == field[1][0]) && (field[1][0] == field[2][0]) && (field[2][0] != 0))return true;
        else if((field[0][1] == field[1][1]) && (field[1][1] == field[2][1]) && (field[2][1] != 0))return true;
        else if((field[0][2] == field[1][2]) && (field[1][2] == field[2][2]) && (field[2][2] != 0))return true;
       
        else if((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && (field[2][2] != 0))return true;
        else if((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && (field[2][0] != 0))return true;
        else return false;
    }
bool fillField(int place, int field[3][3],int content)
{
    switch (place)
    {
    case 1 : field[0][0] = content;
        break;
    case 2 : field[0][1] = content;    
        break;
    case 3 : field[0][2] = content;
        break;
    case 4 : field[1][0] = content;
        break;
    case 5 : field[1][1] = content;
        break;
    case 6 : field[1][2] = content;
        break;
    case 7 : field[2][0] = content;
        break;
    case 8 : field[2][1] = content;
        break;
    case 9 : field[2][2] = content;                      
    }
    displayField(field);
    int rt = winner(field);
    return rt;
}



int main()
{
    int field[3][3];
    int player,win = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        field[i][j] = 0;
    }
    
    
    do{
       displayField(field);
       cout << "x player enter place: ";
       cin >> player;
       if (fillField(player,field,1))
       {
        cout << "player 1 win" << endl;
        win = 1;
        break;
       }

       cout << "o player enter place: ";
       cin >> player;
       if (fillField(player,field,2))
       {
        cout << "player 2 win" << endl;
        win = 2;
        break;
       }
    }while(true);
}