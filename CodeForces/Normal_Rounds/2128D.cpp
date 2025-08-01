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

int go(int idx, vector<int> &p, int n){
    ll ans = 0;
    if(idx == 0){
        if(p[1] > p[idx]) return 1;
        return n;
    }
    if(idx == n - 1){
        return n;
    }
    if(p[idx] > p[idx + 1]){
        return ((long long)idx + 1) * (n - idx);
    } else {
        return (idx + 1);
    }
}

void solve(){
    int n; 
    cin >> n;
    vector<int> p(n);
    vector<int> gcj(n + 1);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        gcj[p[i]] = i;
    }
    ll ans = 0;
    for(int i = n; i > 0; i--){
        ans += go(gcj[i], p, n);
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
