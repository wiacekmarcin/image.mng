#include "imagemng.h"
#include "ui_imagemng.h"
#include "adddirdialog.h"

ImageMng::ImageMng(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageMng)
{
    ui->setupUi(this);
}

ImageMng::~ImageMng()
{
    delete ui;
}


void ImageMng::on_pushButton_clicked()
{
    AddDirDialog * dlg =new AddDirDialog();
    dlg->exec();
}
