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

	void show() const;										// 显示窗口
	void messageLoop();										// 消息循环
	void close();											// 关闭窗口

	void showMainWindow();									// 显示主窗口

	void showMessage();										// 地图界面提示信息展示
	void searchMessage();									// 搜索界面提示信息展示
	void search_pathMessage();								//搜索界面搜索最短路径信息展示
	void editMessage();										// 编辑界面提示信息展示

	void showMap();											// 显示地图窗口   
	void showSearch();										// 显示搜索窗口
	void showEditMap();										// 显示编辑窗口

	int viewJudgeButton();
	int viewJudgeButton_edit();
	int searchJudgeButton(int& s, int& f);
	int editJudgeButton(int& s, int& f);

	void showLine(int x1, int y1, int x2, int y2, int color);

	void update_Button(Button* button, char s[10]);
	void add_Button(UNDIRECTED_GRAPH& G, int x, int y, int width, int height, char s[10]);

	void show_all_path();

public:
	// 窗口状态标识，每个状态代表了一个界面
	enum WindowState { mainWindow, map, editMap, Search };
	Button* update_button;

private:
	// 主窗口按钮
	Button* mainWindow_view;
	Button* mainWindow_edit;
	Button* mainWindow_exit;
	Button* mainWindow_search;
	// 地图窗口按钮
	Button* viewMap_message;
	Button* viewMap_back;
	// 搜索窗口按钮
	Button* search_back;
	Button* search_message;
	Button* search_search_path;
	Button* search_show_all_path;
	// 修改窗口按钮
	Button* editMap_add_vex;
	Button* editMap_delete_vex;
	Button* editMap_update_vex;
	Button* editMap_add_road;
	Button* editMap_delete_road;
	Button* editMap_update_road;
	Button* editMap_message;
	Button* editMap_back;
	Button* editMap_show_all_path;
	// 景点按钮
	Button* button[20];
	// 窗口状态
	WindowState state;							
};