#include "StarShape.h"

void StarShape::draw(QPainter& qPainter)
{
	qPainter.drawLine(m_rect.bottomLeft(), (m_rect.topLeft() + m_rect.topRight()) / 2);
	qPainter.drawLine(m_rect.bottomRight(), (m_rect.topLeft() + m_rect.topRight()) / 2);
	qPainter.drawLine(m_rect.bottomRight(), (m_rect.topLeft() + m_rect.bottomLeft()) / 2);
	qPainter.drawLine(m_rect.bottomLeft(), (m_rect.topRight() + m_rect.bottomRight()) / 2);
	qPainter.drawLine((m_rect.topLeft() + m_rect.bottomLeft()) / 2, (m_rect.topRight() + m_rect.bottomRight()) / 2);
}
