#include <QMessageBox>
#include "keyinput.h"
#include "ui_keyinput.h"

KeyInputWidget::KeyInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyInput)
{
    ui->setupUi(this);

    connect(ui->pbNum0, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum1, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum2, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum3, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum4, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum5, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum6, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum7, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum8, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbNum9, SIGNAL(clicked(bool)), SLOT(numClick()));
    connect(ui->pbClear, SIGNAL(clicked(bool)), SLOT(cleanClick()));
   // connect(ui->pbOK, SIGNAL(clicked(bool)), parent, SLOT(on_keyinput_ok));
}

KeyInputWidget::~KeyInputWidget()
{
    delete ui;
}

void KeyInputWidget::numClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    ui->numDisplay->setText(ui->numDisplay->text() + button->text());

}

void KeyInputWidget::cleanClick()
{
    ui->numDisplay->setText(
                ui->numDisplay->text().remove(
                            ui->numDisplay->text().length()-1, 1)
                );
}


