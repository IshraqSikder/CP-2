#include <bits/stdc++.h>
using namespace std;
#define ll long long

int largestPrimeDivisor(int n)
{
    if (n <= 1)
        return -1;
    
    int largest = -1;
    while (n % 2 == 0)
    {
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            largest = i;
            n /= i;
        }
    }

    if (n > 2)
        largest = n;

    return largest;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int divisor = largestPrimeDivisor(n);
        cout << divisor << endl;
    }
    return 0;
}
