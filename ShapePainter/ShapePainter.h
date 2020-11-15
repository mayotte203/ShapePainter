#pragma once

#include <QtWidgets/QMainWindow>
#include <QToolBar>
#include "PaintArea.h"

class ShapePainter : public QMainWindow
{
    Q_OBJECT

public:
    ShapePainter(QWidget *parent = Q_NULLPTR);
    

private:
    PaintArea* m_paintArea;
    QToolBar* m_toolBar;

    void createToolBar();
    void onNewFileButton();
    void onOpenFileButton();
    void onSaveFileButton();
    void onEllipseShapeButton();
    void onStarShapeButton();
    void onTriangleShapeButton();
    void onMoveButton();
    void onEraseButton();
    void onLineButton();
    void onLineMoveButton();
    void onLineEraseButton();
};
