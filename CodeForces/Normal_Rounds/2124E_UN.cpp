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

int lefti, righti, bigdiff;
int left_big;
int stage_clear;

void f1(int lvl, int l, int r, int diff, vector<int> &a, vector<vector<int>> &ans){
    ll sum = 0;
    int sr;
    for(int i = l; i <= r; i++){
        sum += a[i];
    }
    ll tsum = 0;
    ll trsum = sum;
    for(sr = l; sr <= r && tsum < trsum; sr++){
        tsum += a[sr];
        trsum -= a[sr];
    }
    int offer = 0;
    if(tsum - trsum <= (trsum + a[sr]) - (tsum - a[sr])){
        offer = tsum - trsum;
        if(diff >= offer){
            lefti = sr;
            righti = sr + 1;
            bigdiff = offer;
            left_big = 1;
        } else{
            f1(lvl + 1, l, sr, diff + trsum, a, ans);
        }
        if(stage_clear == lvl){
            for(int i = sr + 1; i <= r; i++){
                ans[lvl][i] = a[i];
                a[i] = 0;
            }
        }
        offer = trsum;
    } else {
        trsum += a[sr];
        tsum -= a[sr];
        sr--;
        offer = trsum - tsum;
        if(diff >= offer){
            lefti = sr;
            righti = sr + 1;
            bigdiff = offer;
            left_big = 0;
        } else{
            f1(lvl + 1, sr + 1, r, diff + tsum, a, ans);
        }
        if(stage_clear == lvl){
            for(int i = l; i <= sr; i++){
                ans[lvl][i] = a[i];
                a[i] = 0;
            }
        }
        offer = tsum;
    }

    assert(offer != 0);
    if(stage_clear == lvl){
        if(left_big){
            while(offer && bigdiff){
                ans[lvl][lefti] = min({a[lefti], offer, bigdiff});
                offer -= ans[lvl][lefti];
                bigdiff -= ans[lvl][lefti];
                a[lefti] -= ans[lvl][lefti];
                lefti--;
            }
        } else {
            while(offer && bigdiff){
                ans[lvl][righti] = min({a[righti], offer, bigdiff});
                offer -= ans[lvl][righti];
                bigdiff -= ans[lvl][righti];
                a[righti] -= ans[lvl][righti];
                righti++;
            }
        }
        int tmp;
        while(offer > 1){
            tmp = min({a[lefti], a[righti], offer/2});
            ans[lvl][lefti] = tmp;
            ans[lvl][righti] = tmp;
            a[lefti] -= tmp;
            a[righti] -= tmp;
            offer -= 2 * tmp;
            if(a[lefti] == 0) lefti--;
            if(a[righti] == 0) righti++;
        }
        if(offer == 1){
            if(lefti >= 0 && a[lefti] > 0){
                ans[lvl][lefti]++;
            } else {
                ans[lvl][righti]++;
            }
        }
        stage_clear++;
        f1(lvl + 1, l, sr, 0, a, ans);
    }
    return;
}

void solve(){
    int n; 
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum & 1){
        cout << "-1\n";
        return;
    }
    ll modif = 0;
    ll rest = sum;
    vector<vector<ll>> ans(17, vector<int>(n, 0));
    stage_clear = 0;
    f1(0, 0, n - 1, 0, a, ans);
    // cout << "YES\n";
    cout << stage_clear + 1 << "\n";
    for(int i = 0; i < stage_clear; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    cout << '\n';
    // while(modif != sum){
    //     rest = sum - modif;
    //     ll tsum = 0;
    //     ll trsum = rest;
    //     for(int i = l; i <= n; i++){
    //         tsum += a[i];
    //         trsum -= a[i];
    //         if(tsum >= trsum){
    //             sr = i;
    //             break;
    //         }
    //     }
    //     if(tsum - trsum <= (trsum + a[sr]) - (tsum - a[sr])){

    //     } else {

    //     }
    // }

}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
