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
    vector<int> deg(n + 1,0);
    int u,v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    string s; cin >> s;
    
    int l0 = 0, l1 = 0, lp = 0, np = 0;
    for(int i = 2; i <= n; i++){
        if(deg[i] == 1){
            if(s[i - 1] == '0') l0++;
            if(s[i - 1] == '1') l1++;
            if(s[i - 1] == '?') lp++;
        } else {
            if(s[i - 1] == '?') np++;
        }
    }

    if(s[0] == '0'){
        cout << l1 + (lp + 1) / 2 << "\n";
        return;
    }
    if(s[0] == '1'){
        cout << l0 + (lp + 1) / 2 << "\n";
        return;
    }
    if(l0 != l1 || !(np&1)){
        cout << max(l0,l1) + lp / 2 << "\n";
        return;
    }
    cout << max(l0,l1) + (lp + 1) / 2 << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
