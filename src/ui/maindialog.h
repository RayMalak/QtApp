/**
  @file maindialog.h
  @brief 主窗口，拥有一个大的stackedWidget，用于切换页面
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
class MainHomePage;
class MainFunctionPage;

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


private slots:
    void toHomePage();
    void toPrintFunctionPage();
    void toScanFunctionPage();

private:
    Ui::MainDialog    *ui;
    MainHomePage      *homePage;
    MainFunctionPage  *functionPage;
};

#endif // MAINDIALOG_H
