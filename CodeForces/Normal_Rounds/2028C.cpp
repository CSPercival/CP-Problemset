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
    int n,m,v; cin >> n >> m >> v;
    vector<int> seg(n + 2,0);
    vector<int> pref(n + 2, 0);
    vector<int> suf(n + 2,0);
    vector<int> gdzie(max(n,m) + 10,-1);
    vector<ll> sumpre(n + 2,0);
    for(int i = 1; i <= n; i++){
        cin >> seg[i];
        sumpre[i] = sumpre[i - 1] + seg[i];
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += seg[i];
        pref[i] = pref[i - 1];
        if(sum >= v){
            pref[i]++;
            sum = 0;
        }
    }
    sum = 0;
    gdzie[0] = n + 1;
    for(int i = n; i > 0; i--){
        sum += seg[i];
        suf[i] = suf[i + 1];
        if(sum >= v){
            suf[i]++;
            gdzie[suf[i]] = i;
            sum = 0;
        }
    }
    ll ans = 0;
    int rend;
    // cout << pref << "\n";
    // cout << suf << "\n";
    // cout << gdzie << "\n";
    for(int i = 1; i <= n; i++){
        rend = gdzie[max(0,m - pref[i - 1])] - 1;
        if(rend < i) continue;
        ans = max(ans, sumpre[rend] - sumpre[i - 1]);
    }
    if(gdzie[m] == -1){
        cout << "-1\n";
    } else {
        cout << ans << "\n";
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
