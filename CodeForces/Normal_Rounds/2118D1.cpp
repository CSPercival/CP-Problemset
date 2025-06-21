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

bool check(ll del1, ll del2, ll k, ll dist){
    if((del1 + dist) % k == del2) return true;
    return false;
}

vector<int> pred[1010];
bool on_cycle[1010];

void find_cycle(int idx){
    on_cycle[idx] = 0;
    for(int i : pred[idx]){
        find_cycle(i);
    }
}


void solve(){
    int n, k, q; cin >> n >> k;
    vector<pair<ll,ll>> traf(n);    //pos,delay
    for(int i = 0; i < n; i++) cin >> traf[i].st;
    for(int i = 0; i < n; i++) cin >> traf[i].nd;

    vector<int> succ(2 * n, -1);    // nastepny w lewo i prawo(i + n)
    // vector<bool> on_cycle(2 * n, 1);

    for(int i = 0; i < 2 * n; i++){
        pred[i].clear();
        on_cycle[i] = true;
    }

    for(int i = 0; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(check(traf[i].nd, traf[j].nd, k, traf[i].st - traf[j].st)){
                succ[i] = j + n;
                pred[j + n].push_back(i);
                break;
            }
        }
        for(int j = i + 1; j < n; j++){
            if(check(traf[i].nd, traf[j].nd, k, traf[j].st - traf[i].st)){
                succ[i + n] = j;
                pred[j].push_back(i + n);
                break;
            }
        }
    }

    for(int i = 0; i < 2 * n; i++){
        if(succ[i] == -1){
            find_cycle(i);
        }
    }

    ll spos;
    cin >> q;
    // cout << traf << "\n";
    while(q--){
        cin >> spos;
        pair<ll,ll> tmpp = {spos, -1};
        auto idx = upper_bound(traf.begin(), traf.end(), tmpp) - traf.begin();
        int gidx = -1;
        // cout << idx << " idx\n";
        for(int i = idx; i < n; i++){
            if(check(0, traf[i].nd, k, traf[i].st - spos)){
                gidx = i;
                break;
            }
        }
        // cout << gidx << " gidx\n";
        if(gidx == -1 || !on_cycle[gidx]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
        // cout << "\n";
    }
    return 0;
}
