#include "UNDIRECTED_GRAPH.h"
#include <graphics.h>
#include "VERTEXTYPE.h"


//�����������·���������,��������
int stack[MAXSPOTS];
bool visit[MAXSPOTS] = { false };							// �����þ������ޱ�����
int stack_top = 0;
int path_array[MAXSPOTS][MAXSPOTS];							// ��¼��Ӧ�����С·����ǰ����
															// ����p(1, 3) = 2 ˵������1������3����С·��Ҫ����2
int short_path_array[MAXSPOTS][MAXSPOTS];					// ��¼������������С·��ֵ

int pass_by[100] = { 0 };
int pass_by_num = 0;
char store_short_path[200] = { 0 };							// ���в����������ӡ�������·��������Ϣ

void UNDIRECTED_GRAPH::init_UNDIRECTED_GRAPH()
{
	m_vertex_number = 14;									// ��ʼ���������
	m_road_number = 27;										// ��ʼ������·������

	VERTEXTYPE vertex0(0, "����¥", "ѧУ������Ա����ס��", true);
	vertexs[0] = vertex0;
	VERTEXTYPE vertex1(1, "��ѧ¥", "��ͼ���ƽ���,������ϰ����,���ݽ���", true);
	vertexs[1] = vertex1;
	VERTEXTYPE vertex2(2, "����", "�˹�����Ժ��������", true);
	vertexs[2] = vertex2;
	VERTEXTYPE vertex3(3, "����", "������,�������ʹ�õĳ���", true);
	vertexs[3] = vertex3;
	VERTEXTYPE vertex4(4, "����¥", "���Ұ칫�Ҵ�¥", true);
	vertexs[4] = vertex4;
	VERTEXTYPE vertex5(5, "��ѧ�������", "ѧ����֯���ʹ�õĴ�����̨", true);
	vertexs[5] = vertex5;
	VERTEXTYPE vertex6(6, "����԰", "һ��������ʳ��,�ṩ����,¥�¹㳡��չ���ֻ", true);
	vertexs[6] = vertex6;
	VERTEXTYPE vertex7(7, "��Զ����", "ѧУ�������Ӳ���ѵ����", true);
	vertexs[7] = vertex7;
	VERTEXTYPE vertex8(8, "ͼ���", "ѧ�������鼮,�ϻ���ҵ,��ѧ������ϰ������", true);
	vertexs[8] = vertex8;
	VERTEXTYPE vertex9(9, "��Զ¥", "ʵ����,���ճ��ϿεĽ��ݽ���", true);
	vertexs[9] = vertex9;
	VERTEXTYPE vertex10(10, "����¥", "��Ҫ���ճ��Ͽν�ѧ¥", true);
	vertexs[10] = vertex10;
	VERTEXTYPE vertex11(11, "�˶���", "�����ܲ�,��������,��֯���ͻ", true);
	vertexs[11] = vertex11;
	VERTEXTYPE vertex12(12, "����", "������,�������ʹ��", true);
	vertexs[12] = vertex12;
	VERTEXTYPE vertex13(13, "У��", "�����Ͼ�ũҵ��ѧ�ֿ�У���Ĵ���", true);
	vertexs[13] = vertex13;
	
	
	for (int i = 0; i < MAXSPOTS; i++)
	{
		for (int j = 0; j < MAXSPOTS; j++)
		{
			roads[i][j] = MAXDISTANCE;
		}
	}

	//��·��Ȩֵ��ֵ���ڽӾ���
	roads[0][1] = 100;
	roads[0][7] = 130;
	roads[1][3] = 370;
	roads[1][4] = 250;
	roads[1][7] = 200;
	roads[2][3] = 50;
	roads[2][6] = 150;
	roads[4][5] = 80;
	roads[4][8] = 70;
	roads[4][9] = 120;
	roads[4][10] = 150;
	roads[4][13] = 200;
	roads[5][6] = 50;
	roads[5][10] = 140;
	roads[5][13] = 200;
	roads[6][11] = 50;
	roads[7][8] = 150;
	roads[8][9] = 70;
	roads[8][10] = 100;
	roads[9][10] = 70;
	roads[10][11] = 150;
	roads[10][12] = 120;
	roads[10][13] = 70;
	roads[11][12] = 20;
	roads[11][13] = 200;
	roads[12][13] = 100;

	for (int i = 0; i < m_vertex_number; i++)
	{
		for (int j = 0; j < m_vertex_number; j++)
		{
			roads[j][i] = roads[i][j];
		}
	}
}

