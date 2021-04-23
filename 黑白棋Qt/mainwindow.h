#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QApplication>
#include "view.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createMenus();     //创建菜单
    void createActions();   //创建动作
private:
    //切换函数
    void changemodel(short _X);
    void modelone();
    void modeltwo();
    void modelthree();
    void close();
    //响应动作
    QAction *_modelOneAction;
    QAction *_modelTwoAction;
    QAction *_modelThreeAction;
    QAction *_closeAction;
    //窗口
    View *_centerWindow;
    //当前模式
    int _model;
};

#endif // MAINWINDOW_H
