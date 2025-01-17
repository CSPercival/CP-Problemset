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

int infi = 1e9 + 7;

struct Edge{
    int w, u, v;
    bool operator<(Edge const& x){
        if(w != x.w) return w < x.w;
        if(u != x.u) return u < x.u;
        return v < x.v;
    }
};


int n, m, q;
vector<Edge> edges;
int ans[410][410][410];
int dist[410][410];

void floyd_warshall(){
    for(auto e : edges){
        dist[e.u][e.v] = 1;
        dist[e.v][e.u] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void preprocessing(){
    floyd_warshall();

    for(auto e : edges){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                if(dist[u][v] > min(dist[u][e.u] + dist[e.v][v], dist[u][e.v] + dist[e.u][v])){
                    dist[u][v] = min(dist[u][e.u] + dist[e.v][v], dist[u][e.v] + dist[e.u][v]);
                    ans[u][v][dist[u][v] + 1] = e.w;
                }
            }
        }
    }

    int mini = infi;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mini = infi;
            for(int k = 1; k <= n; k++){
                mini = min(mini, ans[i][j][k]);
                ans[i][j][k] = mini;
            }
        }
    }
}

void clear_tabs(){
    edges.clear();
    int tmp;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            tmp = infi;
            if(i == j) tmp = 0;
            dist[i][j] = tmp;
            for(int k = 0; k <= n; k++){
                ans[i][j][k] = tmp;
            }
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    Edge e1;

    clear_tabs();

    for(int i = 0; i < m; i++){
        cin >> e1.u >> e1.v >> e1.w;
        edges.push_back(e1); 
    }
    sort(all(edges));

    preprocessing();

    int a,b,k;
    while(q--){
        cin >> a >> b >> k;
        cout << ans[a][b][k] << " ";
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
