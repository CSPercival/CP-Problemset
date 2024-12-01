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
    int n, m; cin >>  n >> m;
    vector<int> s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    // ll pott = 1;
    // for(int i = 0; i < m; i++){
    //     pott *= 2;
    //     if(pott - 1 >= n) break;
    // }
    // if(pott - 1 < n){
    //     cout << -1 << "\n";
    //     return;
    // }
    sort(all(s),greater<int>());
    vector<int> ans(n + 1,0);
    int pot = 2;
    for(int i = 1; i <= n; i++){
        // ans[pot - 1] = s[i];
        // for(int j = pot + pot/2 - 1; j < n; j += pot){
        //     ans[j] = s[i];
        // }
        // pot *= 2;
        for(int j = i + i; j <= n; j += i){
            if(ans[j] == ans[i]) ans[j]++;
            if(ans[j] == m){
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        // cout << i << ": " << s[ans[i]] << "\n";
        cout << s[ans[i]] << " ";
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
