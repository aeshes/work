#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupPositionModel(QStringList()    << trUtf8("Id")
                                                             << trUtf8("Position"));
    setupEmployeeModel(QStringList() << trUtf8("id")
                                                             << trUtf8("Имя")
                                                             << trUtf8("Фамилия")
                                                             << trUtf8("Базовая ставка")
                                                             << trUtf8("Дата приема")
                                                             << trUtf8("Должность"));
    createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete modelEmployee;
    delete modelPosition;
}

void MainWindow::setupPositionModel(const QStringList & headers)
{
    modelPosition = new QSqlQueryModel(this);
    modelPosition->setQuery("SELECT id, name FROM department");

    for (int i = 0; i < modelPosition->columnCount(); ++i)
    {
        modelPosition->setHeaderData(i, Qt::Horizontal, headers[i]);
    }
}

void MainWindow::setupEmployeeModel(const QStringList &headers)
{
    modelEmployee = new QSqlQueryModel(this);
    modelEmployee->setQuery("SELECT * FROM employee");

    for (int i = 0; i < modelPosition->columnCount(); ++i)
    {
        modelPosition->setHeaderData(i, Qt::Horizontal, headers[i]);
    }
}

void MainWindow::createUI()
{
    ui->tableViewPosition->setModel(modelPosition);
    ui->tableViewPosition->resizeColumnsToContents();
    ui->tableViewPosition->setColumnHidden(0, true);    // Hide ID field
    ui->tableViewPosition->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->tableView->setModel(modelEmployee);
    ui->tableView->setColumnHidden(0, true);

    connect(ui->tableViewPosition, &QTableView::activated,
                  this, &MainWindow::updateEmployeeModel);
}

void MainWindow::updateEmployeeModel(const QModelIndex & index)
{
   QSqlRecord record = modelPosition->record(index.row());
   QSqlField     field     = record.field(0);
   QString         id        = field.value().toString();

    modelEmployee->setQuery("SELECT * FROM employee WHERE position = " + id);
}
