#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
using namespace std;
typedef long long ll;

struct Node{
    unsigned long long m = 0;
    int nod(){
        return __builtin_popcountll(m);
    }
};

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<Node> t;

    SegmentTreePURQ(int in_n, vector<int> &ai){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.resize(2 * shift);

        for(int i = 0; i < n; i++){
            t[shift + i].m = (1LL << ai[i]);
        }
        for(int i = shift - 1; i >= 1; i--){
            t[i].m = (t[i << 1].m | t[(i << 1) + 1].m);
        }
    }

    int query(int l, int r){
        Node ans = {0};
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans.m |= t[l++].m;
            if(r & 1) ans.m |= t[--r].m;
        }
        return ans.nod();
    }

    void update(int idx, int val){
        for(idx += shift, t[idx].m = (1LL << val); idx > 1; idx >>= 1){
            t[idx >> 1].m = (t[idx].m | t[idx ^ 1].m);
        }
    }

    void print(){
        for(int i = 1; i < t.size(); i++){
            cout << i << ": " << t[i].m << "\n";
        }
    }

};

int main(){
    BOOST;
    int n, q; cin >> n >> q;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ algo(n, ai);
    // algo.print();

    int t,x,y;
    while(q--){
        cin >> t >> x >> y;
        x--;
        if(t == 1){
            cout << algo.query(x,y) << "\n";
        } else {
            algo.update(x, y);
        }
    }
}