#pragma once
#include "widget.h"
#include <string>

class Button :public Widget							//继承widget类
{
public:
	Button(const int& x = 0, const int& y = 0, const int& width = 100, const int& height = 60, const std::string& text = "按钮");
	void show() const;								// 显示按钮
	void show_click() const;						//显示被点击过后的按钮
	bool state(const ExMessage& msg) const;			// 按钮状态，true 表示按钮按下
	const std::string& getText() const;				// 获取按钮文本
	void setText(const std::string& text);			// 设置按钮文本

protected:
	bool isIn(const ExMessage& msg) const;			// 判断鼠标是否在按钮里面
	std::string text;								// 按钮文本
};