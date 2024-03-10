#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void add_pallete();
    void delete_pallete();
    void open_pallete();
    void set_button_color();
    void save_pallete();
    void delete_cur_pallete();
private:
    Ui::MainWindow *ui;
    void set_buttons_from_json(QString filename);
    QString current_filename;
    QVector<QPushButton*> buttons;
    void del_pallete(QString name);
};
#endif // MAINWINDOW_H
