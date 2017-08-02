#ifndef DIALOGEDITRECORD_H
#define DIALOGEDITRECORD_H

#include <QDialog>

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
};

#endif // DIALOGEDITRECORD_H
