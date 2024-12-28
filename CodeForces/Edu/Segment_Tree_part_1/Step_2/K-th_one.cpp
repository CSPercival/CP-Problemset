#include<bits/stdc++.h>
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<int> t;
    SegmentTreePURQ(int in_n, vector<int> &a){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.resize(2 * shift);
        for(int i = 0; i < n; i++){
            t[shift + i] = a[i];
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = t[i << 1] + t[(i << 1) + 1];
        }
    }

    void update(int idx){
        for(idx += shift, t[idx] ^= 1; idx > 1; idx >>= 1){
            t[idx >> 1] = t[idx] + t[idx ^ 1];
        }
    }

    int query(int k){
        int idx = 1;
        while(idx < shift){
            idx <<= 1;
            if(t[idx] < k){
                k -= t[idx];
                idx ^= 1;
            }
        }
        return idx - shift;
    }
};

int main(){
    BOOST;
    int n, q; cin >> n >> q;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ ds(n, ai);

    int mode, idx, k;
    for(int i = 0; i < q; i++){
        cin >> mode;
        if(mode == 1){
            cin >> idx;
            ds.update(idx);
        } else {
            cin >> k;
            cout << ds.query(k + 1) << "\n";
        }
    }
}