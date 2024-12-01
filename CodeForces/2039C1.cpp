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
    // int numofdiv = 0;
    // int ans = 0;
    // if(x == 1){
    //     cout << "0\n";
    //     return;
    // }
    // int y = 0;
    // for(int i = 1; i * i <= x && i <= m; i++){
    //     if(x % i == 0 ){
    //         y = i;
    //         if(y != x && (x^y <= m))
    //             ans++;
    //         y = x/i;
    //         if(y != x && i != x/i && (x^y <= m))
    //             ans++;
    //     }
    // }
    int ans = 0;
    for(int i = 1; i <= min(2 * x,m); i++){
        if((x^i) % x == 0 || (x^i) % i == 0) ans++;
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
