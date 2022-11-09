#include "widget.h"

Widget::Widget(const int& x, const int& y, const int& width, const int& height) : x(x), y(y), width(width), height(height)
{
}

const int& Widget::getX() const
{
	return x;//获取当前 x 坐标
}

const int& Widget::getY() const
{
	return y;//获取当前 y 坐标。
}

const int& Widget::getWidth() const
{
	return width;//获取绘图区宽度
}

const int& Widget::getHeight() const
{
	return height;//获取绘图区高度
}

void Widget::setX(const int& x)
{
	this->x = x;//设置x坐标
	show();//展示
}

void Widget::setY(const int& y)
{
	this->y = y;
	show();
}

void Widget::setWidth(const int& width)
{
	this->width = width;
	show();
}

void Widget::setHeight(const int& height)
{
	this->height = height;
	show();
}

void Widget::setRect(const int& x, const int& y, const int& width, const int& height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	show();
}