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
    int x; cin >> x;
    vector<int> ai(n);
    vector<vector<int>> r(min(n + 10, x));
    for(int i = 0; i < n; i++){
        cin >> ai[i];
        if(ai[i] % x < n + 10){
            r[ai[i] % x].push_back(ai[i]);
        }
    }
    // int amult = 1e9;
    int aval = 2e9;
    // cout << r << "\n";
    for(int i = 0; i < min(n + 10, x); i++){
        // if(r[i].empty()){
        //     cout << i << "\n";
        //     return;
        // }
        sort(all(r[i]));
        // cout << r[i] << "\n";
        int val = i;
        // int mul = 0;
        int zap = 0;
        for(int j = 0; j < r[i].size(); j++){
            if(r[i][j] == val){
                // mul++;
                val += x;
                continue;
            }
            if(r[i][j] < val){
                zap++;
                continue;
            }
            if(r[i][j] > val){
                if(zap == 0){
                    break;
                } else {
                    zap--;
                    val += x;
                    j--;
                }
                continue;
            }
        }
        val += zap * x;
        // mul += zap;
        if(aval > val){
            // amult = mul;
            aval = val;
        }
    }
    cout << aval << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
