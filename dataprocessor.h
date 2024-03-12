// dataprocessor.h
#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>

class DataProcessor : public QObject
{
    Q_OBJECT

public:
    explicit DataProcessor(QObject *parent = nullptr);

signals:
    void dataProcessed(QString data);

public slots:
    void processData(QString data);

};

#endif // DATAPROCESSOR_H
