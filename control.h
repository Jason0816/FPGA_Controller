#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
//时间显示相关头文件
#include <QDateTime>
#include <QTimer>
// QT串口通信相关头文件
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class control;
}

class control : public QMainWindow
{
    Q_OBJECT

public:
    explicit control(QWidget *parent = 0);
    QTimer *timeTimer;
    //QString转换为Hex
    static QByteArray QString2Hex(QString hexstr);
    static char ConvertHexChar(char c);
    static QString formatInput(QString hexstr);
    static QString decInt2HexStr(int dec);
    ~control();

private slots:
    void scanPort();
    void sendData();
    void openPort();
    void readData();
    void showTimeMessage();

private:
    Ui::control *ui;
    QSerialPort * serial;
};

#endif // CONTROL_H
