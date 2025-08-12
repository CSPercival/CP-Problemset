#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

constexpr int N = (1<<22), M = 21;
bool vis[M][N];

void chop(int x, int bit){
    if(vis[bit][x]) return;
    vis[bit][x] = 1;
    for(int i=0; i<M; i++){
        int y = (x^(1<<i));
        if(y < x && !vis[bit][y]){
            chop(y, bit);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    auto insert = [&](int x){
        for(int i=0; i<M; i++){
            if(!(x & (1<<i))){
                if(!vis[i][x]) chop(x, i);
            }
        }
    };

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insert(x);
    }

    int ans = 0;
    auto go = [&]() -> bool {
        for(int i=0; i<M; i++){
            if(!(ans & (1<<i)) && !vis[i][ans]){
                return false;
            }
        }
        return true;
    };

    while(go()){
        ans++;
    }
    cout << ans << " ";
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        insert(x);

        while(go()){
            ans++;
        }
        cout << ans << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}