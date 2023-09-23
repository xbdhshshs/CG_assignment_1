#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

using namespace std;

void draw_from_vector(vector<pair<int, int>>& points){
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.58f, 0.29f, 0.0f);
    glBegin(GL_POINTS);
        for(auto it:points)
            glVertex2i(it.first,it.second);
    glEnd();
    glFlush();
}

void compute_points(int x0, int y0, int x1, int y1, vector<pair<int, int>>& points){
    if(y0 > y1){
        swap(y0, y1);
        swap(x0, x1);
    }
    if(y0 == y1){
        if(x1 < x0)
            swap(x0, x1);
        while(x0 < x1){
            points.push_back({x0, y0});
            x0++;
        }
    }
    else if(x0 == x1){
        if(y1 < y0)
            swap(y0, y1);
        while(y0 < y1){
            points.push_back({x0, y0});
            y0++;
        }
    }
    else if(y1 - y0 > 0 && x1 - x0 > 0 && y1 - y0 <= x1 - x0){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int d = 2*dy - dx;
        int incrE = 2*dy;
        int increNe = 2*(dy - dx);
        int x = x0, y = y0;
        points.push_back({x, y});
        while(x < x1){
            if(d <= 0){
                d = d + incrE;
            }
            else{
                d = d + increNe;
                y++;
            }
            x++;
            points.push_back({x, y});
        }
    }
    else if(y1 - y0 > 0 && x1 - x0 > 0 && y1 - y0 > x1 - x0){
        swap(x0, y0);
        swap(x1, y1);
        int dx = x1 - x0;
        int dy  =y1 - y0;
        int d = 2*dy - dx;
        int incrE = 2*dy;
        int increNe = 2*(dy - dx);
        int x = x0, y = y0;
        points.push_back({y, x});
        while(x < x1){
            if(d <= 0){
                d = d + incrE;
            }
            else{
                d = d + increNe;
                y++;
            }
            x++;
            points.push_back({y, x});
        }
    }
    else if(abs(y1 - y0) <= abs(x1 - x0)){
        x0 = -x0;
        x1 = -x1;
        int dx = x1 - x0;
        int dy  =y1 - y0;
        int d = 2*dy - dx;
        int incrE = 2*dy;
        int increNe = 2*(dy - dx);
        int x = x0, y = y0;
        points.push_back({-x, y});
        while(x < x1){
            if(d <= 0){
                d = d + incrE;
            }
            else{
                d = d + increNe;
                y++;
            }
            x++;
            points.push_back({-x, y});
        }
    }
    else{
        x0 = -x0;
        x1 = -x1;
        swap(x0, y0);
        swap(x1, y1);
        int dx = x1 - x0;
        int dy  =y1 - y0;
        int d = 2*dy - dx;
        int incrE = 2*dy;
        int increNe = 2*(dy - dx);
        int x = x0, y = y0;
        points.push_back({-y, x});
        while(x < x1){
            if(d <= 0){
                d = d + incrE;
            }
            else{
                d = d + increNe;
                y++;
            }
            x++;
            points.push_back({-y, x});
        }
    }
    return;
}

#endif // LINE_H_INCLUDED
