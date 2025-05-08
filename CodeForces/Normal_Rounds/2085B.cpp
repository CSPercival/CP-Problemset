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

void print_ans(vector<pair<int,int>> &ans){
    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << i.st << " " << i.nd << '\n';
    }
}

void solve(){
    int n; cin >> n;
    vector<int> ai(n + 1);
    vector<pair<int,int>> ans;
    int f0 = -1, l0 = 0;
    for(int i = 1; i <= n; i++){
        cin >> ai[i];
        if(ai[i] == 0){
            if(f0 == -1){
                f0 = i;
            }
            l0 = i;
        }
    }
    if(f0 == -1){
        ans.push_back({1, n});
        print_ans(ans);
        return;
    }
    if(f0 != 1){
        ans.push_back({2, n});
        ans.push_back({1,2});
        print_ans(ans);
        return;
    }
    if(l0 != n){
        ans.push_back({1, n - 1});
        ans.push_back({1,2});
        print_ans(ans);
        return;
    }
    ans.push_back({n - 1, n});
    ans.push_back({1, n - 2});
    ans.push_back({1,2});
    print_ans(ans);
    return;
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
