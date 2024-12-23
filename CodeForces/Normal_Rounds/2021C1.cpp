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
    int n, m ,q; cin >> n >> m >> q;
    vector<int> ai(n);
    vector<int> bi(m);
    vector<int> start(n + 1);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    for(int i = 0; i < m; i++){
        cin >> bi[i];
        if(start[bi[i]] == 0){
            start[bi[i]] = i + 1;
        }
    }

    // cout << start << "\n";
    int last_idx = -1;
    for(int i = 0; i < n; i++){
        // cout << start[ai[i]] << "\n";
        if(start[ai[i]] == 0){
            last_idx = 0;
            continue;
        }
        if(start[ai[i]] < last_idx || (last_idx == 0 && start[ai[i]] > 0)){
            cout << "TIDAK\n";
            return;
        } else {
            last_idx = start[ai[i]];
        }
    }
    cout << "YA\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
