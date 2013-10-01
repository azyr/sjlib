#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QToolButton>

namespace sj
{

class ColorButton : public QToolButton
{
    Q_OBJECT

public:
    explicit ColorButton(QWidget* parent = nullptr);

    void setColor(const QColor& color);
    QColor color() const { return _color; }

signals:
    void colorChanged(const QColor& color);

private slots:
    void chooseColor();

private:
    QColor _color;
};

} // namespace sj

#endif // COLORBUTTON_H
