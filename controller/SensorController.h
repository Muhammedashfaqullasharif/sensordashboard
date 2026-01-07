#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include <QObject>
#include <QTimer>
#include "SensorModel.h"


class SensorController: public QObject
{
    Q_OBJECT
public:

    SensorController(SensorModel *model,QObject *parent = nullptr);

private slots:
    void updateSensors();

public:
    SensorModel *m_model;
    QTimer m_timer;
};

#endif // SENSORCONTROLLER_H
