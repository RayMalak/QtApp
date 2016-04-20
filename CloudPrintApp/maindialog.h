/**
  @file maindialog.h
  @brief 主窗口
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}
class KeyInput;

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


public slots:
    /// 用于处理切换页面信号
    void switch_page();

    /// 用于接收数字键盘输入结束信号
    void keyinput_finished(qlonglong);

    /// 点击验证码取件
    void on_pushButtonFromID_clicked();

    /// 几点二维码取件
    void on_pushButtonFromBarcode_clicked();

    /// 返回主页
    void on_pushButtonReturnHome_clicked();


private:
    /// 打印取件
    void toPrintAcquire();

    /// 证件复印
    void toCardCopy();


private:
    Ui::MainDialog *ui;
    KeyInput       *pageKeyInput;
};

#endif // MAINDIALOG_H
