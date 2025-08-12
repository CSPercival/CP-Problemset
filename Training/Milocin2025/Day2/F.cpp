#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

ll ans = 0;
ll n, k; 
vector<pair<ll,ll>> bef[2]; // {jaka liczba, ile razy jest}
vector<pair<ll,ll>> aft[2];

void add(vector<pair<ll,ll>> *v, ll val, ll num){
    if(v->empty()){
        v->push_back({val,num});
        return;
    }
    if(v->back().st == val){
        // v->back().nd += num;
        (*v)[v->size() - 1].nd += num;
        return;
    }
    if(v->size() == 1){
        v->push_back({val,num});
        return;
    }
    if((*v)[v->size() - 2].st == val){
        (*v)[v->size() - 2].nd += num;
    } else {
        v->push_back({val,num});
    }
}

void add2(vector<pair<ll,ll>> *v, ll val, ll num){
    for(auto &p : (*v)){
        if(p.st == val){
            p.nd += num;
            return;
        }
    }
    v->push_back({val,num});
}

void go(ll l, ll r){
    int mod = 0;
    ll m;
    while(true){
        // cout << k << " " << l << " " << r << endl;
        // for(auto x : bef[mod]){
        //     cout << "{ " << x.st << ", " << x.nd << "} ";
        // }
        // cout << endl;
        // for(auto x : aft[mod]){
        //     cout << "{ " << x.st << ", " << x.nd << "} ";
        // }
        // cout << endl;
        for(auto p : bef[mod]){
            ans += p.nd;
            m = (1 + p.st)/2;
            if(m > 1){
                add(&bef[mod ^ 1], m - 1, p.nd);
            }
            if(m != p.st){
                add(&bef[mod ^ 1], p.st - m, p.nd);
            }
        }
        ans++;
        m = (l + r)/2;
        if(m == k) break;

        for(auto p : aft[mod]){
            ans += p.nd;
            m = (1 + p.st)/2;
            if(m > 1){
                add(&aft[mod ^ 1], m - 1, p.nd);
            }
            if(m != p.st){
                add(&aft[mod ^ 1], p.st - m, p.nd);
            }
        }
        m = (l + r)/2;

        if(k < m){
            if(m + 1 <= r){
                add2(&aft[mod ^ 1], r - m, 1);
            }
            r = m - 1;
        } else {
            if(l <= m - 1){
                add2(&bef[mod ^ 1], m - l, 1);
            }
            l = m + 1;
        }

        aft[mod].clear();
        bef[mod].clear();
        mod ^= 1;
    }
}

void solve() {
    cin >> n >> k;
    bef[0].clear();
    bef[1].clear();
    aft[0].clear();
    aft[1].clear();

    ans = 0;
    go(1, n);
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    
}