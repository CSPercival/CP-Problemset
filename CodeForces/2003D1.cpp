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
 
int li[200010];
vector<int> aij[200010];

ll f1(long long x){
    return x * (x + 1) / 2;
}

void solve(){
    int n; cin >> n;
    ll m; cin >> m;
    int ctr = 0;
    ll ansik, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> li[i];
        aij[i].resize(li[i]);
        for(int j = 0; j < li[i]; j++){
            cin >> aij[i][j]; 
        }
        sort(all(aij[i]));
        ctr = 2;
        ansik = 0;
        for(int j = 0; j < li[i] && ctr > 0; j++){
            if(ansik == aij[i][j]) ansik++;
            else if(ansik > aij[i][j]) continue;
            else {
                ansik++;
                j--;
                ctr--;
            }
        }
        ansik += ctr - 1;
        ans = max(ans,ansik);
    }
    cout << f1(m) - f1(min(ans,m)) + (min(ans,m) + 1) * ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
