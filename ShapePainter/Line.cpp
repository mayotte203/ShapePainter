#include "Line.h"
#include <algorithm>

Line::Line()
{
}

Line::Line(Shape* firstShape, Shape* secondShape)
{
	m_firstShape = firstShape;
	m_secondShape = secondShape;
}

void Line::draw(QPainter& qPainter)
{
	if(m_firstShape != nullptr && m_secondShape !=nullptr)
		qPainter.drawLine(m_firstShape->getCenter(), m_secondShape->getCenter());
}

bool Line::isConnnected(Shape* shape)
{
	return m_firstShape == shape || m_secondShape == shape;
}

float Line::distanceTo(QPoint p)
{
	QPoint P1 = m_firstShape->getCenter();//v
	QPoint P2 = m_secondShape->getCenter();//w
	const float length = powf(P2.y() - P1.y(), 2.0f) + powf(P2.x() - P1.x(), 2.0f);
	const float t = std::clamp(((p.x() - P1.x())*(P2.x() - P1.x()) + (p.y() - P1.y()) * (P2.y() - P1.y())) / length, 0.0f, 1.0f);
	const QPoint projection = P1 + t * (P2 - P1);
	return sqrtf(powf(projection.y() - p.y(), 2.0f) + powf(projection.x() - p.x(), 2.0f));
}
