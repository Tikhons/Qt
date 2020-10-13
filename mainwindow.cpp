#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bookID=0;
    bShelfID=0;
    ShelfID=0;
    ui->groupBox_book->setEnabled(false);
    ui->groupBox_shelf->setEnabled(false);
    ui->pushButton_delshelf->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_abs_clicked()
{
    //создать шкаф
    BookShelf bs;
    //Добавить список
    bookShelfs.push_back(bs);
    ui->listWidget_bshelf->addItem(QString::number(bookShelfs.size()));
}



void MainWindow::on_listWidget_bshelf_itemClicked(QListWidgetItem *item)
{
    bShelfID = item->text().toInt();
    ui->pushButton_delshelf->setEnabled(true);
    ui->groupBox_shelf->setEnabled(true);
    ui->pushButton_delshelf->setEnabled(false);
    int shelfN = bookShelfs[bShelfID-1].getShelfsNumber();
    ui->listWidget_shelf->clear();
    ui->listWidget_book->clear();
    if(shelfN>0){
        for(int i=1;i<shelfN;i++){
            ui->listWidget_shelf->addItem(QString::number(i));
        }

    }

}

void MainWindow::on_pushButton_addshelf_clicked()
{
    bookShelfs[ShelfID-1].addShelf();
    //Обновить список
    int ShelfN=bookShelfs[ShelfID-1].getShelfsNumber();
ui->listWidget_shelf->addItem(QString::number(ShelfN));

}
