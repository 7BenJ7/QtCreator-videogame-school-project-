#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->lcdNumber->display(0);

    ui->frame_command->hide();

    newGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame()
{
    game = new Game();
    qDebug() << "new game";

    ui->graphicsView->setScene(game->scene);
    ui->graphicsView->setSceneRect(0,0,game->scene->width(),game->scene->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    game->player->healthbar = ui->progressBar;
    game->player->healthbar->setMaximum(game->player->healthMax);
    game->player->healthbar->setValue(game->player->healthMax);

    game->player->bulletCount = ui->lcdNumber;
    game->player->bulletCount->display(game->player->bulletMax);


    game->player->label = ui->label;

    game->player->frame_command = ui->frame_command;
    game->player->frame_level = ui->frame_level;


}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "button difficult clicked";
    game->start(1000);
    qDebug() << "game start";


    ui->frame_level->hide();
    ui->frame_command->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "button normal clicked";
    game->start(3000);
    qDebug() << "game start";

    ui->frame_level->hide();
    ui->frame_command->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "button easy clicked";
    game->start(5000);
    qDebug() << "game start";


    ui->frame_level->hide();
    ui->frame_command->show();
}

