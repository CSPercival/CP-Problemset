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

int infi = 2e9;

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> seg;
    vector<pair<int,int>> brid;
    vector<vector<int>> g(n + 1);
    
    for(int i = 1; i < n; i++){
        g[i].push_back(i + 1);
    }
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        brid.push_back({u,v});
    }

    vector<int> dist(n + 1, infi);
    dist[1] = 0;
    for(int i = 1; i < n; i++){
        for(auto j : g[i]){
            dist[j] = min(dist[j], dist[i] + 1);
        }
    }

    for(auto i : brid){
        if(i.nd - dist[i.st] - 2 > i.st){
            seg.push_back({i.st + 1, i.nd - dist[i.st] - 2});
        }
    }
    sort(all(seg));

    // cout << seg;
    // cout << "\n";

    int segctr = 0;
    for(int i = 1; i < n; i++){
        while(segctr < seg.size() && seg[segctr].nd < i) segctr++;
        if(segctr == seg.size()){
            cout << "1";
            continue;
        }
        if(seg[segctr].st <= i && i <= seg[segctr].nd){
            cout << "0";
            continue;
        }
        cout << "1";
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
