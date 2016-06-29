#include "ui_mainwindow.h"
#include "windows.h"
QList<AddressBook> addressbook;
QList<LevelMember> levelmember;
Comunity comunity;
QList<Organization> organization;
QList<Support_Sponsor> support;
QList<Evaluate> evaluate;
#define MAX_V 20;
#define INFINITY 32767


typedef struct
{
    char *vexs[20] = {
        "南大门","英庐","群庐","运动场","和庐","祥庐","北门","静庐","一食堂","宁庐","翠庐"
        ,"荟庐","一教","至善广场","二教","体育馆","图文信息楼","大学生活动中心","商业街","二食堂"};

    int arcs[20][20];
    int vexnum,arcnum;
}MGraph;


void create(MGraph &G)
{
    int i = 0, j = 0;
    G.vexnum = 20; G.arcnum = 32;


    G.arcs[0][1] = 100;G.arcs[1][0] = 100;
    G.arcs[0][11] = 20;G.arcs[11][0] = 20;
    G.arcs[0][13] = 50;G.arcs[13][0] = 50;
    G.arcs[1][14] = 40;G.arcs[14][1] = 40;
    G.arcs[1][2] = 10;G.arcs[2][1] = 10;
    G.arcs[2][14] = 40;G.arcs[14][2] = 40;
    G.arcs[2][3] = 40;G.arcs[3][2] = 40;
    G.arcs[3][16] = 80;G.arcs[16][3] = 80;
    G.arcs[3][4] = 50;G.arcs[4][3] = 50;
    G.arcs[4][19] = 30;G.arcs[19][4] = 30;
    G.arcs[4][5] = 50;G.arcs[5][4] = 50;
    G.arcs[5][6] = 20;G.arcs[6][5] = 20;
    G.arcs[6][18] = 50;G.arcs[18][6] = 50;
    G.arcs[6][7] = 20;G.arcs[7][6] = 20;
    G.arcs[7][8] = 10;G.arcs[8][7] = 10;
    G.arcs[8][18] = 10;G.arcs[18][8] = 10;
    G.arcs[8][9] = 10; G.arcs[9][8] = 10;
    G.arcs[9][10] = 100;G.arcs[10][9] = 100;
    G.arcs[9][17] = 70;G.arcs[17][9] = 70;
    G.arcs[10][12] = 40;G.arcs[12][10] = 40;
    G.arcs[10][11] = 10;G.arcs[11][10] = 10;
    G.arcs[11][12] = 40;G.arcs[12][11] = 40;
    G.arcs[12][13] = 20;G.arcs[13][12] = 20;
    G.arcs[13][14] = 20;G.arcs[14][13] = 20;
    G.arcs[13][15] = 40;G.arcs[15][13] = 40;
    G.arcs[13][16] = 100;G.arcs[16][13] = 100;
    G.arcs[13][17] = 30;G.arcs[17][13] = 30;
    G.arcs[14][15] = 30;G.arcs[15][14] = 30;
    G.arcs[15][16] = 30;G.arcs[16][15] = 30;
    G.arcs[16][18] = 30;G.arcs[18][16] = 30;
    G.arcs[16][17] = 30;G.arcs[17][16] = 30;
    G.arcs[18][19] = 10;G.arcs[19][18] = 10;


    for(i = 0; i < G.vexnum ; i++ )
        for(j = 0 ; j < G.vexnum ; j++)
        {
            if(i == j)
                G.arcs[i][j] = 0;
            else
                G.arcs[i][j] = INFINITY;
        }

}
int have[20];//保存的最短路径下标
void ShortPath(MGraph &G,int v0,int p[20][20],int d[])
{
    int v,w,i,j,min;
    int final[20];
    int k = 1;
    for(v = 0 ; v < G.vexnum ; ++v)
    {
        final[v] = 0;
        d[v] = G.arcs[v0-1][v];
        for(w = 0; w < G.vexnum ; ++w)
            p[v][w] = 0;
        if(d[v] < INFINITY)
        {
            p[v][v0-1] = 1 ;
            p[v][v] = 1;
        }
    }
    d[v0-1] = 0 ;
    final[v0-1] = 1;
    have[0] = v0-1;
    for(i = 1 ; i < G.vexnum ; ++i)
    {
        min = INFINITY;
        for(w = 0 ; w < G.vexnum ; ++w)
            if(!final[w])
                if(d[w] < min)
                {
                    v = w;
                    min = d[w];
                }
        final[v] = 1;
        have[k] = v;
        k++;

        for(w = 0 ; w < G.vexnum ; ++w)
            if(!final[w]&&(min + G.arcs[v][w] < d[w]))
            {
                d[w] = min + G.arcs[v][w];
                for(j = 0 ; j < G.vexnum ; j++)
                    p[w][j] = p[v][j];
                p[w][w] = 1;
            }
    }
}


class Messagetool:public QDialog
{
public:
    Messagetool(QDialog *parent = 0);

    QTextEdit *readline;
    QPushButton *bttn;
    QString str;
protected:
   // void mouseMoveEvent(QMouseEvent *event);
};





//关键路径


typedef char VerTexType2;

typedef struct ArcNode
{                		//边结点
    int adjvex;                          	//该边所指向的顶点的位置
    int weight;								//权值
    struct ArcNode *nextarc;          		//指向下一条边的指针
}ArcNode;

