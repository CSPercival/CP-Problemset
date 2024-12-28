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

vector<int> g[200010];
vector<int> par;
vector<int> leafs;
vector<int> l1;
vector<int> ilel2;
vector<int> ifleaf;

vector<int> l2dir[200010];

void dfs(int idx){
    int l2 = 1;
    for(int i : g[idx]){
        if(par[idx] == i) continue;
        par[i] = idx;
        dfs(i);
    }
    if(g[idx].size() == 1){
        leafs.push_back(idx);
        ifleaf[idx] = 1;
        l1.push_back(par[idx]);
    }
}

void dfs2(int idx){
    if(!ifleaf[idx]) ilel2[idx] = 1;
    for(int i : g[idx]){
        if(par[idx] == i) continue;
        dfs2(i);
        ilel2[idx] += ilel2[i];
    }
}

void solve(){
    int n; cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        l2dir[i].clear();
    }
    int u,v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    par.assign(n + 1, 0);
    leafs.clear();
    l1.clear();
    ifleaf.assign(n + 1, 0);
    dfs(1);

    ans = (ll)leafs.size() * ((ll)n - (ll)leafs.size());

    if(l1.back() == 0){
        l1.pop_back();
        l1.push_back(g[1][0]);
    }
    sort(all(l1));
    l1.resize(distance(l1.begin(), unique(all(l1))));
    for(int i : l1){
        for(int j : g[i]){
            if(ifleaf[j]) continue;
            l2dir[j].push_back(i);
        }
    }
    for(int i : l1){
        ifleaf[i] = 1;
    }
    ilel2.assign(n + 1, 0);
    dfs2(1);
    // cout << ilel2 << "\n";
    for(int q = 1; q <= n; q++){
        for(int p : l2dir[q]){
            // cout << ans << "\n";
            // cout << q << " - " << p << "\n";
            if(par[q] == p){
                ans += (ll)ilel2[1] - ilel2[q];
            } else {
                ans += (ll)ilel2[p];
            }
        }
    }
    cout << ans << "\n";
    // cout << l1 << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
