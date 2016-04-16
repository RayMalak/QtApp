#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    connect(ui->pushButtonPrint, SIGNAL(clicked(bool)), SLOT(on_print()));
    connect(ui->pushButtonReturnHome, SIGNAL(clicked(bool)), SLOT(on_to_home()));
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_print()
{
    ui->stackedWidgetLeft->setCurrentWidget(ui->pagePrint);
    ui->stackedWidgetRight->setCurrentWidget(ui->pageFlow);
}

void MainDialog::on_scan()
{

}

void MainDialog::on_to_home()
{
    ui->stackedWidgetLeft->setCurrentWidget(ui->pageAd);
    ui->stackedWidgetRight->setCurrentWidget(ui->pageHome);
}

