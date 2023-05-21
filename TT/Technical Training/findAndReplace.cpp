#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int calc_hash(string arr, int a, int n)
{
    int pm = 2;
    int ans = 0;
    int k = n;

    for (int i = a; i < n + a; i++)
    {
        ans += (arr[i]) * (pow(pm, (k--) - 1));
    }

    return ans;
}

int find(string str, string pat)
{
    int n = str.length();
    int m = pat.length();

    int hash = calc_hash(pat, 0, m);
    cout << "Pattern Hash : " << hash << endl;

    int index = -1;

    for (int i = 0; i <= n - m; i++)
    {
        int curr_hash = calc_hash(str, i, m);

        if (hash == curr_hash)
        {
            index = i;
            break;
        }
    }
    return index;
}

bool find_and_replace(string &str, string pat, string rep)
{
    int index = find(str, pat);
    if (index == -1)
        return false;
    str.replace(index, pat.length(), rep);
    return true;
}

int main()
{
    string str = "ABABBCAAAABCBBBBBAACCCAA";
    string pat;
    string rep;
    cout << "\nOriginal string: " << str << endl;

    int choice;
    while (true)
    {
        cout << "\n1. Find\n2. Find and Replace\n3. Exit"
             << endl;
        ;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Input : ";
            cin >> pat;
            int res = find(str, pat);
            if (res == -1)
                cout << "Not Found!" << endl;
            else
                cout << "Found!" << endl;
            break;
        }
        case 2:
        {
            cout << "Enter Old String and New String : ";
            cin >> pat >> rep;

            int res = find_and_replace(str, pat, rep);
            if (res == -1)
                cout << "Error: Cannot replace " << pat << endl;
            else
                cout << "Replaced " << rep << " Successfully!" << endl
                     << "Updated String: " << str << endl;
            break;
        }
        case 3:
            exit(0);
        default:
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}