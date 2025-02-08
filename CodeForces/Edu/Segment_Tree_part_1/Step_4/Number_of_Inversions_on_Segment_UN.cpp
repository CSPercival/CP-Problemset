#include<bits/stdc++.h>
using namespace std;
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

struct Node{
    ll v[42];
    // vector<ll> v(42,0);
    ll inv = 0;
    ll s = 0;
    Node(){
        for(int i = 0; i <= 41; i++) v[i] = 0;
    }

    void print(int range){
        cout << "inv:  " << inv << "\n";
        cout << "size: " << s << "\n";
        for(int i = 0; i <= range; i++){
            cout << i << " ";
        }
        cout << "\n";
        for(int i = 0; i <= range; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<Node> t;
    SegmentTreePURQ(int in_n, vector<int> &ai){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.resize(shift * 2);
        for(int i = 0; i < n; i++){
            t[i + shift].s = 1;
            for(int j = ai[i]; j <= 40; j++){
                t[i + shift].v[j]++;
            }
        }
        for(int i = shift - 1; i >= 1; i--){
            t[i] = merge(t[i << 1], t[(i << 1) + 1]);
        }
    }

    void update(int idx, int val){
        idx += shift;
        t[idx].inv = 0;
        t[idx].s = 1;
        for(int i = 0; i <= 40; i++){
            t[idx].v[i] = (i >= val);
        }
        for(idx >>= 1; idx >= 1; idx >>= 1){
            t[idx] = merge(t[idx << 1], t[(idx << 1) + 1]);
        }
    }

    ll query(int l, int r){
        Node ansl, ansr;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ansl = merge(ansl, t[l++]);
            if(r & 1) ansr = merge(t[--r], ansr);
        }
        ansl = merge(ansl, ansr);
        return ansl.inv;
    }

    Node merge(Node &a, Node &b){
        Node ans;
        ans.inv = a.inv + b.inv;
        ans.s = a.s + b.s;
        for(int i = 1; i <= 40; i++){
            ans.v[i] = a.v[i] + b.v[i];
            ans.inv += (b.v[i] - b.v[i - 1]) * (a.s - a.v[i]);
        }
        // cout << "M XDD:\n";
        // ans.print(9);
        return ans;
    }

    void print(){
        for(int i = 1; i < shift + n; i++){
            cout << "I: " << i << "\n";
            t[i].print(9);
            cout << "\n";
        }
    }
};  

int main(){
    BOOST;
    int n,q; cin >> n >> q;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ algo(n, ai);

    // algo.print();

    int tp, x, y;
    while(q--){
        cin >> tp >> x >> y;
        if(tp == 1){
            cout << algo.query(x - 1, y) << "\n";
        } else {
            algo.update(x - 1, y);
            // algo.print();
        }
    }
}
/*
7 6
1 2 3 6 5 4 9
1 1 3
1 2 5
1 2 4
2 2 8
1 1 6
1 1 3
*/