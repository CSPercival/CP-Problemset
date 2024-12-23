#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }


void solve(){
    int l,n,m; cin >> l >> n >> m;
    vector<int> ai(l);
    for(int i = 0; i < l; i++){
        cin >> ai[i];
    }

    vector<vector<int>> b(n + 1,vector<int>(m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    vector<vector<int>> dp(2,vector<int>(n + 1,vector<int>(m + 1,0)));
    for(int i = l - 1; i >= 0; i--){
        for(int j = 0 ; j <= n; j++) dp[i][j][m] = 1;
        for(int j = 0 ; j <= m; j++) dp[n][j] = 1;
        for(int j = n - 1; j >= 0; j--){
            for(int k = m - 1; k >= 0; k--){
                if(b[j][k] != ai[i]) continue;
                dp[i&1][j][k] = dp[i&1][j + 1][k] + dp[i&1][j][k + 1];
                if(dp[i&1][j + 1][k + 1] == 0){
                    dp[i&1][j][k] = 1;
                } else {
                    dp[i&1][j][k] = 0;
                }
            }
        }
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
