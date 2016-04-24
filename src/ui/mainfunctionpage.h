/**
  @file mainfunctionpage.h
  @brief 功能页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#ifndef MAINFUNCTIONPAGE_H
#define MAINFUNCTIONPAGE_H

#include <QWidget>

namespace Ui {
class MainFunctionPage;
}
class PrintPageWidget;

class MainFunctionPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainFunctionPage(QWidget *parent = 0);
    ~MainFunctionPage();

signals:
    /// signal when return to home
    void sig_toHome();

public:
    void toPrintPage();
    void toScanPage();

private:
    Ui::MainFunctionPage    *ui;
    PrintPageWidget         *printPage;
};

#endif // MAINFUNCTIONPAGE_H
