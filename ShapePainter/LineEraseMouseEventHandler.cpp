#include "LineEraseMouseEventHandler.h"

void PaintArea::LineEraseMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        m_parent->eraseLine(qEvent->pos());
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