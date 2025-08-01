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
    int n; 
    cin >> n;
    vector<pair<pair<int,int>, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].st.st >> a[i].st.nd;
        a[i].st.nd *= -1;
        a[i].nd = i;
    }
    sort(all(a));
    vector<pair<pair<int,int>, int>> mstack;
    for(int i = 0; i < n; i++){
        if(mstack.empty()){
            mstack.push_back(a[i]);
        } else {
            if(mstack.back().st.nd > a[i].st.nd){
                mstack.push_back(a[i]);
            }
        }
    }
    cout << mstack.size() << "\n";
    for(auto i : mstack){
        cout << i.nd + 1 << " ";
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
