#include "addnew_widget.h"
#include "ui_addnew_widget.h"

AddNew_Widget::AddNew_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNew_Widget)
{
    ui->setupUi(this);

    //对lineeditt的属性修改
    //设置最大长度为10个字符
    ui->le_TaskName->setMaxLength(8);
    //连接 lineedit编辑 和 获取输入任务名
    connect(ui->le_TaskName,&QLineEdit::textChanged,this,&AddNew_Widget::AddNew_getInputTaskName);

    //对spinbox的属性修改
    //范围只能从30min~180min，即0.5h~3h
    ui->sb_ConcentrationTime->setRange(30, 180);
    //步长30
    ui->sb_ConcentrationTime->setSingleStep(30);
    //不允许手动更改，只能按按钮
    ui->sb_ConcentrationTime->setFocusPolicy(Qt::NoFocus);
    //连接 spinbox改变 和 获取输入任务时间
    connect(ui->sb_ConcentrationTime, QOverload<const QString &>::of(&QSpinBox::valueChanged),this,&AddNew_Widget::AddNew_getInputConcentrationTime);

    //“取消按钮” 连接 “关闭窗口”
    connect(ui->btn_AddNewCancel,&QPushButton::clicked,this,[=](){
        this->close();
    });

    //“确认按钮” 连接 ""
    connect(ui->btn_AddNewConfirm,&QPushButton::clicked,this,[=](){
        //点击确认干三件事：1.数据库 2.退出窗口 3.刷新页面
        //1.加入数据库
        QSqlDatabase db;
        QSqlQuery *query;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();

        query = new QSqlQuery();
        query->exec("create table userTask(name,time)");
        QString sqlString = QString("insert into userTask(name,time) values('%1','%2')").arg(inputTaskeName).arg(inputConcentrationTime);
        qDebug()<<sqlString;
        query->exec(sqlString);
        db.close();
        //2.退出窗口
        this->close();
        //3.刷新页面
        AddNew_Widget::AddNew_updateMainWidget();
    });
}

AddNew_Widget::~AddNew_Widget()
{
    delete ui;
}

void AddNew_Widget::AddNew_getInputTaskName()
{
    //获取输入任务名，判断其不能与数据库中其他name相同
    inputTaskeName = ui->le_TaskName->text();
    //测试用
    qDebug()<<inputTaskeName;
    //先找出所有数据库中名字
    //1.创建nameVector存储数据库中的taskname
    QVector<QString> nameVector;
    //2.数据库 操作
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userTask.db");
    db.open();
    QSqlQuery query;
    query.exec("Select * from userTask");
    while(query.next())
    {
        QString taskName = query.value("name").toString();
        nameVector << taskName;
    }
    //数据库关闭
    db.close();
    //现在测试用
    qDebug()<<nameVector.size();
    qDebug()<<nameVector;
    //3.然后每个判断一下
    //若有重复，enable
    for(int i=0;i<nameVector.size();i++)
    {
        if(nameVector[i]==inputTaskeName)
        {
            ui->btn_AddNewConfirm->setEnabled(false);
            return;
        }
    }
    //执行到这说明无重复，able
    ui->btn_AddNewConfirm->setEnabled(true);
}

void AddNew_Widget::AddNew_getInputConcentrationTime()
{
    //获取输入时间
    inputConcentrationTime = ui->sb_ConcentrationTime->value();
    qDebug()<<inputConcentrationTime;
}

void AddNew_Widget::AddNew_updateMainWidget()
{
    //1.创造控件label显示“任务名”和“时间”
    QVector<QString> taskNameVector;
    QVector<int> taskTimeVector;
    QVector<QString> taskLabelNameVector;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userTask.db");
    db.open();
    QSqlQuery query;
    query.exec("Select * from userTask");
    while(query.next())
    {
        QString taskName = query.value("name").toString();
        int taskTime = query.value("time").toInt();
        taskNameVector << taskName;
        taskTimeVector << taskTime;
    }
    //数据库关闭
    db.close();
    //测试用，以后删除
    qDebug()<<taskNameVector;
    qDebug()<<taskTimeVector;

    //根据namevec和timevec创建labelnamevec，暂时弃用namevec
//    for(int i=0;i<taskNameVector.size();i++)
//    {
//        QString createdLabelName = QString(" 任务名：%1 , 设定时间：%2 ").arg(taskNameVector[i]).arg(taskTimeVector[i]);
//        taskLabelNameVector << createdLabelName;
//        qDebug()<<createdLabelName;
//    }

    //暂时弃用 taskLabel表单
    //把这7个以内的createdLabelName放在新的表单"userTask.db"的新表单“taskLabel(labelName)”中
//    QSqlDatabase db2;
//    QSqlQuery *query2;
//    db2 = QSqlDatabase::addDatabase("QSQLITE");
//    db2.setDatabaseName("userTask.db");
//    db2.open();

//    query2 = new QSqlQuery();
//    query2->exec("create table taskLabel(labelName)");
//    for(int i=0;i<taskLabelNameVector.size();i++)
//    {
//        QString sqlString = QString("insert into taskLabel(labelName) values('%1')").arg(taskLabelNameVector[i]);
//        qDebug()<<sqlString;
//        query2->exec(sqlString);
//    }
//    db.close();

    //吼一嗓子，让主界面迅速更新
    emit AddNewAskUpdate();
}

