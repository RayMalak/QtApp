/**
  @file numkeyboard.cpp
  @brief 数字键盘widget
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "numkeyboard.h"
#include "ui_numkeyboard.h"
#include <QDebug>

NumKeyboard::NumKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumKeyboard)
{
    ui->setupUi(this);

    /// bind signal & slot
    connect(ui->pbNum0, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum1, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum2, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum3, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum4, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum5, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum6, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum7, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum8, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbNum9, SIGNAL(clicked(bool)), SLOT(numClicked()));
    connect(ui->pbClean, SIGNAL(clicked(bool)), SLOT(cleanClicked()));
    connect(ui->pbOK, SIGNAL(clicked(bool)), SLOT(okClicked()));

}

NumKeyboard::~NumKeyboard()
{
    delete ui;
}

void NumKeyboard::Empty()
{
    ui->numDisplay->setText(tr(""));
}

void NumKeyboard::numClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    ui->numDisplay->setText(ui->numDisplay->text() + button->text());
}

void NumKeyboard::okClicked()
{
    qlonglong editNumber = ui->numDisplay->text().toLongLong();

    /// emit finish signal, so other QObject who bind this signal can catch it.
    /// (such like parent widget. *,*)
    emit sig_inputFinished(editNumber);
}

void NumKeyboard::cleanClicked()
{
    /// delete one character each time
    ui->numDisplay->setText(
                ui->numDisplay->text().remove(
                            ui->numDisplay->text().length()-1, 1)
                );
}

