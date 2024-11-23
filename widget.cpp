#include "widget.h"
#include "ui_widget.h"
#include "gameplay.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedSize(1200,800);//设置窗口固定大小
    this->setWindowIcon(QIcon(":/resources/icon.jpg"));//设置游戏图标
    this->setWindowTitle("wordle");//设置游戏标题

    QPushButton *start = new QPushButton(this);//开始按钮指针
    QPushButton *end= new QPushButton(this);//结束按钮指针

    start->setObjectName("start");
    start->move(1000,600);
    start->setText("开始游戏");
    start->setFont(QFont("微软雅黑",25));

    end->setObjectName("end");
    end->move(1000,700);
    end->setText("结束游戏");
    end->setFont(QFont("微软雅黑",25));

    this->setStyleSheet(
        "#start{"
        "border: 0px;"
        "border-radius: 30px;"
        "background-color: black;"
        "padding: 20px;}"

        "#start:hover{"
        "background-color: green;"
        "border: 2px solid green;}"  // 在hover状态下添加边框样式

        "#start:pressed {"
        "background-color: #1f1e33;"
        "border: 2px solid #1f1e33;}"  // 在pressed状态下添加边框样式

        "#end{"
        "border: 0px;"
        "border-radius: 30px;"
        "background-color: black;"
        "padding: 20px;}"

        "#end:hover{"
        "background-color: green;"
        "border: 2px solid green;}"

        "#end:pressed{"
        "background-color: #1f1e33;"
        "border: 2px solid #1f1e33;}"
        );
    connect(start,&QPushButton::clicked,[=]{
        gameplay *gameplay = new class gameplay();
        gameplay->setGeometry(this->geometry());
        this->close();

        gameplay->show();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);
    QPixmap pix(":/resources/raglan.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
