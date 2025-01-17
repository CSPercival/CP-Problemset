#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
#define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

int ans(int a, int b, int c){
    return (a^b) + (a^c) + (b^c);
}

void solve(){
    int l, r; cin >> l >> r;
    int a = 0, b = 0, c = 0;
    int pot = 1;
    while(pot <= r) pot <<= 1;
    pot >>= 1;

    int shift = 0;
    while((r & pot) == (l & pot)){
        shift += (pot & r);
        pot >>= 1;
    }
    // cout << shift << "\n";
    // r -= shift;
    // l -= shift;
    a = pot + shift;
    b = pot + shift - 1;
    c = pot + shift - 2;
    if(c < l) c += 3;
    cout << a << " " << b << " " << c << "\n"; 
}

 
int32_t main(){
    BOOST;

    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
