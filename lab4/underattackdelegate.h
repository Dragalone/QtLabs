#ifndef UNDERATTACKDELEGATE_H
#define UNDERATTACKDELEGATE_H

#include <QItemDelegate>
#include <QObject>

class UnderAttackDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit UnderAttackDelegate(QObject *parent = nullptr);


    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // UNDERATTACKDELEGATE_H
