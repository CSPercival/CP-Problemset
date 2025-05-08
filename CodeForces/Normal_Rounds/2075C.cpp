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


void solve(){
    int n, m; cin >> n >> m;
    vector<int> ai;
    ll tmp;
    int numaxi = 0;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        if(tmp == n){
            numaxi++;
            i--;
            m--;
        } else {
            ai.push_back(tmp);
        }
        // cin >> ai[i];
    }
    sort(all(ai), greater<int>());
    ai.push_back(0);
    ll ans = 0;
    ll last_bit = 0;
    int idx = 0;
    for(int i = m - 1; i >= 0; i--){
        last_bit += idx * (ai[i] - ai[i + 1]);
        while(idx < m && ai[idx] + ai[i] >= n){
            last_bit += (ai[idx] + ai[i] - n + 1);
            idx++;
        }
        ans += last_bit;
    }
    ll tmp2 = 0;
    for(int i = 0; i < m; i++){
        tmp = (ai[i] + ai[i] - n + 1);
        ans -= max(0LL, tmp);

        tmp2 += ai[i];
        // tmp2 += max(n - 1, (ai[i] + 1));
    }
    ans += (numaxi * tmp2) * 2;
    ans += numaxi * (numaxi - 1) * (n - 1);
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
