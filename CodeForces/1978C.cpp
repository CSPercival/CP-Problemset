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

ll f1(ll x){
    if(x&1){
        return x/2 * (x/2 + 1) * 2;
    } else {
        return x + x/2 * (x/2 - 1) * 2;
    }
}

void solve(){
    ll n, k; cin >> n >> k;
    if(k&1 || f1(n) < k){
        cout << "No\n";
        return;
    }
    // for(int i = 0; i < n; i++){
    //     cout << i << " " << f1(i) << "\n";
    // }
    vector<ll> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = i;
    }
    int idx = 0;
    int idx2 = n - 1;
    while(k > 0 && idx < idx2){
        if(k >= 2 * (idx2 - idx)){
            swap(ans[idx],ans[idx2]);
            k -= 2 * (idx2 - idx);
            idx++;
            idx2--;
        } else {
            idx2--;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
