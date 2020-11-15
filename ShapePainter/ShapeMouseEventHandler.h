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
            parent->addShape<T>(m_startPos);
            parent->update();
            break;
        }
        default:
        {

        }
        }
    }
    void handleMouseMoveEvent(QMouseEvent* qEvent)
    {
        if (!parent->m_shapes.empty())
        {
            QPoint size = qEvent->pos() - m_startPos;
            parent->m_shapes.back()->setSize(QSize(size.x(), size.y()));
            parent->update();
        }
    }
    void handleMouseReleaseEvent(QMouseEvent* qEvent)
    {

    }

protected:
    QPoint m_startPos;
};
