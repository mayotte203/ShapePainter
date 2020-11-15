#pragma once
#include "PaintArea.h"

class PaintArea::MoveMouseEventHandler : public PaintArea::IMouseEventHandler
{
public:
    MoveMouseEventHandler(PaintArea* parent) : IMouseEventHandler(parent) {};
    void handleMousePressEvent(QMouseEvent* qEvent);
    void handleMouseMoveEvent(QMouseEvent* qEvent);
    void handleMouseReleaseEvent(QMouseEvent* qEvent);
private:
    QPoint m_startPos;
    Shape* m_selectedShape = nullptr;
};
