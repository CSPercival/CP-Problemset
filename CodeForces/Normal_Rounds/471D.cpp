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

struct Hashing{
    int p, mod;
    vector<int> s;
    vector<ll> h;
    vector<ll> pk;
    int shift = 2e5 + 1;
    Hashing(int ip, int imod, vector<int> &is){
        p = ip; mod = imod; s = is;
        h.resize(s.size());
        pk.resize(s.size());
        h[0] = 0;
        pk[0] = 1;
        for(int i = 1; i < s.size(); i++){
            h[i] = (h[i - 1] * p + s[i] + shift) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    ll gethash(int l, int r){
        //if 0 based
        // l++;r++;
        ll ans = (h[r] - h[l - 1] * pk[r - l + 1]) % mod;
        if(ans < 0) ans += mod;
        return ans;
    }
};

void solve(){
    int n, w; 
    cin >> n >> w;
    vector<int> a(n), b(w);
    vector<int> da(n), db(w);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            da[0] = 0;
        } else {
            da[i] = a[i] - a[i - 1];
        }
    }
    for(int i = 0; i < w; i++){
        cin >> b[i];
        if(i == 0){
            db[0] = 0;
        } else {
            db[i] = b[i] - b[i - 1];
        }
    }
    Hashing ha1(31, 1e9 + 9, da);
    Hashing ha2(53, 1e9 + 7, da);
    Hashing hb1(31, 1e9 + 9, db);
    Hashing hb2(53, 1e9 + 7, db);
    int ans = 0;
    for(int i = 1; i < n - w + 2; i++){
        if(ha1.gethash(i, i + w - 2) == hb1.gethash(1, w - 1) &&
           ha2.gethash(i, i + w - 2) == hb2.gethash(1, w - 1) ){
            ans++;
        }
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
