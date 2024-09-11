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
    int n,m; cin >> n >> m;
    vector<string> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // for(int j = 0; j < m; j++){
        //     cin >> a[i][j];
        //     cout << "wczytano " <<  i << " - " << j << endl;
        // }
    }
    // cout << a;
    // cout << endl;
    // cout << "ok1" << endl;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        // for(int j = 0; j < m; j++){
        //     cin >> b[i][j];
        //     cout << "wczytano " <<  i << " - " << j << endl;
        // }
    }
    // cout << "ok2" << endl;

    int rowa,rowb;
    for(int i = 0; i < n; i++){
        rowa = 0;
        rowb = 0;
        for(int j = 0; j < m; j++){
            rowa = (rowa + a[i][j] - '0') % 3;
            rowb = (rowb + b[i][j] - '0') % 3;
        }
        if(rowa != rowb){
            cout << "NO\n";
            // cout << "row " << i << "\n"; 
            return;
        }
    }
    for(int j = 0; j < m; j++){
        rowa = 0;
        rowb = 0;
        for(int i = 0; i < n; i++){
            rowa = (rowa + a[i][j] - '0') % 3;
            rowb = (rowb + b[i][j] - '0') % 3;
        }
        if(rowa != rowb){
            cout << "NO\n";
            // cout << "col " << j << "\n"; 
            return;
        }
    }
    cout << "YES\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
