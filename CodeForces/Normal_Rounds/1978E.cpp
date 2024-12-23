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

pair<int,int> f1(int idx, string &a, string &b){
    int il = idx - 1, ir = idx + 1;
    // cout << idx << " XD\n";
    if(b[il] == '#') return {-1,-1};
    if(b[il] == '0'){
        il--;
        if(a[il] != '0') return {-1,-1};
    }
    if(b[ir] == '#') return {-1,-1};
    if(b[ir] == '0'){
        ir++;
        if(a[ir] != '0') return {-1,-1};
    }
    return {il,ir};
}

int f2(int l, int r, vector<pair<int,int>> &seg){
    int po = 0, ko = (int)seg.size() - 1, sr;
    int ans = seg.size() - 2;
    while(po < ko){
        sr = (po + ko)/2;
        if(seg[sr].st < l){
            po = sr + 1;
        } else {
            ko = sr;
        }
    }
    // cout << po << " 1\n";
    ans -= po - 1;

    po = 0; ko = (int)seg.size() - 1;
    while(po < ko){
        sr = (po + ko)/2 + 1;
        if(seg[sr].nd <= r){
            po = sr;
        } else {
            ko = sr - 1;
        }
    }
    // cout << po << " 2\n";
    ans -= seg.size() - po - 2;
    return ans;
}

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    a = "#" + a + "#";
    b = "#" + b + "#";
    vector<int> pij(n + 1, 0);
    vector<pair<int,int>> seg0;
    seg0.push_back({-1,-1});
    pair<int,int> tmp, pfal = {-1,-1};
    for(int i = 1; i <= n; i++){
        pij[i] = pij[i - 1];
        if(a[i] == '1') pij[i]++;
        else {
            tmp = f1(i,a,b);
            if(tmp != pfal) seg0.push_back(tmp);
        }
    }

    seg0.push_back({n + 10, n + 10});

    // cout << seg0 << "\n";

    int tmp2;
    int q; cin >> q;
    int l,r;
    while(q--){
        cin >> l >> r;
        if(r - l + 1 <= 5){
            tmp2 = 0;
            for(int i = l; i <= r; i++){
                if(a[i] == '0'){
                    tmp = f1(i,a,b);
                    if(l <= tmp.st && tmp.nd <= r) tmp2++;
                }
            }
        } else {
            tmp2 = f2(l,r,seg0);
        }
        cout << pij[r] - pij[l - 1] + tmp2 << "\n";
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
