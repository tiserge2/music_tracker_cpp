/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QString>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuAbout;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
           // MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextOnly);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        //centralWidget->setObjectName("centralWidget");
        verticalLayoutWidget = new QWidget(centralWidget);
        //verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 10, 551, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(("label_2"));
        label_2->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(("lineEdit_3"));
        lineEdit_3->setMaxLength(4);
        lineEdit_3->setCursorPosition(0);
        //lineEdit_3->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_3, 1, 2, 1, 1);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(("lineEdit"));
        lineEdit->setFrame(true);
        lineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(("pushButton"));
        pushButton->setCheckable(false);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(("label"));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        label->setMidLineWidth(4);
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(370, 480, 254, 51));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(("label_4"));
        label_4->setGeometry(QRect(0, 0, 181, 541));
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setLineWidth(5);
        label_4->setMidLineWidth(4);
        label_4->setTextFormat(Qt::RichText);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/1-Carnival-CLBR-1170x731.png")));
        label_4->setScaledContents(false);
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(("tableView"));
        tableView->setGeometry(QRect(245, 131, 461, 341));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(("menuSettings"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(("menuAbout"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Music Tracker", 0));
        label_3->setText(QApplication::translate("MainWindow", "Year", 0));
        label_2->setText(QApplication::translate("MainWindow", "Title", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "year", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "type the author name", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add track", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "type the title", 0));
        label->setText(QApplication::translate("MainWindow", "Author", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Download", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Remove", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Quit", 0));
        label_4->setText(QString());
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
