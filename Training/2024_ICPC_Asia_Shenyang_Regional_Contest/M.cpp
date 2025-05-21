#include<bits/stdc++.h>

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)

typedef long long ll;
typedef long double ld;
//#define int ll

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

vector<vector<int>> g;
vector<vector<int>> rg;
// int outdeg[500010];
int n;

int mod(int a){
    a = a % n;
    if(a < 0) a += n;
    return a;
}

int findSCC(vector<vector<int>> &g, vector<vector<int>> &rg, vector<vector<int>> &SCC, vector<int> &SCCid){
    // int n = g.size();
    SCCid.assign(n, 0);
    vector<int> order;
    vector<int> vis(n, -1);
    SCCid.assign(n, -1);
    auto sccdfs = [](auto self, int idx, int color, vector<vector<int>> &graph,vector<int> &visited, vector<int> &vstack) -> void {
        visited[idx] = color;
        //cerr << "sccdfs: " << idx << "\n";
        for(int i : graph[idx]){
            int v = mod(idx + i);
            //cerr << "sccdfs " << idx << " nei " << v << "\n";
            if(visited[v] == -1){
                self(self, v, color, graph, visited, vstack);
            }
        }
        vstack.push_back(idx);
        //cerr << "sccdfs end: " << idx << "\n";

    };
    for(int i = 0; i < n; i++)
        if(vis[i] == -1) sccdfs(sccdfs, i, i, g, vis, order);
    
    int scc_ctr = 0;
    //cerr << "dfs done\n";
    // cout << order << " order\n";
    for(int i = n - 1; i >= 0; i--){
        if(SCCid[order[i]] == -1){ 
            //cerr << "dfs starting " << order[i] << "\n";
            sccdfs(sccdfs, order[i], scc_ctr, rg, SCCid, SCC[scc_ctr]);
            scc_ctr++;
        }
    }
    return scc_ctr;
}

void solve(){
    int m,q; cin >> n >> m >> q;
    int a, b;
    g.assign(n + 1, vector<int>());
    rg.assign(n + 1, vector<int>());
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(b == 0) continue;
        g[mod(a)].push_back(b);
        rg[mod(a + b)].push_back(b * -1);
        // outdeg[mod(a, n)]++;
    }

    vector<vector<int>> SCC(n, vector<int>());
    vector<int> SCCid(n, 0);
    //cerr << "ok0\n";
    int noSCC = findSCC(g, rg, SCC, SCCid);

    // cout << SCC << "\n";
    // cout << SCCid << "\n";

    //cerr << "ok1\n";

    vector<int> non_zero_cycle(n + 1, 0);

    queue<int> que_cycle;
    queue<int> que;
    int u, tv;
    ll infi = 1e18;
    ll cost;
    vector<ll> vis(n, infi);
    for(int i = 0; i < noSCC; i++){
        vis[SCC[i][0]] = 0;
        que.push(SCC[i][0]);
    }
    //cerr << "ok2\n";

    while(!que.empty()){
        u = que.front();
        que.pop();
        for(int v : g[u]){
            cost = vis[u] + v;
            tv = mod(u + v);
            if(SCCid[tv] != SCCid[u]) continue;
            if(vis[tv] == cost) continue;
            if(vis[tv] == infi){
                vis[tv] = cost;
                que.push(tv);
                continue;
            }
            non_zero_cycle[tv] = 1;
            que_cycle.push(tv);
        }
    }

    //cerr << "ok3\n";


    while(!que_cycle.empty()){
        u = que_cycle.front();
        que_cycle.pop();
        for(int v : rg[u]){
            tv = mod(u + v);
            if(non_zero_cycle[tv]) continue;
            que_cycle.push(tv);
            non_zero_cycle[tv] = 1;
        }
    }

    //cerr << "ok4\n";


    int x;
    for(int i = 0; i < q; i++){
        cin >> x;
        if(non_zero_cycle[mod(x)]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}


int main(){
    BOOST;
    solve();
    return 0;
}