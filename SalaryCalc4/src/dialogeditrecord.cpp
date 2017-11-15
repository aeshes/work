#include "dialogeditrecord.h"
#include "ui_dialogeditrecord.h"

DialogEditRecord::DialogEditRecord(int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditRecord)
{
    ui->setupUi(this);

    setupModel();

    mapper->setCurrentModelIndex(model->index(row, 0));
}

DialogEditRecord::~DialogEditRecord()
{
    delete ui;
}

void DialogEditRecord::setupModel()
{
    model = new QSqlTableModel(this);
    model->setTable("employee");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->inputFirstName, 1);
    mapper->addMapping(ui->inputLastName, 2);
    mapper->addMapping(ui->inputBaseRate,  3);
    mapper->addMapping(ui->inputHireDate,    4);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void DialogEditRecord::accept()
{

}
