---
title: final_proj
layout: default
filename: index.md
--- 

[>> Back](../../Creative_Embed_Portfolio/)

[Technical Documentation](https://github.com/IzzyFG/Creative_Embed_Portfolio/tree/main/final_proj/Tug_Rope#readme)

# Final Project: Tug of War

This project was inspiried by the Rock-em-sock-em kids game. Rock-em-sock-em has
so many moving pieces, I thought it would be impractical to create a motorized
version of it. Instead I wanted to build something with the same amount of
drama it represented. At summer camp we would have a camp wide tournament at the
end of the summer with one of the main activities being a Tug-Of-War game.
It was one of my favorite activities and to us it had the same amount of drama
and tension as a WWE fight, if not more. It meant winning or losing the entire
summer. Using motors, buttons, and gears to "pull" the string towards a player,
to win the game.

## Difficulties in Project

The Tug of War game is by far the most complicated project I completed for this
class, it has 3 moving parts that all work in tandem and had to be precisely
fitted in the enclosure. In addition to 3 buttons that had to be checked at
precise moments accounting for players pressing the buttons at the same time.

I had many issues implementing interrupts in the code, one of the most
frustrating was sprintf breaking the code. I spent a long time debugging until I
discovered in a forumn that sprintf for some unknown reason can cause ESP32's to
crash. Additionally in using interrupts the console log cannot be used, in
attempting to debug the code with console log prints I discovered I was actually
causing the code to fail. Similarly, adjusting the flag variables back to false
took a lot of trial and error with `noInterrupts()` and `interrupts()`, because
if placed at the wrong location it would cause the ESP32 to crash.

Hardware was definetly the hardest part of this project. I've never built a
project that had moving pieces to it, planning how it was going to look inside
and how everything interacted took many hours of drawing diagrams and
prototyping. The box's material was too thin and difficult to glue together
without warping, the holes in the wheels I 3d printed were too big, and the
gears ordered for the project were not specific to the motor I was using which
meant I had to create a custom fitted adapter for the project.

## Enclosure

The enclosure itself was fairly straight forward, just a simple box with holes
cutout to attach the various components to.

<img src = "images\PXL_20230508_171759294.jpg" alt="left side enclosure" width = "65%" height = "65%">

<img src = "images\PXL_20230508_171743416.jpg" alt="right side enclosure" width = "65%" height = "65%">

The wiring of the project, and the enclosure internals were signficantly harder
and more complicated.

<img src = "images\PXL_20230508_185436638.jpg" alt="enclosure internals" width = "65%" height = "65%">

<img src = "images\PXL_20230508_185444940.jpg" alt="enclosure top" width = "65%" height = "65%">

## Video

[![](https://markdown-videos.deta.dev/youtube/HDft4lnsOyw)](https://youtu.be/HDft4lnsOyw)
