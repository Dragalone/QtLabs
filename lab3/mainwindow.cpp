#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QDirIterator>
#include <QMessageBox>
#include <QInputDialog>
#include <QColorDialog>
struct rgb {
    int red;
    int green;
    int blue;
};

void MainWindow::del_pallete(QString name){

    QString filename (name + ".json");

    if(filename == "base_pallete.json"){
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Ошибка удаления палитры (невозможно удалить базовую палитру)");
        msg->exec();
        return;
    }
    QDirIterator it("palletes/", QStringList() << "*.json", QDir::Files, QDirIterator::Subdirectories);
    bool file_exists = false;
    while (it.hasNext()){
        it.next();
        if (it.fileName() == filename){
            file_exists = true;
        }
    }

    if (file_exists){
        QFile file("palletes/" + filename);
        if(file.remove()){
            auto actions = ui->menu->actions();
            for(auto i : actions){
                if (i->text() == name){
                    ui->menu->removeAction(i);
                    break;
                }
            }
            set_buttons_from_json("palletes/base_pallete.json");
            QMessageBox* msg = new QMessageBox(this);
            msg->setText("Палитра успешно удалена!");
            msg->exec();
        } else {
            QMessageBox* msg = new QMessageBox(this);
            msg->setText("Ошибка удаления палитры :(");
            msg->exec();
        }
    } else {
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Палитра не найдена!");
        msg->exec();
    }

}


//слот добавления палитры
void MainWindow::add_pallete(){
    QDirIterator it("palletes/", QStringList() << "*.json", QDir::Files, QDirIterator::Subdirectories);
    int count = 0;
    while (it.hasNext()){
        qDebug() << it.next();
        qDebug() << it.fileName();
        count++;
    }
    qDebug() << "count:" << count;
    if (count >= 5){
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Превышено максимальное количество палитр!");
        msg->exec();

    } else {
        QString name = QInputDialog::getText(this,"Ввод имени палитры","Введите имя палитры");


        QString filename ("palletes/" + name + ".json");
        QFile file(filename);
        if (file.exists()){
            QMessageBox* msg = new QMessageBox(this);
            msg->setText("Указанная палитра уже существует!");
            msg->exec();
        } else {
            if (file.open(QIODevice::WriteOnly  | QIODevice::Text)){
                auto act = new QAction(name);
                 ui->menu->addAction(act);
                 connect(act,SIGNAL(triggered(bool)),this,SLOT(open_pallete()));
                 QString data("{"
                                "\"pallete\": ["
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180],"
                                "[180, 180, 180]"
                              "]"
                            "}");
                 QTextStream s(&file);
                 s << data;
                 file.close();

            }
            else {
                QMessageBox* msg = new QMessageBox(this);
                msg->setText("Ошибка открытия файла");
                msg->exec();
            }
        }
    }

}
//слот удаления палитры
void MainWindow::delete_pallete(){
    QString name = QInputDialog::getText(this,"Ввод имени палитры","Введите имя палитры, которую необходимо удалить");
    del_pallete(name);

}

//слот удаления текущей палитры
void MainWindow::delete_cur_pallete(){
    QString name = current_filename;

    int pos = name.lastIndexOf(QChar('.'));
    name = name.left(pos);
    QRegExp rx("*/");
    rx.setPatternSyntax(QRegExp::Wildcard);
    pos = name.size() - rx.lastIndexIn(name) - 1;
    name = name.right(pos);
    del_pallete(name);
    set_buttons_from_json("palletes/base_pallete.json");
}
// слот установки цвета кнопки
void MainWindow::set_button_color(){
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    const QColor base_color(180,180,180);
    QColor color = QColorDialog::getColor(base_color,this);
    if (!color.isValid())
        color = base_color;
    QString stylesheet("background-color: rgb(%1,%2,%3)");
    stylesheet = stylesheet.arg(color.red()).arg(color.green()).arg(color.blue());
    btn->setStyleSheet(stylesheet);
}


