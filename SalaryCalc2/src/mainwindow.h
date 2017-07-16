#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>

#include "constants.h"

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
    Ui::MainWindow              *ui;
    QSqlQueryModel            *modelPosition;
    QSqlQueryModel            *modelEmployee;

private:
    void setupPositionModel(const QStringList & headers);
    void setupEmployeeModel(const QStringList & headers);
    void createUI();

public slots:
    void updateEmployeeModel(const QModelIndex & index);
};


#endif // MAINWINDOW_H
