#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "drawer.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slider->setOrientation(Qt::Horizontal);

    ui->slider->setMinimum(0);
    ui->slider->setMaximum(10);
    ui->slider->setValue(0);

    ui->slider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    height: 8px;"
        "    background: #303030;"
        "    border-radius: 4px;"
        "}"

        "QSlider::sub-page:horizontal {"
        "    background: #4CAF50;"
        "    border-radius: 4px;"
        "}"

        "QSlider::add-page:horizontal {"
        "    background: #303030;"
        "    border-radius: 4px;"
        "}"

        "QSlider::handle:horizontal {"
        "    background: #FFFFFF;"
        "    border: 2px solid #4CAF50;"
        "    width: 18px;"
        "    height: 18px;"
        "    margin: -6px 0;"
        "    border-radius: 9px;"
        "}"

        "QSlider::handle:horizontal:hover {"
        "    background: #4CAF50;"
        "}"
        );
    connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::changeFractal);

    Drawer f(this);
    f.DrawFractals();
    ui->slider->setMaximum(fractal_count - 1);

}

void MainWindow::drawPoint(QPointF point)
{
    points.append(point);
    update();
}

void MainWindow::draw() {
    update();
}

void MainWindow::changeFractal() {
    points = fractals[ui->slider->value()];
    draw();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(Qt::red);
    for (const QPointF &point : points) {
        painter.drawEllipse(point, 0.001, 0.001);
    }
    for (int i = 1; i < points.size(); ++i) {
        painter.drawLine(points[i - 1], points[i]);
    }
    painter.drawLine(points[points.length() - 1], points[0]);
}

MainWindow::~MainWindow()
{
    delete ui;
}
