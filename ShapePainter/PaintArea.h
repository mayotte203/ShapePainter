#pragma once
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "Shape.h"
#include "Line.h"

class PaintArea :
    public QWidget
{
public:
    PaintArea(QWidget* parent = Q_NULLPTR);

public:
    class IMouseEventHandler;
    template <class T>
    class ShapeMouseEventHandler;
    class MoveMouseEventHandler;
    class EraseMouseEventHandler;
    class LineMouseEventHandler;
    class LineEraseMouseEventHandler;

    template <class T>
    void setMouseEventHandler()
    {
        m_mouseEventHandler = std::make_unique<T>(this);
    };
    void newFile();

private:
    static constexpr float DISTANCE_THRESHOLD = 4.0f;

    std::vector<std::unique_ptr<Shape>> m_shapes;
    std::vector<std::unique_ptr<Line>> m_lines;
    std::unique_ptr<IMouseEventHandler> m_mouseEventHandler;

    template <class T>
    Shape* addShape(QPoint pos) {
        m_shapes.push_back(std::make_unique<T>());
        m_shapes.back()->setPos(pos);
        return m_shapes.back().get();
    };
    void eraseShape(QPoint point);
    void addLine(Shape* firstShape, Shape* secondShape);
    void deleteConnectedLine(Shape* shape);
    void eraseLine(QPoint point);
    void paintEvent(QPaintEvent* qEvent);
    void mousePressEvent(QMouseEvent* qEvent);
    void mouseMoveEvent(QMouseEvent* qEvent);
    void mouseReleaseEvent(QMouseEvent* qEvent);
};

class PaintArea::IMouseEventHandler
{
public:
    IMouseEventHandler(PaintArea* parent) : m_parent(parent) {};
    virtual void handleMousePressEvent(QMouseEvent* qEvent) = 0;
    virtual void handleMouseMoveEvent(QMouseEvent* qEvent) = 0;
    virtual void handleMouseReleaseEvent(QMouseEvent* qEvent) = 0;
    virtual ~IMouseEventHandler() {};
protected:
    PaintArea* const m_parent;
};
