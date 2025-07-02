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

int pref[100010];

void solve(){
    // cout << "START ============================\n";
    int n; cin >> n;
    vector<int> a(n + 2);
    a[0] = -1;
    a[n + 1] = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int po,ko,sr;
    int k;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j < n; j++){
            // cout << ans << "\n";
            // cout << "i: " << i << "  j: " << j << "\n";
            po = j;
            ko = n;
            while(po + 1 < ko){
                sr = (po + ko)/2;
                if(a[i] + a[j] + a[sr] > a[n]){
                    ko = sr;
                } else {
                    po = sr;
                }
            }
            if(j == n - 1 && ko == n && a[i] + a[j] > a[ko]) ans++;
            if(ko == n) continue;
            k = ko;
            // cout << "k: " << k << "\n";


            po = k - 1;
            ko = n + 1;
            while(po + 1 < ko){
                sr = (po + ko)/2;
                if(a[i] + a[j] > a[sr]){
                    po = sr;
                } else {
                    ko = sr;
                }
            }
            // cout << po << " - " << k << "\n";
            if(po == k - 1) continue;
            ans += max(0, po - k + 1);
        }
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
