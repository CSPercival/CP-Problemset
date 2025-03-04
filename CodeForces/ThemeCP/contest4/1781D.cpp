//Rating 1800
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

int ans = 1;
ll bestx = 0;

ll arit(ll a1, ll k){
    return (a1 + (k - 1)) * k;
}

ll ca1(ll sum, ll k){
    return (sum / k) - (k - 1);
}

bool sq(ll a){
    ll tmp = sqrt(a);
    return (tmp * tmp == a);
}

void check(int d, int i, int j, vector<int> &ai){
    // cout << d << " " << i << " " << j << "\n";
    ll diff = ai[j] - ai[i];
    ll a = ca1(diff, d);
    // cout << a << " a\n";
    if(a < 0 || a % 2 == 0) return;
    ll x = arit(1,a/2) - ai[i];
    // cout << x << " x\n";
    if(x < 0) return;
    // cout << d << " " << i << " " << j << " " << x << " " << a << "\n";
    int tans = 2;
    for(int ii = j + 1; ii < ai.size(); ii++){
        if(sq(x + ai[ii])){
            // cout << ii << "\n";
            tans++;
        }
    }
    if(ans < tans){     
        ans = tans;
        bestx = x;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    ll diff;
    ans = 1;
    bestx = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            diff = ai[j] - ai[i];
            for(int d = 1; d * d <= diff; d++){
                if(diff % d == 0){
                    check(d, i, j, ai);
                    check(diff/d, i , j, ai);
                }
            }
        }
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
