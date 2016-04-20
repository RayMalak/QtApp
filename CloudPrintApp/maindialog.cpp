/**
  @file maindialog.cpp
  @brief 主窗口
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "maindialog.h"
#include "ui_maindialog.h"
#include "keyinput.h"


MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);


    /// add child page

    /// 验证码取件页面
    pageKeyInput = new KeyInput(this);
    //ui->stackedWidgetInput->addWidget(pageKeyInput);
    ui->stackedWidgetInput->insertWidget(0, pageKeyInput);
    /// 二维码取件页面


    /// init display
    ui->stackedWidgetLeft->setCurrentIndex(0);
    ui->stackedWidgetRight->setCurrentIndex(0);


    /// bind signal & slot

    connect(pageKeyInput, SIGNAL(sig_inputFinished(qlonglong)), SLOT(keyinput_finished(qlonglong)));
    connect(ui->pushButtonPrint, SIGNAL(clicked(bool)), SLOT(switch_page()));
    connect(ui->pushButtonScan, SIGNAL(clicked(bool)), SLOT(switch_page()));
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::switch_page()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    /// 打印取件
    if(button == ui->pushButtonPrint){
        toPrintAcquire();
    }
    /// 扫描取件
    else if(button == ui->pushButtonScan){
        toCardCopy();
    }
}


void MainDialog::keyinput_finished(qlonglong inputNumReturn)
{
    /// 进行验证码校验
    /// test
    QString title;
    title.sprintf("%lld", inputNumReturn);
    this->setWindowTitle(title);

    /// 进入等待窗口
}


/// 验证码取件
void MainDialog::on_pushButtonFromID_clicked()
{
    ui->stackedWidgetInput->setCurrentWidget(pageKeyInput);
    ui->pushButtonFromID->setDown(true);
    ui->pushButtonFromBarcode->setDown(false);
}

/// 二维码取件
void MainDialog::on_pushButtonFromBarcode_clicked()
{
    ui->stackedWidgetInput->setCurrentWidget(ui->pageScanBarcode);
    ui->pushButtonFromBarcode->setDown(true);
    ui->pushButtonFromID->setDown(false);
}

/// 返回主页
void MainDialog::on_pushButtonReturnHome_clicked()
{
    ui->stackedWidgetLeft->setCurrentWidget(ui->pageAd);
    ui->stackedWidgetRight->setCurrentWidget(ui->pageHome);
}


/// 切换到打印取件页面
void MainDialog::toPrintAcquire()
{
    ui->stackedWidgetLeft->setCurrentWidget(ui->pagePrint);
    ui->stackedWidgetRight->setCurrentWidget(ui->pageFlow);

    /// 默认验证码取件
    ui->pushButtonFromID->click();
}

/// 切换到证件复印页面
void MainDialog::toCardCopy()
{
    toPrintAcquire();
}


