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

bool enough_space(int maxl, int minl, vector<int> &a){
    // int minl = maxl - k + 1;
    ll space = 0, driv = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] > maxl){
            driv += a[i] - maxl;
        }
        if(a[i] <= minl){
            space += minl - a[i];
        }
    }
    return driv <= space;
}

void solve(){
    ll sum1 = 0, sum2 = 0, sum15 = 0;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){ 
        cin >> a[i]; 
        sum1 += a[i];
    }
    sort(all(a), greater<int>());

    int po = 0, ko = a[0], sr;
    while(po + 1 < ko){
        sr = (po + ko) / 2;
        if(enough_space(sr, sr - k + 1, a)){
            ko = sr;
        } else {
            po = sr;
        }
    }

    int maxl = ko;

    po = 0, ko = maxl - k + 1;
    while(po + 1 < ko){
        sr = (po + ko) / 2;
        if(enough_space(maxl, sr, a)){
            ko = sr;
        } else {
            po = sr;
        }
    }

    int minl = ko;

    ll drivers = 0;
    ll swinum = 0;
    ll tmp;
    for(int i = 0; i < a.size(); i++){
        if(a[i] > maxl){
            drivers += a[i] - maxl;
            swinum += a[i] - maxl;
            a[i] = maxl;
        }
        if(a[i] < minl){
            tmp = min((ll)minl - a[i] - 1, drivers);
            a[i] += tmp;
            drivers -= tmp;
        }
    }
    for(int i = 0 ; i < a.size(); i++){
        if(a[i] < minl){
            tmp = min((ll)minl - a[i], drivers);
            a[i] += tmp;
            drivers -= tmp;
        }
        sum15 += a[i];
    }
    assert(drivers == 0);
    
    int ptr = n - 1;
    for(int i = 0; i < ptr; i++){
        if(a[i] >= a[ptr] + 1 + k){
            swinum++;
            a[i]--;
            a[ptr]++;
            if(a[ptr - 1] < a[ptr]){
                ptr--;
            } else {
                ptr = n - 1;
            }
            continue;
        }
        break;
    }
    ll ans = (ll)k * swinum;
    for(int i = 0; i < n; i++){
        ans += (ll)a[i] * (a[i] + 1)/2;
        sum2 += a[i];
    }
    assert(sum1 == sum2);
    cout << ans << '\n';
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
