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
    vector<int> ai(n + 1);
    vector<int> bi(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> bi[i];
    }

    vector<ll> vis(n + 1, LLONG_MAX);
    vis[0] = 0;
    vis[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    pair<ll,int> tmpp;
    while(!pq.empty()){
        tmpp = pq.top();
        pq.pop();
        if(tmpp.st != vis[tmpp.nd]) continue;
        
        if(vis[tmpp.nd - 1] > tmpp.st){
            vis[tmpp.nd - 1] = tmpp.st;
            pq.push({tmpp.st, tmpp.nd - 1});
        }

        if(vis[bi[tmpp.nd]] > tmpp.st + ai[tmpp.nd]){
            vis[bi[tmpp.nd]] = tmpp.st + ai[tmpp.nd];
            pq.push({vis[bi[tmpp.nd]], bi[tmpp.nd]});
        }
    }
    ll ans = 0;
    ll suma = 0;
    for(int i = 1; i <= n; i++){
        suma += ai[i];
        ans = max(ans, suma - vis[i]);
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
