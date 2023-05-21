#include <bits/stdc++.h>
using namespace std;
void count_sort(vector<int> &v)
{
    map<int, int> um;
    for (auto &x : v)
    {
        um[x]++;
    }
    int itr = 0;
    for (auto &x : um)
    {
        int num = x.first;
        int times = x.second;
        while (times--)
        {
            v[itr++] = num;
        }
    }
}

void print1d(vector<int> &v)
{
    for (auto &x : v)
    {
        cout << x << "";
    }
    cout << "\n";
}

int main()
{
    vector<int> v = {2, 5, 3, 4, 1, 6, 7, 3, 5, 9};
    print1d(v);
    count_sort(v);
    print1d(v);
    return 0;
}
