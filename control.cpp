#include "control.h"
#include "ui_control.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>

control::control(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::control)
{
    ui->setupUi(this);
    timeTimer = new QTimer(this);
    connect(timeTimer, SIGNAL(timeout()), this, SLOT(showTimeMessage()));
    connect(this->ui->btn_scan, SIGNAL(clicked(bool)), this, SLOT(scanPort()));
    connect(this->ui->btn_open, SIGNAL(clicked(bool)), this, SLOT(openPort()));
    connect(this->ui->btn_send, SIGNAL(clicked(bool)), this, SLOT(sendData()));
    timeTimer->start(1000);
    //设置默认值
    this->ui->cb_baud->setCurrentIndex(2);
    this->ui->cb_bit->setCurrentIndex(3);
    this->ui->btn_send->setEnabled(false);
    scanPort();
}

control::~control()
{
    delete ui;
}

// 显示时间
void control::showTimeMessage()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString time = currentTime.toString("yyyy-MM-dd hh:mm:ss  ddd");
    this->ui->statusBar->showMessage(time);
}
//查找可用串口
void control::scanPort()
{
    this->ui->cb_port->clear();
    int isHavePort = 0;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        //判断端口能否打开
        if(serial.open(QIODevice::ReadWrite))
        {
            this->ui->cb_port->addItem(serial.portName());
            isHavePort ++;
        }
        if(isHavePort == 0)
        {
            QMessageBox::information(NULL, "警告", "没有可用串口");
        }
    }
}

