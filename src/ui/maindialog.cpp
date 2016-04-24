/**
  @file maindialog.cpp
  @brief 主窗口，拥有一个大的stackedWidget，用于切换页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "maindialog.h"
#include "ui_maindialog.h"
#include "mainhomepage.h"
#include "mainfunctionpage.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);


    //setWindowState(Qt::WindowFullScreen);

    /// add child page
    homePage = new MainHomePage(this);
    functionPage = new MainFunctionPage(this);

    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->addWidget(functionPage);


    /// bind signal & slot
    connect(homePage, SIGNAL(sig_toPrint()), this, SLOT(toPrintFunctionPage()));
    connect(homePage, SIGNAL(sig_toScan()), this, SLOT(toScanFunctionPage()));

    connect(functionPage, SIGNAL(sig_toHome()), this, SLOT(toHomePage()));

    toHomePage();
    //toFunctionPage();

}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::toHomePage()
{
    ui->stackedWidget->setCurrentWidget(homePage);
}

void MainDialog::toPrintFunctionPage()
{
    ui->stackedWidget->setCurrentWidget(functionPage);
    functionPage->toPrintPage();
}

void MainDialog::toScanFunctionPage()
{
    ui->stackedWidget->setCurrentWidget(functionPage);
    functionPage->toScanPage();
}


