#pragma once
#include "PaintArea.h"

template <class T>
class PaintArea::ShapeMouseEventHandler : public PaintArea::IMouseEventHandler
{
public:
    ShapeMouseEventHandler(PaintArea* parent) : IMouseEventHandler(parent) {};
    void handleMousePressEvent(QMouseEvent* qEvent)
    {
        switch (qEvent->button())
        {
        case Qt::MouseButton::LeftButton:
        {
            m_startPos = qEvent->pos();
            m_createdShape = m_parent->addShape<T>(m_startPos);
            m_parent->update();
            break;
        }
        default:
        {

        }
        }
    }
    void handleMouseMoveEvent(QMouseEvent* qEvent)
    {
        if (m_createdShape != nullptr)
        {
            QPoint size = qEvent->pos() - m_startPos;
            m_createdShape->setSize(QSize(size.x(), size.y()));
            m_parent->update();
        }
    }
    void handleMouseReleaseEvent(QMouseEvent* qEvent)
    {
        switch (qEvent->button())
        {
        case Qt::MouseButton::LeftButton:
        {
            m_createdShape = nullptr;
            break;
        }
        default:
        {

        }
        }
    }

protected:
    QPoint m_startPos;
    Shape* m_createdShape = nullptr;
};
