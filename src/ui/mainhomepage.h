/**
  @file mainhomepage.h
  @brief 主页面，默认显示的页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#ifndef MAINHOMEPAGE_H
#define MAINHOMEPAGE_H

#include <QWidget>

namespace Ui {
class MainHomePage;
}

class MainHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit MainHomePage(QWidget *parent = 0);
    ~MainHomePage();

signals:
    /// signal when click print
    void sig_toPrint();

    /// signal when click scan
    void sig_toScan();

private:
    Ui::MainHomePage *ui;
};

#endif // MAINHOMEPAGE_H
