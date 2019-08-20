#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QImage>

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
//    cv::Mat frameOriginal;
//    cv::Mat frameProcessed; //More efficient to work with gray scale
//    cv::VideoCapture* cap;

    bool status;
    bool capturing;

    bool binaryThresholdEnable;
    int binaryThreshold;

    void process();

protected:
    void changeEvent(QEvent* e);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendFrame(QImage frameProcessed);

public slots:


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
