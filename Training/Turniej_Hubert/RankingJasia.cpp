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

vector<vector<int>> g;
vector<bool> vis;
int cnt;

void dfs(int u) {
    cnt++;
    vis[u] = true;
    for (int v: g[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}


int ans(vector<pair<int, int>> e, int n) {
    g = vector<vector<int>> (n+1);
    vis = vector<bool>(n+1);
    vector<int> zeros;
    vector<int> deg(n+1);
    for (auto p: e) {
        deg[p.nd]++;
        g[p.st].push_back(p.nd);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            zeros.push_back(i);
        }
    }
    while (!zeros.empty()) {
        int v = zeros.back();
        zeros.pop_back();
        for (int u: g[v]) {
            deg[u]--;
            if (!deg[u]) zeros.push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i]) return -1;
    }
    cnt = 0;
    dfs(1);
    return cnt-1;
}


void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edges.push_back({b, a});
    }
    int highest = ans(edges, n);
    if (highest == -1) {
        cout << "NIE\n";
        return;
    }
    highest++;
    for (int i = 0; i < m; i++) {
        swap(edges[i].st, edges[i].nd);
    }
    int lowest = n - ans(edges, n);
    cout << highest << ' ' << lowest << '\n';
    return;
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
