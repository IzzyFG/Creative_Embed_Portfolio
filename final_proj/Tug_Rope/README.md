# Tug of Rope

## Setup

1. Used PlatformIO vscode extension to create project
2. Changed monitor_speed in platformio.ini
    - monitor_speed = 115200
3. Added TFT_eSPI library
    - opened PIO Home while in TUG_ROPE directory
    - Opened libraries (side panel)
    - searched "TFT_eSPI" by Bodmer
    - Clicked "Add to Project"
    - Select a Project > selected `final_proj\Tug_Rope`
    - clicked Add
4. Edited `User_Setup.h`
    - Opened `\Tug_Rope\.pio\libdeps\ttgo-t1\TFT_eSPI\User_Setup_Select.h`
    - Commented out line 30:

        ```C
        //#include <User_Setup.h>           // Default setup is root library folder
        ```

    - Uncommented line 61:

        ```C
        #include <User_Setups/Setup25_TTGO_T_Display.h>    // Setup file for ESP32 and TTGO T-Display ST7789V SPI bus TFT
        ```

## References

- [Button Class](https://arduino.stackexchange.com/a/48244)
