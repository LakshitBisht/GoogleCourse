#include <bits/stdc++.h>
using namespace std;

void reverse_using_stack(vector<int> &v)
{
    stack<int> st;

    for (auto &x : v)
    {
        st.push(x);
    }
    int itr = 0;
    while (st.size())
    {
        v[itr++] = st.top();
        st.pop();
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

    vector<int> v1 = {5, 4, 3, 2, 1};
    vector<int> v2 = {9, 8, 7, 6, 5};
    cout << "Original Arrays: \n";
    print1d(v1);
    print1d(v2);

    reverse_using_stack(v1);
    reverse_using_stack(v2);

    cout << "After Reversing: \n";
    print1d(v1);
    print1d(v2);

    return 0;
}