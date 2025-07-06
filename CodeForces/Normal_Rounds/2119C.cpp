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


void solve(){
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if(n&1){
        cout << l << "\n";
        return;
    }
    if(n == 2){
        cout << "-1\n";
        return;
    }
    ll min1 = 1, max1 = 1;
    while(min1 <= l) min1 <<= 1;
    min1 >>= 1;
    while(max1 <= r) max1 <<= 1;
    max1 >>= 1;
    if(min1 < max1){
        if(k <= n - 2){
            cout << l << "\n";
        } else {
            cout << (min1 << 1) << "\n";
        }
        return;
    }
    cout << "-1\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
