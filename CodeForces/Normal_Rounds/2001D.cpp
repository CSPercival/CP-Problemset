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
 
int infi = 300005;
int ai[300010];
int mostr[300010];
int used[300010];
vector<int> pos[300010];

struct SegTree{
    vector<int> t;
    int n;
    int not_ans;
    int shift = 1;
    bool (*cmp)(int,int);

    SegTree(int in_n, int in_not_ans, bool(*in_cmp)(int,int)){ 
        n = in_n;
        not_ans = in_not_ans;
        cmp = in_cmp;
        while(shift <= n) shift *= 2;
        t.resize(2 * shift);

        for(int i = 0; i < n; i++) t[shift + i] = ai[i];
        for(int i = n + shift; i < t.size(); i++) t[i] = not_ans;
        for(int i = shift - 1; i > 0; i--){
            t[i] = t[i << 1];
            if(cmp(t[(i << 1) + 1], t[i]))
                t[i] = t[(i << 1) + 1];
        }
    }

    void set_val(int x, int idx){
        idx += shift;
        t[idx] = x;
        for(idx /= 2; idx > 0; idx /= 2){
            t[idx] = t[idx * 2];
            if(cmp(t[idx * 2 + 1], t[idx])) t[idx] = t[idx * 2 + 1];
        }
    }

    int find_val(int lidx, int ridx){
        int ans = not_ans;
        for(lidx += shift, ridx += shift; lidx < ridx; lidx >>= 1, ridx >>= 1){
            if(lidx & 1){
                if(cmp(t[lidx], ans)){
                    ans = t[lidx];
                }
                lidx++;
            }
            if(1 & ridx){
                ridx--;
                if(cmp(t[ridx], ans)){
                    ans = t[ridx];
                }
            }
        }
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        ai[i] = 0;
        mostr[i] = -1;
        used[i] = 0;
        pos[i].clear();
    }
    for(int i = 0; i < n; i++){
        cin >> ai[i];
        mostr[ai[i]] = i;
        pos[ai[i]].push_back(i);
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 1; i <= n; i++){
        if(mostr[i] == -1) continue;
        pq.push(mostr[i]);
    }
    SegTree tmin(n,infi,[](int a, int b){return a < b;});
    SegTree tmax(n,infi * -1,[](int a, int b){return a > b;});
    int lptr = 0, rptr;
    int ctr1 = 0;
    int ansik;
    vector<int> ans;
    while(!pq.empty()){
        rptr = pq.top();
        if(used[ai[rptr]]){
            pq.pop();
            continue;
        }
        if(ctr1&1){
            ansik = tmin.find_val(lptr, rptr + 1);
        } else {
            ansik = tmax.find_val(lptr, rptr + 1);
        }
        
        ctr1++;
        ans.push_back(ansik);
        used[ansik] = 1;
        clear_val(&lptr, &rptr, ansik, &tmin, &tmax);
        for(int idx : pos[ansik]){
            tmin.set_val(infi, idx);
            tmax.set_val(infi * -1, idx);
        }
        for(int idx : pos[ansik]){
            if(lptr <= idx){
                lptr = idx + 1;
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
