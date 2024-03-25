#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Result of a^b % m
int big_mod(int a, int b, int m)
{
    int result = 1;
    a = a % m; // Reduce base to a number between 0 and M-1
    while (b > 0)
    {
        // If power is odd, multiply result with base
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }
        b = b / 2;
        a = (a * a) % m;
    }
    return result;
}

int main()
{
    int base, power, modulus;
    while (cin >> base >> power >> modulus)
    {
        cout << big_mod(base, power, modulus) << endl;
        string blankLine;
        getline(cin, blankLine);
    }
    return 0;
}
