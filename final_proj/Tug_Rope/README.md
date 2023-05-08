# Tug of Rope

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
9. (2x) [large pulley wheel](https://www.amazon.com/Zeberoxyz-Synchronous-Aluminum-Timing-20-60T-5B-6/dp/B09JWLTBGT/ref=pd_day0fbt_img_sccl_2/137-4032094-1164165?pd_rd_w=aqmx5&content-id=amzn1.sym.a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_p=a400618b-650b-4c39-a4fe-66c3e0813a14&pf_rd_r=Y25H3PRKQT6J4VJPNCJ8&pd_rd_wg=q1mVC&pd_rd_r=9fa581fd-0b1d-4c12-a2aa-504381926a37&pd_rd_i=B08QYYF6W4&th=1)
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
31. Lillygo TTGO T-1

### Hardware assembly

1. Making the enclosure
    1. Laser cut the Basswood with the [full box](..\3d_models\full_box.svg)
    design
    2. Wood glue the 4 sides together
        1. Player 1 and player 2 side opposite eachother
        2. Reset side and the side with a small rectangle cut out opposite
        eachother
    3. Wood glue the 4 sides to the 8"x8" piece with no holes
    4. Drill 3 holes through the 8" dowels (with a 7/64" drill bit)
        1. Drill 1/2" from the top
        2. Drill 1" from the top
        3. Drill 1 1/2" from the top
    5. Place the dowels in the top of the box
        1. With the side of the dowels with holes above the box place them
         through the holes in the box and hot glue in place
    6. Thread the string through the dowels (so it looks like a boxing ring)
        1. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off
        2. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off
        3. Thread the rope through each dowel's 1 1/2" hole from the top and tie
         it off
    7. Place the 3d Printed TTGO T1 Mount Top in the rectangular hole in the top
    of the box
2. For the wheel gears
    1. 

## Code Setup

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
