#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
#define all(x) x.begin(), x.end()
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
 
    void update(int idx, int val){
        for(idx += shift, t[idx] += val; idx > 1; idx >>= 1) t[idx >> 1] = t[idx] + t[idx ^ 1];
    }
 
    int query(int l, int r){
        int ans = 0;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ans += t[l++];
            if(r & 1) ans += t[--r];
        }
        return ans;
    }
};
 
int main(){
    BOOST;
    int n, q; cin >> n >> q;
    vector<int> ai(n);
    vector<tuple<char,int,int>> qi(q);
    
    vector<int> o2nv(n + 2 * q);
    map<int,int> o2n;
    for(int i = 0; i < n; i++){
        cin >> ai[i];
        o2nv[i] = ai[i];
    }
    char mode;
    int a, b, k, x;
    for(int i = 0; i < q; i++){
        cin >> mode >> a >> b;
        get<0>(qi[i]) = mode;
        get<1>(qi[i]) = a;
        get<2>(qi[i]) = b;
        o2nv[n + 2 * i] = get<1>(qi[i]);
        o2nv[n + 2 * i + 1] = get<2>(qi[i]);
    }
    sort(all(o2nv));
    o2nv.resize(distance(o2nv.begin(), unique(all(o2nv))));
    
    for(int i = 0; i < (int)o2nv.size(); i++){
        o2n[o2nv[i]] = i;
    }
 
    SegmentTreePURQ ds((int)o2nv.size() + 1);
    for(int i = 0; i < n; i++){
        ds.update(o2n[ai[i]], 1);    
    }
 
    
    for(int i = 0; i < q; i++){
        mode = get<0>(qi[i]);
        if(mode == '!'){
            k = get<1>(qi[i]);
            x = get<2>(qi[i]);
            k--;
            ds.update(o2n[ai[k]], -1);
            ai[k] = x;
            ds.update(o2n[ai[k]], 1);
        } else {
            a = get<1>(qi[i]);
            b = get<2>(qi[i]);
            cout << ds.query(o2n[a], o2n[b] + 1) << "\n";
        }
    }
}