#pragma once
#include <QPainter>

class Drawable
{
public:
	virtual ~Drawable() {};
	virtual void draw(QPainter& qPainter) {};
private:
};

