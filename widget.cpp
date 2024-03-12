#include "widget.h"
#include "dataprocessor.h"
#include "./ui_widget.h"
#include <QString>
#include <QPushButton>
#include <QVariant>
#include <QDate>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->processButton, &QPushButton::clicked, this, &Widget::processText);

    DataProcessor *dataProcessor = new DataProcessor(this);

    // Соединение сигнала dataProcessed с слотом для отображения данных на форме
    connect(dataProcessor, &DataProcessor::dataProcessed, this, [this](QString processedData) {
        ui->label_4->setText(processedData);
    });

    // Пример вызова метода обработки данных по нажатию кнопки
    connect(ui->extraButton, &QPushButton::clicked, dataProcessor, [=]() {
        QString input = ui->inputLineEdit->text();
        dataProcessor->processData(input);
    });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::processText()
{

    QString inputLineText = ui->inputLineEdit->text();
    QString first = parseInputData(QVariant(inputLineText));
    QString second =parseInputData(QVariant(ui->calendar->selectedDate()));
    QString third = parseInputData(QVariant(ui->doubleSpinBox->value()));


    ui->label->setText(first);
    ui->label_2->setText(second);
    ui->label_3->setText(third);
}


QString Widget::parseInputData(QVariant var)
{
    QString result = "";
    if (var.typeId() == QVariant::String) {
        result.append("String value: " + var.toString());

    } else if (var.type() == QVariant::Int || var.type() == QVariant::Double) {
        result.append("Doubled value: " + std::to_string(var.toDouble() * 2));

    } else if (var.canConvert<QDate>()) {
        QDate date = var.toDate();
        result.append("Date value: " + date.toString("dd.MM.yyyy"));

    } else {
        qDebug() << "Unsupported type";
        return "";
    }

    return result;
}
