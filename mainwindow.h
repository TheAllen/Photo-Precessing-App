#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    cv::Mat frameOriginal;
    cv::Mat frameProcessed; //More efficient to work with gray scale
    cv::VideoCapture* cap;

    bool status;
    bool capturing;

    bool binaryThresholdEnable;
    int binaryThreshold;

    void process();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendFrame(QImage frameProcessed);

public slots:
    void receiveGrabFrame();
    void receiveSetup(const int device);
    void receiveToggleStream();

    void receiveEnableBinaryThreshold();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
