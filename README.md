# 参考博客：
1. 博客园-菜头大大：[QT串口通信](https://www.cnblogs.com/wurenzhong/p/8186437.html)
2. CSDN-宗师之路：[QT实现串口通信(附源码下载)](https://blog.csdn.net/qq_27312943/article/details/52900527)
3. CSDN-xz-c：[C++将10进制字符串转为16进制字符串](https://blog.csdn.net/u014602230/article/details/52752683)
## 本文改进
1. 在前辈们的代码基础上进行改进，使操作更符合逻辑
2. 优化代码结构，提高了代码的可移植性
## QT实现串口通信
1. 在工程文件（.pro）中添加串口通信相关运行库：`QT       += serialport`
2. 在头文件中添加
    ```cpp
    #include <QtSerialPort/QSerialPort>
    #include <QtSerialPort/QSerialPortInfo>
    ```
3. 在头文件中定义全局的串口对象：`QSerialPort *serial;`
## 串口通讯步骤
1. 设置串口名称
    + 寻找可用串口
        ```cpp
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
                if(isHavePort == 0){
                    QMessageBox::information(NULL, "警告", "没有可用串口");
                }
            }
        }
        ```
    + 设置串口名
        ```cpp
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(this->ui->cb_port->currentText());
        ```
2. 打开串口
    ```cpp
    serial->open(QIODevice::ReadWrite);
    ```
3. 设置波特率
    ```cpp
    serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200
    ```
4. 设置数据位
    ```cpp
    serial->setDataBits(QSerialPort::Data8);//设置数据位8
    ```
5. 设置校验位
    ```cpp
    serial->setParity(QSerialPort::NoParity); //无校验位
    ```
6. 设置停止位
    ```cpp
    serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
    ```
7. 设置流控制
    ```cpp
    serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制
    ```
通过上述操作，串口的基本设置就设置好了，接下来需要实现数据的接收和发送：
1. 在打开串口按钮中执行的操作中添加槽函数，当下位机中有数据发送过来时就会相应这个槽函数
    ```cpp
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    ```
2. 从上位机发送数据到下位机，发送内容位ASII码值或者为Hex格式；根据自身需求，我将数据进行了转换和格式化，此处为Hex格式。
    ```cpp
    serial->write(QString2Hex(formatInput(hexStr)));
    ```
## 进制转换及格式化
由于下位机需求，需要两帧将数据发送过去，经过多番考虑，最终决定将十进制转换为16进制，然后以Hex进行发送
1. 十进制转换为16进制字符串
    ```cpp
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
    ```
2. 将字符串转换为Hex格式
    ```cpp
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
    ```
3. 输出形式格式化
    ```cpp
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
    ```
## UI展示
![界面展示](https://upload-images.jianshu.io/upload_images/14484228-06891a8bb97b3885.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
## 源码下载：
[Github](https://github.com/2572880761/FPGA_Controller)