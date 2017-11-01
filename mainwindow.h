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
    bool showData(QVariant author,QVariant title,QVariant album,QVariant year);
    void unShowData(int i);

public slots:
    void insertData();
    void removeData();
    void updateTable();
    void start_timer();
    void stop_timer();



private:
    Ui::MainWindow *ui;
    //Database *db;
    QSqlDatabase database;
    QSqlTableModel *model;
    QTimer *updateInterval;
};

#endif // MAINWINDOW_H
