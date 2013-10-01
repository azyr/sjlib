#ifndef FONTSELECTOR_H
#define FONTSELECTOR_H

#include <QWidget>

class QLabel;

namespace sj
{

class FontSelector : public QWidget
{
    Q_OBJECT

public:
    FontSelector(QWidget* parent = nullptr);

    const QFont& selectedFont() const { return _font; }

public slots:
    void setSelectedFont(const QFont& font);

signals:
    void fontChanged(const QFont& font);

protected:
    void changeEvent(QEvent* e) override;

protected slots:
    void chooseFont();

private:
    QFont _font;
    QLabel* _demo;
};

} // namespace sj

#endif // FONTSELECTOR_H
