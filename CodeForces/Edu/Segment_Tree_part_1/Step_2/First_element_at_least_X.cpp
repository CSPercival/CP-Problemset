#include<bits/stdc++.h>
using namespace std;

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<int> t;
    SegmentTreePURQ(int in_n, vector<int> &ai){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        for(int i = 0; i < n; i++) t[i + shift] = ai[i];
        for(int i = shift - 1; i > 0; i--) t[i] = max(t[i << 1], t[(i << 1) + 1]);
    }

    void update(int idx, int val){
        for(idx += shift, t[idx] = val; idx > 1; idx >>= 1) t[idx >> 1] = max(t[idx], t[idx ^ 1]);
    }

    int query(int x){
        int idx = 1;
        if(t[idx] < x) return -1;
        while(idx < shift){
            idx <<= 1;
            if(t[idx] < x) idx++;
        }
        return idx - shift;
    }

    void print(){
        for(int i = 1; i < 2 * shift; i++){
            cout << i << ": " << t[i] << "\n"; 
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegmentTreePURQ ds(n, ai);

    int mode, idx, val, x;
    for(int i = 0; i < m; i++){
        cin >> mode;
        if(mode == 1){
            cin >> idx >> val;
            ds.update(idx, val);
        } else {
            cin >> x;
            cout << ds.query(x) << "\n";
        }
    }
}