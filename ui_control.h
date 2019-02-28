/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_control
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_port;
    QComboBox *cb_port;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_baud;
    QComboBox *cb_baud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_bit;
    QComboBox *cb_bit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lab_parity;
    QComboBox *cb_parity;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lab_stop;
    QComboBox *cb_stop;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *btn_scan;
    QPushButton *btn_open;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *ckb_0;
    QLineEdit *le_amplitude;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *ckb_1;
    QLineEdit *le_frequency;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *ckb_2;
    QLineEdit *le_3;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *ckb_3;
    QLineEdit *le_4;
    QTextEdit *te_recieve;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *control)
    {
        if (control->objectName().isEmpty())
            control->setObjectName(QStringLiteral("control"));
        control->resize(640, 437);
        centralWidget = new QWidget(control);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 191, 251));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lab_port = new QLabel(groupBox);
        lab_port->setObjectName(QStringLiteral("lab_port"));

        horizontalLayout->addWidget(lab_port);

        cb_port = new QComboBox(groupBox);
        cb_port->setObjectName(QStringLiteral("cb_port"));

        horizontalLayout->addWidget(cb_port);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lab_baud = new QLabel(groupBox);
        lab_baud->setObjectName(QStringLiteral("lab_baud"));

        horizontalLayout_2->addWidget(lab_baud);

        cb_baud = new QComboBox(groupBox);
        cb_baud->setObjectName(QStringLiteral("cb_baud"));

        horizontalLayout_2->addWidget(cb_baud);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lab_bit = new QLabel(groupBox);
        lab_bit->setObjectName(QStringLiteral("lab_bit"));

        horizontalLayout_3->addWidget(lab_bit);

        cb_bit = new QComboBox(groupBox);
        cb_bit->setObjectName(QStringLiteral("cb_bit"));

        horizontalLayout_3->addWidget(cb_bit);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lab_parity = new QLabel(groupBox);
        lab_parity->setObjectName(QStringLiteral("lab_parity"));

        horizontalLayout_4->addWidget(lab_parity);

        cb_parity = new QComboBox(groupBox);
        cb_parity->setObjectName(QStringLiteral("cb_parity"));

        horizontalLayout_4->addWidget(cb_parity);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lab_stop = new QLabel(groupBox);
        lab_stop->setObjectName(QStringLiteral("lab_stop"));

        horizontalLayout_5->addWidget(lab_stop);

        cb_stop = new QComboBox(groupBox);
        cb_stop->setObjectName(QStringLiteral("cb_stop"));

        horizontalLayout_5->addWidget(cb_stop);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        btn_scan = new QPushButton(groupBox);
        btn_scan->setObjectName(QStringLiteral("btn_scan"));

        horizontalLayout_13->addWidget(btn_scan);

        btn_open = new QPushButton(groupBox);
        btn_open->setObjectName(QStringLiteral("btn_open"));

        horizontalLayout_13->addWidget(btn_open);


        verticalLayout->addLayout(horizontalLayout_13);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 280, 488, 86));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ckb_0 = new QCheckBox(groupBox_2);
        ckb_0->setObjectName(QStringLiteral("ckb_0"));

        horizontalLayout_6->addWidget(ckb_0);

        le_amplitude = new QLineEdit(groupBox_2);
        le_amplitude->setObjectName(QStringLiteral("le_amplitude"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(le_amplitude->sizePolicy().hasHeightForWidth());
        le_amplitude->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(le_amplitude);

        horizontalLayout_6->setStretch(1, 6);

        horizontalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ckb_1 = new QCheckBox(groupBox_2);
        ckb_1->setObjectName(QStringLiteral("ckb_1"));

        horizontalLayout_7->addWidget(ckb_1);

        le_frequency = new QLineEdit(groupBox_2);
        le_frequency->setObjectName(QStringLiteral("le_frequency"));
        sizePolicy2.setHeightForWidth(le_frequency->sizePolicy().hasHeightForWidth());
        le_frequency->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(le_frequency);

        horizontalLayout_7->setStretch(1, 6);

        horizontalLayout_10->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ckb_2 = new QCheckBox(groupBox_2);
        ckb_2->setObjectName(QStringLiteral("ckb_2"));

        horizontalLayout_8->addWidget(ckb_2);

        le_3 = new QLineEdit(groupBox_2);
        le_3->setObjectName(QStringLiteral("le_3"));
        sizePolicy2.setHeightForWidth(le_3->sizePolicy().hasHeightForWidth());
        le_3->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(le_3);

        horizontalLayout_8->setStretch(1, 6);

        horizontalLayout_11->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ckb_3 = new QCheckBox(groupBox_2);
        ckb_3->setObjectName(QStringLiteral("ckb_3"));

        horizontalLayout_9->addWidget(ckb_3);

        le_4 = new QLineEdit(groupBox_2);
        le_4->setObjectName(QStringLiteral("le_4"));
        sizePolicy2.setHeightForWidth(le_4->sizePolicy().hasHeightForWidth());
        le_4->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(le_4);

        horizontalLayout_9->setStretch(1, 6);

        horizontalLayout_11->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(horizontalLayout_11);

        te_recieve = new QTextEdit(centralWidget);
        te_recieve->setObjectName(QStringLiteral("te_recieve"));
        te_recieve->setGeometry(QRect(230, 30, 381, 241));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(530, 290, 81, 71));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_send = new QPushButton(layoutWidget);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
        btn_send->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(btn_send);

        control->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(control);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 23));
        control->setMenuBar(menuBar);
        mainToolBar = new QToolBar(control);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        control->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(control);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        control->setStatusBar(statusBar);

        retranslateUi(control);

        QMetaObject::connectSlotsByName(control);
    } // setupUi

    void retranslateUi(QMainWindow *control)
    {
        control->setWindowTitle(QApplication::translate("control", "FPGA\346\216\247\345\210\266\345\231\250", 0));
        groupBox->setTitle(QApplication::translate("control", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        lab_port->setText(QApplication::translate("control", "\344\270\262\345\217\243\357\274\232", 0));
        lab_baud->setText(QApplication::translate("control", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        cb_baud->clear();
        cb_baud->insertItems(0, QStringList()
         << QApplication::translate("control", "2400", 0)
         << QApplication::translate("control", "4800", 0)
         << QApplication::translate("control", "9600", 0)
         << QApplication::translate("control", "19200", 0)
         << QApplication::translate("control", "38400", 0)
         << QApplication::translate("control", "57600", 0)
         << QApplication::translate("control", "115200", 0)
        );
        lab_bit->setText(QApplication::translate("control", "\346\225\260\346\215\256\344\275\215\357\274\232", 0));
        cb_bit->clear();
        cb_bit->insertItems(0, QStringList()
         << QApplication::translate("control", "5", 0)
         << QApplication::translate("control", "6", 0)
         << QApplication::translate("control", "7", 0)
         << QApplication::translate("control", "8", 0)
        );
        lab_parity->setText(QApplication::translate("control", "\346\240\241\351\252\214\344\275\215\357\274\232", 0));
        cb_parity->clear();
        cb_parity->insertItems(0, QStringList()
         << QApplication::translate("control", "\346\227\240", 0)
         << QApplication::translate("control", "\345\245\207\346\240\241\351\252\214", 0)
         << QApplication::translate("control", "\345\201\266\346\240\241\351\252\214", 0)
        );
        lab_stop->setText(QApplication::translate("control", "\345\201\234\346\255\242\344\275\215\357\274\232", 0));
        cb_stop->clear();
        cb_stop->insertItems(0, QStringList()
         << QApplication::translate("control", "1", 0)
         << QApplication::translate("control", "1.5", 0)
         << QApplication::translate("control", "2", 0)
        );
        btn_scan->setText(QApplication::translate("control", "\346\211\253\346\217\217\344\270\262\345\217\243", 0));
        btn_open->setText(QApplication::translate("control", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        groupBox_2->setTitle(QApplication::translate("control", "\346\263\242\345\275\242\346\216\247\345\210\266", 0));
        ckb_0->setText(QApplication::translate("control", "\345\271\205\345\200\274(V)\357\274\232", 0));
        ckb_1->setText(QApplication::translate("control", "\351\242\221\347\216\207(KHz)\357\274\232", 0));
        ckb_2->setText(QApplication::translate("control", "\345\276\205\345\256\232\345\200\274(X)\357\274\232", 0));
        ckb_3->setText(QApplication::translate("control", "\345\276\205\345\256\232\345\200\274(X)\357\274\232", 0));
        te_recieve->setHtml(QApplication::translate("control", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        btn_send->setText(QApplication::translate("control", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class control: public Ui_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
