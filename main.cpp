#include <GL/glew.h>
#include <GL/freeglut.h>
#include <functional>
#include <bits/stdc++.h>
#include <windows.h>
#include "line.h"
#include "circle.h"
using namespace std;

int draw_tree(string& tree, int ind, int x, int y, int dir, vector<pair<int, int>>& direction, vector<pair<int, int>>& circle, vector<pair<int, int>>& points){
    int last_turn = 1;
    for(int i = ind;i<tree.length();i++){
        if(tree[i] == ']')
            return i;
        else if(tree[i] == '0'){
            compute_circle(x, y, 3, circle);
            compute_circle(x+1, y+1, 3, circle);
            compute_circle(x-1, y-1, 3, circle);
        }
        else if(tree[i] == '1'){
            compute_points(x, y, x + direction[dir].first, y + direction[dir].second, points);
            x = x + direction[dir].first;
            y = y + direction[dir].second;
        }
        else{
            if(last_turn == 1){
                i = draw_tree(tree, i + 1, x, y, (dir + 11)%12, direction, circle, points);
                last_turn = 0;
            }
            else{
                i = draw_tree(tree, i + 1, x, y, (dir + 1)%12, direction, circle, points);
                last_turn = 1;
            }
        }
    }
    return 0;
}

void render_plant_tree(){
    vector<pair<int, int>> direction{{0, 5}, {2, 4}, {4, 2}, {3, 0}, {4, -2}, {2, -4}, {0, -3}, {-2, -4}, {-4, -2}, {-3, 0}, {-4, 2}, {-2, 4}};
    vector<pair<int, int>> points;
    vector<pair<int, int>> circle;
    string zero = "1[0][0][0]1[0]0";
    string one = "11";
    vector<string> tree = {"0"};
    for(int i = 0;i<6;i++){
        draw_tree(tree[i], 0, 300, 300, 0, direction, points, circle);
        draw_from_vector(points);
        draw_from_plant_tree(circle);
        points.clear();
        circle.clear();
        string temp = "";
        for(int j = 0;j<tree[i].length();j++){
            if(tree[i][j] == '0')
                temp.append(zero);
            else if(tree[i][j] == '1')
                temp.append(one);
            else
                temp.push_back(tree[i][j]);
        }
        tree.push_back(temp);
    }
}

void render_small_tree(){
    vector<pair<int, int>> direction{{0, 3}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}, {0, -5}, {-2, -4}, {-4, -2}, {-5, 0}, {-4, 2}, {-2, 4}};
    vector<pair<int, int>> directionRoot{{-5, -5}, {-4, -4}, {-5, 0}, {-4, 2}, {-2, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}, {0, -5}};
    vector<pair<int, int>> directionRoot2{{0, -5}, {-3, -6}, {-6, -2}, {-5, 0}, {-4, 2}, {-4, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}};
    vector<pair<int, int>> directionRoot3{{4, -3}, {2, -4}, {0, -5}, {-3, -6}, {-4, -2}, {-5, 0}, {-4, 2}, {-2, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}};
    vector<pair<int, int>> points;
    vector<pair<int, int>> circle;
    string zero = "1[0][0]1[0]0";
    string one = "11";
    vector<string> tree = {"0"};
    for(int i = 0;i<8;i++){
        string temp = "";
        for(int j = 0;j<tree[i].length();j++){
            if(tree[i][j] == '0')
                temp.append(zero);
            else if(tree[i][j] == '1')
                temp.append(one);
            else
                temp.push_back(tree[i][j]);
        }
        tree.push_back(temp);
    }
    draw_tree(tree[6], 0, -400, 300, 0, direction, points, circle);
    draw_from_vector(points);
    draw_from_small_tree(circle);
    points.clear();
    circle.clear();
    draw_tree(tree[3], 0, -400, 300, 0, directionRoot, circle, points);
    draw_from_vector(points);
    points.clear();
    circle.clear();
    draw_tree(tree[3], 0, -400, 300, 0, directionRoot2, circle, points);
    draw_from_vector(points);
    points.clear();
    circle.clear();
    draw_tree(tree[3], 0, -400, 300, 0, directionRoot3, circle, points);
    draw_from_vector(points);
    points.clear();
    circle.clear();
}

void render_main_tree(){
    vector<pair<int, int>> direction{{0, 5}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}, {0, -5}, {-2, -4}, {-4, -2}, {-5, 0}, {-4, 2}, {-2, 4}};
    vector<pair<int, int>> directionRoot{{-5, -5}, {-4, -4}, {-5, 0}, {-4, 2}, {-2, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}, {0, -5}};
    vector<pair<int, int>> directionRoot2{{0, -5}, {-3, -6}, {-6, -2}, {-5, 0}, {-4, 2}, {-4, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}, {4, -2}, {2, -4}};
    vector<pair<int, int>> directionRoot3{{4, -3}, {2, -4}, {0, -5}, {-3, -6}, {-4, -2}, {-5, 0}, {-4, 2}, {-2, 4}, {0, 5}, {2, 4}, {4, 2}, {5, 0}};
    vector<pair<int, int>> points;
    vector<pair<int, int>> circle;
    string zero = "1[0]1[0]0";
    string one = "11";
    vector<string> tree = {"0"};
    compute_points(-500, 300, 500, 300, points);
    draw_from_vector(points);
    points.clear();
    for(int i = 0;i<7;i++){
        draw_tree(tree[i], 0, 0, 300, 0, direction, circle, points);
        draw_from_vector(points);
        draw_from_circle(circle);
        points.clear();
        circle.clear();
        if(i>=3){
            draw_tree(tree[i-3], 0, 0, 300, 0, directionRoot, circle, points);
            draw_from_vector(points);
            points.clear();
            circle.clear();
            draw_tree(tree[i-3], 0, 0, 300, 0, directionRoot2, circle, points);
            draw_from_vector(points);
            points.clear();
            circle.clear();
            draw_tree(tree[i-3], 0, 0, 300, 0, directionRoot3, circle, points);
            draw_from_vector(points);
            points.clear();
            circle.clear();
        }
        string temp = "";
        for(int j = 0;j<tree[i].length();j++){
            if(tree[i][j] == '0')
                temp.append(zero);
            else if(tree[i][j] == '1')
                temp.append(one);
            else
                temp.push_back(tree[i][j]);
        }
        tree.push_back(temp);
    }
}

void render_tree(){
    render_small_tree();
    render_main_tree();
    render_plant_tree();
}

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //left, top, bottom, right
    gluOrtho2D(-1500, 1500, 0, 1500);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500, 1200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line");
    glutDisplayFunc(render_tree);
    init();
    glutMainLoop();
    return 0;
}
