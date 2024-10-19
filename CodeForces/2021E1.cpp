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

struct Edge{ int u,v,w; };

struct UnionFind{
    int n;
    vector<int> leader;
    vector<int> siz;

    UnionFind(int in_n){
        n = in_n;
        leader.resize(n + 1);
        siz.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) leader[i] = i;
    }

    int Find(int a){
        if(leader[a] == a) return a;
        leader[a] = Find(leader[a]);
        return leader[a];
    }

    void Union(int a, int b){
        siz[Find(a)] += siz[Find(b)];
        leader[Find(b)] = Find(a);
    }
};

void solve(){
    int n, m, p; cin >> n >> m >> p;
    vector<int> houses(p);
    for(int i = 0; i < p; i++){
        cin >> houses[i];
    }
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
            if(a.w != b.w) return a.w < b.w;
            if(a.u != b.u) return a.u < b.u;
            return a.v < b.v;
        });

    UnionFind algo_uf(n);
    ll dp[500][500];
    ll infi = 1e18;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = infi;
        }
    }

    for(int i : houses){
        algo_uf.siz[i] = 1;
        for(int j = 1; j <= n; j++){
            dp[i][j] = 0;
        }
    }

    vector<ll> ans;
    int root = -1;
    for(auto edge : edges){
        int lu = algo_uf.Find(edge.u), lv = algo_uf.Find(edge.v), lw = edge.w;
        if(lu != lv){
            ans.assign(n + 1, infi);
            ans[0] = infi;
            for(int k = 1; k <= n; k++){
                ans[k] = min(dp[lu][k] + (ll)algo_uf.siz[lv] * lw, dp[lv][k] + (ll)algo_uf.siz[lu] * lw);
                for(int i = 1; i <= k - 1; i++){
                    int j = k - i;
                    ans[k] = min(ans[k], dp[lu][i] + dp[lv][j]);
                }
            }
            for(int k = 0; k <= n; k++){
                dp[lu][k] = ans[k];
            }
            algo_uf.Union(lu, lv);
            root = lu;
        }
    }
    for(int k = 1; k <= n; k++){
        cout << dp[root][k] << " ";
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
