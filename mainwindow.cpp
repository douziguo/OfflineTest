//
// Created by lx on 2026/4/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved
#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    setWindowTitle("AOI 离线测试平台 v1.0");
    resize(1600, 950);

    // 优先使用Qt资源系统中的图标（打包后也能正常显示）
    if (QFile::exists(":/icons/seewave.ico")) {
        setWindowIcon(QIcon(":/icons/seewave.ico"));
    }
    else {
        // 开发环境fallback：尝试从文件系统加载
        QString iconPath = QCoreApplication::applicationDirPath() + "/seewave.ico";
        if (QFile::exists(iconPath)) {
            setWindowIcon(QIcon(iconPath));
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}