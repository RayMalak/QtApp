#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}
class KeyInput;

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


public slots:
    void on_switch_page();

private:
    Ui::MainDialog *ui;
    KeyInput       *keyInput;
};

#endif // MAINDIALOG_H
