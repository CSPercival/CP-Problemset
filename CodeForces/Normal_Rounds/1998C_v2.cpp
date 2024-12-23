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

int infi = 2e9 + 7;

bool check(vector<pair<int,int>>& ai, int k, int med){
    ll ctr = 0;
    ll cost = 0;
    for(int i = ai.size() - 1; i >= 0 && ctr < ai.size()/2 + 1; i--){
        if(ai[i].st >= med){
            ctr++;
            continue;
        }
        if(ai[i].nd){
            cost += med - ai[i].st;
            ctr++;
        }
    }
    if(ctr < ai.size()/2 + 1 || cost > k) return false;
    return true;
}

int f1(vector<pair<int,int>>& ai, int k){
    int po = 0, ko = infi, sr;
    while(po < ko){
        sr = (po + ko)/2 + 1;
        if(check(ai,k,sr)){
            po = sr;
        } else {
            ko = sr - 1;
        }
    }
    return po;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int,int>> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i].st;
    }
    for(int i = 0; i < n; i++){
        cin >> ai[i].nd;
    }
    sort(all(ai));

    int max1 = 0, bi = -1;
    for(int i = 0; i < n; i++){
        if(ai[i].nd && ai[i].st > max1) bi = max1;
    }
    if(bi == -1){
        cout << ai.back().st + ai[n/2 - 1].st << "\n";
        return;
    }
    pair<int,int> maxelem = ai.back();
    ai.pop_back();
    ll best_med = f1(ai,k);
    ll ans = best_med + maxelem.st;

    ai.push_back(maxelem);
    for(int i = ai.size() -1; i >= 0; i--){
        if(ai[i].nd){
            for(int j = i + 1; j < ai.size(); j++){
                swap(ai[j], ai[j - 1]);
            }
            break;
        }
    }
    ans = max(ans, ai.back().st + k + ai[n/2 - 1].st);
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