typedef struct VNode
{
    VerTexType2 data;                    	//顶点信息
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针
}VNode, AdjList;               		//AdjList表示邻接表类型

typedef struct
{
    AdjList vertices[100];                 		//邻接表
    AdjList converse_vertices[100];				//逆邻接表
    int vexnum, arcnum;              		//图的当前顶点数和边数
}ALGraph;

typedef struct//- - - - -顺序栈的定义
{
    int *base;
    int *top;
    int stacksize;
}spStack;

int indegree[100];						//数组indegree存放个顶点的入度
int ve[9900];								//事件vi的最早发生时间
int vl[9900];								//事件vi的最迟发生时间
int topo[100];							//记录拓扑序列的顶点序号
spStack S;


typedef struct//------------图的邻接矩阵
{
    VerTexType2 vexs[100];            		//顶点表
    int  arcs[100][100];      		//邻接矩阵
    int vexnum,arcnum;                		//图的当前点数和边数
}AMGraph;




//

Messagetool::Messagetool(QDialog *parent)
    :QDialog(parent)
{
    readline = new QTextEdit;
    bttn = new QPushButton;
}
//交互界面+第一部分
void windows::open1()
{
    QWidget *windows1 = new QWidget;
    windows1->resize( QSize( 300, 300 ));
    windows1->setWindowTitle(tr("Member message manage"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows1->setPalette(palette);
    QPushButton *bttn1 = new QPushButton(tr("Address Book Manage"));

    QPushButton *bttn2 = new QPushButton("Member Level Manage");

    connect(bttn1,&QPushButton::clicked,this,&windows::Show_Menu_Address);
    connect(bttn2,&QPushButton::clicked,this,&windows::MemberLevelManage);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    windows1->setLayout(vbox);

    windows1->show();

   //QMessageBox::information(this,"Error","nobody");
}
void windows::open2()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("club helper"));

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);
    QPushButton *bttn1 = new QPushButton(tr("Club Basic information management"));
    QPushButton *bttn2 = new QPushButton("Organization Management Agency");
    QPushButton *bttn3 = new QPushButton("Sponsorship supplier management");

    connect(bttn1,&QPushButton::clicked,this,&windows::windwos_for_Club_Basic_information);
    connect(bttn2,&QPushButton::clicked,this,&windows::Windows_For_Organization_Management_Agency);
    connect(bttn3,&QPushButton::clicked,this,&windows::Windows_For_Support);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    windows2->setLayout(vbox);
    windows2->show();
   //QMessageBox::information(this,"Error","nobody");
}
void windows::open3()
{
    QWidget *windows3 = new QWidget;
    windows3->resize( QSize( 300, 300 ));
    windows3->setWindowTitle(tr("club activity manage"));
    //windows3->setStyleSheet("background-color: gray");
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows3->setPalette(palette);
    QPushButton *bttn1 = new QPushButton(tr("Activities Management Plan"));
    QPushButton *bttn2 = new QPushButton("Preparatory activities management");
    QPushButton *bttn3 = new QPushButton("Evaluation of management activities");

    connect(bttn1,&QPushButton::clicked,this,&windows::windows_plan);
    connect(bttn2,&QPushButton::clicked,this,&windows::guide_school);
    connect(bttn3,&QPushButton::clicked,this,&windows::Windwos_Evalute);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    windows3->setLayout(vbox);
    windows3->show();
   //QMessageBox::information(this,"Error","nobody");

}

windows::windows(QWidget *parent):QWidget(parent)
{

    //3.1
    R.elem = new Acti_Plan[INIT_LEN_ARRAY];
    R.lefght = 0;
    T.thing = new Things[INIT_LEN_ARRAY];
    T.actity = new Actity[INIT_LEN_ARRAY];

    this->setAutoFillBackground(true);

    setWindowTitle("高校社团助手");
    resize( QSize( 300, 300 ));

    QLabel *info = new QLabel(this);
    //info->setText("    Welcome To School Club Helper");
    info->setGeometry(QRect(20, 20, 260, 20));

    //info->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    this->setPalette(palette);

    bttn1 = new QPushButton(tr("Member message manage"));
    bttn1->setFixedSize(280,60);
    bttn1->setStyleSheet("background-color:rgb(213,176,195)");
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    bttn2 = new QPushButton("club helper");
    bttn2->setFixedSize(280,60);
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");
    bttn3 = new QPushButton("club activity manage");
    bttn3->setFixedSize(280,60);
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");


    connect(bttn1,&QPushButton::clicked,this,&windows::open1);
    connect(bttn2,&QPushButton::clicked,this,&windows::open2);
    connect(bttn3,&QPushButton::clicked,this,&windows::open3);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    setLayout(vbox);

    //text


}

