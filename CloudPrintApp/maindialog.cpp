#include "maindialog.h"
#include "ui_maindialog.h"
#include "keyinput.h"


MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    keyInput = new KeyInput(ui->pagePrint);

    //ui->pagePrint->layout()->addWidget(keyInput);

    //ui->verticalLayoutPrintPage->addWidget(keyInput);
    ui->pagePrint->layout()->addWidget(keyInput);
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_switch_page()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if(button == ui->pushButtonPrint)
    {
        ui->stackedWidgetLeft->setCurrentWidget(ui->pagePrint);
        ui->stackedWidgetRight->setCurrentWidget(ui->pageFlow);
    }
    else if(button == ui->pushButtonReturnHome)
    {
        ui->stackedWidgetLeft->setCurrentWidget(ui->pageAd);
        ui->stackedWidgetRight->setCurrentWidget(ui->pageHome);
    }
}

