#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwidget.h"

#include <QVBoxLayout>

void MainWindow::showMsg(login_password lp){
    ui->label->setText(lp.login);
    ui->label_2->setText(lp.password);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoginWidget* login_widget = new LoginWidget();
    QVBoxLayout* vlayout = new QVBoxLayout(ui->centralwidget);
    connect(login_widget,SIGNAL(form_entered(login_password)),this,SLOT(showMsg(login_password)));
    vlayout->addWidget(login_widget);
}



MainWindow::~MainWindow()
{
    delete ui;
}

