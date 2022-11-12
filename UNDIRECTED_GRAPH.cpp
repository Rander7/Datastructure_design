#include "UNDIRECTED_GRAPH.h"
#include <graphics.h>
#include "VERTEXTYPE.h"


//搜索所有最短路径相关数组,变量声明
int stack[MAXSPOTS];
bool visit[MAXSPOTS] = { false };							// 表明该景点有无被访问
int stack_top = 0;
int path_array[MAXSPOTS][MAXSPOTS];							// 记录对应点的最小路径的前驱点
															// 例如p(1, 3) = 2 说明顶点1到顶点3的最小路径要经过2
int short_path_array[MAXSPOTS][MAXSPOTS];					// 记录两个顶点间的最小路径值

int pass_by[100] = { 0 };
int pass_by_num = 0;
char store_short_path[200] = { 0 };							// 所有操作结束后打印所有最短路径文字信息

void UNDIRECTED_GRAPH::init_UNDIRECTED_GRAPH()
{
	m_vertex_number = 14;									// 初始化景点个数
	m_road_number = 27;										// 初始化所有路径个数

	VERTEXTYPE vertex0(0, "家属楼", "学校工作人员家属住所", true);
	vertexs[0] = vertex0;
	VERTEXTYPE vertex1(1, "勤学楼", "工图绘制教室,考研自习教室,阶梯教室", true);
	vertexs[1] = vertex1;
	VERTEXTYPE vertex2(2, "宿舍", "人工智能院宿舍所在", true);
	vertexs[2] = vertex2;
	VERTEXTYPE vertex3(3, "网球场", "打网球,网球课所使用的场地", true);
	vertexs[3] = vertex3;
	VERTEXTYPE vertex4(4, "育贤楼", "教室办公室大楼", true);
	vertexs[4] = vertex4;
	VERTEXTYPE vertex5(5, "大学生活动中心", "学生组织活动所使用的大厅舞台", true);
	vertexs[5] = vertex5;
	VERTEXTYPE vertex6(6, "润泽园", "一，二，三食堂,提供三餐,楼下广场开展各种活动", true);
	vertexs[6] = vertex6;
	VERTEXTYPE vertex7(7, "宁远车队", "学校竞赛车队测试训练地", true);
	vertexs[7] = vertex7;
	VERTEXTYPE vertex8(8, "图书馆", "学生借阅书籍,上机作业,自学备考自习室所在", true);
	vertexs[8] = vertex8;
	VERTEXTYPE vertex9(9, "博远楼", "实验室,有日常上课的阶梯教室", true);
	vertexs[9] = vertex9;
	VERTEXTYPE vertex10(10, "汇贤楼", "主要的日常上课教学楼", true);
	vertexs[10] = vertex10;
	VERTEXTYPE vertex11(11, "运动场", "可以跑步,上体育课,组织大型活动", true);
	vertexs[11] = vertex11;
	VERTEXTYPE vertex12(12, "排球场", "打排球,上排球课使用", true);
	vertexs[12] = vertex12;
	VERTEXTYPE vertex13(13, "校门", "进入南京农业大学浦口校区的大门", true);
	vertexs[13] = vertex13;
	
	
	for (int i = 0; i < MAXSPOTS; i++)
	{
		for (int j = 0; j < MAXSPOTS; j++)
		{
			roads[i][j] = MAXDISTANCE;
		}
	}

	//将路径权值赋值给邻接矩阵
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
	change_vertex_number(true);								//总景点数递增

}

