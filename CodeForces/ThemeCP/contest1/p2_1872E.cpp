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


void solve(){
    int n; cin >> n;
    vector<int> ai(n + 1);
    vector<int> pxor(n + 1, 0);
    for(int i = 1; i <= n; i++){ 
        cin >> ai[i];
        pxor[i] = (pxor[i - 1] ^ ai[i]);
    }
    string s; cin >> s;
    int ans0 = 0;
    int allxor = pxor[n];
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            ans0 ^= ai[i + 1];
        }
    }

    int q; cin >> q;
    int tp;
    int l,r,g;
    while(q--){
        cin >> tp;
        if(tp == 1){
            cin >> l >> r;
            ans0 ^= (pxor[r] ^ pxor[l - 1]);
        } else {
            cin >> g;
            if(g == 0){
                cout << ans0 << " ";
            } else {
                cout << (ans0 ^ allxor) << " ";
            }
        }
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