int UNDIRECTED_GRAPH::get_vertex_number()
{
	return m_vertex_number;
}

int UNDIRECTED_GRAPH::get_vertex_road_number()
{
	return m_road_number;
}

void UNDIRECTED_GRAPH::add_vertex(char name2[], char info2[])
{
	VERTEXTYPE vertex(m_vertex_number, name2, info2, true);
	vertexs[m_vertex_number] = vertex;
	for (int i = 0; i <= m_vertex_number; i++)
	{
		roads[m_vertex_number][i] = MAXDISTANCE;
		roads[i][m_vertex_number] = MAXDISTANCE;
	}
	change_vertex_number(true);								//�ܾ���������

}

void UNDIRECTED_GRAPH::del_vertex(int x)
{
	for (int i = 0; i < m_vertex_number; i++)
	{
		if (roads[i][x] != MAXDISTANCE)
		{
			roads[i][x] = MAXDISTANCE;
			roads[x][i] = MAXDISTANCE;
			change_road_number(false);						//�ܵ�·���ݼ�
		}
	}
	vertexs[x].change_vex_existence(false);					//�þ�����ڸ���
}

void UNDIRECTED_GRAPH::update_vertex(int x, char name1[], char info1[],int flag)
{
	if (flag == 3)
	{
		vertexs[x].change_vex_name(name1);
		vertexs[x].change_vex_information(info1);
	}
	else if (flag == 1)
	{
		vertexs[x].change_vex_name(name1);
	}
	else if (flag == 2)
	{
		vertexs[x].change_vex_information(info1);
	}
}

void UNDIRECTED_GRAPH::add_road(int x, int y, int weight)
{
	roads[x][y] = weight;
	roads[y][x] = weight;
	change_road_number(true);
}

void UNDIRECTED_GRAPH::del_road(int x, int y)
{
	roads[x][y] = MAXDISTANCE;
	roads[y][x] = MAXDISTANCE;
	change_road_number(false);
}

void UNDIRECTED_GRAPH::update_road(int x, int y, int weight)
{
	roads[x][y] = weight;
	roads[y][x] = weight;
	change_road_number(false);
}

bool UNDIRECTED_GRAPH::judge_path_exist(int x, int y)
{
	if (roads[x][y] == MAXDISTANCE)
		return false;
	else
		return true;
}

void UNDIRECTED_GRAPH::change_vertex_number(bool t)
{
	if (t == true)
	{
		m_vertex_number++;
	}
	else
	{
		m_vertex_number--;
	}
}

void UNDIRECTED_GRAPH::change_road_number(bool t)
{
	if (t == true)
	{
		m_road_number++;
	}
	else
	{
		m_road_number--;
	}

}


