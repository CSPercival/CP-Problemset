#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    if (k == 1) {
        cout << (n*(n-1))/2 << '\n';
    }
    else cout << n-1 << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    
}