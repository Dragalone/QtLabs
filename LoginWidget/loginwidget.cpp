#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget() : QWidget(),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}



LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_enter_button_clicked()
{
    if (!ui->login_edit->displayText().isEmpty() && !ui->password_edit->displayText().isEmpty()){
        login_password tmp;
        tmp.login = ui->login_edit->displayText();
        tmp.password = ui->password_edit->displayText();
        emit form_entered(tmp);
    } else if (ui->login_edit->displayText().isEmpty() && ui->password_edit->displayText().isEmpty()){
            msg.setText("Поля: Логин, Пароль - пустые!");
            msg.exec();
    } else if (ui->login_edit->displayText().isEmpty() && !ui->password_edit->displayText().isEmpty()){
            msg.setText("Полe: Логин - пустое!");
            msg.exec();
    } else {
            msg.setText("Поле: Пароль - пустое!");
            msg.exec();
    }

}


void LoginWidget::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()){
        ui->password_edit->setEchoMode(QLineEdit::EchoMode::Normal);
    } else {
        ui->password_edit->setEchoMode(QLineEdit::EchoMode::Password);
    }
}



void LoginWidget::on_delete_button_clicked()
{
    ui->login_edit->setText("");
    ui->password_edit->setText("");
    emit cancellation();
}

