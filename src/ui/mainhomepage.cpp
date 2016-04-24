/**
  @file mainhomepage.cpp
  @brief 主页面，默认显示的页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "mainhomepage.h"
#include "ui_mainhomepage.h"

MainHomePage::MainHomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainHomePage)
{
    ui->setupUi(this);

    connect(ui->pushBtnToPrint, SIGNAL(clicked(bool)), this, SIGNAL(sig_toPrint()));
    connect(ui->pushBtnToScan, SIGNAL(clicked(bool)), this, SIGNAL(sig_toScan()));
}

MainHomePage::~MainHomePage()
{
    delete ui;
}

