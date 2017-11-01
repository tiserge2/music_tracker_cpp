#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QString>
//-------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(removeData()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    //creating a timer to update the table each second
    updateInterval = new QTimer(this);
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(start_timer()));
    connect(updateInterval,SIGNAL(timeout()),this,SLOT(updateTable()));
    connect(updateInterval,SIGNAL(timeout()),this,SLOT(stop_timer()));
    /***1-*********************************/
                //Databse
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("src/essaie");
    database.open();
    if(database.open()){
        ui->statusBar->showMessage("Successfull connection with the DB");
    } else {
        ui->statusBar->showMessage("Failed connecting to the DB");
    }
    /************************************/

    /**2-***********************************/
                //the model
    model = new QSqlTableModel(this,database);
    model->setTable("music_tracker");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Author"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));
    model->setHeaderData(3, Qt::Horizontal, tr("Year"));

    /*************************************/

    /**3***********************************/
                    //the view
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->tableView->resizeColumnsToContents();
    //ui->tableView->set
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->show();

    /*************************************/
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::insertData(){
    if(database.open()){
        if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_4->text().isEmpty()){
            database = QSqlDatabase::database();
            QSqlQuery query(database);
            QString queryText("insert into music_tracker(author, title,album, year)"
                              "values (?, ?, ?, ?);");
            query.clear();
            query.prepare(queryText );
            query.addBindValue(ui->lineEdit_2->text());
            query.addBindValue(ui->lineEdit->text());
            query.addBindValue(ui->lineEdit_4->text());
            query.addBindValue(ui->lineEdit_3->text());
            if(query.exec()){
                ui->statusBar->showMessage("Your new field have been added successfully.");
                if(showData(ui->lineEdit_2->text(),ui->lineEdit->text(),ui->lineEdit_4->text(),ui->lineEdit_3->text())){
                    ui->lineEdit->clear();
                    ui->lineEdit_2->clear();
                    ui->lineEdit_3->clear();
                    ui->lineEdit_4->clear();
                    ui->statusBar->showMessage("Refreshing data view.");
                } else {
                    ui->statusBar->showMessage("Can't add new data in the view.");
                }
            } else {
                ui->statusBar->showMessage("Failled adding new field to DB.");
                qDebug() << query.lastError().text();
                qDebug() << ui->lineEdit_2->text() << ui->lineEdit->text() << ui->lineEdit_3->text();
            }
        } else {
            QMessageBox::critical(this,"Insertion text Error","You must filled all the field.");
            ui->statusBar->showMessage("Please fullfil all the fields.");
        }
    } else {
        qDebug() << "Database not open";
    }
}

bool MainWindow::showData(QVariant author,QVariant title,QVariant album,QVariant year){
    int row = 0;
    if(model->insertRow(row)){
        model->setData(model->index(row,0),author);
        model->setData(model->index(row,1),title);
        model->setData(model->index(row,2),album);
        model->setData(model->index(row,3),year);
        model->submitAll();
        return true;
    } else {
        return false;
    }


}

void MainWindow::unShowData(int i){
    ui->statusBar->showMessage("Data will be removed, button in implementation phase");

    //QModelIndexList indexes = selection.indexes();
    if(model->removeRow(i)){
        //updateInterval->start();
        ui->statusBar->showMessage("Row has been removed.");
    } else {
        ui->statusBar->showMessage("Row can't be removed.");
    }
    //return true;}
}

void MainWindow::removeData(){
//    QModelIndexList selection(ui->tableView->selectionModel()->selectedRows());
//    QModelIndex index = selection.at(0);
    //getting the index of the data so that i can remove them later
    QModelIndexList selection(ui->tableView->selectionModel()->selectedIndexes());
    QVector <QVector <int> > dataIndexes;
    QVector < int > dataIndex;
    foreach (QModelIndex index, selection) {
        dataIndex.clear();
        dataIndex.push_back(index.row());
        dataIndex.push_back(index.column());
        dataIndexes.push_back(dataIndex);
    }
    //query to remove the selected data in the db
    QSqlQuery removeQuery;
    QString author = ui->tableView->model()->data(ui->tableView->model()->index(dataIndexes.at(0).value(0),dataIndexes.at(0).value(1))).toString();
    QString title = ui->tableView->model()->data(ui->tableView->model()->index(dataIndexes.at(1).value(0),dataIndexes.at(1).value(1))).toString();
    QString album = ui->tableView->model()->data(ui->tableView->model()->index(dataIndexes.at(2).value(0),dataIndexes.at(2).value(1))).toString();
    QString year = ui->tableView->model()->data(ui->tableView->model()->index(dataIndexes.at(3).value(0),dataIndexes.at(3).value(1))).toString();

    QString removeQueryText = "DELETE FROM music_tracker WHERE"
                              " (author IS NULL OR author = ?)  AND "
                              " (title IS NULL OR title = ?) AND "
                              " (album IS NULL OR album = ?) AND"
                              " (year IS NULL OR year = ?) ;";

    removeQuery.prepare(removeQueryText);
    removeQuery.addBindValue(author);
    removeQuery.addBindValue(title);
    removeQuery.addBindValue(album);
    removeQuery.addBindValue(year);

    if(removeQuery.exec()){
        unShowData(dataIndexes.at(0).value(0));
        ui->statusBar->showMessage("Data has been removed from the Db");
        qDebug() << removeQuery.lastError() ;
        //qDebug() <<  QSqlField::clear(author);

    } else {
        ui->statusBar->showMessage("Can't remove the data in the Db");
        qDebug() << removeQuery.lastError() ;
    }

    qDebug() << author << title << album << year;
}

void MainWindow::updateTable(){
    model->select();
    ui->tableView->reset();
}

void MainWindow::start_timer(){
    updateInterval->setInterval(100);
    updateInterval->start();
}

void MainWindow::stop_timer(){
    updateInterval->stop();
}
