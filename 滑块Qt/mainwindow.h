#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QApplication>
#include "window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Window *_window;
    void createMenus();     //创建菜单
    void createActions();   //创建动作
private:
    //切换函数
    void modelone();
    void modeltwo();
    void close();
    //响应动作
    QAction *_modelOneAction;
    QAction *_modelTwoAction;
    QAction *_closeAction;
};
#endif // MAINWINDOW_H
