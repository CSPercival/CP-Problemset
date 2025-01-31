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

int n;
vector<int> ai;
vector<pair<ll,int>> hmb(2 * n + 10, {0, 0});
int shift, lastl, lastr, last_idx, last_balans, start_idx;

void update_hmb(int idx, int val, int color){
    if(hmb[idx + shift].second != color){
        hmb[idx + shift] = {0, color};
    }
    hmb[idx + shift].first += val;
}

void update_bal(int l, int r, int color){
    while(last_idx < lastr && last_idx < lastl){
        if(last_idx == start_idx){
            update_hmb(0, 1, color);
            last_idx++;
            continue;
        }
        if(ai[last_idx] <= l){
            last_balans++;
        }
        if(ai[last_idx] >= r){
            last_balans--;
        }
        update_hmb(last_balans, 1, color);
        last_idx++;
        // if(hmb[last_balans + shift].second != color){
        //     hmb[last_balans + shift] = {0,color};
        //     // if(!last_balans){
        //     //     hmb[shift].first++;
        //     // }
        // }
        // hmb[last_balans + shift].first++;
    }
}

ll f1(int l, int r){
    lastl = 0;
    lastr = 0;
    last_idx = 0;
    last_balans = 0;
    shift = n + 2;
    int color = 0;
    ll ans = 0;
    int balans = 0;
    start_idx = 0;
    hmb.assign(2 * n + 10, {0, 0});
    for(int i = 1; i <= n; i++){
        if(ai[i] <= l){
            balans++;
            if(ai[i] == l){
                lastl = i;
                update_bal(l, r, color);
            }
            update_hmb(balans, 0, color);
            // if(hmb[shift + balans].second != color){
            //     hmb[shift + balans] = {0,color};
            // }
            ans += hmb[shift + balans].first;
            continue;
        }
        if(r <= ai[i]){
            balans--;
            if(r == ai[i]){
                lastr = i;
                update_bal(l, r, color);
            }
            // if(hmb[shift + balans].second != color){
            //     hmb[shift + balans] = {0,color};
            // }
            update_hmb(balans, 0, color);
            ans += hmb[shift + balans].first;
            continue;
        }
        last_idx = i;
        lastl = i;
        lastr = i;
        balans = 0;
        last_balans = 0;
        start_idx = i;
        color++;
    }
    return ans;
}

void solve(){
    cin >> n;
    ai.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    ll ans = (ll)n * (n + 1)/2;
    // cout << "0 - 0 " << ans << "\n";
    for(int i = 1; i <= 10; i++){
        for(int j = i + 1; j <= 10; j++){
            // cout << i << " - " << j << "  " << ans << "\n";
            ans -= f1(i,j);
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
