#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n+1);
    for(int i=1; i<=n; i++) cin >> t[i];
    int mx = 0;
    for(int i=1; i<=n; i++){
        t[i] = abs(t[i]);
        mx = max(mx, t[i]);
    }
    if(mx == 0){
        cout << 0 << "\n";
        return;
    }

    int minus = 0;
    int l = 1, r = n;
    while(l <= r){
        if((t[l]&1) == (minus&1) && t[l] <= minus){
            l++;
        }
        else if((t[r]&1) == (minus&1) && t[r] <= minus){
            r--;
        }
        else{
            int mn = min(t[l], t[r]);
            if(minus < mn) minus = mn;
            else minus++;
        }
    }
    cout << minus << "\n";
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