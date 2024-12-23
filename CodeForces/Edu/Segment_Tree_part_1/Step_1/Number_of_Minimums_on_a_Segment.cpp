#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
typedef long long ll;
using namespace std;

struct SegmentTreePURQ{
    int n;
    int shift = 1;
    vector<pair<int,int>> t;
    pair<int, int> pzero = {INT_MAX, 0}; 
    SegmentTreePURQ(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, pzero);

        for(int i = 0; i < n; i++){
            t[i + shift] = {a[i], 1};
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = combine(t[i << 1] , t[(i << 1) + 1]);
        }
    }

    void update(int idx, int val){
        for(idx += shift, t[idx] = {val,1}; idx > 1; idx >>= 1){
            t[idx >> 1] = combine(t[idx], t[idx ^ 1]);
        }
    }

    pair<int, int> query(int l, int r){
        pair<int,int> ans = pzero;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans = combine(ans, t[l++]);
            if(r & 1) ans = combine(ans, t[--r]);
        }
        return ans;
    }


    pair<int,int> combine(pair<int,int> a, pair<int,int> b){
        if(a.st == b.st) return {a.st, a.nd + b.nd};
        if(a.st < b.st) return a;
        return b;
    }

    void print(){
        for(int i = 1; i < n + shift; i++){
            cout << i << ":  " << t[i].st << " " << t[i].nd << '\n';
        }
    }
};

int main(){
    BOOST;

    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    SegmentTreePURQ ds(n,a);
    // ds.print();

    int mode, idx, v, l, r;
    pair<int, int> ans;
    while(m--){
        cin >> mode;
        if(mode&1){
            cin >> idx >> v;
            ds.update(idx,v);
        } else {
            cin >> l >> r;
            ans = ds.query(l, r);
            cout << ans.st << " " << ans.nd << "\n";
        }
    }
}