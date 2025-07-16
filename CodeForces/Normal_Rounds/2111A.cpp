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
    int n; 
    cin >> n;
    // vector<int> a(n);
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    vector<int> a(3,0);
    // priority_queue<int> pq(vector<int>, greater<int>)
    int ans = 0;
    while(min({a[0],a[1],a[2]}) < n){
        int mini = min({a[0],a[1],a[2]}), tmini = 1e9;
        for(int i = 0; i < 3; i++){
            if(a[i] == mini){
                for(int j = 0; j < 3; j++){
                    if(i == j) continue;
                    tmini = min(tmini, a[j]);
                }
                a[i] = tmini * 2 + 1;
                ans++;
                break;
            }
        }       
    }
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
