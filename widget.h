#pragma once
#include <easyx.h>

class Widget
{
public:
	Widget(const int& x = 0, const int& y = 0, const int& width = 100, const int& height = 60);
	//�вι��촰�ڵ�����ͳ���,���û�����������ʹ��Ĭ�ϲ���
	void setRect(const int& x, const int& y, const int& width, const int& height);//���ô��ڵ�����ͳ���
	virtual void show() const = 0;	//����show����
	const int& getX() const;//��ȡx����
	const int& getY() const;
	const int& getWidth() const;
	const int& getHeight() const;
	void setX(const int& x);//����x����
	void setY(const int& y);
	void setWidth(const int& width);
	void setHeight(const int& height);

protected:
	int x;        // X ����
	int y;        // Y ����
	int width;    // ���
	int height;   // �߶�
};