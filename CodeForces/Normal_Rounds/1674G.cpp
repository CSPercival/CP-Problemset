//Rating 2000
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


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<vector<int>> ing(n + 1);
    vector<int> indeg(n + 1, 0);
    vector<int> alive(n + 1, 1);

    int a, b;
    for(int i = 0 ; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        ing[b].push_back(a);
        indeg[b]++;
    }

    vector<int> depth(n + 1, 0);
    queue<int> q;
    vector<int> toq(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1){
            indeg[g[i][0]]--;
            if(indeg[g[i][0]] == 0) 
                toq[g[i][0]] = 1;
            g[i].pop_back();
        }
        if(ing[i].size() == 1){
            // g[i].pop_back();
            alive[i] = 0;
            ing[i].pop_back();
        }
        if(ing[i].size() == 0){
            // q.push(i);
            // depth[i] = 1;
            toq[i] = 1;
        }
    }
    // cout << g << "\n";
    // cout << alive << "\n";
    for(int i = 1; i <= n ; i++){
        if(toq[i]){
            depth[i] = 1;
            q.push(i);
        }
    }

    int curr = 0;
    int ans = 1;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        // cout << curr << endl;
        for(auto i : g[curr]){
            if(!alive[i]) continue;
            // cout << "somsiad: " << i << "\n";
            depth[i] = max(depth[i], depth[curr] + 1);
            // ans = max(ans, depth[i]);
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }
    ans = 1;
    for(int i = 1; i <= n; i++){
        ans = max(ans, depth[i]);
    }
    cout << ans << "\n";
}

 
int32_t main(){
    // BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
