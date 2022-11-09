#include"window.h"
#include<graphics.h>
#include<conio.h>

UNDIRECTED_GRAPH G;										// 先实例化无向图类

Window::Window(const int& width, const int& height) : Widget(0, 0, width, height)
{
	G.init_UNDIRECTED_GRAPH();							// 创建以学校景点和道路构建的邻接矩阵
	show();

	// 设置绘图样式
	LOGFONT f;											// 字体的属性
	gettextstyle(&f);									// 获取当前文字样式 LOGFONT 结构体的指针。
	f.lfQuality = ANTIALIASED_QUALITY;					// 指定文字的输出质量
	settextstyle(&f);									// 设置当前文字样式
	settextcolor(BLACK);								// 字体颜色
	setbkmode(TRANSPARENT);								// 设置当前设备图案填充和文字输出时的背景模式 透明
	setlinecolor(BLACK);								// 设置当前设备画线颜色

	// 创建主窗口按钮
	mainWindow_view = new Button(250, 200, 150, 40, "查看地图");
	mainWindow_search = new Button(250, 260, 150, 40, "查询路径");
	mainWindow_edit = new Button(250, 320, 150, 40, "更改景点");
	mainWindow_exit = new Button(250, 380, 150, 40, "退出程序");

	// 创建地图窗口按钮
	viewMap_message = new Button(850, 600, 120, 40, "使用提示");
	viewMap_back = new Button(850, 650, 120, 40, "返回");

	// 创建搜索窗口按钮
	search_message = new Button(850, 600, 120, 40, "使用提示");
	search_back = new Button(850, 650, 120, 40, "返回");

	// 创建修改窗口按钮
	editMap_update_vex = new Button(850, 400, 120, 40, "更新景点");
	editMap_add_vex = new Button(850, 450, 120, 40, "添加景点");
	editMap_delete_vex = new Button(850, 500, 120, 40, "删除景点");
	editMap_update_road = new Button(850, 550, 120, 40, "更新道路");
	editMap_add_road = new Button(850, 600, 120, 40, "添加道路");
	editMap_delete_road = new Button(850, 650, 120, 40, "删除道路");
	editMap_message = new Button(850, 700, 120, 40, "使用提示");
	editMap_back = new Button(850, 750, 120, 40, "返回");

	// 创建景点按钮
	button[0] = new Button(115, 140, 95, 42, "家属楼");
	button[1] = new Button(315, 100, 95, 42, "勤学楼");
	button[2] = new Button(700, 195, 75, 42, "宿舍");
	button[3] = new Button(697, 110, 95, 42, "网球场");
	button[4] = new Button(345, 327, 95, 42, "育贤楼");
	button[5] = new Button(526, 305, 75, 42, "大活");
	button[6] = new Button(628, 340, 95, 42, "润泽园");
	button[7] = new Button(90, 258, 125, 42, "宁远车队");
	button[8] = new Button(225, 383, 95, 42, "图书馆");
	button[9] = new Button(215, 490, 95, 42, "博远楼");
	button[10] = new Button(315, 518, 95, 42, "汇贤楼");
	button[11] = new Button(622, 415, 95, 42, "运动场");
	button[12] = new Button(680, 487, 95, 42, "排球场");
	button[13] = new Button(470, 660, 75, 42, "大门");

	showMainWindow();									// 显示主界面
}

void Window::update_Button(Button* button, char s[])
{
	button->setText(s);
}

int Window::viewJudgeButton()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage();
		for (int i = 0; i < G.m_vertex_number; i++)
		{
			if (button[i]->state(msg))
			{
				return i;
			}
			else if (viewMap_message->state(msg))
			{
				showMessage();
				return -1;
			}
			else if (viewMap_back->state(msg))
			{
				showMainWindow();
				return -1;
			}
		}
	}
}

int Window::viewJudgeButton_edit()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage();
		for (int i = 0; i < G.m_vertex_number; i++)
		{
			if (button[i]->state(msg))
			{
				return i;
			}
			else if (editMap_message->state(msg))
			{
				editMap_message->show();
				return -1;
			}
			else if (editMap_back->state(msg))
			{
				showMainWindow();
				return -1;
			}
		}
	}
}

int Window::searchJudgeButton(int& s, int& f)
{
	ExMessage msg;
	int flag = 1;
	while (1)
	{
		msg = getmessage();
		if (flag == 1) {
			for (int i = 0; i < G.m_vertex_number; i++)
			{
				if (button[i]->state(msg) && msg.message != WM_LBUTTONUP)
				{
					s = i;
					flag++;
				}
				else if (search_message->state(msg))
				{
					searchMessage();
					return 0;
				}
				else if (search_back->state(msg))
				{
					showMainWindow();
					return 0;
				}
			}
		}
		else if (flag == 2)
		{
			for (int i = 0; i < G.m_vertex_number; i++)
			{
				if (button[i]->state(msg) && msg.message != WM_LBUTTONUP)
				{
					f = i;
					return 1;
				}
				else if (search_message->state(msg))
				{
					searchMessage();
					return 0;
				}
				else if (search_back->state(msg))
				{
					showMainWindow();
					return 0;
				}
			}
		}
	}
}


