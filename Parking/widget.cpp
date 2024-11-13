#include "widget.h"
#include "ui_widget.h"
#include "warningid.h"
#include "warningnocar.h"
#include "warningwaitnum.h"
#include "warninginput.h"
#include "warningsamecar.h"

#include <QLabel>
#include <QPropertyAnimation>
#include<vector>
#include<queue>
#include<iostream>
#include<sstream>
#include<QTimer>
#include<random>

#define PRICEPERSECOND 20
#define MINUTEPERHOUR 60
#define SECONDPERMINUTE 60

using namespace std;

vector<int> emptyPosition;
queue<Car*> waitCars;
Car** parkCars2;
vector<QLabel*> parkLabels;
QLabel** waitLabels2;
int parkNum;
int waitNum;
int shouldWidth;
int shouldLength;

void initPosition(int parkNum){
    for(int i=0;i<parkNum;i++){
        emptyPosition.push_back(1);
    }
}

void initParkCars2(int parkNum){
    parkCars2=new Car*[parkNum];
    for(int i=0;i<parkNum;i++){
        parkCars2[i]=nullptr;
    }
}

void initWaitLabels(int waitNum){
    waitLabels2=new QLabel*[waitNum];
    for(int i=0;i<waitNum;i++){
        waitLabels2[i]=nullptr;
    }
}

Car::Car(std::string ID){
    this->ID=ID;
}

void Car::setPos(int pos){
    this->pos=pos;
}

std::string Car::getID(){
    return this->ID;
}

int Car::getPos(){
    return this->pos;
}

int leftPosition(int parkNum){
    int ret=0;
    for(int i=0;i<parkNum;i++){
        if(emptyPosition.at(i)==1){
            ret++;
        }
    }
    return ret;
}

std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> result;
    std::istringstream stream(str);
    std::string word;
    while (stream >> word) {
        result.push_back(word);
    }
    return result;
}

std::vector<std::string> split2(const std::string& str) {
    std::vector<std::string> result;
    std::string token;
    std::istringstream stream(str);
    while (std::getline(stream, token, ':')) {
        result.push_back(token);
    }

    return result;
}

int timeDeal(std::string startTimeStr,std::string endTimeStr){
    vector<std::string> startTime=split(startTimeStr);
    vector<std::string> endTime=split(endTimeStr);
    string startHMS=startTime.at(3);
    string endHMS=endTime.at(3);
    vector<std::string> startHMSs=split2(startHMS);
    vector<std::string> endHMSs=split2(endHMS);
    int startHour=std::stoi(startHMSs.at(0));
    int startMinute=std::stoi(startHMSs.at(1));
    int startSecond=std::stoi(startHMSs.at(2));
    int endHour=std::stoi(endHMSs.at(0));
    int endMinute=std::stoi(endHMSs.at(1));
    int endSecond=std::stoi(endHMSs.at(2));
    int duration=(endHour-startHour)*MINUTEPERHOUR+(endMinute-startMinute)*SECONDPERMINUTE+(endSecond-startSecond)*1;

    return duration;
}

int priceDeal(int duration){
    return duration*PRICEPERSECOND;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
    setWindowTitle("Parking System");
    ui->setupUi(this);
    this->setFixedSize(1302, 704);
    timer=new QTimer;
    value=0;
    ui->label_15->setMinimumHeight(41);
    QObject::connect(timer, &QTimer::timeout, [&]() {
        value += 1;
        ui->lcdNumber->display(value/60);
        ui->lcdNumber_2->display(value%60);
    });
    timer->start(1000);
}

Widget::~Widget() {
    delete ui;
}

