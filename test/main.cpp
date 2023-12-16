//
// Created by Xinchen on 2023/10/26.
//
#include <iostream>
#include <vector>

using namespace std;

int Func(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return Func(a ^ b, (a & b) << 1);
}

int main()
{
    cout << Func(3, 5) << endl;

    vector<int> v = {1, 2, 3, 4, 5};

    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}