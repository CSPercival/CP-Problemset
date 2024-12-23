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
    if(s.size() == 1){
        if(s[0] == 'a'){
            cout << 'b' << s << "\n";
        } else {
            cout << 'a' << s << "\n";
        }
        return;
    }
    int idx = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]){
            idx = i;
            break;
        }
    }
    for(int i = 0; i < idx; i++){
        cout << s[i];
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(i != s[idx - 1] && i != s[idx]){
            cout << i;
            break;
        }
    }
    for(int i = idx; i < s.size(); i++){
        cout << s[i];
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
