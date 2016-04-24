#include "maindialog.h"
#include "ui_maindialog.h"
#include "keyinput.h"


MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    keyInput = new KeyInputWidget(this);
    ui->verticalLayoutPrintPage->addWidget(keyInput);

    ui->stackedWidgetLeft->setCurrentIndex(0);
    ui->stackedWidgetRight->setCurrentIndex(0);
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

void MainDialog::on_keyinput_ok()
{
    ui->pushButtonReturnHome->click();
}

