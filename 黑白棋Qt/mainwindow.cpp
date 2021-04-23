#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化
    _model=0;
    _centerWindow = new View(this,_model);
    this->setCentralWidget(_centerWindow);
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    _modelOneAction = new QAction(QIcon(":/images/选中.png"), "人人对战", this);
    _modelOneAction->setShortcut(QKeySequence(tr("Alt+1")));
    connect(_modelOneAction, &QAction::triggered, this, &MainWindow::modelone);

    _modelTwoAction = new QAction(QIcon(":/images/选中.png"), "人机对战（持黑子）", this);
    _modelTwoAction->setShortcut(QKeySequence(tr("Alt+2")));
    connect(_modelTwoAction, &QAction::triggered, this, &MainWindow::modeltwo);

    _modelThreeAction = new QAction(QIcon(":/images/选中.png"), "人机对战（持白子）", this);
    _modelThreeAction->setShortcut(QKeySequence(tr("Alt+3")));
    connect(_modelThreeAction, &QAction::triggered, this, &MainWindow::modelthree);

    _closeAction = new QAction(QIcon(":/images/close"), "关闭", this);//图案，名字
    _closeAction->setShortcut(QKeySequence(tr("Alt+F4")));//快捷键
    connect(_closeAction, &QAction::triggered, this, &MainWindow::close);//单击事件
}
void MainWindow::createMenus()
{
    //菜单栏
    QMenu *file1 = menuBar()->addMenu("游戏");
    file1->addAction(_modelOneAction);
    file1->addAction(_modelTwoAction);
    file1->addAction(_modelThreeAction);
    file1->addSeparator();
    file1->addAction(_closeAction);

}

//事件处理
void MainWindow::changemodel(short int _X)
{
    if(_model!=_X)
    {
        _model=_X;
        _centerWindow->init(this,_model);
    }
}

void MainWindow::modelone(){changemodel(0);}
void MainWindow::modeltwo(){changemodel(1);}
void MainWindow::modelthree(){changemodel(-1);}
void MainWindow::close()
{
    QApplication::exit();
}
