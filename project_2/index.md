---
title: pfoject_2
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
2. Install Live Server from marketplace
3. Install PlatformIO from marketplace
4. Create New Project with PlatformIO PIO Home
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
    4. Select `Creative_Embed_Portfolio/project_2/Quiz_Game`

3. Upload code to TTGO T1
    1. Connect TTGO T1 to computer
    2. Ensure no wires are connected to outputs
    3. Open command pallete "ctrl + shift + p"
    4. Type "Platform IO: upload" and select item

4. Open website locally on computer
    1. Open `Creative_Embed_Portfolio\project_2\Quiz_Game\webpage\index.html` in VSCode
    2. Open command pallete "ctrl + shift + p"
    3. Type "Live Server: Open with Live Server" and select item

## Difficulties in Project

I found it was difficult to be restricted to only using JavaScript to mutate the
html page. Also by necessity I could only use one JavaScript file since the
output from the microcrontoller had to be accessible at every stage of the page.

Through utilizing different json files to hold the different quizzes instead of
statically holding them in hidden fields and revealing when the user was at
that question led to quite a few difficutlies in importing information. I chose
to have the data in json files that way the buttons/questions reference id's
would stay the same for all of the other functions. This led to be having to
utilize a server (through the Live Server extension) in order to use the fetch
API.

## Creative Documentation

First I prototyped the design. I wanted a simple enclosure that would have a button and joystick stick out from one side and allow for usb C access on side.


<img src = "src\PXL_20230403_032123117.jpg" alt="Design Draw" width = "65%" height = "65%">

<img src = "src\PXL_20230402_172559122.jpg" alt="Prototyping Design" width = "65%" height = "65%">


Then I cut everything to size and taped the sides for a nicer finish:
   
<img src = "src\PXL_20230402_175251574.jpg" alt="Design Cut" width = "65%" height = "65%">

<img src = "src\PXL_20230402_184541882.jpg" alt="Design with board" width = "65%" height = "65%">


<img src = "src\PXL_20230402_185430024.jpg" alt="taped1" width = "65%" height = "65%">

<img src = "src\PXL_20230402_185434966.jpg" alt="taped2" width = "65%" height = "65%">

Taping the project closed also allows for it to be a bit of a mystery, which is how it is intended to seem. Since the whole project is designed around quizzes I wanted the user to feel uncertain about what truly lies ahead.

![Youtube video](https://youtube.com/shorts/36etN84fEU0)
