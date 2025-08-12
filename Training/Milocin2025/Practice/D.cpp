#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[(i+m-1)%n] = a[n-i-1]; 
    }
    for (int x: b) cout << x << ' ';
    cout << '\n';
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