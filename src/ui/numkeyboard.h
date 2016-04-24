/**
  @file numkeyboard.h
  @brief 数字键盘widget
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#ifndef NUMKEYBOARD_H
#define NUMKEYBOARD_H

#include <QWidget>

namespace Ui {
class NumKeyboard;
}

class NumKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit NumKeyboard(QWidget *parent = 0);
    ~NumKeyboard();

    /// 清空
    void Empty();

private slots:
    void numClicked();
    void okClicked();
    void cleanClicked();

signals:
    /// 输入完成后触发的信号，信号携带当前现实的数字
    void sig_inputFinished(qlonglong);


public:
    Ui::NumKeyboard *ui;
};

#endif // NUMKEYBOARD_H