// 打开串口
void control::openPort()
{
    if(this->ui->btn_open->text() == tr("打开串口"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(this->ui->cb_port->currentText());
        //打开串口
        bool isOpenSucc = serial->open(QIODevice::ReadWrite);
        if(isOpenSucc)
        {
            //设置波特率
            switch(this->ui->cb_baud->currentIndex())
            {
                case 0:
                    serial->setBaudRate(QSerialPort::Baud2400);
                    break;
                case 1:
                    serial->setBaudRate(QSerialPort::Baud4800);
                    break;
                case 2:
                    serial->setBaudRate(QSerialPort::Baud9600);
                    break;
                case 3:
                    serial->setBaudRate(QSerialPort::Baud19200);
                    break;
                case 4:
                    serial->setBaudRate(QSerialPort::Baud38400);
                    break;
                case 5:
                    serial->setBaudRate(QSerialPort::Baud57600);
                    break;
                case 6:
                    serial->setBaudRate(QSerialPort::Baud115200);
                    break;
                default:
                    break;
            }

            //设置数据位
            switch(this->ui->cb_bit->currentIndex())
            {
                case 0:
                    serial->setDataBits(QSerialPort::Data5);
                    break;
                case 1:
                    serial->setDataBits(QSerialPort::Data6);
                    break;
                case 2:
                    serial->setDataBits(QSerialPort::Data7);
                    break;
                case 3:
                    serial->setDataBits(QSerialPort::Data8);
                    break;
                default:
                    break;
            }
            //设置校验位
            switch(this->ui->cb_parity->currentIndex())
            {
                case 0:
                    serial->setParity(QSerialPort::NoParity);
                    break;
                case 1:
                    serial->setParity(QSerialPort::OddParity);
                    break;
                case 2:
                    serial->setParity(QSerialPort::EvenParity);
                default:
                    break;
            }
            //设置停止位
            switch(this->ui->cb_stop->currentIndex())
            {
                case 0:
                    serial->setStopBits(QSerialPort::OneStop);
                    break;
                case 1:
                    serial->setStopBits(QSerialPort::OneAndHalfStop);
                case 2:
                    break;
                    serial->setStopBits(QSerialPort::TwoStop);
                    break;
                default:
                    break;
            }
            //设置流控制
            serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制

            //关闭设置菜单使能
            this->ui->cb_port->setEnabled(false);
            this->ui->cb_baud->setEnabled(false);
            this->ui->cb_bit->setEnabled(false);
            this->ui->cb_parity->setEnabled(false);
            this->ui->cb_stop->setEnabled(false);
            this->ui->btn_open->setText(tr("关闭串口"));
            this->ui->btn_send->setEnabled(true);
            connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
        }
        else
        {
            QMessageBox::information(NULL, "警告", "打开串口失败，串口可能被占用，请扫描可用串口。");
        }

    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();
        //恢复设置菜单使能
        this->ui->cb_port->setEnabled(true);
        this->ui->cb_baud->setEnabled(true);
        this->ui->cb_bit->setEnabled(true);
        this->ui->cb_parity->setEditable(true);
        this->ui->cb_stop->setEnabled(true);
        this->ui->btn_open->setText(tr("打开串口"));
        this->ui->btn_send->setEnabled(false);
    }
}

//读取接收到的信息
void control::readData()
{

    QByteArray buf = serial->readAll();//返回读取的字节
    if(!buf.isEmpty())
    {
        QString str = this->ui->te_recieve->toPlainText();
        this->ui->te_recieve->clear();
        this->ui->te_recieve->setText(str);
        this->ui->te_recieve->moveCursor(QTextCursor::End);//移动光标
        this->ui->te_recieve->insertPlainText(buf.toHex());
        this->ui->te_recieve->moveCursor(QTextCursor::End);//移动光标
        this->ui->te_recieve->insertPlainText(" ");
    }
    buf.clear();
}

//发送数据
void control::sendData()
{
    //发一个标记+信号
    //发送幅值
    if(this->ui->ckb_0->isChecked())
    {
        serial->write(QString2Hex("00"));
        int decInput = this->ui->le_amplitude->text().toInt();
        QString hexStr = decInt2HexStr(decInput);
        serial->write(QString2Hex(formatInput(hexStr)));
    }
    //发送频率
    if(this->ui->ckb_1->isChecked())
    {
        serial->write(QString2Hex("01"));
        int decInput = this->ui->le_frequency->text().toInt();
        QString hexStr = decInt2HexStr(decInput);
        serial->write(QString2Hex(formatInput(hexStr)));
    }

}

//将十进制int转换为十六进制字符串
QString control::decInt2HexStr(int dec)
{
    //保证数据在两帧范围内
    if(dec > 65535)
    {
        QMessageBox::information(NULL, "警告", "输入超出规定范围（input < 65535）");
        return "0";
    }
    QString hexStr;
    int temp = dec / 16;
    int left = dec % 16;
    if(temp > 0)
        hexStr += decInt2HexStr(temp);
    if(left < 10)
        hexStr += (left + '0');
    else
        hexStr += ('A' + left - 10);
    return hexStr;
}

//将输入格式化，补满四位：0XFFFF
QString control::formatInput(QString hexStr)
{
    int strlen = hexStr.length();
    switch(strlen)
    {
        case 0:
            hexStr = "0000";
            break;
        case 1:
            hexStr = "000" + hexStr;
            break;
        case 2:
            hexStr = "00" + hexStr;
            break;
        case 3:
            hexStr = "0" + hexStr;
            break;
        case 4:
            hexStr = hexStr;
            break;
        default:
            break;
    }
    return hexStr;
}

//字符串转Hex(QByteArray)类型
QByteArray control::QString2Hex(QString hexStr)
{
    QByteArray senddata;
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = hexStr.length();
    senddata.resize(len/2);
    char lstr, hstr;
    for(int i = 0; i < len; )
    {
        //将第一个不为' '的字符赋给hstr;
        hstr = hexStr[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        //当i >= len时，跳出循环
        if(i >= len)
            break;
        //当i < len时，将下一个字符赋值给lstr;
        lstr = hexStr[i].toLatin1();
        //将hstr和lstr转换为0-15的对应数值
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        //
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata * 16 + lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

//将单个字符串转换为hex
//0-F -> 0-15
char control::ConvertHexChar(char c)
{
    if((c >= '0') && (c <= '9'))
        return c - 0x30;
    else if((c >= 'A') && (c <= 'F'))
        return c - 'A' + 10;//'A' = 65;
    else if((c >= 'a') && (c <= 'f'))
        return c - 'a' + 10;
    else
        return -1;
}
