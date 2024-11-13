#include "mydialog.h"
#include <fstream>
#include <vector>

MyDialog::MyDialog(QWidget *parent) : QDialog(parent), ui(new Ui::MyDialog) {
    ui->setupUi(this);

    std::ifstream file("history.txt",std::ios::app);
    if (!file) {
        return;
    }

    std::vector<std::string> lines;
    std::string line;


    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int start = std::max(0, static_cast<int>(lines.size()) - 6);
    for (int i = start; i < lines.size(); ++i) {
        QString outLine = QString::fromStdString(lines[i]);
        switch (i - start) {
        case 0: ui->h1->setText(outLine); break;
        case 1: ui->h2->setText(outLine); break;
        case 2: ui->h3->setText(outLine); break;
        case 3: ui->h4->setText(outLine); break;
        case 4: ui->h5->setText(outLine); break;
        case 5: ui->h6->setText(outLine); break;
        }
    }
}

MyDialog::~MyDialog() {
    delete ui;
}
