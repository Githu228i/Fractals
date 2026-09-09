#include "drawer.h"
#include <cmath>

Drawer::Drawer(MainWindow *window) {
    main = window;
}

void Drawer::DrawFractals() {
    for (int q = 0; q <= main -> fractal_count; q++) {
        if (main->fractals.empty()) {
            main->fractals.push_back(QVector<QPointF>({QPointF(600, 730.94), QPointF(1000, 38.12), QPointF(1400, 730.94), QPointF(600, 730.94)}));
        } else {
            main->fractals.push_back(QVector<QPointF>());
            for (int i = 1; i < main->fractals[main->fractals.length() - 2].length(); i++) {
                QPointF start = main->fractals[main->fractals.length() - 2][i-1];
                QPointF end = main->fractals[main->fractals.length() - 2][i];
                QPointF right((start.x() + 2 * end.x()) / 3, (start.y() + 2 * end.y()) / 3);
                QPointF left((2 * start.x() + end.x()) / 3, (2 * start.y() + end.y()) / 3);
                QPointF mid ((start.x() + end.x()) / 2, (start.y() + end.y()) / 2);
                double dx = end.x() - start.x();
                double dy = end.y() - start.y();
                QPointF spike(mid.x() + std::sqrt(3) / 6 * dy, mid.y() - std::sqrt(3) / 6 * dx);
                main->fractals[main->fractals.length() - 1].push_back(start);
                main->fractals[main->fractals.length() - 1].push_back(left);
                main->fractals[main->fractals.length() - 1].push_back(spike);
                main->fractals[main->fractals.length() - 1].push_back(right);
            }
            main->fractals[main->fractals.length() - 1].push_back(main->fractals[main->fractals.length() - 2][0]);
        }
    }
    main->points = main->fractals[0];
    main->draw();
}
