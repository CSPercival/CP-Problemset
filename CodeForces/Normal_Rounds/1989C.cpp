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
    vector<pair<int,int>> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i].st;
    }
    for(int i = 0; i < n; i++){
        cin >> ai[i].nd;
    }
    vector<int> same(3,0);
    int rat1 = 0, rat2 = 0;
    for(int i = 0 ; i < n; i++){
        if(ai[i].st == ai[i].nd){
            same[ai[i].st + 1]++;
        } else {
            if(ai[i].st < ai[i].nd){
                rat2 += ai[i].nd;
            } else {
                rat1 += ai[i].st;
            }
        }
    }
    if(rat1 < rat2){
        swap(rat1,rat2);
    }
    if(rat1 - same[0] >= rat2){
        rat1 -= same[0];
        same[0] = 0;
    } else {
        same[0] -= (rat1 - rat2);
        rat1 = rat2;
        rat1 -= same[0]/2;
        rat2 -= (same[0] + 1)/2;
    }
    if(rat2 + same[2] <= rat1){
        rat2 += same[2];
        same[2] = 0;
    } else {
        same[2] -= (rat1 - rat2);
        rat2 = rat1;
        rat1 += (same[2] + 1)/2;
        rat2 += (same[2])/2;
    }
    cout << rat2 << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
