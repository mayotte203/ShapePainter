#pragma once
#include "Shape.h"
class StarShape :
    public Shape
{
public:
    void draw(QPainter& qPainter);
	static QString getNameS()
	{
		return "Star";
	}
	virtual QString getName()
	{
		return getNameS();
	};
private:
};

