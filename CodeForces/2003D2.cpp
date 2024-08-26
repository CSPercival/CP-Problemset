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
 
int li[200010];
vector<int> aij[200010];

int deg[200010];
vector<int> graph[200010];
int vis[200010];
vector<pair<int,int>> tmpv;

void dfs(int idx, int col){
    vis[idx] = col;
    for(int i : graph[idx]){
        if(!vis[i]){
            dfs(i,col);
        }
    }
}

ll f1(long long x){
    return x * (x + 1) / 2;
}

void solve(){
    ll n; cin >> n;
    ll m; cin >> m;

    tmpv.clear();
    for(int i = 0; i <= n + 2; i++){
        graph[i].clear();
    }

    int ctr = 0;
    ll ansik;
    ll all_top = 0, double_top = 0, min_top = 0;
    ll mex1, mex2;
    ll ans = 0;
    // cout << "---------------\n";
    for(int i = 0; i < n; i++){
        cin >> li[i];
        aij[i].resize(li[i]);
        for(int j = 0; j < li[i]; j++){
            cin >> aij[i][j]; 
        }
        sort(all(aij[i]));
        ctr = 2;
        ansik = 0;
        mex1 = 0;
        mex2 = 0;
        for(int j = 0; j < li[i] && ctr > 0; j++){
            if(ansik == aij[i][j]) ansik++;
            else if(ansik > aij[i][j]) continue;
            else {
                mex2 = mex1;
                mex1 = ansik;
                ansik++;
                j--;
                ctr--;
            }
        }
        if(ctr == 2){
            mex2 = ansik;
            mex1 = ansik + 1;
        }
        if(ctr == 1){
            mex2 = mex1;
            mex1 = ansik;
        }

        // cout << mex2 << " - " << mex1 << "\n";

        tmpv.push_back({mex2,mex1});
        // deg[mex2]++;
        // graph[mex1].push_back(mex2);
        min_top = max(min_top, mex2);
        all_top = max(all_top, mex1);
    }
    for(int i = 0; i <= all_top; i++){
        deg[i] = 0;
        vis[i] = 0;
    }
    for(auto i : tmpv){
        deg[i.first]++;
        graph[i.second].push_back(i.first);
    }

    for(int i = all_top; i > 0; i--){
        if(!vis[i]){
            dfs(i, i);
        }
        // cout << vis[i] << " ";
    }
    // cout << "\n";

    for(int i = 0; i <= all_top; i++){
        if(deg[i] >= 2){
            double_top = max(double_top, vis[i]);
        }
    }
    // cout << double_top << "\n";
    for(int i = 0; i <= min(all_top, m); i++){
        // cout << i << " " << vis[i] << "\n";
        ans += max({vis[i], double_top, i, min_top});
    }
    cout << ans + f1(m) - f1(min(all_top, m)) << "\n";
    // cout << f1(m) - f1(min(ans,m)) + (min(ans,m) + 1) * ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