//слот открытия палитры
void MainWindow::open_pallete(){
    QAction* act = qobject_cast<QAction*>(sender());
    QString filename("palletes/" + act->text() + ".json");
    set_buttons_from_json(filename);
}

//слот сохранения текущей палитры
void MainWindow::save_pallete(){
    QFile file(current_filename);
    if (file.open(QIODevice::WriteOnly  | QIODevice::Text)){
       QJsonObject recordObject;
       QJsonArray mainArray;
       for (int i = 0; i < 16; i++){
           QJsonArray btnArray;
           QColor color = buttons[i]->palette().button().color();
           btnArray.push_back(color.red());
           btnArray.push_back(color.green());
           btnArray.push_back(color.blue());
           mainArray.push_back(btnArray);
       }
       recordObject.insert("pallete", mainArray);
       QJsonDocument doc(recordObject);
       QString jsonString = doc.toJson(QJsonDocument::Indented);
       QTextStream stream( &file );
       stream << jsonString;

    } else {
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Ошибка сохранения палитры!");
        msg->exec();
    }
    file.close();
}


//установка цвета кнопок из палитры
void MainWindow::set_buttons_from_json(QString filename){
    current_filename = filename;
    QString val;
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8(), &error);
    qDebug() << "Error: " << error.errorString() << error.offset << error.error;
    if (doc.isObject()){
        QJsonObject json = doc.object();
        QJsonArray arr = json["pallete"].toArray();
        QVector<rgb> pallete(16);

        for (int i = 0;i < 16; i ++){
            QJsonArray ar = (arr[i].toArray());
            pallete[i].red = ar[0].toInt();
            pallete[i].green = ar[1].toInt();
            pallete[i].blue = ar[2].toInt();
        }
        for (int i = 0;i < 16; i ++){
            QString stylesheet("background-color: rgb(%1,%2,%3)");
            stylesheet = stylesheet.arg(pallete[i].red).arg(pallete[i].green).arg(pallete[i].blue);
            buttons[i]->setStyleSheet(stylesheet);

        }

    }

    file.close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buttons.push_back(ui->btn_0);
    buttons.push_back(ui->btn_1);
    buttons.push_back(ui->btn_2);
    buttons.push_back(ui->btn_3);
    buttons.push_back(ui->btn_4);
    buttons.push_back(ui->btn_5);
    buttons.push_back(ui->btn_6);
    buttons.push_back(ui->btn_7);
    buttons.push_back(ui->btn_8);
    buttons.push_back(ui->btn_9);
    buttons.push_back(ui->btn_10);
    buttons.push_back(ui->btn_11);
    buttons.push_back(ui->btn_12);
    buttons.push_back(ui->btn_13);
    buttons.push_back(ui->btn_14);
    buttons.push_back(ui->btn_15);
    for (auto i : buttons){
        connect(i,SIGNAL(clicked()),this,SLOT(set_button_color()));
    }

    QFile file;
    if (!QDir("palletes").exists()){
        QDir().mkdir("palletes");
    }
    file.setFileName("palletes/base_pallete.json");
    if (!file.exists()){
        if (file.open(QIODevice::WriteOnly  | QIODevice::Text)){
             QString data("{"
                            "\"pallete\": ["
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180],"
                            "[180, 180, 180]"
                          "]"
                        "}");
             QTextStream s(&file);
             s << data;
             file.close();
     }
    }
    //загрузка цветов кнопок из json
    QString filename = "palletes/base_pallete.json";
    set_buttons_from_json(filename);
    current_filename = filename;
    QDirIterator it("palletes/", QStringList() << "*.json", QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext()){
        it.next();
        QString s(it.fileName());
        int pos = s.lastIndexOf(QChar('.'));
        auto act = new QAction(s.left(pos));
        ui->menu->addAction(act);
        connect(act,SIGNAL(triggered(bool)),this,SLOT(open_pallete()));
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