void windows::Show_Menu_Address()
{
    QWidget *windows = new QWidget();
    windows->resize( QSize( 400, 400 ));
    windows->setWindowTitle(tr("Address Book Manage"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows->setPalette(palette);
    QPushButton *bttn1 = new QPushButton(tr("Contacts initialization and saved to a file"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Delete contacts members");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Contacts Lookup member");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton("Contacts modify records");
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Insert address book record");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn6 = new QPushButton("Contacts show all records");
    bttn6->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    connect(bttn1,&QPushButton::clicked,this,&windows::Save_Address);
    connect(bttn2,&QPushButton::clicked,this,&windows::Delete_Address);
    connect(bttn3,&QPushButton::clicked,this,&windows::Search_Address);
    connect(bttn4,&QPushButton::clicked,this,&windows::Modify_Address);
    connect(bttn6,&QPushButton::clicked,this,&windows::Traversal_Book);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);
    vbox->addWidget(bttn6);
    windows->setLayout(vbox);
    windows->show();
   //QMessageBox::information(this,"Error","nobody");
}

void windows::Save_Address()
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;
  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/text.txt");
    AddressBook temp;
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 1; i++)
        {

            temp.stud_Name = ou.readLine();
            temp.stud_Num = ou.readLine();
            temp.stud_Sex = ou.readLine();
            temp.stud_Class = ou.readLine();
            temp.comunity_Time = ou.readLine();
            temp.phone_Num = ou.readLine();
            temp.Address = ou.readLine();
            addressbook << temp;
        }
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }


}
void windows::Delete_Address()
{

    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Delete_Address"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);

    QLabel *lbl = new QLabel(win);
    lbl->setText("please input delete name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < addressbook.length();++i)
        {
            if(addressbook[i].stud_Name == win->str)
            {
                addressbook.removeAt(i);
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << addressbook.length();
}


void windows::Search_Address()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Search_Address"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input search name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < addressbook.length();++i)
        {
            if(addressbook[i].stud_Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QString temp = " ";
                QString str = addressbook[i].stud_Name + temp +addressbook[i].stud_Class;
                QTextEdit *showtext = new QTextEdit;
                showtext->setPlainText(str);
                showtext->show();
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << addressbook.length();
}

void windows::Modify_Address()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Modify_Address"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input modify name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < addressbook.length();++i)
        {
            if(addressbook[i].stud_Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit("Name");
                QLineEdit *read2 = new QLineEdit("Num");
                QLineEdit *read3 = new QLineEdit("Sex");
                QLineEdit *read4 = new QLineEdit("Class");
                QLineEdit *read5 = new QLineEdit("Comunity");
                QLineEdit *read6 = new QLineEdit("Phone");
                QLineEdit *read7 = new QLineEdit("Address");
                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(read5);
                layout->addWidget(read6);
                layout->addWidget(read7);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    AddressBook t1;
                    t1.stud_Name = read1->text();
                    t1.stud_Num = read2->text();
                    t1.stud_Sex = read3->text();
                    t1.stud_Class = read4->text();
                    t1.comunity_Time = read5->text();
                    t1.phone_Num = read6->text();
                    t1.Address = read7->text();
                    addressbook.removeAt(i);
                    addressbook.insert(i,t1);
                }

                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << addressbook[0].stud_Name;
}
void windows::Traversal_Book()
{
    QString temp = " ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    QString aa = "  Name   |   Num   |  Sex  |  Class  |  Comunity  |  Phone  |  Address";
    QLineEdit *info = new QLineEdit(aa);

    info->setReadOnly(true);
    layout->addWidget(info);

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    win->resize(600,200);
    win->setWindowTitle(tr("show_all"));
    int i;
    for(i = 0;i < addressbook.length();++i)
    {
        QString str = addressbook[i].stud_Name + temp + addressbook[i].stud_Num
                + temp +addressbook[i] . stud_Sex + temp+addressbook[i].stud_Class+temp+
                addressbook[i].comunity_Time+ temp + addressbook[i].phone_Num + temp
                + addressbook[i].Address;
        QLineEdit *text = new QLineEdit(str);
        text->setReadOnly(true);
        layout->addWidget(text,30);
    }
    win->setLayout(layout);
    win->show();
}
void windows::MemberLevelManage()
{
    QWidget *windows = new QWidget();
    windows->resize( QSize( 400, 400 ));
    windows->setWindowTitle(tr("Member Level Manage"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows->setPalette(palette);
    QPushButton *bttn1 = new QPushButton(tr("Initialization information"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Increase score");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("decrease score");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton("Search_member");
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Show all Menber and Average");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    //QPushButton *bttn6 = new QPushButton("sort by score");

    connect(bttn1,&QPushButton::clicked,this,&windows::Save_file_member);
    connect(bttn2,&QPushButton::clicked,this,&windows::Getscore);
    connect(bttn3,&QPushButton::clicked,this,&windows::Deductscore);
    connect(bttn4,&QPushButton::clicked,this,&windows::Search_member);
    connect(bttn5,&QPushButton::clicked,this,&windows::Show_Menber_Average);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);
    windows->setLayout(vbox);
    windows->show();
}
void windows::Save_file_member()
{
    QFile outfile;
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/chinesetext.txt");
    LevelMember temp;
    if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"ERROR","OPEN ERROR");
    }
    else
    {
        QTextStream ou(&outfile);
        ou.setCodec(codec);
    for (int i = 0; i < 1; i++)
    {

        temp.stud_Name = ou.readLine();
        temp.stud_Num = ou.readLine();
        temp.stud_Sex = ou.readLine();
        temp.stud_Class = ou.readLine();
        temp.comunity_Time = ou.readLine();
        temp.phone_Num = ou.readLine();
        temp.Address = ou.readLine();
        temp.star = ou.readLine().toInt();
        temp.score = ou.readLine().toInt();
        levelmember << temp;
    }
    QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
    }
}
void windows::Getscore()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Getscore"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input getscore name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < levelmember.length();++i)
        {
            if(levelmember[i].stud_Name == win->str)
            {
                levelmember[i].score = levelmember[i].score + 1 ;
                if(levelmember[i].score >= 10)
                {
                    levelmember[i].score = 0;
                    levelmember[i].star++;
                }
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << levelmember[0].score;

}
void windows::Deductscore()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Getscore"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input Deduct name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < levelmember.length();++i)
        {
            if(levelmember[i].stud_Name == win->str)
            {
                levelmember[i].score-- ;
                if(levelmember[i].score == -1 && levelmember[i].star != 0)
                {
                    levelmember[i].star--;
                    levelmember[i].score = 9 ;
                    QMessageBox::information(this,"SUCCESS","SUCCESS");
                }
                else
                {
                    levelmember[i].score++;
                    QMessageBox::information(this,"ERROR","limited!");
                }
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << levelmember[0].score;

}
void windows::Search_member()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Search_Menber_score"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input search name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < levelmember.length();++i)
        {
            if(levelmember[i].stud_Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QString temp = "The Menber score is ";
                QString temp2 = QString::number(levelmember[i].star*10+levelmember[i].score,10);
                QString str = temp + temp2;
                QTextEdit *showtext = new QTextEdit;
                showtext->setPlainText(str);
                showtext->show();
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }

}
void windows::Show_Menber_Average()
{
    QString temp = " ";
    QString temp1 = " star is ";
    QString temp2 = " score is ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    win->resize(600,200);
    win->setWindowTitle("show_all_average");
    int i,sum = 0;
    for(i = 0;i < levelmember.length();++i)
    {
        sum += levelmember[i].star*10 + levelmember[i].score;
        QString str1 = QString::number(levelmember[i].star,10);
        QString str2 = QString::number(levelmember[i].score,10);
        QString str = levelmember[i].stud_Name + temp+ temp1 + str1 +
                temp + temp2 +str2;
        QLineEdit *text = new QLineEdit(str);
        text->setReadOnly(true);
        layout->addWidget(text);
    }
    QString info = "average is ";
    QString info_ave = QString::number(sum/levelmember.length(),10);
    QLineEdit *info_text = new QLineEdit(info+info_ave);
    info_text->setReadOnly(true);
    layout->addWidget(info_text);
    win->setLayout(layout);
    win->show();
}

//第二部分

void windows::windwos_for_Club_Basic_information()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("club helper"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);

    QPushButton *bttn1 = new QPushButton(tr("Initial_comunity"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Rivise_name");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Rivise_sponsor");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton(tr("Rivise_property"));
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Rivise_slogan");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn6 = new QPushButton("Rivise_purpose");
    bttn6->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn7 = new QPushButton("Rivise_regulation");
    bttn7->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn8 = new QPushButton("Traversal_comunity");
    bttn8->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");



    connect(bttn1,&QPushButton::clicked,this,&windows::Read_file_comunity);
    connect(bttn2,&QPushButton::clicked,this,&windows::Rivise_name);
    connect(bttn3,&QPushButton::clicked,this,&windows::Rivise_sponsor);
    connect(bttn4,&QPushButton::clicked,this,&windows::Rivise_property);
    connect(bttn5,&QPushButton::clicked,this,&windows::Rivise_slogan);
    connect(bttn6,&QPushButton::clicked,this,&windows::Rivise_purpose);
    connect(bttn7,&QPushButton::clicked,this,&windows::Rivise_regulation);
    connect(bttn8,&QPushButton::clicked,this,&windows::Traversal_comunity);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);
    vbox->addWidget(bttn6);
    vbox->addWidget(bttn7);
    vbox->addWidget(bttn8);

    windows2->setLayout(vbox);
    windows2->show();
}

void windows::Read_file_comunity()
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;
  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/comunity.txt");
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 1; i++)
        {

            comunity.name = ou.readLine();
            comunity.sponsor = ou.readLine();
            comunity.property = ou.readLine();
            comunity.slogan = ou.readLine();
            comunity.purpose = ou.readLine();
            comunity.regulation = ou.readLine();
        }
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }
            qDebug() << comunity.name;

}

void windows::Rivise_name()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_name"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.name = win->str;

    }

    qDebug() << comunity.name;
}

void windows::Rivise_sponsor()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_sponsor"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input sponsor:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.sponsor = win->str;
    }
}

