#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QMap>
#include <QPushButton>
#include <QKeyEvent>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //按下数字
    void btnNumberClick();
    //按下二元运算符
    void btnBinaryOperatorClick();
    //按下单元运算符
    void btnUnaryOperatorClick();
    //按下小数点
    void on_btnPoint_clicked();
    //按下删除
    void on_btnErase_clicked();
    //按下清空
    void on_btnC_clicked();
    //按下等号
    void on_btnEqual_clicked();
    //键盘响应
    virtual void keyPressEvent(QKeyEvent *event);
    //按下将当前操作数清0
    void on_btnCE_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString operand;                    //操作数
    QStack<QString> operands;           //操作数栈
    QString opercode;                   //二元运算符
    QStack<QString> opercodes;          //二元运算符栈
    QMap<int,QPushButton*> digitBTNs;   //数字按钮集

    QString calculation(bool *ok=NULL);
    bool calculate();

};
#endif // MAINWINDOW_H
