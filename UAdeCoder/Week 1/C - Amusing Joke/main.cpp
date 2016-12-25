#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int dict[128] = {0};

    string str;

    cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        dict[str[i]] += 1;
    }

    cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        dict[str[i]] += 1;
    }

    cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        dict[str[i]] -= 1;
    }


    if (count(dict, dict + sizeof(dict) / sizeof(dict[0]), 0) == sizeof(dict) / sizeof(*dict))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
