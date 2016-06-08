#include "ui_mainwindow.h"
#include "window.h"
#include "window_messagetool.h"
QList<AddressBook> addressbook;
QList<LevelMember> levelmember;
Comunity comunity;
QList<Organization> organization;
QList<Support_Sponsor> support;
QList<Evaluate> evaluate;
//交互界面+第一部分
void windows::open1()
{
    QWidget *windows1 = new QWidget;
    windows1->resize( QSize( 300, 300 ));
    windows1->setWindowTitle(tr("Member message manage"));

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

    QPushButton *bttn1 = new QPushButton(tr("Activities Management Plan"));
    QPushButton *bttn2 = new QPushButton("Preparatory activities management");
    QPushButton *bttn3 = new QPushButton("Evaluation of management activities");

    //connect(bttn1,&QPushButton::clicked,this,&windows::open1);
    //connect(bttn2,&QPushButton::clicked,this,&windows::open2);
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
    setWindowTitle("高校社团助手");
    resize( QSize( 300, 300 ));

    QLabel *info = new QLabel(this);
    info->setText("  Welcome to school club helper");
    info->setGeometry(QRect(20, 20, 260, 20));
    info->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    bttn1 = new QPushButton(tr("Member message manage"));
    bttn2 = new QPushButton("club helper");
    bttn3 = new QPushButton("club activity manage");
    connect(bttn1,&QPushButton::clicked,this,&windows::open1);
    connect(bttn2,&QPushButton::clicked,this,&windows::open2);
    connect(bttn3,&QPushButton::clicked,this,&windows::open3);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(bttn1);
    vbox->addWidget(bttn2);
    vbox->addWidget(bttn3);
    setLayout(vbox);
}

void windows::Show_Menu_Address()
{
    QWidget *windows = new QWidget();
    windows->resize( QSize( 400, 400 ));
    windows->setWindowTitle(tr("Address Book Manage"));

    QPushButton *bttn1 = new QPushButton(tr("Contacts initialization and saved to a file"));
    QPushButton *bttn2 = new QPushButton("Delete contacts members");
    QPushButton *bttn3 = new QPushButton("Contacts Lookup member");
    QPushButton *bttn4 = new QPushButton("Contacts modify records");
    QPushButton *bttn5 = new QPushButton("Insert address book record");
    QPushButton *bttn6 = new QPushButton("Contacts show all records");

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

    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Delete_Address"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Search_Address"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Modify_Address"));
    win->bttn->setText(tr("send"));

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
                QLineEdit *read1 = new QLineEdit;
                QLineEdit *read2 = new QLineEdit;
                QLineEdit *read3 = new QLineEdit;
                QLineEdit *read4 = new QLineEdit;
                QLineEdit *read5 = new QLineEdit;
                QLineEdit *read6 = new QLineEdit;
                QLineEdit *read7 = new QLineEdit;
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
    win->resize(600,200);
    win->setWindowTitle(tr("show_all"));
    int i;
    for(i = 0;i < addressbook.length();++i)
    {
        QString str = addressbook[i].stud_Name + temp + addressbook[i].stud_Num
                +addressbook[i] . stud_Sex + temp+addressbook[i].stud_Class+temp+
                addressbook[i].comunity_Time+ temp + addressbook[i].phone_Num + temp
                + addressbook[i].Address;
        QLineEdit *text = new QLineEdit(str);
        layout->addWidget(text);
    }
    win->setLayout(layout);
    win->show();
}
void windows::MemberLevelManage()
{
    QWidget *windows = new QWidget();
    windows->resize( QSize( 400, 400 ));
    windows->setWindowTitle(tr("Member Level Manage"));

    QPushButton *bttn1 = new QPushButton(tr("Initialization information"));
    QPushButton *bttn2 = new QPushButton("Increase score");
    QPushButton *bttn3 = new QPushButton("decrease score");
    QPushButton *bttn4 = new QPushButton("Search_member");
    QPushButton *bttn5 = new QPushButton("Show all Menber and Average");
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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Getscore"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Getscore"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Search_Menber_score"));
    win->bttn->setText(tr("send"));

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
        layout->addWidget(text);
    }
    QString info = "average is ";
    QString info_ave = QString::number(sum/levelmember.length(),10);
    QLineEdit *info_text = new QLineEdit(info+info_ave);
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


    QPushButton *bttn1 = new QPushButton(tr("Initial_comunity"));
    QPushButton *bttn2 = new QPushButton("Rivise_name");
    QPushButton *bttn3 = new QPushButton("Rivise_sponsor");
    QPushButton *bttn4 = new QPushButton(tr("Rivise_property"));
    QPushButton *bttn5 = new QPushButton("Rivise_slogan");
    QPushButton *bttn6 = new QPushButton("Rivise_purpose");
    QPushButton *bttn7 = new QPushButton("Rivise_regulation");
    QPushButton *bttn8 = new QPushButton("Traversal_comunity");


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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_name"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_sponsor"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_property"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_slogan"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_purpose"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Rivise_regulation"));
    win->bttn->setText(tr("send"));

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
    int i;

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


    QPushButton *bttn1 = new QPushButton(tr("Initial_organization"));
    QPushButton *bttn2 = new QPushButton("Traversal_organization");
    QPushButton *bttn3 = new QPushButton("Update_organization");
    QPushButton *bttn4 = new QPushButton(tr("Del_organization"));
    QPushButton *bttn5 = new QPushButton("Search_organization");



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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Update_organization"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Del_organization"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Search_organization"));
    win->bttn->setText(tr("send"));

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


    QPushButton *bttn1 = new QPushButton(tr("Save_File_Support"));
    QPushButton *bttn2 = new QPushButton("Insert_Support");
    QPushButton *bttn3 = new QPushButton("Modify_Support");
    QPushButton *bttn4 = new QPushButton(tr("Delete_Support"));
    QPushButton *bttn5 = new QPushButton("Traversal_Support");
    QPushButton *bttn6 = new QPushButton("Search_Support");


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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Insert_Support"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Modify_Support"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Delete_Support"));
    win->bttn->setText(tr("send"));

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
        layout->addWidget(text);
    }
    win->setLayout(layout);
    win->show();
}

void windows::Search_Support()
{
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Search_Support"));
    win->bttn->setText(tr("send"));

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


    QPushButton *bttn1 = new QPushButton(tr("Initial_Evaluate"));
    QPushButton *bttn2 = new QPushButton("Insert_Evaluate");
    QPushButton *bttn3 = new QPushButton("Delete_Evaluate");
    QPushButton *bttn4 = new QPushButton(tr("Traversal_Evaluate"));
    QPushButton *bttn5 = new QPushButton("Search_Evaluate");


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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Insert_Evaluate"));
    win->bttn->setText(tr("send"));

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
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Delete_Evaluate"));
    win->bttn->setText(tr("send"));

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
        layout->addWidget(text);
    }
    win->setLayout(layout);
    win->show();
}

void windows::Search_Evaluate()
{
    window_Messagetool *win = new window_Messagetool;
    win->setWindowTitle(tr("Search_Evaluate"));
    win->bttn->setText(tr("send"));

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
