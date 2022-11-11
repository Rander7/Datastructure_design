#include "button.h"



Button::Button(const int& x, const int& y, const int& width, const int& height, const std::string& text) : Widget(x, y, width, height), text(text)
{
}

void Button::show() const
{
	// 设置样式
	setlinestyle(PS_SOLID, 2);
	setfillcolor(CYAN);
	settextstyle(25, 0, "华文琥珀");

	// 绘制按钮
	fillrectangle(x, y, x + width, y + height);

	// 绘制文本
	RECT rect = { x, y, x + width, y + height };
	settextcolor(BLACK);
	drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//用于在指定区域内以指定格式输出字符串
}

void Button::show_click() const
{
	// 设置样式
	setlinestyle(PS_SOLID, 2);
	setfillcolor(RGB(111, 241, 216));
	settextstyle(25, 0, "华文琥珀");

	// 绘制按钮
	fillrectangle(x, y, x + width, y + height);

	// 绘制文本
	RECT rect = { x, y, x + width, y + height };
	settextcolor(BLACK);
	drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//用于在指定区域内以指定格式输出字符串
}

bool Button::state(const ExMessage& msg) const
{
	if (msg.message == WM_MOUSEMOVE && isIn(msg))				// 按钮悬浮
	{
		// 设置样式
		setlinestyle(PS_SOLID, 2);
		setfillcolor(LIGHTCYAN);
		settextstyle(25, 0, "华文琥珀");

		// 绘制按钮
		fillrectangle(x, y, x + width, y + height);

		// 绘制文本
		RECT rect = { x, y, x + width, y + height };
		drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		return false;
	}
	else if ((msg.message == WM_LBUTTONDOWN) && isIn(msg))		// 按钮被点击
	{
		// 设置样式
		setlinestyle(PS_SOLID, 2);
		setfillcolor(RGB(111, 241, 216));
		settextstyle(25, 0, "华文琥珀");

		// 绘制按钮
		fillrectangle(x, y, x + width, y + height);

		// 绘制文本
		RECT rect = { x, y, x + width, y + height };
		drawtext(text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		return true;
	}
	else														// 恢复按钮原来的状态
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