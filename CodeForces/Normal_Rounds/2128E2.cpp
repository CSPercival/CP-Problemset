#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
#define int ll
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

struct Seg{
    int val,l,r;
};

Seg check(int med, int n, int k, vector<int> &a, bool (*f1)(int,int)){
    Seg tworst = {(int) -1e9, 0LL, 0LL};
    vector<int> c(n + 1, -1);
    c[0] = 0;
    for(int i = 1; i <= n; i++){
        if(f1(a[i], med)){
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
            return bp[i];
        }
    }
    return tworst;
}

Seg bin_search(bool (*f1)(int,int), int po, int ko, int n, int k, vector<int> &a, int mode){
    Seg ans;
    int sr;
    while(po + 1 < ko){
        sr = (po + ko)/2;
        ans = check(sr, n, k, a, f1);
        if((ans.val >= 0) ^ mode){
            po = sr;
        } else {
            ko = sr;
        }
    }
    if(mode){
        ans = check(ko,n,k,a,f1);
        ans.val = ko; 
    } else {
        ans = check(po,n,k,a,f1);
        ans.val = po; 
    }
    return ans;
}

struct CountMedian{
    ordered_set os;
    CountMedian(vector<int> &a, int l, int r){
        for(int i = l; i <= r; i++){
            os.insert(a[i]);
        }
    }

    void printos(){
        for(int i = 0; i < os.size(); i++){
            cout << i << " - " << *os.find_by_order(i) << "\n";
        }
    }

    void add(int val){
        os.insert(val);
    }
    void sub(int val){
        os.erase(os.find_by_order(os.order_of_key(val)));
    }

    pair<int,int> get_med(){
        int mini, maxi;
        if(os.size() & 1){
            mini = (*(os.find_by_order(os.size()/2)));
            maxi = mini;
        } else {
            maxi = (*(os.find_by_order(os.size()/2)));
            mini = (*(os.find_by_order(os.size()/2 - 1)));
        }
        return {mini,maxi};
    }

    void update_ans(vector<Seg> &ans, int *wans, Seg *curr){
        pair<int,int> cmed = get_med();
        while((*wans) <= cmed.nd){
            curr->val = (*wans);
            ans[(*wans)] = (*curr);
            (*wans)++;
        }
    }
};

void solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Seg ans_max = bin_search([](int x, int y){return x >= y;}, 1, n + 1, n, k, a, 0);
    Seg ans_min = bin_search([](int x, int y){return x <= y;}, 0, ans_max.val, n, k, a, 1);
    int min_sub = ans_min.val;
    int max_sub = ans_max.val;

    vector<Seg> ans(n + 1);
    ans[min_sub] = ans_min;
    ans[max_sub] = ans_max;
    Seg curr = ans_min;
    CountMedian cm(a, ans_min.l, ans_min.r);
    pair<int,int> cmed;
    int wans = ans_min.val;
    cm.update_ans(ans, &wans, &curr);

    
    while(curr.l > ans_max.l){
        curr.l--;
        cm.add(a[curr.l]);
        cm.update_ans(ans, &wans, &curr);
    }
    while(curr.r < ans_max.r){
        curr.r++;
        cm.add(a[curr.r]);
        cm.update_ans(ans, &wans, &curr);
    }
    while(curr.l < ans_max.l){
        cm.sub(a[curr.l]);
        curr.l++;
        cm.update_ans(ans, &wans, &curr);
    }
    while(curr.r > ans_max.r){
        cm.sub(a[curr.r]);
        curr.r--;
        cm.update_ans(ans, &wans, &curr);
    }

    cout << ans_max.val - ans_min.val + 1 << "\n";
    for(int i = ans_min.val; i <= ans_max.val; i++){
        cout << i << " " << ans[i].l << " " << ans[i].r << "\n";
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
