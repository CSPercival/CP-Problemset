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

struct ST_SetSum{
    vector<ll> t;
    int shift = 1;
    int n;
    ST_SetSum(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 1);
        // for(int i = 0; i < n; i++) t[i + shift] = a[i];
        for(int i = shift - 1; i > 0; i--) t[i] = t[i << 1] + t[(i << 1) + 1];
    }
    void update(int idx, int val){
        for(idx += shift, t[idx] = val ;idx > 1; idx >>= 1) t[idx >> 1] = t[idx] + t[idx^1];
    }
 
    ll query(int l_idx, int r_idx){
        ll ans = 0;
        for(l_idx += shift, r_idx += shift; l_idx < r_idx; l_idx >>= 1, r_idx >>= 1){
            if(l_idx & 1) ans += t[l_idx++];
            if(r_idx & 1) ans += t[--r_idx];
        }
        return ans;
    }

    void print(){
        for(int i = 1; i <= n + shift; i++){
            cout << i << ": " << t[i] << "\n";
        }
    }
};

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> imp(n);
    vector<int> vis(2 * n + 10, 0);
    ST_SetSum ds(2 * n + 10);

    // ds.print();

    for(int i = 0; i < n; i++){
        cin >> imp[i].st >> imp[i].nd;
        if(imp[i].st == imp[i].nd){
            ds.update(imp[i].st, 0);
            vis[imp[i].st]++;
        }
    }

    // ds.print();

    for(int i = 0; i < n; i++){
        if(imp[i].st == imp[i].nd){
            if(vis[imp[i].st] <= 1){
                cout << '1';
            } else {
                cout << '0';
            }
            continue;
        }
        if(ds.query(imp[i].st, imp[i].nd + 1) > 0){
            cout << '1';
        } else {
            cout << '0';
        }
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
