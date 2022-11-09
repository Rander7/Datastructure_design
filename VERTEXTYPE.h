#pragma once
//头文件引入
#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#define MAXDISTANCE 32767                                   //表示两个景点间无路径，距离为无限
#define MAXSPOTS 50                                         //景点最大个数
#define MAXROAD 50                                          //最大道路数
#define MAXNAME 64                                          //景点名字
#define MAXINFORMATION 256                                  //景点信息说明最大容量
typedef int ROADTYPE;                                       //定义边的数据类型为int
using namespace std;

class VERTEXTYPE
{
protected:
    int m_number;                                           //景点编号
    char m_name[MAXNAME];                                   //景点名字
    char m_information[MAXINFORMATION];                     //景点介绍
    bool m_existence;                                       //景点是否还存在
public:
    VERTEXTYPE() {}
    VERTEXTYPE(int number, const char* name, const char* information, bool existence);
    ~VERTEXTYPE() {}
    int get_vex_number();                                   //返回景点下标
    char* get_vex_name();                                   //返回景名字
    char* get_vex_information();                            //返回景点信息
    bool get_vex_existence();                               //返回景点是否存在

    void change_vex_number(int number);                     //改变景点下标
    void change_vex_name(const char*name);                  //改变景点名字
    void change_vex_information(const char *information);   //改变景点信息
    void change_vex_existence(bool existence);              //改变景点存在状态

    void add_vertex();                                      //增加景点
    void del_vertex();                                      //删除景点
    void update_vertex();                                   //更新景点
};


