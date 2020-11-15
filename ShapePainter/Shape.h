#pragma once
#include "Drawable.h"
#include <QPoint>
#include <QRect>
#include <QSize>

class Shape : public Drawable
{
public:
	Shape() : m_rect() {};
	virtual ~Shape() {};
	void setPos(const QPoint& pos);
	void setSize(const QSize& size);
	QRect getRect();
	QPoint getPos();
	QPoint getCenter();
	virtual void draw(QPainter& qPainter) = 0;
protected:
	QRect m_rect;
private:

};

