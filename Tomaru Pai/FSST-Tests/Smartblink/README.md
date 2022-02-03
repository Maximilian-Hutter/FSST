# Programmieraufgabe Smartblink

Basierend auf der vorliegenden Qt-Oberfläche soll ein Programm erstellt werden, das die LEDs des
Raspberry-Zusatzboards wahlweise gleichzeitig blinken lässt oder als Lauflicht betreibt. 
<img src="screenshot.png" width="60%">

## Lösungsschritte
1. Logge dich auf deinem Account auf github über den Webbrowser ein
2. Navigiere mit dem Browser zu diesem Repository: 
 https://github.com/eneukirchner/Smartblink
3. Erstelle einen Fork davon auf deinem github-Account (fork-Button rechts oben auf der github-Website).
4. Kopiere den Fork auf deinen Raspberry: `git clone git@github.com:<dein Accountname>/Smartblink.git`. 
   In dem dadurch erzeugten Ordner befindet sich das Projekt.
5. Die grafische Oberfläche soll nicht verändert werden.
6. Die zu erstellende Programmlogik in C++ soll der Funktionalität der Vorlage (lauffähiges Programm unter `./bin/Smartblink`) entsprechen: 
   Nach dem Start des Programmes blinken zunächst alle 4 LEDs gleichzeitig mit der Frequenz 1 Hz. Mittels des
   Schiebereglers kann die Frequenz zwischen 1 ... 10 Hz variiert werden. Die Radiobuttons ermöglichen die Umschaltung
   zwischen Blinker und Lauflicht. Nach dem  Schließen des Programmfensters sollen alle LEDs ausgeschaltet sein.
7. Wenn alles wunschgemäß funktioniert, lade den aktualisierten Quellcode wieder auf deinen Account (git-Ablauf wie gelernt).

## Dein Name: 
