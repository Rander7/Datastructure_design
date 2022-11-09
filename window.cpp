#include"window.h"
#include<graphics.h>
#include<conio.h>

UNDIRECTED_GRAPH G;										// ��ʵ��������ͼ��

Window::Window(const int& width, const int& height) : Widget(0, 0, width, height)
{
	G.init_UNDIRECTED_GRAPH();							// ������ѧУ����͵�·�������ڽӾ���
	show();

	// ���û�ͼ��ʽ
	LOGFONT f;											// ���������
	gettextstyle(&f);									// ��ȡ��ǰ������ʽ LOGFONT �ṹ���ָ�롣
	f.lfQuality = ANTIALIASED_QUALITY;					// ָ�����ֵ��������
	settextstyle(&f);									// ���õ�ǰ������ʽ
	settextcolor(BLACK);								// ������ɫ
	setbkmode(TRANSPARENT);								// ���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ ͸��
	setlinecolor(BLACK);								// ���õ�ǰ�豸������ɫ

	// ���������ڰ�ť
	mainWindow_view = new Button(250, 200, 150, 40, "�鿴��ͼ");
	mainWindow_search = new Button(250, 260, 150, 40, "��ѯ·��");
	mainWindow_edit = new Button(250, 320, 150, 40, "���ľ���");
	mainWindow_exit = new Button(250, 380, 150, 40, "�˳�����");

	// ������ͼ���ڰ�ť
	viewMap_message = new Button(850, 600, 120, 40, "ʹ����ʾ");
	viewMap_back = new Button(850, 650, 120, 40, "����");

	// �����������ڰ�ť
	search_message = new Button(850, 600, 120, 40, "ʹ����ʾ");
	search_back = new Button(850, 650, 120, 40, "����");

	// �����޸Ĵ��ڰ�ť
	editMap_update_vex = new Button(850, 400, 120, 40, "���¾���");
	editMap_add_vex = new Button(850, 450, 120, 40, "��Ӿ���");
	editMap_delete_vex = new Button(850, 500, 120, 40, "ɾ������");
	editMap_update_road = new Button(850, 550, 120, 40, "���µ�·");
	editMap_add_road = new Button(850, 600, 120, 40, "��ӵ�·");
	editMap_delete_road = new Button(850, 650, 120, 40, "ɾ����·");
	editMap_message = new Button(850, 700, 120, 40, "ʹ����ʾ");
	editMap_back = new Button(850, 750, 120, 40, "����");

	// �������㰴ť
	button[0] = new Button(115, 140, 95, 42, "����¥");
	button[1] = new Button(315, 100, 95, 42, "��ѧ¥");
	button[2] = new Button(700, 195, 75, 42, "����");
	button[3] = new Button(697, 110, 95, 42, "����");
	button[4] = new Button(345, 327, 95, 42, "����¥");
	button[5] = new Button(526, 305, 75, 42, "���");
	button[6] = new Button(628, 340, 95, 42, "����԰");
	button[7] = new Button(90, 258, 125, 42, "��Զ����");
	button[8] = new Button(225, 383, 95, 42, "ͼ���");
	button[9] = new Button(215, 490, 95, 42, "��Զ¥");
	button[10] = new Button(315, 518, 95, 42, "����¥");
	button[11] = new Button(622, 415, 95, 42, "�˶���");
	button[12] = new Button(680, 487, 95, 42, "����");
	button[13] = new Button(470, 660, 75, 42, "����");

	showMainWindow();									// ��ʾ������
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
	//���ߵ�4�����췽��״̬
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
	// �½�����
	SetWindowText(initgraph(width, height, NULL), "У԰����ϵͳ");	//���ô��ڱ���
	setbkcolor(WHITE);
	cleardevice();
}

