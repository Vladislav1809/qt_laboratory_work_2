// customclass.cpp
#include "dataprocessor.h"

DataProcessor::DataProcessor(QObject *parent) : QObject(parent)
{
}

void DataProcessor::processData(QString data)
{
    // Логика обработки данных
    QString processedData = "Processed: " + data;

    // Испускаем сигнал с обработанными данными
    emit dataProcessed(processedData);
}