void Widget::onMoveClicked(){
    QPropertyAnimation *animation = new QPropertyAnimation(car, "pos");
    animation->setDuration(1000);
    animation->setStartValue(car->pos());
    animation->setEndValue(QPoint(200, 200));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start();
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void Widget::on_changeButton_clicked()
{
    labels.clear();
    QLabel *clearLabel=new QLabel("",this);
    clearLabel->setGeometry(0,60,800,400);
    clearLabel->setStyleSheet("background-color: lightgray; border: 0px solid black; padding: 1px;");
    clearLabel->show();
    string parkNumRaw=ui->parkNum->toPlainText().toStdString();
    string waitNumRaw=ui->waitNum->toPlainText().toStdString();
    if(parkNumRaw==""||waitNumRaw==""){
        warningInput* warning=new warningInput();
        warning->show();
        return;
    }
    parkNum=std::stoi(parkNumRaw);
    waitNum=std::stoi(waitNumRaw);

    int parkXNum=parkNum/5;
    if(parkNum%5!=0){
        parkXNum+=1;
    }
    QString realNum=QString::fromStdString(std::to_string(parkXNum*5));
    ui->parkNum->setPlainText(realNum);
    parkNum=parkXNum*5;
    int parkYNum=5;
    shouldLength=this->PARKLENGTH/parkXNum;
    shouldWidth=this->PARKWIDTH/parkYNum;

    /*第i个停车位的位置应该是
     *i=i/5,j=i%5,park[i][j]=i*shouldLength,30+j*shouldWidth,shouldLength,shouldWidth
    */
    for(int i=0;i<parkXNum;i++){
        for(int j=0;j<parkYNum;j++){
            labels.push_back(new QLabel("",this));
            QLabel *label=labels.at(i*parkYNum+j);
            label->setGeometry(i*shouldLength,60+j*shouldWidth,shouldLength,shouldWidth);
            label->setStyleSheet("border: 1px solid black; padding: 3px;");
            label->show();

            /*About Query Button*/
            int index=i*parkYNum+j;
            string rawIndex="查询:"+to_string(index);
            QPushButton* curButton = new QPushButton(QString::fromStdString(rawIndex), this);

            string rawIndex2="出车:"+to_string(index);
            QPushButton* curButton2 = new QPushButton(QString::fromStdString(rawIndex2), this);

            if (curButton) {
                buttons.push_back(curButton);
            } else {
                cout << "curButton is nullptr" << endl;
            }

            if (curButton2) {
                buttons2.push_back(curButton2);
            } else {
                cout << "curButton2 is nullptr" << endl;
            }
            buttons2.at(i*parkYNum+j)->setGeometry(i*shouldLength,90+j*shouldWidth,70,30);
            buttons2.at(i*parkYNum+j)->show();

            buttons.at(i*parkYNum+j)->setGeometry(i*shouldLength,60+j*shouldWidth,70,30);
            buttons.at(i*parkYNum+j)->show();
        }
    }
    for(unsigned long long i=0;i<buttons.size();i++){
        QPushButton* curButton=buttons.at(i);
        QObject::connect(curButton, &QPushButton::clicked,this, [curButton, this]() {
            string sourceString=splitString(curButton->text().toStdString(),':')[1];

            int sourcePos=std::stoi(sourceString);

            int x=sourcePos%5;
            int y=sourcePos/5;
            int index=sourcePos;
            if(parkCars2[index]==nullptr){
                WarningNoCar* warning=new WarningNoCar();
                warning->show();
                return;
            }

            Car* car=parkCars2[index];

            ui->queryEdit->setText(QString::fromStdString(car->getID()));

            string posOut="第"+to_string(x+1)+"行，第"+to_string(y+1)+"列";
            ui->posEdit->setText(QString::fromStdString(posOut));
            std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            car->setEndTime(std::ctime(&now_c));
            int outputInteger=timeDeal(car->getStartTime(),car->getEndTime());
            ui->timeEdit->setText(QString::fromStdString("已停"+std::to_string(outputInteger)+"秒"));
        });
    }

    for(unsigned long long i=0;i<buttons2.size();i++){
        QPushButton* curButton=buttons2.at(i);
        QObject::connect(curButton, &QPushButton::clicked,this, [curButton, this]() {


            //Query all data of this car
            string sourceString=splitString(curButton->text().toStdString(),':')[1];

            int sourcePos=std::stoi(sourceString);

            int x=sourcePos%5;
            int y=sourcePos/5;
            int index=sourcePos;
            if(parkCars2[index]==nullptr){
                WarningNoCar* warning=new WarningNoCar();
                warning->show();
                return;
            }
            Car* car=parkCars2[index];
            ui->queryEdit->setText(QString::fromStdString(car->getID()));
            string posOut="第"+to_string(x+1)+"行，第"+to_string(y+1)+"列";
            ui->posEdit->setText(QString::fromStdString(posOut));
            std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            car->setEndTime(std::ctime(&now_c));
            int outputInteger=timeDeal(car->getStartTime(),car->getEndTime());
            ui->timeEdit->setText(QString::fromStdString("已停"+std::to_string(outputInteger)+"秒"));


            /**Out the car*/
            std::string ID=QString::fromStdString(car->getID()).toStdString();
            ui->outEdit->setText(QString::fromStdString(ID));
            if(ID==""){
                WarningID* warning = new WarningID();
                warning->show();
                return;
            }
            int money=0;
            QLabel* curLabel;
            bool find=false;
            for(int i=0;i<parkNum;i++){
                if(parkCars2[i]==nullptr){
                    continue;
                }
                if(ID==parkCars2[i]->getID()){
                    emptyPosition[i]=1;
                    std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                    parkCars2[i]->setEndTime(std::ctime(&now_c));
                    money=priceDeal(timeDeal(parkCars2[i]->getStartTime(),parkCars2[i]->getEndTime()));
                    ui->moneyEdit->setText(QString::fromStdString("需付款"+std::to_string(money)+"元"));
                    parkCars2[i]=nullptr;

                    /*Have car out*/
                    QString originalNumRaw=ui->leftEdit->toPlainText();
                    int originalNum=stoi(originalNumRaw.toStdString());
                    int afterNum=originalNum+1;
                    QString afterString=QString::fromStdString(to_string(afterNum));
                    ui->leftEdit->setText(afterString);
                    find=true;
                    break;
                }
            }
            if(find==false){
                WarningNoCar* warning=new WarningNoCar();
                warning->show();
                return;
            }
            //curLabel = findChild<QLabel*>(QString::fromStdString(ID));
            for (QLabel* label : parkLabels) {
                if (label->objectName() == QString::fromStdString(ID)) {
                    curLabel = label;
                    break;
                }
            }
            if(curLabel!=nullptr){
                curLabel->setPixmap(QPixmap(":/new/prefix1/car.png"));
                QPropertyAnimation *animation = new QPropertyAnimation(curLabel, "pos");
                QPoint curPoint=curLabel->pos();
                int x=curPoint.x();
                animation->setDuration(1000);
                animation->setEndValue(QPoint(x,550));
                animation->setEasingCurve(QEasingCurve::InOutQuad);

                connect(animation, &QPropertyAnimation::finished, this, [this,curLabel](){
                    QPropertyAnimation *animation2 = new QPropertyAnimation(curLabel, "pos");
                    animation2->setDuration(1000);
                    animation2->setEndValue(QPoint(1500,550));
                    animation2->setEasingCurve(QEasingCurve::InOutQuad);

                    connect(animation2,&QPropertyAnimation::finished,[this](){
                        /*Waiting car parking*/
                        if(waitCars.size()!=0){

                            string ID2=waitCars.front()->getID();
                            QLabel* curLabel = nullptr;
                            for (QLabel* label : parkLabels) {
                                if (label->objectName() == QString::fromStdString(ID2)) {
                                    curLabel = label;
                                    break;
                                }
                            }

                            for (int i=0;i<waitNum;i++) {
                                if(waitLabels2[i]==nullptr){
                                    continue;
                                }
                                QLabel* label=waitLabels2[i];
                                if (label->objectName() == QString::fromStdString(ID2)) {
                                    waitLabels2[i]=nullptr;
                                    break;
                                }
                            }

                            for(unsigned long long i=0;i<emptyPosition.size();i++){
                                if(emptyPosition.at(i)==1){
                                    int pos=i;

                                    waitCars.front()->setPos(pos);
                                    std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                                    waitCars.front()->setStartTime(std::ctime(&now_c));
                                    parkCars2[i]=(waitCars.front());

                                    emptyPosition.at(i)=0;
                                    QPropertyAnimation *animation = new QPropertyAnimation(curLabel, "pos");
                                    animation->setDuration(1000);

                                    animation->setEndValue(QPoint((pos/5)*shouldLength+65,60+(pos%5)*shouldWidth));
                                    animation->setEasingCurve(QEasingCurve::InOutQuad);

                                    connect(animation, &QPropertyAnimation::finished, this, [this,curLabel]() {
                                        QImage* img=new QImage();
                                        img->load(":/new/prefix1/car.png");
                                        *img=img->scaled(shouldLength-65,shouldWidth,Qt::IgnoreAspectRatio);
                                        curLabel->setMinimumSize(shouldLength-65, shouldWidth);
                                        curLabel->setMaximumSize(shouldLength-65, shouldWidth);
                                        curLabel->setPixmap(QPixmap::fromImage(*img));
                                    });

                                    animation->start();

                                    QString originalNumRaw=ui->leftEdit->toPlainText();
                                    int originalNum=stoi(originalNumRaw.toStdString());
                                    int afterNum=originalNum-1;
                                    QString afterString=QString::fromStdString(to_string(afterNum));
                                    ui->leftEdit->setText(afterString);

                                }
                            }
                            waitCars.pop();
                        }
                    });
                    animation2->start();
                    parkLabels.erase(std::remove(parkLabels.begin(), parkLabels.end(), curLabel), parkLabels.end());
                });
                animation->start();
            }


        });
    }

    initPosition(parkNum);
    initParkCars2(parkNum);
    initWaitLabels(waitNum);
    ui->leftEdit->setText(QString::fromStdString(std::to_string(leftPosition(parkNum))));
}

int couldPark(){
    for(unsigned long long i=0;i<emptyPosition.size();i++){
        if(emptyPosition.at(i)==1){
            return i;
        }
    }
    return -1;
}

void Widget::on_inButton_clicked()
{
    std::string ID=ui->inEdit->text().toStdString();
    if(ID==""){
        WarningID* warning = new WarningID();
        warning->show();
        return;
    }
    if(waitCars.size()==(unsigned long long)waitNum){
        WarningWaitNum* warning=new WarningWaitNum();
        warning->show();
        return;
    }
    /**
     * @brief find
     */
    for(int i=0;i<parkNum;i++){
        if(parkCars2[i]==nullptr){
            continue;
        }
        Car* car = parkCars2[i];
        if(car->getID()==ID){
            WarningSameCar* warning = new WarningSameCar();
            warning->show();
            return;
        }
    }

    ui->inEdit->setText("");
    waitCars.push(new Car(ID));
    QLabel* newLabel=new QLabel(QString::fromStdString(ID),this);
    newLabel->setText(QString::fromStdString(ID));
    newLabel->setObjectName(QString::fromStdString(ID));
    parkLabels.push_back(newLabel);

    newLabel->setGeometry((waitCars.size()-1)*100-100,600,100,100);
    newLabel->setPixmap(QPixmap(":/new/prefix1/car.png"));
    newLabel->show();

    QPropertyAnimation *animation = new QPropertyAnimation(newLabel, "pos");
    animation->setDuration(1000);
    animation->setStartValue(QPoint(-100,600));
    int saveI;
    for(int i=0;i<waitNum;i++){
        if(waitLabels2[i]==nullptr){
            waitLabels2[i]=newLabel;
            saveI=i;
            break;
        }
    }
    /*animation->setEndValue(QPoint((waitCars.size()-1)*100,600));*/

    animation->setEndValue(QPoint(saveI*100,600));
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    connect(animation, &QPropertyAnimation::finished, this, [this,newLabel,saveI]() {
        int parkPos = couldPark();
        if (parkPos == -1) {
            return;
        }
        /*Have new car parking*/
        waitLabels2[saveI]=nullptr;
        QString originalNumRaw=ui->leftEdit->toPlainText();
        int originalNum=stoi(originalNumRaw.toStdString());
        int afterNum=originalNum-1;
        QString afterString=QString::fromStdString(to_string(afterNum));
        ui->leftEdit->setText(afterString);

        waitCars.front()->setPos(parkPos);

        std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        waitCars.front()->setStartTime(std::ctime(&now_c));

        parkCars2[parkPos]=waitCars.front();
        waitCars.pop();
        emptyPosition.at(parkPos)=0;

        int i = parkPos / 5, j = parkPos % 5;
        QPropertyAnimation *animation2 = new QPropertyAnimation(newLabel, "pos");
        animation2->setDuration(1000);
        animation2->setEndValue(QPoint(i * shouldLength+70, 60 + j * shouldWidth));
        animation2->setEasingCurve(QEasingCurve::InOutQuad);

        connect(animation2, &QPropertyAnimation::finished, this, [this,newLabel]() {
            QImage* img=new QImage();
            img->load(":/new/prefix1/car.png");
            *img=img->scaled(shouldLength-65,shouldWidth,Qt::IgnoreAspectRatio);
            newLabel->setMinimumSize(shouldLength-65, shouldWidth);
            newLabel->setMaximumSize(shouldLength-65, shouldWidth);
            newLabel->setPixmap(QPixmap::fromImage(*img));
        });

        animation2->start();

    });
    animation->start();
}


void Widget::on_outButton_clicked()
{
    std::string ID=ui->outEdit->text().toStdString();

    if(ID==""){
        WarningID* warning = new WarningID();
        warning->show();
        return;
    }
    ui->outEdit->setText("");
    int money=0;
    QLabel* curLabel;
    bool find=false;
    for(int i=0;i<parkNum;i++){
        if(parkCars2[i]==nullptr){
            continue;
        }
        if(ID==parkCars2[i]->getID()){
            emptyPosition[i]=1;
            std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            parkCars2[i]->setEndTime(std::ctime(&now_c));
            money=priceDeal(timeDeal(parkCars2[i]->getStartTime(),parkCars2[i]->getEndTime()));
            ui->moneyEdit->setText(QString::fromStdString("需付款"+std::to_string(money)+"元"));
            parkCars2[i]=nullptr;

            /*Have car out*/
            QString originalNumRaw=ui->leftEdit->toPlainText();
            int originalNum=stoi(originalNumRaw.toStdString());
            int afterNum=originalNum+1;
            QString afterString=QString::fromStdString(to_string(afterNum));
            ui->leftEdit->setText(afterString);
            find=true;
            break;
        }
    }
    if(find==false){
        WarningNoCar* warning=new WarningNoCar();
        warning->show();
        return;
    }
    //curLabel = findChild<QLabel*>(QString::fromStdString(ID));
    for (QLabel* label : parkLabels) {
        if (label->objectName() == QString::fromStdString(ID)) {
            curLabel = label;
            break;
        }
    }
    if(curLabel!=nullptr){
        curLabel->setPixmap(QPixmap(":/new/prefix1/car.png"));
        QPropertyAnimation *animation = new QPropertyAnimation(curLabel, "pos");
        QPoint curPoint=curLabel->pos();
        int x=curPoint.x();
        animation->setDuration(1000);
        animation->setEndValue(QPoint(x,550));
        animation->setEasingCurve(QEasingCurve::InOutQuad);

        connect(animation, &QPropertyAnimation::finished, this, [this,curLabel](){
            QPropertyAnimation *animation2 = new QPropertyAnimation(curLabel, "pos");
            animation2->setDuration(1000);
            animation2->setEndValue(QPoint(1500,550));
            animation2->setEasingCurve(QEasingCurve::InOutQuad);

            /**
             * Why can't captured "this" here?
             * What's problem with it?
             * what's explicit method which could use connect method/function?
             * */

            connect(animation2,&QPropertyAnimation::finished,[this](){
                /*Waiting car parking*/
                if(waitCars.size()!=0){

                    string ID2=waitCars.front()->getID();
                    QLabel* curLabel = nullptr;
                    for (QLabel* label : parkLabels) {
                        if (label->objectName() == QString::fromStdString(ID2)) {
                            curLabel = label;
                            break;
                        }
                    }

                    for (int i=0;i<waitNum;i++) {
                        if(waitLabels2[i]==nullptr){
                            continue;
                        }
                        QLabel* label=waitLabels2[i];
                        if (label->objectName() == QString::fromStdString(ID2)) {
                            waitLabels2[i]=nullptr;
                            break;
                        }
                    }

                    for(unsigned long long i=0;i<emptyPosition.size();i++){
                        if(emptyPosition.at(i)==1){
                            int pos=i;

                            waitCars.front()->setPos(pos);
                            std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                            waitCars.front()->setStartTime(std::ctime(&now_c));
                            parkCars2[i]=(waitCars.front());

                            emptyPosition.at(i)=0;
                            QPropertyAnimation *animation = new QPropertyAnimation(curLabel, "pos");
                            animation->setDuration(1000);

                            animation->setEndValue(QPoint((pos/5)*shouldLength+65,60+(pos%5)*shouldWidth));
                            animation->setEasingCurve(QEasingCurve::InOutQuad);

                            connect(animation, &QPropertyAnimation::finished, this, [this,curLabel]() {
                                QImage* img=new QImage();
                                img->load(":/new/prefix1/car.png");
                                *img=img->scaled(shouldLength-65,shouldWidth,Qt::IgnoreAspectRatio);
                                curLabel->setMinimumSize(shouldLength-65, shouldWidth);
                                curLabel->setMaximumSize(shouldLength-65, shouldWidth);
                                curLabel->setPixmap(QPixmap::fromImage(*img));

                                /*
                                 *      QImage* img=new QImage();
                                        img->load(":/new/prefix1/car.png");
                                        *img=img->scaled(shouldLength-65,shouldWidth,Qt::IgnoreAspectRatio);
                                        curLabel->setMinimumSize(shouldLength-65, shouldWidth);
                                        curLabel->setMaximumSize(shouldLength-65, shouldWidth);
                                        curLabel->setPixmap(QPixmap::fromImage(*img));
                                */
                            });

                            animation->start();

                            QString originalNumRaw=ui->leftEdit->toPlainText();
                            int originalNum=stoi(originalNumRaw.toStdString());
                            int afterNum=originalNum-1;
                            QString afterString=QString::fromStdString(to_string(afterNum));
                            ui->leftEdit->setText(afterString);

                        }
                    }
                    waitCars.pop();
                }
            });
            animation2->start();
            parkLabels.erase(std::remove(parkLabels.begin(), parkLabels.end(), curLabel), parkLabels.end());
        });
        animation->start();
    }
}

void Widget::query2(string pos){
    int x=pos[1]-'0';
    int y=pos[3]-'0';
    int index=(y-1)*5+(x-1);
    if(parkCars2[index]==nullptr){
        WarningNoCar* warning=new WarningNoCar();
        warning->show();
        return;
    }
    Car* car=parkCars2[index];
    ui->queryEdit->setText(QString::fromStdString(car->getID()));
    string posOut="第"+to_string(x)+"行，第"+to_string(y)+"列";
    ui->posEdit->setText(QString::fromStdString(posOut));
    std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    car->setEndTime(std::ctime(&now_c));
    int outputInteger=timeDeal(car->getStartTime(),car->getEndTime());
    ui->timeEdit->setText(QString::fromStdString("已停"+std::to_string(outputInteger)+"秒"));
    return;
}

void Widget::on_queryButton_clicked()
{
    string ID=ui->queryEdit->text().toStdString();
    string posIn=ui->posEdit->toPlainText().toStdString();

    ui->posEdit->setText("");
    ui->timeEdit->setText("");
    ui->queryEdit->setText("");
    if(ID==""&&posIn==""){
        WarningID* warning = new WarningID();
        warning->show();
        return;
    }
    if(ID==""){
        query2(posIn);
        //按照位置查询
        return;
    }else{
        //按照ID查询
    }
    ui->queryEdit->setText(QString::fromStdString(ID));
    bool find=false;
    /*foreach (Car* car, parkCars) {*/
    for(int i=0;i<parkNum;i++){
        if(parkCars2[i]==nullptr){
            continue;
        }
        Car* car = parkCars2[i];
        if(car->getID()==ID){
            int pos=car->getPos();
            int line,queue;
            line=pos%5;
            queue=pos/5;
            string result="停在第"+std::to_string(line+1)+"行，第"+std::to_string(queue+1)+"列";
            ui->posEdit->setText(QString::fromStdString(result));
            std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            car->setEndTime(std::ctime(&now_c));
            int outputInteger=timeDeal(car->getStartTime(),car->getEndTime());
            ui->timeEdit->setText(QString::fromStdString("已停"+std::to_string(outputInteger)+"秒"));
            find=true;
            break;
        }
    }
    if(find==false){
        WarningNoCar* warning=new WarningNoCar();
        warning->show();
        return;
    }
}


void Widget::on_pushButton_clicked()
{
    ui->queryEdit->setText("");
    ui->posEdit->setText("");
    ui->timeEdit->setText("");
}

void Widget::on_autoIn_clicked()
{
    vector<string> district={"京", "津", "冀", "晋", "蒙", "辽", "吉", "黑", "沪", "苏", "浙", "皖", "闽", "湘", "粤", "桂", "琼", "渝", "川", "贵", "云", "藏", "陕", "甘", "青", "宁","新"};
    string genID;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 53);
    std::uniform_int_distribution<> dis2(0, 65);//26useful
    std::uniform_int_distribution<> dis3(0, 25);
    int firstChar=dis2(gen);
    if(firstChar>26&&firstChar<60){
        firstChar=0;
    }else if(firstChar>=60){
        firstChar=3;
    }
    genID.append(district.at(firstChar));
    char secondChar='A'+dis3(gen);
    string secondString="a";
    secondString.at(0)=secondChar;
    genID.append(secondString);
    genID.append("•");
    for (int i = 0; i < 6; ++i) {
        int random_number = dis(gen);
        if(random_number<10){
            genID.append(to_string(random_number));
        }else if(random_number<=33){
            string append="a";
            append.at(0)='A'+random_number-10;
            genID.append(append);
        }else if(random_number<=43){
            genID.append(to_string(random_number-34));
        }else{
            genID.append(to_string(random_number-44));
        }
    }
    std::string ID=genID;
    if(ID==""){
        WarningID* warning = new WarningID();
        warning->show();
        return;
    }
    if(waitCars.size()==(unsigned long long)waitNum){
        WarningWaitNum* warning=new WarningWaitNum();
        warning->show();
        return;
    }
    /**
     * @brief find
     */
    for(int i=0;i<parkNum;i++){
        if(parkCars2[i]==nullptr){
            continue;
        }
        Car* car = parkCars2[i];
        if(car->getID()==ID){
            WarningSameCar* warning = new WarningSameCar();
            warning->show();
            return;
        }
    }

    ui->inEdit->setText("");
    waitCars.push(new Car(ID));
    QLabel* newLabel=new QLabel(QString::fromStdString(ID),this);
    newLabel->setText(QString::fromStdString(ID));
    newLabel->setObjectName(QString::fromStdString(ID));
    parkLabels.push_back(newLabel);

    newLabel->setGeometry((waitCars.size()-1)*100-100,600,100,100);
    newLabel->setPixmap(QPixmap(":/new/prefix1/car.png"));
    newLabel->show();

    QPropertyAnimation *animation = new QPropertyAnimation(newLabel, "pos");
    animation->setDuration(1000);
    animation->setStartValue(QPoint(-100,600));
    int saveI;
    for(int i=0;i<waitNum;i++){
        if(waitLabels2[i]==nullptr){
            waitLabels2[i]=newLabel;
            saveI=i;
            break;
        }
    }
    /*animation->setEndValue(QPoint((waitCars.size()-1)*100,600));*/

    animation->setEndValue(QPoint(saveI*100,600));
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    connect(animation, &QPropertyAnimation::finished, this, [this,newLabel,saveI]() {
        int parkPos = couldPark();
        if (parkPos == -1) {
            return;
        }
        /*Have new car parking*/
        waitLabels2[saveI]=nullptr;
        QString originalNumRaw=ui->leftEdit->toPlainText();
        int originalNum=stoi(originalNumRaw.toStdString());
        int afterNum=originalNum-1;
        QString afterString=QString::fromStdString(to_string(afterNum));
        ui->leftEdit->setText(afterString);

        waitCars.front()->setPos(parkPos);

        std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        waitCars.front()->setStartTime(std::ctime(&now_c));

        parkCars2[parkPos]=waitCars.front();
        waitCars.pop();
        emptyPosition.at(parkPos)=0;

        int i = parkPos / 5, j = parkPos % 5;
        QPropertyAnimation *animation2 = new QPropertyAnimation(newLabel, "pos");
        animation2->setDuration(1000);
        animation2->setEndValue(QPoint(i * shouldLength+65, 60 + j * shouldWidth));
        animation2->setEasingCurve(QEasingCurve::InOutQuad);

        connect(animation2, &QPropertyAnimation::finished, this, [this,newLabel]() {
            QImage* img=new QImage();
            img->load(":/new/prefix1/car.png");
            *img=img->scaled(shouldLength-65,shouldWidth,Qt::IgnoreAspectRatio);
            newLabel->setMinimumSize(shouldLength-65, shouldWidth);
            newLabel->setMaximumSize(shouldLength-65, shouldWidth);
            newLabel->setPixmap(QPixmap::fromImage(*img));
        });

        animation2->start();

    });
    animation->start();
}

