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

int ai[300010];
vector<int> nimber(1e7,-1);

void solve(){
    int n; cin >> n;
    int tmp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        ans ^= nimber[tmp];
    }
    if(ans){
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

 
int32_t main(){
    BOOST;

    nimber[0] = 0;
    nimber[1] = 1;
    int nim_ctr = -1;
    for(int i = 2; i <= 1e7; i++){
        if(i == 3) nim_ctr++;
        if(nimber[i] == -1){
            nim_ctr++;
            for(int j = i; j <= 1e7; j += i){
                if(nimber[j] == -1) nimber[j] = nim_ctr;
            }
        }
    }
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
