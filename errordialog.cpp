#include "errordialog.h"
#include "ui_errordialog.h"
#include "QLabel"
ErrorDialog::ErrorDialog(QString txt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);

    QLabel *l = new QLabel(txt,this);
    QFont f("MS Shell Dlg 2", 10, QFont::Bold);
    l->setFont(f);
    l->setFixedSize(261,31);
    l->setAlignment(Qt::AlignCenter);
    l->move(0,30);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}
