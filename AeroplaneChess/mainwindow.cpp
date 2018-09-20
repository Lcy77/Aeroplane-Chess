
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QApplication>
#include <ctime>
#include <qlcdnumber.h>
#include <qvector.h>
#include <QPoint>
#include <QtGlobal>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NewGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)        //选棋并进行走棋
{
    QPoint pt;
    pt.setX(e->pos().x());
    pt.setY(e->pos().y());
    if (ThrowNum != 0){
    switch (PlayTurn) {
    case 1:{
        if (ThrowNum == 6){
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerRed.getchess(i)->c_pt.x() && pt.x() <= PlayerRed.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerRed.getchess(i)->c_pt.y() && pt.y() <= PlayerRed.getchess(i)->c_pt.y() + 50){
                    if (PlayerRed.getchess(i)->ifStart == false){
                        PlayerRed.getchess(i)->Fly(true);
                        PlayerRed.getchess(i)->Position(29);
                        PlayerRed.getchess(i)->ChangePoint(CirclesStart[0].point());
                        UpdateLocR();
                    }
                    else{
                        PlayerRed.getchess(i)->Forward(6);
                        PlayerRed.getchess(i)->ChangePoint(Circles[PlayerRed.getchess(i)->position - 1].point());
                        UpdateLocR();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerRed.getchess(i)->c_pt.x() && pt.x() <= PlayerRed.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerRed.getchess(i)->c_pt.y() && pt.y() <= PlayerRed.getchess(i)->c_pt.y() + 50){
                    if (!PlayerRed.getchess(i)->ifStart){
                        ui->textEdit->insertPlainText("未投掷到6点，该飞机无法起飞\n");
                        isSelect = false;
                        return;
                    }
                    else{
                        PlayerRed.getchess(i)->Forward(6);
                        PlayerRed.getchess(i)->ChangePoint(Circles[PlayerRed.getchess(i)->position - 1].point());
                        UpdateLocR();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                }
            }
        }
    }
        break;

    case 2:{
        if (ThrowNum == 6){
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerYellow.getchess(i)->c_pt.x() && pt.x() <= PlayerYellow.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerYellow.getchess(i)->c_pt.y() && pt.y() <= PlayerYellow.getchess(i)->c_pt.y() + 50){
                    if (PlayerYellow.getchess(i)->ifStart == false){
                        PlayerYellow.getchess(i)->Fly(true);
                        PlayerYellow.getchess(i)->Position(42);
                        PlayerYellow.getchess(i)->ChangePoint(CirclesStart[1].point());
                        UpdateLocY();
                    }
                    else{
                        PlayerYellow.getchess(i)->Forward(6);
                        PlayerYellow.getchess(i)->ChangePoint(Circles[PlayerYellow.getchess(i)->position - 1].point());
                        UpdateLocY();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerYellow.getchess(i)->c_pt.x() && pt.x() <= PlayerYellow.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerYellow.getchess(i)->c_pt.y() && pt.y() <= PlayerYellow.getchess(i)->c_pt.y() + 50){
                    if (!PlayerYellow.getchess(i)->ifStart){
                        ui->textEdit->insertPlainText("未投掷到6点，该飞机无法起飞\n");
                        isSelect = false;
                        return;
                    }
                    else{
                        PlayerYellow.getchess(i)->Forward(6);
                        PlayerYellow.getchess(i)->ChangePoint(Circles[PlayerYellow.getchess(i)->position - 1].point());
                        UpdateLocY();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                }
            }
        }
    }
        break;

    case 3:{
        if (ThrowNum == 6){
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerBlue.getchess(i)->c_pt.x() && pt.x() <= PlayerBlue.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerBlue.getchess(i)->c_pt.y() && pt.y() <= PlayerBlue.getchess(i)->c_pt.y() + 50){
                    if (PlayerBlue.getchess(i)->ifStart == false){
                        PlayerBlue.getchess(i)->Fly(true);
                        PlayerBlue.getchess(i)->Position(3);
                        PlayerBlue.getchess(i)->ChangePoint(CirclesStart[2].point());
                        UpdateLocB();
                    }
                    else{
                        PlayerBlue.getchess(i)->Forward(6);
                        PlayerBlue.getchess(i)->ChangePoint(Circles[PlayerBlue.getchess(i)->position - 1].point());
                        UpdateLocB();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerBlue.getchess(i)->c_pt.x() && pt.x() <= PlayerBlue.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerBlue.getchess(i)->c_pt.y() && pt.y() <= PlayerBlue.getchess(i)->c_pt.y() + 50){
                    if (!PlayerBlue.getchess(i)->ifStart){
                        ui->textEdit->insertPlainText("未投掷到6点，该飞机无法起飞\n");
                        isSelect = false;
                        return;
                    }
                    else{
                        PlayerBlue.getchess(i)->Forward(6);
                        PlayerBlue.getchess(i)->ChangePoint(Circles[PlayerBlue.getchess(i)->position - 1].point());
                        UpdateLocB();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                }
            }
        }
    }
        break;

    case 4:{
        if (ThrowNum == 6){
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerGreen.getchess(i)->c_pt.x() && pt.x() <= PlayerGreen.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerGreen.getchess(i)->c_pt.y() && pt.y() <= PlayerGreen.getchess(i)->c_pt.y() + 50){
                    if (PlayerGreen.getchess(i)->ifStart == false){
                        PlayerGreen.getchess(i)->Fly(true);
                        PlayerGreen.getchess(i)->Position(15);
                        PlayerGreen.getchess(i)->ChangePoint(CirclesStart[3].point());
                        UpdateLocG();
                    }
                    else{
                        PlayerGreen.getchess(i)->Forward(6);
                        PlayerGreen.getchess(i)->ChangePoint(Circles[PlayerGreen.getchess(i)->position - 1].point());
                        UpdateLocG();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < 4; i++){
                if (pt.x() >= PlayerGreen.getchess(i)->c_pt.x() && pt.x() <= PlayerGreen.getchess(i)->c_pt.x() + 50
                        && pt.y() >= PlayerGreen.getchess(i)->c_pt.y() && pt.y() <= PlayerGreen.getchess(i)->c_pt.y() + 50){
                    if (!PlayerGreen.getchess(i)->ifStart){
                        ui->textEdit->insertPlainText("未投掷到6点，该飞机无法起飞\n");
                        isSelect = false;
                        return;
                    }
                    else{
                        PlayerGreen.getchess(i)->Forward(6);
                        PlayerGreen.getchess(i)->ChangePoint(Circles[PlayerGreen.getchess(i)->position - 1].point());
                        UpdateLocG();
                    }
                    isSelect = true;
                    ThrowNum = 0;
                }
            }
        }
    }
        break;
    default:
        break;
    }
    }
}

