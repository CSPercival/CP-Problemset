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
/*
Wydaje sie ze to taki sortujemy lany
\
 \_
   \___
       \__

       A potem robimy takie cos ze sukcesywnie zmniejszamy z lewej i przenosimy na prawo
       trzeba tylko handlowac takie cos, ze lewy fragment zmniejsza sie tylko w polowie (analogicznie prawy)
        Bo nie zawsze fragmenty o takiej samej wysokosci(prefiks i sufiks) sa tak samo dlugie
        To jakis przedzial przedzial z minimum i set i wyszukiwaniem nastepnej wielkosci po x
       */
struct SegTree{
    vector<int> t;
    vector<int> p;
    int n;
    int shift = 1;
    SegTree(int in_n, vector<int> ai){
        shift = 1;
        n = in_n;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        p.assign(2 * shift, -1);
        for(int i = 0; i < n; i++){
            t[i + shift] = ai[i];
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = min(t[i << 1], t[(i << 1) + 1]);
        }
    }

    void set_val(int l, int r, int val){
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l&1){
                t[l] = val;
                p[l] = val;
            }
        }
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a), greater<int>());
    // cout << lanes << "\n";

    int maxl = a[0], minl = a.back();
    int ptrl = 0, ptrr = n - 1, ctrr = 1, ctrl = 1;
    int swinum = 0;
    while(maxl - minl > k){
        while(a[ptrl + 1] == maxl){
            ptrl++;
            ctrl++;
        }
        while(a[ptrr - 1] == minl){
            ptrr++;
            ctrr++;
        }
        if(ctrl == ctrr){
            int lchange = min(a[ptrl] - a[ptrl + 1], a[ptrr - 1] - a[ptrr]);
            maxl -= lchange;
            minl += lchange;
            swinum += ctrl * lchange;
            continue;
        }
        if(ctrl < ctrr){

            continue;
        }
        if(ctrl > ctrr){

            continue;
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
