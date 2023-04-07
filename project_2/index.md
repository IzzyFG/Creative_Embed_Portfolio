---
title: project_2
layout: default
filename: project_2.md
--- 

[>> Back](../../Creative_Embed_Portfolio/)
# Serial Project: [Quiz Game](Quiz_Game/webpage/)

This project in addition to utilizing the TTGO T1 used a joy-stick and button.
I took advantage of the fact web-browsers can listen for serial input on ports
using javascript and created a
[basic website](./project_2/Quiz_Game/webpage/)
to display the input. With limited ability to create larger scenes in HTML/JS I
decided to create a simple quiz/trivia game that the user can choose from 1 of 4
topics for.

## [Technical Documentation](https://github.com/IzzyFG/Creative_Embed_Portfolio/blob/04b4d150e2a33755a646f14974aebe55d05a7d08/project_2/Quiz_Game/README)


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

## Enclosure

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
