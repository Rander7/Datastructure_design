#pragma once
#include"VERTEXTYPE.h"

class UNDIRECTED_GRAPH:public VERTEXTYPE                            //继承景点类
{
private:
    VERTEXTYPE vertexs[MAXSPOTS];                                   //景点组成的顶点数组
    ROADTYPE roads[MAXSPOTS][MAXSPOTS];                             //构建邻接矩阵
    int m_vertex_number;
    int m_road_number;                                              //景点个数和边数
public:
    friend class Window;                                            //Window类作为友元

    UNDIRECTED_GRAPH() {}
    void init_UNDIRECTED_GRAPH();                                   //初始化邻接矩阵

    int get_vertex_number();                                        //返回景点总个数
    int get_vertex_road_number();                                   //返回道路总个数

    void change_vertex_number(bool t);                              //改变景点总数
    void change_road_number(bool t);                                //改变道路总数

    void add_vertex(char name2[], char info2[]);                    //增加景点
    void del_vertex(int x);                                         //删除景点
    void update_vertex(int x, char name1[], char info1[]);          //更新景点

    int add_road(int x, int y, int weight);                         //增加道路
    int del_road(int x, int y);                                     //删除道路
    int update_road(int x, int y, int weight);                      //更新道路

    void search_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y);
    void search_all_the_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y);
    /*void dfs(int pos, int end, int min, int pass_by_temp_num);*/
    void dfs(int pos, int end, int min);

};

//搜索所有最短路径相关数组,变量声明
extern int stack[MAXSPOTS];
extern bool visit[MAXSPOTS];                                        
extern int stack_top;
extern int path_array[MAXSPOTS][MAXSPOTS];
extern int short_path_array[MAXSPOTS][MAXSPOTS];
extern int pass_by[100];



