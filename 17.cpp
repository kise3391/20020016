#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Year;
    cin >> Year;
    if (Year % 100)
        cout << (Year % 4 ? "false" : "true");
    else
        cout << (Year % 400 ? "false" : "true");
    return 0;
}
