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
namespace Ui {
class windows;
}

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

    //



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

class Organization                                                                          //组织机构结构体
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
#endif // MAINWINDOW_H
