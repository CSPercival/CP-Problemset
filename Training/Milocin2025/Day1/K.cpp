#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int kk = k;
    vector<int> a(n), pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    if (k == 1) {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    vector<bool> s(n);
    int it = 1;
    while (it <= n) {
        if (pos[it] == it-1) {
            it++;
            continue;
        }
        if (!s[pos[it]] && !s[it-1]) {
            if (k < 2) break;
            s[pos[it]] = s[it-1] = true;
            k-=2;
        }
        else if (!s[pos[it]]) {
            if (k < 1) break;
            s[pos[it]] = true;
            k -= 1;
        }
        else if (!s[it-1]) {
            if (k < 1) break;
            s[it-1] = true;
            k-= 1;
        }
        it++;
    }
    if (it == n+1) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> picked;
    for (int i = 0; i < n; i++) {
        if (s[i]) picked.push_back(a[i]);
    }
    sort(picked.begin(), picked.end());
    int q = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]) a[i] = picked[q++];
    }

    if (k == 0) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    assert(a[it-1] != it);
    vector<int> suf(n+1), sufp(n+1);
    suf[n] = sufp[n] = n+1;
    for (int i = n-1; i >= 0; i--) {
        suf[i] = min(suf[i+1], a[i]);
        if (s[i]) sufp[i] = min(sufp[i+1], a[i]);
        else sufp[i] = sufp[i+1];
    }
    for (int i = it-1; i < n; i++) {
        if (s[i]) {
            if (suf[i+1] < a[i]) {
                int x = suf[i+1];
                int j;
                for (j = i+1; j < n; j++) if (a[j] == x) break;
                s[j] = true;
                break;
            }
        }
        else {
            if (sufp[i+1] < a[i]) {
                s[i] = true;
                break;
            }
        }
    }

    picked.clear();
    for (int i = 0; i < n; i++) {
        if (s[i]) picked.push_back(a[i]);
    }
    sort(picked.begin(), picked.end());
    assert(picked.size() <= kk);
    q = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]) a[i] = picked[q++];
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
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