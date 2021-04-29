#include "dialog.h"
#include "ui_dialog.h"
#include <string>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::dimXDialog()
{
    return ui->lineEditDimX->text();
}

QString Dialog::dimYDialog()
{
    return ui->lineEditDimY->text();
}

QString Dialog::dimZDialog()
{
    return ui->lineEditDimZ->text();
}

void Dialog::on_buttonBox_accepted()
{
    px = ui->lineEditDimX->text();
    py = ui->lineEditDimY->text();
    pz = ui->lineEditDimZ->text();
}
