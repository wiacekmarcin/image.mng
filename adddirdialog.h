#ifndef ADDDIRDIALOG_H
#define ADDDIRDIALOG_H

#include <QDialog>
#include <QString>
#include <QMap>

#include "adddirwidget.h"

namespace Ui {
class AddDirDialog;
}

class AddDirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDirDialog(QWidget *parent = 0);
    ~AddDirDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddDirDialog *ui;
    QString mLast;
    QMap<QString, AddDirWidget*> mTask;
};

#endif // ADDDIRDIALOG_H
