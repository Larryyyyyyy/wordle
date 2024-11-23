#include "gameplay.h"
#include "ui_gameplay.h"

gameplay::gameplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameplay)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
    this->setWindowIcon(QIcon(":/resources/icon.jpg"));
    this->setWindowTitle("Wordle");
    read();

    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    //    player->setSource(QUrl("qrc:/musics/t+pazolite - Squeaky Mind.mp3")); //音乐文件路径
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5); // 设置音量 0.0 到 1.0 之间
    // 优雅的小曲们
    QVector<QUrl> musicList = {
        QUrl("qrc:/resources/ak+q - astrum.mp3"),
        QUrl("qrc:/resources/sasakure.UK - uzumakinoharu.mp3"),
        //       QUrl("qrc:/musics/Juggernaut - Antler.mp3"),
        QUrl("qrc:/resources/t+pazolite - Squeaky Mind.mp3"),
        QUrl("qrc:/resources/Feryquitous.mp3"),
        //       QUrl("qrc:/musics/to mo da ti.mp3"),
        //       QUrl("qrc:/musics/Glimmer-Satie.mp3")
    };
    int randomIndex = QRandomGenerator::global()->bounded(musicList.size());
    QUrl selectedMusic = musicList[randomIndex];
    player->setSource(selectedMusic);
    player->play();

    QPushButton *musicSelect = new QPushButton(this);
    musicSelect->setText("Random music");
    musicSelect->move(0,0);
    musicSelect->setFixedSize(400,100);
    musicSelect->setFont(QFont("微软雅黑",25));
    connect(musicSelect, &QPushButton::clicked, this, [=]() {
        player->setSource(musicList[QRandomGenerator::global()->bounded(musicList.size())]);
        player->play();
    });

    ans="";
    currentIndex = 0;
    //    len=6;//

    Q->move(80,400);
    Q->setText("Q");
    Q->setFont(QFont("微软雅黑",25));
    Q->setFixedSize(100,100);
    W->move(180,400);
    W->setText("W");
    W->setFont(QFont("微软雅黑",25));
    W->setFixedSize(100,100);
    E->move(280,400);
    E->setText("E");
    E->setFont(QFont("微软雅黑",25));
    E->setFixedSize(100,100);
    R->move(380,400);
    R->setText("R");
    R->setFont(QFont("微软雅黑",25));
    R->setFixedSize(100,100);
    T->move(480,400);
    T->setText("T");
    T->setFont(QFont("微软雅黑",25));
    T->setFixedSize(100,100);
    Y->move(580,400);
    Y->setText("Y");
    Y->setFont(QFont("微软雅黑",25));
    Y->setFixedSize(100,100);
    U->move(680,400);
    U->setText("U");
    U->setFont(QFont("微软雅黑",25));
    U->setFixedSize(100,100);
    I->move(780,400);
    I->setText("I");
    I->setFont(QFont("微软雅黑",25));
    I->setFixedSize(100,100);
    O->move(880,400);
    O->setText("O");
    O->setFont(QFont("微软雅黑",25));
    O->setFixedSize(100,100);
    P->move(980,400);
    P->setText("P");
    P->setFont(QFont("微软雅黑",25));
    P->setFixedSize(100,100);
    A->move(100,500);
    A->setText("A");
    A->setFont(QFont("微软雅黑",25));
    A->setFixedSize(100,100);
    S->move(200,500);
    S->setText("S");
    S->setFont(QFont("微软雅黑",25));
    S->setFixedSize(100,100);
    D->move(300,500);
    D->setText("D");
    D->setFont(QFont("微软雅黑",25));
    D->setFixedSize(100,100);
    F->move(400,500);
    F->setText("F");
    F->setFont(QFont("微软雅黑",25));
    F->setFixedSize(100,100);
    G->move(500,500);
    G->setText("G");
    G->setFont(QFont("微软雅黑",25));
    G->setFixedSize(100,100);
    H->move(600,500);
    H->setText("H");
    H->setFont(QFont("微软雅黑",25));
    H->setFixedSize(100,100);
    J->move(700,500);
    J->setText("J");
    J->setFont(QFont("微软雅黑",25));
    J->setFixedSize(100,100);
    K->move(800,500);
    K->setText("K");
    K->setFont(QFont("微软雅黑",25));
    K->setFixedSize(100,100);
    L->move(900,500);
    L->setText("L");
    L->setFont(QFont("微软雅黑",25));
    L->setFixedSize(100,100);
    Z->move(160,600);
    Z->setText("Z");
    Z->setFont(QFont("微软雅黑",25));
    Z->setFixedSize(100,100);
    X->move(260,600);
    X->setText("X");
    X->setFont(QFont("微软雅黑",25));
    X->setFixedSize(100,100);
    C->move(360,600);
    C->setText("C");
    C->setFont(QFont("微软雅黑",25));
    C->setFixedSize(100,100);
    V->move(460,600);
    V->setText("V");
    V->setFont(QFont("微软雅黑",25));
    V->setFixedSize(100,100);
    B->move(560,600);
    B->setText("B");
    B->setFont(QFont("微软雅黑",25));
    B->setFixedSize(100,100);
    N->move(660,600);
    N->setText("N");
    N->setFont(QFont("微软雅黑",25));
    N->setFixedSize(100,100);
    M->move(760,600);
    M->setText("M");
    M->setFont(QFont("微软雅黑",25));
    M->setFixedSize(100,100);
    Backspace->move(860,600);
    Backspace->setText("Backspace");
    Backspace->setFont(QFont("微软雅黑",25));
    Backspace->setFixedSize(200,100);
    Confirm->move(1000,500);
    Confirm->setText("Confirm");
    Confirm->setFont(QFont("微软雅黑",25));
    Confirm->setFixedSize(160,100);
    Clear->move(1060,600);
    Clear->setText("Clear");
    Clear->setFont(QFont("微软雅黑",25));
    Clear->setFixedSize(120,100);
    Giveup->move(1070,0);
    Giveup->setText("Giveup");
    Giveup->setFont(QFont("微软雅黑",25));
    Giveup->setFixedSize(130,100);
    Reset->move(940,0);
    Reset->setText("Reset");
    Reset->setFont(QFont("微软雅黑",25));
    Reset->setFixedSize(130,100);

    // 连接按钮点击事件
    connect(Q, &QPushButton::clicked, this, [=]() {
        addLetter("Q");
    });
    connect(W, &QPushButton::clicked, this, [=]() {
        addLetter("W");
    });
    connect(E, &QPushButton::clicked, this, [=]() {
        addLetter("E");
    });
    connect(R, &QPushButton::clicked, this, [=]() {
        addLetter("R");
    });
    connect(T, &QPushButton::clicked, this, [=]() {
        addLetter("T");
    });
    connect(Y, &QPushButton::clicked, this, [=]() {
        addLetter("Y");
    });
    connect(U, &QPushButton::clicked, this, [=]() {
        addLetter("U");
    });
    connect(I, &QPushButton::clicked, this, [=]() {
        addLetter("I");
    });
    connect(O, &QPushButton::clicked, this, [=]() {
        addLetter("O");
    });
    connect(P, &QPushButton::clicked, this, [=]() {
        addLetter("P");
    });
    connect(A, &QPushButton::clicked, this, [=]() {
        addLetter("A");
    });
    connect(S, &QPushButton::clicked, this, [=]() {
        addLetter("S");
    });
    connect(D, &QPushButton::clicked, this, [=]() {
        addLetter("D");
    });
    connect(F, &QPushButton::clicked, this, [=]() {
        addLetter("F");
    });
    connect(G, &QPushButton::clicked, this, [=]() {
        addLetter("G");
    });
    connect(H, &QPushButton::clicked, this, [=]() {
        addLetter("H");
    });
    connect(J, &QPushButton::clicked, this, [=]() {
        addLetter("J");
    });
    connect(K, &QPushButton::clicked, this, [=]() {
        addLetter("K");
    });
    connect(L, &QPushButton::clicked, this, [=]() {
        addLetter("L");
    });
    connect(Z, &QPushButton::clicked, this, [=]() {
        addLetter("Z");
    });
    connect(X, &QPushButton::clicked, this, [=]() {
        addLetter("X");
    });
    connect(C, &QPushButton::clicked, this, [=]() {
        addLetter("C");
    });
    connect(V, &QPushButton::clicked, this, [=]() {
        addLetter("V");
    });
    connect(B, &QPushButton::clicked, this, [=]() {
        addLetter("B");
    });
    connect(N, &QPushButton::clicked, this, [=]() {
        addLetter("N");
    });
    connect(M, &QPushButton::clicked, this, [=]() {
        addLetter("M");
    });
    connect(Backspace, &QPushButton::clicked, this, &gameplay::removeLetter);
    connect(Confirm, &QPushButton::clicked, this, &gameplay::giveFeedback);
    connect(Clear, &QPushButton::clicked, this, &gameplay::clearLetter);
    connect(Giveup, &QPushButton::clicked, this, &gameplay::giveUp);
    connect(Reset, &QPushButton::clicked, this, &gameplay::reset);

    messageLabel = new QLabel(this);
    messageLabel->setStyleSheet("font-size: 24px; color: white;");
    messageLabel->move(500,100);
    messageLabel->setFixedSize(1000,100);

    typeTimer = new QTimer(this);
    connect(Confirm, &QPushButton::clicked, this, &gameplay::giveFeedback);
    connect(typeTimer, &QTimer::timeout, this, &gameplay::goonPrintError);

    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();

    for (auto button : buttons) {//按其它按钮，将error提示清除
        connect(button, &QPushButton::clicked, [=]() {
            messageLabel->clear();
        });
    }


}