void windows::Rivise_property()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_property"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input property:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.property = win->str;
    }
}

void windows::Rivise_slogan()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_slogan"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input slogan:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.slogan = win->str;
    }
}

void windows::Rivise_purpose()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_purpose"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input purpose:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.purpose = win->str;
    }
}

void windows::Rivise_regulation()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Rivise_regulation"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input regulation:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        comunity.regulation = win->str;
    }
}

void windows::Traversal_comunity()
{
    QString temp = " | ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    win->resize(600,200);
    win->setWindowTitle(tr("show_all"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QString str = comunity.name + temp + comunity.sponsor + comunity.property + temp
            + comunity.slogan + temp + comunity.purpose + temp + comunity.regulation;

    QTextEdit *text = new QTextEdit(str);
    layout->addWidget(text);

    win->setLayout(layout);
    win->show();
}


void windows::Windows_For_Organization_Management_Agency()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("club helper"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);

    QPushButton *bttn1 = new QPushButton(tr("Initial_organization"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Traversal_organization");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Update_organization");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton(tr("Del_organization"));
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Search_organization");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");




    connect(bttn1,&QPushButton::clicked,this,&windows::Initial_organization);
    connect(bttn2,&QPushButton::clicked,this,&windows::Traversal_organization);
    connect(bttn3,&QPushButton::clicked,this,&windows::Update_organization);
    connect(bttn4,&QPushButton::clicked,this,&windows::Del_organization);
    connect(bttn5,&QPushButton::clicked,this,&windows::Search_organization);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);


    windows2->setLayout(vbox);
    windows2->show();
}

