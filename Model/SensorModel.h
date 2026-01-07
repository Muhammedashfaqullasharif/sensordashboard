#ifndef SENSORMODEL_H
#define SENSORMODEL_H

#include <QObject>

class SensorModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(int pressure READ pressure WRITE setPressure NOTIFY pressureChanged)
    Q_PROPERTY(int aqi READ aqi WRITE setAqi NOTIFY aqiChanged)
    Q_PROPERTY(double uv READ uv WRITE setUv NOTIFY uvChanged)

public:
    explicit SensorModel(QObject *parent = nullptr);

    int temperature() const;
    int humidity() const;
    int pressure() const;
    int aqi() const;
    double uv() const;

public slots:

    void setTemperature(int value);
    void setHumidity(int value);
    void setPressure(int value);
    void setAqi(int value);
    void setUv(double value);

signals:

    void temperatureChanged();
    void pressureChanged();
    void humidityChanged();
    void aqiChanged();
    void uvChanged();

private:

    int m_temperature = 0;
    int m_humidity = 0;
    int m_pressure = 0;
    double m_uv = 0.0;
    int m_aqi = 0;

};


#endif // SENSORMODEL_H
