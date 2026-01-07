import QtQuick
import QtQuick.Controls


// Item {
//     id: root
//     width: 220
//     height: 120

//     property var values: [40, 70, 90, 60, 110, 80]
//     property real maxValue: 150

//     Row {
//         anchors.bottom: parent.bottom
//         anchors.horizontalCenter: parent.horizontalCenter
//         spacing: 8

//         Repeater {
//             model: values.length

//             Rectangle {
//                 width: 14
//                 height: 0
//                 radius: 4
//                 color: "#FFB74D"   // AQI amber
//                 opacity: 0.9

//                 Rectangle {
//                     anchors.fill: parent
//                     radius: 4
//                     color: "transparent"
//                     border.color: Qt.rgba(1,1,1,0.3)
//                 }

//                 SequentialAnimation {
//                     running: true
//                     loops: Animation.Infinite

//                     NumberAnimation {
//                         target: parent
//                         property: "height"
//                         to: (values[index] / maxValue) * root.height
//                         duration: 1200
//                         easing.type: Easing.OutCubic
//                     }
//                     PauseAnimation { duration: 1000 }
//                 }
//             }
//         }
//     }
// }


Item {
    id: root
    width: 420
    height: 200

    // AQI data (0–500)
    property real value: 0
    property var aqiData: []
    property real maxAQI: 500
    property real currentAQI: value


    Canvas {
        id: canvas
        anchors.fill: parent
        z: 1

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            var left = 45
            var top = 20
            var bottom = 30

            var w = width - left - 15
            var h = height - top - bottom

            // ---- GRID ----
            ctx.strokeStyle = "rgba(255,255,255,0.08)"
            ctx.lineWidth = 1

            for (var i = 0; i <= 500; i += 100) {
                var y = top + h * (1 - i / maxAQI)
                ctx.beginPath()
                ctx.moveTo(left, y)
                ctx.lineTo(width - 10, y)
                ctx.stroke()
            }

            // ---- AREA ----
            ctx.beginPath()
            ctx.moveTo(left, top + h)

            for (var j = 0; j < aqiData.length; j++) {
                var x = left + w * (j / (aqiData.length - 1))
                var z = top + h * (1 - aqiData[j] / maxAQI)
                ctx.lineTo(x, z)
            }

            ctx.lineTo(width - 10, top + h)
            ctx.closePath()

            var g = ctx.createLinearGradient(0, top, 0, height)
            g.addColorStop(0, "rgba(255,120,120,0.45)")
            g.addColorStop(1, "rgba(255,120,120,0.05)")

            ctx.fillStyle = g
            ctx.fill()

            // ---- LINE ----
            ctx.beginPath()
            for (var k = 0; k < aqiData.length; k++) {
                var lx = left + w * (k / (aqiData.length - 1))
                var ly = top + h * (1 - aqiData[k] / maxAQI)
                k === 0 ? ctx.moveTo(lx, ly) : ctx.lineTo(lx, ly)
            }

            ctx.strokeStyle = "#FF8A8A"
            ctx.lineWidth = 2.5
            ctx.shadowColor = "#FF8A8A"
            ctx.shadowBlur = 8
            ctx.stroke()
        }
    }

    onValueChanged: {

        aqiData.push(value)
        if(aqiData.length > 20)
            aqiData.shift()
        canvas.requestPaint()
    }

    // ---- LEFT SCALE ----
    Column {
        anchors.left: parent.left
        anchors.leftMargin: 6
        anchors.verticalCenter: parent.verticalCenter
        spacing: 14
        z: 2

        Repeater {
            model: ["500","400","300","200","100","0"]
            Text {
                text: modelData
                font.pixelSize: 10
                color: "#9AA0B5"
            }
        }
    }

    // ---- CENTER VALUE ----
    Column {
        anchors.centerIn: parent
        spacing: 2
        z: 2

        Text {
            text: Math.round(currentAQI)
            font.pixelSize: 32
            font.bold: true
            color: "#FFEAEA"
        }

        Text {
            text: "AQ INDEX"
            font.pixelSize: 12
            color: "#C0C5E0"
        }

    }
}
