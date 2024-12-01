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

set<vector<int>> poss;
int lim = 0;
int all_ans = 0;
int tmp = 0;

int count_inv(vector<int> x){
    int ans = 0;
    for(int i = 0; i < x.size(); i++){
        for(int j = i + 1; j < x.size(); j++){
            if(x[i] > x[j]) ans++;
        }
    }
    return ans;
}


void solve(vector<int> x){
    if(x.size() == lim){
        all_ans++;
        return;
    }
    int inv = count_inv(x);
    x.push_back(inv);
    if(poss.find(x) == poss.end()){
        poss.insert(x);
        solve(x);
    } else {
        tmp++;
    }
    for(int i = x.size() - 2; i >= 0; i--){
        if(x[i] == x[i + 1]) continue;
        swap(x[i],x[i + 1]);
        if(poss.find(x) == poss.end()){
            poss.insert(x);
            solve(x);
        } else {
            tmp++;
        }
    }
}

 
int32_t main(){
    BOOST;
 
    lim = 10;

    vector<int> start;
    start.push_back(0);
    start.push_back(1);
    poss.insert(start);
    solve(start);

    cout << all_ans << "\n";
    cout << tmp << "\n";
    return 0;
}
