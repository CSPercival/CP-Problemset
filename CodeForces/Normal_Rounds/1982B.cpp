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
 
bool phase1(int *x, int  *y, int *k){
    int tmp1 = (*y) - ((*x) % (*y));
    if(tmp1 > (*k)){
        (*x) += (*k);
        (*k) = 0;
        return false;
    }
    (*k) -= tmp1;
    (*x) += tmp1;
    while((*x) % (*y) == 0){
        (*x) /= (*y);
    }
    return true;
}
 
void solve(){
    int x,k,y; cin >> x >> y >> k;
    while(phase1(&x,&y,&k) && x != 1)
 
    if(k == 0){
        cout << x << "\n";
        return;
    }
 
    k %= (y - 1);
    phase1(&x,&y,&k);
    cout << x << "\n";
 
}
 
 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}