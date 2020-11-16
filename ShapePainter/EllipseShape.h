#pragma once
#include "Shape.h"
#include <QString>
#include <QRect>

class EllipseShape : public Shape
{
public:
	void draw(QPainter& qPainter);
	static QString getNameS()
	{
		return "Ellipse";
	}
	virtual QString getName()
	{
		return getNameS();
	};
private:
};

