#pragma once
#include "PaintArea.h"

class PaintArea::EraseMouseEventHandler : public PaintArea::IMouseEventHandler
{
public:
    EraseMouseEventHandler(PaintArea* parent) : IMouseEventHandler(parent) {};
    void handleMousePressEvent(QMouseEvent* qEvent);
    void handleMouseMoveEvent(QMouseEvent* qEvent);
    void handleMouseReleaseEvent(QMouseEvent* qEvent);
private:

};