int Window::editJudgeButton(int& s, int& f)
{
	ExMessage msg;
	int flag = 1;
	while (1)
	{
		msg = getmessage();
		if (flag == 1) {
			for (int i = 0; i < G.m_vertex_number; i++)
			{
				if (button[i]->state(msg) && msg.message != WM_LBUTTONUP)
				{
					s = i;
					flag++;
				}
				else if (editMap_message->state(msg))
				{
					editMessage();
					return 0;
				}
				else if (editMap_back->state(msg))
				{
					showMainWindow();
					return 0;
				}
			}
		}
		else if (flag == 2)
		{
			for (int i = 0; i < G.m_vertex_number; i++)
			{
				if (button[i]->state(msg) && msg.message != WM_LBUTTONUP)
				{
					f = i;
					return 1;
				}
				else if (editMap_message->state(msg))
				{
					editMessage();
					return 0;
				}
				else if (editMap_back->state(msg))
				{
					showMainWindow();
					return 0;
				}
			}
		}
	}
}

int color[4] = { 0xFFFF55,0x55FF55,0xFF5555,0x5555FF };
void Window::showLine(int x1, int y1, int x2, int y2,int color)
{
	//画线的4种延伸方向状态
	if (x1 <= x2 && y1 <= y2)
	{
		for (double x = x1 + 50; x <= x2 + 50; x += 0.05)
		{
			for (double y = y1 + 20; y <= y2 + 20; y += 0.05)
			{
				if (fabs((x1 - x2) * (y - y1 - 20) - (y1 - y2) * (x - x1 - 50)) <= (x2 - x1) + (y2 - y1))
					putpixel(x, y, color);
			}
		}
	}
	if (x1 >= x2 && y1 >= y2)
	{
		for (double x = x1 + 50; x >= x2 + 50; x -= 0.05)
		{
			for (double y = y1 + 20; y >= y2 + 20; y -= 0.05)
			{
				if (fabs((x1 - x2) * (y - y1 - 20) - (y1 - y2) * (x - x1 - 50)) <= (x1 - x2) + (y1 - y2))
					putpixel(x, y, color);
			}
		}
	}
	if (x1 <= x2 && y1 >= y2)
	{
		for (double x = x1 + 50; x <= x2 + 50; x += 0.05)
		{
			for (double y = y1 + 20; y >= y2 + 20; y -= 0.05)
			{
				if (fabs((x1 - x2) * (y - y1 - 20) - (y1 - y2) * (x - x1 - 50)) <= (x2 - x1) + (y1 - y2))
					putpixel(x, y, color);
			}
		}
	}
	if (x1 >= x2 && y1 <= y2)
	{
		for (double x = x1 + 50; x >= x2 + 50; x -= 0.05)
		{
			for (double y = y1 + 20; y <= y2 + 20; y += 0.05)
			{
				if (fabs((x1 - x2) * (y - y1 - 20) - (y1 - y2) * (x - x1 - 50)) <= (x1 - x2) + (y2 - y1))
					putpixel(x, y, color);
			}
		}
	}
}

void Window::show() const
{
	// 新建窗口
	SetWindowText(initgraph(width, height, NULL), "校园导游系统");	//设置窗口标题
	setbkcolor(WHITE);
	cleardevice();
}

