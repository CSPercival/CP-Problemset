//Rating 1800
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

vector<int> auxa[400200];
vector<int> tauxa[400200];
vector<int> auxb[400200];
vector<int> tauxb[400200];

void vclr(vector<int> &v){
    vector<int>().swap(v);
}

void solve(){

    int n; cin >> n;
    vector<int> ai(n);
    vector<int> bi(n);
    for(int i = 0; i < n; i++){cin >> ai[i];}
    for(int i = 0; i < n; i++){cin >> bi[i];}

    vclr(auxa[0]);
    vclr(auxb[0]);
    for(int i = 0; i < n; i++){
        auxa[0].push_back(ai[i]);
        auxb[0].push_back(bi[i]);
    }
    int mask = 0;
    int ans = 0;
    int git = 1;
    int midx = 1;
    int tidx = 0;
    for(int phase = 0; phase <= 29; phase++){
        mask = (1 << (29 - phase));
        git = 1;
        tidx = 0;
        for(int i = 0; i < midx; i++){
            if(auxa[i].size() == 0) continue;
            vclr(tauxa[tidx]);
            vclr(tauxa[tidx + 1]);
            vclr(tauxb[tidx]);
            vclr(tauxb[tidx + 1]);

            if(!git){
                tauxa[tidx] = auxa[i];
                tauxb[tidx] = auxb[i];
                tidx += 2;
                continue;
            }
            for(int j = 0; j < auxa[i].size(); j++){
                if(auxa[i][j] & mask){
                    tauxa[tidx].push_back(auxa[i][j]);
                } else {
                    tauxa[tidx + 1].push_back(auxa[i][j]);
                }
                if(auxb[i][j] & mask){
                    tauxb[tidx + 1].push_back(auxb[i][j]);
                } else {
                    tauxb[tidx].push_back(auxb[i][j]);
                }
            }
            if(tauxa[tidx].size() != tauxb[tidx].size() || tauxa[tidx + 1].size() != tauxb[tidx + 1].size()) git = 0;
            tidx += 2;
        }
        if(git){
            ans += mask;
        }
        midx = 0;
        for(int i = 0; i < tidx; i++){
            if(i & 1){
                if(git){
                    auxa[midx].clear();
                    for(int j = 0; j < tauxa[i].size(); j++){
                        auxa[midx].push_back(tauxa[i][j]);
                    }
                    auxb[midx].clear();
                    for(int j = 0; j < tauxb[i].size(); j++){
                        auxb[midx].push_back(tauxb[i][j]);
                    }
                    if(auxa[midx].size() != 0) midx++;
                } else {
                    for(int j = 0; j < tauxa[i].size(); j++){
                        auxa[midx - 1].push_back(tauxa[i][j]);
                    }
                    for(int j = 0; j < tauxb[i].size(); j++){
                        auxb[midx - 1].push_back(tauxb[i][j]);
                    }
                }
            } else {
                auxa[midx].clear();
                for(int j = 0; j < tauxa[i].size(); j++){
                    auxa[midx].push_back(tauxa[i][j]);
                }
                auxb[midx].clear();
                for(int j = 0; j < tauxb[i].size(); j++){
                    auxb[midx].push_back(tauxb[i][j]);
                }
                if(auxa[midx].size() != 0 || auxb[midx].size() != 0 || !git) midx++;
            }
            vclr(tauxa[i]);
            vclr(tauxb[i]);
        }
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
