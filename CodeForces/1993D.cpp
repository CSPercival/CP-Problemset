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

bool check(int med, int k, vector<int>& ai){
    int n = ai.size();
    int d = n % k;
    if(!d) d += n;
    vector<int> r;
    for(int i = 0; i < n; i++){
        if(ai[i] >= med){
            r.push_back(i % k);
        }
    }
    int ilo = d/2 + 1;
    if(r.size() < ilo) return false;
    
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    int po = 0, ko = 1e9 + 7, sr;
    while(po < ko){
        sr = (po + ko) / 2 + 1;
        if(check(sr,k,ai)){
            po = sr;
        } else {
            ko = sr - 1;
        }
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
