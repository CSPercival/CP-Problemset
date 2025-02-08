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
    int n; cin >> n;
    // vector<pair<int,int>> deg(n + 1);
    vector<int> deg(n + 1);
    
    // for(int i = 1; i <= n; i++) deg[i].nd = i;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<pair<int,int>> e;
    int a,b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        e.push_back({a,b});
        deg[a]++;
        deg[b]++;
    }
    int ans = 1;
    int vtd = 0;
    vector<int> vbest;
    for(int i = 1; i <= n; i++){
        if(deg[i] > deg[vtd]){
            vtd = i;
            vbest.clear();
        }
        if(deg[i] == deg[vtd]){
            vbest.push_back(i);
        }
    }
    vtd = vbest[0];
    if(vbest.size() <= 2){
        ans += deg[vtd] - 1;
        for(auto u : g[vtd]){
            deg[u]--;
        }
        deg[vtd] = 0;
        for(int i = 1; i <= n; i++){
             if(deg[i] > deg[vtd]){
                vtd = i;
            }
        }
        ans += deg[vtd] - 1;
    } else {
        ans += deg[vtd] - 1;
        ans += deg[vtd] - 1;
    }
    cout << ans << '\n';

}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
