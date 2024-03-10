#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "skntobject.h"
#include "underattackmodel.h"
#include <QDebug>
#include <QItemDelegate>
#include <QDir>
#include <QTimer>
#include "skntsystem.h"
#include "commitedmodel.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    under_attack_model = new UnderAttackModel(this);
    UnderAttackDelegate* del = new UnderAttackDelegate();
    ui->attack_zone_list_view->setItemDelegate(del);
    successed_model = new CommitedModel(this);
    failed_model = new CommitedModel(this);

    ui->attack_zone_list_view->setModel(under_attack_model);
    ui->attack_zone_list_view->setItemDelegate(del);
    ui->sucessed_list_view->setModel(successed_model);
    ui->failed_list_view->setModel(failed_model);
    timer = new QTimer();
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

MainWindow::~MainWindow()
{    
    delete ui;
}


void MainWindow::on_add_button_clicked()
{
    QString type;
    if (ui->type->currentText() == "Земля-воздух"){
        type = "air";
    } else if (ui->type->currentText() == "Земля-вода"){
        type = "water";
    }else if (ui->type->currentText() == "Земля-земля"){
        type = "earth";
    }
    SkntObject sobj(ui->speed->value(),type,ui->name->text(),ui->cannons_count->value(),ui->damage_count->value());
    under_attack_model->add_sknt_object(sobj);
}

void MainWindow::updateTime()
{
    SkntObject* obj = under_attack_model->check();
    if (obj!=nullptr){
        if (obj->getZone() == SkntObject::Checked_zone){
            successed_model->add_sknt_object(*obj);
            int damage = ui->prevented_damage_count_label->text().toInt();
            damage+= obj->getDamage();
            ui->prevented_damage_count_label->setText(QString::number(damage));
        } else if (obj->getZone() == SkntObject::Leaved_zone){
            failed_model->add_sknt_object(*obj);
            int damage = ui->damage_count_label->text().toInt();
            damage+= obj->getDamage();
            ui->damage_count_label->setText(QString::number(damage));
        }
    }

}




void MainWindow::on_start_button_clicked()
{
    timer->start();
    QModelIndex i = under_attack_model->index(0);

    under_attack_model->sort(0,Qt::AscendingOrder);

    under_attack_model->system->setEe_weapons(ui->ee_count->value());
    under_attack_model->system->setEw_weapons(ui->ew_count->value());
    under_attack_model->system->setEa_weapons(ui->ea_count->value());
    under_attack_model-> system->setProcess_time(ui->processing_count->value());
    under_attack_model-> system->setAvailable_ee_weapons(ui->ee_count->value());
    under_attack_model->system->setAvailable_ew_weapons(ui->ew_count->value());
    under_attack_model->system->setAvailable_ea_weapons(ui->ea_count->value());

        qDebug() << under_attack_model->system->getProcess_time() <<" "<< under_attack_model->system->getEa_weapons() <<" " << under_attack_model->system->getEe_weapons()<<" " << under_attack_model->system->getEw_weapons();
}


void MainWindow::on_stop_button_clicked()
{
    timer->stop();
}


void MainWindow::on_clear_data_clicked()
{
    successed_model->clear_data();
    failed_model->clear_data();
    under_attack_model->clear_data();
    ui->damage_count_label->setText("0");
    ui->prevented_damage_count_label->setText("0");
}

