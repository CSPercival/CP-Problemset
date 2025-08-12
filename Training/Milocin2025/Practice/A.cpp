#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void game(ll n, ll m, ll *curr, ll *sec){
    // cout << "game " << n << " " << m << " " << (*curr) << " " << (*sec) << endl;
    if(n == 0) return;
    if(n == m){
        (*curr) += n * m;
        return;
    }
    ll ir = m/n;
    ll ircurr = (ir + 1)/2;
    ll irsec = ir - ircurr;
    if(ir&1){
        (*curr) += (n * n) * (ircurr);
        (*sec) += (n * n) * (irsec);
        game(m % n, n, sec, curr);
    } else {
        (*curr) += (n * n) * (ircurr);
        (*sec) += (n * n) * (irsec);
        game(m % n, n, curr, sec);
    }
}

bool check(ll n, ll m, ll p, ll q){
    // cout << "check " << n << " " << m << " " << p << " " << q << endl;
    ll ansp= 0, ansq = 0;
    if(n > m) swap(n,m);
    game(n, m, &ansp, &ansq);
    // cout << "check " << n << " " << m << " " << ansp << " " << ansq << endl;
    if(ansp == p && ansq == q) return true;
    return false;
}

void solve() {
    ll p, q;
    cin >> p >> q;
    ll sum = p + q;
    ll n,m;
    for(n = 1; n * n <= sum; n++){
        if(sum % n != 0) continue;
        m = sum / n;
        if(check(n, m, p, q)){
            cout << n << " " << m << "\n";\
            return;
        }
    }
    cout << "-1\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    
}