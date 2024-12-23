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
    ll x;
    ll m;
    cin >> x >> m;
    //(x^y) % x == 0 || 
    ll ans = 0;
    for(ll y = 1; y <= min(x,m); y++){
        if((x^y) % y == 0) ans++;
    }
    //cout << ans << "\n";
    if(m % x == 0){
        ans += max(0LL,m/x - 1);
        ans -= 1;
        //cout << ans << "\n";
        for(ll kx = m; kx <= m + x; kx += x){
            if(x == kx) ans++;
            if(x < (x^kx) && (x^kx) <= m) ans++;
        }
    } else {
        ll newm = m/x;
        ans += max(newm - 1,0LL);
        ans -= 1;
        //cout << ans << "\n";
        newm *= x;
        for(ll kx = newm; kx <= newm + x; kx += x){
            if(x == kx) ans++;
            if(x < (x^kx) && (x^kx) <= m) ans++;
        }
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
