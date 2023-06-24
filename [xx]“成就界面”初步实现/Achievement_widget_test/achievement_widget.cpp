#include "achievement_widget.h"
#include "ui_achievement_widget.h"

Achievement_Widget::Achievement_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Achievement_Widget)
{
    ui->setupUi(this);

    //先默认为0，以后加接口，根据“行星碎片”判断 achievement_state
    int achievement_state = 4;

    //提示语句
    ui->planet1->setToolTip("恭喜您获得1000行星碎片");
    ui->planet2->setToolTip("恭喜您获得2000行星碎片");
    ui->planet3->setToolTip("恭喜您获得3000行星碎片");
    ui->planet4->setToolTip("恭喜您获得4000行星碎片");

    //判断后显示
    if(achievement_state == 0)
    {
        ui->dot1->hide();
        ui->dot2->hide();
        ui->dot3->hide();
        ui->dot4->hide();
        ui->dot5->hide();
        ui->dot6->hide();

        ui->planet1->hide();
        ui->planet2->hide();
        ui->planet3->hide();
        ui->planet4->hide();
    }
    else if(achievement_state == 1)
    {
        ui->dot1->hide();
        ui->dot2->hide();
        ui->dot3->hide();
        ui->dot4->hide();
        ui->dot5->hide();
        ui->dot6->hide();

        //p1显示
        ui->planet2->hide();
        ui->planet3->hide();
        ui->planet4->hide();
    }
    else if(achievement_state == 2)
    {
        //dot1，dot2显示
        ui->dot3->hide();
        ui->dot4->hide();
        ui->dot5->hide();
        ui->dot6->hide();

        //p1显示，p2显示
        ui->planet3->hide();
        ui->planet4->hide();
    }
    else if(achievement_state == 3)
    {
        //dot1，dot2，dot3，dot4显示
        ui->dot5->hide();
        ui->dot6->hide();

        //p1显示，p2显示，p3显示
        ui->planet4->hide();
    }
    else if(achievement_state == 4)
    {
        //全显示
    }
}

Achievement_Widget::~Achievement_Widget()
{
    delete ui;
}
