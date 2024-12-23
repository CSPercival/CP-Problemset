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


void solve(){
    int n, x; cin >> n >> x;
    vector<int> ai(n + 1);
    vector<int> pref(n + 2);
    vector<int> hmz(n + 2,0);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
        sum += ai[i];
        pref[i] = pref[i - 1] + ai[i];
    }
    if(sum <= x){
        cout << n * (n + 1)/2 << "\n";
        return;
    }
    int ptr1 = n;
    int ptr2 = n;
    int rev_ans = 0;
    while(pref[n] - pref[ptr2] <= x) ptr2--;
    for(int i = ptr2 + 1; i > 0; i--){
        while(pref[ptr1] - pref[i - 1] > x && ptr1 >= i) ptr1--;
        ptr1++;
        hmz[i] = 1 + hmz[ptr1 + 1];
        rev_ans += hmz[i];
    }
    cout << n * (n + 1)/2 - rev_ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
