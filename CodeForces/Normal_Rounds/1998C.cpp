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

int infi = 2e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int,int>> ai(n);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> ai[i].st;
        maxi = max(maxi,ai[i].st);
    }
    int bi = -1;
    int max0 = maxi;
    maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> ai[i].nd;
        if(ai[i].nd && ai[i].st > maxi){
            bi = i;
        }
    }
    if(bi == -1){

    }
    int max1 = ai[bi].st;
    ai[bi].st = infi;
    sort(all(ai));
    ai.pop_back();
    // n--;
    vector<int> przedmed, zamed, slup;
    for(int i = 0 ; i < n/2 - 1; i++){
        if(ai[i].nd){
            przedmed.push_back(ai[i].st);
        }
    }
    for(int i = n/2 - 1; i < n - 1; i++){
        if(ai[i].nd){
            zamed.push_back(ai[i].st);
        } else {
            slup.push_back(ai[i].st);
        }
    }
    ll ans = max(max1 + k, max0) + ai[n/2 - 1];
    while(true){
        if(slup.size() > 0){

        } else {
            
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