void MainWindow::InitBoard()
{
    Chess cs_r1(CHESS_RED, QPoint(625,70)); Chesses.push_back(cs_r1);   //16个棋子初始化
    Chess cs_r2(CHESS_RED, QPoint(685,70)); Chesses.push_back(cs_r2);
    Chess cs_r3(CHESS_RED, QPoint(625,125)); Chesses.push_back(cs_r3);
    Chess cs_r4(CHESS_RED, QPoint(685,125)); Chesses.push_back(cs_r4);
    Chess cs_y1(CHESS_YELLOW, QPoint(625,617)); Chesses.push_back(cs_y1);
    Chess cs_y2(CHESS_YELLOW, QPoint(685,617)); Chesses.push_back(cs_y2);
    Chess cs_y3(CHESS_YELLOW, QPoint(625,673)); Chesses.push_back(cs_y3);
    Chess cs_y4(CHESS_YELLOW, QPoint(685,674)); Chesses.push_back(cs_y4);
    Chess cs_b1(CHESS_BLUE, QPoint(65,617)); Chesses.push_back(cs_b1);
    Chess cs_b2(CHESS_BLUE, QPoint(122,617)); Chesses.push_back(cs_b2);
    Chess cs_b3(CHESS_BLUE, QPoint(65,673)); Chesses.push_back(cs_b3);
    Chess cs_b4(CHESS_BLUE, QPoint(122,617)); Chesses.push_back(cs_b4);
    Chess cs_g1(CHESS_GREEN, QPoint(65,70)); Chesses.push_back(cs_g1);
    Chess cs_g2(CHESS_GREEN, QPoint(122,70)); Chesses.push_back(cs_g2);
    Chess cs_g3(CHESS_GREEN, QPoint(65,125)); Chesses.push_back(cs_g3);
    Chess cs_g4(CHESS_GREEN, QPoint(122,125)); Chesses.push_back(cs_g4);

    PlayerRed.setType(PLAYER_RED);
    PlayerYellow.setType(PLAYER_YELLOW);
    PlayerBlue.setType(PLAYER_BLUE);
    PlayerGreen.setType(PLAYER_GREEN);
    for (int i = 0; i < 4; i++){            //为4方玩家初始化棋子
        PlayerRed.addChess(Chesses[i]);
    }
    for (int i = 4; i < 8; i++){
        PlayerYellow.addChess(Chesses[i]);
    }
    for (int i = 8; i < 12; i++){
        PlayerBlue.addChess(Chesses[i]);
    }
    for (int i = 12; i < 12; i++){
        PlayerGreen.addChess(Chesses[i]);
    }

    Circle c1(CIRCLE_BLUE, 1, QPoint(375,695), 1); Circles.push_back(c1);   //外围位置初始化
    Circle c2(CIRCLE_GREEN, 2, QPoint(330,695), 1); Circles.push_back(c2);
    Circle c3(CIRCLE_RED, 3, QPoint(285,695), 1); Circles.push_back(c3);
    Circle c4(CIRCLE_YELLOW, 4, QPoint(235,680), 1); Circles.push_back(c4);
    Circle c5(CIRCLE_BLUE, 5, QPoint(220,635), 1); Circles.push_back(c5);
    Circle c6(CIRCLE_GREEN, 6, QPoint(220,590), 1); Circles.push_back(c6);
    Circle c7(CIRCLE_RED, 7, QPoint(240, 520), 1); Circles.push_back(c7);
    Circle c8(CIRCLE_YELLOW, 8, QPoint(200,510), 1); Circles.push_back(c8);
    Circle c9(CIRCLE_BLUE, 9, QPoint(150, 525), 1); Circles.push_back(c9);
    Circle c10(CIRCLE_GREEN, 10, QPoint(105, 525), 1); Circles.push_back(c10);
    Circle c11(CIRCLE_RED, 11, QPoint(60, 510), 1); Circles.push_back(c11);
    Circle c12(CIRCLE_YELLOW, 12, QPoint(40,460), 1); Circles.push_back(c12);
    Circle c13(CIRCLE_BLUE, 13, QPoint(40, 420), 1); Circles.push_back(c13);
    Circle c14(CIRCLE_GREEN, 14, QPoint(40, 375), 1); Circles.push_back(c14);
    Circle c15(CIRCLE_RED, 15, QPoint(40,335), 1); Circles.push_back(c15);
    Circle c16(CIRCLE_YELLOW, 16, QPoint(40,290), 1); Circles.push_back(c16);
    Circle c17(CIRCLE_BLUE, 17, QPoint(60, 240), 1); Circles.push_back(c17);
    Circle c18(CIRCLE_GREEN, 18, QPoint(108,225), 1); Circles.push_back(c18);
    Circle c19(CIRCLE_RED, 19, QPoint(150, 225), 1); Circles.push_back(c19);
    Circle c20(CIRCLE_YELLOW, 20, QPoint(200,240), 1); Circles.push_back(c20);
    Circle c21(CIRCLE_BLUE, 21, QPoint(235,210), 1); Circles.push_back(c21);
    Circle c22(CIRCLE_GREEN, 22, QPoint(220, 160), 1); Circles.push_back(c22);
    Circle c23(CIRCLE_RED, 23, QPoint(220,115), 1); Circles.push_back(c23);
    Circle c24(CIRCLE_YELLOW, 24, QPoint(240,70), 1); Circles.push_back(c24);
    Circle c25(CIRCLE_BLUE, 25, QPoint(285,50), 1); Circles.push_back(c25);
    Circle c26(CIRCLE_GREEN, 26, QPoint(330, 50), 1); Circles.push_back(c26);
    Circle c27(CIRCLE_RED, 27, QPoint(375,50), 1); Circles.push_back(c27);
    Circle c28(CIRCLE_YELLOW, 28, QPoint(420,50), 1); Circles.push_back(c28);
    Circle c29(CIRCLE_BLUE, 29, QPoint(465,50), 1); Circles.push_back(c29);
    Circle c30(CIRCLE_GREEN, 30, QPoint(510,70), 1); Circles.push_back(c30);
    Circle c31(CIRCLE_RED, 31, QPoint(530,115), 1); Circles.push_back(c31);
    Circle c32(CIRCLE_YELLOW, 32, QPoint(530,160), 1); Circles.push_back(c32);
    Circle c33(CIRCLE_BLUE, 33, QPoint(510,210), 1); Circles.push_back(c33);
    Circle c34(CIRCLE_GREEN, 34, QPoint(550,240), 1); Circles.push_back(c34);
    Circle c35(CIRCLE_RED, 35, QPoint(600,230), 1); Circles.push_back(c35);
    Circle c36(CIRCLE_YELLOW, 36, QPoint(642,230), 1); Circles.push_back(c36);
    Circle c37(CIRCLE_BLUE, 37, QPoint(690,240), 1); Circles.push_back(c37);
    Circle c38(CIRCLE_GREEN, 38, QPoint(705,290), 1); Circles.push_back(c38);
    Circle c39(CIRCLE_RED, 39, QPoint(705,330), 1); Circles.push_back(c39);
    Circle c40(CIRCLE_YELLOW, 40, QPoint(705,375), 1); Circles.push_back(c40);
    Circle c41(CIRCLE_BLUE, 41, QPoint(705,420), 1); Circles.push_back(c41);
    Circle c42(CIRCLE_GREEN, 42, QPoint(705,460), 1); Circles.push_back(c42);
    Circle c43(CIRCLE_RED, 43, QPoint(690,510), 1); Circles.push_back(c43);
    Circle c44(CIRCLE_YELLOW, 44, QPoint(640,530), 1); Circles.push_back(c44);
    Circle c45(CIRCLE_BLUE, 45, QPoint(595,530), 1); Circles.push_back(c45);
    Circle c46(CIRCLE_GREEN, 46, QPoint(550,510), 1); Circles.push_back(c46);
    Circle c47(CIRCLE_RED, 47, QPoint(510,540), 1); Circles.push_back(c47);
    Circle c48(CIRCLE_YELLOW, 48, QPoint(530,590), 1); Circles.push_back(c48);
    Circle c49(CIRCLE_BLUE, 49, QPoint(530,635), 1); Circles.push_back(c49);
    Circle c50(CIRCLE_GREEN, 50, QPoint(510,680), 1); Circles.push_back(c50);
    Circle c51(CIRCLE_RED, 51, QPoint(465,695), 1); Circles.push_back(c51);
    Circle c52(CIRCLE_YELLOW, 52, QPoint(420,695), 1); Circles.push_back(c52);

    Circle c53(CIRCLE_RED, 53, QPoint(550,35), 0); CirclesStart.push_back(c53);   //四个起始位置初始化
    Circle c54(CIRCLE_YELLOW, 54, QPoint(722,545), 0); CirclesStart.push_back(c54);
    Circle c55(CIRCLE_BLUE, 55, QPoint(200,716), 0); CirclesStart.push_back(c55);
    Circle c56(CIRCLE_GREEN, 56, QPoint(20,205), 0); CirclesStart.push_back(c56);
}

