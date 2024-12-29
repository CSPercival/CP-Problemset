#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;

struct SegmentTreeRUPQ{
    int n, shift = 1;
    vector<long long> t;
    SegmentTreeRUPQ(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
    }

    void update(int l, int r, int val){
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) t[l++] += val;
            if(r & 1) t[--r] += val;
        }
    }

    long long query(int idx){
        long long ans = 0;
        for(idx += shift; idx > 0; idx >>= 1) ans += t[idx];
        return ans;
    }
};

int main(){
    BOOST;
    
    int n, q; cin >> n >> q;

    SegmentTreeRUPQ ds(n);

    int mode, l, r, v, i;
    while(q--){
        cin >> mode;
        if(mode == 1){
            cin >> l >> r >> v;
            ds.update(l, r, v);
        } else {
            cin >> i;
            cout << ds.query(i) << "\n";
        }
    }
}