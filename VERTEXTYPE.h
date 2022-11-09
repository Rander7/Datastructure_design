#pragma once
//ͷ�ļ�����
#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#define MAXDISTANCE 32767                                   //��ʾ�����������·��������Ϊ����
#define MAXSPOTS 50                                         //����������
#define MAXROAD 50                                          //����·��
#define MAXNAME 64                                          //��������
#define MAXINFORMATION 256                                  //������Ϣ˵���������
typedef int ROADTYPE;                                       //����ߵ���������Ϊint
using namespace std;

class VERTEXTYPE
{
protected:
    int m_number;                                           //������
    char m_name[MAXNAME];                                   //��������
    char m_information[MAXINFORMATION];                     //�������
    bool m_existence;                                       //�����Ƿ񻹴���
public:
    VERTEXTYPE() {}
    VERTEXTYPE(int number, const char* name, const char* information, bool existence);
    ~VERTEXTYPE() {}
    int get_vex_number();                                   //���ؾ����±�
    char* get_vex_name();                                   //���ؾ�����
    char* get_vex_information();                            //���ؾ�����Ϣ
    bool get_vex_existence();                               //���ؾ����Ƿ����

    void change_vex_number(int number);                     //�ı侰���±�
    void change_vex_name(const char*name);                  //�ı侰������
    void change_vex_information(const char *information);   //�ı侰����Ϣ
    void change_vex_existence(bool existence);              //�ı侰�����״̬

    void add_vertex();                                      //���Ӿ���
    void del_vertex();                                      //ɾ������
    void update_vertex();                                   //���¾���
};


