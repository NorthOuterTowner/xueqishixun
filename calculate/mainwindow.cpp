/**Thought:
 * All the calculate done in mainwindow.cpp,and main.cpp doing nothing.
 * because all the input and output will be done at the window, no outputs
 * in console.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"
#include "about.h"
#include <stack>
#include<fstream>
#include<cmath>
#include<iostream>
#define INLEVEL 1
#define OUTLEVEL 2
using namespace std;

/*The Matrix which could determine which operator is higher*/
int operatorMatrix[10][10]={
    {1,1,0,0,0,1,1,0,0,0},//+
    {1,1,0,0,0,1,1,0,0,0},//-
    {1,1,1,1,0,1,1,0,0,0},//*
    {1,1,1,1,0,1,1,0,0,0},///
    {0,0,0,0,0,2,-1,0,0,0},//(
    {1,1,1,1,-1,1,1,1,1,0},//)
    {0,0,0,0,0,-1,2,0,0,0},//#
    {1,1,1,1,0,0,1,1,1,0},//^
    {1,1,1,1,0,0,1,1,1,0},//√
    {1,1,1,1,1,1,1,1,1,1}//!
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

vector<char> initArray;

//Define array of operator and operand
stack<char> OPTR;
stack<double> OPND;

double outputValue=0;

MainWindow::~MainWindow()
{
    delete ui;
}
int compareOPTR(char pre,char lat){
    int prePos=0;
    int latPos=0;
    switch(pre){
    case '+':
        prePos=0;
        break;
    case '-':
        prePos=1;
        break;
    case '*':
        prePos=2;
        break;
    case '/':
        prePos=3;
        break;
    case '(':
        prePos=4;
        break;
    case ')':
        prePos=5;
        break;
    case '#':
        prePos=6;
        break;
    case '^':
        prePos=7;
        break;
    case 's':
        prePos=8;
        break;
    case '!':
        prePos=9;
        break;
    }
    switch(lat){
    case '+':
        latPos=0;
        break;
    case '-':
        latPos=1;
        break;
    case '*':
        latPos=2;
        break;
    case '/':
        latPos=3;
        break;
    case '(':
        latPos=4;
        break;
    case ')':
        latPos=5;
        break;
    case '#':
        latPos=6;
        break;
    case '^':
        latPos=7;
        break;
    case 's':
        latPos=8;
        break;
    case '!':
        latPos=9;
        break;
    }
    return operatorMatrix[prePos][latPos];
}
int isDigit(char ch){
    if((ch-'0'>=0)&&(ch-'0'<10)){
        return 1;
    }else{
        return 0;
    }
}

//Doing meta operate use two digit and one operator
double Operate(double a,char theta,double b){
    double ret=0;
    switch(theta){
    case '+':
        ret=a+b;
        break;
    case '-':
        ret= a-b;
        break;
    case '*':
        ret = a*b;
        break;
    case '/':
        ret = a/b;
        break;
    case '^':
        ret=pow(a,b);
        break;
    case 's':
        ret=sqrt(a);
        break;
    case '!':
        ret=1;
        for(int i=1;i<=a;i++){
            ret*=i;
        }
        break;
    }
    return ret;
}

int isDot(char ch){
    if(ch=='.'){
        return 1;
    }else{
        return 0;
    }
}

int consecutiveDigit(){
    char later=initArray.front();
    //cout<<later<<endl;
    if(isDigit(later)){
        return 1;
    }else if(isDot(later)){
        return 2;
    }else{
        return 0;
    }
}

double calculate(){
    OPTR.push('#');
    char c=initArray.front();
    initArray.erase(initArray.begin());
    while(c!='#'||OPTR.top()!='#'){
        if(isDigit(c)){
            //
            double realDigit=c-'0';
            int conNum=0;
            int con=consecutiveDigit();
            while(con>0){
                if(con==1){
                    char later=initArray.front();
                    initArray.erase(initArray.begin());
                    int laterDigit=later-'0';
                    realDigit=realDigit*10+laterDigit;
                }else if(con==2){
                    initArray.erase(initArray.begin());
                    while(consecutiveDigit()==1){
                        conNum+=1;
                        char later=initArray.front();
                        initArray.erase(initArray.begin());
                        double laterDigit=later-'0';
                        for(int i=0;i<conNum;i++){
                            laterDigit*=0.1;
                        }
                        realDigit=realDigit+laterDigit;
                    }
                }
                con=consecutiveDigit();
            }

            OPND.push(realDigit);
            c=initArray.front();
            initArray.erase(initArray.begin());
        }else{
            int higherFirst=2;
            higherFirst=compareOPTR(OPTR.top(),c);
            double a,b;
            char theta;
            switch(higherFirst){
            case 0:
                //Right Operator higher than left
                OPTR.push(c);
                c=initArray.front();
                initArray.erase(initArray.begin());
                break;
            case 2:
                //Same height
                OPTR.pop();
                c=initArray.front();
                initArray.erase(initArray.begin());
                break;
            case 1:
                //Left Operator higher than right
                theta=OPTR.top();
                OPTR.pop();
                b=OPND.top();
                OPND.pop();
                a=OPND.top();
                OPND.pop();
                OPND.push(Operate(a,theta,b));
                break;
            }}//switch
    }//while
    return OPND.top();
}

int isOPTR(char c){
    switch(c){
    case '+':
    case '*':
    case '/':
    case '-':
    case '#':
    case '^':
    case '!':
        return 1;
    default:
        return 0;
    }
}


int leftBracketCorrect(int level){
    if(initArray.size()==0){
        return 1;
    }
    int ret=0;
    if(level==INLEVEL){
        if(initArray.at(initArray.size()-1)!=')'){
            ret=1;
        }
    }else if(level==OUTLEVEL){
        int leftNumber=0,rightNumber=0;
        for(int i=0;i<initArray.size();i++){
            if(initArray.at(i)=='('){
                leftNumber++;
            }else if(initArray.at(i)==')'){
                rightNumber++;
            }
        }
        if(leftNumber==rightNumber){
            ret=1;
        }
    }
    return ret;
}

int rightBracketCorrect(int level){
    if(initArray.size()==0){
        return 0;
    }
    int leftNumber=0,rightNumber=0;
    for(int i=0;i<initArray.size();i++){
        if(initArray.at(i)=='('){
            leftNumber++;
        }else if(initArray.at(i)==')'){
            rightNumber++;
        }
    }
    if(level==INLEVEL){
        if((initArray.at(initArray.size()-1)!='(')&&(leftNumber>rightNumber)){
            return 1;
        }
    }else if(level==OUTLEVEL){
        if(leftNumber==rightNumber){
            return 1;
        }
    }
    return 0;
}


void MainWindow::on_ButtonLeft_clicked()
{
    if(!leftBracketCorrect(INLEVEL)){
        return;
    }
    initArray.push_back('(');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonRight_clicked()
{
    if(!rightBracketCorrect(INLEVEL)){
        return;
    }
    initArray.push_back(')');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}

bool zeroCorrect(){
    int dotIndex=-1;
    bool ret=false;
    for(int i=0;i<initArray.size();i++){
        if(isDot(initArray.at(i))){
            dotIndex=i;
        }
    }
    if(dotIndex==-1){
        return true;
    }
    for(int i=dotIndex-1;i>=0;i--){
        if(isOPTR(initArray.at(i))){
            break;
        }
        if(initArray.at(i)!='0'){
            return true;
        }
    }
    for(int i=dotIndex+1;i<initArray.size();i++){
        if(isOPTR(initArray.at(i))){
            break;
        }
        if(initArray.at(i)!='0'){
            return true;
        }
    }
    std::cout<<ret;
    return ret;
}

void MainWindow::on_ButtonEqual_clicked()
{
    if(initArray.size()==0||isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    if((!leftBracketCorrect(OUTLEVEL))||(!rightBracketCorrect(OUTLEVEL))){
        return;
    }
    if(!zeroCorrect()){
        ui->outputLabel->setText("ERROR.\n零不可以做除数，请输入非零数字");
        return;
    }
    ofstream file("history.txt", std::ios::app);
    for(int i=0;i<initArray.size();i++){
        char a=initArray.at(i);
        file << a ;
    }
    file<<'=';
    initArray.push_back('#');
    double resultRaw=calculate();
    string result=std::to_string(resultRaw);
    QString output=QString::fromStdString(result);
    ui->outputLabel->setText(output);
    file<<result<<endl;
    file.close();
}



void MainWindow::on_Button7_clicked()
{
    initArray.push_back('7');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button8_clicked()
{
    initArray.push_back('8');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button9_clicked()
{
    initArray.push_back('9');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button4_clicked()
{
    initArray.push_back('4');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button5_clicked()
{
    initArray.push_back('5');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button6_clicked()
{
    initArray.push_back('6');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button1_clicked()
{
    initArray.push_back('1');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button2_clicked()
{
    initArray.push_back('2');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button3_clicked()
{
    initArray.push_back('3');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_Button0_clicked()
{
    if(initArray.at(initArray.size()-1)=='/'){
        return;
    }
    initArray.push_back('0');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonAdd_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('+');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonMin_clicked()
{
    if(initArray.size()==0){
        initArray.push_back('(');
        initArray.push_back('0');
        initArray.push_back('-');
        QString inputText;
        for(int i=0;i<initArray.size();i++){
            inputText+=initArray.at(i);
            if(initArray.at(i)=='!'){
                i+=1;
            }
        }
        ui->inputLabel->setText(inputText);
        return;
    }
    if(initArray.at(initArray.size()-1)=='('){
        initArray.push_back('0');
        initArray.push_back('-');
        QString inputText;
        for(int i=0;i<initArray.size();i++){
            inputText+=initArray.at(i);
            if(initArray.at(i)=='!'){
                i+=1;
            }
        }
        ui->inputLabel->setText(inputText);
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('-');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonMul_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('*');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonD_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('/');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonDot_clicked()
{
    if(initArray.size()==0){
        return;
    }
    /*if(isOPTR(initArray.at(initArray.size()-1))&&(initArray.at(initArray.size()-1)!='/')){
        return;
    }
    if(initArray.at(initArray.size()-1)=='/'){
        initArray.push_back('0');
    }*/
    if(isOPTR(initArray.at(initArray.size()-1))){
        initArray.push_back('0');
    }
    int OPTRindex=0;
    int dotindex=0;
    for(int i=0;i<initArray.size();i++){
        if(isOPTR(initArray.at(i))){
            OPTRindex=i;
        }
        if(isDot(initArray.at(i))){
            dotindex=i;
        }
    }
    if(dotindex>OPTRindex){
        return;
    }
    initArray.push_back('.');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonC_clicked()
{
    initArray.clear();
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_ButtonDel_clicked()
{
    if(initArray.size()==0){
        return;
    }
    initArray.erase(initArray.end()-1);
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_pushButton_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('!');
    initArray.push_back('1');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('^');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('^');
    initArray.push_back('(');
    initArray.push_back('0');
    initArray.push_back('.');
    initArray.push_back('5');
    initArray.push_back(')');
    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(initArray.size()==0){
        return;
    }
    if(isOPTR(initArray.at(initArray.size()-1))){
        return;
    }
    initArray.push_back('^');
    initArray.push_back('2');

    QString inputText;
    for(int i=0;i<initArray.size();i++){
        inputText+=initArray.at(i);
        if(initArray.at(i)=='!'){
            i+=1;
        }
    }
    ui->inputLabel->setText(inputText);
}

void MainWindow::on_pushButton_6_clicked()
{
    About about(this);
    about.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    MyDialog dialog(this);
    dialog.exec();
}
