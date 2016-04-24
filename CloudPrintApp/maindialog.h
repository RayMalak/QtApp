#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}
class KeyInputWidget;

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


public slots:
    void on_switch_page();
    void on_keyinput_ok();

private:
    Ui::MainDialog *ui;
    KeyInputWidget       *keyInput;
};

#endif // MAINDIALOG_H
