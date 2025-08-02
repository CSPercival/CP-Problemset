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

struct Seg{
    int val,l,r;
};

Seg check(int med, int n, int k, vector<int> &a){
    // cout << "CHECK " << med << "\n";
    // printf("CHECK %lld\n",med);
    // vector<int> big(n + 1, 0);
    // for(int i = 1; i <= n; i++){
    //     big[i] = big[i - 1];
    //     if(a[i] >= med) big[i]++;
    // }

    Seg tworst = {(int) -1e9, 0LL, 0LL};
    // vector<Seg> c;
    // int idx = 0;
    // while(idx <= n && a[idx] < med) idx++;
    // if(idx > n) return tworst;
    // int ctr = 0;
    // int inc = 1;
    // int starti = idx;
    // for(int i = idx; i <= n; i++){
    //     if(inc){
    //         if(a[i] >= med ){
    //             ctr++;
    //         } else {
    //             c.push_back({ctr, starti, i - 1});
    //             ctr = -1;
    //             inc = 0;
    //             starti = i;
    //         }
    //     } else {
    //         if(a[i] < med ){
    //             ctr--;
    //         } else {
    //             c.push_back({ctr, starti, i - 1});
    //             ctr = 1;
    //             inc = 1;
    //             starti = i;
    //         }
    //     }    
    // }
    // if(ctr > 0) c.push_back({ctr,starti, n});
    // int cn = c.size();
    // // cout << c << "\n";
    // for(int i = 0; i < cn; i++){
    //     // cout << c[i] << "\n";
    //     printf("{%lld %lld %lld}, ",c[i].val, c[i].l, c[i].r);
    // }
    // printf("\n");
    vector<int> c(n + 1, -1);
    c[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] >= med){
            c[i] = 1;
        }
    }

    vector<Seg> bp(n + 1, tworst);
    int lasti = 1;
    int segsize = 0;
    int score = 0;

    for(int i = 1; i <= n; i++){
        
        while(lasti <= n && segsize < k){
            segsize++;
            score += c[lasti];
            lasti++;
        }
        lasti--;
        if(segsize >= k){
            if(bp[lasti].val == tworst.val || bp[lasti].val < score){
                bp[lasti] = {score, i, lasti};
            }
        }
        lasti++;
        score -= c[i];
        segsize --;
        
        if(bp[i - 1].val != tworst.val && bp[i - 1].val + c[i] > bp[i].val){
            bp[i] = {bp[i - 1].val + c[i], bp[i - 1].l, i};
        }
        if(bp[i].val >= 0){
            // cout << "YES\n";
            // printf("YES\n");
            return bp[i];
        }
        // if (i == n + 1) break;
        
        // for(int i = 0; i <= n; i++){
        //     // cout << c[i] << "\n";
        //     printf("{%lld %lld %lld}, ",bp[i].val, bp[i].l, bp[i].r);
        // }
        // printf("\n");
    }

    

    return tworst;
}

void solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int po = 1, ko = n + 1, sr;
    Seg ans;
    while(po + 1 < ko){
        sr = (po + ko)/2;
        ans = check(sr, n, k, a);
        if(ans.val >= 0){
            po = sr;
        } else {
            ko = sr;
        }
    }
    ans = check(po,n,k,a);
    cout << po << " " << ans.l << " " << ans.r << "\n";
    // cout << endl;
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
