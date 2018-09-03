#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "open file";

    const QString &imagePath = ui->imagePathLineEdit->text();
    QPixmap image(imagePath);
    ui->imageLabel->setPixmap(image);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "blur";

    const QPixmap *pixmap = ui->imageLabel->pixmap();
    QImage tmp = pixmap->toImage();
    QImage dest = tmp;

    int range = ui->effectSpinBox->value();
    qDebug() << "effect range" << range;

    QColor color;
    int r, g, b;
    for(int y = 0; y < tmp.height(); ++y)
    //for(int y = 0; y < 50; ++y)
    {
        for(int x = 0; x < tmp.width(); ++x)
        {
            r = g = b = 0;

            // calculate
            int xmin, xmax, ymin, ymax;
            xmin = x - range;
            xmax = x + range;
            ymin = y - range;
            ymax = y + range;
            if (xmin < 0)
                xmin = 0;
            if (xmax >= tmp.width())
                xmax = tmp.width() - 1;
            if (ymin < 0)
                ymin = 0;
            if (ymax >= tmp.height())
                ymax = tmp.height() - 1;

            for (int xx = xmin; xx < xmax; ++xx)
                for (int yy = ymin; yy < ymax; ++yy)
                {
                    color = tmp.pixelColor(xx,yy);
                    r += color.red();
                    g += color.green();
                    b += color.blue();
                }
            int count = (xmax - xmin + 1) * (ymax - ymin + 1);
            r /= count;
            g /= count;
            b /= count;

            if (r > 255)
                r = 255;
            if (g > 255)
                g = 255;
            if (b > 255)
                b = 255;

            color = tmp.pixelColor(x,y);
            color.setRed(r);
            color.setGreen(g);
            color.setBlue(b);
            //color.setRed(255 - color.red());
            //color.setAlpha(tmp.pixelColor(x,y).alpha());

            //color = QColor::fromRgb(255, 0, 0, 0);
            dest.setPixelColor(x, y, color);
        }
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(dest));
    qDebug() << "done";
}
