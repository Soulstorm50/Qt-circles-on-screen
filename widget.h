#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "qpainter.h"
#include <QPushButton>
#include <QVariant>
#include <QDebug>
#include <windows.h>

class Widget : public QWidget {
    Q_OBJECT
    int dx;
    int dy;
    QRect circleBounds;
    QRect circleBounds2;

public:
    Widget(QWidget * parent) : QWidget(parent) {


        srand(time(0));
            dx = rand() % 30;
            dy = rand() % 30;
            circleBounds.setLeft(34);
            circleBounds.setTop(21);
            circleBounds.setWidth(50);
            circleBounds.setHeight(50);



            QTimer * timer = new QTimer();
            connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
            timer->start(100);

    }

    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.setPen(Qt::NoPen);  // circ color
        painter.setBrush(Qt::white);  // desktop color
        painter.drawRect(this->rect());

        if ( ( circleBounds.left() + dx ) < 0 || ( circleBounds.right() + dx ) > this->rect().width() )
            dx = -dx;
        if ( ( circleBounds.top() + dy ) < 0 || ( circleBounds.bottom() + dy ) > this->rect().height() )
            dy = -dy;
        circleBounds.setLeft(circleBounds.left() + dx);
        circleBounds.setTop(circleBounds.top() + dy);
        circleBounds.setWidth(50);
        circleBounds.setHeight(50);
        painter.setBrush(Qt::blue);
        painter.drawEllipse(circleBounds);




    }
};

#endif // WIDGET_H
