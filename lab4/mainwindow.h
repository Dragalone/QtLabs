#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "underattackmodel.h"
#include "underattackdelegate.h"
#include <QMainWindow>
#include "skntsystem.h"
#include "commitedmodel.h"


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
    void on_add_button_clicked();
    void updateTime();
    void on_start_button_clicked();

    void on_stop_button_clicked();

    void on_clear_data_clicked();

private:
    Ui::MainWindow *ui;
    UnderAttackModel* under_attack_model;
    CommitedModel* successed_model;
    CommitedModel* failed_model;
    UnderAttackDelegate* del;
    QTimer* timer;
};
#endif // MAINWINDOW_H
