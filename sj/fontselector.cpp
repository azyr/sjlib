#include "fontselector.h"

#include <QFontDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QEvent>

using namespace sj;

FontSelector::FontSelector(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QPushButton* chooseButton = new QPushButton("Choose...", this);
    connect(chooseButton, SIGNAL(clicked()), SLOT(chooseFont()));

    layout->addWidget(_demo = new QLabel("Font"));
    layout->addWidget(chooseButton);
    layout->setContentsMargins(0, 0, 0, 0);

    _demo->setFrameStyle(QFrame::StyledPanel);
    _demo->setFrameShadow(QFrame::Sunken);
    _demo->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
}

void FontSelector::setSelectedFont(const QFont& font)
{
    _font = font;
    QString text = QString("%1 %2pt").arg(font.family()).arg(font.pointSize());
    _demo->setText(text);
    _demo->setFont(font);
    emit fontChanged(font);
}

void FontSelector::chooseFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, _demo->font());
    if (ok)
        setSelectedFont(font);
}

void FontSelector::changeEvent(QEvent* e)
{
    if (e->type() == QEvent::StyleChange)
        _demo->setFont(_font);
}