void windows::Initial_organization()
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;
  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/organization.txt");
    Organization temp;
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 1; i++)//读取一条数据
        {

            temp.name = ou.readLine();
            temp.abstract = ou.readLine();
            temp.person = ou.readLine();
            temp.phonenum = ou.readLine();

            organization << temp;
        }
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }
    qDebug()<<organization[0].phonenum;
}

void windows::Traversal_organization()
{
    QString temp = " | ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    win->resize(600,200);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    win->setWindowTitle(tr("show_all"));
    int i;
    for(i = 0 ; i <organization.length() ; i++)
    {

    QString str = organization[i].name + temp + organization[i].abstract + temp+
            organization[i].person + temp + organization[i].phonenum;

    QTextEdit *text = new QTextEdit(str);

    layout->addWidget(text);

    }

    win->setLayout(layout);
    win->show();
}

void windows::Update_organization()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Update_organization"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input modify organization name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < organization.length();++i)
        {
            if(organization[i].name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit;
                QLineEdit *read2 = new QLineEdit;
                QLineEdit *read3 = new QLineEdit;
                QLineEdit *read4 = new QLineEdit;
                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    Organization t1;
                    t1.name = read1->text();
                    t1.abstract = read2->text();
                    t1.person = read3->text();
                    t1.phonenum = read4->text();
                    organization.removeAt(i);
                    organization.insert(i,t1);
                }

                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << organization[0].phonenum;
}

void windows::Del_organization()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Del_organization"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input delete name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < organization.length();++i)
        {
            if(organization[i].name == win->str)
            {
                organization.removeAt(i);
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
}

void windows::Search_organization()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Search_organization"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input search name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < organization.length();++i)
        {
            if(organization[i].name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QString temp = " | ";
                QString str = organization[i].name + temp +organization[i].abstract + temp +
                        organization[i].person + organization[i].phonenum;
                QTextEdit *showtext = new QTextEdit;
                showtext->setPlainText(str);
                showtext->show();
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
}



void windows::Windows_For_Support()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("club helper"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);

    QPushButton *bttn1 = new QPushButton(tr("Save_File_Support"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Insert_Support");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Modify_Support");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton(tr("Delete_Support"));
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Traversal_Support");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn6 = new QPushButton("Search_Support");
    bttn6->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");



    connect(bttn1,&QPushButton::clicked,this,&windows::Save_File_Support);
    connect(bttn2,&QPushButton::clicked,this,&windows::Insert_Support);
    connect(bttn3,&QPushButton::clicked,this,&windows::Modify_Support);
    connect(bttn4,&QPushButton::clicked,this,&windows::Delete_Support);
    connect(bttn5,&QPushButton::clicked,this,&windows::Traversal_Support);
    connect(bttn6,&QPushButton::clicked,this,&windows::Search_Support);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);
    vbox->addWidget(bttn6);

    windows2->setLayout(vbox);
    windows2->show();
}

void windows::Save_File_Support()
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;
  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/support.txt");
    Support_Sponsor temp;
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 1; i++)//读取一条数据
        {

            temp.Name = ou.readLine();
            temp.Person = ou.readLine();
            temp.Web = ou.readLine();
            temp.Brief = ou.readLine();
            temp.Support1 = ou.readLine();
            temp.Support2 = ou.readLine();
            temp.Support3 = ou.readLine();
            temp.Support4 = ou.readLine();
            temp.Support5 = ou.readLine();

            support << temp;
        }
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }
        qDebug() << support[0].Support5;
}

void windows::Insert_Support()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Insert_Support"));
    win->bttn->setText(tr("send"));
   win-> bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input space you want to insert:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i =win->str.toInt();
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit;
                QLineEdit *read2 = new QLineEdit;
                QLineEdit *read3 = new QLineEdit;
                QLineEdit *read4 = new QLineEdit;
                QLineEdit *read5 = new QLineEdit;
                QLineEdit *read6 = new QLineEdit;
                QLineEdit *read7 = new QLineEdit;
                QLineEdit *read8 = new QLineEdit;
                QLineEdit *read9 = new QLineEdit;
                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(read5);
                layout->addWidget(read6);
                layout->addWidget(read7);
                layout->addWidget(read8);
                layout->addWidget(read9);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    Support_Sponsor t1;
                    t1.Name = read1->text();
                    t1.Person = read2->text();
                    t1.Web = read3->text();
                    t1.Brief = read4->text();
                    t1.Support1= read5->text();
                    t1.Support2 = read6->text();
                    t1.Support3 = read7->text();
                    t1.Support4 = read8->text();
                    t1.Support5 = read9->text();
                    support.insert(i,t1);
                }
        }
    qDebug() << support.length();
}

