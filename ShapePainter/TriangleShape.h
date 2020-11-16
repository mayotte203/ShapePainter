#pragma once
#include "Shape.h"
class TriangleShape :
    public Shape
{
public:
	void draw(QPainter& qPainter);
	static QString getNameS()
	{
		return "Triangle";
	}
	virtual QString getName()
	{
		return getNameS();
	};
private:
};

