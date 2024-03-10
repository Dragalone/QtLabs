#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H


#include "LoginWidget_global.h"

#include <QMessageBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWidget; }
QT_END_NAMESPACE

class LOGINWIDGET_EXPORT LoginWidget : public QWidget
{
    Q_OBJECT

public:
     explicit LoginWidget();
     ~LoginWidget();

private:
    struct login_password{
        QString login;
        QString password;
    };
    QMessageBox msg;
private slots:
    void on_enter_button_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_delete_button_clicked();

signals:
    void form_entered(login_password lp);
    void cancellation();

private:

    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
