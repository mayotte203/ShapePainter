#include "LineMouseEventHandler.h"

void PaintArea::LineMouseEventHandler::handleMousePressEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        m_firstShape = nullptr;
        m_secondShape = nullptr;
        auto it = std::find_if(parent->m_shapes.begin(), parent->m_shapes.end(),
            [&qEvent](const std::unique_ptr<Shape>& shape) {return shape->getRect().contains(qEvent->pos()); });
        if (it < parent->m_shapes.end())
            m_firstShape = (*it).get();
        break;
    }
    default:
    {

    }
    }
}

void PaintArea::LineMouseEventHandler::handleMouseMoveEvent(QMouseEvent* qEvent)
{
}

void PaintArea::LineMouseEventHandler::handleMouseReleaseEvent(QMouseEvent* qEvent)
{
    switch (qEvent->button())
    {
    case Qt::MouseButton::LeftButton:
    {
        if (m_firstShape != nullptr)
        {
            auto it = std::find_if(parent->m_shapes.begin(), parent->m_shapes.end(),
                [&qEvent](const std::unique_ptr<Shape>& shape) {return shape->getRect().contains(qEvent->pos()); });
            if (it < parent->m_shapes.end())
            {
                m_secondShape = (*it).get();
                if (m_firstShape != m_secondShape)
                {
                    parent->addLine(m_firstShape, m_secondShape);
                    parent->update();
                }
            }
            m_firstShape = nullptr;
            m_secondShape = nullptr;
        }
        break;
    }
    default:
    {

    }
    }
}