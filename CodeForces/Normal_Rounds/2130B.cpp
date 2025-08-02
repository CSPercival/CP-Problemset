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
    int s; 
    cin >> n >> s;
    vector<int> a(n);
    ll sum = 0;
    vector<int> ic(10,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        ic[a[i]]++;
    }
    if(sum == s){
        cout << "-1\n";
        return;
    }
    if(sum < s && (s - sum) % 2 == 0){
        cout << "-1\n";
        return;
    }
    if(sum + 3 <= s && (s - sum - 3) % 2 == 0){
        cout << "-1\n";
        return;
    }
        while(ic[0]--) cout << "0 ";
        while(ic[2]--) cout << "2 ";
        while(ic[1]--) cout << "1 ";
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
