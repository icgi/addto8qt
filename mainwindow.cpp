#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QPushButton>
#include<QStack>
#include<cctype>
#include<iostream>
#include<cstdio>
#include<QDesktopServices>
#include<QUrl>

int you[10]={1,1,1,1,1,1,1,1,1,1},pc[10]={1,1,1,1,1,1,1,1,1,1};
int you2[10]={1,1,1,1,1,1,1,1,1,1},pc2[10]={1,1,1,1,1,1,1,1,1,1};
int you3[10]={1,1,1,1,1,1,1,1,1,1},pc3[10]={1,1,1,1,1,1,1,1,1,1};
int yy=0,pp=0,nn=0,rd=1,ww=1;
int pcpan[10]={0,0,0,0,0,0,0,0,0,0,};
int pcpancount=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pc_left_clicked()
{
    ui->pc_choose->setText("左"+QString::number(pc[1]));
    pp=1;
}

void MainWindow::on_pc_right_clicked()
{
    ui->pc_choose->setText("右"+QString::number(pc[2]));
    pp=2;
}

void MainWindow::on_plus_clicked()
{
    ui->add_choose->setText("＋");
    nn=1;
}

void MainWindow::on_time_clicked()
{
    ui->add_choose->setText("×");
    nn=2;
}

void MainWindow::on_you_left_clicked()
{
    ui->you_choose->setText("左"+QString::number(you[1]));
    yy=1;
}

void MainWindow::on_you_right_clicked()
{
    ui->you_choose->setText("右"+QString::number(you[2]));
    yy=2;
}

void MainWindow::on_a2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.addto8.com"));
}

void MainWindow::on_a3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.addto8.com/docs/"));
}

void MainWindow::on_a4_clicked()
{
    QMessageBox::about(this, "关于 “抢8 AddTo8”", "《抢8 AddTo8》是一款非常简单好玩即时战略游戏。\n本游戏由《抢8》爱好者制作，免费供各玩家对战，支持人机对战。\n\n版本：v1.1(算法版) \n\n系统环境：windows/linux/android(ARM)\n发布日期：2022年2月11日\n\n官方网站：https://www.addto8.com\n联系邮箱：addto8@addto8.com\n游戏制作：clappinggame\n运营维护：clappinggame\n\nCopyright © 2021-2022 AddTo8 . All rights reserved.");

}

void MainWindow::on_a1_clicked()
{
    QMessageBox::information(this, "提示", "游戏重新开始");
    yy=0;pp=0;nn=0;
    you[1]=1;
    pc[1]=1;
    you[2]=1;
    pc[2]=1;
    ui->you_left->setText(QString::number(you[1]));
    ui->you_right->setText(QString::number(you[2]));
    ui->pc_left->setText(QString::number(pc[1]));
    ui->pc_right->setText(QString::number(pc[2]));
    ui->you_choose->setText("请选择");
    ui->add_choose->setText("请选择");
    ui->pc_choose->setText("请选择");
    rd=1;
    ui->round->setText("回合" + QString::number(rd));
}

