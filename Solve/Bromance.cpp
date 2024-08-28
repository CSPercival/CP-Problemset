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

struct Low{
    vector<vector<int>>* graph;
    vector<int> *low;
    vector<int> vis;
    int n;
    int preorder = 0;

    Low(int in_n, vector<vector<int>>* in_graph, vector<int> *ans){
        n = in_n; graph = in_graph; low = ans;
        vis.assign(n + 1,0);
        low->assign(n + 1,0);
        dfs(1,0);
    }

    void dfs(int idx, int par){
        (*low)[idx] = ++preorder;
        vis[idx] = preorder;
        for(int i : (*graph)[idx]){
            if(i == par) continue;
            if(vis[i]) (*low)[idx] = min((*low)[idx], vis[i]);
            else {
                dfs(i,idx);
                (*low)[idx] = min((*low)[idx],(*low)[i]);
            }
        }
    }
};

struct BCC{
    int n;
    int bcc_ctr = 0;
    vector<vector<int>> *ans, *graph;
    vector<int> bcc_stack, vis, low, *preorder;

    BCC(int in_n, vector<vector<int>> *in_graph, vector<vector<int>> *in_ans){
        n = in_n; graph = in_graph; ans = in_ans;
        vis.assign(n + 1, 0);
        Low algo(n,graph,&low);
        preorder = (&algo.vis);
        ans->emplace_back();
        bcc_stack.push_back(0);
        dfs(1);
    }

    void dfs(int idx){
        vis[idx] = 1;
        (*ans)[bcc_stack.back()].push_back(idx);
        for(int i : (*graph)[idx]){
            if(vis[i]) continue;
            if(low[i] >= (*preorder)[idx]){
                bcc_stack.push_back(++bcc_ctr);
                ans->emplace_back();
                (*ans)[bcc_stack.back()].push_back(idx);
                dfs(i);
                bcc_stack.pop_back();
            } else 
                dfs(i);
        }
    }
};

void dfs(int idx, vector<int> *vis, vector<vector<int>> *g){
    (*vis)[idx] = 1;
    for(int i : (*g)[idx]){
        if((*vis)[i]) continue;
        dfs(i,vis,g);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> gl(n + 1);
    vector<vector<int>> gm(n + 1, vector<int>(n + 1, 0));
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        gl[u].push_back(v);
        gl[v].push_back(u);
        gm[u][v] = 1;
        gm[v][u] = 1;
    }
    vector<int> vis(n + 1,0);
    dfs(1,&vis,&gl);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "NO\n";
            return;
        }
    }

    vector<vector<int>> bcc;
    BCC algo(n,&gl,&bcc);

    vector<int> hmbcc(n + 1, 0);
    hmbcc[1] = -1;
    for(auto i : bcc){
        for(int j = 0; j < i.size(); j++){
            hmbcc[i[j]]++;
            for(int k = j + 1; k < i.size(); k++){
                if(!gm[i[j]][i[k]]){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for(int i = 0; i <= n; i++){
        if(hmbcc[i] > 2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}