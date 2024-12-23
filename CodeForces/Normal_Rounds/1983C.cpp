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
    vector<int> ai[3];
    ai[0].assign(n,0);
    ai[1].assign(n,0);
    ai[2].assign(n,0);
    ll tot = 0;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < n; i++){
            cin >> ai[j][i];
            tot += ai[j][i];    
        }
    }
    tot /= 3;
    ll lim = (tot + 2)/3;

    vector<int> rend[3];
    rend[0].assign(n,0);
    rend[1].assign(n,0);
    rend[2].assign(n,0);
    for(int j = 0; j < 3; j++){
        int ptr = n, ptr2 = n;
        ll sum = 0;
        while(sum < lim){
            ptr--;
            sum += ai[j][ptr];
        }
        for(int i = ptr + 1; i < n; i++){
            rend[j][i] = n;
        }
        sum -= ai[j][ptr];
        // rend[j][ptr] = n - 1;
        ptr2 = n - 1;
        for(int i = ptr; i >= 0; i--){
            sum += ai[j][i];
            while(sum >= lim){
                sum -= ai[j][ptr2];
                ptr2--;
            }
            ptr2++;
            sum += ai[j][ptr2];
            rend[j][i] = ptr2;
        }
    }
    // cout << rend[0];
    // cout << "\n";
    // cout << rend[1];
    // cout << "\n";
    // cout << rend[2];
    // cout << "\n";
    pair<int,int> ans[3] = {{-1,-1},{-1,-1},{-1,-1}};
    vector<int> kol = {0,1,2};
    int ptr1, ptr2;
    do{
        ptr1 = rend[kol[0]][0] + 1;
        if(ptr1 >= n) continue;
        ptr2 = rend[kol[1]][ptr1] + 1;
        if(ptr2 >= n) continue;
        if(rend[kol[2]][ptr2] >= n) continue;
        ans[kol[0]] = {1, ptr1};
        ans[kol[1]] = {ptr1 + 1, ptr2};
        ans[kol[2]] = {ptr2 + 1, n};
    }while(next_permutation(all(kol)));
    if(ans[0].st == -1){
        cout << "-1" << "\n";
        return;
    }
    cout << ans[0].st << " " << ans[0].nd << " " << ans[1].st << " " << ans[1].nd << " " << ans[2].st << " " << ans[2].nd << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
