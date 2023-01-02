<h1>Parking Rover</h1>
Rover dotato di Mecanum Wheels, ovvero ruote che permettono operazioni come traslazione laterale e diagonale.
</br>

<h2>Hardware</h2>
<ul>
  <li> 1 Arduino Uno
  <li> 1 Adafruit Motorshield V1
  <li> 1 HC05 Modulo Bluetooth
  <li> 4 Motori DC
  <li> 5 HC-SR04 (Sensori ad ultrasuoni)
</ul>

</br>
<h2>Meccanica</h2>
Le 4 ruote mecanum vanno montate nella giusta direzione: fare affidamento all'<a href="https://github.com/Ab0rter/Parking_Rover/blob/main/Mecanum%20Wheels%20Orientation.jpeg">immagine</a> 

</br>
<h2>Software</h2>
Il progetto è realizzato mediante platformio in Visual Studio Code.
<h3>Librerie esterne necessarie</h3>
<ul>
  <li> SoftwareSerial: per gestire la comunicazione bluetooth
  <li> Adafruit-Motor-Shield-Library: per gestire i motori e la motorshield
</ul>
