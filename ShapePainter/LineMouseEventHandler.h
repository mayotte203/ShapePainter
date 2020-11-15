#pragma once
#include "PaintArea.h"

class PaintArea::LineMouseEventHandler : public PaintArea::IMouseEventHandler
{
public:
    LineMouseEventHandler(PaintArea* parent) : IMouseEventHandler(parent) {};
    void handleMousePressEvent(QMouseEvent* qEvent);
    void handleMouseMoveEvent(QMouseEvent* qEvent);
    void handleMouseReleaseEvent(QMouseEvent* qEvent);
private:
    Shape* m_firstShape = nullptr;
    Shape* m_secondShape = nullptr;
};
