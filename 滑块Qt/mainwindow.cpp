#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(400,600);
    _window = new Window(this);
    this->setCentralWidget(_window);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    _modelOneAction = new QAction(QIcon(":/images/选中.png"), "开始轨迹绘画", this);
    _modelOneAction->setShortcut(QKeySequence(tr("Alt+1")));
    connect(_modelOneAction, &QAction::triggered, this, &MainWindow::modelone);

    _modelTwoAction = new QAction(QIcon(":/images/选中.png"), "结束轨迹绘画", this);
    _modelTwoAction->setShortcut(QKeySequence(tr("Alt+2")));
    connect(_modelTwoAction, &QAction::triggered, this, &MainWindow::modeltwo);


    _closeAction = new QAction(QIcon(":/images/close"), "关闭", this);//图案，名字
    _closeAction->setShortcut(QKeySequence(tr("Alt+F4")));//快捷键
    connect(_closeAction, &QAction::triggered, this, &MainWindow::close);//单击事件
}
void MainWindow::createMenus()
{
    //菜单栏
    QMenu *file1 = menuBar()->addMenu("轨迹绘画");
    file1->addAction(_modelOneAction);
    file1->addAction(_modelTwoAction);
    file1->addSeparator();
    file1->addAction(_closeAction);
}

//事件处理
void MainWindow::modelone()
{
    _window->isStart=true;
    _window->m_pX=0;
    _window->add=1;
    _window->m_nTimerId = _window->startTimer(100);
}
void MainWindow::modeltwo()
{
    _window->isStart=false;
}
void MainWindow::close()
{
    QApplication::exit();
}
