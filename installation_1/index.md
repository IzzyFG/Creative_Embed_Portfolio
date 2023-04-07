---
title: installation_1
layout: default
filename: index.md
--- 
[>> Back](../../Creative_Embed_Portfolio/)

# Project 1: Words and More Words

This project was intended as an introduction to microcontrollers, Arduino IDE
and embedded systems/design. I decided to display on the microcontroller the most
commonly used words in the English Language in a randomized order with the font
size representing the frequency of use (i.e. the larger the word the more often
it used).

I faced quite a few technical issues throughout this project, figuring out how
to create new fonts of various sizes was a major one. I went through multiple
different methods of making fonts and using custom fonts, and ensuring that the
code could all be uploaded without using a shared filesystem limited my ability
to create fonts. I found the simplest way was to use the freefonts already given
but create new ones of various sizes instead of scaling the size itself in
print statements (to avoid pixelation).

Another issue that I faced in using so many words is the size of the lists
themselves, I discovered when flashing the ESP32 that if the list size was too
big the code would be unable to upload. Related I found using a simple scale
to weight the font size with the frequency of the word spoken in English led to
a very limited amount of words being displayed larger than 5. It was important
to the vision I had of the project that the words' size would feel more
representative of the frequency, if 460 of the words are all size 1-3 then
there's no diference seen between them. I decided to instead weight each
quartile range in groups to lead to better visualization.

## [Technical Documentation](https://github.com/IzzyFG/Creative_Embed_Portfolio/blob/main/installation_1/README.md)
