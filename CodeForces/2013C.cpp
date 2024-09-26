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

int n;

int ask(string t){
    assert(t.size() <= n);
    cout << "? " << t << "\n";
    cout.flush();

    int ans;
    cin >> ans;
    return ans;
}

void guess(string t){
    cout << "! " << t << "\n";
    cout.flush();
}

void solve(){
    cin >> n;
    string ans = "";
    for(int i = 0; i < n; i++){
        ans.push_back('1');
        if(ask(ans)) continue;
        ans.back() = '0';
        if(ask(ans)) continue;
        ans.pop_back();
        break;
    }
    while(ans.size() != n){
        ans = "1" + ans;
        if(ask(ans)) continue;
        ans[0] = '0';
    }
    guess(ans);
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
