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

bool check(vector<int> &a){
    int n = 6;
    // for(int i = 0; i <= 1; i++){
    //     for(int j = 2; j <= 3; j++){
    //         for(int k = 4; k <= 5; k++){
    //             if(a[j] == a[k]){
    //                 if(a[j] == a[i]){
    //                     if(a[i^1] + a[j^1] + a[k^1] == a[i])
    //                         return true;
    //                 }

    //                 if(a[i] == a[j^1] + a[k^1]){
    //                     if(a[i] == a[i^1] + a[j])
    //                         return true;
    //                 }
    //             }
    //         }
    //     }
    // }
    if(a[0] >= a[1]){
        if(a[2] == a[4] && a[0] == a[2]){
            if(a[1] + a[3] + a[5] == a[0]) return true;
        }
        if(a[3] == a[5]){
            if(a[0] == a[2] + a[4] && a[0] == a[1] + a[3]) return true;
        }
    } 
    
    
    
    if(a[0] <= a[1]) {
        if(a[3] == a[5] && a[1] == a[3]){
            if(a[0] + a[2] + a[4] == a[1]) return true;
        }
        if(a[2] == a[4]){
            if(a[1] == a[3] + a[5] && a[1] == a[0] + a[2]) return true;
        }
    }
    return false;
}

void solve(){
    int n = 6; //cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // for(int i = 0; i < n; i+=2){
    //     if(a[i] < a[i + 1]) swap(a[i],a[i + 1]);
    // }
    // for(int i = 2; i <= 3; i++){
    //     for(int )
    // }

    
    // int l1, b1, l2, b2, l3, b3;
    // cin >> 
    // vector<int> ai
    if(check(a)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
