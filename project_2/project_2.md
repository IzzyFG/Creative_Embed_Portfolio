---
title: homepage
layout: default
filename: project_2.md
--- 

# Serial Project: Quiz Game

## Technical Documentation

### Design

#### Materials Needed

1. TTGO T1
2. 5v Joystick Breakout Module with X and Y axis
3. Button
4. Sufficient Length Wire (6 pieces will be needed)
5. Wire cutters/strippers
6. Breadboard

#### Wire Project 

1. Connect wire from TTGO T1 pin 5V to joystick pin  +5V
2. Connect wire from TTGO T1 pin G to joystick pin  G
3. Connect wire from TTGO T1 pin 25 to joystick pin VRX
4. Connect wire from TTGO T1 pin 32 to joystick pin VRY
5. Connect wire from TTGO T1 pin 26 to button power
6. Connect wire from TTGO T1 pin G to button ground

### Steps to recreate project

1. Install VS code
2. Install PlatformIO from marketplace
3. Create New Project with PlatformIO PIO Home
    1. Select Board TTGO T1
    2. Match monitor_speed in platformio.ini to serial monitor speed of VSCode

## To run project

1. Clone the repository

    ```console

    git clone git@github.com:IzzyFG/Creative_Embed_Portfolio.git

    ```

2. Open Quiz_Game in VScode
    1. Open VScode
    2. Open PlatformIO
    3. Select 'Pick a folder'
    4. Select 'Creative_Embed_Portfolio/project_2/Quiz_Game'

3. Upload code to TTGO T1
    1. Connect TTGO T1 to computer
    2. Ensure no wires are connected to outputs
    3. Open command pallete "ctrl + p"
    4. Type "Platform IO: upload" and select item

4. Open website locally on computer
    1. Launch a chromiun browser
    2. Get full path of "/Embedded%20Design/Creative_Embed_Portfolio/project_2/Quiz_Game/webpage/index.html"
    3. Type full path in browser address bar

## Creative Documentation

## Project website

View visuals for Quiz_Game[Quiz_Game](./Quiz_Game/)
