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

int sf(set<int> &s){
    if(s.size() == 0) return 1e9;
    auto it = s.begin();
    return (*it);
}
int ss(set<int> &s){
    if(s.size() < 2) return 1e9;
    auto it = s.begin();
    it++;
    return (*it);
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    set<int> sa;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sa.insert(a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int maxi = 0;
    int al = 0, ar = n - 1;

    for(int i = 0; i < n; i++){
        cout << sa << "\n";
        cout << maxi << "\n";
        if(sf(sa) > b[i] || (min(ss(sa), maxi) > b[i])){
            cout << n - i << " ---\n";
            return;
        }
        while(a[al] > b[i] && al < ar){
            sa.erase(a[al]);
            al++;
        }
        sa.erase(a[ar]);
        maxi = max(maxi, a[ar]);
        ar--;
    }
    cout << "0\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
