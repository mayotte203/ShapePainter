#include "ShapePainter.h"
#include <QLabel>
#include <QMovie>
#include "ShapeMouseEventHandler.h"
#include "MoveMouseEventHandler.h"
#include "EraseMouseEventHandler.h"
#include "LineMouseEventHandler.h"
#include "LineEraseMouseEventHandler.h"
#include "EllipseShape.h"
#include "StarShape.h"
#include "TriangleShape.h"

ShapePainter::ShapePainter(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(640, 480);
    m_paintArea = new PaintArea();
    this->setCentralWidget(m_paintArea);
    createToolBar();
}

void ShapePainter::createToolBar()
{
    m_toolBar = addToolBar("actions");
    m_toolBar->addAction(QIcon(":/ShapePainter/NewIcon"), "New File", this, &ShapePainter::onNewFileButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/OpenIcon"), "Open File", this, &ShapePainter::onOpenFileButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/SaveIcon"), "Save File", this, &ShapePainter::onSaveFileButton);
    m_toolBar->addSeparator();
    m_toolBar->addAction(QIcon(":/ShapePainter/EllipseIcon"), "Ellipse", this, &ShapePainter::onEllipseShapeButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/StarIcon"), "Star", this, &ShapePainter::onStarShapeButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/TriangleIcon"), "Triangle", this, &ShapePainter::onTriangleShapeButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/MoveIcon"), "Move", this, &ShapePainter::onMoveButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/EraseIcon"), "Erase", this, &ShapePainter::onEraseButton);
    m_toolBar->addSeparator();
    m_toolBar->addAction(QIcon(":/ShapePainter/LineIcon"), "Line", this, &ShapePainter::onLineButton);
    m_toolBar->addAction(QIcon(":/ShapePainter/LineEraseIcon"), "Line erase", this, &ShapePainter::onLineEraseButton);
    #include "CowInjector.h"
}

void ShapePainter::onNewFileButton()
{
    m_paintArea->newFile();
    m_paintArea->update();
}

void ShapePainter::onOpenFileButton()
{
}

void ShapePainter::onSaveFileButton()
{
}

void ShapePainter::onEllipseShapeButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::ShapeMouseEventHandler<EllipseShape>>();
}

void ShapePainter::onStarShapeButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::ShapeMouseEventHandler<StarShape>>();
}

void ShapePainter::onTriangleShapeButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::ShapeMouseEventHandler<TriangleShape>>();
}

void ShapePainter::onMoveButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::MoveMouseEventHandler>();
}

void ShapePainter::onEraseButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::EraseMouseEventHandler>();
}

void ShapePainter::onLineButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::LineMouseEventHandler>();
}

void ShapePainter::onLineMoveButton()
{
}

void ShapePainter::onLineEraseButton()
{
    m_paintArea->setMouseEventHandler<PaintArea::LineEraseMouseEventHandler>();
}
