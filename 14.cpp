#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k; // Bob xem thẻ
    if (k < 50) cout << "other"; // Bob chọn thẻ còn lại
    else cout << k; // Bob chọn thẻ k
    return 0;
}
