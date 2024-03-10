#include "underattackdelegate.h"
#include <QDebug>
#include <QLabel>

UnderAttackDelegate::UnderAttackDelegate(QObject *parent) : QItemDelegate(parent)
{
}

QWidget *UnderAttackDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLabel* label = new QLabel(parent);
    qDebug() << "ZDES";
    return label;

}

void UnderAttackDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = "Имя: " + index.model()->data(index,Qt::DisplayRole).toString() + " Урон: " + index.model()->data(index,Qt::UserRole+4).toString();
    QLabel* label = static_cast<QLabel*>(editor);
    label->setText(value);

}

void UnderAttackDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

void UnderAttackDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}



