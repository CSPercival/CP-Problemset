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


void solve(){
    int n; cin >> n;
    int px,py,qx,qy; cin >> px >> py >> qx >>qy;
    vector<int> ai(n);
    int sum = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> ai[i];
        sum += ai[i];
        maxi = max(maxi, ai[i]);
    }
    int min_dist = max(0LL, maxi - (sum - maxi));
    // int lim = sum/2 + 10;
    // vector<int> rest(lim + 1, 0);
    // rest[0] = 1;
    // for(int i = 0; i < n; i++){
    //     for(int j = lim; j >= 0; j--){
    //         if(rest[j]){
    //             rest[min(j + ai[i], lim)] = 1;
    //         }
    //     }
    // }
    // int min_dist = -1;
    // for(int i = sum/2; i >= 0; i--){
    //     if(rest[i]){
    //         min_dist = (sum - (2 * i));
    //         break;
    //     }
    // }
    ll a = abs(px - qx);
    ll b = abs(py - qy);
    ll c2 = a * a + b * b; 
    ll min_dist2 = min_dist;
    ll max_dist2 = sum;
    min_dist2 *= min_dist2;
    max_dist2 *= max_dist2;
    if(min_dist2 <= c2 && c2 <= max_dist2){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
