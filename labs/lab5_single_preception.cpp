#include <iostream>
using namespace std;
int signum(int net)
{
    if (net < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    float des_op[3] = {1, -1, 1};      // desired output
    float weight[4] = {1, -1, 0, 0.5}; // weights are given
    float c = 1;                       // c ki value given haii

    float net = 0; // net ko 0 se initialize
    int out;
    float x[3][4] = {{1, -2, 1.5, 0}, {1, -0.5, -2, -1.5}, {0, 1, -1, 1.5}}; // input
    cout << "\nDisplaying weights calculated:\n";
    for (int i = 0; i < 3; i++)
    {
        net = 0;
        for (int j = 0; j < 4; j++)
        {
            net = net + x[i][j] * weight[j];
        }

        if (net != 0)
        {
            out = signum(int(net));
        }
        int y = des_op[i] - out;
        cout << "\nWeights for X" << i << "\n";
        for (int j = 0; j < 4; j++)
        {
            weight[j] = weight[j] + c * y * x[i][j];
            cout << weight[j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

// Displaying weights calculated:

// Weights for X0
// 1       -1      0       0.5

// Weights for X1
// -1      0       4       3.5

// Weights for X2
// -1      0       4       3.5