#include <iostream>
#include <list>

using namespace std;

bool find_char(list<char> char_list, char c)
{
    for (char ch : char_list)
    {
        if (ch == c)
            return true;
    }
    return false;
}
void print_list(list<char> char_list)
{
    for (char ch : char_list)
        cout << ch << " -> ";
    cout << endl;
}

int main()
{
    list<char> char_list = {'l', 'a', 'k', 's', 'h', 'i', 't'};
    cout << "List of characters: ";
    print_list(char_list);
    char c = 'l';
    if (find_char(char_list, c))
        cout << c << " is present in the list" << endl;
    else
        cout << c << " is not present in the list" << endl;
    return 0;
}
