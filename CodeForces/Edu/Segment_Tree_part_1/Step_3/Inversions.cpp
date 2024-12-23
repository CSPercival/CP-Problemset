#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
typedef long long ll;
using namespace std;

struct SegmentTreePURQ{
    int n;
    int shift = 1;
    vector<int> t;
    SegmentTreePURQ(int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
    }

    void update(int idx){
        for(idx += shift, t[idx] += 1; idx > 1; idx >>= 1){
            t[idx >> 1] = t[idx] + t[idx ^ 1];
        }
    }

    int query(int l){
        int r = n;
        int ans = 0;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans += t[l++];
            if(r & 1) ans += t[--r];
        }
        return ans;
    }

    void print(){
        for(int i = 1; i < n + shift; i++){
            cout << i << ":   " << t[i] << "\n";
        }
    }
};

int main(){
    BOOST;

    int n; cin >> n;

    SegmentTreePURQ ds(n);

    int ai;
    for(int i = 0; i < n; i++){
        cin >> ai;
        ai--;
        cout << ds.query(ai) << " ";
        ds.update(ai);
    }
    cout << "\n";
}
