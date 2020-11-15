#pragma once
#include <QPainter>

class Drawable
{
public:
	virtual ~Drawable() {};
	virtual void draw(QPainter& qPainter) = 0;
private:
};

