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

struct ST_SetMin{
    int n;
    int shift = 1;
    vector<pair<int,int>> t;

    ST_SetMin(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, {0,0});
        for(int i = 0; i < n; i++) t[i + shift] = {a[i], i};
        for(int i = shift - 1; i > 0; i--) t[i] = merge(t[i << 1], t[(i << 1) + 1]);
    }

    void update(int idx, int val){
        for(idx += shift, t[idx].st = val; idx > 1; idx >>= 1) t[idx >> 1] = merge(t[idx], t[idx ^ 1]);
    }

    pair<int,int> query(int l, int r){
        pair<int,int> ans = t[l + shift];
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans = merge(ans, t[l++]);
            if(r & 1) ans = merge(ans, t[--r]);
        } 
        return ans;
    }

    pair<int,int> merge(pair<int,int> a, pair<int,int> b){
        pair<int,int> ans;
        if(a.st == 0) return b;
        if(b.st == 0) return a;
        if(a.st > b.st){
            return b;
        }
        if(a.st < b.st){
            return a;
        }
        if(a.nd < b.nd) return a;
        return b;
    }
};

struct ST_SetSum{
    int n;
    int shift = 1;
    vector<int> t;

    ST_SetSum(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        for(int i = 0; i < n; i++) t[i + shift] = 1;
        for(int i = shift - 1; i > 0; i--) t[i] = merge(t[i << 1], t[(i << 1) + 1]);
    }

    void update(int idx, int val){
        for(idx += shift, t[idx] = val; idx > 1; idx >>= 1) t[idx >> 1] = merge(t[idx], t[idx ^ 1]);
    }

    int query(int l, int r){
        int ans = 0;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans = merge(ans, t[l++]);
            if(r & 1) ans = merge(ans, t[--r]);
        } 
        return ans;
    }

    int merge(int a, int b){
        return a + b;
    }
};



void solve(){
    int n, k; cin >> n >> k;
    vector<int> di(n);
    vector<int> alive(n, 1);
    // map<int, ll> dp;

    for(int i = 0; i < n; i++){
        cin >> di[i];
    }

    ST_SetMin tmini(n, di);
    ST_SetSum tsum(n);

    vector<pair<int,int>> di2(n);
    for(int i = 0; i < n; i++){
        di2[i] = {di[i], i};
    }
    sort(all(di2));
    ll ans = 0;
    int idx;
    pair<int,int> tmpp;
    ll val;
    for(int i = di2.size() - 1; i >= 0; i--){
        // if(algo.query(di2[i].nd, di2[i].nd + 1).st == 0) continue;
        idx = di2[i].nd;
        val = di2[i].st;
        if(!alive[idx]) continue;
        if(tsum.query(idx + 1, n) < k) continue;
        // cout << idx << " " << val << "\n";
        ans += val;
        // cout << "d: ";
        for(int j = 0; j < k; j++){
            tmpp = tmini.query(idx + 1, n);
            // cout << tmpp.nd << " ";
            alive[tmpp.nd] = 0;
            tsum.update(tmpp.nd, 0);
            tmini.update(tmpp.nd, 0);
        }
        // cout << "\n";
        tsum.update(idx, 0);
        tmini.update(idx, 0);
        alive[idx] = 0;
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
