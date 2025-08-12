#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

constexpr int N = 10005, M = 10005, mod = 1e9 + 7;
int dp[2][N][M];
int prefk[N];
int prefa[N];
int tin[N];
bool iskin[N];
int t[N];
bool isk[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> tin[i];
    }
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        iskin[x] = 1;
    }
    int cur = 0;
    for(int i=1; i<=n; i++){
        if(iskin[i]){
            for(int j=0; j<tin[i]; j++){
                cur++;
                t[cur] = 1;
                isk[cur] = 1;
            }
        }
        else{
            cur++;
            t[cur] = tin[i];
        }
    }
    n = cur;

    for(int i=1; i<=n; i++){
        prefa[i] += t[i];
        if(isk[i]) prefk[i] += t[i];
        prefa[i] += prefa[i-1];
        prefk[i] += prefk[i-1];
    }

    if(prefa[n] != 2*prefk[n]){
        cout << 0 << "\n";
        return;
    }

    auto upd = [&](int &a, int b){
        a += b;
        a %= mod;
    };

    dp[0][0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<M; j++){
            if(isk[i]){
                upd(dp[0][i][j], dp[0][i-1][j]);
                if(j){
                    upd(dp[1][i][j-1], dp[1][i-1][j]);
                    upd(dp[1][i][j-1], dp[0][i-1][j]);
                }
            }
            else{
                if(j+t[i] < M){
                    upd(dp[0][i][j+t[i]], dp[0][i-1][j]);
                    upd(dp[1][i][j+t[i]], dp[1][i-1][j]);
                }
                int k = prefk[i-1] - (prefa[i-1] - prefk[i-1] - j);
                if(k >= t[i]){
                    upd(dp[0][i][j], dp[0][i-1][j]);
                    upd(dp[1][i][j], dp[1][i-1][j]);
                }
            }
        }
    }

    cout << (dp[0][n][0] + dp[1][n][0])%mod << "\n";
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