void MainWindow::NewGame()
{
    InitBoard();
    PlayTurn = 1;
    round = 1;
    isThrow = false;
    isSelect = false;
    ui->BtnThrow->setEnabled(false);
}

void MainWindow::on_pBtnStart_clicked()     //开始游戏
{
    ui->pBtnStart->setEnabled(false);
    ui->textEdit->insertPlainText("游戏开始！！！\n");
    ui->BtnThrow->setEnabled(true);
    ui->textEdit->setReadOnly(true);
    while (!finish())
        PlayRound();
}

bool MainWindow::finish()
{
    return false;
}

void MainWindow::PlayRound()
{
    ui->lcdNumber_2->display(round);
    ui->label_3->setStyleSheet("color:red;");
    ui->label_3->setText("红方");
    while(!isThrow){
        Sleep(300);
    }
    isThrow = false;
    ui->lcdNumber->display(ThrowNum);
    QString number = "红方投掷的点数：";
    number += QString::number(ThrowNum);
    number += "\n";
    ui->textEdit->insertPlainText(number);
    if (ifFly()){
        while(!isSelect){
            Sleep(300);
        }
    }
    isSelect = false;
    ui->BtnThrow->setEnabled(true);
    PlayTurn = 2;


    ui->label_3->setStyleSheet("color:yellow;");
    ui->label_3->setText("黄方");
    while(!isThrow)
    {
        Sleep(300);
    }
    ui->lcdNumber->display(ThrowNum);
    isThrow = false;
    number = "黄方投掷的点数：";
    number += QString::number(ThrowNum);
    number += "\n";
    ui->textEdit->insertPlainText(number);
    if (ifFly()){
        while(!isSelect){
            Sleep(300);
        }
    }
    isSelect = false;;
    ui->BtnThrow->setEnabled(true);
    PlayTurn = 3;


    ui->label_3->setStyleSheet("color:blue;");
    ui->label_3->setText("蓝方");
    while(!isThrow)
    {
        Sleep(300);
    }
    ui->lcdNumber->display(ThrowNum);
    isThrow = false;
    number = "蓝方投掷的点数：";
    number += QString::number(ThrowNum);
    number += "\n";
    ui->textEdit->insertPlainText(number);
    if (ifFly()){
        while(!isSelect){
            Sleep(300);
        }
    }
    isSelect = false;;
    ui->BtnThrow->setEnabled(true);
    PlayTurn = 4;


    ui->label_3->setStyleSheet("color:green;");
    ui->label_3->setText("绿方");
    while(!isThrow)
    {
        Sleep(300);
    }
    ui->lcdNumber->display(ThrowNum);
    isThrow = false;
    number = "绿方投掷的点数：";
    number += QString::number(ThrowNum);
    number += "\n";
    ui->textEdit->insertPlainText(number);
    if (ifFly()){
        while(!isSelect){
            Sleep(300);
        }
    }
    isSelect = false;;
    ui->BtnThrow->setEnabled(true);
    PlayTurn = 1;

    round++;
}

