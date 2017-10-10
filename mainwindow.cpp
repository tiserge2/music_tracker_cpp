#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

//-------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(removeData()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(executeQuery()));
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
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->show();

    /*************************************/
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::executeQuery(){
    if(database.open()){
        if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty()){
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
                if(insertData(ui->lineEdit_2->text(),ui->lineEdit->text(),ui->lineEdit_4->text(),ui->lineEdit_3->text())){
                    ui->statusBar->showMessage("Refreshing data view.");
                    ui->lineEdit->clear();
                    ui->lineEdit_2->clear();
                    ui->lineEdit_3->clear();
                    ui->lineEdit_4->clear();
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

bool MainWindow::insertData(QVariant author,QVariant title,QVariant album,QVariant year){
    int row = 0;
    if(model->insertRow(row)){
        model->setData(model->index(row,0),author);
        model->setData(model->index(row,1),title);
        model->setData(model->index(row,2),album);
        model->setData(model->index(row,3),year);
        return true;
    } else {
        return false;
    }


}

bool MainWindow::removeData(){
    ui->statusBar->showMessage("Data will be removed, button in implementation phase");
    QItemSelection selection(ui->tableView->selectionModel()->selection());
    QModelIndexList indexes = selection.indexes();
    foreach (QModelIndex index, indexes) {
         qDebug() << index;
    }

    return true;
}
