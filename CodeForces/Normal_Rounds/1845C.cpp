//Rating 1400
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
    string s; cin >> s;
    int m; cin >> m;
    string l, r; cin >> l >> r;

    vector<int> last(10, -1);
    int fn = 0;
    int ptr1 = 0;
    for(int i = 0; i < m; i++){
        fn = 0;
        while(fn != r[i] - l[i] + 1 && ptr1 < s.size()){
            if(s[ptr1] >= l[i] && s[ptr1] <= r[i]){
                if(last[s[ptr1] - '0'] != i){
                    last[s[ptr1] - '0'] = i;
                    fn++;
                }
            }
            ptr1++;
        }
        if(ptr1 == s.size() && fn != r[i] - l[i] + 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