void Window::messageLoop()
{
	// 开启消息循环
	ExMessage msg;
	while (true)
	{
		// 获取并判断消息
		msg = getmessage();//用于获取一个消息。如果当前消息队列中没有，就一直等待

		// 判断显示界面
		if (state == WindowState::mainWindow)									// 主窗口显示
		{
			if (mainWindow_view->state(msg))									// 查看地图
			{
				showMap();
			}
			else if (mainWindow_edit->state(msg))								// 编辑景点
			{
				showEditMap();
			}
			else if (mainWindow_search->state(msg))								// 查询路径
			{
				showSearch();
			}
			else if (mainWindow_exit->state(msg) && msg.message != WM_LBUTTONUP)// 退出程序
			{
				return;															// 直接return返回主函数
			}
		}
		else if (state == WindowState::map)										// 查看地图
		{
			if (viewMap_message->state(msg))
			{
				showMessage();//展示提示信息
			}
			else if (viewMap_back->state(msg))									// 返回主窗口
			{
				showMainWindow();
			}
			else 
			{
				int n = viewJudgeButton();
				if (n >= 0)
				{
					MessageBox(GetHWnd(), G.vertexs[n].get_vex_information(), "景点信息", MB_OK);
				}
			}

		}
		else if (state == WindowState::Search)
		{
			if (search_back->state(msg))
			{
				showMainWindow();
			}
			else if (search_message->state(msg))
			{
				searchMessage();
			}
			else
			{
				int start, finish;
				if (searchJudgeButton(start, finish))
				{
					G.search_all_the_short_path(path_array, short_path_array, start, finish);
					int cnt=0;													//计算每一个最短路径景点数
					int c = 0;													//控制显示路线的颜色
					for (int i = 0; pass_by[i]!= -1; i+=(cnt+1))
					{
						cnt = 0;
						for (int j = i; pass_by[j] != -1; j++)
						{
							cnt++;
						}
						for (int k = i; k < i + cnt - 1; k++)
						{
							showLine(button[pass_by[k]]->getX(), button[pass_by[k]]->getY(), button[pass_by[k + 1]]->getX(), button[pass_by[k + 1]]->getY(), color[c % 4]);
						}
						c++;
					}
					if (cnt != 0)												// 展示线路并暂停、刷新
					{
						system("pause");
						cleardevice();
						loadimage(NULL, MAP_IMAGE, 1000, 800);
					}
				}
			}
		}
		else if (state == WindowState::editMap)
		{
			if (editMap_back->state(msg))
			{
				showMainWindow();
			}
			else if (editMap_message->state(msg))
			{
				editMessage();
			}
			else if (editMap_update_vex->state(msg))
			{
				int n = viewJudgeButton_edit();
				if (n >= 0)
				{
					MessageBox(GetHWnd(), "请输入要更新的景点名和信息", "操作提示", MB_OK);
					char s1[50];
					char s2[50];
					int flag1 = 0;
					int flag2 = 0;
					int id1=MessageBox(GetHWnd(), "要更新景点名吗", "操作提示", MB_YESNO);
					if (IDYES == id1)
					{
						InputBox(s1, 50, "请输入新景点名");
						update_Button(button[n], s1);								//更新显示的按钮名字
						Window::showEditMap();										//刷新更新后的按钮
						flag1= 1;
					}
					int id2 = MessageBox(GetHWnd(), "要更新景点信息吗", "操作提示", MB_YESNO);
					if (IDYES == id2)
					{
						InputBox(s2, 50, "请输入景点信息");
						flag2 = 2;
					}
					if (flag1 || flag2)
					{
						MessageBox(GetHWnd(), "该景点相关信息已更新", "操作提示", MB_OK);
						G.update_vertex(n, s1, s2,flag1+flag2);
					}
					showEditMap();
				}
			}
			else if (editMap_add_vex->state(msg))
			{
				MessageBox(GetHWnd(), "请输入景点名和信息后点击景点位置", "操作提示", MB_OK);
				char s1[50] = {0};
				char s2[50];
				InputBox(s1, 50, "请输入新景点名");
				InputBox(s2, 50, "请输入景点介绍");
				G.add_vertex(s1, s2);
				int length = 0;
				for (int i = 0; s1[i] != 0; i++)
				{
					length++;
				}
				MessageBox(GetHWnd(), "请在图中选择新增景点的位置", "操作提示", MB_OK);
				while (1)
				{
					ExMessage m = getmessage(EX_MOUSE);
					if (m.message == WM_LBUTTONDOWN)
					{
						button[G.m_vertex_number - 1] = new Button(m.x - length * 5 - 20, m.y - 20, length * 10 + 35, 40, s1);
						showEditMap();
						MessageBox(GetHWnd(), "该景点已增加", "操作完成", MB_OK);
						break;
					}
				}
						
			}
			else if (editMap_delete_vex->state(msg))
			{
				MessageBox(GetHWnd(), "请在图中选择想要删除的景点", "操作提示", MB_OK);
				int n = viewJudgeButton_edit();
				if (n >= 0)
				{
					int id = MessageBox(GetHWnd(), "确定删除该景点吗", "操作提示", MB_YESNO);
					if (id == IDYES)
					{
						G.del_vertex(n);
						button[n] = new Button(0, 0, 0, 0, "0");
						showEditMap();
					}
					else if (id == IDNO)
					{
						showEditMap();
					}
				}
			}
			else if (editMap_update_road->state(msg))
			{
				MessageBox(GetHWnd(), "请在图中选择两个景点以更新之间的道路", "操作提示", MB_OK);
				int start, finish;
				if (editJudgeButton(start, finish))
				{
					char s[10];
					int weight = 0;
					if (G.update_road(start, finish, weight))
					{
						InputBox(s, 10, "请输入道路长度");
						int weight = atoi(s);									//char*转int
						G.update_road(start, finish, weight);
						MessageBox(GetHWnd(), "该道路已更新", "操作完成", MB_OK);
					}
					else
					{
						int id=MessageBox(GetHWnd(), "该道路不存在，是否增加道路?", "操作", MB_YESNO);
						if (IDYES == id)
						{
							InputBox(s, 10, "请输入道路长度");
							weight = atoi(s);									//char*转int
							G.add_road(start, finish, weight);
							MessageBox(GetHWnd(), "该道路已增加", "操作完成", MB_OK);
						}
						else if(IDNO==id)
						{
							showEditMap();
						}
					}
				}
			}
			else if (editMap_add_road->state(msg))
			{
				MessageBox(GetHWnd(), "请在图中选择两个景点以添加之间的道路", "操作提示", MB_OK);
				int start, finish;
				if (editJudgeButton(start, finish))
				{

					char s[10];
					int weight = 0;
					if (G.add_road(start, finish, weight))
					{
						InputBox(s, 10, "请输入道路长度");
						weight = atoi(s);										//char*转int
						G.add_road(start, finish, weight);
						MessageBox(GetHWnd(), "该道路已增加", "操作完成", MB_OK);
					}
					else
					{
						int id=MessageBox(GetHWnd(), "该道路已经存在，是否要更新该道路的权值?", "操作提示", MB_YESNO);
						if (IDYES == id)
						{
							InputBox(s, 10, "请输入道路长度");
							int weight = atoi(s);								//char*转int
							G.update_road(start, finish, weight);
							MessageBox(GetHWnd(), "该道路已更新", "操作完成", MB_OK);
						}
						else if(IDNO==id)
						{
							showEditMap();
						}
					}
				}
			}
			else if (editMap_delete_road->state(msg))
			{
			MessageBox(GetHWnd(), "请在图中选择两个景点以删除之间的道路", "操作提示", MB_OK);
			int start, finish;
				if (editJudgeButton(start, finish))
				{
					if (G.del_road(start,finish))
						MessageBox(GetHWnd(), "该道路已删除", "操作完成", MB_OK);
					else
						MessageBox(GetHWnd(), "无此道路！", "操作完成", MB_OK);
				}
			}
		}
	}
}

