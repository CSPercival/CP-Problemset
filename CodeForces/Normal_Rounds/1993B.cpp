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
    vector<int> ai(n);
    int maxi = -1;
    int maxi2 = 0;
    int ip = 0;
    for(int i = 0; i < n; i++){
        cin >> ai[i];
        if(ai[i]&1 && ai[i] > maxi) maxi = ai[i];
        if(!(ai[i]&1)){
            ip++;
            maxi2 = max(maxi2,ai[i]);
        }
    }
    if(ip == 0 || ip == n){
        cout << "0\n";
        return;
    }

    sort(all(ai));

    // for(int i = 0; i < n; i++){
    //     if(!(ai[i]&1)){
    //         if(ai[i] < maxi && ai[i] + maxi > maxi2){
    //             cout << ip << "\n";
    //             return;
    //         }
    //     }
    // }
    // cout << ip + 1 << "\n";

    sort(all(ai));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(ai[i]&1) continue;
        while(ai[i] > maxi){
            maxi += ai[i];
            ans++;
        }
        maxi += ai[i];
        ans++;
    }
    cout << min(ans, ip + 1) << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
