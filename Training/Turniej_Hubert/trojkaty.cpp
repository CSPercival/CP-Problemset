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


ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.st-b.st)*(a.st-b.st)+(a.nd-b.nd)*(a.nd-b.nd);
}

void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> points(n);
    set<pair<ll, ll>> p2;
    for (int i = 0; i < n; i++) {
        cin >> points[i].st >> points[i].nd;
        p2.insert({points[i].st*2, points[i].nd*2});
    }
    map<ll, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cnt.clear();
        for (int j = 0; j < n; j++) {
            cnt[dist(points[i], points[j])]++;
            if (i < j && p2.count({points[i].st+points[j].st, points[i].nd+points[j].nd})) ans--;
        }
        for (auto p: cnt) {
            ans += (p.nd*(p.nd-1))/2;
        }
        // cout << i << ": " << ans << '\n';
    }
    cout << ans << '\n';
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
