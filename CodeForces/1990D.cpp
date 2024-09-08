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

int f1(pair<int,int> seg, vector<int>& ai){
    int lend = seg.st;
    int rend = seg.nd;
    int ans = 0;
    for(; lend <= rend; lend++){
        if(ai[lend] <= 2) break;
        ans++;
    }
    for(; lend <= rend; rend--){
        if(ai[rend] <= 2) break;
        ans++;
    }
    if(rend < lend) return ans;
    if(rend == lend) return ans + 1;

    vector<int> pos2;
    for(int i = lend; i <= rend; i++){
        if(ai[i] <= 2) pos2.push_back(i);
    }

    int tmp = 0;
    for(int i = 1; i < pos2.size(); i++){
        if((pos2[i] - pos2[i-1])&1){
            tmp++;
            i++;
        }
    }
    return ans + (rend - lend + 1 - tmp);
}

// int f1(pair<int,int> seg, vector<int>& ai){
//     int ilo2 = 0;
//     for(int i = seg.first; i <= seg.nd; i++){
//         if(ai[i] <= 2) ilo2++;
//     }
//     return seg.nd - seg.st + 1 - (ilo2/2);
// }

// int f1(pair<int,int> seg, vector<int>& ai){
//     int lend = seg.st;
//     int rend = seg.nd;
//     int ans = 0;
//     vector<int> pos2;
//     for(int i = 0)
// }

void solve(){
    int n; cin >> n;
    vector<int> ai(n);
    vector<pair<int,int>> seg;
    int ans = -1;
    int lend = 0;
    for(int i = 0; i < n; i++) cin >> ai[i];
    ai.push_back(1e9);
    for(int i = 0; i < n + 1; i++){
        // cin >> ai[i];
        if(ai[i] > 4 || ai[i] == 0){
            if(ai[i] > 4) ans++;
            if(lend <= i - 1){
                seg.push_back({lend,i - 1});
            }
            lend = i + 1;
        }
    }
    ai.pop_back();
    for(auto i : seg){
        ans += f1(i,ai);
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
