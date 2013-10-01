#ifndef TWOWAYACTION_H
#define TWOWAYACTION_H

class QString;

#include <QAction>

namespace sj
{

class TwoWayAction : public QAction
{
    Q_OBJECT
public:
    TwoWayAction(QString first, QString second,
                 QWidget* parent = nullptr);

signals:
    void firstStateTriggered();
    void secondStateTriggered();

private slots:
    void changeState();

private:

    bool _state;
    QString _first;
    QString _second;
};

} // namespace sj

#endif // TWOWAYACTION_H
