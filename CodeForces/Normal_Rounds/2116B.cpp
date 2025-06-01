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

int mod = 998244353;
int tpow[100010];

void solve(){
    int n; cin >> n;
    vector<int> p(n + 1, 0);
    vector<int> q(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }

    vector<pair<int,int>> r(n);
    int midxp = n, midxq = n;
    for(int i = 0; i < n; i++){
        if(p[i] >= p[midxp]) midxp = i;
        if(q[i] >= q[midxq]) midxq = i;
        if(p[midxp] == q[midxq]){
            if(q[i - midxp] > p[i - midxq]){
                r[i] = {p[midxp], q[i - midxp]};
            } else {
                r[i] = {p[i - midxq], q[midxq]};
            }
        } else {
            if(p[midxp] > q[midxq]){
                r[i] = {p[midxp], q[i - midxp]};
            } else {
                r[i] = {p[i - midxq], q[midxq]};
            }
        }
    }
    for(auto i : r){
        cout << (tpow[i.st] + tpow[i.nd]) % mod << " ";
    }
    cout << '\n';
}

 
int32_t main(){
    BOOST;
    tpow[0] = 1;
    for(int i = 1; i <= 1e5; i++){
        tpow[i] = (tpow[i - 1] * 2) % mod;
    }
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
