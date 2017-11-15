#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>
#include <QMenu>
#include <QAction>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow  *ui;
    QSqlQueryModel  *modelPosition;
    QSqlQueryModel  *modelEmployee;

private:
    void setupPositionModel(const QStringList & headers);
    void setupEmployeeModel(const QStringList & headers);
    void createUI();

public slots:
    void updateEmployeeModel(const QModelIndex & index);

private slots:
    void slotUpdateModels();
    void slotCustomMenuRequested(QPoint pos);
    void slotEditRecord();
    void slotCalcSalary();
};


#endif // MAINWINDOW_H
