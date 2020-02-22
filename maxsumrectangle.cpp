#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v420;

#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxi 100000
#define pii pair<int, int>
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x))
#define DANGER                        \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int kadane(int b[], int n)
{
    int max_kadane = b[0], curr_max = b[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(b[i], curr_max + b[i]);
        max_kadane = max(max_kadane, curr_max);
    }
    return max_kadane;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int b[n];
    int l = 0, r = 0, max_sum = INT_MIN, top = 0, down = 0;
    for (int i = l; i < m; i++)
    {
        mem(b, 0);

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                b[k] += a[k][j];     
            }

            int kadane_max = kadane(b, n);
        
            if (kadane_max > max_sum)
            {
                max_sum = kadane_max;
            }
        }
    }
    cout << max_sum;
}