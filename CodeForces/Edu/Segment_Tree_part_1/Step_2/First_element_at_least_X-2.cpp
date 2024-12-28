#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
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

    int query(int l, int r, int x){
        vector<int> visited;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1){
                if(t[l] >= x) return query_aux(l, x);
                l++;
            }
            if(r & 1) visited.push_back(--r);
        }
        while(!visited.empty()){
            if(t[visited.back()] >= x){
                return query_aux(visited.back(), x);
            }
            visited.pop_back();
        }
        return -1;
    }

    int query_aux(int idx, int x){
        while(idx < shift){
            idx <<= 1;
            if(t[idx] < x) idx++;
        }
        return idx - shift;
    }

};

int main(){
    BOOST;
    int n, m; cin >> n >> m;
    vector<int> ai(n);
    for(int i = 0; i < n; i++) cin >> ai[i];

    SegmentTreePURQ ds(n, ai);

    int mode, idx, val, x, l;
    for(int i = 0; i < m; i++){
        cin >> mode;
        if(mode == 1){
            cin >> idx >> val;
            ds.update(idx, val);
        } else {
            cin >> x >> l;
            cout << ds.query(l, n, x) << "\n";
        }
    }
}