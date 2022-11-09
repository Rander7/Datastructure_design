#pragma once
#include <easyx.h>

class Widget
{
public:
	Widget(const int& x = 0, const int& y = 0, const int& width = 100, const int& height = 60);
	//有参构造窗口的坐标和长宽,如果没有输入参数就使用默认参数
	void setRect(const int& x, const int& y, const int& width, const int& height);//设置窗口的坐标和长宽
	virtual void show() const = 0;	//纯虚show函数
	const int& getX() const;//获取x坐标
	const int& getY() const;
	const int& getWidth() const;
	const int& getHeight() const;
	void setX(const int& x);//设置x坐标
	void setY(const int& y);
	void setWidth(const int& width);
	void setHeight(const int& height);

protected:
	int x;        // X 坐标
	int y;        // Y 坐标
	int width;    // 宽度
	int height;   // 高度
};