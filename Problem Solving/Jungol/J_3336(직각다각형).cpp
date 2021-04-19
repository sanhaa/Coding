/*
2021-04-16
Jungol 3336
*/
#include <iostream>
#include <vector>
 
using namespace std;
 
struct Point {
    int x = 0;
    int y = 0;
    Point() {};
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
};
 
typedef pair<Point, Point> Line;
 
#define MAX_N 100000
#define INF 987654321
#define MAX(x, y) ((x)>(y))?(x):(y)
#define MIN(x, y) ((x)<(y))?(x):(y)
 
void print_Line(vector<Line> Line) {
    for (auto iter = Line.begin(); iter != Line.end();iter++) {
        cout << (*iter).first.x << " " << (*iter).first.y << " --- ";
        cout << (*iter).second.x << " " << (*iter).second.y << endl;
    }
}
 
 
int main() {
    int N = 0; cin >> N;
    Point start, prev, end;
 
    vector<Line> V_line;
    vector<Line> H_line;
    //vector<Line> line;
 
    cin >> start.x >> start.y;
    prev = start;
 
    int minx = start.x, maxx = start.x;
    int miny = start.y, maxy = start.y;
 
    for (int n = 1;n < N;n++) {
        Point now;
        cin >> now.x >> now.y;
        maxx = MAX(maxx, now.x);
        minx = MIN(minx, now.x);
 
        maxy = MAX(maxy, now.y);
        miny = MIN(miny, now.y);
 
        /*  Make Line  */ // 번갈아 가면서 수직 - 수평
        if (prev.x == now.x) { // 수직선
            if (prev.y < now.y) V_line.push_back(make_pair(prev, now));
            else V_line.push_back(make_pair(now, prev));
        }
        else {
            if (prev.x < now.x) H_line.push_back(make_pair(prev, now));
            else H_line.push_back(make_pair(now, prev));
        }
        prev = now;
    }
 
    // 마지막 선분
    if (prev.x == start.x) { // 수직선
        if (prev.y < start.y) V_line.push_back(make_pair(prev, start));
        else V_line.push_back(make_pair(start, prev));
    }
    else {
        if (prev.x < start.x) H_line.push_back(make_pair(prev, start));
        else H_line.push_back(make_pair(start, prev));
    }
 
    //cout << "Vertical line : " << endl;
    //print_Line(V_line);
 
    //cout << "Horizontal line : " << endl;
    //print_Line(H_line);
 
    //cout << minx << " ~ " << maxx << endl;
    //cout << miny << " ~ " << maxy << endl;
 
    /*  최대 교차점  */
    int v_max = 0, h_max = 0;
    int v = 0, h = 0; //  교차점 세기
 
    // 수직선으로 swipping
    for (int vertical_x = minx; vertical_x <= maxx; vertical_x++) {
        for (std::vector<Line>::iterator iter = H_line.begin(); iter != H_line.end();iter++) {
            if (vertical_x == (*iter).first.x) {
                v++;
            }
            else if (vertical_x == (*iter).second.x) {
                //iter = H_line.erase(iter);
                v--;
            }
            v_max = MAX(v_max, v);
        }
    }
 
    // 수평선으로 swipping
    for (int vertical_y = miny; vertical_y <= maxy; vertical_y++) {
        for (auto iter = V_line.begin(); iter != V_line.end();iter++) {
            if (vertical_y == (*iter).first.y) h++;
            else if (vertical_y == (*iter).second.y) {
                //iter = V_line.erase(iter);
                h--;
            }
            h_max = MAX(h_max, h);
        }
    }
 
    cout << (MAX(h_max, v_max)) << endl;
 
    return 0;
}
