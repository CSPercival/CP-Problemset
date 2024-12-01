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

vector<int> change[3][3];
vector<int> corr;
vector<pair<int,int>> ans;
vector<int> sto;



void make_easy_swap(int p, int v){
    while(!change[p][v].empty() && !change[v][1].empty()){
        ans.push_back({change[p][v].back(),change[v][1].back()});
        swap(sto[change[p][v].back()],sto[change[v][1].back()]);
        change[p][1].push_back(change[p][v].back());
        corr[change[v][1].back()] = 1;
        change[p][v].pop_back();
        change[v][1].pop_back();
    }
}

int make_swaps(){
    int checkpoint = ans.size();
    make_easy_swap(1,2);
    make_easy_swap(1,0);
    make_easy_swap(0,2);
    make_easy_swap(2,0);

    return (checkpoint == ans.size());
}

void solve(){
    int n; cin >> n;
    sto.assign(n,0);
    corr.assign(n,0);
    int hei[]={0,0,0};
    for(int i = 0; i < n; i++){
        cin >> sto[i];
        hei[sto[i]]++;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            change[i][j].clear();
        }
    }
    ans.clear();
    
    int lim1 = hei[0];
    int lim2 = hei[0] + hei[1];
    for(int i = 0; i < lim1; i++){
        if(sto[i] == 0){
            corr[i] = 1;
        }
        if(sto[i] == 1){
            change[0][1].push_back(i);
        }
        if(sto[i] == 2){
            change[0][2].push_back(i);
        }
    }
    for(int i = lim1; i < lim2; i++){
        if(sto[i] == 1){
            //corr[i] = 1;
            change[1][1].push_back(i);
        }
        if(sto[i] == 0){
            change[1][0].push_back(i);
        }
        if(sto[i] == 2){
            change[1][2].push_back(i);
        }
    }
    for(int i = lim2; i < n; i++){
        if(sto[i] == 2){
            corr[i] = 1;
        }
        if(sto[i] == 1){
            change[2][1].push_back(i);
        }
        if(sto[i] == 0){
            change[2][0].push_back(i);
        }
    }

    while(!make_swaps());
    // for(auto mov : ans){
    //     cout << mov.st+1 << " " << mov.nd+1 << "\n";
    // }
    int mov_idx = change[1][1].back();
    if(!change[2][0].empty()){
        ans.push_back({mov_idx,change[2][0].back()});
        swap(sto[mov_idx], sto[change[2][0].back()]);
        change[2][1].push_back(change[2][0].back());
        change[1][0].push_back(mov_idx);
        change[2][0].pop_back();
        change[1][1].pop_back();
    }
    while(!change[2][0].empty()){
        make_easy_swap(0,2);
        make_easy_swap(2,0);
    }
    make_easy_swap(0,2);
    make_easy_swap(1,0);
    
    cout << ans.size() << "\n";
    for(auto mov : ans){
        cout << mov.st+1 << " " << mov.nd+1 << "\n";
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
