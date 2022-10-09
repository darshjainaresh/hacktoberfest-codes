#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl
#define mod 1000000007
#define fo(i, n) for (i = 0; i < n; i++)
#define s(a, n) sort(a, a + n);
#define sr(a, n) sort(a, a + n, greater<ll>());
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, i, j;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), r, b;
        fo(i, n) cin >> a[i];
        string s;
        cin >> s;
        fo(i, n)
        {
            if (s[i] == 'R')
                r.push_back(a[i]);
            else
                b.push_back(a[i]);
        }
        bool fou[n + 1] = {0};
        sort(r.begin(), r.end());
        sort(b.begin(), b.end());
        ll num = n;
        for (i = r.size() - 1; i >= 0 && num > 0; i--)
        {
            if (num < r[i])
            {
                break;
            }
            else
            {
                fou[num] = 1;
                num--;
            }
        }
        num = 1;
        for (i = 0; i < b.size() && num <= n; i++)
        {
            if (fou[num])
            {
                num++;
                i--;
            }
            else if (num > b[i])
            {
                break;
            }
            else
            {
                fou[num] = 1;
                num++;
            }
        }
        bool f = 0;
        fo(i, n)
        {
            if (fou[i + 1] == 0)
            {
                // deb(i + 1);
                f = 1;
                break;
            }
        }
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}