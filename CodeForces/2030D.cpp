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

pair<int,int> f1(int idx, vector<int>&perm, vector<int>&vis){
    int mini = -1, maksi = 1e9;
    while(!vis[idx]){
        mini = min(mini,idx);
        maksi = max(maksi,idx);
        vis[idx] = 1;
        idx = perm[idx];
    }
    return {mini,maksi};
}

bool checklr(int idx, string&man){
    if(man[idx - 1] == 'L' && man[idx] == 'R') return true;
    return false;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> perm(n);
    vector<int> maxpre(n);
    vector<int> minsuf(n);
    // vector<int> vis(n);
    for(int i = 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }
    maxpre[0] = perm[0];
    minsuf[n - 1] = perm[n - 1];
    for(int i = 1; i < n; i++){
        maxpre[i] = max(maxpre[i - 1], perm[i]);
        minsuf[n - i - 1] = max(minsuf[n - i], perm[n - i - 1]);
    }
    // pair<int,int> tmpp;
    // for(int i = 0; i < n; i++){
    //     if(!vis[i]){
    //         tmpp = f1(i,perm,vis);
    //     }
    // }
    set<int> lr;
    string man; cin >> man;
    for(int i = 1; i < n; i++){
        if(man[i - 1] == 'L' && man[i] == 'R'){
            if(maxpre[i - 1] >= i || minsuf[i] < i){
                lr.insert(i);
            }
        }
    }
    int idx;
    while(q--){
        cin >> idx;
        idx--;
        if(checklr(idx,man) && lr.count(idx)) lr.erase(idx);
        if(checklr(idx + 1,man) && lr.count(idx + 1)) lr.erase(idx + 1);
        if(man[idx] == 'R') man[idx] = 'L';
        else man[idx] = 'R';

        if(checklr(idx,man) && (maxpre[idx - 1] >= idx || minsuf[idx] < idx)) lr.insert(idx);
        if(checklr(idx + 1,man) && (maxpre[idx] >= idx + 1 || minsuf[idx + 1] < idx + 1)) lr.insert(idx + 1);

        // if(man[idx] == 'R'){
        //     man[idx] = 'L';
        //     if(man[idx - 1] == 'L'){
        //         if(lr.count(idx)) lr.erase(idx);
        //     } else{

        //     }
        // } else {
        //     man[idx] = 'R';
        //     if(man[idx + 1] == 'L'){
        //         if(lr.count(idx + 1)) lr.erase(idx + 1);
        //     } else{
                
        //     }
        // }
        


        if(lr.empty()){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
