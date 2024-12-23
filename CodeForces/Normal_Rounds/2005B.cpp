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
    int n, m, q; cin >> n >> m >> q;
    vector<int> tec(m);
    for(int i = 0; i < m; i++){
        cin >> tec[i];
    }
    tec.push_back(0);
    tec.push_back(n);
    sort(all(tec));
    // cout << tec;
    // cout << "\n";
    int x;
    while(q--){
        cin >> x;
        if(m == 1){
            if(x == tec[1]){
                cout << "0\n";
                continue;
            }
            if(x < tec[1]){
                cout << tec[1] - 1 << "\n";
            } else {
                cout << n - tec[1] << "\n";
            }
            continue;
        }
        int po = 0, ko = tec.size() - 2,sr;
        while(po < ko){
            sr = (po + ko)/2 + 1;
            if(tec[sr] <= x){
                po = sr;
            } else {
                ko = sr - 1;
            }
        }
        // cout << po << " " << tec[po] << " " << tec[po + 1] << "\n";
        if(po == 0){
            cout << tec[po + 1] - 1 << "\n";
            continue;
        }
        if(po == tec.size() - 2){
            cout << n - tec[po] << "\n";
            continue;
        }
        cout << (tec[po + 1] - tec[po])/2 << "\n";
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
