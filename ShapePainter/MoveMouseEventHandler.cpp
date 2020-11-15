#include "MoveMouseEventHandler.h"

void PaintArea::MoveMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        m_startPos = qEvent->pos();
        auto it = std::find_if(m_parent->m_shapes.begin(), m_parent->m_shapes.end(),
            [this](const std::unique_ptr<Shape>& shape) {return shape->getRect().contains(m_startPos); });
        if (it < m_parent->m_shapes.end())
            m_selectedShape = (*it).get();
        break;
    }
    default:
    {

    }
    }
}

void PaintArea::MoveMouseEventHandler::handleMouseMoveEvent(QMouseEvent* qEvent)
{
    if (m_selectedShape != nullptr)
    {
        m_selectedShape->setPos(m_selectedShape->getPos() - m_startPos + qEvent->pos());
        m_startPos = qEvent->pos();
        m_parent->update();
    }
}

void PaintArea::MoveMouseEventHandler::handleMouseReleaseEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        m_selectedShape = nullptr;
        break;
    }
    default:
    {

    }
    }
}