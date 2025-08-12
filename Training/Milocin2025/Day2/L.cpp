#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    ll n; cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    ll ans = n-2;
    if (((n%4) == 1) || (((n%4)==2) && (n >= 6))) ans++;
    if (((n%4) == 2) || (((n%4)== 1) && (n >= 9))) ans++;
    if (n-1 > 2) ans--;
    if (n-3 > 2) ans--;
    cout << ans << '\n';
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