void MainWindow::on_BtnThrow_clicked()
{
    qsrand(time(NULL));
    int n;
    n = qrand()%6 + 1;
    ThrowNum = n;
    ui->BtnThrow->setEnabled(false);
    isThrow = true;
}

void MainWindow::UpdateLocR()
{
    ui->labRchess_1->move(PlayerRed.getchess(0)->c_pt);
    ui->labRchess_2->move(PlayerRed.getchess(1)->c_pt);
    ui->labRchess_3->move(PlayerRed.getchess(2)->c_pt);
    ui->labRchess_4->move(PlayerRed.getchess(3)->c_pt);
}

void MainWindow::UpdateLocY()
{
    ui->labYchess_1->move(PlayerYellow.getchess(0)->c_pt);
    ui->labYchess_2->move(PlayerYellow.getchess(1)->c_pt);
    ui->labYchess_3->move(PlayerYellow.getchess(2)->c_pt);
    ui->labYchess_4->move(PlayerYellow.getchess(3)->c_pt);
}

void MainWindow::UpdateLocB()
{
    ui->labBchess_1->move(PlayerBlue.getchess(0)->c_pt);
    ui->labBchess_2->move(PlayerBlue.getchess(1)->c_pt);
    ui->labBchess_3->move(PlayerBlue.getchess(2)->c_pt);
    ui->labBchess_4->move(PlayerBlue.getchess(3)->c_pt);
}

