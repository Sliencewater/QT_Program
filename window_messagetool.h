#ifndef WINDOW_MESSAGETOOL_H
#define WINDOW_MESSAGETOOL_H
class window_Messagetool:public QDialog
{
public:
    window_Messagetool(QDialog *parent = 0);

    QTextEdit *readline;
    QPushButton *bttn;
    QString str;
protected:
   // void mouseMoveEvent(QMouseEvent *event);
};
window_Messagetool::window_Messagetool(QDialog *parent)
    :QDialog(parent)
{
    readline = new QTextEdit;
    bttn = new QPushButton;
}
#endif





// WINDOW_MESSAGETOOL_H
