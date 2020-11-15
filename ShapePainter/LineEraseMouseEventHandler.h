#pragma once
#include "PaintArea.h"

class PaintArea::LineEraseMouseEventHandler : public PaintArea::IMouseEventHandler
{
public:
    LineEraseMouseEventHandler(PaintArea* parent) : IMouseEventHandler(parent) {};
    void handleMousePressEvent(QMouseEvent* qEvent);
    void handleMouseMoveEvent(QMouseEvent* qEvent);
    void handleMouseReleaseEvent(QMouseEvent* qEvent);
private:
    constexpr static float m_threshold = 4.0f;
};
