#include "tastierinoview.h"
#include "ui_tastierinoview.h"

tastierinoView::tastierinoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tastierinoView)
{
    ui->setupUi(this);

    connect(ui->btn0, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn1, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn2, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn3, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn4, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn5, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn6, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn7, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn8, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btn9, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btnPoint, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
    connect(ui->btnComma, SIGNAL(clicked(bool)), this, SLOT(slotKeyPressed()));
}

tastierinoView::~tastierinoView()
{
    delete ui;
}

void tastierinoView::slotKeyPressed() {
    if (sender() == ui->btn0) {
        // Do something
    }else if (sender() == ui->btn1) {
        // Do something
    }else if (sender() == ui->btn2) {
        // Do something
    }else if (sender() == ui->btn3) {
        // Do something
    }else if (sender() == ui->btn4) {
        // Do something
    }else if (sender() == ui->btn5) {
        // Do something
    }else if (sender() == ui->btn6) {
        // Do something
    }else if (sender() == ui->btn7) {
        // Do something
    }else if (sender() == ui->btn8) {
        // Do something
    }else if (sender() == ui->btn9) {
        // Do something
    }else if (sender() == ui->btnPoint) {
        // Do something
    }else if (sender() == ui->btnComma) {
        // Do something
    }
}
