#include "colorbutton.h"

#include <QColorDialog>

using namespace sj;

sj::ColorButton::ColorButton(QWidget *parent) :
    QToolButton(parent)
{
    setText("");
    connect(this, SIGNAL(clicked()), SLOT(chooseColor()));
}

void ColorButton::setColor(const QColor& color)
{
    _color = color;
    QPixmap pixmap(QSize(32, 32));
    pixmap.fill(color);
    setIcon(pixmap);

    emit colorChanged(color);
}

void ColorButton::chooseColor()
{
    QColor color = QColorDialog::getColor(_color, this);

    if (color.isValid())
        setColor(color);
}
