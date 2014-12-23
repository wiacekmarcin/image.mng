#ifndef ADDDIRWIDGET_H
#define ADDDIRWIDGET_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class AddDirWidget;
}

class AddDirWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddDirWidget(const QString &dirname, QWidget *parent = 0);
    ~AddDirWidget();

    void setAllFilesNumber(unsigned int number);

    void addFile(const QString &fileName, bool imgFile, bool exifFile, const QDateTime &beg, const QDateTime &end);

private:
    Ui::AddDirWidget *ui;
    QDateTime mBegan;
    QDateTime mEnd;
};

#endif // ADDDIR_H
