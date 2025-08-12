#include <bits/stdc++.h>
#define st first
#define nd second

#define int long long
typedef long long ll;
using namespace std;
//        w   m   r
int cnt[20][20][2];
ll fac[300005];

ll newtab[300005][21];
ll mod = 1000000007;

ll newton(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return newtab[n][k];
}


ll sum (ll n, ll k) {
    return (((newton(n-1, k-1) * ((n*(n+1))/2))%mod) * fac[k])%mod;
}


void rek(int L, int R, int w, int m, int r) {
    // if (L > R) return;
    if (L == R) {
        cnt[w][m][r+1]++;
        cnt[w][m+1][r]++;
        cnt[w+1][m][r]++;
        return;
    }
    cnt[w][m][r+1]++;
    int mid = (L+R)/2;
    if (mid-1 < L) {
        cnt[w+1][m][r]++;

    }
    else rek(L, mid-1, w+1, m, r);
    if (mid+1 > R){
        cnt[w][m+1][r]++;
    }
    else rek(mid+1, R, w, m+1, r);
}

void solve() {
    int n, q; cin >> n >> q;
    rek(1, n, 0, 0, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i-1]*i)%mod;
    newtab[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        newtab[i][0] = 1;
        for (int j = 1; j < 20; j++) {
            newtab[i][j] = (newtab[i-1][j] + newtab[i-1][j-1])%mod;
        }
    }
    while(q--) {
        int x; cin >> x;
        ll ans = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < 2; k++) {
                    // cout << i << ' ' << k << ' ' << j << ": " << cnt[i][j][k] << '\n';
                    if (cnt[i][j][k] == 0) continue;
                    ll tmp = 0;
                    ll smal = (newton(x-1, j) * fac[j])%mod;
                    ll big = (newton(n-x, i) * fac[i])%mod;
                    tmp += (sum(x-1, j) * big)%mod;
                    tmp += ((sum(n-x, i) + (((((newton(n-x, i) * fac[i])%mod) * x)%mod) * i)%mod) * smal)%mod;
                    tmp += (((k * x)%mod) * ((smal * big)%mod))%mod;
                    tmp %= mod;
                    tmp = (tmp*fac[n-i-j-k])%mod;
                    ans += (cnt[i][j][k]*tmp)%mod;
                }
            }
        }
        cout << ans%mod << '\n';
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