void windows::Modify_Support()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Modify_Support"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input modify name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        //QMessageBox::information(this,"SUCCESS","SUCCESS");
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < support.length(); ++i)
        {
            if(support[i].Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit;
                QLineEdit *read2 = new QLineEdit;
                QLineEdit *read3 = new QLineEdit;
                QLineEdit *read4 = new QLineEdit;
                QLineEdit *read5 = new QLineEdit;
                QLineEdit *read6 = new QLineEdit;
                QLineEdit *read7 = new QLineEdit;
                QLineEdit *read8 = new QLineEdit;
                QLineEdit *read9 = new QLineEdit;
                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(read5);
                layout->addWidget(read6);
                layout->addWidget(read7);
                layout->addWidget(read8);
                layout->addWidget(read9);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    Support_Sponsor t1;
                    t1.Name = read1->text();
                    t1.Person = read2->text();
                    t1.Web = read3->text();
                    t1.Brief = read4->text();
                    t1.Support1= read5->text();
                    t1.Support2 = read6->text();
                    t1.Support3 = read7->text();
                    t1.Support4 = read8->text();
                    t1.Support5 = read9->text();
                    support.removeAt(i);
                    support.insert(i,t1);
                }
                break;
               }

        }
       qDebug() << support[0].Name;
       qDebug() << support.length();
}
}

void windows::Delete_Support()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Delete_Support"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input delete name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;

        for(i = 0;i < support.length();++i)
        {
            if(support[i].Name == win->str)
            {
                support.removeAt(i);
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
    qDebug() << support.length();
}

void windows::Traversal_Support()
{
    QString temp = " | ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    win->resize(600,200);
    win->setWindowTitle(tr("show_all"));
    int i;
    for(i = 0;i < support.length();++i)
    {
        QString str = support[i].Name + temp + support[i].Person + temp
                + support[i].Web + temp+support[i].Brief+temp
                + support[i].Support1+ temp + support[i].Support2 + temp
                + support[i].Support3 + temp + support[i].Support4 + temp
                + support[i].Support5;
        QLineEdit *text = new QLineEdit(str);
        text->setReadOnly(true);
        layout->addWidget(text);
    }
    win->setLayout(layout);
    win->show();
}

void windows::Search_Support()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Search_Support"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input search name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < support.length();++i)
        {
            if(support[i].Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QString temp = " | ";
                QString str = support[i].Name + temp + support[i].Person + temp
                        + support[i].Web + temp+support[i].Brief+temp
                        + support[i].Support1+ temp + support[i].Support2 + temp
                        + support[i].Support3 + temp + support[i].Support4 + temp
                        + support[i].Support5;
                QTextEdit *showtext = new QTextEdit;
                showtext->setPlainText(str);
                showtext->resize(500,100);
                showtext->show();
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }

}


//第三部分
void windows::Windwos_Evalute()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("Windwos_Evalute"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);

    QPushButton *bttn1 = new QPushButton(tr("Initial_Evaluate"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Insert_Evaluate");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Delete_Evaluate");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton(tr("Traversal_Evaluate"));
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("Search_Evaluate");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");



    connect(bttn1,&QPushButton::clicked,this,&windows::Initial_Evaluate);
    connect(bttn2,&QPushButton::clicked,this,&windows::Insert_Evaluate);
    connect(bttn3,&QPushButton::clicked,this,&windows::Delete_Evaluate);
    connect(bttn4,&QPushButton::clicked,this,&windows::Traversal_Evaluate);
    connect(bttn5,&QPushButton::clicked,this,&windows::Search_Evaluate);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);

    windows2->setLayout(vbox);
    windows2->show();
}

void windows::Initial_Evaluate()
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;
  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/Evaluate.txt");
    Evaluate temp;
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 1; i++)//读取一条数据
        {

            temp.act_Name= ou.readLine();
            temp.stud_Num = ou.readLine();
            temp.stud_Name = ou.readLine();
            temp.stud_Class = ou.readLine();
            temp.act_Time = ou.readLine();
            temp.act_Place = ou.readLine();
            temp.act_Score = ou.readLine();
            temp.act_Evaluate = ou.readLine();

            evaluate << temp;
        }
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }
        qDebug() << evaluate[0].act_Evaluate;
}

void windows::Insert_Evaluate()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Insert_Evaluate"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input space you want to insert:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i =win->str.toInt();
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit;
                QLineEdit *read2 = new QLineEdit;
                QLineEdit *read3 = new QLineEdit;
                QLineEdit *read4 = new QLineEdit;
                QLineEdit *read5 = new QLineEdit;
                QLineEdit *read6 = new QLineEdit;
                QLineEdit *read7 = new QLineEdit;
                QLineEdit *read8 = new QLineEdit;
                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(read5);
                layout->addWidget(read6);
                layout->addWidget(read7);
                layout->addWidget(read8);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    Evaluate t1;
                    t1.act_Name= read1->text();
                    t1.stud_Num = read2->text();
                    t1.stud_Name = read3->text();
                    t1.stud_Class = read4->text();
                    t1.act_Time = read5->text();
                    t1.act_Place = read6->text();
                    t1.act_Score = read7->text();
                    t1.act_Evaluate = read8->text();
                    evaluate.insert(i,t1);
                }
        }
    qDebug() << evaluate.length();
}

