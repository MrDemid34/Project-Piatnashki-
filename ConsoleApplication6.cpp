#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int row_zero = 0;//строка
int col_zero = 0;//столб

void movement(int u_c, int matrix[][3])
{
    if (col_zero == 0 && u_c == 1)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (col_zero == 2 && u_c == 2)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (row_zero == 0 && u_c == 3)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (row_zero == 2 && u_c == 4)
    {
        cout << "You can't do this!" << endl;
        return;
    }

    if (u_c == 1)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero][col_zero - 1]);
        col_zero -= 1;
    }
    else if (u_c == 2)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero][col_zero + 1]);
        col_zero += 1;
    }
    else if (u_c == 3)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero - 1][col_zero]);
        row_zero -= 1;
    }
    else if (u_c == 4)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero + 1][col_zero]);
        row_zero += 1;
    }
}

void type(int matrix[][3])
{
    int randomNumber = rand() % 100;
    int i = 0;
    while (randomNumber >= 0)
    {
        i = rand() % 4 + 1;
        cout << i << endl;
        movement(i, matrix);
        randomNumber = randomNumber - 1;
    }
}
void printpole(int matrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << (char)205;


        }
        std::cout << endl;
        for (int j = 0; j < 3; j++)
        {
            std::cout << (char)179;

            std::cout << matrix[i][j] << " ";


        }
        cout << (char)179;

        cout << endl;
    }
    for (int j = 0; j < 9; j++)
    {
        cout << (char)205;


    }
    cout << endl;
}

void movementfour(int u_c, int matrix[][4])
{
    if (col_zero == 0 && u_c == 1)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (col_zero == 3 && u_c == 2)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (row_zero == 0 && u_c == 3)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    else if (row_zero == 3 && u_c == 4)
    {
        cout << "You can't do this!" << endl;
        return;
    }
    if (u_c == 1)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero][col_zero - 1]);
        col_zero -= 1;
    }
    else if (u_c == 2)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero][col_zero + 1]);
        col_zero += 1;
    }
    else if (u_c == 3)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero - 1][col_zero]);
        row_zero -= 1;
    }
    else if (u_c == 4)
    {
        swap(matrix[row_zero][col_zero], matrix[row_zero + 1][col_zero]);
        row_zero += 1;
    }

}

void typefour(int matrix[][4])
{
    int randomNumber = rand() % 100;
    int i = 0;
    while (randomNumber >= 0)
    {
        i = rand() % 5 + 1;
        cout << i << endl;
        movementfour(i, matrix);
        randomNumber = randomNumber - 1;
    }
}

void printpolefour(int matrix[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << (char)205;


        }
        cout << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << (char)179;

            cout << matrix[i][j] << " ";


        }
        cout << (char)179;

        cout << endl;
    }
    for (int j = 0; j < 16; j++)
    {
        cout << (char)205;


    }
    cout << endl;
}

int main()
{
    string v_p;
    srand(time(0));
    cout << "Select the game mod:\n3x3\n4x4" << endl << "I select: ";
    cin >> v_p;
    if (v_p == "3x3")
    {
        int vibor;
        int Z = 0;
        const int row = 3;
        const int col = 3;
        int matrix[3][3] = { {0,1,2},
                             {3,4,5},
                             {6,7,8} };
        int babka = 0, u_c = 0, y = 0, b = 0, ucw = 0;

        cout << "What you would prefer:\n1)I'll mix the field myself\n2)I want the computer to shuffle the field" << endl << "I would prefer: ";
        cin >> vibor;
        while (Z == 0)
        {
            if (vibor == 1)
            {
                cout << "Instructions on how to walk:\nleft = 1\nright = 2\nup = 3\ndown = 4" << endl << "If you want to stop mixing the field then you need to write 100" << endl;
                while (u_c != 100)
                {
                    printpole(matrix);
                    cin >> u_c;
                    movement(u_c, matrix);
                    /*cout << "You want to continue mixing the field and start playing:" << endl;
                    cin >> MixorPlay;*/
                }
                Z++;
            }
            else if (vibor == 2)
            {
                type(matrix);
                Z++;
            }
        }
        system("cls");//эта штука чистит консоль

        //cout << (char)179;

        std::cout << "Instructions on how to walk:\nleft = 1\nright = 2\nup = 3\ndown = 4" << endl;
        clock_t t = clock();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_zero = i;
                    col_zero = j;
                }
            }
        }

        while (babka != 1)
        {
            while (y != 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (matrix[i][j] <= matrix[i][j + 1])
                        {
                            b++;
                        }
                        y++;
                    }
                }
                printpole(matrix);
                if (b == 8)
                {
                    int time = (clock() - t) / CLOCKS_PER_SEC;
                    cout << "YOU WIN!!!";
                    cout << "You made: " << ucw << " moves!!!" << endl;
                    cout << "You spend: " << time << " seconds!!!" << endl;
                    babka++;
                    break;
                }
                else
                {
                    b = 0;
                }
                cout << "Your choise is: ";
                cin >> u_c;
                ucw++;
                movement(u_c, matrix);
            }
        }
    }
    ///
    else if (v_p == "4x4")
    {
        int vibor;
        int Z = 0;
        const int row = 4;
        const int col = 4;
        int matrix[4][4] = { {0,1,2,3},
                             {4,5,6,7},
                             {8,9,10,11},
                             {12,13,14,15} };
        int babka = 0, u_c = 0, y = 0, b = 0, ucw = 0;
        cout << "What you would prefer:\n1)I'll mix the field myself\n2)I want the computer to shuffle the field" << endl << "I would prefer: ";
        cin >> vibor;
        while (Z == 0)
        {
            if (vibor == 1)
            {
                cout << "Instructions on how to walk:\nleft = 1\nright = 2\nup = 3\ndown = 4" << endl << "If you want to stop mixing the field then you need to write 100" << endl;
                while (u_c != 100)
                {


                    printpolefour(matrix);
                    cin >> u_c;
                    movementfour(u_c, matrix);
                }
                Z++;
            }
            else if (vibor == 2)
            {
                typefour(matrix);
                Z++;
            }
        }
        system("cls");//эта штука чистит консоль
        cout << "Instructions on how to walk:\nleft = 1\nright = 2\nup = 3\ndown = 4" << endl;
        clock_t t = clock();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_zero = i;
                    col_zero = j;
                }
            }
        }

        while (babka != 1)
        {
            while (y != 4)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (matrix[i][j] <= matrix[i][j + 1])
                        {
                            b++;
                        }
                        y++;
                    }
                }
                printpolefour(matrix);
                if (b == 15)
                {
                    int time = (clock() - t) / CLOCKS_PER_SEC;
                    cout << "YOU WIN!!!" << endl;
                    cout << "You made: " << ucw << endl << " moves!!!" << endl;
                    cout << "You spend: " << time << " seconds!!!" << endl;
                    babka++;
                    break;
                }
                else
                {
                    b = 0;
                }
                cout << "Your choise is: ";
                cin >> u_c;
                ucw++;
                movementfour(u_c, matrix);
            }
        }
    }
}

