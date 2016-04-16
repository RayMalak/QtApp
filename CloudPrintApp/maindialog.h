#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


public slots:
    void on_print();
    void on_scan();
    void on_to_home();

private:
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H
