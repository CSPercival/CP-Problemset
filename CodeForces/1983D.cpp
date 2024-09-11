#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

struct SegTree{
    vector<int> t;
    int shift = 1;
    SegTree(int n){
        while(shift <= n) shift <<= 1;
        t.assign(shift * 2, 0);
    }

    void add(int idx){
        for(idx += shift; idx > 0; idx >>= 1){
            t[idx] += 1;
        }
    }

    int query(int l, int r){
        int ans = 0;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l&1) ans += t[l++];
            if(r&1) ans += t[--r];
        }
        return ans;
    }

    void clear(){
        for(int i = 0; i < shift * 2; i++){
            t[i] = 0;
        }
    }
};

ll count_inv(vector<int> &a){
    SegTree T((int)a.size() + 10);
    // (*T).clear();
    ll ans = 0;
    for(int i = 0; i < a.size(); i++){
        // cout << a[i] << endl;
        ans += T.query(1, a[i]);
        T.add(a[i]);
    }
    return ans;
}

map<int,int> code;

void solve(){
    int n; cin >> n;
    vector<int> ai(n), bi(n);
    code.clear();
    int maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    for(int i = 0; i < n; i++){
        cin >> bi[i];
    }
    vector<int> sai = ai,sbi = bi;
    sort(all(sai));
    sort(all(sbi));
    for(int i = 0; i < n; i++){
        if(sai[i] != sbi[i]){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0; i < n; i++){
        code[sai[i]] = i + 1;
    }
    for(int i = 0; i < n; i++){
        ai[i] = code[ai[i]];
        bi[i] = code[bi[i]];
    }
    // for(int i = 1; i < n; i++){
    //     if(sai[i] == sai[i - 1]){
    //         cout << "YES\n";
    //         return;
    //     }
    // }
    // cout << "ok1" << endl;

    ll inva = count_inv(ai);
    // cout << "ok2" << endl;
    ll invb = count_inv(bi);
    // cout << "ok3" << endl;

    // cout << inva << " " << invb << "\n";
    if(inva % 2 == invb % 2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

 
int32_t main(){
    BOOST;
    
    // SegTree T(200010);
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
