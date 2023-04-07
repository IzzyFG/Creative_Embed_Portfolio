# Technical Documentation

To clone my repository:

```console
git clone git@github.com:IzzyFG/Creative_Embed_Portfolio.git
```

## Arduino IDE Setup

Creating this program required a large amount of initial setup:

1. Downloading the [Arduino IDE](https://www.arduino.cc/en/software)
    1. Launch Arduino IDE after installation
2. Editing Arduino Preferences
    1. Add ESP32 support to Additional Board manager URLs: [https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
3. Add neccessary Library
    1. Tools>Library Manager
    2. Search "TFT_eSPI" and install the library by Bodmer
4. Edit User Setup
    1. Navigate to Arduino location in files as listed in Preferences>Settings>Sketchbook location
    2. Open `Arduino/libaries/TFT_eSPI/User_Setup_Select.h` in any text editor
    3. Ensure "Default setup is root library folder" is commented out
        1. Line 22 should have `//` before `#include`
    4. Ensure "Setup file for ESP32 and TTGO T-Display ST7789V SPI bus TFT" is uncommented
        1. Line 61 should not contain any characters before `#include`

## Font Setup

In order to have multiple custom fonts I had to download a few programs

1. Install freetype libaries

    In a linux environment terminal

    ```console
    sudo apt-get install libfreetype-dev libfreetype6 libfreetype6-dev
    ````

2. Install [freefont library](https://ftp.gnu.org/gnu/freefont/)
    1. Download freefont-ttf-20120503.zip
    2. Extract file into the Arduino libaries directory (as found earlier)

        ```console
        $ cd Arduino/libaries/

        $ ls 
        TFT_eSPI
        freefont-20120503
        ```

3. Install the Adafruit-GFX-Library into Arduino libaries
    1. Clone repository

        ```console
        $ git clone https://github.com/adafruit/Adafruit-GFX-Library.git 

        $ ls
        Adafruit-GFX-Library-master
        TFT_eSPI
        freefont-20120503
        ```

    2. Replace `Adafruit-GFX-Library/fontconvert/makefonts.sh` with the file with the file found at `Creative_Embeded_Portfolio_installation_1/Create_Fonts/makefonts.sh` to create custom fonts

    3. Make the fonts

        ```console
        cd Adafruit-GFX-Library/fontconvert
        make
        bash makefonts.sh
        ```

4. Setup TFT_eSPI fonts
    1. Move font files output to TFT_eSPI fonts

        ```console
        mv ../Fonts/* ../../TFT_eSPI/Fonts/GFXFF
        ```

    2. Include newly made fonts in `TFT_eSPI/Fonts/GFXFF/gfxfont.h` by replacing
    it with the file found at `Creative_Embed_Portfolio\installation_1\Fonts\gfxfont.h`

To recreate the above without having install excess prorams, all that is necessary is:
    1. Copy all files in `Creative_Embed_Portfolio\installation_1\Fonts\`
    2. Paste files in `TFT_eSPI/Fonts/GFXFF/` and overwrite any existing files

## Recreating words file

1. Download [google-10000-english-no-swears.txt](https://github.com/first20hours/google-10000-english/blob/d0736d492489198e4f9d650c7ab4143bc14c1e9e/google-10000-english-no-swears.txt)

2. Download [count_1w.txt](https://norvig.com/ngrams/count_1w.txt)

3. Run Python file `Creative_Embed_Portfolio\installation_1\getWords.py`
    1. Install [Python 3.11.0](https://www.python.org/downloads/)
    2. Ensure `getWords.py`, `counts_1w.txt`, and `google-10000-english-no-swears.txt` are all in same directory

        ```console
        py getWords.py
        ```

    3. Rename file `words_w_count.h`
        1. Change `const char * wordsList []` to `const char * wordsList [500]`
        2. Change `int wordsFreq []` to `int wordsFreq [500]`
    4. Move output file to `Creative_Embed_Portfolio\installation_1\installation_1`

## Running installation_1.ino

1. Open Arduino IDE
2. File>Open
    1. Select `Creative_Embed_Portfolio\installation_1\installation_1` in file explorer popup
3. Select Board and port
    1. Tools>Boards>esp32>TTGO T1
    2. Tools>Port> [select port TTGO T1 is connected to]
4. Upload code to TTGO T1
    1. Sketch>Upload
