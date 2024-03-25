#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<int, int> primeFactorization(int n)
{
    unordered_map<int, int> factors;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;
    return factors;
}

int largestPowerDividesFactorial(int m, int n)
{
    unordered_map<int, int> factorCount = primeFactorization(m);
    int power = 0;
    for (auto &pair : factorCount)
    {
        int prime = pair.first;
        int count = pair.second;
        int temp = prime;
        while (temp <= n)
        {
            power += n / temp;
            temp *= prime;
        }
        power /= count;
    }
    return power;
}

int main()
{
    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; caseNum++)
    {
        int m, n;
        cin >> m >> n;
        int result = largestPowerDividesFactorial(m, n);
        cout << "Case " << caseNum << ":" << endl;
        if (result > 0)
            cout << result << endl;
        else
            cout << "Impossible to divide" << endl;
    }
    return 0;
}
