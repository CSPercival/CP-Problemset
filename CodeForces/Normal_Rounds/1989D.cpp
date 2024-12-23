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

int infi = 2e9;

void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> weap(n);
    vector<int> lost(1e6 + 1,infi);
    for(int i = 0; i < n; i++){
        cin >> weap[i].st;
    }
    for(int i = 0; i < n; i++){
        cin >> weap[i].nd;
    }

    int tlos;
    for(int i = 0; i < n; i++){
        tlos = weap[i].st - weap[i].nd;
        lost[tlos] = min(lost[tlos],weap[i].st);
    }

    vector<pair<int,int>> bestw;
    for(int i = 0; i <= 1e6; i++){
        if(lost[i] == infi) continue;
        bestw.push_back({lost[i],lost[i] - i});
    }
    for(int i = 1; i < bestw.size(); i++){
        if(bestw[i].st > bestw[i - 1].st){
            bestw[i] = bestw[i - 1];
        }
    }

    // bestw.push_back({0,0});
    // cout << bestw << "\n";

    vector<int> ans(1e6 + 1,0);
    int ptr = bestw.size() - 1;
    for(int i = 1; i <= 1e6; i++){
        while(ptr >= 0 && bestw[ptr].st <= i) ptr--;
        ptr = min(ptr + 1, (int)bestw.size() - 1);
        ans[i] = ans[i - 1];
        if(i < bestw[ptr].st) continue;
        ans[i] = max(ans[i], ans[i - bestw[ptr].st + bestw[ptr].nd] + 2);
    }
    
    // cout << ans << "\n";

    ll all_ans = 0, tans;
    int ci;
    int bbw = bestw[0].st - bestw[0].nd;
    for(int i = 0; i < m; i++){
        cin >> ci;
        tans = 0;
        if(ci > 1e6){
            ci -= 1e6;
            tans += 2 * (ci/bbw);
            ci %= bbw;
            ci += 1e6;
            tans += 2;
            ci -= bbw;
        }
        tans += ans[ci];
        all_ans += tans;
    }
    cout << all_ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
