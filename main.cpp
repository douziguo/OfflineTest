//
// Created by lx on 2026/3/31.
//


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序信息
    app.setApplicationName("OfflineTestModule");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("OfflineTestModule");

    MainWindow window;
    window.show();

    return app.exec();
}