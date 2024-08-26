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
 
int il[30];

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i <= 'z' - 'a'; i++) il[i] = 0;
    for(int i = 0; i < s.size(); i++){
        il[s[i] - 'a']++;
    }
    string ans = "";
    int last = -1;
    int best_idx = 0;
    int maxi = 0;
    for(int i = 0; i < s.size(); i++){
        maxi = 0;
        for(int j = 0; j <= 'z' - 'a'; j++){
            if(last == j) continue;
            if(maxi < il[j]){
                maxi = il[j];
                best_idx = j;
            }
        }
        ans.push_back(best_idx + 'a');
        last = best_idx;
        il[last]--;
    }
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
