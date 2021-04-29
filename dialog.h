#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QString px, py, pz;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString dimXDialog();
    QString dimYDialog();
    QString dimZDialog();
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
