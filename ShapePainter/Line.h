#pragma once
#include "Drawable.h"
#include "Shape.h"

class Line :
    public Drawable
{
public:
	Line();
	Line(Shape* firstShape, Shape* secondShape);
	virtual ~Line() {};
	void draw(QPainter& qPainter);
	bool isConnnected(Shape* shape);
	float distanceTo(QPoint point);
private:
	Shape* m_firstShape = nullptr;
	Shape* m_secondShape = nullptr;

	friend class PaintAreaSerializer;
};

