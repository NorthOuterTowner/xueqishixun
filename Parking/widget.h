#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<vector>
#include<queue>
namespace Ui {
class Widget;
}
class ParkPos{
private:
    int x;
    int y;
public:
    static int length;
    static int width;
    //explicit ParkPos(int length,int width);
    void setLength(int);
    void setWidth(int);
};

class Car{
private:
    std::string ID;
    std::string startTime;
    std::string endTime;
    int pos;
    int x;
    int y;
public:
    explicit Car(std::string ID);
    void setPos(int pos);
    int getPos();
    std::string getID();
    void setStartTime(std::string time){
        this->startTime=time;
    }
    std::string getStartTime(){
        return this->startTime;
    }
    void setEndTime(std::string time){
        this->endTime=time;
    }
    std::string getEndTime(){
        return this->endTime;
    }
};

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void query2(std::string pos);
    ~Widget();

private slots:
    void onMoveClicked();

    void on_changeButton_clicked();

    void on_inButton_clicked();

    void on_outButton_clicked();

    void on_queryButton_clicked();

    void on_pushButton_clicked();

    void on_autoIn_clicked();

private:
    int PARKWIDTH=400;
    int PARKLENGTH=800;
    int WAITWIDTH=100;
    int WAITLENGTH=1000;
    std::vector<QLabel*> labels;
    std::vector<QPushButton*> buttons;
    std::vector<QPushButton*> buttons2;
    Ui::Widget *ui;
    QLabel *car;
    int parkNum;
    int waitNum;
    std::vector<ParkPos> parkings;
    QTimer *timer;
    int value;
};
#endif
