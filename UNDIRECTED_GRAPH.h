#pragma once
#include"VERTEXTYPE.h"

class UNDIRECTED_GRAPH:public VERTEXTYPE                            //�̳о�����
{
private:
    VERTEXTYPE vertexs[MAXSPOTS];                                   //������ɵĶ�������
    ROADTYPE roads[MAXSPOTS][MAXSPOTS];                             //�����ڽӾ���
    int m_vertex_number;
    int m_road_number;                                              //��������ͱ���
public:
    friend class Window;                                            //Window����Ϊ��Ԫ

    UNDIRECTED_GRAPH() {}
    void init_UNDIRECTED_GRAPH();                                   //��ʼ���ڽӾ���

    int get_vertex_number();                                        //���ؾ����ܸ���
    int get_vertex_road_number();                                   //���ص�·�ܸ���

    void change_vertex_number(bool t);                              //�ı侰������
    void change_road_number(bool t);                                //�ı��·����

    void add_vertex(char name2[], char info2[]);                    //���Ӿ���
    void del_vertex(int x);                                         //ɾ������
    void update_vertex(int x, char name1[], char info1[]);          //���¾���

    int add_road(int x, int y, int weight);                         //���ӵ�·
    int del_road(int x, int y);                                     //ɾ����·
    int update_road(int x, int y, int weight);                      //���µ�·

    void search_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y);
    void search_all_the_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y);
    /*void dfs(int pos, int end, int min, int pass_by_temp_num);*/
    void dfs(int pos, int end, int min);

};

//�����������·���������,��������
extern int stack[MAXSPOTS];
extern bool visit[MAXSPOTS];                                        
extern int stack_top;
extern int path_array[MAXSPOTS][MAXSPOTS];
extern int short_path_array[MAXSPOTS][MAXSPOTS];
extern int pass_by[100];