void windows::Delete_Evaluate()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Delete_Evaluate"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input delete act_name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;

        for(i = 0;i < evaluate.length();++i)
        {
            if(evaluate[i].act_Name == win->str)
            {
                evaluate.removeAt(i);
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
}

void windows::Traversal_Evaluate()
{
    QString temp = " | ";
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    win->resize(600,200);
    win->setWindowTitle(tr("show_all"));
    int i;
    for(i = 0;i < evaluate.length();++i)
    {
        QString str = evaluate[i].act_Name + temp + evaluate[i].stud_Num + temp
                + evaluate[i].stud_Name + temp+evaluate[i].stud_Class+temp
                + evaluate[i].act_Time+ temp + evaluate[i].act_Place + temp
                + evaluate[i].act_Score + temp + evaluate[i].act_Evaluate;
        QLineEdit *text = new QLineEdit(str);
        text->setReadOnly(true);
        layout->addWidget(text);
    }
    win->setLayout(layout);
    win->show();
}

void windows::Search_Evaluate()
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Search_Evaluate"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input search act_name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < evaluate.length();++i)
        {
            if(evaluate[i].act_Name == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QString temp = " | ";
                QString str = evaluate[i].act_Name + temp + evaluate[i].stud_Num + temp
                        + evaluate[i].stud_Name + temp+evaluate[i].stud_Class+temp
                        + evaluate[i].act_Time+ temp + evaluate[i].act_Place + temp
                        + evaluate[i].act_Score + temp + evaluate[i].act_Evaluate;
                QTextEdit *showtext = new QTextEdit;
                showtext->setReadOnly(true);
                showtext->setPlainText(str);
                showtext->resize(500,100);
                showtext->show();
                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
}
//3.1
void windows::ActiPlan_FeasAnal()//活动可行性分析（拓扑排序）
{
    vrcnode *topo = new vrcnode[6];
    topo[0].data = 'A';
    topo[0].In = 3;
    topo[0].first = NULL;
    topo[1].data = 'B';
    topo[1].In = 0;
    topo[1].first = new node;
    topo[1].first->vex = 0;
    topo[1].first->next = new node;
    topo[1].first->next->vex = 3;
    topo[1].first->next->next = NULL;
    topo[2].data = 'C';
    topo[2].In = 1;
    topo[2].first = new node;
    topo[2].first->vex = 0;
    topo[2].first->next = new node;
    topo[2].first->next->vex = 3;
    topo[2].first->next->next = NULL;
    topo[3].data = 'D';
    topo[3].In = 3;
    topo[3].first = new node;
    topo[3].first->vex = 0;
    topo[3].first->next = new node;
    topo[3].first->next->vex = 5;
    topo[3].first->next->next = NULL;
    topo[4].data = 'E';
    topo[4].In = 0;
    topo[4].first = new node;
    topo[4].first->vex = 2;
    topo[4].first->next = new node;
    topo[4].first->next->vex = 3;
    topo[4].first->next->next = new node;
    topo[4].first->next->next->vex = 5;
    topo[4].first->next->next->next = NULL;
    topo[5].data = 'F';
    topo[5].In = 2;
    topo[5].first = NULL;
    Stack s;//初始化一个栈对象

    //cout << "开始拓扑排序..."<<endl;

    int count = 0;//判断是否完成拓扑排序

    for (int i = 0;i<6;i++)
    {
        if (topo[i].In == 0)
        {
            s.Push(i);
        }
    }

    QLineEdit *text = new QLineEdit;
    QString temp_text;
    while (!s.IsEmpty())//只要栈不为空，则循环进行
    {
        int value;
        s.Pop(value);

        QString aa;
        aa.append(topo[value].data);
        aa.append("->");
        temp_text += aa;
        count++;
        for (node* p = topo[value].first;p;p = p->next)//将topo[e]的弧删除
        {
            topo[p->vex].In--;
            if (topo[p->vex].In == 0)
                s.Push(p->vex);
        }
    }
    //
    if (6 == count)
        QMessageBox::information(this,"SUCCESS","Topo Success");
    else
        QMessageBox::information(this,"ERROR","Topo Error");
    text->setText(temp_text);
    text->show();
    //内存清理
    for (int i = 0;i<6;i++)
    {
        node* p = topo[i].first, *pr;
        while (p)
        {
            pr = p;
            p = p->next;
            delete[] pr;
        }
    }
    delete[] topo;

}

void windows::Inse_ActiPlan()//插入活动信息记录
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Insert_Rncord"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input space you want to insert:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int position =win->str.toInt();
        if(position>=R.lefght + 2 || position < 1)
        {
           // QMessageBox(this,"ERROR","Cross The Border");
            delete win;
        }
                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");
                QLineEdit *read1 = new QLineEdit("code");
                QLineEdit *read2 = new QLineEdit("ActiName");
                QLineEdit *read3 = new QLineEdit("AnctDesc");
                QLineEdit *read4 = new QLineEdit("FollActi");

                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);

                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    for (int i = R.lefght;i >= position;i--)
                    {
                        R.elem[i + 1] = R.elem[i];
                    }
                    R.elem[position].Code = read1->text();
                    R.elem[position].ActiName = read1->text();
                    R.elem[position].AnctDesc = read1->text();
                    R.elem[position].FollActi = read1->text();
                    R.lefght++;
                }
        }
}

