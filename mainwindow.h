#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pc_left_clicked();

    void on_pc_right_clicked();

    void on_plus_clicked();

    void on_time_clicked();

    void on_you_left_clicked();

    void on_you_right_clicked();

    void on_a2_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

    void on_a1_clicked();

    void on_zok_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
