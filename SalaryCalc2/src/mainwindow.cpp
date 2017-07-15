#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupPositionModel(QStringList()    << trUtf8("Position"));
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
    modelPosition->setQuery("SELECT name FROM department");

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
    ui->tableViewPosition->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    ui->tableView->setModel(modelEmployee);
    ui->tableView->setColumnHidden(0, true);

    connect(ui->tableViewPosition, &QTableView::activated,
                  this, &MainWindow::updateEmployeeModel);
}

void MainWindow::updateEmployeeModel(const QModelIndex &index)
{
    qDebug() << index.model()->data(index, Qt::DisplayRole).toString();
   QItemSelectionModel *selectionModel = ui->tableViewPosition->selectionModel();

   int position = 0;
   if (selectionModel->hasSelection())
   {
       position = selectionModel->selectedRows().first().row();
   }
    modelEmployee->setQuery("SELECT * FROM employee WHERE position = " + QString::number(position + 1));
}