void windows::Outp_ActiPlan()//输出当前活动信息记录
{

    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *win = new QWidget();
    win->resize(600,200);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    win->setWindowTitle("show present record");
    int i;
    QString info = "   ";
    for(i = 0;i < R.lefght;++i)
    {
        QString str ;
        str = R.elem[i].Code + info + R.elem[i].ActiName + info + R.elem[i].AnctDesc + info
                + R.elem[i].FollActi;
        QLineEdit *text = new QLineEdit(str);
        text->setReadOnly(true);
        layout->addWidget(text);
    }

    win->setLayout(layout);
    win->show();
}

void windows::Modi_ActiPlan()//修改活动信息记录
{
    Messagetool *win = new Messagetool;
    win->setWindowTitle(tr("Modify_Record"));
    win->bttn->setText(tr("send"));
    win->bttn->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QLabel *lbl = new QLabel(win);
    lbl->setText("please input modify activity_name:");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(win->readline);
    layout->addWidget(win->bttn);
    win->setLayout(layout);

    connect(win->bttn,&QPushButton::clicked,win,&QDialog::accept);


    if ( win->exec() == QDialog::Accepted )
    {
        win->str = win->readline->toPlainText();
        int i;
        for(i = 0;i < R.lefght;++i)
        {
            if(R.elem[i].ActiName == win->str)
            {

                QMessageBox::information(this,"SUCCESS","SUCCESS");
                QDialog *wins = new QDialog;
                wins->setWindowTitle("show");

                QLineEdit *read1 = new QLineEdit("code");
                QLineEdit *read2 = new QLineEdit("ActiName");
                QLineEdit *read3 = new QLineEdit("AnctDesc");
                QLineEdit *read4 = new QLineEdit("FollActi");

                QPushButton *bttn = new QPushButton();
                bttn->setText("send");
                QVBoxLayout *layout = new QVBoxLayout;
                layout->addWidget(read1);
                layout->addWidget(read2);
                layout->addWidget(read3);
                layout->addWidget(read4);
                layout->addWidget(bttn);
                wins->setLayout(layout);
                connect(bttn,&QPushButton::clicked,wins,&QDialog::accept);
                if ( wins->exec() == QDialog::Accepted )
                {
                    R.elem[i].Code = read1->text();
                    R.elem[i].ActiName = read2->text();
                    R.elem[i].AnctDesc = read3->text();
                    R.elem[i].FollActi = read4->text();
                }

                break;
            }
            else
            {
                QMessageBox::information(this,"ERROR","ERROR");
                break;
            }
        }
        }
}

void windows::Get_ActiPlan()//从文件中读取活动详细信息
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QFile outfile;

  //  QMessageBox::information(this,"SHOW","OPEN SHOW");
    outfile.setFileName(":/new/res/topo.txt");
        if (!outfile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"ERROR","OPEN ERROR");
        }
        else
        {
            QTextStream ou(&outfile);
            ou.setCodec(codec);
        for (int i = 0; i < 6; i++)
        {
            QString temp = ou.readLine();
            QStringList temp_L = temp.split("#");
            R.elem[i].Code = temp_L[0];
            R.elem[i].ActiName = temp_L[1];
            R.elem[i].AnctDesc = temp_L[2];
            R.elem[i].FollActi = temp_L[3];
        }
        R.lefght = 6;
        QMessageBox::information(this,"SUCCESS","OPEN SUCCESS");
        }
        outfile.close();
}

void windows::windows_plan()
{
    QWidget *windows2 = new QWidget;
    windows2->resize( QSize( 300, 300 ));
    windows2->setWindowTitle(tr("club helper"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    windows2->setPalette(palette);

    QPushButton *bttn1 = new QPushButton(tr("Initial_Actiplan"));
    bttn1->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn2 = new QPushButton("Insert_ActiPlan");
    bttn2->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn3 = new QPushButton("Modity_ActiPlan");
    bttn3->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn4 = new QPushButton(tr("Output_ActiPlan"));
    bttn4->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn5 = new QPushButton("ActiPlan_FeasAnal");
    bttn5->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");

    QPushButton *bttn6 = new QPushButton("ActiPlan_FeasAnal");
    bttn6->setStyleSheet("border:2px groove rgb(213,176,195);border-radius:10px;padding:2px 4px;");


    connect(bttn1,&QPushButton::clicked,this,&windows::Get_ActiPlan);
    connect(bttn2,&QPushButton::clicked,this,&windows::Inse_ActiPlan);
    connect(bttn3,&QPushButton::clicked,this,&windows::Modi_ActiPlan);
    connect(bttn4,&QPushButton::clicked,this,&windows::Outp_ActiPlan);
    connect(bttn5,&QPushButton::clicked,this,&windows::ActiPlan_FeasAnal);
    connect(bttn6,&QPushButton::clicked,this,&windows::ActiPlan_FeasAnal);



    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    vbox->addWidget(bttn4);
    vbox->addWidget(bttn5);
    vbox->addWidget(bttn6);


    windows2->setLayout(vbox);
    windows2->show();
}

//3.2

void windows::guide_school()
{   //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QDialog *win = new QDialog;
    QLabel *pic = new QLabel(win);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/23")));

    win->setPalette(palette);
    QPixmap pix(":/images/2");
    QLabel *text = new QLabel(win);

    pic->setPixmap(pix);
   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(pic);
   win->setLayout(layout);


    win->show();
}

int main(int argc, char *argv[])
{

    QApplication shit(argc, argv);
    QTranslator oTranslator;
    windows win;
    win.show();
    return shit.exec();
}
