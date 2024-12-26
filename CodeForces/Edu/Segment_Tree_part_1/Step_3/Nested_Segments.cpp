#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<int> t;
    SegmentTreePURQ(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(shift * 2, 0);
        for(int i = 0; i < n; i++){
            t[i + shift] = 1;
        }
        for(int i = shift - 1; i > 0; i--) t[i] = t[i << 1] + t[(i << 1) + 1];
    }

    int query(int k){
        int idx = 1;
        while(idx < shift){
            idx <<= 1;
            if(t[idx] < k){
                k -= t[idx];
                idx++;
            }
        }
        return idx - shift;
    }

    void update(int idx, int val){
        for(idx += shift, t[idx] = val; idx > 1; idx >>= 1) t[idx >> 1] = t[idx] + t[idx ^ 1];
    }

    void print(){
        for(int i = 1; i < n + shift; i++){
            cout << i << ": " << t[i] << "\n";
        }
    }
};

int main(){
    BOOST;
    int n; cin >> n;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ ds(n);
    // ds.print();

    vector<int> ans(n,0);
    for(int i = n - 1; i >= 0; i--){
        ans[i] = ds.query(i - ai[i] + 1);
        // cout << i - ai[i] << " " << ans[i] << "\n";
        ds.update(ans[i], 0);
        // ds.print();
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}