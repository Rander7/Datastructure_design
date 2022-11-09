#include "widget.h"

Widget::Widget(const int& x, const int& y, const int& width, const int& height) : x(x), y(y), width(width), height(height)
{
}

const int& Widget::getX() const
{
	return x;//��ȡ��ǰ x ����
}

const int& Widget::getY() const
{
	return y;//��ȡ��ǰ y ���ꡣ
}

const int& Widget::getWidth() const
{
	return width;//��ȡ��ͼ�����
}

const int& Widget::getHeight() const
{
	return height;//��ȡ��ͼ���߶�
}

void Widget::setX(const int& x)
{
	this->x = x;//����x����
	show();//չʾ
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