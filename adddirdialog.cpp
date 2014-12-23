#include "adddirdialog.h"
#include "ui_adddirdialog.h"

#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>

AddDirDialog::AddDirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDirDialog)
{
    ui->setupUi(this);
    mLast =  QApplication::applicationDirPath();
    mTask = QMap<QString, AddDirWidget*>();
}

AddDirDialog::~AddDirDialog()
{
    delete ui;
}

void AddDirDialog::on_pushButton_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this, trUtf8("Wybierz katalog z zdjęciami"), mLast);
    if (dirname.isEmpty())
        return;
    mLast = dirname;
    AddDirWidget *w = new AddDirWidget(dirname, ui->frame);
    mTask[dirname] = w;
    ui->verticalLayout->addWidget(w);
    QDir dir = QDir(dirname);

    QStringList files, files_;
    QStringList dirs, dirs_;

    dirs.append(dirname);

    while (dirs.size() > 0) {

        dir  = QDir(dirs.first());
        dirname = dir.absolutePath();
        dirs.pop_front();

        files_ = dir.entryList(QDir::Files);
        for (int i = 0; i < files_.size(); ++i)
            files_[i] = dirname + "/" + files_[i];

        files.append(files_);
        dirs_ = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for (int i = 0; i < dirs_.size(); ++i) {
            dirs_[i] = dirname + "/" + dirs_[i];
        }
        dirs.append(dirs_);
    }

    w->setAllFilesNumber(files.size());
    qDebug("Done");
}
