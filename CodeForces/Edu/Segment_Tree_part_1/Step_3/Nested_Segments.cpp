#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<int> t;
    SegmentTreePURQ(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
    }

    int query(int l, int r){
        int ans = 0;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans += t[l++];
            if(r & 1) ans += t[--r];
        }
        return ans;
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
    vector<int> ai(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> ai[i];
    }
    vector<int> vis(n + 1, -1);
    SegmentTreePURQ ds(2 * n);
    // ds.print();

    vector<int> ans(n);
    for(int i = 0; i < 2 * n; i++){
        if(vis[ai[i]] == -1){
            vis[ai[i]] = i;
        } else {
            ans[ai[i] - 1] = ds.query(vis[ai[i]], i);
            ds.update(vis[ai[i]], 1);
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}