#ifndef IMAGEMNG_H
#define IMAGEMNG_H

#include <QMainWindow>

namespace Ui {
class ImageMng;
}

class ImageMng : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageMng(QWidget *parent = 0);
    ~ImageMng();



private slots:
    void on_pushButton_clicked();

private:
    Ui::ImageMng *ui;
};

#endif // IMAGEMNG_H
