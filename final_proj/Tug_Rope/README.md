# Tug of Rope

## Table of Contents

1. [Software](#software)
    1. [Software Requirements](#software-requirements)
    2. [Code Settings](#my-code-settings)
    3. [Code Settings](#my-code-settings)
    4. [ESP32 Setup](#esp32-setup)
2. [Hardware](#hardware)
    1. [Materials](#materials)
    2. [Hardware Assembly](#hardware-assembly)
3. [References](#references)

## Software

### Software requirements

1. VS code
2. VS code extension PlatformIO
3. VS code extension Live Server

### My Code Settings

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

### ESP32 Setup

1. Clone the repository

    ```console
    git clone git@github.com:IzzyFG/Creative_Embed_Portfolio.git
    ```

2. Open Quiz_Game in VScode
    1. Open VScode
    2. Open PlatformIO
    3. Select 'Pick a folder'
    4. Select `Creative_Embed_Portfolio/final_proj/Tug_Rope`
    5. Ensure the monitor_speed in `Tug_Rope/platformio.ini` is set to the
    correct speed of matching the serial monitor speed (in my case 115200)

3. Upload code to TTGO T1
    1. Connect TTGO T1 to computer
    2. Ensure no wires are connected to outputs
    3. Open command pallete "ctrl + shift + p"
    4. Type "Platform IO: upload" and select item

## Hardware

### Materials

1. (8x) M5x16 screws
2. (8x) M5 washers
3. (8x) M5 bolts
4. (2x) M3x8 screws
5. (2x) M3x16 screws
6. (4x) M4 washers
7. (4x) M4 bolts
8. (1x) [Pulley belt](https://www.amazon.com/Zeberoxyz-Synchronous-Aluminum-Timing-20-60T-5B-6/dp/B09JWLTBGT/ref=pd_day0fbt_img_sccl_2/137-4032094-1164165?pd_rd_w=aqmx5&content-id=amzn1.sym.a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_p=a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_r=Y25H3PRKQT6J4VJPNCJ8&pd_rd_wg=q1mVC&pd_rd_r=9fa581fd-0b1d-4c12-a2aa-504381926a37&pd_rd_i=B08QYYF6W4&th=1)
9. (1x) [large pulley wheel](https://www.amazon.com/Zeberoxyz-Synchronous-Aluminum-Timing-20-60T-5B-6/dp/B09JWLTBGT/ref=pd_day0fbt_img_sccl_2/137-4032094-1164165?pd_rd_w=aqmx5&content-id=amzn1.sym.a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_p=a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_r=Y25H3PRKQT6J4VJPNCJ8&pd_rd_wg=q1mVC&pd_rd_r=9fa581fd-0b1d-4c12-a2aa-504381926a37&pd_rd_i=B08QYYF6W4&th=1)
10. (1x) [small pulley wheel](https://www.amazon.com/Zeberoxyz-Synchronous-Aluminum-Timing-20-60T-5B-6/dp/B09JWLTBGT/ref=pd_day0fbt_img_sccl_2/137-4032094-1164165?pd_rd_w=aqmx5&content-id=amzn1.sym.a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_p=a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_r=Y25H3PRKQT6J4VJPNCJ8&pd_rd_wg=q1mVC&pd_rd_r=9fa581fd-0b1d-4c12-a2aa-504381926a37&pd_rd_i=B08QYYF6W4&th=1)
11. [Vertical Bearing](https://www.amazon.com/Sydien-Diameter-Mounted-Pillow-Bearing/dp/B07C5MTB5X/ref=sr_1_3?c=ts&keywords=Mounted%2BBearings&qid=1681677196&s=industrial&sr=1-3&ts_id=16411221&th=1)
12. (2x) 5/8"x3" wooden dowel
13. (4x) 5/8"x8" wooden dowel
14. (3x) QN16-f2 buttons (or any equivalent push button)
15. (2x) [3d Printed Wheel](..\3d_models\wheel.stl)
16. (1x) [3d Printed Gear Connector](..\3d_models\gear_connector.stl)
17. (1x) [3d Printed Motor Mount](..\3d_models\motor_mount.stl)
18. (1x) [3d Printed TTGO T1 Mount Top]("..\3d_models\ttgo mount top.stl")
19. (1x) [3d Printed TTGO T1 Mount Bottom]("..\3d_models\ttgo mount bottom.stl")
20. (2x) 1/8"x8"x24" Basswood
21. [String](https://www.amazon.com/gp/product/B00DKA34VE/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
22. Solid Gauge wire
23. [Female to Female wire connectors](https://www.amazon.com/gp/product/B01EV70C78/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)
24. [Female to Male wire connectors](https://www.amazon.com/gp/product/B01EV70C78/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)
25. Breadboard
26. Hot Glue
27. Wood glue
28. Duct tape
29. USB-C cable
30. 80 Grit Sand paper
31. Lillygo TTGO T-1 ESP32
32. 28BYJ-48 5vDC Step Motor with driver board

### Hardware assembly

1. Build the enclosure.
    1. Laser cut the Basswood with the [full box](..\3d_models\full_box.svg)
    design.
    2. Wood glue the 4 sides together.
        1. Player 1 and player 2 side opposite eachother.
        2. Reset side and the side with a small rectangle cut out opposite
        eachother.
    3. Wood glue the 4 sides to the 8"x8" piece with no holes.
    4. Drill 3 holes through the 8" dowels (with a 7/64" drill bit).
        1. Drill 1/2" from the top.
        2. Drill 1" from the top.
        3. Drill 1 1/2" from the top.
    5. Place the dowels in the top of the box.
        1. With the side of the dowels with holes above the box place them
         through the holes in the box and hot glue in place.
    6. Thread the string through the dowels (so it looks like a boxing ring).
        1. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off.
        2. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off.
        3. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off.
    7. Place the 3d Printed TTGO T1 Mount Top in the rectangular hole in the top
    of the box.
2. Mount the wheel gears.
    1. Build the wheel with pulley.
        1. Place one large pulley wheel ~1" onto a 3" dowel from one end.
        2. ~1/4" from the large pulley wheel wrap duct tape around the 3" dowel
        until the 3d Printed Wheel can fit snug on the dowel.
        3. Put the pulley belt over the large pulley wheel.
        4. Place a vertical bearing ~1/2" from the large wheel.
        5. Place a vertical bearing ~1/4" from the large pulley wheel.
        6. Mount the system on the bottom side of the top of the box so the
        wheel fits throught the small rectangular hole and the vertical bearings
        can be affixed with M5x16 screws (side without strings running through
        the dowels). The screw side should face the top of the box and the bolt
        should be on the inside.
    2. Build the wheel without a pulley.
        1. ~1 1/2" from the the end of the 3" dowel wrap duct tape around it
        until the 3d Printed Wheel can fit snug on the dowel.
        2. Place a vertical bearing ~1/2" from the large wheel.
        3. Place a vertical bearing ~1 1/2" from the large wheel.
        4. Mount the system on the bottom side of the top of the box so the
        wheel fits throught the unused small rectangular hole and the vertical
        bearings can be affixed with M5x16 screws (side without strings running
        through the dowels). The screw side should face the top of the box and
        the bolt should be on the inside.
3. Mount the motor.
    1. Affix the motor to the 3d Printed Motor Mount using M3x8 screws and bolts.
    2. Place the 3d Printed Gear Connector on the motor and hot glue it in place.
    3. Attach the small pulley wheel to the 3d Printed Gear Connector.
    4. Pull the pulley belt towards the center of the inside of the box
    (bottom-side of the top of the box) so it is taught. Align the motor so the
    flat side of the 3d Printed Motor Mount is flush against the inside of the
    box and the small pulley gear is pulling the belt taught.
    Mark where the holes of the mount are.
    5. Drill the marked locations (with a 7/64" drill bit).
    6. Affix the 3d Printed Motor Mount to the inside of the box using M3x16
    screws, washers and bolts.
4. Thread the wheels.
    1. Thread one wheel by passing the string through the hole in the wheel then
    wrapping it around the wheel 3x, ensuring that when it rotates the rope
    would pass over the wheel towards the top of the box (the string would come
    out of the hole on the side closest to the edge rather than the center).
    2. Using the same string, ensuring that there is enough excess string,
    thread the second wheel.
        1. Thread the string through the hole.
        2. wrap the wheel in the excess string leaving the loose end hanging
        inside the box.
    3. Tie the two loose ends of the string (one from each wheel) together
    using a
    [Sheet Bend's knot](https://youtube.com/shorts/qEDe_jpvT_I?feature=share)
    to ensure the tension is kept tight.
5. Mount the buttons.
    1. Place a button in each of the 3 cutout holes in the sides of the
    box.
6. Wire the motor and buttons.
    1. Place ESP32 on the 3d Printed TTGO T1 Mount Bottom
    2. Wire the buttons
        1. Use a wire to connect a ground pin from the ESP32 to the breadboard's
        ground.
        2. Ground each of the button's C to the breadboard's ground.
        3. Following the button pins in the code wire the ESP32 to the NO pin of
        each button.
    3. Wire the motor.
        1. Motor's power to the 5V output from the ESP32.
        2. Motor's ground to the ESP32 ground.
        3. Follow the motor pins listed in the code.
7. Mount the ESP32 by clasping the 3d Printed TTGO T1 Mount Bottom to the
3d Printed TTGO T1 Mount Top
8. Thread the USB-C cord through the small rectangular hole through the side of
the box and into the ESP32 and close the box

## References

- [Button Class](https://arduino.stackexchange.com/a/48244)
- [Textbook](https://drive.google.com/file/d/1GLq7iRY_I1D5Fgma1Rd3yVhNt3dg7K0T/view?usp=sharing)
