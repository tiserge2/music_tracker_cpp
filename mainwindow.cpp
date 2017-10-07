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
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(insertDataIntoTable()));
    /***1-*********************************/
                //Databse
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/sergioumix/Documents/sqliteDB/essaie");
    database.open();
    if(database.open()){
        ui->statusBar->showMessage("Successfull connection with the DB");
    } else {
        ui->statusBar->showMessage("Failed connecting to the DB");
    }
    /************************************/

    /**2-***********************************/
                //the model
    QSqlTableModel *model = new QSqlTableModel(this,database);
    model->setTable("music_tracker");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Author"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Album"));

    /*************************************/

    /**3***********************************/
                    //the view
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->show();

    /*************************************/
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::insertDataIntoTable(){
    if(database.open()){
        if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty()){
            database = QSqlDatabase::database();
            QSqlQuery query(database);
            QString queryText("insert into music_tracker(author, title, album)"
                              "values (?, ?, ?);");
            query.clear();
            query.prepare(queryText );
            query.addBindValue(ui->lineEdit_2->text());
            query.addBindValue(ui->lineEdit->text());
            query.addBindValue(ui->lineEdit_3->text());
            if(query.exec()){
                ui->statusBar->showMessage("Your new field have been added successfully.");
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
