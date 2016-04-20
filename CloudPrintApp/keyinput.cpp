/**
  @file keyinput.cpp
  @brief 数字键盘widget
  @author raym
  @version 1.0
  @date 2016-04-20
  #update
**/


#include "keyinput.h"
#include "ui_keyinput.h"
#include <QDebug>

KeyInput::KeyInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumKeyInput)
{
    ui->setupUi(this);

    /// bind signal & slot
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

}

KeyInput::~KeyInput()
{
    delete ui;
}


/// Number button clicked
void KeyInput::numClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    ui->numDisplay->setText(ui->numDisplay->text() + button->text());
}

/// OK button clicked
void KeyInput::on_pbOK_clicked()
{
    qlonglong editNumber = ui->numDisplay->text().toLongLong();

    /// emit finish signal, so other QObject who bind this signal can catch it.
    /// (such like parent widget. *,*)
    emit sig_inputFinished(editNumber);
}

/// Clean button clicked
void KeyInput::on_pbClean_clicked()
{
    /// delete one character each time
    ui->numDisplay->setText(
                ui->numDisplay->text().remove(
                            ui->numDisplay->text().length()-1, 1)
                );
}

