#include "LineEraseMouseEventHandler.h"

void PaintArea::LineEraseMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        auto it = std::find_if(parent->m_lines.begin(), parent->m_lines.end(),
            [&qEvent](const std::unique_ptr<Line>& line) {return line->distanceTo(qEvent->pos()) < m_threshold; });
        if (it < parent->m_lines.end())
        {
            parent->deleteLine(it);
            parent->update();
        }
        break;
    }
    default:
    {

    }
    }
}

void PaintArea::LineEraseMouseEventHandler::handleMouseMoveEvent(QMouseEvent* qEvent)
{
}

void PaintArea::LineEraseMouseEventHandler::handleMouseReleaseEvent(QMouseEvent* qEvent)
{
}