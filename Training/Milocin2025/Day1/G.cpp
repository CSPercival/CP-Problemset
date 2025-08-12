#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, k;
vector<vector<int>> board;
vector<vector<int>> vis;
vector<vector<int>> deg;

bool git(pair<int, int> curr, int col)
{
    if (curr.st < 0 || n <= curr.st || curr.nd < 0 || m <= curr.nd || board[curr.st][curr.nd] != col || vis[curr.st][curr.nd])
        return false;
    return true;
}
bool git2(pair<int, int> curr)
{
    if (curr.st < 0 || n <= curr.st || curr.nd < 0 || m <= curr.nd)
        return false;
    return true;
}

void dfs(pair<int, int> curr, int col, vector<pair<int, int>> *w, vector<pair<int, int>> *b)
{
    vis[curr.st][curr.nd] = 1;
    w->push_back(curr);
    for (int i = 0; i < 4; i++)
    {
        if (git({curr.st + dx[i], curr.nd + dy[i]}, col))
        {
            dfs({curr.st + dx[i], curr.nd + dy[i]}, col, b, w);
        }
    }
}

int get_color(pair<int, int> curr)
{
    int gitc = 1;
    for (int col = 1; col <= 4; col++)
    {
        gitc = 1;
        for (int i = 0; i < 4; i++)
        {
            if (!git2({curr.st + dx[i], curr.nd + dy[i]}))
                continue;
            if (board[curr.st + dx[i]][curr.nd + dy[i]] == col)
            {
                gitc = 0;
                break;
            }
        }
        if (gitc)
            return col;
    }
    return 5;
}

bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi &B)
{
    if (A[a] != L)
        return 0;
    A[a] = -1;
    for (int b : g[a])
        if (B[b] == L + 1)
        {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
                return btoa[b] = a, 1;
        }
    return 0;
}
int hopcroftKarp(vector<vi> &g, vi &btoa)
{
    int res = 0;
    vi A(g.size()), B(btoa.size()), cur, next;
    for (;;)
    {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for (int a : btoa)
            if (a != -1)
                A[a] = -1;
        rep(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; lay++)
        {
            bool islast = 0;
            next.clear();
            for (int a : cur)
                for (int b : g[a])
                {
                    if (btoa[b] == -1)
                    {
                        B[b] = lay;
                        islast = 1;
                    }
                    else if (btoa[b] != a && !B[b])
                    {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            if (islast)
                break;
            if (next.empty())
                return res;
            for (int a : next)
                A[a] = lay;
            cur.swap(next);
        }
        rep(a, 0, sz(g))
            res += dfs(a, 0, g, btoa, A, B);
    }
}

vi cover(vector<vi> &g, int n, int m)
{
    vi match(m, -1);
    // int res = dfsMatching(g, match);
    int res = hopcroftKarp(g, match);
    vector<bool> lfound(n, true), seen(m);
    for (int it : match)
        if (it != -1)
            lfound[it] = false;
    vi q, cover;
    rep(i, 0, n) if (lfound[i]) q.push_back(i);
    while (!q.empty())
    {
        int i = q.back();
        q.pop_back();
        lfound[i] = 1;
        for (int e : g[i])
            if (!seen[e] && match[e] != -1)
            {
                seen[e] = true;
                q.push_back(match[e]);
            }
    }
    rep(i, 0, n) if (!lfound[i]) cover.push_back(i);
    rep(i, 0, m) if (seen[i]) cover.push_back(n + i);
    assert(sz(cover) == res);
    return cover;
}

vector<vector<int>> g;

void solve()
{
    cin >> n >> m >> k;
    g.resize(n * m + 10);
    board.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<int>(m, 0));
    deg = board;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<pair<int, int>> w, b;

    vector<pair<int, int>> left_side;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            w.clear();
            b.clear();
            if (!vis[i][j])
            {
                dfs({i, j}, board[i][j], &w, &b);
                if (w.size() > b.size())
                    for (auto p : b)
                        left_side.push_back(p);
                else
                    for (auto p : w)
                        left_side.push_back(p);
            }
        }
    }

    for (pair<int, int> p : left_side)
    {
        int i = p.st, j = p.nd;
        for (int k = 0; k < 4; k++)
        {
            if (git2({i + dx[k], j + dy[k]}) && board[i + dx[k]][j + dy[k]] == board[i][j])
            {
                g[i * m + j].push_back((i + dx[k]) * m + (j + dy[k]));
            }
        }
    }
    vector<int> nodes = cover(g, n * m, n * m);
    vector<pair<int, int>> change;
    for (int u : nodes)
    {
        if (u >= n * m)
            u -= n * m;
        change.push_back({u / m, u % m});
    }

    // cout << change.size() << "\n";
    for (auto p : change)
    {
        board[p.st][p.nd] = get_color(p);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}