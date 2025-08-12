#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int xo = 0, cur = 1;
    for(int i=1; i<=n-3; i++){
        cout << cur << " ";
        xo ^= cur;
        cur++;
    }
    while((xo^cur) == 0) cur++;
    // exit(0);
    cout << cur << " ";
    xo ^= cur;
    cur++;
    while((xo^cur) <= cur) cur++;
    cout << cur << " ";
    cout << (xo^cur) << "\n";
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