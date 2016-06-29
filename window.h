#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QAction>
#include <QList>
#include <QTranslator>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QTextEdit>
#include <QLineEdit>
#include <QStringList>
#include <QTextCodec>
#include <QPalette>
#define MAX 999;
#define INIT_LEN_ARRAY 100//数组的初始化长度
#define MaxInt 32767;//表示极大值；

#define MVNum 100;
#define BDNum MVNum * (MVNum - 1);			//最大边数
#define OK 1;
#define ERROR 0;

namespace Ui {
class windows;
}

class Stack :public QWidget
{

public:
    Stack()
    {
        data = new int[INIT_LEN_ARRAY];
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }
    void Push(int value)//压栈
    {
        if (top == INIT_LEN_ARRAY - 1)
        {
            QMessageBox::information(this,"ERROR","Full Stack");
            return;
        }
        top++;
        data[top] = value;
    }
    void Pop(int& value)//出栈
    {
        if (top == -1)
        {
            QMessageBox::information(this,"ERROR","Empty Stack");
            return;
        }
        value = data[top];//将值保留在e中
        top--;
    }
    bool IsEmpty()//判断栈是否为空
    {
        if (top == -1)
            return true;
        return false;
    }
private:
    int* data;
    int top;
};

class windows :public QWidget
{
    Q_OBJECT
public:
    windows(QWidget *parent = 0);
    void open1();
    void open2();
    void open3();
    void Show_Menu_Address();
    void Save_Address();
    void Delete_Address();
    void Search_Address();
    void Modify_Address();
    void Traversal_Book();
    void MemberLevelManage();
    void Getscore();
    void Save_file_member();
    void Updatescore();
    void Scoresorted();
    void Deductscore();
    void Search_member();
    void Show_Menber_Average();
    //第二部分
    void windwos_for_Club_Basic_information();
    void Read_file_comunity();
    void Rivise_name();
    void Rivise_sponsor();
    void Rivise_property();
    void Rivise_slogan();
    void Rivise_purpose();
    void Rivise_regulation();
    void Traversal_comunity();

    void Windows_For_Organization_Management_Agency();
    void Initial_organization();
    void Traversal_organization();
    void Update_organization();
    void Del_organization();
    void Search_organization();

    void Windows_For_Support();
    void Save_File_Support();
    void Insert_Support();
    void Modify_Support();
    void Delete_Support();
    void Traversal_Support();
    void Search_Support();

    //第三部分
    void Get_ActiPlan();//从文件中读取活动详细信息
    void Outp_ActiPlan();//输出当前活动信息记录
    void Inse_ActiPlan();//插入活动信息记录
    void Modi_ActiPlan();//修改活动信息记录
    void ActiPlan_FeasAnal();//活动可行性分析（拓扑排序）
    void windows_plan();

    //
    //void show_prepare();
    void guide_school();
    //

    void Windwos_Evalute();
    void Initial_Evaluate();
    void Insert_Evaluate();
    void Delete_Evaluate();
    void Traversal_Evaluate();
    void Search_Evaluate();
private:
    QString temp_all;
    QPushButton *bttn1;
    QPushButton *bttn2;
    QPushButton *bttn3;

//3.1
    struct Acti_Plan
    {
        QString Code;//事件代号
        QString ActiName;//活动名称
        QString AnctDesc;//活动描述
        QString FollActi;//先行活动
    };
    struct gSqlist
    {
        Acti_Plan* elem;
        int lefght;
    }R;
    struct node//结点域
    {
        int vex;//后续活动下标
        node *next;
    };
    struct vrcnode
    {
        char data;//活动
        int In;//入度
        node* first;
    };
    struct Things
    {
        QString code;//事件代号
        QString thname;//事件名称
        QString thdesc;//事件描述
        QString desc;//解释
    };
    struct Actity
    {
        QString code;//代号
        QString Actiname;//活动名称
        QString Actidesc;//活动描述
        int weight;//权值
        QString fronth;//前事件
        QString afth;//后事件
    };
    struct Plan_Info
    {
        Things* thing;//结构体数组
        Actity* actity;
        int thnum, actinum;//事件数目，活动数目
    }T;


    //3.2


};


class AddressBook/**定义通讯录类将数据成员封装**/
{
public:
    QString stud_Name;/**学生姓名数据成员**/
    QString stud_Num;/**学号数据成员**/
    QString stud_Sex;/**性别数据成员**/
    QString stud_Class;/**班级数据成员**/
    QString comunity_Time;/**入社时间数据成员**/
    QString phone_Num;/**电话号码数据成员**/
    QString Address;/**通信地址数据成员**/
};
class LevelMember/**定义通讯录类将数据成员封装**/
{
public:
    QString stud_Name;/**学生姓名数据成员**/
    QString stud_Num;/**学号数据成员**/
    QString stud_Sex;/**性别数据成员**/
    QString stud_Class;/**班级数据成员**/
    QString comunity_Time;/**入社时间数据成员**/
    QString phone_Num;/**电话号码数据成员**/
    QString Address;/**通信地址数据成员**/
    int star;
    int score;
};
class Comunity
{
public:
    QString name;
    QString sponsor;
    QString property;
    QString slogan;
    QString purpose;
    QString regulation;
};

class Organization     //组织机构结构体
{
public:
    QString name;
    QString abstract;
    QString person;
    QString phonenum;
};

class Support_Sponsor/**定义赞助商信息类将数据成员封装**/
{
public:
    QString Name;/**赞助商名称数据成员**/
    QString Person;/**赞助商负责人数据成员**/
    QString Web;/**赞助商网址数据成员**/
    QString Brief;/**赞助商简介**/
    QString Support1;/**赞助社团1数据成员**/
    QString Support2;/**赞助社团2数据成员**/
    QString Support3;/**赞助社团3数据成员**/
    QString Support4;/**赞助社团4数据成员**/
    QString Support5;/**赞助社团5数据成员**/
};

class Evaluate/**定义活动评价管理类将数据成员封装**/
{
public:
    QString act_Name;/**活动名称数据成员**/
    QString stud_Num;/**学生学号数据成员**/
    QString stud_Name;/**学生姓名数据成员**/
    QString stud_Class;/**学生班级数据成员**/
    QString act_Time;/**活动时间数据成员**/
    QString act_Place;/**活动地点数据成员**/
    QString act_Score;/**活动评分数据成员**/
    QString act_Evaluate;/**活动评价数据成员**/
};
/*
class Graph
{
public:window_Messagetool
    int arcs[101][101];
    void pointpath(Graph &t,char cstart[20],char cend[20]);
};
*/




#endif // MAINWINDOW_H
