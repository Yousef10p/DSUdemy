#include <iostream>
using namespace std;

void displayField(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                if (j == 0 || j == 1)
                    cout << "   | ";
            }
            else if (arr[i][j] == 1)
            {
                cout << 'x' << ' ';
                if (j == 0 || j == 1)
                    cout << " | ";
            }
            else
            {
                cout << 'o' << ' ';
                if (j == 0 || j == 1)
                    cout << " | ";
            }
        }
        cout << endl;
        if (i != 2)
            cout << "-------------" << endl;
    }
    cout << endl
         << endl
         << endl;
}
bool winner(int field[3][3])
{
    if ((field[0][0] == field[0][1]) && (field[0][1] == field[0][2]) && (field[0][2] != 0))
        return true;
    else if ((field[1][0] == field[1][1]) && (field[1][1] == field[1][2]) && (field[1][2] != 0))
        return true;
    else if ((field[2][0] == field[2][1]) && (field[2][1] == field[2][2]) && (field[2][2] != 0))
        return true;

    else if ((field[0][0] == field[1][0]) && (field[1][0] == field[2][0]) && (field[2][0] != 0))
        return true;
    else if ((field[0][1] == field[1][1]) && (field[1][1] == field[2][1]) && (field[2][1] != 0))
        return true;
    else if ((field[0][2] == field[1][2]) && (field[1][2] == field[2][2]) && (field[2][2] != 0))
        return true;

    else if ((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && (field[2][2] != 0))
        return true;
    else if ((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && (field[2][0] != 0))
        return true;
    else
        return false;
}
bool fillField(int place, int field[3][3], int content)
{
    bool check;
    
    do
    {
        check = true;
        switch (place)
        {
        case 1:
            if (field[0][0] == 0)
                field[0][0] = content;
            else
                check = false;
            break;
        case 2:
            if (field[0][1] == 0)
                field[0][1] = content;
            else
                check = false;
            break;
        case 3:
            if (field[0][2] == 0)
                field[0][2] = content;
            else
                check = false;
            break;
        case 4:
            if (field[1][0] == 0)
                field[1][0] = content;
            else
                check = false;
            break;
        case 5:
            if (field[1][1] == 0)
                field[1][1] = content;
            else
                check = false;
            break;
        case 6:
            if (field[1][2] == 0)
                field[1][2] = content;
            else
                check = false;
            break;
        case 7:
            if (field[2][0] == 0)
                field[2][0] = content;
            else
                check = false;
            break;
        case 8:
            if (field[2][1] == 0)
                field[2][1] = content;
            else
                check = false;
            break;
        case 9:
            if (field[2][2] == 0)
                field[2][2] = content;
            else
                check = false;
            break;
        }

        if (check == true)
        {
            displayField(field);
            int rt = winner(field);

            return rt;
        }
        else
        {
            cout << "occupied place enter in other place: ";
            cin >> place;
        }
    } while (true);
}
bool FieldIsFull(int field[3][3])
{
    //bool check = true;//field is full and no place to enter = ture

    for(int i = 0; i < 3; i++)
    {
        for(int j =0 ;j < 3; j++)
        {
            if(field[i][j] == 0)
            {
                return false;
                break;
            }
        }
    }
    return true;
}

int main()
{
    int field[3][3];
    int player, win = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            field[i][j] = 0;
    }

    displayField(field);
    do
    {
        
        cout << "x player enter place: ";
        cin >> player;
        if (fillField(player, field, 1))
        {
            cout << "player 1 win" << endl;
            win = 1;
            break;
        }

        if(FieldIsFull(field))
        {
            win  = 0;
            cout << "Tied - Game Over" << endl;
            break;
        }

        cout << "o player enter place: ";
        cin >> player;
        if (fillField(player, field, 2))
        {
            cout << "player 2 win" << endl;
            win = 2;
            break;
        }
    } while (true);
}