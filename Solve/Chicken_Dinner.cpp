#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;
typedef long double ld;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

struct Point{
    ld x,y;
    Point operator+(const Point& a){ return {x + a.x, y + a.y}; }
    Point operator-(const Point& a){ return {x - a.x, y - a.y}; }
    Point operator*(const ld d){ return {x * d, y * d}; }
    Point operator/(const ld d){ return {x / d, y / d}; }

    void print(){cout << "[Point: " << x << " " << y << "]\n";}
};

struct Line{
    ld A,B,C;
    Line(ld a,ld b,ld c){A = a; B = b; C = c;}
    Line(Point p1, Point p2){
        A = p1.y - p2.y;
        B = p2.x - p1.x;
        C = -A * p1.x - B * p1.y;
    }
    void print(){cout << "[Line: " << A << " " << B << " " << C << "]\n";}
};

struct Circle{
    Point c;
    ld r;
    void print(){cout << "[Circle: " << c.x << " " << c.y << " " << r << "]\n";}
};

struct BGeo{

    ld dot(Point a, Point b){ return a.x * b.x + a.y + b.y; }
    ld len(Point a){ return sqrt(a.x * a.x + a.y * a.y); }
    ld dist(Point a, Point b){ return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

    pair<Point,Point> intersection(Circle C, Line L){ return intersection(L,C);}
    pair<Point,Point> intersection(Line L, Circle C){
        Line tL(L.A,L.B,L.C + C.c.x * L.A + C.c.y * L.B);
        Point v1 = {tL.B * -1, tL.A};
        v1 = v1 / len(v1);

        Point proj = {(-1 * tL.C * tL.A) / (tL.A * tL.A + tL.B * tL.B), (-1 * tL.C * tL.B) / (tL.A * tL.A + tL.B * tL.B)};
        // proj.print();
        ld h = sqrt(C.r * C.r - proj.x * proj.x - proj.y * proj.y);
        return {proj + v1 * h + C.c, proj + v1 * -h + C.c};
    }

    Point arc_mid(Circle C, Point A, Point B){
        // if AB forms diameter it will cause error
        // Do not know what happens if arc AB takes more than half of a circle
        A = A - C.c;
        B = B - C.c;
        Point part_of_segment = A + (B - A)/2;
        Point proj = part_of_segment * (C.r / len(part_of_segment));
        return proj + C.c;
    }

    Point arc_near_third(Circle C, Point A, Point B){
        Point mid = arc_mid(C,A,B);
        return arc_mid(C,arc_mid(C,A,mid),mid);
    }
};

struct CTS{
    ld EPS = 1e-9;
    Point A,B;
    Circle C;
    ld (*costf)(Point);
    BGeo calc;

    CTS(Point p1, Point p2, Circle c1, ld (*in_costf)(Point)){
        A = p1; B = p2; C = c1; costf = in_costf;
    }

    Point find_best(int mode){ // mode 0 -> /-\, mode 1 -> \_/
        Point lmid, rmid;
        while(calc.dist(A,B) > EPS){
            lmid = calc.arc_near_third(C,A,B);
            rmid = calc.arc_near_third(C,B,A);
            if((int)(costf(lmid) < costf(rmid)) ^ mode){
                A = lmid;
            } else {
                B = rmid;
            }
        }
        return calc.arc_mid(C,A,B);
    }

};

void solve(){
    int x1,y1,r1,d1,t,x2,y2,r2,d2; cin >> x1 >> y1 >> r1 >> d1 >> t >> x2 >> y2 >> r2 >> d2;
    Circle big = {x1,y1,r1}, small = {x2,y2,r2};
    Point start = {0,0};
    Bgeo calc;
    if(calc.dist(start,small.c) <= small.r){
        cout << "0\n";
        return;
    }
    if(calc.dist(start,small.c) <= big.r){
        ld h2 = calc.dist(start,small.c) - small.r;
        if(h2 <= t){
            cout << "0\n";
        } else {
            cout << (h2 - t) * d2 << "\n";
        }
        return;
    }

    Line l1(start, big.c);
    Line l2(start, small.c);
    pair<Point, Point> tmpp1, tmpp2;
    Point p1, p2;
    tmpp1 = calc.intersection(big, l1);
    tmpp2 = calc.intersection(small, l2);
    p1 = (calc.len(tmpp1.st) < calc.len(tmpp1.nd) ? tmpp1.st : tmpp1.nd);
    p2 = (calc.len(tmpp2.st) < calc.len(tmpp2.nd) ? tmpp2.st : tmpp2.nd);

    ld cost_function = [](Point x){
        ld h1 = calc.len(x);
        ld h2 = calc.dist(x,small.c) - small.r;
        if(h1 >= t) return t * d1 + (h1 - t + h2) * d2;
        if(h1 + h2 <= t) return h1 * d1;
        return h1 * d1 + (h1 + h2 - t) * d2;
    };

    CTS algo(p1, p2, big, &cost_function);
    Point ans = algo.find_best(1);
    cout << cost_function(ans) << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