void UNDIRECTED_GRAPH::dfs(int pos, int end, int min)
{
	int i;
	if (pos == end)										// �����β������ͬ��һ��·�����ҽ���
	{
		int sum = 0;									// ��¼��·�����ܳ�
		for (i = 0; i < stack_top - 1; i++)			    // ע�����stack_top��ջ�о���������1
		{												// ע�����i��ѭ������±�
			if (sum > min)								//�ӵ�;��sum>minֱ��ȡ��
			{
				break;
			}
			sum += roads[stack[i]][stack[i + 1]];		// sum+=ջ�о�������֮��·������
		}
		sum += roads[stack[i]][end];					// ע���յ�û����ջ,�������һ�����㵽end·������
		if (sum == min)									// �������·�����ȵ������·������
		{
			for (i = 0; i < stack_top; i++)				// ����·��ջ�е����о����±�浽pass_by
			{
				pass_by[pass_by_num++]= stack[i];
				strcat(store_short_path, vertexs[stack[i]].get_vex_name());
				strcat(store_short_path, "->");
			}
			pass_by[pass_by_num++] = end;				// ����end�����±�
			pass_by[pass_by_num++] = -1;				// ��ͬ���·�����������о����±겢��-1����
			strcat(store_short_path, vertexs[end].get_vex_name());
			strcat(store_short_path, "\n");
		}
		return;
	}
	visit[pos] = true;									// ��Ǳ����ʹ� 
	stack[stack_top++] = pos;							// �����ľ������ջ
	for (i = 0; i < m_vertex_number; i++)
	{
		if (!visit[i] && roads[pos][i] != MAXDISTANCE)	// ��������û�б����ʹ�������pos��������������ͼ�������
		{
			UNDIRECTED_GRAPH::dfs(i, end, min);
		}
	}
	visit[pos] = false;									// �þ������±��Ϊδ����
	stack_top--;										// ջ��ɾ���þ���
}



void UNDIRECTED_GRAPH::search_all_the_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y)
{
	pass_by_num = 0;									// ÿ�ε���ǰ�ȳ�ʼ��Ϊ0
	memset(pass_by, -1, 400);
	memset(store_short_path, 0, 200);					// ��ʼ�������������

	strcat(store_short_path, vertexs[x].get_vex_name());
	strcat(store_short_path, "->");
	strcat(store_short_path, vertexs[y].get_vex_name());
	strcat(store_short_path, "�����·��Ϊ: \n");

	int v, w, k;										// v,w�ֱ��������յ�,kΪ�м�ڵ�													
	for (v = 0; v < m_vertex_number; v++)				// ��ʼ��floyd�㷨���������� 
	{
		for (w = 0; w < m_vertex_number; w++)
		{
			D[v][w] = roads[v][w];						// D�����ʼֵΪ����������֮���·Ȩֵ
			P[v][w] = w;								// p�����ʼֵΪ��ָ�򶥵���±�
		}
	}

	for (k = 0; k < m_vertex_number; k++)				// kΪ�м�� 
	{

		for (v = 0; v < m_vertex_number; v++)			// vΪ���
		{

			for (w = 0; w < m_vertex_number; w++)		// wΪ�յ� 
			{
				if (D[v][w] > (D[v][k] + D[k][w]))		// �������k��Ϊ�м���·��Ȩֵ��С��vwԭ����Ȩֵ��
				{
					D[v][w] = D[v][k] + D[k][w];		// �������·�� 
					P[v][w] = P[v][k];					// �������·���м䶥�� 
				}
			}
		}
	}
	char zan_path[100];									//�����洢��������·����С������MessageBox���
	int temp_min_path = D[x][y];						//Ҫ���ݵ�dfs�����е����·������
	if (D[x][y] != MAXDISTANCE)							//���xy�������·���Ͱ���ֵ����zan_path��
	{
		sprintf(zan_path, "%d", D[x][y]);
	}
	if (x == y)											//����Ǹþ��㵽�������·�����Ⱦ���0��ֱ�ӽ�������
	{
		D[x][y] = 0;
		sprintf(zan_path, "%d", D[x][y]);
		strcat(store_short_path, zan_path);
		MessageBox(GetHWnd(), store_short_path, "���·��", MB_OK);
	}
	else
	{
		if (D[x][y] == MAXDISTANCE)						//�������䲻����·���������ʾ�򣬳������
		{
			MessageBox(GetHWnd(), "������·�������������㣬ĳ�����������������Ѿ���ɾ����", "���·��", MB_OK);
		}
		else
		{
			dfs(x, y, temp_min_path);					//���������λ��ţ����·�����ȣ������ľ����±괫��dfs
			strcat(store_short_path, " \n���·������Ϊ: ");
			strcat(store_short_path, zan_path);
			MessageBox(GetHWnd(), store_short_path, "���·��", MB_OK);
		}
	}
}