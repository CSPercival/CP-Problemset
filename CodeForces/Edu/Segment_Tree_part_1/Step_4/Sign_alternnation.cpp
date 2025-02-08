#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
using namespace std;
typedef long long ll;

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<pair<ll, int>> t;
    SegmentTreePURQ(int in_n, vector<int> &ai){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(shift * 2, {0LL, 0});
        for(int i = 0; i < n; i++){
            t[i + shift] = {ai[i], 1};
        }
        for(int i = shift - 1; i > 0; i--) t[i] = merge(t[i << 1], t[(i << 1) + 1]);
    }

    ll query(int l, int r){
        ll ans = 0;
        pair<ll, int> ansl = {0,0};
        pair<ll, int> ansr = {0,0};
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ansl = merge(ansl, t[l++]);
            if(r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr).st;
    }

    void update(int idx, int val){
        idx += shift;
        t[idx] = {val, 1};
        for(idx >>= 1; idx > 1; idx >>= 1) t[idx] = merge(t[idx << 1], t[(idx << 1) + 1]);
    }

    pair<ll, int> merge(pair<ll, int> a, pair<ll, int> b){
        pair<ll, int> ans;
        ans.nd = a.nd + b.nd;
        ans.st = a.st;
        if(a.nd & 1) ans.st -= b.st;
        else ans.st += b.st;
        return ans;
    }

    void print(){
        for(int i = 1; i < n + shift; i++){
            cout << i << ": " << t[i].st << " - " << t[i].nd << "\n";
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

    SegmentTreePURQ ds(n, ai);
    // ds.print();
    int q; cin >> q;
    int mode, idx, val, l, r;
    while(q--){
        cin >> mode;
        if(mode == 0){
            cin >> idx >> val;
            ds.update(idx - 1, val);
        } else {
            cin >> l >> r;
            cout << ds.query(l - 1, r) << "\n";
        }
    }
}