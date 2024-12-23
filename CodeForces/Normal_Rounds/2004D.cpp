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
 
int city[200010];
vector<int> comb = {3, 5, 9, 6, 10, 12};
vector<int> pos[15];

int compute(int ptype, int l, int r){
    if(pos[ptype].size() == 0) return 1e9;
    if(pos[ptype].back() < l){
        return r - l + 2 * (l - pos[ptype].back());
    }
    if(pos[ptype][0] > r){
        return r - l + 2 * (pos[ptype][0] - r);
    }

    int po = 0, ko = pos[ptype].size() - 1, sr;
    while(po < ko){
        sr = (po + ko) / 2;
        if(pos[ptype][sr] > l){
            ko = sr;
        } else {
            po = sr + 1;
        }
    }
    if(pos[ptype][po] < r){
        return r - l;
    }
    return r - l + 2 * min(pos[ptype][po] - r,l - pos[ptype][po - 1]);
}

void solve(){
    int n,q; cin >> n >> q;
    string p;
    for(int i = 0; i <= n; i++){
        city[i] = 0;
    }
    for(int i = 0; i < 15; i++){
        pos[i].clear();
    }
    for(int i = 0; i < n; i++){
        cin >> p;
        // sort(all(p));
        if(p[0] == 'B' || p[1] == 'B'){
            city[i] |= 1;
        }
        if(p[0] == 'G' || p[1] == 'G'){
            city[i] |= 2;
        }
        if(p[0] == 'R' || p[1] == 'R'){
            city[i] |= 4;
        }
        if(p[0] == 'Y' || p[1] == 'Y'){
            city[i] |= 8;
        }
        pos[city[i]].push_back(i);
    }
    // for(int i = 0; i <= n; i++){
    //     cout << city[i] << "\n";
    // }


    int u,v;
    while(q--){
        cin >> u >> v;
        u--; v--;
        if(city[u] & city[v]){
            cout << abs(u - v) << "\n";
            continue;
        }
        int ans = 1e9;
        for(int i : comb){
            if(i == city[u] || i == city[v]) continue;
            ans = min(ans, compute(i, min(u, v), max(u, v)));
        }
        if(ans == 1e9){
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
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
