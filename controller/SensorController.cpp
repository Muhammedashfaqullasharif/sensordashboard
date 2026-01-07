#include "SensorController.h"
#include <QRandomGenerator>

SensorController::SensorController(SensorModel *model,QObject *parent)
    :QObject(parent), m_model(model)
{
    connect(&m_timer, &QTimer::timeout, this, SensorController::updateSensors);

    m_timer.start(2000);
}

void SensorController:: updateSensors()
{
    m_model->setTemperature(QRandomGenerator::global()->bounded(12, 48));
    m_model->setHumidity(QRandomGenerator::global()->bounded(36,90));
    m_model->setPressure(QRandomGenerator::global()->bounded(42,96));
    m_model->setAqi(QRandomGenerator::global()->bounded(50,305));
    double uv = QRandomGenerator::global()->generateDouble() * 11.0;
    m_model->setUv(uv);
    // m_model->setUv(QRandomGenerator::global()->bounded(0.0,11.0));
}
