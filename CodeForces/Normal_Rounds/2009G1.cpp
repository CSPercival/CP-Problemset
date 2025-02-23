//Rating 1900
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


void solve(){
    int n, k, q; cin >> n >> k >> q;
    
    vector<int> ai(n + 1);
    for(int i = 1 ; i <= n; i++){
        cin >> ai[i];
    }
    int offset = n + 10;
    ai[0] = offset;
    vector<int> bal(2 * offset + 20, 0);
    vector<int> ans(n + 1, 0);
    multiset<int> fmax;
    // int maksi = 0;
    int cbal;
    // cout << "gitt" << endl;
    for(int i = 0; i < k; i++){
        cbal = offset + ai[i] - i;
        // cout << cbal - offset << " +\n";
        if(bal[cbal] != 0)
            fmax.erase(fmax.find(bal[cbal]));
        bal[cbal]++;
        fmax.insert(bal[cbal]);
    }
    for(int i = k; i <= n; i++){
        cbal = offset + ai[i] - i;
        // cout << cbal - offset << " +2\n";
        if(bal[cbal] != 0)
            fmax.erase(fmax.find(bal[cbal]));
        bal[cbal]++;
        fmax.insert(bal[cbal]);

        cbal = offset + ai[i - k] - (i - k);
        // cout << cbal - offset << " -\n";

        fmax.erase(fmax.find(bal[cbal]));
        bal[cbal]--;
        if(bal[cbal] != 0)
            fmax.insert(bal[cbal]);

        ans[i] = (*(fmax.rbegin()));
    }

    int l, r;
    while(q--){
        cin >> l >> r;
        cout << k - ans[r] << "\n";
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
