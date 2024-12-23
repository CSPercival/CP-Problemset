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

int ai[200010];

struct SegTree{
    vector<int> t;
    int shift = 1;
    SegTree(int n){
        while(shift <= n) shift *= 2;
        t.assign(2 * shift,0);
    }

    void add(int l, int r, int val){
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l&1) t[l++] += val;
            if(r&1) t[--r] += val;
        }
    }

    int query(int idx){
        int ans = 0;
        for(idx += shift; idx > 0; idx >>= 1){
            ans += t[idx];
        }
        return ans;
    }
};

int findk(int idx, SegTree *tree, int n){
    int po = 0, ko = n + 1, sr;
    while(po < ko){
        sr = (po + ko)/2;
        if((*tree).query(sr) < (ll)ai[idx] * sr){
            ko = sr; 
        } else {
            po = sr + 1;
        }
    }
    return po;
}

void solve(){
    int n; int q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    vector<int> mink(n + 1, 0);
    SegTree tree(n + 1);
    for(int i = 1; i <= n; i++){
        mink[i] = findk(i,&tree, n);
        tree.add(mink[i], n + 2, 1);
    }

    int idx, x;
    while(q--){
        cin >> idx >> x;
        if(mink[idx] <= x){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; // cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
