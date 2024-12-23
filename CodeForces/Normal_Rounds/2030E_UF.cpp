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

int mod = 998244353;

int fast_pow(int a, int k){
    if(k == 1) return a;
    int tmp = fast_pow(a, k/2);
    int ans = ((ll)tmp * tmp) % mod;
    if(k&1) ans = ((ll)ans * a) % mod;
    return ans;
}

int revmod(int a){
    return fast_pow(a, mod - 2);
}

void solve(){
    cout << fast_pow(4, 5) << endl;
    int n; cin >> n;
    vector<int> hmn(n + 1,0);
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        hmn[tmp]++;
    }
    vector<vector<int>> val(n + 1);
    vector<vector<int>> poss(n + 1);

    val[0].assign(hmn[0] + 2, 0);
    poss[0].assign(hmn[0] + 2, 0);
    int newt = 1;
    val[0][0] = 0;
    poss[0][0] = 1;
    for(int i = 1; i <= hmn[0]; i++){
        newt *= ((ll)(hmn[0] - i + 1) * revmod(i)) % mod;
        newt %= mod;
        // cout << newt << "\n";
        val[0][i] = i * newt;
        poss[0][i] = newt;
    }
    // cout << val[0] << "\n";
    for(int i = 1; i <= n; i++){
        
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