gameplay::~gameplay()
{
    delete ui;
}

void gameplay::paintEvent(QPaintEvent *event){
    (void)event;
    QPainter painter(this);
    QPixmap pix;
    pix.load(":pictures/raglan.jpg");

}
void gameplay::addLetter(QString letter){
    if (currentIndex < len) {
        ans+=letter;
        letterBoxes[currentIndex++]->setText(letter);
    }
}
void gameplay::removeLetter(){
    if(currentIndex){
        ans.erase(ans.end() - 1);
        letterBoxes[--currentIndex]->clear();
    }
}
void gameplay::clearLetter(){
    ans="";
    while(currentIndex){
        letterBoxes[--currentIndex]->clear();
    }
}
void gameplay::giveUp(){
    clearLetter();
    for(int i=0;i<rans.size();++i){
        addLetter(rans.toUpper()[i]);
    }
}
void gameplay::reset(){
    clearLetter();
    for(int i=0;i<len;++i){
        letterBoxes[i]->setStyleSheet("QLineEdit { background-color: DEFULT; }");
    }
    read();
}
void gameplay::giveFeedback(){
    for(int i=0;i<len;++i){
        letterBoxes[i]->setStyleSheet("QLineEdit { background-color: BLACK; }");
    }
    ans=ans.toLower();
    if(ans.size()<len)return;
    if(!rec[ans]){
        startPrintError();
        return;
    }
    //ans和rans对比
    int judge[9]={0};
    for(int i=0;i<len;++i){
        if(ans[i]==rans[i])judge[i]=1;//位置正确
        else
            for(int j=0;j<len;++j){
                if(ans[i]==rans[j])judge[i]=2;//位置不正确
            }
    }
    for(int i=0;i<len;++i){
        if(judge[i]==0){
            changeColor0(ans[i]);
        }
        if(judge[i]==1){
            letterBoxes[i]->setStyleSheet("QLineEdit { background-color: GREEN; }");
            changeColor1(ans[i]);
        }
        if(judge[i]==2){
            letterBoxes[i]->setStyleSheet("QLineEdit { background-color: ORANGE; }");
            changeColor2(ans[i]);
        }
    }
}
void gameplay::changeColor0(QChar s){
    if(s=='a')A->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='b')B->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='c')C->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='d')D->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='e')E->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='f')F->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='g')G->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='h')H->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='i')I->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='j')J->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='k')K->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='l')L->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='m')M->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='n')N->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='o')O->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='p')P->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='q')Q->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='r')R->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='s')S->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='t')T->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='u')U->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='v')V->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='w')W->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='x')X->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='y')Y->setStyleSheet("QPushButton { background-color: BLACK; }");
    if(s=='z')Z->setStyleSheet("QPushButton { background-color: BLACK; }");
}
void gameplay::changeColor1(QChar s){
    if(s=='a')A->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='b')B->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='c')C->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='d')D->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='e')E->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='f')F->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='g')G->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='h')H->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='i')I->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='j')J->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='k')K->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='l')L->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='m')M->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='n')N->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='o')O->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='p')P->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='q')Q->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='r')R->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='s')S->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='t')T->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='u')U->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='v')V->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='w')W->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='x')X->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='y')Y->setStyleSheet("QPushButton { background-color: GREEN; }");
    if(s=='z')Z->setStyleSheet("QPushButton { background-color: GREEN; }");
}
void gameplay::changeColor2(QChar s){
    if(s=='a')A->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='b')B->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='c')C->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='d')D->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='e')E->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='f')F->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='g')G->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='h')H->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='i')I->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='j')J->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='k')K->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='l')L->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='m')M->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='n')N->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='o')O->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='p')P->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='q')Q->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='r')R->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='s')S->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='t')T->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='u')U->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='v')V->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='w')W->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='x')X->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='y')Y->setStyleSheet("QPushButton { background-color: ORANGE; }");
    if(s=='z')Z->setStyleSheet("QPushButton { background-color: ORANGE; }");
}
void gameplay::startPrintError(){
    error_s="";
    typingIndex=0;
    typeTimer->start(100);
}
void gameplay::goonPrintError(){
    if(typingIndex<errorMessage.length()){
        error_s+=errorMessage[typingIndex++];
        messageLabel->setText(error_s);
    }
}
void gameplay::read(){
    if(!haveRead){
        QFile file(":resources/words.txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qWarning() << "Unable to open file:";
            return;
        }
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            rec[line.toLower()]=1;
        }
        QFile file_(":resources/FourLevel.txt");
        if(!file_.open(QIODevice::ReadOnly | QIODevice::Text)){
            qWarning() << "Unable to open file_:";
            return;
        }
        QTextStream in_(&file_);
        while(!in_.atEnd()){
            QString line = in_.readLine(),lin="";
            for(int i=0;i<line.size();++i){
                if(line[i]<'A'||('Z'<line[i]&&line[i]<'a')||(line[i]>'z'))break;
                else lin+=line[i];
            }
            if(lin.size()>=4&&lin.size()<=7)qv.push_back(lin);
        }
        haveRead=1;
    }
    rans="";
    int randomIndex = QRandomGenerator::global()->bounded(qv.size());
    rans=qv[randomIndex];
    rans=rans.toLower();
    qDebug()<<rans;
    for(int i=0;i < len;++i){
        if(letterBoxes[i]!=nullptr)delete letterBoxes[i],letterBoxes[i]=nullptr;
    }
    len=rans.size();
    for (int i = 0; i < len; ++i) {
        letterBoxes[i] = new QLineEdit(this);
        letterBoxes[i]->setReadOnly(true);     // 设置为只读
        letterBoxes[i]->setAlignment(Qt::AlignCenter);
        letterBoxes[i]->setFixedSize(100, 100);  // 设置固定大小
        letterBoxes[i]->setFont(QFont("微软雅黑",25));
        letterBoxes[i]->move(600-((len%2==0)?(120*len/2-10):(50+len/2*120))+i*120,200);
        letterBoxes[i]->setStyleSheet("QLineEdit { background-color: DEFULT; }");
        letterBoxes[i]->show();
    }
    A->setStyleSheet("QPushButton { background-color: #808080; }");
    B->setStyleSheet("QPushButton { background-color: #808080; }");
    C->setStyleSheet("QPushButton { background-color: #808080; }");
    D->setStyleSheet("QPushButton { background-color: #808080; }");
    E->setStyleSheet("QPushButton { background-color: #808080; }");
    F->setStyleSheet("QPushButton { background-color: #808080; }");
    G->setStyleSheet("QPushButton { background-color: #808080; }");
    H->setStyleSheet("QPushButton { background-color: #808080; }");
    I->setStyleSheet("QPushButton { background-color: #808080; }");
    J->setStyleSheet("QPushButton { background-color: #808080; }");
    K->setStyleSheet("QPushButton { background-color: #808080; }");
    L->setStyleSheet("QPushButton { background-color: #808080; }");
    M->setStyleSheet("QPushButton { background-color: #808080; }");
    N->setStyleSheet("QPushButton { background-color: #808080; }");
    O->setStyleSheet("QPushButton { background-color: #808080; }");
    P->setStyleSheet("QPushButton { background-color: #808080; }");
    Q->setStyleSheet("QPushButton { background-color: #808080; }");
    R->setStyleSheet("QPushButton { background-color: #808080; }");
    S->setStyleSheet("QPushButton { background-color: #808080; }");
    T->setStyleSheet("QPushButton { background-color: #808080; }");
    U->setStyleSheet("QPushButton { background-color: #808080; }");
    V->setStyleSheet("QPushButton { background-color: #808080; }");
    W->setStyleSheet("QPushButton { background-color: #808080; }");
    X->setStyleSheet("QPushButton { background-color: #808080; }");
    Y->setStyleSheet("QPushButton { background-color: #808080; }");
    Z->setStyleSheet("QPushButton { background-color: #808080; }");
}
