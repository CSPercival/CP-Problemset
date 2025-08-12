#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
#define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

int mod = 998'244'353;

void solve(){
    int n, x;
    cin >> n >> x;
    int limx = n * (n - 1)/2 + n - 1; 
    if(x < limx){
        cout << "0\n";
        return;
    }
    vector<int> dp(x + 2, 0);
    // int initial = (n + 1) * (n - 1) - n * (n + 1)/2;
    int initial = max(0LL, (n + 1) * (n - 2)/2);
    if(n + initial > x){
        cout << "0\n";
        return;
    }
    dp[n + initial] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(i + j <= x){
                dp[i + j] = (dp[i + j] + dp[j]) % mod;
            }
        }
        // cout << i << " " << dp << "\n";
    }
    ll ans = 0;
    for(int j = 0; j <= x; j++){
        dp[j + 1] = (dp[j + 1] + dp[j]) % mod;
        ans = (ans + dp[j]) % mod;
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
