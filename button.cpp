#include "button.h"



Button::Button(const int& x, const int& y, const int& width, const int& height, const std::string& text) : Widget(x, y, width, height), text(text)
{
}

void Button::show() const
{
	// ������ʽ
	setlinestyle(PS_SOLID, 2);
	setfillcolor(CYAN);
	settextstyle(25, 0, "��������");

	// ���ư�ť
	fillrectangle(x, y, x + width, y + height);

	// �����ı�
	RECT rect = { x, y, x + width, y + height };
	settextcolor(BLACK);
	drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//������ָ����������ָ����ʽ����ַ���
}

void Button::show_click() const
{
	// ������ʽ
	setlinestyle(PS_SOLID, 2);
	setfillcolor(RGB(111, 241, 216));
	settextstyle(25, 0, "��������");

	// ���ư�ť
	fillrectangle(x, y, x + width, y + height);

	// �����ı�
	RECT rect = { x, y, x + width, y + height };
	settextcolor(BLACK);
	drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//������ָ����������ָ����ʽ����ַ���
}

bool Button::state(const ExMessage& msg) const
{
	if (msg.message == WM_MOUSEMOVE && isIn(msg))				// ��ť����
	{
		// ������ʽ
		setlinestyle(PS_SOLID, 2);
		setfillcolor(LIGHTCYAN);
		settextstyle(25, 0, "��������");

		// ���ư�ť
		fillrectangle(x, y, x + width, y + height);

		// �����ı�
		RECT rect = { x, y, x + width, y + height };
		drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		return false;
	}
	else if ((msg.message == WM_LBUTTONDOWN) && isIn(msg))		// ��ť�����
	{
		// ������ʽ
		setlinestyle(PS_SOLID, 2);
		setfillcolor(RGB(111, 241, 216));
		settextstyle(25, 0, "��������");

		// ���ư�ť
		fillrectangle(x, y, x + width, y + height);

		// �����ı�
		RECT rect = { x, y, x + width, y + height };
		drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		return true;
	}
	else														// �ָ���ťԭ����״̬
	{
		show();
		return false;
	}
}

const std::string& Button::getText() const
{
	return text;
}

void Button::setText(const std::string& text)
{
	this->text = text;
}

bool Button::isIn(const ExMessage& msg) const
{
	if (msg.x >= this->x && msg.x <= this->x + width && msg.y >= this->y && msg.y <= this->y + height)
	{
		return true;
	}
	return false;
}