#include "SensorModel.h"

SensorModel::SensorModel(QObject *parent)
    :QObject(parent)
{

}

int SensorModel:: temperature() const{return m_temperature;}
int SensorModel:: humidity() const{return m_humidity;}
int SensorModel:: pressure() const{return m_pressure;}
double SensorModel:: uv() const{return m_uv;}
int SensorModel:: aqi() const{return m_aqi;}


void SensorModel:: setTemperature(int value)
{
    if(m_temperature == value)
    {
        return;
    }
    m_temperature = value;
    emit temperatureChanged();
}

void SensorModel:: setHumidity(int value)
{
    if(m_humidity == value)
    {
        return;
    }
    m_humidity = value;
    emit humidityChanged();
}

void SensorModel:: setPressure(int value)
{
    if(m_pressure == value)
    {
        return;
    }
    m_pressure = value;
    emit pressureChanged();
}

void SensorModel:: setUv(double value)
{
    if(qFuzzyCompare(m_uv,value))
    {
        return;
    }
    m_uv = value;
    emit uvChanged();
}

void SensorModel:: setAqi(int value)
{
    if(m_aqi == value)
    {
        return;
    }
    m_aqi = value;
    emit aqiChanged();
}



