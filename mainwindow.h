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
public slots:
    void insertDataIntoTable();


private:
    Ui::MainWindow *ui;
    //Database *db;
    QSqlDatabase database;
};

#endif // MAINWINDOW_H