void Window::messageLoop()
{
	// ������Ϣѭ��
	ExMessage msg;
	while (true)
	{
		// ��ȡ���ж���Ϣ
		msg = getmessage();//���ڻ�ȡһ����Ϣ�������ǰ��Ϣ������û�У���һֱ�ȴ�

		// �ж���ʾ����
		if (state == WindowState::mainWindow)									// ��������ʾ
		{
			if (mainWindow_view->state(msg))									// �鿴��ͼ
			{
				showMap();
			}
			else if (mainWindow_edit->state(msg))								// �༭����
			{
				showEditMap();
			}
			else if (mainWindow_search->state(msg))								// ��ѯ·��
			{
				showSearch();
			}
			else if (mainWindow_exit->state(msg) && msg.message != WM_LBUTTONUP)// �˳�����
			{
				return;															// ֱ��return����������
			}
		}
		else if (state == WindowState::map)										// �鿴��ͼ
		{
			if (viewMap_message->state(msg))
			{
				showMessage();//չʾ��ʾ��Ϣ
			}
			else if (viewMap_back->state(msg))									// ����������
			{
				showMainWindow();
			}
			else 
			{
				int n = viewJudgeButton();
				if (n >= 0)
				{
					MessageBox(GetHWnd(), G.vertexs[n].get_vex_information(), "������Ϣ", MB_OK);
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
					int cnt=0;													//����ÿһ�����·��������
					int c = 0;													//������ʾ·�ߵ���ɫ
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
					if (cnt != 0)												// չʾ��·����ͣ��ˢ��
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
					MessageBox(GetHWnd(), "������Ҫ���µľ���������Ϣ", "������ʾ", MB_OK);
					char s1[50];
					char s2[50];
					int flag1 = 0;
					int flag2 = 0;
					int id1=MessageBox(GetHWnd(), "Ҫ���¾�������", "������ʾ", MB_YESNO);
					if (IDYES == id1)
					{
						InputBox(s1, 50, "�������¾�����");
						update_Button(button[n], s1);								//������ʾ�İ�ť����
						Window::showEditMap();										//ˢ�¸��º�İ�ť
						flag1= 1;
					}
					int id2 = MessageBox(GetHWnd(), "Ҫ���¾�����Ϣ��", "������ʾ", MB_YESNO);
					if (IDYES == id2)
					{
						InputBox(s2, 50, "�����뾰����Ϣ");
						flag2 = 2;
					}
					if (flag1 || flag2)
					{
						MessageBox(GetHWnd(), "�þ��������Ϣ�Ѹ���", "������ʾ", MB_OK);
						G.update_vertex(n, s1, s2,flag1+flag2);
					}
					showEditMap();
				}
			}
			else if (editMap_add_vex->state(msg))
			{
				MessageBox(GetHWnd(), "�����뾰��������Ϣ��������λ��", "������ʾ", MB_OK);
				char s1[50] = {0};
				char s2[50];
				InputBox(s1, 50, "�������¾�����");
				InputBox(s2, 50, "�����뾰�����");
				G.add_vertex(s1, s2);
				int length = 0;
				for (int i = 0; s1[i] != 0; i++)
				{
					length++;
				}
				MessageBox(GetHWnd(), "����ͼ��ѡ�����������λ��", "������ʾ", MB_OK);
				while (1)
				{
					ExMessage m = getmessage(EX_MOUSE);
					if (m.message == WM_LBUTTONDOWN)
					{
						button[G.m_vertex_number - 1] = new Button(m.x - length * 5 - 20, m.y - 20, length * 10 + 35, 40, s1);
						showEditMap();
						MessageBox(GetHWnd(), "�þ���������", "�������", MB_OK);
						break;
					}
				}
						
			}
			else if (editMap_delete_vex->state(msg))
			{
				MessageBox(GetHWnd(), "����ͼ��ѡ����Ҫɾ���ľ���", "������ʾ", MB_OK);
				int n = viewJudgeButton_edit();
				if (n >= 0)
				{
					int id = MessageBox(GetHWnd(), "ȷ��ɾ���þ�����", "������ʾ", MB_YESNO);
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
				MessageBox(GetHWnd(), "����ͼ��ѡ�����������Ը���֮��ĵ�·", "������ʾ", MB_OK);
				int start, finish;
				if (editJudgeButton(start, finish))
				{
					char s[10];
					int weight = 0;
					if (G.update_road(start, finish, weight))
					{
						InputBox(s, 10, "�������·����");
						int weight = atoi(s);									//char*תint
						G.update_road(start, finish, weight);
						MessageBox(GetHWnd(), "�õ�·�Ѹ���", "�������", MB_OK);
					}
					else
					{
						int id=MessageBox(GetHWnd(), "�õ�·�����ڣ��Ƿ����ӵ�·?", "����", MB_YESNO);
						if (IDYES == id)
						{
							InputBox(s, 10, "�������·����");
							weight = atoi(s);									//char*תint
							G.add_road(start, finish, weight);
							MessageBox(GetHWnd(), "�õ�·������", "�������", MB_OK);
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
				MessageBox(GetHWnd(), "����ͼ��ѡ���������������֮��ĵ�·", "������ʾ", MB_OK);
				int start, finish;
				if (editJudgeButton(start, finish))
				{

					char s[10];
					int weight = 0;
					if (G.add_road(start, finish, weight))
					{
						InputBox(s, 10, "�������·����");
						weight = atoi(s);										//char*תint
						G.add_road(start, finish, weight);
						MessageBox(GetHWnd(), "�õ�·������", "�������", MB_OK);
					}
					else
					{
						int id=MessageBox(GetHWnd(), "�õ�·�Ѿ����ڣ��Ƿ�Ҫ���¸õ�·��Ȩֵ?", "������ʾ", MB_YESNO);
						if (IDYES == id)
						{
							InputBox(s, 10, "�������·����");
							int weight = atoi(s);								//char*תint
							G.update_road(start, finish, weight);
							MessageBox(GetHWnd(), "�õ�·�Ѹ���", "�������", MB_OK);
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
			MessageBox(GetHWnd(), "����ͼ��ѡ������������ɾ��֮��ĵ�·", "������ʾ", MB_OK);
			int start, finish;
				if (editJudgeButton(start, finish))
				{
					if (G.del_road(start,finish))
						MessageBox(GetHWnd(), "�õ�·��ɾ��", "�������", MB_OK);
					else
						MessageBox(GetHWnd(), "�޴˵�·��", "�������", MB_OK);
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

	// ���ر���ͼƬ
	loadimage(NULL, BACKGROUND_IMAGE, 1000, 800);

	// ������ʾ����
	RECT rect = { 0, 0, width, 200 };
	settextstyle(70, 0, "������ͷ��_CNKI");

	//������ָ����������ָ����ʽ����ַ���
	drawtext("У԰����ϵͳ", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	// ��ʾ��ť
	mainWindow_view->show();
	mainWindow_edit->show();
	mainWindow_exit->show();
	mainWindow_search->show();
}

void Window::showMap()
{
	state = WindowState::map;
	cleardevice();

	// ���ر���ͼƬ
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// ��ʾ�ؼ�
	viewMap_message->show();
	viewMap_back->show();

	for (int i = 0; i < G.m_vertex_number; i++)
	{
		button[i]->show();
	}
	static int n = 1;							//��֤��ʾ��Ϣֻ���һ��
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

	// ���ر���ͼƬ
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// ��ʾ�ؼ�
	search_message->show();
	search_back->show();
	for (int i = 0; i < G.m_vertex_number; i++)
	{
		button[i]->show();
	}
	static int n = 1;							//��֤��ʾ��Ϣֻ���һ��
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

	// ���ر���ͼƬ
	loadimage(NULL, MAP_IMAGE, 1000, 800);

	// ��ʾ�ؼ�
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
	static int n = 1;							//��֤��ʾ��Ϣֻ���һ��
	while (n)
	{
		editMessage();
		n--;
	}
}

void Window::showMessage()
{
	MessageBox(GetHWnd(), "����������Ƽ��ɲ鿴������Ϣ", "ʹ����ʾ", MB_OK);
}

void Window::searchMessage()
{
	MessageBox(GetHWnd(), "�Ⱥ��������������Ƽ��ɻ��ƾ��������·���������������", "ʹ����ʾ", MB_OK);
}

void Window::editMessage()
{
	MessageBox(GetHWnd(), "ѡ������ʵ�ֵĹ���", "ʹ����ʾ", MB_OK);
}
