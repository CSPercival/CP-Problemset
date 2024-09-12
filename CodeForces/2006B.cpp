#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
#define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

vector<int> g[200010];
vector<vector<int>> wn;
vector<int> maxn, par;
vector<int> limit;

int dfs(int idx){
    int maxi = idx;
    for(int i : g[idx]){
        maxi = max(maxi,dfs(i));
    }
    maxn[idx] = maxi;
    return maxi;
}

void f1(int idx, int idx2){
    int tidx = idx;
    if(g[idx].size() == 0){
        while(maxn[tidx] < idx2){
            wn[tidx].push_back(idx);
            limit[idx]++;
            tidx = par[tidx];
            // cout << tidx << " ok1" << endl;

        }
    }
    limit[idx]++;
    wn[idx2].push_back(idx);
}

void solve(){
    int n; cin >> n;
    ll w; cin >> w;
    par.assign(n + 1,0);
    maxn.assign(n + 1, 0);
    limit.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) g[i].clear();
    wn.clear();
    wn.resize(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> par[i];
        g[par[i]].push_back(i);
    }
    par[1] = 1;
    dfs(1);

    // cout << maxn;
    // cout << endl;

    for(int i = 1; i < n; i++){
        f1(i, i + 1);
    }
    int tidx = n;
    while(tidx != 1){
        // cout << "ok2" << endl;
        limit[n]++;
        wn[tidx].push_back(n);
        tidx = par[tidx];
    }

    // dfs(1,0);
    vector<int> ti(n + 1);
    int x,y;
    int ans = 0;
    int left = n;
    ll tw = w;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        ans += 2 * y;
        tw -= y;
        for(int j : wn[x]){
            limit[j]--;
            if(!limit[j]){
                left--;
            }
        }
        cout << ans + left * tw << " ";
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
