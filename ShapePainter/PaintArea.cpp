#include "PaintArea.h"
#include "EllipseShape.h"
#include "StarShape.h"
#include "TriangleShape.h"
#include "ShapeMouseEventHandler.h"

PaintArea::PaintArea(QWidget* parent) : QWidget(parent) {
    setFocusPolicy(Qt::ClickFocus);
    m_mouseEventHandler = std::make_unique<ShapeMouseEventHandler<EllipseShape>>(this);
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

void PaintArea::eraseShape(QPoint point)
{

    auto it = std::find_if(m_shapes.begin(), m_shapes.end(),
        [&point](const std::unique_ptr<Shape>& shape) {return shape->getRect().contains(point); });
    if (it < m_shapes.end())
    {
        deleteConnectedLine(it->get());
        m_shapes.erase(it);
        update();
    }
}

void PaintArea::deleteConnectedLine(Shape* shape)
{
    for (auto it = m_lines.begin(); it < m_lines.end();)
    {
        if ((*it)->isConnnected(shape))
        {
            it = m_lines.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void PaintArea::addLine(Shape* firstShape, Shape* secondShape)
{
    m_lines.push_back(std::make_unique<Line>(firstShape, secondShape));
}

void PaintArea::eraseLine(QPoint point)
{
    auto it = std::find_if(m_lines.begin(), m_lines.end(),
        [&point](const std::unique_ptr<Line>& line) {return line->distanceTo(point) < DISTANCE_THRESHOLD; });
    if (it < m_lines.end())
    {
        m_lines.erase(it);
        update();
    }
}

void PaintArea::newFile()
{
    m_shapes.clear();
    m_lines.clear();
}

