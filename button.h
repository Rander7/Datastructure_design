#pragma once
#include "widget.h"
#include <string>

class Button :public Widget							//�̳�widget��
{
public:
	Button(const int& x = 0, const int& y = 0, const int& width = 100, const int& height = 60, const std::string& text = "��ť");
	void show() const;								// ��ʾ��ť
	void show_click() const;						//��ʾ���������İ�ť
	bool state(const ExMessage& msg) const;			// ��ť״̬��true ��ʾ��ť����
	const std::string& getText() const;				// ��ȡ��ť�ı�
	void setText(const std::string& text);			// ���ð�ť�ı�

protected:
	bool isIn(const ExMessage& msg) const;			// �ж�����Ƿ��ڰ�ť����
	std::string text;								// ��ť�ı�
};