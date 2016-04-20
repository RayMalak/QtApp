/**
  @file keyinput.h
  @brief 数字键盘widget
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#ifndef KEYINPUT_H
#define KEYINPUT_H

#include <QWidget>

namespace Ui {
class NumKeyInput;
}

class KeyInput : public QWidget
{
    Q_OBJECT

public:
    explicit KeyInput(QWidget *parent = 0);
    ~KeyInput();

private slots:
    void numClick();
    void on_pbOK_clicked();
    void on_pbClean_clicked();

signals:
    /// 输入完成后触发的信号
    void sig_inputFinished(qlonglong);


public:
    Ui::NumKeyInput *ui;
};

#endif // KEYINPUT_H
