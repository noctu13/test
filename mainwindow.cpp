#include "mainwindow.h"
#include <QCoreApplication>
#include <QLayout>
#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsItem>
#include "genunit.h"
#include "modgraphicscene.h"
#include "playerunit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
//====================Все используемые переменные==================================
    //компоновки
    QVBoxLayout *main_lt, *start_lt, *load_lt, *set_lt;
    //кнопки меню
    QPushButton *btn_start, *btn_load, *btn_settings, *btn_exit;
    //кнопки подменю
    QPushButton *btn_game_back, *btn_load_back, *btn_settings_back;
    //Отрисовка графики
    QGraphicsView *graphView;
//====================Операции с главным окном=====================================
    setWindowTitle("RPG Maker");
    wgt_stk = new QStackedWidget(this);
    setCentralWidget(wgt_stk);
    window = new QWidget(wgt_stk);
    wgt_stk->addWidget(window);
    wgt_stk->setCurrentWidget(window);
//====================Операции с главным меню======================================
    main_lt = new QVBoxLayout(window);
    main_lt->setAlignment(Qt::AlignCenter);
    btn_start = new QPushButton("Начало");
    main_lt->addWidget(btn_start);
    connect(btn_start, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(game);
        //инициализация таймеров
        animationTimer = new QTimer(game);
        connect(animationTimer, &QTimer::timeout, graphScene, &QGraphicsScene::advance);
        animationTimer->start(1000/60);
        genTimer = new QTimer(game);
        connect(genTimer, &QTimer::timeout, [this](){
            graphScene->addItem(new GenUnit(graphScene));
        });
        genTimer->start(1000);
    });
        //альтернативный вариант через слоты
        //connect(btn_start, &QPushButton::clicked, this, &MainWindow::start_btn_click);
    btn_start->setFixedWidth(120);
    btn_load = new QPushButton("Загрузка");
    main_lt->addWidget(btn_load);
    connect(btn_load, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(load);
    });
    btn_settings = new QPushButton("Настройки");
    main_lt->addWidget(btn_settings);
    connect(btn_settings, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(settings);
    });
    btn_exit = new QPushButton("Выход");
    main_lt->addWidget(btn_exit);
    connect(btn_exit, &QPushButton::clicked, qApp, &QCoreApplication::quit);
//====================Операции с кнопками подменю==================================
    //кнопка назад из центрального виджета
    btn_game_back = new QPushButton("Назад");
    btn_game_back->setFixedWidth(120);
    connect(btn_game_back, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(window);
    });
    //кнопка назад из виджета загрузки
    btn_load_back = new QPushButton("Назад");
    btn_load_back->setFixedWidth(120);
    connect(btn_load_back, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(window);
    });
    //кнопка назад из виджета настройки
    btn_settings_back = new QPushButton("Назад");
    btn_settings_back->setFixedWidth(120);
    connect(btn_settings_back, &QPushButton::clicked, [this](){
        wgt_stk->setCurrentWidget(window);
    });
//====================Создание основных виджетов===================================
    //Наполнение центрального виджета
    game = new QWidget();
    wgt_stk->addWidget(game);
        //представление и сцена отрисовки графических примитивов
    graphScene = new ModGraphicScene(game);//800 600 ga
    graphScene->addRect(graphScene->sceneRect());
    graphView = new QGraphicsView(graphScene, game);
    playerUnit = new PlayerUnit(graphScene);
    graphScene->setPlayer(playerUnit);
    graphScene->addItem(playerUnit);

    start_lt = new QVBoxLayout(game);
    start_lt->setAlignment(Qt::AlignCenter);
    start_lt->addWidget(graphView);
    start_lt->addWidget(btn_game_back);
    //Наполнение виджета загрузки
    load = new QWidget();
    wgt_stk->addWidget(load);
    load_lt = new QVBoxLayout(load);
    load_lt->setAlignment(Qt::AlignCenter);
    load_lt->addWidget(btn_load_back);
    //Наполнение виджета настройки
    settings = new QWidget(wgt_stk);
    wgt_stk->addWidget(settings);
    set_lt = new QVBoxLayout(settings);
    set_lt->setAlignment(Qt::AlignCenter);
    set_lt->addWidget(btn_settings_back);
}
