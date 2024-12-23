#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
// typedef long double ld;
typedef long long ll;
// #define ld ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }


struct Point{
    ll x,y;
    Point operator+(const Point& a){ return {x + a.x, y + a.y}; }
    Point operator-(const Point& a){ return {x - a.x, y - a.y}; }
    // Point operator*(const ld d){ return {x * d, y * d}; }
    // Point operator/(const ld d){ return {x / d, y / d}; }
    bool operator==(const Point& a){ return ((x == a.x) && (y == a.y));}
    bool operator!=(const Point& a){ return ((x != a.x) || (y != a.y));}

    void print(){cout << "[Point: " << x << " " << y << "]\n";}
};

ll cross(Point a, Point b){ return (a.x * b.y) - (a.y * b.x); }
bool collinear(Point a, Point b, Point c){ return (cross(b - a, c - b) == 0); }

int msng(int x){
    if(x > 0) return 1;
    if(x == 0) return 0;
    return -1;
}

bool check_col2(Point a, Point b, Point c){
    b = b - a;
    c = c - a;
    if(msng(b.x) == msng(c.x) && msng(b.y) == msng(c.y)) return true;
    return false;
}

void print_ans(Point a, Point b, Point c, Point d, Point e){
    cout << a.x << " " << a.y << "\n";
    cout << b.x << " " << b.y << "\n";
    cout << c.x << " " << c.y << "\n";
    cout << d.x << " " << d.y << "\n";
    cout << e.x << " " << e.y << "\n";
}

bool find_lines(Point start, vector<Point> &P, vector<vector<Point>> &lines){
    for(int i = 0; i < P.size(); i++){
        if(P[i] == start) continue;
        for(int j = 0; j < 4; j++){
            if(lines[j].empty()){
                lines[j].push_back(P[i]);
                break;
            }
            if(collinear(start,lines[j][0],P[i]) && check_col2(start,lines[j][0],P[i])){
                lines[j].push_back(P[i]);
                break;
            }
        }
        if(!lines[3].empty()) break;
    }

    // cout << "start:  ";
    // start.print();
    // for(int i = 0; i < 4; i++){
    //     for(auto j : lines[i]){
    //         j.print();
    //     }
    //     cout << endl;
    // }

    if(!lines[3].empty()){
        return true;
    }
    return false;
}

void brute_force(vector<Point> &P){
    for(auto i : P){
        vector<vector<Point>> lines(4);
        if(find_lines(i,P,lines)){
            cout << "YES\n";
            print_ans(i,lines[0][0],lines[1][0],lines[2][0],lines[3][0]);
            return;
        }
    }
    cout << "NO\n";
    return;
}

void solve(){
    int n; cin >> n;
    vector<Point> P;
    int x,y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        P.push_back({x,y});
    }
    if(n < 5){
        cout << "NO\n";
        return;
    }
    if(n <= 20){
        brute_force(P);
        return;
    }

    Point start = P[0];
    int start_idx = 0;
    for(int i = 1; i < n; i++){
        if(P[i].x < start.x || (P[i].x == start.x && P[i].y < start.y)){
            start = P[i];
            start_idx = i;
        }
    }
    swap(P[0],P[start_idx]);

    vector<vector<Point>> lines(4);
    find_lines(P[0],P,lines);

    // lines[0].push_back(P[1]);
    // for(int i = 2; i < n; i++){
    //     for(int j = 0; j < 4; j++){
    //         if(lines[j].empty()){
    //             lines[j].push_back(P[i]);
    //             break;
    //         }
    //         if(collinear(P[0],lines[j][0],P[i])){
    //             lines[j].push_back(P[i]);
    //             break;
    //         }
    //     }
    //     if(!lines[3].empty()) break;
    // }

    // cout << "start:  ";
    // start.print();
    // for(int i = 0; i < 4; i++){
    //     for(auto j : lines[i]){
    //         j.print();
    //     }
    //     cout << endl;
    // }

    if(lines[1].empty()){
        cout << "NO\n";
        return;
    }
    if(!lines[3].empty()){
        cout << "YES\n";
        print_ans(P[0],lines[0][0],lines[1][0],lines[2][0],lines[3][0]);
        return;
    }

    int tidx = -1;
    for(int i = 0; i < 4; i++){
        if(lines[i].size() >= 4){
            tidx = i;
            break;
        }
    }
    if(tidx == -1){
        cout << "NO\n";
        return;
    }
    int tidx2 = tidx - 1;
    if(tidx2 == -1) tidx2 = 1;
    cout << "YES\n";
    print_ans(lines[tidx2][0],lines[tidx][0],lines[tidx][1],lines[tidx][2],lines[tidx][3]);
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}