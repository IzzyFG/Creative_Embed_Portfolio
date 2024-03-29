# Technical documentation

## Hardware

### Materials Needed

1. TTGO T1
2. 5v Joystick Breakout Module with X and Y axis
3. Button
4. Sufficient Length Wire (6 pieces will be needed)
5. Wire cutters/strippers
6. Breadboard

### Wire Project

1. Connect wire from TTGO T1 pin 5V to joystick pin  +5V
2. Connect wire from TTGO T1 pin G to joystick pin  G
3. Connect wire from TTGO T1 pin 25 to joystick pin VRX
4. Connect wire from TTGO T1 pin 32 to joystick pin VRY
5. Connect wire from TTGO T1 pin 26 to button power
6. Connect wire from TTGO T1 pin G to button ground

## Software
### Steps to recreate project

1. VS code
2. VS code extension PlatformIO
3. VS code extension Live Server

### To run project

1. Clone the repository

    ```console
    git clone git@github.com:IzzyFG/Creative_Embed_Portfolio.git
    ```

2. Open Quiz_Game in VScode
    1. Open VScode
    2. Open PlatformIO
    3. Select 'Pick a folder'
    4. Select `Creative_Embed_Portfolio/project_2/Quiz_Game`
    5. Ensure the monitor_speed in `Quiz_Game/platformio.ini` is set to the
    correct speed of matching the serial monitor speed (in my case 115200)

3. Upload code to TTGO T1
    1. Connect TTGO T1 to computer
    2. Ensure no wires are connected to outputs
    3. Open command pallete "ctrl + shift + p"
    4. Type "Platform IO: upload" and select item

4. Open website locally on computer
    1. Open `Creative_Embed_Portfolio\project_2\Quiz_Game\webpage\index.html` in VSCode
    2. Open command pallete "ctrl + shift + p"
    3. Type "Live Server: Open with Live Server" and select item

OR

4. Open [website](Quiz_Game/webpage/) hosted on GitHub Pages

## Quiz Sources

1. [NYC](https://www.factmonster.com/take-quiz/new-york-city)
2. [Music](https://www.usefultrivia.com/music_trivia/)
3. [Sports](https://www.usefultrivia.com/sports_trivia/)
4. [Movies](https://www.rd.com/article/movie-trivia-facts/)

## Future Features

1. Multiple Quiz sources
2. Add scoreboard
3. Randomize order of questions and answers
4. Pull questions from a larger question bank
