#ifndef KEYINPUT_H
#define KEYINPUT_H

#include <QWidget>

namespace Ui {
class KeyInput;
}

class KeyInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeyInputWidget(QWidget *parent = 0);
    ~KeyInputWidget();

public slots:
    void numClick();
    void cleanClick();

private:
    Ui::KeyInput *ui;
};

#endif // KEYINPUT_H
