#include "myachievementwidget.h"
#include "ui_myachievementwidget.h"

myAchievementWidget::myAchievementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myAchievementWidget)
{
    ui->setupUi(this);
    //初始隐藏
    for(int i=1000;i<=9000;i+=1000)
    {
        //找planet的label，找到了就hide
        if(myAchievementLabel *planet_label = ui->widget->findChild<myAchievementLabel *>("planet_" + QString::number(i)))
        {
             //测试
             planet_label->hide();
        }
    }
    //初始隐藏，给dot设置图片
    for(int i=0;i<=9000;i+=250)
    {
        //找planet的label，找到了就hide
        if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
        {
            //测试
//            dot_label->setPixmap(QPixmap("//这里填上无旗子的照片"));
            dot_label->hide();
        }
    }

    //给成就填上图片
//    ui->planet_1000->setPixmap(QPixmap("//这里填上成就1的照片"));
//    ui->planet_2000->setPixmap(QPixmap("//这里填上成就2的照片"));
//    ui->planet_3000->setPixmap(QPixmap("//这里填上成就3的照片"));
//    ui->planet_4000->setPixmap(QPixmap("//这里填上成就4的照片"));
//    ui->planet_5000->setPixmap(QPixmap("//这里填上成就5的照片"));
//    ui->planet_6000->setPixmap(QPixmap("//这里填上成就6的照片"));
//    ui->planet_7000->setPixmap(QPixmap("//这里填上成就7的照片"));
//    ui->planet_8000->setPixmap(QPixmap("//这里填上成就8的照片"));
//    ui->planet_9000->setPixmap(QPixmap("//这里填上成就9的照片"));

    //提示语句
    ui->planet_1000->setToolTip("您的碎片数目已经达到1000");
    ui->planet_2000->setToolTip("您的碎片数目已经达到2000");
    ui->planet_3000->setToolTip("您的碎片数目已经达到3000");
    ui->planet_4000->setToolTip("您的碎片数目已经达到4000");
    ui->planet_5000->setToolTip("您的碎片数目已经达到5000");
    ui->planet_6000->setToolTip("您的碎片数目已经达到6000");
    ui->planet_7000->setToolTip("您的碎片数目已经达到7000");
    ui->planet_8000->setToolTip("您的碎片数目已经达到8000");
    ui->planet_9000->setToolTip("您的碎片数目已经达到9000");

    //测试：假设我现在有5600个碎片
    int mySplinterCount = 10000;

    //先根据碎片数量来找显示的部分
    //先显示最近的部分
    //0~1000
    if(mySplinterCount>=0 && mySplinterCount < 250)
    {
        ui->dot_250->show();
    }
    else if(mySplinterCount>=250 && mySplinterCount < 500)
    {
        ui->dot_250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_250->show();
        ui->dot_500->show();
    }
    else if(mySplinterCount>=500 && mySplinterCount < 750)
    {
        ui->dot_500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_750->show();
        //
        ui->dot_500->show();
        ui->dot_250->show();
    }
    else if(mySplinterCount>=750 && mySplinterCount < 1000)
    {
        ui->dot_750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //ui->planet_1000->show();
        //
        ui->dot_750->show();
        ui->dot_250->show();
        ui->dot_500->show();
    }

    //1000~2000
    else if(mySplinterCount>=1000 && mySplinterCount < 1250)
    {
        ui->planet_1000->show();
        ui->dot_1250->show();
        //
        for(int i=0;i<=1000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
    }
    else if(mySplinterCount>=1250 && mySplinterCount < 1500)
    {
        ui->dot_1250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_1500->show();
        //
        for(int i=0;i<=1250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
    }
    else if(mySplinterCount>=1500 && mySplinterCount < 1750)
    {
        ui->dot_1500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_1750->show();
        //
        for(int i=0;i<=1500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
    }
    else if(mySplinterCount>=1750 && mySplinterCount < 2000)
    {
        ui->dot_1750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=1750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
    }

    //2000~3000
    else if(mySplinterCount>=2000 && mySplinterCount < 2250)
    {
        ui->planet_2000->show();
        ui->dot_2250->show();
        //
        for(int i=0;i<=2000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
    }
    else if(mySplinterCount>=2250 && mySplinterCount < 2500)
    {
        ui->dot_2250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_2500->show();
        //
        for(int i=0;i<=2250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
    }
    else if(mySplinterCount>=2500 && mySplinterCount < 2750)
    {
        ui->dot_2500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_2750->show();
        //
        for(int i=0;i<=2500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
    }
    else if(mySplinterCount>=2750 && mySplinterCount < 3000)
    {
        ui->dot_2750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=2750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
    }

    //3000~4000
    else if(mySplinterCount>=3000 && mySplinterCount < 3250)
    {
        ui->dot_3250->show();
        ui->planet_3000->show();
        //
        for(int i=0;i<=3000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
    }
    else if(mySplinterCount>=3250 && mySplinterCount < 3500)
    {
        ui->dot_3250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_3500->show();
        //
        for(int i=0;i<=3250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
    }
    else if(mySplinterCount>=3500 && mySplinterCount < 3750)
    {
        ui->dot_3500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_3750->show();
        //
        for(int i=0;i<=3500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
    }
    else if(mySplinterCount>=3750 && mySplinterCount < 4000)
    {
        ui->dot_3750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=3750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
    }

    //4000~5000
    else if(mySplinterCount>=4000 && mySplinterCount < 4250)
    {
        ui->planet_4000->show();
        ui->dot_4250->show();
        //
        for(int i=0;i<=4000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
    }
    else if(mySplinterCount>=4250 && mySplinterCount < 4500)
    {
        ui->dot_4250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_4500->show();
        //
        for(int i=0;i<=4250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
    }
    else if(mySplinterCount>=4500 && mySplinterCount < 4750)
    {
        ui->dot_4500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_4750->show();
        //
        for(int i=0;i<=4500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
    }
    else if(mySplinterCount>=4750 && mySplinterCount < 5000)
    {
        ui->dot_4750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=4750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
    }

    //5000~6000
    else if(mySplinterCount>=5000 && mySplinterCount < 5250)
    {
        ui->planet_5000->show();
        ui->dot_5250->show();
        //
        for(int i=0;i<=5000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
    }
    else if(mySplinterCount>=5250 && mySplinterCount < 5500)
    {
        ui->dot_5250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_5500->show();
        //
        for(int i=0;i<=5250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
    }
    else if(mySplinterCount>=5500 && mySplinterCount < 5750)
    {
        ui->dot_5500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_5750->show();
        //
        for(int i=0;i<=5500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
    }
    else if(mySplinterCount>=5750 && mySplinterCount < 6000)
    {
        ui->dot_5750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=5750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
    }

    //6000~7000
    else if(mySplinterCount>=6000 && mySplinterCount < 6250)
    {
        ui->planet_6000->show();
        ui->dot_6250->show();
        //
        for(int i=0;i<=6000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
    }
    else if(mySplinterCount>=6250 && mySplinterCount < 6500)
    {
        ui->dot_6250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_6500->show();
        //
        for(int i=0;i<=6250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
    }
    else if(mySplinterCount>=6500 && mySplinterCount < 6750)
    {
        ui->dot_6500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_6750->show();
        //
        for(int i=0;i<=6500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
    }
    else if(mySplinterCount>=6750 && mySplinterCount < 7000)
    {
        ui->dot_6750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=6750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
    }

    //7000~8000
    else if(mySplinterCount>=7000 && mySplinterCount < 7250)
    {
        ui->planet_7000->show();
        ui->dot_7250->show();
        //
        for(int i=0;i<=7000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
    }
    else if(mySplinterCount>=7250 && mySplinterCount < 7500)
    {
        ui->dot_7250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_7500->show();
        //
        for(int i=0;i<=7250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
    }
    else if(mySplinterCount>=7500 && mySplinterCount < 7750)
    {
        ui->dot_7500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_7750->show();
        //
        for(int i=0;i<=7500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
    }
    else if(mySplinterCount>=7750 && mySplinterCount < 8000)
    {
        ui->dot_7750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=7750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
    }

    //8000~9000
    else if(mySplinterCount>=8000 && mySplinterCount < 8250)
    {
        ui->planet_8000->show();
        ui->dot_8250->show();
        //
        for(int i=0;i<=8000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
    }
    else if(mySplinterCount>=8250 && mySplinterCount < 8500)
    {
        ui->dot_8250->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_8500->show();
        //
        for(int i=0;i<=8250;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
        ui->planet_8000->show();
    }
    else if(mySplinterCount>=8500 && mySplinterCount < 8750)
    {
        ui->dot_8500->setPixmap(QPixmap("//这里填上有旗子的照片"));
        ui->dot_8750->show();
        //
        for(int i=0;i<=8500;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
        ui->planet_8000->show();
    }
    else if(mySplinterCount>=8750 && mySplinterCount < 9000)
    {
        ui->dot_8750->setPixmap(QPixmap("//这里填上有旗子的照片"));
        //
        for(int i=0;i<=8750;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
        ui->planet_8000->show();
    }
    else if(mySplinterCount>=9000)
    {
        ui->planet_9000->show();
        //
        for(int i=0;i<=9000;i+=250)
        {
            //找以往的dot的label，找到了就show
            if(myAchievementLabel *dot_label = ui->widget->findChild<myAchievementLabel *>("dot_" + QString::number(i)))
            {
                dot_label->show();
            }
        }
        ui->planet_1000->show();
        ui->planet_2000->show();
        ui->planet_3000->show();
        ui->planet_4000->show();
        ui->planet_5000->show();
        ui->planet_6000->show();
        ui->planet_7000->show();
        ui->planet_8000->show();
    }
}

myAchievementWidget::~myAchievementWidget()
{
    delete ui;
}
