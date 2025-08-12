#include <bits/stdc++.h>
#define st first
#define nd second

#define int long long
typedef long long ll;
using namespace std;

vector<vector<int>> g;
vector<int> a;
vector<ll> cost;
vector<ll> tcost;
vector<ll> siz;
vector<ll> tsiz;

ll ans = 0;
int n;

void dfs1(int idx, int par){
    siz[idx] = a[idx];
    cost[idx] = 0;
    vector<int> c;
    // int nc = 0;
    for(int i = 0; i < g[idx].size(); i++){
        if(g[idx][i] != par){
            dfs1(g[idx][i], idx);
            c.push_back(siz[g[idx][i]]);
            siz[idx] += siz[g[idx][i]];
            cost[idx] += cost[g[idx][i]];
        }
    }
    int nc = c.size();
    cost[idx] += a[idx] * nc;
    sort(c.begin(), c.end());
    for(int i = 0; i < c.size(); i++){
        cost[idx] += c[i] * (nc - i);
    }
}

void dfs2(int idx, int par){
    vector<pair<int,int>> c;
    // int nc = 0;
    siz[idx] = a[idx];
    cost[idx] = 0;
    for(int i = 0; i < g[idx].size(); i++){
        // if(g[idx][i] != par){
            // dfs1(g[idx][i], idx);
        c.push_back({siz[g[idx][i]], g[idx][i]});
        cost[idx] += cost[g[idx][i]];
        siz[idx] += siz[g[idx][i]];
        // }
    }
    int nc = c.size();
    cost[idx] += a[idx] * nc;
    sort(c.begin(), c.end());
    for(int i = 0; i < c.size(); i++){
        cost[idx] += c[i].st * (nc - i);
    }
    ans = min(ans, cost[idx]);

    // cout << "IN " << idx << "\n";
    // for(int i = 0; i <= n; i++){
    //     cout << cost[i] << " " << siz[i] << "\n";
    // }

    cost[idx] -= a[idx];
    ll tmp;
    ll tmp2;
    for(int i = 0; i < c.size(); i++){
        tmp = c[i].st * (nc - i) + cost[c[i].nd];
        tmp2 = siz[c[i].nd];
        cost[idx] -= tmp;
        siz[idx] -= tmp2;
        if(c[i].nd != par)
            dfs2(c[i].nd, idx);
        cost[idx] += tmp;
        cost[idx] -= c[i].st;
        siz[idx] += tmp2;
    }
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int u,v;
    g.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }    

    cost.assign(n + 1, 0);
    tcost.assign(n + 1, 0);
    siz.assign(n + 1, 0);
    tsiz.assign(n + 1, 0);
    int sidx = 1;
    dfs1(sidx, 0);
    ans = cost[sidx];
    // for(int i = 0; i <= n; i++){
    //     cout << cost[i] << " " << siz[i] << "\n";
    // }
    // cout << cost[sidx] << "\n";
    dfs2(sidx, 0);
    
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    
}