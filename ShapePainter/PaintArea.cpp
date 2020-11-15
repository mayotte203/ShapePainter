#include "PaintArea.h"
#include "EllipseShape.h"
#include "StarShape.h"
#include "TriangleShape.h"
#include "ShapeMouseEventHandler.h"

PaintArea::PaintArea(QWidget* parent) : QWidget(parent) {
    setFocusPolicy(Qt::ClickFocus);
    m_mouseEventHandler = std::make_unique<ShapeMouseEventHandler<EllipseShape>>(this);
}

void PaintArea::eraseShape(std::vector<std::unique_ptr<Shape>>::iterator shapeIt)
{
    for (auto it = m_lines.begin(); it < m_lines.end();)
    {
        if ((*it)->isConnnected(shapeIt->get()))
        {
            it = m_lines.erase(it);
        }
        else
        {
            ++it;
        }
    }
    m_shapes.erase(shapeIt);
}

void PaintArea::paintEvent(QPaintEvent* qEvent)
{
	QPainter painter(this);
	for (auto it = m_shapes.begin(); it < m_shapes.end(); ++it)
	{
		(*it)->draw(painter);
	}
    for (auto it = m_lines.begin(); it < m_lines.end(); ++it)
    {
        (*it)->draw(painter);
    }
}

void PaintArea::mousePressEvent(QMouseEvent* qEvent)
{
	m_mouseEventHandler->handleMousePressEvent(qEvent);
}

void PaintArea::mouseMoveEvent(QMouseEvent* qEvent)
{
	m_mouseEventHandler->handleMouseMoveEvent(qEvent);
}

void PaintArea::mouseReleaseEvent(QMouseEvent* qEvent)
{
    m_mouseEventHandler->handleMouseReleaseEvent(qEvent);
}

void PaintArea::addLine(Shape* firstShape, Shape* secondShape)
{
    m_lines.push_back(std::make_unique<Line>(firstShape, secondShape));
}
 
void PaintArea::deleteLine(std::vector<std::unique_ptr<Line>>::iterator it)
{
    m_lines.erase(it);
}

void PaintArea::newFile()
{
    m_shapes.clear();
    m_lines.clear();
}

