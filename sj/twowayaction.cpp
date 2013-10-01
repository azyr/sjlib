#include "twowayaction.h"
#include <QString>

using namespace sj;

TwoWayAction::TwoWayAction(QString first, QString second,
    QWidget* parent)
    : QAction(first, parent)
    , _state(true)
    , _first(first)
    , _second(second)
{
    connect(this, SIGNAL(triggered()), this, SLOT(changeState()));
}

void TwoWayAction::changeState()
{
    _state = !_state;

    if (_state)
    {
        setIconText(_first);
        emit(secondStateTriggered());
    }
    else
    {
        setIconText(_second);
        emit(firstStateTriggered());
    }
}
