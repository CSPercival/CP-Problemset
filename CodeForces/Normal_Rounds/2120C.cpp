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
    ll n; cin >> n;
    ll m; cin >> m;
    if(n * (n + 1)/2 < m || n > m){
        cout << "-1\n";
        return;
    }
    ll curr = n * (n + 1)/2;
    ll root = n;
    while(curr - (root - 1) > m){
        root--;
        curr -= root; 
    }
    int fix = curr - m;
    vector<int> ans;
    int currv = root - 1;
    for(int i = 0; i < fix; i++){
        ans.push_back(currv);
        currv--;
    }
    ans.push_back(root);
    for(int i = root - fix - 1; i >= 1; i--){
        ans.push_back(i);
    }
    for(int i = n; i > root;i--){
        ans.push_back(i);
    }
    // cout << ans << "\n";
    cout << ans[0] << "\n";
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i - 1] << " " << ans[i] << "\n";
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
