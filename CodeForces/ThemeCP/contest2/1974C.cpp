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
    int n; cin >> n;
    map<pair<int,int>, int> m12,m13,m23;
    map<pair<pair<int,int>,int>,int> mall;
    int a1,a2,a3;
    cin >> a1 >> a2;
    ll ans = 0;
    for(int i = 2; i < n; i++){
        cin >> a3;
        ans += m12[{a1,a2}] - mall[{{a1,a2},a3}];
        ans += m13[{a1,a3}] - mall[{{a1,a2},a3}];
        ans += m23[{a2,a3}] - mall[{{a1,a2},a3}];
        m12[{a1,a2}]++;
        m13[{a1,a3}]++;
        m23[{a2,a3}]++;
        mall[{{a1,a2},a3}]++;
        a1 = a2;
        a2 = a3;
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
