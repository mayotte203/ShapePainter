#include "Shape.h"

void Shape::setPos(const QPoint& pos)
{
	m_rect.moveTo(pos);
}

void Shape::setSize(const QSize& size)
{
	m_rect.setSize(size);
}

QRect Shape::getRect()
{
	return m_rect;
}

QPoint Shape::getPos()
{
	return m_rect.topLeft();
}

QPoint Shape::getCenter()
{
	return m_rect.center();
}
