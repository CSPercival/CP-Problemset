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


ll check(vector<int> &ai, int d){
    if(d == 0) return 0;
    ll ans = 0;
    for(int i = 0; i < ai.size(); i++){
        if(ai[i] == i + 1){
            ans++;
        }
    }
    d--;
    ans += d/2;
    return ans;
}

void update(vector<int> &ai, int bi){
    for(int i = 0; i < min((int)ai.size(), bi); i++){
        ai[i]++;
    }
}

void solve(){
    int n, k, d; cin >> n >> k >> d;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    vector<int> vk(k);
    for(int i = 0; i < k; i++){
        cin >> vk[i];
    }

    ll ans = 0;
    for(int i = 0; i <= min(2 * n, d); i++){
        ans = max(ans, check(ai, d - i));
        update(ai, vk[i % k]);
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
