#include "myconcentrationmainwindow.h"
#include "ui_myconcentrationmainwindow.h"

MyConcentrationMainWindow::MyConcentrationMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyConcentrationMainWindow)
{
    ui->setupUi(this);
    //连接“添加”和“展现widget添加界面”
    connect(ui->mainWindow_addNewBtn,&QPushButton::clicked,this,&MyConcentrationMainWindow::triggered_CreateNewWidget);
    Heard_updateMainWindow();

    //创建窗口后，除了刷新，还要让按钮有用啊
    connect(ui->labelDelete_1,&QPushButton::clicked,[=](){
        //按下第1个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 1");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_2,&QPushButton::clicked,[=](){
        //按下第2个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 2");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_3,&QPushButton::clicked,[=](){
        //按下第3个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 3");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_4,&QPushButton::clicked,[=](){
        //按下第4个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 4");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_5,&QPushButton::clicked,[=](){
        //按下第5个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 5");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_6,&QPushButton::clicked,[=](){
        //按下第6个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 6");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });
    connect(ui->labelDelete_7,&QPushButton::clicked,[=](){
        //按下第7个删除按钮
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("userTask.db");
        db.open();
        QSqlQuery query;
        query.exec("Delete from userTask where ROWID = 7");
        db.close();
        updateDatabase();
        Heard_updateMainWindow();
    });

    //历史按钮连接
    connect(ui->mainWindow_historyBtn,&QPushButton::clicked,this,&MyConcentrationMainWindow::clicked_generateHistoryDialog);
}

MyConcentrationMainWindow::~MyConcentrationMainWindow()
{
    delete ui;
}

void MyConcentrationMainWindow::Heard_updateMainWindow()
{
    //先创建vec去获取数据库中的数据
    //QString的vec
    QVector<QString> taskNameVector;
    //int的vec
    QVector<int> taskTimeVector;
    //打开数据库 userTask
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userTask.db");
    db.open();
    QSqlQuery query;
    query.exec("Select * from userTask");
    while(query.next())
    {
        QString taskName = query.value("name").toString();
        int taskTime = query.value("time").toInt();
        taskNameVector<<taskName;
        taskTimeVector<<taskTime;
    }

    //数据库关闭
    db.close();

    //按钮初始都无，看不见 hide，用不了 disable
    for(int i=1;i<=7;i++)
    {
        QPushButton* buttonStart = ui->centralWidget->findChild<QPushButton*>("labelStart_"+QString::number(i));
        QPushButton* buttonDelete = ui->centralWidget->findChild<QPushButton*>("labelDelete_"+QString::number(i));
        buttonStart->setEnabled(false);
        buttonDelete->setEnabled(false);
        buttonStart->hide();
        buttonDelete->hide();
    }

    //更新界面，主要通过找到相关的label，前面设置显示文字，后面隐藏，超过了7个会报错
    //假设我有vec 3个数据 size得到3 label 1~3 改文字
    for(int i=1;i<=taskNameVector.size();i++)
    {
        //上半部分有效，label显示，按钮有效
        QLabel *label = ui->centralWidget->findChild<QLabel *>("taskLabel_" + QString::number(i));
        QPushButton* buttonStart = ui->centralWidget->findChild<QPushButton*>("labelStart_"+QString::number(i));
        QPushButton* buttonDelete = ui->centralWidget->findChild<QPushButton*>("labelDelete_"+QString::number(i));
        label->show();
        label->setText(QString("任务名: %1 , 设定时间: %2 分钟").arg(taskNameVector[i-1]).arg(taskTimeVector[i-1]));
        buttonStart->setEnabled(true);
        buttonDelete->setEnabled(true);
        buttonStart->show();
        buttonDelete->show();
    }
    //label 4~7 置空
    for(int i=taskNameVector.size()+1;i<=7;i++)
    {
        QLabel *label = ui->centralWidget->findChild<QLabel *>("taskLabel_" + QString::number(i));
        label->hide();
    }
}

//点击“添加”后创建widget界面，函数实现
void MyConcentrationMainWindow::triggered_CreateNewWidget()
{
    //先判断是否大于7个，再打开界面
    //创建vector存放userTask中的taskname
    QVector<QString> nameVector;
    //数据库读取
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
    //现在测试用
    qDebug()<<nameVector.size();
    qDebug()<<nameVector;
    //判断
    //如果大于等于7，警告后退出  ！！！！这里测试就不return了，后面记得加上
    if(nameVector.size()>=7)
    {
        QMessageBox::warning(this,"警告","您制定的任务数已经达到上限，请清理后再使用");
        return;
    }
    //没达到7，就正常开始界面
    AddNew_Widget *aw = new AddNew_Widget();
    aw->show();
    //如果打开了界面，那就 监听“刷新信号”和“刷新”
    connect(aw,&AddNew_Widget::AddNewAskUpdate,this,&MyConcentrationMainWindow::Heard_updateMainWindow);
}

//“刷新数据库表单”函数，重新分配uid，函数声明
void MyConcentrationMainWindow::updateDatabase()
{
    //打开数据库
    QSqlDatabase db;
    QSqlQuery *query;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userTask.db");
    db.open();
    //创建query操作
    query = new QSqlQuery();
    //1.创建新表
    //2.删除新表数据
    //3.向新表插入所有数据
    //4.删除原表
    //5.新表命名为原表
    query->exec("create table userTask_temp(name,time)");
    query->exec("delete from userTask_temp");
    query->exec("insert into userTask_temp select * from userTask");
    query->exec("Drop table userTask");
    query->exec("alter table userTask_temp rename to userTask");
    db.close();
}

//"历史数据"dialog生成
void MyConcentrationMainWindow::clicked_generateHistoryDialog()
{
    //点一下“历史数据”，生成w，w是dialog，dialog有chistogram成员，成员会依附到dialog上面。
    //如果传空参，那么什么都不会生成
    //现在要调用数据库传入三个参数，1.int maximumUpCount，最大上标（相近于 最大总次数）
    //2.taskNameVector QString类型的任务名vector
    //3.taskCountVector int类型的y轴次数，就是一个任务的总次数
    //1 3都需要总次数，需要悬浮窗实现
    //4.nullCount 即空的次数

    //2可以直接获取，如下
    QVector<QString> taskNameVector;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userTask.db");
    db.open();
    QSqlQuery query;
    query.exec("Select * from userTask");
    while(query.next())
    {
        QString taskName = query.value("name").toString();
        taskNameVector << taskName;
    }

    //taskNameVector即传入的QString类型的任务名vector
    if(taskNameVector.size()<7)
    {
        //比如我现在不满7个，我只有5个，那要加2个
        for(int i=7;i>taskNameVector.size();i--)
        {
            taskNameVector << "暂无";
        }
    }

    myHistoryDialog *w = new myHistoryDialog();
    w->show();
}
