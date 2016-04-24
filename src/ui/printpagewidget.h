/**
  @file printpagewidget.h
  @brief 功能页面之 打印取件页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/

#ifndef PRINTPAGEWIDGET_H
#define PRINTPAGEWIDGET_H

#include <QWidget>

namespace Ui {
class PrintPageWidget;
}
class NumKeyboard;

class PrintPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PrintPageWidget(QWidget *parent = 0);
    ~PrintPageWidget();

signals:
    /// 点击 返回或取消 触发的信号
    void sig_return();

private slots:
    /// 切换到验证码取件页面
    void toIDCodePage();

    /// 切换到条形码取件页面
    void toBarcodePage();

    /// 验证码输入完成
    void idCodeInputFinished(qlonglong numInput);

    /// 条形码扫描完成
    //void barcodeScanFinished();


private:
    Ui::PrintPageWidget *ui;
    NumKeyboard         *numKeyboard;
};

#endif // PRINTPAGEWIDGET_H
