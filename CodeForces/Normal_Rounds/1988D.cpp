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

ll infi = 5e17;
vector<vector<int>> g;
// vector<vector<int>> dp;
vector<int> ai;

pair<pair<int,int>, pair<int,int>> dfs(int idx, int par){
    pair<pair<int,int>, pair<int,int>> dans;
    vector<vector<pair<int, pair<int,int>>>> bround(60); 
    ll sum = 0;
    for(int i : g[idx]){
        if(i == par) continue;
        dans = dfs(i,idx);
        bround[dans.st.st].push_back({dans.st.nd,dans.nd});
        sum = min(infi,sum + dans.st.nd);
    }
    dans = {{0,infi},{0,infi}};
    ll ansik;
    for(int i = 1; i < 60; i++){
        ansik = min(infi, i * ai[idx] + sum);
        for(auto j : bround[i]){
            ansik = min(infi, ansik + j.nd.nd - j.st);
        }
        if(dans.st.nd > ansik){
            swap(dans.st,dans.nd);
            dans.st = {i,ansik};
        } else {
            if(dans.nd.nd > ansik){
                dans.nd = {i,ansik};
            }
        }
    }
    return dans;
}

void solve(){
    int n; cin >> n;
    vector<int> tai(n + 1);
    // vector<vector<int>(60,0)> tdp(n + 1);
    vector<vector<int>> tg(n + 1);
    ai = tai;
    g = tg;
    // dp = tdp;
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    int u,v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pair<pair<int,int>,pair<int,int>> dans;
    dans = dfs(1, 0);
    cout << dans.st.nd << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