void Window::close()
{
	closegraph();
}

void Window::showMainWindow()
{
	state = WindowState::mainWindow;
	cleardevice();

	// 加载背景图片
	loadimage(NULL, BACKGROUND_IMAGE, 1000, 800);

	// 绘制提示文字
	RECT rect = { 0, 0, width, 200 };
	settextstyle(70, 0, "华光胖头鱼_CNKI");

	//用于在指定区域内以指定格式输出字符串
	drawtext("校园导游系统", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	// 显示按钮
	mainWindow_view->show();
	mainWindow_edit->show();
	mainWindow_exit->show();
	mainWindow_search->show();
}

void Window::showMap()
{
	state = WindowState::map;
	cleardevice();

	// 加载背景图片
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// 显示控件
	viewMap_message->show();
	viewMap_back->show();

	for (int i = 0; i < G.m_vertex_number; i++)
	{
		button[i]->show();
	}
	static int n = 1;							//保证提示信息只输出一次
	while (n)
	{
		showMessage();
		n--;
	}
}

void Window::showSearch()
{
	state = WindowState::Search;
	cleardevice();

	// 加载背景图片
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// 显示控件
	search_message->show();
	search_back->show();
	for (int i = 0; i < G.m_vertex_number; i++)
	{
		button[i]->show();
	}
	static int n = 1;							//保证提示信息只输出一次
	while (n)
	{
		searchMessage();
		n--;
	}
}

void Window::showEditMap()
{
	state = WindowState::editMap;
	cleardevice();

	// 加载背景图片
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// 显示控件
	editMap_update_vex->show();
	editMap_add_vex->show();
	editMap_delete_vex->show();
	editMap_update_road->show();
	editMap_add_road->show();
	editMap_delete_road->show();
	editMap_message->show();
	editMap_back->show();
	for (int i = 0; i <  G.m_vertex_number; i++)
	{
		button[i]->show();
	}
	static int n = 1;							//保证提示信息只输出一次
	while (n)
	{
		editMessage();
		n--;
	}
}

void Window::showMessage()
{
	MessageBox(GetHWnd(), "点击景点名称即可查看景点信息", "使用提示", MB_OK);
}

void Window::searchMessage()
{
	MessageBox(GetHWnd(), "先后点击两个景点名称即可绘制景点间的最短路径，按任意键继续", "使用提示", MB_OK);
}

void Window::editMessage()
{
	MessageBox(GetHWnd(), "选择你想实现的功能", "使用提示", MB_OK);
}