void MainWindow::UpdateLocG()
{
    ui->labGchess_1->move(PlayerGreen.getchess(0)->c_pt);
    ui->labGchess_2->move(PlayerGreen.getchess(1)->c_pt);
    ui->labGchess_3->move(PlayerGreen.getchess(2)->c_pt);
    ui->labGchess_4->move(PlayerGreen.getchess(3)->c_pt);
}
bool MainWindow::ifFly()
{
    if (ThrowNum == 6)
        return true;
    switch (PlayTurn) {
    case 1:{
        int count = 0;
        for (int i = 0; i < 4; i++){
            if (PlayerRed.getchess(i)->ifStart == true)
                count++;
        }
        if (count == 0)
            return false;
        else
            return true;
    }
        break;
    case 2:{
        int count = 0;
        for (int i = 0; i < 4; i++){
            if (PlayerRed.getchess(i)->ifStart == true)
                count++;
        }
        if (count == 0)
            return false;
        else
            return true;
    }
        break;
    case 3:{
        int count = 0;
        for (int i = 0; i < 4; i++){
            if (PlayerRed.getchess(i)->ifStart == true)
                count++;
        }
        if (count == 0)
            return false;
        else
            return true;
    }
        break;
    case 4:{
        int count = 0;
        for (int i = 0; i < 4; i++){
            if (PlayerRed.getchess(i)->ifStart == true)
                count++;
        }
        if (count == 0)
            return false;
        else
            return true;
    }
        break;
    default:
        break;
    }
}

void MainWindow::Sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::on_overBtn_clicked()
{
    qApp->exit(0);
}
