#include <bits/stdc++.h>
using namespace std;

vector<int> giveCommonElements(vector<pair<int, string>> l1, vector<pair<int, string>> l2, vector<pair<int, string>> l3)
{
    vector<int> ans;
    int n1 = 0, n2 = 0, n3 = 0;
    while (n1 < l1.size() && n2 < l2.size() && n3 < l3.size())
    {
        if (l1[n1].first == l2[n2].first && l1[n1].first == l3[n3].first)
        {
            ans.push_back(l1[n1].first);
            n1++, n2++, n3++;
        }
        else if (l1[n1].first < l2[n2].first)
            n1++;
        else if (l3[n3].first < l1[n1].first && l3[n3].first < l2[n2].first)
            n3++;
        else
            n2++;
    }
    return ans;
}

int main()
{
    vector<pair<int, string>> l1 = {{6588, "Lakshit"}, {6590, "Rahul"}, {6594, "Mohit"}, {6620, "Aryan"}, {6690, "Shashwat"}};
    vector<pair<int, string>> l2 = {{6588, "Aiml"}, {6590, "Aiml"}, {6700, "BDA"}, {6721, "BCG"}, {6999, "CC"}};
    vector<pair<int, string>> l3 = {{6588, "8.85"}, {6590, "7.93"}, {6594, "8.32"}, {6620, "8.36"}, {6999, "7.98"}};

    vector<int> ans = giveCommonElements(l1, l2, l3);

    cout << "Common Roll Nos: ";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}