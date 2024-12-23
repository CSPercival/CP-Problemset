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
 
vector<pair<int,int>> edges;

void find_edge(int inv){
    int sev = 1;
    int ans = 1;
    while(ans != inv){
        sev = ans;
        cout << "? " << inv << " " << sev << "\n";
        cout.flush();
        cin >> ans;
    }
    edges.push_back({inv,sev});
    return;
}

void solve(){
    int n;
    cin >> n;
    edges.clear();
    for(int i = 2; i <= n; i++){
        find_edge(i);
    }
    cout << "! ";
    for(auto e : edges){
        cout << e.st << " " << e.nd << " ";
    }
    cout << "\n";
    cout.flush();
}

 
int32_t main(){
    // BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
