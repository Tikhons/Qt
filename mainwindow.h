#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BookShelf.h"
#include "printbook.h"
#include "shelf.h"
#include <QListWidgetItem>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_abs_clicked();





    void on_listWidget_bshelf_itemClicked(QListWidgetItem *item);

    void on_pushButton_addshelf_clicked();

private:
    Ui::MainWindow *ui;
    vector<BookShelf> bookShelfs;
    int bShelfID;
    int ShelfID;
    int bookID;
};
#endif // MAINWINDOW_H
