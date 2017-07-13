#include "qtfm.h"
#include "ui_qtfm.h"
#include <QDir>
#include <QDebug>

qtfm::qtfm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qtfm)
{
    ui->setupUi(this);

    // ~~ Dir Window ~~ //
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs); // set filter
    dirModel->setRootPath(QDir::rootPath()); // set root path
    ui->dirview->setModel(dirModel); // link to the ui
    // ui->dirview->setRootIndex(dirModel->setRootPath(QDir::homePath())); // for home dir only

    // ~~ File Window ~~ //
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files); // set filter
    fileModel->setRootPath(QDir::homePath()); // set root path
    ui->fileview->setModel(fileModel); // link to the ui
    // ui->fileview->setRootIndex(fileModel->setRootPath(QDir::homePath())); // for home dir only

    // set the UI to look the way we want
    ui->dirview->setHeaderHidden(true);
    //ui->fileview->setHeaderHidden(true);
    ui->dirview->resizeColumnToContents(0);
    ui->dirview->setColumnHidden(1, true);
    ui->dirview->setColumnHidden(2, true);
    ui->dirview->setColumnHidden(3, true);

    }

qtfm::~qtfm()
{
    delete ui;
}

void qtfm::on_dirview_clicked(const QModelIndex &index)
{
    QString newPath = dirModel->fileInfo(index).absoluteFilePath(); // get new path
    ui->fileview->setRootIndex(fileModel->setRootPath(newPath));
}

