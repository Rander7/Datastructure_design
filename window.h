#pragma once
#include "widget.h"
#include "button.h"
#include"UNDIRECTED_GRAPH.h"
#define BACKGROUND_IMAGE "background.jpg"
#define MAP_IMAGE "map.png"

class Window :public Widget
{
public:
	friend class UNDIRECTED_GRAPH;
	Window(const int& width = 600, const int& height = 400);

	void show() const;										// ��ʾ����
	void messageLoop();										// ��Ϣѭ��
	void close();											// �رմ���

	void showMainWindow();									// ��ʾ������

	void showMessage();										// ��ͼ������ʾ��Ϣչʾ
	void searchMessage();									// ����������ʾ��Ϣչʾ
	void search_pathMessage();								//���������������·����Ϣչʾ
	void editMessage();										// �༭������ʾ��Ϣչʾ

	void showMap();											// ��ʾ��ͼ����   
	void showSearch();										// ��ʾ��������
	void showEditMap();										// ��ʾ�༭����

	int viewJudgeButton();
	int viewJudgeButton_edit();
	int searchJudgeButton(int& s, int& f);
	int editJudgeButton(int& s, int& f);

	void showLine(int x1, int y1, int x2, int y2, int color);

	void update_Button(Button* button, char s[10]);
	void add_Button(UNDIRECTED_GRAPH& G, int x, int y, int width, int height, char s[10]);

	void show_all_path();

public:
	// ����״̬��ʶ��ÿ��״̬������һ������
	enum WindowState { mainWindow, map, editMap, Search };
	Button* update_button;

private:
	// �����ڰ�ť
	Button* mainWindow_view;
	Button* mainWindow_edit;
	Button* mainWindow_exit;
	Button* mainWindow_search;
	// ��ͼ���ڰ�ť
	Button* viewMap_message;
	Button* viewMap_back;
	// �������ڰ�ť
	Button* search_back;
	Button* search_message;
	Button* search_search_path;
	Button* search_show_all_path;
	// �޸Ĵ��ڰ�ť
	Button* editMap_add_vex;
	Button* editMap_delete_vex;
	Button* editMap_update_vex;
	Button* editMap_add_road;
	Button* editMap_delete_road;
	Button* editMap_update_road;
	Button* editMap_message;
	Button* editMap_back;
	Button* editMap_show_all_path;
	// ���㰴ť
	Button* button[20];
	// ����״̬
	WindowState state;							
};