#include <bits/stdc++.h>
using namespace std;

bool issafe(int a, int b)
{
    if ((a >= 0 && a < 3) && (b >= 0 && b < 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // int board[3][3] = {1, 5, 8, 2, 0, 3, 4, 6, 7};
    // int board[3][3] = {1, 8, 7, 2, 6, 0, 4, 3, 5};
    // int board[3][3] = {1, 4, 0, 2, 5, 3, 8, 6, 7};

    int board[3][3] = {1,2,3,0,4,6,7,5,8};
    int pos1[3][3], pos2[3][3], pos3[3][3], pos4[3][3];
    // int goal[3][3] = {1, 2, 3, 8, 0, 4, 7, 6, 5};


    int goal[3][3]={1,2,3,4,5,6,7,8,0};
    int zi, zj;
    int i, j;
    int heu1 = 0, heu2 = 0, heu3 = 0, heu4 = 0;
    int heusum1 = 0, heusum2 = 0, heusum3 = 0, heusum4 = 0;
    // cout << "Enter the elements of 8 puzzle matrix:\n";
    // for (i = 0; i < 3; i++)
    // {
    //     for (j = 0; j < 3; j++)
    //     {
    //         cin >> board[i][j];
    //     }
    // }
    cout << "Elements of 8 puzzle matrix:\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                zi = i;
                zj = j;
                break;
            }
        }
    }
    cout << "All possible moves are:\n";
    if (issafe(zi - 1, zj))
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                pos1[i][j] = board[i][j];
            }
        }
        pos1[zi][zj] = pos1[zi - 1][zj];
        pos1[zi - 1][zj] = 0;
        cout << "\nFirst possible move:\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << pos1[i][j] << "\t";
            }
            cout << "\n";
        }
        int sqr;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (pos1[i][j] != goal[i][j])
                {
                    heu1++;
                }
                int ans1 = pos1[i][j] - goal[i][j];
                int sq = ans1 * ans1;
                heusum1 = heusum1 + sq;
                sqr = sqrt(heusum1);
            }
        }
        cout << "Heuristic value of first move: " << heu1 << endl;
        cout << "Heuristic value of first move according to distance: " << sqr << endl;
    }
    if (issafe(zi + 1, zj))
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                pos2[i][j] = board[i][j];
            }
        }
        pos2[zi][zj] = pos2[zi + 1][zj];
        pos2[zi + 1][zj] = 0;
        cout << "\nSecond possible move:\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << pos2[i][j] << "\t";
            }
            cout << "\n";
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (pos2[i][j] != goal[i][j])
                {
                    heu2++;
                }
            }
        }
        cout << "Heuristic value of second move: " << heu2 << endl;
    }
    if (issafe(zi, zj - 1))
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                pos3[i][j] = board[i][j];
            }
        }
        pos3[zi][zj] = pos3[zi][zj - 1];
        pos3[zi][zj - 1] = 0;
        cout << "\nThird possible move:\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << pos3[i][j] << "\t";
            }
            cout << "\n";
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (pos3[i][j] != goal[i][j])
                {
                    heu3++;
                }
            }
        }
        cout << "Heuristic value of third move: " << heu3 << endl;
    }
    if (issafe(zi, zj + 1))
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                pos4[i][j] = board[i][j];
            }
        }
        pos4[zi][zj] = pos4[zi][zj + 1];
        pos4[zi][zj + 1] = 0;
        cout << "\nFourth possible move:\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << pos4[i][j] << "\t";
            }
            cout << "\n";
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (pos4[i][j] != goal[i][j])
                {
                    heu4++;
                }
            }
        }
        cout << "Heuristic value of fourth move: " << heu4 << endl;
    }
    return 0;
}