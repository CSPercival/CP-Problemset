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

int infi = 1e9 + 7;
vector<int> g[200010];
int ai[200010];

int dfs(int idx){
    int mini = infi;
    int tmp;
    for(int i : g[idx]){
        tmp = dfs(i);
        mini = min(mini,tmp);
    }

    if(mini == infi){
        return ai[idx];
    }
    if(idx == 1){
        return mini + ai[idx];
    }
    if(ai[idx] >= mini) return mini;
    return (mini + ai[idx])/2;
}

void solve(){
    int n; cin >> n;
    int u, v;

    for(int i = 0; i <= n; i++) g[i].clear();

    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    for(int i = 2; i <= n; i++){
        cin >> u;
        g[u].push_back(i);
    }

    cout << dfs(1) << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
