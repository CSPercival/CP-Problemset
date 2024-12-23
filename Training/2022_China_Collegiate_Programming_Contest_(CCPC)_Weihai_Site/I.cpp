#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define st first
#define nd second
#define all(x) x.begin(),x.end()
 
vector<ll> a1, a2;
bool check(int n, int k, vector<ll> a, vector<ll> b, ll mult) {
    for (int i = 0; i < n; i++) {
        if (a[i] > ((ll)2e16)/mult) return false;
        a[i] *= mult;
    }
    int it = k-1;
    for (int i = 55; i >= 0; i--) {
        ll limit = (1LL<<(ll)i);
        a1 = a2 = vector<ll>(0);
        for (int j = 0; j < a.size(); j++) {
            if (a[j] < limit) a1.push_back(a[j]);
            else a2.push_back(a[j]);
        }
        if (a2.empty()) continue;
        // cout << i << ":\n";
        // for (auto x: a1) cout << x << ' ';
        // cout << '\n';
        // for (auto x: a2) cout << x << ' ';
        // cout << '\n';
        for (int j = a2.size()-1; j >= 0; j--) {
            if (it < 0) return false;
            if (a2[j] <= (1LL<<(ll)it)) {
                a2[j] = 0;
                b[it]--;
                if (b[it] == 0) it--;
            }
            else {
                ll rm = limit;
                while (rm > 0) {
                    if (it < 0) return false;
                    ll s = rm/(1LL<<(ll)it);
                    if (s < b[it]) {
                        b[it] -= s;
                        break;
                    }
                    else {
                        rm -= b[it]*(1LL<<(ll)it);
                        b[it] = 0;
                        it--;
                    }
                }
                a2[j] -= limit;
            }
        }
        a = vector<ll>(0);
        for (int i1 = 0, i2 = 0; i1 < a1.size() || i2 < a2.size(); ) {
            while (i2 < a2.size() && a2[i2] == 0) i2++;
            if (i1 == a1.size()) a.push_back(a2[i2++]);
            else if (i2 == a2.size()) a.push_back(a1[i1++]);
            else {
                if (a1[i1] < a2[i2]) a.push_back(a1[i1++]);
                else a.push_back(a2[i2++]);
            }
 
        }
        if (a.empty()) break;
    }
    return true;
}
 
void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) cin >> b[i];
    ll l = 0, r = 2e16, mid;
    while (l < r) {
        mid = (l+r)/2;
        if (check(n, k, a, b, mid)) l = mid+1;
        else r = mid;
    }
    cout << l-1 << '\n';
    // cout << check(n, k, a, b, 3) << '\n';
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
        
}