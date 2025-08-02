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

bool check(int n, ll blim, vector<int> &b, vector<vector<pair<int,int>>> &g){
    priority_queue<int,vector<int>, greater<int>> pq;
    vector<ll> vis(n + 1, -1);
    vector<int> vised(n + 1, 0);
    ll bstat = 0;
    // bstat += min(blim, b[1]);
    int currv = 1;
    vis[currv] = bstat;
    pq.push(currv);

    // cout << "CHECK: " << blim << "\n";
    while(!pq.empty()){
        currv = pq.top();
        pq.pop();
        // cout << "bfs cv: " << currv << "\n"; 
        if(vised[currv]) continue;
        vised[currv] = 1;
        bstat = vis[currv];
        // cout << "bfs bstat " << bstat << "\n"; 
        bstat = min(blim, bstat + b[currv]);
        // cout << "bfs bstat " << bstat << "\n"; 
        for(auto dest : g[currv]){
            if(dest.nd <= bstat){
                vis[dest.st] = max(vis[dest.st], bstat);
                pq.push(dest.st);
            }
        }
    }
    // cout << vis << "\n";
    if(vis[n] != -1) return true;
    return false;
}

void solve(){
    int n, m; 
    ll max_batt = 0;
    cin >> n >> m;
    
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        max_batt = max_batt + b[i];
    }
    vector<vector<pair<int,int>>> g(n + 1);
    int si,ti,wi;
    for(int i = 0; i < m; i++){
        cin >> si >> ti >> wi;
        g[si].push_back({ti,wi});
    }

    if(!check(n, max_batt, b, g)){
        cout << "-1\n";
        return;
    }

    ll po = 0, ko = max_batt, sr;
    while(po + 1 < ko){
        sr = (po + ko)/2;
        if(check(n, sr, b, g)){
            ko = sr;
        } else {
            po = sr;
        }
    }
    cout << ko << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
