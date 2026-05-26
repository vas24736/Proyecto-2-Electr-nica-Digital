 Monitor de Paciente Dual con Arduino Nano

## Integrantes

Israel Vásquez  
Kathy Anzueto

## Descripción del proyecto

Este repositorio contiene el código y la documentación del Proyecto 2 del curso Electrónica Digital 1. El proyecto consiste en un sistema embebido desarrollado con Arduino Nano que simula un monitor biomédico básico para representar diferentes condiciones fisiológicas de un paciente.

El sistema utiliza un potenciómetro como entrada analógica para simular señales de frecuencia cardíaca y temperatura corporal. Además, cuenta con dos botones: uno para cambiar entre los modos de operación y otro para apagar la alarma en el modo de temperatura. Las salidas del sistema incluyen un LED RGB, un servomotor, un buzzer y un display de 7 segmentos.

## Funcionamiento general

El sistema tiene tres modos de operación. En el modo 0, el sistema permanece en reposo, todas las salidas están apagadas, el servomotor se coloca en 0 grados y el display muestra el número 0.

En el modo 1, el sistema funciona como monitor de frecuencia cardíaca. El potenciómetro simula valores entre 0 y 200 latidos por minuto. Según el rango detectado, el LED RGB cambia de color para indicar bradicardia, estado normal, taquicardia o taquicardia severa. El servomotor se mueve proporcionalmente al valor de frecuencia cardíaca y el display muestra el número 1.

En el modo 2, el sistema funciona como monitor de temperatura corporal. El potenciómetro simula una temperatura y el sistema clasifica la condición como hipotermia, normal, febrícula, fiebre o fiebre alta. Dependiendo del rango, el LED RGB cambia de color y el servomotor se posiciona en un ángulo definido. Si la temperatura se encuentra en hipotermia o fiebre alta, el buzzer se activa como alarma hasta que se presione el botón correspondiente o la señal cambie de rango. En este modo, el display muestra el número 2.

## Componentes utilizados

El proyecto utiliza un Arduino Nano, un potenciómetro, dos botones, un LED RGB, un servomotor, un buzzer, un display de 7 segmentos, resistencias, protoboard y cables de conexión.

## Asignación de pines

El potenciómetro está conectado al pin A4. El botón de cambio de modo está conectado al pin D3 y el botón de apagado de alarma al pin D2. El display de 7 segmentos utiliza los pines D4, D5, D6, D7, D8, D9 y D10. El LED RGB utiliza los pines D13 para rojo, D12 para azul y D11 para verde. El buzzer está conectado al pin A3 y el servomotor al pin A2.

## Código

El programa está escrito en C++ para Arduino. La lógica principal se basa en una variable de estado que permite cambiar entre los tres modos de operación. También se incluyen funciones propias para mostrar los números en el display de 7 segmentos y para evaluar los rangos de frecuencia cardíaca.

## Simulación

La simulación del circuito fue realizada en Tinkercad y puede consultarse en el siguiente enlace:

https://www.tinkercad.com/things/0YbKFgtK1N7/editel?returnTo=%2Fdashboard&sharecode=MnVbXvgvk2C7W-V-FuyvDH-fQ3ULrGEA9-2VsxQ0SHQ

## Estado del proyecto

El proyecto cuenta con código funcional, simulación en Tinkercad y una propuesta de implementación física mediante Arduino Nano. El sistema integra entradas digitales, entrada analógica y salidas visuales, sonoras y mecánicas para representar el funcionamiento básico de un monitor de paciente dual.
