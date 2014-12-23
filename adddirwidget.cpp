#include "adddirwidget.h"
#include "ui_adddirwidget.h"

AddDirWidget::AddDirWidget(const QString & dirname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDirWidget)
{
    ui->setupUi(this);
    ui->lDirname->setText(dirname);
    ui->lcdFileNumber->display(0);
    ui->lcdFotoNumber->display(0);
    ui->lcdExifNumber->display(0);
    mBegan = QDateTime(QDate(2199, 12, 31), QTime(23,59,59));
    mEnd = QDateTime(QDate(1900, 1, 1), QTime(0,0,1));
    ui->lBegin->setText("-");
    ui->lEnd->setText("-");
}

AddDirWidget::~AddDirWidget()
{
    delete ui;
}

void AddDirWidget::setAllFilesNumber(unsigned int number)
{
    ui->progressBar->setMaximum(number);
    ui->progressBar->setValue(0);
    ui->lAllFilesNumber->setText(QString("z %1").arg(number));
}

void AddDirWidget::addFile(const QString & fileName, bool imgFile, bool exifFile, const QDateTime & beg, const QDateTime & end)
{
    ui->lFileName->setText(fileName);
    ui->lcdFileNumber->display(ui->lcdFileNumber->intValue() + 1);
    if (imgFile)
        ui->lcdFotoNumber->display(ui->lcdFotoNumber->intValue() + 1);
    if (exifFile)
        ui->lcdExifNumber->display(ui->lcdExifNumber->intValue() + 1);
    ui->progressBar->setValue(ui->lcdFileNumber->intValue());
}
