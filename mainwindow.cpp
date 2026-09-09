#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawPoint(QPoint(100, 500));
    drawPoint(QPoint(100, 100));
}

void MainWindow::drawPoint(QPoint point)
{
    points.append(point);
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(Qt::red);
    for (const QPoint &point : points) {
        painter.drawEllipse(point, 1, 1);
    }
    for (int i = 1; i < points.size(); ++i) {
        painter.drawLine(points[i - 1], points[i]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
