#ifndef DIALOGEDITRECORD_H
#define DIALOGEDITRECORD_H

#include <QDialog>
#include <QtSql>
#include <QDataWidgetMapper>

namespace Ui
{
    class DialogEditRecord;
}

class DialogEditRecord : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditRecord(int row = -1, QWidget *parent = 0);
    ~DialogEditRecord();

signals:
    void signalReady();

private:
    Ui::DialogEditRecord *ui;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;

private:
    void setupModel();
    void createUI();
    void accept();
};

#endif // DIALOGEDITRECORD_H
