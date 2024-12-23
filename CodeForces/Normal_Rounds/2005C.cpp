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

int infi = 1e9;
int bestb[5];

void solve(){
    int n, m; cin >> n >> m;
    vector<string> w(n);
    vector<char> alfa = {'n','a','r','e','k'};
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    vector<int> bestb(5,infi * -1),comb(5);
    // for(int i = 0; i < 5; i++){
    //     bestb[i] = -1 * infi;
    // }
    bestb[0] = 0;
    // cout << bestb << "\n";
    for(int i = 0; i < n; i++){
        // int comb[5];
        // for(int k = 0; k < 5; k++) comb[i] = bestb[i];
        comb = bestb;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 5; k++){
                if(w[i][j] == alfa[k]){
                    for(int k2 = 0; k2 < 5; k2++){
                        if(k2 == k){
                            continue;
                        } else {
                            comb[k2]--;                          
                        }
                    }
                    comb[(k + 1) % 5] = max(comb[(k + 1) % 5],comb[k] + 1);
                    comb[k] = infi * (-1);
                }
            }
            // cout << comb << "\n";
        }
        // cout << comb << "\n";
        for(int k = 0; k < 5; k++){
            bestb[k] = max(bestb[k],comb[k]);
        }
        // cout << "\n";
        // cout << comb;
        // cout << "\n";
        // cout << bestb << "\n\n";
    }
    // cout << bestb << "\n\n\n\n";
    // cout << "lalala\n\n";
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans = max(ans,bestb[i] - 2 * i);
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
