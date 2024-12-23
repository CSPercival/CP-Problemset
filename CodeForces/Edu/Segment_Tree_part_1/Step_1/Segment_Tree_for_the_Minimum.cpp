#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

// Minimum, Point Update Range Query
struct SegmentTreePURQ{
    int n;
    int shift = 1;
    vector<int> t;

    SegmentTreePURQ(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        for(int i = 0; i < n; i++){
            t[i + shift] = a[i];
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = min(t[i << 1], t[(i << 1) + 1]);
        }
    }

    void update(int idx, int val){
        for(idx += shift, t[idx] = val; idx > 1; idx >>= 1){
            t[idx >> 1] = min(t[idx], t[idx ^ 1]);
        }
    }

    int query(int l, int r){
        int ans = t[l + shift];
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans = min(ans, t[l++]);
            if(r & 1) ans = min(ans, t[--r]);
        } 
        return ans;
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

    int mode, idx, v, l, r;
    while(m--){
        cin >> mode;
        if(mode&1){
            cin >> idx >> v;
            ds.update(idx,v);
        } else {
            cin >> l >> r;
            cout << ds.query(l, r) << "\n";
        }
    }
}