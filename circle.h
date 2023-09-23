#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

using namespace std;

void draw_from_circle(vector<pair<int, int>>& circle){
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
        for(auto it:circle)
            glVertex2i(it.first,it.second);
    glEnd();
    glColor3f(1.0f,0.71f,.77f);
    glBegin(GL_POINTS);
        for(int i = 500; i<circle.size(); i+=500){
            for(int j = i; j<i+100; j++)
                glVertex2i(circle[j].first,circle[j].second);
        }
    glEnd();
    glFlush();
}

void draw_from_plant_tree(vector<pair<int, int>>& circle){
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.043f, 0.412f, 0.122f);
    glBegin(GL_POINTS);
        for(auto it:circle)
            glVertex2i(it.first,it.second);
    glEnd();
    glColor3f(0.459f, 0.949f, 0.565f);
    glBegin(GL_POINTS);
        for(int i = 500; i<circle.size(); i+=500){
            for(int j = i; j<i+100; j++)
                glVertex2i(circle[j].first,circle[j].second);
        }
    glEnd();
    glFlush();
}

void draw_from_small_tree(vector<pair<int, int>>& circle){
    glColor3f(1.0f, 0.882f, 0.11f);
    glBegin(GL_POINTS);
        for(auto it:circle)
            glVertex2i(it.first,it.second);
    glEnd();
    glColor3f(0.98f, 0.165f, 0.165f);
    glBegin(GL_POINTS);
        for(int i = 500; i<circle.size(); i+=1000){
            for(int j = i; j<i+50; j++)
                glVertex2i(circle[j].first,circle[j].second);
        }
    glEnd();
    glFlush();
}

void compute_circle(int x0, int y0, int rad, vector<pair<int, int>>& circle){
    int x = 0, y = rad;
    int d = 1 - rad;
    int de = 3;
    int dse = -2*rad + 5;
    while(y > x){
        if(d < 0){
            d = d + de;
            de = de + 2;
            dse = dse + 2;
        }
        else{
            d = d + dse;
            de = de + 2;
            dse = dse + 4;
            y--;
        }
        x++;
        circle.push_back({x + x0, y + y0});
        circle.push_back({y + x0, x + y0});
        circle.push_back({x + x0, -y + y0});
        circle.push_back({y + x0, -x + y0});
        circle.push_back({-x + x0, y + y0});
        circle.push_back({-y + x0, x + y0});
        circle.push_back({-x + x0, -y + y0});
        circle.push_back({-y + x0, -x + y0});
    }
}

#endif // CIRCLE_H_INCLUDED
