# CppProject1_BubbleSortVis
 
My first working project for a 2 week C++ learning session I have done.

Here is a quick preview of the project.

![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/67654528/114593051-9175d700-9c83-11eb-86c7-02e45afcbdfe.gif)


Youtube link-
-- https://youtu.be/MS-q5rTBMjw


This uses the SFML library.
-- I think its the 64bit Visual Studio 15 one.


Setup -
 (This is for myself in the future)

Go into Project Properties-
Select all Configurations
 In C++ -> Additional Include Dicts add "c:\SFMLVS\INCLUDE"
 In Linker -> Additional Library Dicts "c:\SFMLVS\lib"
    In Linker, Linker Input -> Additional Dependencies "sfml-window.lib;sfml-system.lib;sfml-graphics.lib;sfml-audio.lib;sfml-network.lib;"
    
 Apply <-
 Go into Debug Configuration
 In Linker, Linker Input -> "sfml-window-d.lib;sfml-system-d.lib;sfml-graphics-d.lib;sfml-audio-d.lib;sfml-network-d.lib;"


After that get SFMLVS Bin .dlls and add into solution with CPP files.
--> Run
