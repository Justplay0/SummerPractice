#include "CHistogram.h"

CHistogram::CHistogram(QWidget *parent)
    :QFrame(parent)
{
    initUI();
}

void CHistogram::refreshUI(QVector<int> vecData) //重新设置上标
{
    if(vecData.isEmpty())
        return ;
    vecData.resize(7);                          //可变（或有效的）柱的个数
    for(int i = 0; i < vecData.size(); i++){
        m_pBarSet->replace(i,vecData.at(i));    //m_pBarSet上标集合替换
    }
}

void CHistogram::initUI()
{
    this->resize(1200,800);                  //设置柱状图的 宽,高
    QFont fontText("SimHei");               //设置文本字体
    fontText.setPixelSize(20);              //设置字体的像素大小

    QBarSeries *pBarSeries = new QBarSeries();
    pBarSeries->setLabelsVisible(true);     //柱状图的顶端的上标是否可视
    pBarSeries->setLabelsFormat("@valueh"); //设置坐标数据（上标）的数据类型
    pBarSeries->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);     //上标位置
    connect(pBarSeries,&QBarSeries::hovered,[=](bool bStatus,int index,QBarSet *pBarSet){ //鼠标悬浮柱状条
        Q_UNUSED(bStatus)
        Q_UNUSED(index)
        Q_UNUSED(pBarSet)
    });

    m_pBarSet = new QBarSet("运行时间");         //下方图例名!!!
    m_pBarSet->setBrush(QBrush("#dd5da4f2"));   //设置颜色
    m_pBarSet->setBorderColor("#dd5da4f2");     //设置边缘色
    m_pBarSet->setLabelFont(fontText);          //设置字体
    *m_pBarSet<< 49 << 49 << 49 << 49 << 49 << 49 << 49;   //上标上限，设置为range最大值-1 !!!
    pBarSeries->append(m_pBarSet);


    /*X轴设置*/
    QBarCategoryAxis *pAxisX = new QBarCategoryAxis();
    QStringList strListDate;                    //strListDate为字符串列表

    strListDate.append("A");                    //设置横标!!!
    strListDate.append("B");
    strListDate.append("C");


   /*for(int i = 6;i >= 0; i--) {                //6~0，共七个日期，往字符串列表添加，最终成为X轴
        strListDate.append(QDate::currentDate().addDays(-i).toString("M.dd"));
    } */
    pAxisX->append(strListDate);                //X轴添加字符串列表
    pAxisX->setGridLineColor("transparent");    //参考线颜色透明
    pAxisX->setLinePenColor("#5da4f2");         //标尺 线颜色
    pAxisX->setLabelsColor("#5da4f2");          //文本颜色
    pAxisX->setLabelsFont(fontText);            //设置字体

    /*Y轴设置*/
    QValueAxis *pAxisY = new QValueAxis();
    pAxisY->setTickCount(13);                //y轴线的次数，包含0那一条横线!!!
    pAxisY->setLabelFormat("%dh");           //y轴数据类型
    pAxisY->setRange(0,50);                  //y轴的取值范围!!!
    pAxisY->setGridLineColor("#5da4f2");     //颜色
    pAxisY->setLinePenColor("#5da4f2");      //标尺 线颜色
    pAxisY->setLabelsColor("#5da4f2");       //文本颜色
    pAxisY->setLabelsFont(fontText);         //字体

    QChart *pChart = new QChart();
    pChart->addSeries(pBarSeries);           //添加上标序列
    pChart->setTitle("最近任务专注次数");       //柱状图标题!!!
    pChart->setAnimationOptions(QChart::SeriesAnimations);
    pChart->createDefaultAxes();
    pChart->setAxisX(pAxisX);
    pChart->setAxisY(pAxisY);
    pChart->legend()->setVisible(true);                 //设置图例为显示状态
    pChart->legend()->setAlignment(Qt::AlignBottom);    //设置图例的显示位置在底部

    QChartView *pChartView = new QChartView(pChart,this);
    pChartView->setRenderHint(QPainter::Antialiasing);
    pChartView->resize(this->size());

}

