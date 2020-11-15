#include "TriangleShape.h"

void TriangleShape::draw(QPainter& qPainter)
{
	qPainter.drawLine(m_rect.bottomLeft(), (m_rect.topLeft() + m_rect.topRight()) / 2);
	qPainter.drawLine(m_rect.bottomRight(), (m_rect.topLeft() + m_rect.topRight()) / 2);
	qPainter.drawLine(m_rect.bottomRight(), m_rect.bottomLeft());
}
