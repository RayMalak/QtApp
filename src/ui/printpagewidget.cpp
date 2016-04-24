/**
  @file printpagewidget.cpp
  @brief 功能页面之 打印取件页面
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/

#include "printpagewidget.h"
#include "ui_printpagewidget.h"
#include "numkeyboard.h"
#include <QMessageBox>

PrintPageWidget::PrintPageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintPageWidget)
{
    ui->setupUi(this);

    /// add child page
    numKeyboard = new NumKeyboard(ui->printPageIDCode);
    QVBoxLayout* layout = new QVBoxLayout(ui->printPageIDCode);
    layout->addWidget(numKeyboard);
    ui->printPageIDCode->setLayout(layout);


    /// bind signal and slot
    connect(ui->pushButtonReturn, SIGNAL(clicked(bool)), SIGNAL(sig_return()));
    connect(ui->pushButtonBarcode, SIGNAL(clicked(bool)), SLOT(toBarcodePage()));
    connect(ui->pushButtonIDCode, SIGNAL(clicked(bool)), SLOT(toIDCodePage()));
    connect(numKeyboard, SIGNAL(sig_inputFinished(qlonglong)), SLOT(idCodeInputFinished(qlonglong)));


    toIDCodePage();

}


PrintPageWidget::~PrintPageWidget()
{
    delete ui;
}

void PrintPageWidget::toIDCodePage()
{
    numKeyboard->Empty();
    ui->fnPageStack->setCurrentWidget(ui->printPageIDCode);
    ui->pushButtonBarcode->setDown(false);
    ui->pushButtonIDCode->setDown(true);
}

void PrintPageWidget::toBarcodePage()
{
    ui->fnPageStack->setCurrentWidget(ui->printPageBarcode);
    ui->pushButtonBarcode->setDown(true);
    ui->pushButtonIDCode->setDown(false);
}


void showTipWindow(QWidget* parent, QString strTip)
{
    QMessageBox msgBox(parent);
    msgBox.setStandardButtons(QMessageBox::Cancel);
    msgBox.setText(strTip);
    msgBox.exec();
}

bool isIdCodeValid(qlonglong idNum)
{
    return (123 == idNum);
}

void PrintPageWidget::idCodeInputFinished(qlonglong numInput)
{
    /// 弹出提示窗口
    showTipWindow(this, tr("正在验证，请稍后..."));

    /// 验证输入的验证码
    if(isIdCodeValid(numInput))
        toBarcodePage();
    else
        toIDCodePage();
}




