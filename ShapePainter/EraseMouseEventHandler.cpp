#include "EraseMouseEventHandler.h"

void PaintArea::EraseMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        m_parent->eraseShape(qEvent->pos());
        break;
    }
    default:
    {

    }
    }
}

void PaintArea::EraseMouseEventHandler::handleMouseMoveEvent(QMouseEvent* qEvent)
{
}

void PaintArea::EraseMouseEventHandler::handleMouseReleaseEvent(QMouseEvent* qEvent)
{
}