//
// Created by lx on 2026/4/9.
//

#ifndef OFFLINETESTMODULE_MAINWINDOW_H
#define OFFLINETESTMODULE_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class mainwindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //OFFLINETESTMODULE_MAINWINDOW_H