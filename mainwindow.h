#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPointF>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<QPointF> points;
    QVector<QVector<QPointF>> fractals;
    void drawPoint(QPointF point);
    void draw();
    void changeFractal();
    const int fractal_count = 9;

private:
    void paintEvent(QPaintEvent *event) override;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
