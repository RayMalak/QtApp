#ifndef KEYINPUT_H
#define KEYINPUT_H

#include <QWidget>

namespace Ui {
class KeyInput;
}

class KeyInput : public QWidget
{
    Q_OBJECT

public:
    explicit KeyInput(QWidget *parent = 0);
    ~KeyInput();

public slots:
    void numClick();
    void cleanClick();

private:
    Ui::KeyInput *ui;
};

#endif // KEYINPUT_H
