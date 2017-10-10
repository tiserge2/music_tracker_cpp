#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSqlTableModel"
#include <QSqlDatabase>
//#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool insertData(QVariant author,QVariant title,QVariant album,QVariant year);

public slots:
    void executeQuery();
    bool removeData();



private:
    Ui::MainWindow *ui;
    //Database *db;
    QSqlDatabase database;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
