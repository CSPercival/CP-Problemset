#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;
typedef unsigned long long ull;


using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

const int N = 500005;
vector<pair<int, ull>> g[N];
int sz[N];
unordered_map<ull, ll> res[N];

void dfs(int u, int parent) {
    for (auto v: g[u]) {
        if (v.st == parent) continue;
        dfs(v.st, u);
        sz[u]+=sz[v.st];
    }
    sz[u]++;
}

ll ans;

pair<int, ull> dfs2(int u, int parent) {
    if (g[u].size() == 1 && u != 1) {
        res[u][0] = 1;
        return {u, 0};
    }
    pair<int, ull> big = {-1, -1};
    for (auto v: g[u]) {
        if (v.st == parent) continue;
        if (big.st == -1 || (sz[v.st] > sz[big.st])) big = v;
    }
    pair<int, ull> big_res = dfs2(big.st, u);
    if ( res[big_res.st].find(big.nd^big_res.nd) != res[big_res.st].end()) {
        ans += res[big_res.st][big.nd^big_res.nd];
        // cout << "W dol z " << u << ": " << res[big_res.st][big.nd] << '\n';
    }
    big_res.nd ^= big.nd;
    for (auto v: g[u]) {
        if (v.st == parent || v.st == big.st) continue;
        pair<int, ull> child_res = dfs2(v.st, u);
        if (res[child_res.st].find(v.nd^child_res.nd) != res[child_res.st].end()) {
            ans += res[child_res.st][v.nd^child_res.nd];
            // cout << "W dol z " << u << ": " << res[child_res.st][v.nd] << '\n';

        }
        for (auto p: res[child_res.st]) {
            ull path = p.st^v.nd^child_res.nd;
            if (res[big_res.st].find(path^big_res.nd) != res[big_res.st].end()){
                // cout << "Path with " << path << " through " << u << " - " << res[big_res.st][path^big_res.nd] * p.nd << '\n';
                ans += res[big_res.st][path^big_res.nd] * p.nd;
            }
        }
        for (auto p: res[child_res.st]) {
            ull path = p.st^v.nd^child_res.nd;
            // if (res[big_res.st].find(path^big_res.nd) != res[big_res.st].end()){
            //     ans += res[big_res.st][path^big_res.nd] * child_res.nd;
            // }
            res[big_res.st][path^big_res.nd] += p.nd;
        }
        res[child_res.st].clear();
        // unordered_map<ull, ll>().swap(res[child_res.st]);
        res[child_res.st].rehash(0);
        // res[child_res.st];
    }
    res[big_res.st][big_res.nd]++;
    return big_res;
}


void solve(){
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        int k; cin >> k;
        ull w = 0;
        for (int j = 0; j < k; j++) {
            ull b; cin >> b;
            w |= (1LL<<b-1);
        }
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
