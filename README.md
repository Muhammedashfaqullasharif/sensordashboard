# sensordashboard
🌡️ Sensor Monitor – Qt/QML Real-Time HMI Dashboard

A modern Qt Quick (QML) based sensor monitoring dashboard with glassmorphism UI, animated circular meters, and real-time graph visualizations for environmental data such as Temperature, Humidity, Pressure, UV Index, and Air Quality Index (AQI).

This project demonstrates industry-style HMI development, clean separation of Model–View–Controller (MVC), and real-time UI updates driven from a C++ backend.

✨ **Features**

Frameless custom window

Custom title bar with drag support

Minimize / Maximize / Close buttons

Modern glassmorphism UI

Frosted cards

Soft gradients

Dark industrial theme

Real-time sensor simulation

Randomly generated sensor values

Periodic updates using controller logic

Animated circular meters

Temperature

Humidity

Pressure

Canvas-based real-time graphs

UV Index (0–11 scale)

Air Quality Index (0–500 scale)

Area fill + glowing curve

Smooth UI updates

Q_PROPERTY + signals

Automatic QML reactivity

Scalable layout

GridLayout-based dashboard

Easily extendable for more sensors

🧠 Architecture (MVC Pattern)
sensormonitor/
│
├── model/
│
├── controller/
|
├── qml/
│
└── main.cpp

**Model**

Stores sensor values

Emits change signals

Acts as the single source of truth

**Controller**

Generates random sensor values

Updates model at fixed intervals

Simulates real sensor input

**View (QML)**

Pure UI layer

Automatically reacts to model changes

No business logic inside QML

🖥️ **Technologies Used**

Qt 6.x

Qt Quick (QML)

Qt Quick Controls

Qt Quick Layouts

Qt Canvas

C++ (Qt backend)

MVC architecture

📊 Sensors Implemented
Sensor	Type	Visualization
Temperature	°C	Circular Meter
Humidity	%	Circular Meter
Pressure	%	Circular Meter
UV Index	0–11	Animated Graph
AQI	0–500	Animated Graph
🚀 How It Works

SensorController periodically generates random values

Values are updated in SensorModel

Model emits valueChanged signals

QML UI reacts automatically

Circular meters animate smoothly

Graphs redraw using Canvas when data changes

▶️ **Build & Run
Requirements**

Qt 6.5+ (Qt 6.9 tested)

MinGW / MSVC (Windows) or GCC (Linux)

Qt Creator recommended

Steps

Open the project in Qt Creator

Configure kit (Qt 6)

Build

Run

📸 Screenshots



https://github.com/user-attachments/assets/f9cd680c-08dc-4664-9823-eaf31e16632f



🎯 Use Cases

Industrial HMI dashboards

Sensor monitoring systems

Embedded Linux touchscreens

Medical / environmental UI prototypes

Automotive or EV dashboards

Factory automation interfaces

🔧 Future Improvements

Real hardware sensor integration (UART / I2C / SPI)

Data logging (CSV / database)

Alarm thresholds

Historical zoom & pan

Touch gestures

Light theme support

Network data input (MQTT / TCP)

👨‍💻 **Author**

M Ashfaqulla Sharif
Qt / QML HMI Developer
Embedded & GUI Engineer

📄 License

This project is for educational and demonstration purposes.
You may reuse UI concepts with attribution.0
