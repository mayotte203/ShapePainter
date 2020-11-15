#include "EraseMouseEventHandler.h"

void PaintArea::EraseMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        auto it = std::find_if(parent->m_shapes.begin(), parent->m_shapes.end(),
            [&qEvent](const std::unique_ptr<Shape>& shape) {return shape->getRect().contains(qEvent->pos()); });
        if (it < parent->m_shapes.end())
        {
            parent->eraseShape(it);
            parent->update();
        }
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