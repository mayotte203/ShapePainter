#pragma once
class EmptyWidget :public QWidget
{
public:
    EmptyWidget(QWidget* parent = Q_NULLPTR)
        : QWidget(parent) {};
};

EmptyWidget* separator = new EmptyWidget;
separator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

m_toolBar->addWidget(separator);

QMovie* cow;
constexpr char jifs[3][20] = { "Resources/cow.gif",
    "Resources/jam.gif",
    "Resources/sama.gif" };
srand(time(NULL));
cow = new QMovie(jifs[rand() % 3]);
cow->setScaledSize(QSize(20, 20));
QLabel* cowLabel = new QLabel();
cowLabel->setMovie(cow);
cow->start();

m_toolBar->addWidget(cowLabel);