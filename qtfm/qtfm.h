#ifndef QTFM_H
#define QTFM_H

#include <QMainWindow>
#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class qtfm;
}

class qtfm : public QMainWindow
{
    Q_OBJECT

public:
    explicit qtfm(QWidget *parent = 0);
    ~qtfm();

private slots:
    void on_dirview_clicked(const QModelIndex &index);

private:
    Ui::qtfm *ui;
    QFileSystemModel *dirModel; QFileSystemModel *fileModel;
};


#endif // QTFM_H
