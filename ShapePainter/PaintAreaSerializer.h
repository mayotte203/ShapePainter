#pragma once
#include "PaintArea.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRect>
#include <QJsonArray>
#include <QFile>
#include "EllipseShape.h"
#include "StarShape.h"
#include "TriangleShape.h"

class PaintAreaSerializer
{
public:
	PaintAreaSerializer(PaintArea* paintArea) : m_paintArea(paintArea) {
		initializeShapes();
	};
	void saveToFile(QString filePath)
	{
		QJsonObject jsonObject;
		QJsonArray shapesArray;
		for (auto& s : m_paintArea->m_shapes)
		{
			QJsonObject shape;
			QRect shapeRect = s->getRect();
			shape["name"] = s->getName();
			shape["x"] = shapeRect.topLeft().x();
			shape["y"] = shapeRect.topLeft().y();
			shape["w"] = shapeRect.size().width();
			shape["h"] = shapeRect.size().height();
			shapesArray.append(shape);
		}
		jsonObject["shapes"] = shapesArray;
		QJsonArray linesArray;
		for (auto& l : m_paintArea->m_lines)
		{
			QJsonObject line;
			line["first"] = findIndex(l->m_firstShape);
			line["second"] = findIndex(l->m_secondShape);
			linesArray.append(line);
		}
		jsonObject["lines"] = linesArray;
		QJsonDocument document(jsonObject);
		QFile saveFile(filePath);
		saveFile.open(QIODevice::WriteOnly);
		saveFile.write(document.toJson());
		saveFile.close();
	}
	int findIndex(Shape* shape)
	{
		for (int i = 0; i < m_paintArea->m_shapes.size(); ++i)
		{
			if (m_paintArea->m_shapes[i].get() == shape)
			{
				return i;
			}
		}
	}
	void loadFromFile(QString filePath)
	{
		std::vector<std::unique_ptr<Shape>> shapesV;
		std::vector<std::unique_ptr<Line>> linesV;
		QFile loadFile(filePath);
		loadFile.open(QIODevice::ReadOnly);
		QByteArray saveData = loadFile.readAll();
		QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
		QJsonObject jsonObject = loadDoc.object();
		if (jsonObject.contains("shapes") && jsonObject["shapes"].isArray())
		{
			QJsonArray shapesArray = jsonObject["shapes"].toArray();
			for (auto s = shapesArray.begin(); s < shapesArray.end(); ++s)
			{
				if (s->isObject())
				{
					QJsonObject shape = s->toObject();
					if (shape.contains("name") && shape["name"].isString()
						&& shape.contains("x") && shape["x"].isDouble()
						&& shape.contains("y") && shape["y"].isDouble()
						&& shape.contains("w") && shape["w"].isDouble()
						&& shape.contains("h") && shape["h"].isDouble())
					{
						shapesV.push_back(m_factories[shape["name"].toString()]());
						shapesV.back()->setPos(QPoint(shape["x"].toInt(), shape["y"].toInt()));
						shapesV.back()->setSize(QSize(shape["w"].toInt(), shape["h"].toInt()));
					}
				}
			}
		}
		if (jsonObject.contains("lines") && jsonObject["lines"].isArray())
		{
			QJsonArray linesArray = jsonObject["lines"].toArray();
			for (auto l = linesArray.begin(); l < linesArray.end(); ++l)
			{
				if (l->isObject())
				{
					QJsonObject line = l->toObject();
					if (line.contains("first") && line["first"].isDouble()
						&& line.contains("second") && line["second"].isDouble())
					{
						int firstIndex = line["first"].toInt();
						int secondIndex = line["second"].toInt();
						linesV.push_back(std::make_unique<Line>(shapesV[firstIndex].get(),
																shapesV[secondIndex].get()));
					}
				}
			}
		}
		m_paintArea->m_shapes = std::move(shapesV);
		m_paintArea->m_lines = std::move(linesV);
		m_paintArea->update();
		loadFile.close();
	}
	void initializeShapes()
	{
		registerShape<EllipseShape>();
		registerShape<StarShape>();
		registerShape<TriangleShape>();
	}
	template <typename T>
	void registerShape()
	{
		m_factories[T::getNameS()] = [this]()
		{
			return std::make_unique<T>();
		};
	}
private:
	std::map<QString, std::function<std::unique_ptr<Shape>()>> m_factories;
	PaintArea* m_paintArea;
};