int copy(int cp)
{
    if(cp==1)
    {
        you2[1]=you[1];
        you2[2]=you[2];
        pc2[1]=pc[1];
        pc2[2]=pc[2];
    }
    else
    {
        you3[1]=you2[1];
        you3[2]=you2[2];
        pc3[1]=pc2[1];
        pc3[2]=pc2[2];
    }
    return 0;
}
int do1(int d1)
{
    if(d1==1)pc[1]=pc[1]+you[1];
    else if(d1==2)pc[1]=pc[1]+you[2];
    else if(d1==3)pc[2]=pc[2]+you[1];
    else if(d1==4)pc[2]=pc[2]+you[2];
    else if(d1==5)pc[1]=pc[1]*you[1];
    else if(d1==6)pc[1]=pc[1]*you[2];
    else if(d1==7)pc[2]=pc[2]*you[1];
    else     pc[2]=pc[2]*you[2];
    if(pc[1]>9) pc[1]=pc[1]%10;
    if(pc[1]==0) pc[1]=1;
    if(pc[2]>9) pc[2]=pc[2]%10;
    if(pc[2]==0) pc[2]=1;
    return 0;
}
int do2(int d2)
{
    if(d2==1)pc2[1]=pc2[1]+you2[1];
    else if(d2==2)pc2[1]=pc2[1]+you2[2];
    else if(d2==3)pc2[2]=pc2[2]+you2[1];
    else if(d2==4)pc2[2]=pc2[2]+you2[2];
    else if(d2==5)pc2[1]=pc2[1]*you2[1];
    else if(d2==6)pc2[1]=pc2[1]*you2[2];
    else if(d2==7)pc2[2]=pc2[2]*you2[1];
    else     pc2[2]=pc2[2]*you2[2];
    if(pc2[1]>9) pc2[1]=pc2[1]%10;
    if(pc2[1]==0) pc2[1]=1;
    if(pc2[2]>9) pc2[2]=pc2[2]%10;
    if(pc2[2]==0) pc2[2]=1;
    return 0;
}
int do3(int d3)
{
    if(d3==1)you3[1]=you3[1]+pc3[1];
    else if(d3==2)you3[1]=you3[1]+pc3[2];
    else if(d3==3)you3[2]=you3[2]+pc3[1];
    else if(d3==4)you3[2]=you3[2]+pc3[2];
    else if(d3==5)you3[1]=you3[1]*pc3[1];
    else if(d3==6)you3[1]=you3[1]*pc3[2];
    else if(d3==7)you3[2]=you3[2]*pc3[1];
    else     you3[2]=you3[2]*pc3[2];
    if(you3[1]>9) you3[1]=you3[1]%10;
    if(you3[1]==0) you3[1]=1;
    if(you3[2]>9) you3[2]=you3[2]%10;
    if(you3[2]==0) you3[2]=1;
    return 0;
}


int yanyou()
{
    if(nn==1)
    {
        ww=you[yy]+pc[pp];
        if(ww>9) ww=ww%10;//大于9取个位
        if(ww==0) ww=1;//0取1
    }
    else if(nn==2)
    {
        ww=you[yy]*pc[pp];
        if(ww>9) ww=ww%10;
        if(ww==0) ww=1;
    }

    if(ww==you[yy])return 1;else return 0;
}

