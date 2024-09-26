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

bool check(vector<ll> &ai, int mini){
    ll zapas = 0;
    for(int i = 0; i < ai.size(); i++){
        if(ai[i] >= mini){
            zapas += ai[i] - mini;
            continue;
        }
        if(mini - ai[i] > zapas){
            return false;
        }
        zapas -= mini - ai[i];
    }
    return true;
}

ll mindif(vector<int> &ai, int mini){
    // ll maxi = ai[i];
    // ll idn = 1;
    vector<int> debt;
    int n = ai.size();
    for(int i = n - 1; i >= 0; i--){
        if(ai[i] < mini){
            debt.push_back(i);
            continue;
        }
        while(ai[i] > mini && !debt.empty()){
            if(ai[i] - mini >= mini - ai[debt.back()]){
                ai[i] -= mini - ai[debt.back()];
                ai[debt.back()] = mini;
                debt.pop_back();
            } else {
                ai[debt.back()] += ai[i] - mini;
                ai[i] = mini;
            }
        }
    }

    vector<ll> suf(n + 1, 0);
    for(int i = n - 1; i >= 0; i--){
        suf[i] = suf[i + 1] + ai[i];
    }
    ll maxi = 0;
    // ll mini = 1e9;
    for(int i = n - 1; i >= 0; i--){
        maxi = max(maxi, (suf[i] + n - i - 1) / (n - i));
        // if( <<< (suf[i] + n - i - 1) / (n - i))
    }
    return maxi - mini;
}

void solve(){
    ll n; cin >> n;
    vector<ll> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    
    ll po = 1, ko = 1e12, sr;
    while(po < ko){
        sr = (po + ko)/2 + 1;
        if(check(ai, sr)){
            po = sr;
        } else {
            ko = sr - 1;
        }
    }

    cout << mindif(ai,po) << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
