#include <bits/stdc++.h>
using namespace std;
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0)
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using int128_t = __int128_t;
#define int long long
template <typename T>
using vc = vector<T>;

// int n;
ll minfi = -1e18;
vector<ll> oria;

struct onecase{
    vector<pair<int,ll>> pots;
    int idx = 1;
    bool check(pair<int128_t, int128_t> l1, pair<int128_t, int128_t> l2, pair<int128_t, int128_t> l3, pair<int128_t, int128_t> l4) {
        return (l2.nd-l1.nd)*(l3.st-l4.st) >= (l1.st-l2.st)*(l4.nd-l3.nd);
    }

    void compute_pots(vector<pair<int,ll>> &inpots){
        pots.push_back({0, minfi});
        for (int i = 0; i < (int)inpots.size(); i++) {
            while (pots.size() > 1 && check(pots[pots.size()-2], pots[pots.size()-1],pots.back(), inpots[i])) pots.pop_back();
            pots.push_back(inpots[i]);
        }
    }

    ll get_ans(int tidx, ll shift){
        return pots[tidx].st * shift + pots[tidx].nd;
    }

    ll get_best(ll shift){
        while(idx + 1 < (int)pots.size() && get_ans(idx, shift) <= get_ans(idx + 1, shift)) idx++;
        return get_ans(idx, shift);
    }
};

struct Block{
    int n, l, r;
    ll sum = 0;
    vector<int> a;
    onecase L,R,M;

    Block(int inl, int inr) : l(inl), r(inr){
        n = r - l + 1;
        a.resize(n);
        for(int i = l; i <= r; i++){
            a[i - l] = oria[i];
            sum += oria[i];
        }

        vector<pair<int, ll>> lpots, rpots, mpots;
        ll csum = 0;
        for(int i = 0; i < n; i++){
            csum += a[i];
            lpots.push_back({i + 1, csum});
        }
        csum = 0;
        for(int i = n - 1; i >= 0; i--){
            csum += a[i];
            rpots.push_back({n - i, csum});
        }
        ll bsum;
        for(int i = 1; i <= n; i++){
            bsum = minfi;
            csum = 0;
            for(int j = 0; j < i; j++){
                csum += a[j];
            }
            bsum = max(bsum, csum);
            for(int j = i; j < n; j++){
                csum += a[j] - a[j - i];
                bsum = max(bsum, csum);
            }
            mpots.push_back({i, bsum});
        }

        L.compute_pots(lpots);
        R.compute_pots(rpots);
        M.compute_pots(mpots);
    }

    ll lbest(ll shift){
        return L.get_best(shift);
    }
    ll rbest(ll shift){
        return R.get_best(shift);
    }
    ll mbest(ll shift){
        return M.get_best(shift);
    }
    ll gsum(ll shift){
        return sum + shift * n;
    }
};

struct SQRTDS{
    vector<int> a;
    vector<Block> blk;
    int n, sqn;
    int curr_shift = 0;

    SQRTDS(int inn){
        n = inn;
        sqn = (int)sqrt(n) + 2;
        for(int i = 0; i < n; i += sqn){
            blk.push_back(Block(i,min(n - 1, i + sqn - 1)));
        }
    }

    void update(ll nshift){
        curr_shift = nshift;
    }

    void naive(ll *ans, ll *curr_sum, int l, int r){
        for(int i = l; i <= r; i++){
            (*curr_sum) += oria[i] + curr_shift;
            (*ans) = max((*ans), (*curr_sum));
            if((*curr_sum) < 0) (*curr_sum) = 0;
        }
    }

    ll query(int ql, int qr){
        ll best_ans = 0;
        ll curr_sum = 0;
        int cblk = 0;
        int send = 0;
        for(int i = 0; i < (int)blk.size(); i++){
            if(blk[i].l <= ql){
                send = blk[i].r;
                cblk = i + 1;
            }
        }
        if(qr <= send){
            naive(&best_ans, &curr_sum, ql, qr);
            return best_ans;
        }
        naive(&best_ans, &curr_sum, ql, send);
        while(cblk < (int)blk.size() && blk[cblk].r <= qr){
            best_ans = max({best_ans, curr_sum + blk[cblk].lbest(curr_shift), blk[cblk].mbest(curr_shift)});
            curr_sum = max({0LL, curr_sum + blk[cblk].gsum(curr_shift), blk[cblk].rbest(curr_shift)});
            best_ans = max(best_ans, curr_sum);
            cblk++;
        }
        if(cblk == (int)blk.size()){
            return best_ans;
        }
        naive(&best_ans, &curr_sum, blk[cblk].l, qr);

        return best_ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    oria.resize(n);
    for(int i = 0; i < n; i++){
        cin >> oria[i];
    }

    ll shift = 0;
    int sctr = 0;
    vector<vector<pair<int,pair<int,int>>>> quests(1);
    vector<pair<ll, int>> strens;
    strens.push_back({0,0});
    
    string stmp;
    int l, r;
    ll x;
    for(int i = 0; i < m; i++){
        cin >> stmp;
        if(stmp == "ASSESS"){
            cin >> l >> r;
            l--;
            r--;
            quests.back().push_back({i, {l, r}});
        }
        if(stmp == "STRENGTH"){
            cin >> x;
            shift += x;
            quests.emplace_back();
            sctr++;
            strens.push_back({shift, sctr});
        }
    }
    sort(all(strens));

    for(int i = 0; i < n; i++){
        oria[i] += strens[0].st;
    }

    for(int i = strens.size() - 1; i >= 0; i--){
        strens[i].st -= strens[0].st;
    }

    SQRTDS ds(n);

    vector<pair<int, ll>> answers;
    for(auto i : strens){
        ds.update(i.st);
        for(auto j : quests[i.nd]){
            ll tmp = ds.query(j.nd.st, j.nd.nd);
            answers.push_back({j.st, tmp});
        }
    }
    sort(all(answers));

    for(auto i : answers){
        cout << i.nd << "\n";
    }
}

int32_t main(){
    BOOST;
    solve();
}