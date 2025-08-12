#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> mult(vector<vector<ll>>A, vector<vector<ll>> B, ll mod) {        
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size()));
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            for (int k = 0; k < B.size(); k++) {
                C[i][j] = (C[i][j]+ A[i][k] * B[k][j])%mod;
            }
        }
    }
    return C;
}


vector<vector<ll>> mPow(vector<vector<ll>> A, ll k, ll mod) {      
    vector<vector<ll>> res(A.size(), vector<ll>(A.size()));
    for (int i = 0; i < res.size(); i++) res[i][i] = 1;
    for (; k; k >>= 1, A = mult(A, A, mod)) {
        if (k&1) res = mult(res, A, mod);
    }
    return res;
}

ll getKth(ll k, vector<ll> base, vector<vector<ll>> matrix, ll mod) { 
    matrix = mPow(matrix, k, mod);
    vector<ll> result(base.size());
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            result[i] = (result[i]+matrix[i][j]*base[j])%mod;
        }
    }
    return result[0];
}

ll powmod(ll x, ll k, ll mod) {
    ll res = 1;
    for (; k; k>>=1, x = (x*x)%mod) {
        if (k&1) res = (res*x)%mod;
    }
    return res;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll tmp = getKth(m*2, {0, 1}, {{1, 1}, {1, 0}}, 1000000007);
    ll ans = powmod(tmp, n-1, 1000000007);
    // cout << tmp << ' ';
    cout << ans << "\n";
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