/**
  @file mainfunctionpage.cpp
  @brief 功能页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "mainfunctionpage.h"
#include "ui_mainfunctionpage.h"
#include "printpagewidget.h"
#include <QMessageBox>


MainFunctionPage::MainFunctionPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainFunctionPage)
{
    ui->setupUi(this);

    /// add child page
    printPage = new PrintPageWidget(this);

    ui->fnPageStack->addWidget(printPage);
    ui->fnPageStack->setCurrentIndex(0);

    /// bind signal and slot
    connect(printPage, SIGNAL(sig_return()), SIGNAL(sig_toHome()));
}


MainFunctionPage::~MainFunctionPage()
{
    delete ui;
}

void MainFunctionPage::toPrintPage()
{
    ui->fnPageStack->setCurrentWidget(printPage);
}

void MainFunctionPage::toScanPage()
{
    QMessageBox::information(this, tr("Hi!"), tr("Scan page not finish yet!"));
    emit sig_toHome();
}
