// Vishal Singh
// Batch 2
// roll no 63
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<double> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double parameter = 0.6;

    for (auto it : nums)
    {

        double ans = abs((10 - it) / max(int(it), 10)) * parameter;

        if (ans == 0)
            cout << it << "-->" << 1 << endl;
        else if (ans > 1)
            cout << it << "-->" << 0 << endl;
        else
            cout << it << "--->" << 1 - ans << endl;
    }
}