void UNDIRECTED_GRAPH::del_vertex(int x)
{
	for (int i = 0; i < m_vertex_number; i++)
	{
		if (roads[i][x] != MAXDISTANCE)
		{
			roads[i][x] = MAXDISTANCE;
			roads[x][i] = MAXDISTANCE;
			change_road_number(false);						//总道路数递减
		}
	}
	vertexs[x].change_vex_existence(false);					//该景点存在赋否
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
	if (pos == end)										// 如果首尾景点相同，一次路径查找结束
	{
		int sum = 0;									// 记录该路径的总长
		for (i = 0; i < stack_top - 1; i++)			    // 注意最后stack_top比栈中景点总数多1
		{												// 注意最后i的循环最大下标
			if (sum > min)								//加的途中sum>min直接取消
			{
				break;
			}
			sum += roads[stack[i]][stack[i + 1]];		// sum+=栈中景点两两之间路径长度
		}
		sum += roads[stack[i]][end];					// 注意终点没有入栈,加上最后一个景点到end路径长度
		if (sum == min)									// 如果该条路径长度等于最短路径长度
		{
			for (i = 0; i < stack_top; i++)				// 将该路径栈中的所有景点下标存到pass_by
			{
				pass_by[pass_by_num++]= stack[i];
				strcat(store_short_path, vertexs[stack[i]].get_vex_name());
				strcat(store_short_path, "->");
			}
			pass_by[pass_by_num++] = end;				// 存入end景点下标
			pass_by[pass_by_num++] = -1;				// 不同最短路径包含的所有景点下标并用-1隔开
			strcat(store_short_path, vertexs[end].get_vex_name());
			strcat(store_short_path, "\n");
		}
		return;
	}
	visit[pos] = true;									// 标记被访问过 
	stack[stack_top++] = pos;							// 经过的景点加入栈
	for (i = 0; i < m_vertex_number; i++)
	{
		if (!visit[i] && roads[pos][i] != MAXDISTANCE)	// 如果这个点没有被访问过，而且pos与这个点相连，就继续搜索
		{
			UNDIRECTED_GRAPH::dfs(i, end, min);
		}
	}
	visit[pos] = false;									// 该景点重新标记为未访问
	stack_top--;										// 栈里删除该景点
}



void UNDIRECTED_GRAPH::search_all_the_short_path(int P[MAXSPOTS][MAXSPOTS], int D[MAXSPOTS][MAXSPOTS], int x, int y)
{
	pass_by_num = 0;									// 每次调用前先初始化为0
	memset(pass_by, -1, 400);
	memset(store_short_path, 0, 200);					// 初始化文字输出数组

	strcat(store_short_path, vertexs[x].get_vex_name());
	strcat(store_short_path, "->");
	strcat(store_short_path, vertexs[y].get_vex_name());
	strcat(store_short_path, "的最短路径为: \n");

	int v, w, k;										// v,w分别是起点和终点,k为中间节点													
	for (v = 0; v < m_vertex_number; v++)				// 初始化floyd算法的两个矩阵 
	{
		for (w = 0; w < m_vertex_number; w++)
		{
			D[v][w] = roads[v][w];						// D数组初始值为这两个顶点之间道路权值
			P[v][w] = w;								// p数组初始值为被指向顶点的下标
		}
	}

	for (k = 0; k < m_vertex_number; k++)				// k为中间点 
	{

		for (v = 0; v < m_vertex_number; v++)			// v为起点
		{

			for (w = 0; w < m_vertex_number; w++)		// w为终点 
			{
				if (D[v][w] > (D[v][k] + D[k][w]))		// 如果利用k作为中间结点路径权值和小于vw原来的权值和
				{
					D[v][w] = D[v][k] + D[k][w];		// 更新最短路径 
					P[v][w] = P[v][k];					// 更新最短路径中间顶点 
				}
			}
		}
	}
	char zan_path[100];									//用来存储两点间最短路径大小，方便MessageBox输出
	int temp_min_path = D[x][y];						//要传递到dfs函数中的最短路径整型
	if (D[x][y] != MAXDISTANCE)							//如果xy两点间有路径就把其值存在zan_path中
	{
		sprintf(zan_path, "%d", D[x][y]);
	}
	if (x == y)											//如果是该景点到自身，最短路径长度就是0，直接结束程序
	{
		D[x][y] = 0;
		sprintf(zan_path, "%d", D[x][y]);
		strcat(store_short_path, zan_path);
		MessageBox(GetHWnd(), store_short_path, "最短路径", MB_OK);
	}
	else
	{
		if (D[x][y] == MAXDISTANCE)						//如果两点间不存在路径，输出提示框，程序结束
		{
			MessageBox(GetHWnd(), "不存在路径连接两个景点，某个或者两个都景点已经被删除了", "最短路径", MB_OK);
		}
		else
		{
			dfs(x, y, temp_min_path);					//将景点的首位序号，最短路径长度，经过的景点下标传入dfs
			strcat(store_short_path, " \n最短路径长度为: ");
			strcat(store_short_path, zan_path);
			MessageBox(GetHWnd(), store_short_path, "最短路径", MB_OK);
		}
	}
}