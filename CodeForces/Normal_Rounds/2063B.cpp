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
    int n; cin >> n;
    int l, r; cin >> l >> r;
    vector<int> ai(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
    }
    vector<int> op1, mid, op2;
    for(int i = 1; i < l; i++){
        op1.push_back(ai[i]);
    }
    ll sum = 0;
    for(int i = l; i <= r; i++){
        mid.push_back(ai[i]);
        sum += ai[i];
    }
    for(int i = r + 1; i <= n; i++){
        op2.push_back(ai[i]);
    }

    sort(all(mid));
    sort(all(op1));
    sort(all(op2));

    ll sum1 = sum, sum2 = sum;
    int idx1 = 0;
    for(int i = mid.size() - 1; i >= 0; i--){
        if(idx1 == op1.size()) break;
        if(op1[idx1] >= mid[i]) break;
        sum1 -= mid[i] - op1[idx1];
        idx1++;
    }

    int idx2 = 0;
    for(int i = mid.size() - 1; i >= 0; i--){
        if(idx2 == op2.size()) break;
        if(op2[idx2] >= mid[i]) break;
        sum2 -= mid[i] - op2[idx2];
        idx2++;
    }

    cout << min(sum1, sum2) << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
