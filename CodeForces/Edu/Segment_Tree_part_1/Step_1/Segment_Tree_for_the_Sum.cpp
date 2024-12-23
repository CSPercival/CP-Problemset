#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef long long ll;

// Sum, Point Update Range Query
struct SegmentTreePURQ{
    vector<ll> t;
    int shift = 1;
    int n;
    SegmentTreePURQ(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        for(int i = 0; i < n; i++){
            t[i + shift] = a[i];
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = t[i << 1] + t[(i << 1) + 1];
        }
    }
    void update(int idx, int val){
        for(idx += shift - 1, t[idx] = val ;idx > 1; idx >>= 1){
            t[idx >> 1] = t[idx] + t[idx^1];
        } 
    }

    ll query(int l_idx, int r_idx){
        ll ans = 0;
        for(l_idx += shift - 1, r_idx += shift - 1; l_idx < r_idx; l_idx >>= 1, r_idx >>= 1){
            if(l_idx & 1) ans += t[l_idx++];
            if(r_idx & 1) ans += t[--r_idx];
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
            ds.update(idx + 1,v);
        } else {
            cin >> l >> r;
            cout << ds.query(l + 1, r + 1) << "\n";
        }
    }
}