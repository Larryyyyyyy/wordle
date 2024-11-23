#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include <QFile>
#include <Qmap>
#include <Qstring>
#include <QSoundEffect>
#include <QtMultiMedia>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTimer>
#include <QVector>
#include <QRandomGenerator>

using namespace std;

namespace Ui {
class gameplay;
}

class gameplay : public QWidget
{
    Q_OBJECT

public:
    explicit gameplay(QWidget *parent = nullptr);
    ~gameplay();
    void paintEvent(QPaintEvent *event);
    void addLetter(QString letter);
    void removeLetter();
    void clearLetter();
    void giveFeedback();
    void giveUp();
    void reset();
    void startPrintError();
    void goonPrintError();
    void read();//读取单词文件
    void changeColor0(QChar s);
    void changeColor1(QChar s);
    void changeColor2(QChar s);

private:
    Ui::gameplay *ui;
    QLineEdit *letterBoxes[21]={nullptr};
    QTimer *typeTimer=nullptr;
    bool haveRead=0;//只读一次文本
    QVector<QString> qv;
    QLabel *messageLabel=nullptr;
    int currentIndex=0,len=0,typingIndex=0;
    QString ans="",rans="";//输入的答案和真正的答案
    QString error_s="";
    const QString errorMessage="Not in word list";
    QMap<QString,bool> rec;//记录单词合法
    QPushButton *A = new QPushButton(this);
    QPushButton *B = new QPushButton(this);
    QPushButton *C = new QPushButton(this);
    QPushButton *D = new QPushButton(this);
    QPushButton *E = new QPushButton(this);
    QPushButton *F = new QPushButton(this);
    QPushButton *G = new QPushButton(this);
    QPushButton *H = new QPushButton(this);
    QPushButton *I = new QPushButton(this);
    QPushButton *J = new QPushButton(this);
    QPushButton *K = new QPushButton(this);
    QPushButton *L = new QPushButton(this);
    QPushButton *M = new QPushButton(this);
    QPushButton *N = new QPushButton(this);
    QPushButton *O = new QPushButton(this);
    QPushButton *P = new QPushButton(this);
    QPushButton *Q = new QPushButton(this);
    QPushButton *R = new QPushButton(this);
    QPushButton *S = new QPushButton(this);
    QPushButton *T = new QPushButton(this);
    QPushButton *U = new QPushButton(this);
    QPushButton *V = new QPushButton(this);
    QPushButton *W = new QPushButton(this);
    QPushButton *X = new QPushButton(this);
    QPushButton *Y = new QPushButton(this);
    QPushButton *Z = new QPushButton(this);
    QPushButton *Backspace = new QPushButton(this);
    QPushButton *Confirm = new QPushButton(this);
    QPushButton *Clear = new QPushButton(this);
    QPushButton *Giveup = new QPushButton(this);
    QPushButton *Reset = new QPushButton(this);

};

#endif // GAMEPLAY_H
