#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
using namespace std;
typedef long long ll;

const int zero = 2e9;

struct SegTree{
    vector<pair<int,int>> t;
    int shift = 1;
    int n;

    SegTree(int inn){
        n = inn;
        while(shift <= n) shift *= 2;
        t.assign(2 * shift, {zero, zero});
        for(int i = 0; i < n; i++){
            t[i + shift] = {zero, i};
        }
        for(int i = shift - 1; i >= 1; i--){
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update(int idx, int val){
        // cout << "update " << idx << " " << val << endl;
        // print();
        t[idx + shift] = {val, idx};
        for(idx += shift; idx > 1; idx >>= 1){
            t[idx >> 1] = min(t[idx], t[idx ^ 1]);
        }
        // print();
    }

    pair<int,int> query(int l, int r){
        // cout << "query" << endl;
        pair<int,int> ans = {zero, zero};
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l&1) ans = min(ans, t[l++]);
            if(r&1) ans = min(ans, t[--r]);
        }
        return ans;
    }

    void print(){
        cout << "shift: " << shift << "\n";
        for(int i = 1; i < t.size(); i++){
            cout << i << ": " << t[i].st << " - " << t[i].nd << "\n";
        }
    }
};

int main(){

    // int tmp = 16;
    // cout << (tmp << 1) << endl;
    int n, q; cin >> n >> q;
    SegTree ds(n);
    
    int action, l, r, p, idx, h;
    while(q--){
        // cout << "quest" << endl;
        cin >> action;
        if(action == 1){
            cin >> idx >> h;
            ds.update(idx, h);
        } else {
            cin >> l >> r >> p;
            // r++;
            int ans = 0;
            pair<int,int> mini = ds.query(l, r);
            while(mini.first <= p){
                // cout << mini.first << " " << mini.second << "\n";
                ans++;
                ds.update(mini.nd, zero);
                mini = ds.query(l, r);
            }
            cout << ans << "\n";
        }
    }
}