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

int k = 300;
vector<int> g[5010];
int par[5010];
int subtree[5010];
int depth[5010];

void dfs(int idx, int ojc){
    par[idx] = ojc;
    subtree[idx] = 1;
    depth[idx] = depth[ojc] + 1;
    for(int i : g[idx]){
        if(i == ojc) continue;
        dfs(i,idx);
        subtree[idx] += subtree[i];
    }
}

void clear_path_to_root(int idx){
    int ojc = par[idx];
    while(idx != 1){
        subtree[ojc] = subtree[idx] + 1;
        while(g[ojc].size() > 1){
            if(g[ojc].back() == idx){
                swap(g[ojc].back(), g[ojc][g[ojc].size() - 2]);
            }
            g[ojc].pop_back();
        }
        idx = ojc;
        ojc = par[idx];
    }
}

int find_centroid(int idx){
    int bestc = idx;
    int tmp;
    for(int i : g[idx]){
        if(i == par[idx]) continue;
        tmp = find_centroid(i);
        if(abs(subtree[par[bestc]] - 2 * subtree[bestc]) > abs(subtree[par[tmp]] - 2 * subtree[tmp])) bestc = tmp;
    }
    return bestc;
}

int phase1(){
    int ans = 1;
    int v;
    while(true){
        assert(k > 0);
        v = find_centroid(1);
        cout << "? " << v << "\n";
        cout.flush();
        cin >> ans;
        k--;
        if(ans == 1) break;

        subtree[par[v]] -= subtree[v];
        for(int i = 0; i < g[par[v]].size(); i++){
            if(g[par[v]][i] == v){
                swap(g[par[v]][i],g[par[v]].back());
                g[par[v]].pop_back();
            }
        }
    }
    return v;
}

int phase2(int root){
    int v;
    int ans;
    while(subtree[root] > 1){
        assert(k > 0);
        v = find_centroid(root);
        cout << "? " << v << "\n";
        cout.flush();
        cin >> ans;
        k--;
        if(ans == 1){
            root = v;
            clear_path_to_root(v);
        } else {
            root = par[root];
            subtree[par[v]] -= subtree[v];
            for(int i = 0; i < g[par[v]].size(); i++){
                if(g[par[v]][i] == v){
                    swap(g[par[v]][i],g[par[v]].back());
                    g[par[v]].pop_back();
                }
            }
        }
    }
    return root;
}

void solve(){
    int n; cin >> n;
    k = 300;
    for(int i = 0; i <= n; i++) g[i].clear();
    
    int u,v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int last_seen = phase1();
    clear_path_to_root(last_seen);
    par[1] = 1;
    last_seen = phase2(last_seen);
    cout << "! " << last_seen << "\n";
}

 
int32_t main(){
    // BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
