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

struct Node{
    ll best, pref, suf, all;
};
Node Nzero = {0LL,0LL,0LL,0LL};

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<Node> t;
    SegmentTreePURQ(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, Nzero);
        for(int i = 0; i < n; i++){
            t[i + shift] = create(a[i]);
        }
        for(int  i = shift - 1; i > 0; i--){
            t[i] = merge(t[i << 1], t[(i << 1) + 1]);
        }
    }

    void update(int idx, int val){
        idx += shift;
        t[idx] = create(val);
        for(idx >>= 1; idx > 0; idx >>= 1){
            t[idx] = merge(t[idx << 1], t[(idx << 1) + 1]);
        }
    }

    ll query(){
        return t[1].best;
    }

    Node create(int val){
        Node ans = {max(val, 0), max(val, 0), max(val, 0), val};
        return ans;
    }

    Node merge(Node a, Node b){
        Node ans;
        ans.all = a.all + b.all;
        ans.best = max({a.best, b.best, a.suf + b.pref, 0LL});
        ans.pref = max({a.pref, a.all + b.pref, 0LL});
        ans.suf = max({b.suf, a.suf + b.all, 0LL});
        return ans;
    }
};

 
int32_t main(){
    BOOST;
 
    int n, q; cin >> n >> q;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ ds(n,ai);

    cout << ds.query() << "\n";
    int idx, val;
    for(int i = 0; i < q; i++){
        cin >> idx >> val;
        ds.update(idx,val);
        cout << ds.query() << "\n";
    }
    return 0;
}
