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
    int n; cin >> n;
    vector<int> prior[3];
    vector<int> where[3];
    vector<int> route(n + 1, -1);
    vector<int> route2(n + 1, -1);
    int best_prior[3];

    int tmp;
    int tn,tp;
    vector<pair<int,int>> tstack;
    for(int i = 0; i < 3; i++){
        where[i].assign(n + 2, -1);  
        for(int j = 0; j < n; j++){
            cin >> tmp;
            prior[i].push_back(tmp);
            where[i][tmp] = j;   
        }
        best_prior[i] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int g = 0; g < 3; g++){
            if(prior[g][best_prior[g]] > prior[g][i]){
                route[i] = g;
                route2[i] = best_prior[g];
                for(int gg = 0; gg < 3; gg++){
                    if(prior[gg][best_prior[gg]] < prior[gg][i]) best_prior[gg] = i;
                }
            }
        }
    }

    if(route[n - 1] == -1){
        cout << "NO\n";
        return;
    }
    char trans[]={'q','k','j'};
    vector<pair<int,int>> ans;
    int start = n - 1; 

    while(start > 0){
        ans.push_back({route[start],start});
        start = route2[start];
    }
    reverse(all(ans));

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << trans[ans[i].st] << " " << ans[i].nd + 1 << "\n";
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