int yanpc()
{
    if(pc[1]==pc2[1]&&pc[2]==pc2[2])return 1;else return 0;
}
/*
int trypc(int z)
{
    //验证对面left+
    ww=pc[z]+you[1];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 1;
    //验证对面left*
    ww=pc[z]*you[1];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 2;
    //验证对面right+
    ww=pc[z]+you[2];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 3;
    //验证对面right*
    ww=pc[z]*you[2];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 4;

    return 0;
}

int tryyou(int z)
{
    //验证pc left+
    ww=you[z]+pc[1];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 1;
    //验证pc left*
    ww=you[z]*pc[1];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 1;
    //验证pc right+
    ww=you[z]+pc[2];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 2;
    //验证pc right*
    ww=you[z]*pc[2];
    if(ww>9) ww=ww%10;
    if(ww==0) ww=1;
    if(ww==8) return 2;

    return 0;
}
*/
int clpcp()
{
    pcpan[1]=0;pcpan[2]=0;pcpan[3]=0;pcpan[4]=0;pcpan[5]=0;
    pcpan[6]=0;pcpan[7]=0;pcpan[8]=0;pcpan[9]=0;pcpan[0]=0;
    pcpancount=0;
    return 0;
}
int step=0,panding=0,doit=0;
void MainWindow::on_zok_clicked()
{
    if(yy==0||pp==0||nn==0)
    {
        QMessageBox::information(this, "提示", "请选择完毕后再点击“确定”");
        return;
    }
    else
    {
        if(yanyou()==1)
        {
            QMessageBox::information(this, "提示", "你的数字必须要改变！");
            return;
        }
        rd++;
        ui->round->setText("回合" + QString::number(rd));
        ui->you_choose->setText("请选择");
        ui->add_choose->setText("请选择");
        ui->pc_choose->setText("请选择");
            if(nn==1)
            {
                you[yy]=you[yy]+pc[pp];
                if(you[yy]>9) you[yy]=you[yy]%10;//大于9取个位
                if(you[yy]==0) you[yy]=1;//0取1
            }
            else if(nn==2)
            {
                you[yy]=you[yy]*pc[pp];
                if(you[yy]>9) you[yy]=you[yy]%10;
                if(you[yy]==0) you[yy]=1;
            }

        ui->you_left->setText(QString::number(you[1]));
        ui->you_right->setText(QString::number(you[2]));
        yy=0;pp=0;nn=0;
        if(you[1]==8&&you[2]==8)
        {
            QMessageBox::about(this, "你胜利了！", "你胜利了！\n游戏将自动重新开始。");
            yy=0;pp=0;nn=0;
            you[1]=1;
            pc[1]=1;
            you[2]=1;
            pc[2]=1;
            ui->you_left->setText(QString::number(you[1]));
            ui->you_right->setText(QString::number(you[2]));
            ui->pc_left->setText(QString::number(pc[1]));
            ui->pc_right->setText(QString::number(pc[2]));
            rd=1;
            ui->round->setText("回合" + QString::number(rd));
            return;
        }
        //电脑操作/////////////////////////////////
        //step1:验证下一步是否能赢？
        step=0;
        for(int i=1;i<=8;i++)
        {
            copy(1);
            do2(i);
            if(pc2[1]==8&&pc2[2]==8)
            {
                do1(i);step=1;
                break;
            }
        }
        clpcp();
        //step2:验证下一步是否不输？
        if(step==0)
        {
            for(int i=1;i<=8;i++)
            {
                copy(1);
                do2(i);
                panding=0;
                if(yanpc()==1)panding=1;
                for(int m=1;m<=8;m++)
                {
                    copy(2);
                    do3(m);
                    if(you3[1]==8&&you3[2]==8)
                    {
                        panding=1;
                    }
                }
                if(panding==0)
                {
                    pcpancount++;pcpan[pcpancount]=i;
                }

            }
            if(pcpancount>0)
            {
                doit=rand()%pcpancount+1;
                do1(pcpan[doit]);step=1;
            }
            //ui->label_6->setText(QString::number(pcpan[1]) + "-" + QString::number(pcpan[2]) + "-" + QString::number(pcpan[3]) + "-" + QString::number(pcpan[4]) + "-" + QString::number(pcpan[5]) + "-" + QString::number(pcpan[6]) + "-" + QString::number(pcpan[7]) + "-" + QString::number(pcpan[8]) + ":" + QString::number(doit) + "->" + QString::number(pcpan[doit]));
        }

        //step3:输了输了

        if(step==0)
        {
            for(int i=1;i<=8;i++)
            {
                copy(1);
                do2(i);
                panding=0;
                if(yanpc()==1)panding=1;
                if(panding==0)
                {
                    do1(i);step=1;
                    break;
                }
            }
        }




/*
        if(you[1]!=8&&you[2]!=8)
        {
            if(pc[1]!=8&&pc[2]!=8)
            {
                yy=1+rand()%2;pp=1+rand()%2;
                nn=1+rand()%2;
                while(yanpc())
                {
                    yy=1+rand()%2;pp=1+rand()%2;
                    nn=1+rand()%2;
                }
            }
            else if(pc[1]==8&&pc[2]!=8)
            {
                if(trypc(2)==1)
                {
                    pp=2;yy=1;nn=1;
                }
                else if(trypc(2)==2)
                {
                    pp=2;yy=1;nn=2;
                }
                else if(trypc(2)==3)
                {
                    pp=2;yy=2;nn=1;
                }
                else if(trypc(2)==4)
                {
                    pp=2;yy=2;nn=2;
                }
                else
                {//此处下次有待改进
                    yy=1+rand()%2;pp=1+rand()%2;
                    nn=1+rand()%2;
                }
                while(yanpc())
                {
                    yy=1+rand()%2;pp=1+rand()%2;
                    nn=1+rand()%2;
                }
            }
            else if(pc[1]!=8&&pc[2]==8)
            {
                if(trypc(1)==1)
                {
                    pp=1;yy=1;nn=1;
                }
                else if(trypc(1)==2)
                {
                    pp=1;yy=1;nn=2;
                }
                else if(trypc(1)==3)
                {
                    pp=1;yy=2;nn=1;
                }
                else if(trypc(1)==4)
                {
                    pp=1;yy=2;nn=2;
                }
                else
                {//此处下次有待改进
                    yy=1+rand()%2;pp=1+rand()%2;
                    nn=1+rand()%2;
                }
                while(yanpc())
                {
                    yy=1+rand()%2;pp=1+rand()%2;
                    nn=1+rand()%2;
                }

            }

        }
        else if(you[1]==8&&you[2]!=8)
        {
                    if(pc[1]==8&&pc[2]!=8)
                        {
                            if(trypc(2)==1)
                            {
                                pp=2;yy=1;nn=1;
                            }
                            else if(trypc(2)==2)
                            {
                                pp=2;yy=1;nn=2;
                            }
                            else if(trypc(2)==3)
                            {
                                pp=2;yy=2;nn=1;
                            }
                            else if(trypc(2)==4)
                            {
                                pp=2;yy=2;nn=2;
                            }
                        }
                        else if(pc[1]!=8&&pc[2]==8)
                        {
                            if(trypc(1)==1)
                            {
                                pp=1;yy=1;nn=1;
                            }
                            else if(trypc(1)==2)
                            {
                                pp=1;yy=1;nn=2;
                            }
                            else if(trypc(1)==3)
                            {
                                pp=1;yy=2;nn=1;
                            }
                            else if(trypc(1)==4)
                            {
                                pp=1;yy=2;nn=2;
                            }

                        }

            else if(tryyou(2)==1)
            {
                pp=1;yy=1+rand()%2;nn=1+rand()%2;
            }
            else if(tryyou(2)==2)
            {
                pp=2;yy=1+rand()%2;nn=1+rand()%2;
            }
            else
            {//此处下次有待改进
                yy=1+rand()%2;pp=1+rand()%2;
                nn=1+rand()%2;
            }
            while(yanpc())
            {
                yy=1+rand()%2;pp=1+rand()%2;
                nn=1+rand()%2;
            }
        }
        else if(you[1]!=8&&you[2]==8)
        {
            if(pc[1]==8&&pc[2]!=8)
                {
                    if(trypc(2)==1)
                    {
                        pp=2;yy=1;nn=1;
                    }
                    else if(trypc(2)==2)
                    {
                        pp=2;yy=1;nn=2;
                    }
                    else if(trypc(2)==3)
                    {
                        pp=2;yy=2;nn=1;
                    }
                    else if(trypc(2)==4)
                    {
                        pp=2;yy=2;nn=2;
                    }
                }
                else if(pc[1]!=8&&pc[2]==8)
                {
                    if(trypc(1)==1)
                    {
                        pp=1;yy=1;nn=1;
                    }
                    else if(trypc(1)==2)
                    {
                        pp=1;yy=1;nn=2;
                    }
                    else if(trypc(1)==3)
                    {
                        pp=1;yy=2;nn=1;
                    }
                    else if(trypc(1)==4)
                    {
                        pp=1;yy=2;nn=2;
                    }

                }
            else if(tryyou(1)==1)
            {
                pp=1;yy=1+rand()%2;nn=1+rand()%2;
            }
            else if(tryyou(1)==2)
            {
                pp=2;yy=1+rand()%2;nn=1+rand()%2;
            }
            else
            {//此处下次有待改进
                yy=1+rand()%2;pp=1+rand()%2;
                nn=1+rand()%2;
            }
            while(yanpc())
            {
                yy=1+rand()%2;pp=1+rand()%2;
                nn=1+rand()%2;
            }
        }

*/
        //算法结束/////////////////////////////////
        /*
        if(nn==1)
        {
            pc[yy]=pc[yy]+you[pp];
            if(pc[yy]>9) pc[yy]=pc[yy]%10;//大于9取个位
            if(pc[yy]==0) pc[yy]=1;//0取1
        }
        else if(nn==2)
        {
            pc[yy]=pc[yy]*you[pp];
            if(pc[yy]>9) pc[yy]=pc[yy]%10;
            if(pc[yy]==0) pc[yy]=1;
        }
        */
        yy=0;pp=0;nn=0;
        ui->pc_left->setText(QString::number(pc[1]));
        ui->pc_right->setText(QString::number(pc[2]));
        if(pc[1]==8&&pc[2]==8)
        {
            QMessageBox::about(this, "你失败了！", "你失败了！\n游戏将自动重新开始。");
            yy=0;pp=0;nn=0;
            you[1]=1;
            pc[1]=1;
            you[2]=1;
            pc[2]=1;
            ui->you_left->setText(QString::number(you[1]));
            ui->you_right->setText(QString::number(you[2]));
            ui->pc_left->setText(QString::number(pc[1]));
            ui->pc_right->setText(QString::number(pc[2]));
            rd=1;
            ui->round->setText("回合" + QString::number(rd));
            return;
        }
        return;
    }
}
