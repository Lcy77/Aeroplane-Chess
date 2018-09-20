#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmap.h"
#include "chess.h"
#include "circle.h"
#include "player.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitBoard();			//初始化所有棋盘上点的位置
    void InitChess();			//初始化所有棋子的位置
    void NewGame();			//新游戏
    void PlayRound();       //游戏中间的回合
    bool finish();      //判断游戏是否结束

    void Sleep(unsigned int msec);
    void ChangeItemPoint(Chess c, QPoint ptChess,QPoint pt);				//改变棋子位置属性
    void mousePressEvent(QMouseEvent *);  //鼠标点击以选择棋子
    void UpdateLocR();
    void UpdateLocY();
    void UpdateLocB();
    void UpdateLocG();
    bool ifFly();   //判断是否可以选择棋子
private slots:

    void on_BtnThrow_clicked();

    void on_pBtnStart_clicked();

    void on_overBtn_clicked();

private:
    Player PlayerRed;
    Player PlayerYellow;
    Player PlayerBlue;
    Player PlayerGreen;
    QVector<Circle> Circles;	//所有位置
    QVector<Circle> CirclesStart;    //起始位置
    QVector<Chess> Chesses;
    Chess m_SelectedChess;
    Ui::MainWindow *ui;
    int round;      //回合数
    int PlayTurn;      //应该由哪一方下，1234分别代表红黄蓝绿
    int ThrowNum;       //投掷的点数
    bool isThrow;
    bool isSelect;
    bool canChoose;
};

#endif // MAINWINDOW_H
