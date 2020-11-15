#include "EllipseShape.h"

void EllipseShape::draw(QPainter& qPainter)
{
	qPainter.drawEllipse(m_rect);
}
