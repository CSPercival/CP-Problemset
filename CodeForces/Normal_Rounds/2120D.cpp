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

ll mod = 1e9 + 7;

ll fast_pow(ll a, ll k){
    ll ans = 1;
    if(k == 1) return (a % mod);
    ans = fast_pow(a, k/2);
    ans = (ans * ans) % mod;
    if(k&1){
        ans = (ans * a) % mod;
    }
    return ans;
}

ll rev_mod(ll x){
    return fast_pow(x, mod - 2);
}

void solve(){
    // int n; cin >> n;
    ll a,b,k,n,m;
    cin >> a >> b >> k;
    n = (a - 1) * k + 1;
    // n %= mod;
    // poss = npoa
    ll poss = 1;
    for(ll i = n - a + 1; i <= n; i++){
        poss = (poss * (i % mod)) % mod;
    }
    for(ll i = 1; i <= a; i++){
        poss = (poss * rev_mod(i)) % mod;
    }
    // m = ()
    m = (((poss * (b - 1)) % mod ) * k + 1) % mod;
    cout << n % mod << " " << m <<"\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
