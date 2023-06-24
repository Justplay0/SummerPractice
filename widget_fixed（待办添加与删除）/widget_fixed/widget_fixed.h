#ifndef WIDGET_FIXED_H
#define WIDGET_FIXED_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget_fixed; }
QT_END_NAMESPACE

class Widget_fixed : public QWidget
{
    Q_OBJECT

public:
    Widget_fixed(QWidget *parent = nullptr);
    ~Widget_fixed();
    bool isDeleteMode=false;
    void loadItems();
private slots:
    void on_addButton_clicked();
    void on_manageButton_clicked();
    void onDeleteButtonClicked();
private:
    Ui::Widget_fixed *ui;
};
#endif // WIDGET_FIXED_H
