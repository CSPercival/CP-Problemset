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

void dfs(int idx, int par, int c, vector<int> &col, vector<vector<int>> &g){
    col[idx] = c;
    for(int i : g[idx]){
        if(par == i) continue;
        dfs(i,idx,c^1,col,g);
    }
}

int git;

void dfs2(int idx, int par, int c, vector<pair<int,int>> &ans, vector<vector<int>> &g){
    // if(g[idx].size() == 2 && git2 == ){
    //     git1 = 1;
    //     git2 = 1;    
    // }
    for(int i : g[idx]){
        if(par == i) continue;
        if(!git && g[i].size() == 2){
            git = 1;
            if(c == 0){
                ans.push_back({idx, i});
            } else {
                ans.push_back({i, idx});
            }
            dfs2(i,idx,c,ans,g);
            continue;
        }
        if(c == 0){
            ans.push_back({idx, i});
        } else {
            ans.push_back({i, idx});
        }
        dfs2(i,idx,c^1,ans,g);
    }
    // for(int i : g[idx]){
    //     if(par == i) continue;
    //     dfs(i,idx,c^1,col,g);
    // }
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> e(n - 1);
    vector<int> deg(n + 1, 0);
    vector<int> col(n + 1, 0);
    vector<vector<int>>g(n + 1);
    vector<pair<int,int>> ans;
    for(int i = 0; i < n - 1; i++){
        cin >> e[i].st >> e[i].nd;
        g[e[i].st].push_back(e[i].nd);
        g[e[i].nd].push_back(e[i].st);
        deg[e[i].st]++;
        deg[e[i].nd]++;
    }
    // dfs(1, 0, 0, col, g);
    git = 0;
    int root = 1;
    if(deg[root] == 2) root = 2;
    dfs2(root, 0, 0, ans, g);
    if(git){
        cout << "YES\n";
        for(auto i : ans){
            cout << i.st << " " << i.nd << "\n";
        }
    } else {
        
        cout << "NO\n";
    }
    // int spe = -1;
    // for(int i = 0; i < e.size(); i++){
    //     assert(deg[e[i].st] != 0);
    //     assert(deg[e[i].nd] != 0);
    //     assert(col[e[i].st] != col[e[i].nd]);
    //     if(deg[e[i].st] + deg[e[i].nd] == 3){
    //         spe = i;
    //         break;
    //     }
    // }
    // if(spe == -1){
    //     cout << "NO\n";
    //     return;
    // }
    // cout << "YES\n";
    // for(int i = 0; i < e.size(); i++){
    //     if(i == spe){
    //         if(col[e[i].st] == 1){
    //             cout << e[i].st << " " << e[i].nd << "\n";
    //         } else {
    //             cout << e[i].nd << " " << e[i].st << "\n";
    //         }
    //         continue;
    //     }
    //     if(col[e[i].st] == 0){
    //         cout << e[i].st << " " << e[i].nd << "\n";
    //     } else {
    //         cout << e[i].nd << " " << e[i].st << "\n";
    //     }
    // }

}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
