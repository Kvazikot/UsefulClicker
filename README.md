This project is licensed under the terms of the GNU General Public License v3.0

  + - - - + - + - -
  + - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
  + - + - + email: vsbaranov83@gmail.com  <br>
  + - + - + github: http://github.com/Kvazikot/BallPark  <br>
```
                            )            (
                           /(   (\___/)  )\
                          ( #)  \ ('')| ( #
                           ||___c\  > '__||
                           ||**** ),_/ **'|
                     .__   |'* ___| |___*'|
                      \_\  |' (    ~   ,)'|
                       ((  |' /(.  '  .)\ |
                        \\_|_/ <_ _____> \______________
                         /   '-, \   / ,-'      ______  \
                b'ger   /      (//   \\)     __/     /   \
                                            './_____/
```             
## About Useful Clicker
The UC program is intended for programming user actions.
For example, to automatically search for materials in youtube and download certain videos.
The program has a built-in computer vision functionality, i.e. it can identify the buttons on the screen by analyzing the pixels in the image.
In this sense, it works similar to how the retina of an animal's eye works.
The buttons are highlighted in green in the style of augmented reality.

## New concept for Useful Clicker (3/28/2022)
The program must recognize the context. Those. which window is currently on the screen, which buttons are on the screen.
It circles all the buttons in green, and the button to be clicked in red.
He also signs the sequence number of the action next to the button.
All this can be arranged in a full-screen semi-transparent widget.
The "Next Frame" and "Previous Frame" buttons at the top of the screen.
That is, the clicker also works in the clicker programming mode. To return the previous window e.g.
## The idea for an astronomical number of screenshots for reverse engineering human software (came from Marvell comics)
We need to create an astronomical number of screenshots for all sorts of programs and operating systems.
Each dialog box is unique to the program. Therefore, the clicker will be oriented towards reverse engineering of traditional software.
Soon, according to the idea of ​​Elon Musk, all traditional software i.e. the expertise of some engineer will replace neural networks.
But we need to prepare a description of the functions of every program on Earth that has ever existed.
So that the future AGI can use these compiled programs for its calculations.
So that he does not need to invent the wheel, roughly speaking
Since AGI thinks orders of magnitude faster than humans, it will be able to use human software
in such interesting combinations that people never even dreamed of. But this information should be available.
In order not to waste time on reverse engineering.
Perhaps at some stage AGI will be able to explore various software written by people.
By disassembling it.
To do this, I provided the Function Description window, which a person must fill out.
  
This idea is explained in more detail in the next video.
https://youtu.be/BYM5G5CIgS8

## Reformulation of the problem (5/6/2022) . Few new thoughts. 
Check UsefulClicker on noisy data. 
This is related to interactive mode there clicker is mirrors user event but with a small delay.
* 1. Try to predic there user is about to click next second or more. The possible mathematical models can be: inverse reinforcment learnong, CNN 
* 2. MicroRecorder suppose to do several things 
  * a) Record mouse
  * b) Record voice and extract text from audio signal
  * c) Record keyboard events
  * d) Record screen with interactive button recognition
* 3. Find youtube videos with tutorials on most popular programs for solving common problems on computer like Microsof Excel
* 4. Try to replay tutrial based only on video data from youtube.
* 5. Develop a plugin that invoke some video search for a particular tutorial. Maybe embed youtube search in UC interface.
* 6. You probably need connect some decentralised blockchain based database of tutorials and make team working support (like Discord)

The UsefulClicker in its development stage project right at the point of collecting vast amount of data.
So since this is a toy project and it respects ai aligment problem. 
I have to write some security requerments at this early stage.
Inteligence can be a harmful weapon.
Next stage is actualy has more teoretical than practical sense at this point.


## Compression
It is necessary to make such programs for the clicker so that they take up a minimum of bytes and do a maximum of useful work. It is possible to add additional information so that it can be restored in case of errors in the communication channel. Here you can compress the information using not only artificial neural networks, but also the slightly forgotten information theory of Claude Shannon's [1]. 

## Short UC code
It neccessary to implement short one string encoding of clicker instructins.
For the small band-width communicatioons like brain net.
```  
<!-- example of short program for Useful Clicker
xy,140:122,ctrl+f,"banana republic gdp",enter,cr,56,cb,"next"
```  
xyl,140:122 - mouse click, left button in point with coordinates (140,120) <br/>
cr,56 - click rectangle object on the page with number #56 <br/>
cb,"next" - click "next" button  <br/>
  
# Macro recording with code generation of optimal xml code,
  * input: for which mouse trajectory and keyboard events.  
  * output: minimal xml code, preferably with human-readable content
  ```
  <window template="notepad_template.png"/>
  <menuclick> File -> Open </menuclick>
  <inputline>readme.txt</inputline>
  ```
  
# XML document sheme for Useful Clicker 0.91. Sort of meta language (Language of languages)
  
```  
<!-- 
when launching UsefulClicker the following environment variables are set
UsefulClicker_xml = "(CWD)\xml" - directory where it looks for include
UsefulClicker_scripts = "(CWD)\scripts" - directory where it saves scripts from this scheme
UsefulClicker_settings = "%APPDATA%\Roaming\UsefulClicker"
-->

<!--         INCLUDE DERECTIVE          -->
<include> sheme1.xml </include>
<include> sheme2.xml </include>

<!--         CODE BLOCK(PYTHON, C++, etc)          -->
<code source_name="block.py" lang="python" >
  import random
  print( random.randint(0, 13) )
</code> 

<!--         SHELL CODE BLOCK(bash, cmd etc)          -->
<shell name="cmd" bg="1" showConsole="1"> start / B date </shell>
 
 <!--         RUN PYTHON FUNCTION          -->
 <py_call name="pyFunctionName($(arg1))"/>  
 
 <!--         FUNCTION CALL           -->
 <call name="SetUrl" arg0="https://www.hh.ru" comment="set hh url" />
 
 <!--         FUNCTION DEFINITION           >
 <!-- every function is inialised global python variables arg0, arg1 etc  --> 
  
  <func name="Type test 2">
   <shell bg="1" showConsole="1" hotkey="ctrl + a" cmd="notepad.exe" comment="run notepad"/>
   <type mode="copy_paste" text="This is an example of text that was generated by UsefulClicker today. " />
  </func>
  
  <!--         CONDITION           >
 <if var1=regexp(var1,"[\d]+")> 
 <if var1="1" var2="1" op="and"></if>
 <if var1="1" var2="1" op="or">
 <goto id="nodeid"/>
 <break/>
 <clicktext text="Type here to search">
 </if>  
 <else> </else> 
 <pyblock>
   if var1 == "1":
      call("Type test 2")
   else:
     show_message("not found");
 </pyblock>
 
 
  <func name="Change font">
   <click button="left" x="1531" y="661" />
   <hotkey hotkey="alt+o"/>
   <hotkey keysequence="f" delay_ms="100"/>
   <hotkey hotkey="alt+s" delay_fixed="500"/>
   <type text="48" />
   <hotkey keysequence="enter" delay_ms="100"/>
   </func>
  
  <func name="Post Twit">
    <click button="left" x="1700" y="416" comment="click in chrome window" />
    <hotkey hotkey="F6"/>
    <type text="https://twitter.com/" />
    <hotkey keysequence="enter" delay_ms="1000"/>
    <clickimg targetImg="$(UsefulClicker)/images/18.10.45.400.png" button="left" delay_fixed="1000"> </clickimg>
    <type text="This is an example of the text generated by UsefulClicker today." delay_fixed="1000"/>
    <clickimg targetImg="$(UsefulClicker)/images/18.01.05.902.png" button="left"> </clickimg>
    <hotkey keysequence="enter" delay_ms="1000"/>
  </func>
  ````
  
  
  


## Disadvantages of Auto Mouse Clicker by MurGee

What would you like to improve in a clone of the program with the working name UsefulClicker?

0. Not free
1. works only under Windows (platform-dependent limitation of free will)
2. Lack of full export in csv format.
In particular, the inability to save Hot Key combinations is frightening.
2. You cannot run multiple scripts within the same process.
For example, viewing mail, then arbitrary switching of a circular search in YouTube, etc.
2.1 There is no concept of procedure or function in the program.
In the action table, I cannot collapse the actions into a closure and name it somehow.
And then make a place for the main loop at the bottom of the action table

3. There is no script export to any of the known programming languages, in particular
visual basic.
4. The action dropdown menu is too large. I would limit myself to the following (see [LA1]).
5. You cannot move multiple actions in the list.
6. You can not copy paste the lines of the table \ script
7. Actions go to the end of the list, not to the selection.
8. NOT GPU optimized
9. No image search at different scales.
10. You can not change comments directly in the table
11. There are NO built-in comboboxes in the table, for example, to change Scroll up to Scroll Down
12. No conditional jumps
13. No variables
14. Doesn't understand environment variables like %TMP%
15. No goto statement
16. No arithmetic functions
17.
12 - 17 deficiencies relate to clicker instructions.
(maybe more it's intentionally made more predictable scripts)
all of the following things can be done in an external script


[LA1] List of actions
--------------------------------
*Hot key
*Press Key
* left click
* right click
* Scroll down
* Scroll up
* launch program
* Image search
*Type Comment

# Problems
1. Existing scripts that I wrote as part of R&D cannot be converted to open source without a valid license.
You should take the time to rewrite them in UsefulClicker.
Or make it backwards compatible with AMC, it all depends on whether there will be a connection with the Indian support department.
I don't think he will like this idea.

# Possible features
1. Automatic search for buttons without the need to outline them in a rectangular pixel area
2. Automatic recognition of web page markup or form areas such as widgets.
3. Recognition of text areas and areas with pictures as OCR systems
Method for searching text by histogram. The text is divided into rectangular areas, then they are discarded when searching for the target image.
Later, if you really want, you can add cnn for text recognition.
But first, the system must highlight the buttons and give them a serial number.
After that, the user selects the already highlighted areas with the mouse, and does not select the areas with a rectangle like an Indian.
5. Built-in interpreter, lua, python, vbs. Inserting Python code into table cells.
6. Excel can also be considered, especially if you move towards data science.
7. An interesting idea is the self-learning of the clicker according to the actions of the operator (such as child mode, grandmother mode). At AMC, this is called MacroRecorder. But it is important that he somehow segments the actions into separate records.
8. Well, immediately the recognition of the user itself by typing speed, characteristic mouse movements, etc. immediately comes to mind. But this is already a task for the Third Reich, and not for me. I'm not going to get my hands dirty.
 
10. Make a plugin-like environment inside UsefulClicker
11. We need to make some kind of protection from the Reich :) I already did - all the codes are open, except for Windows and Python. And so everything is open.
12. RegEx function as in AMC, but with the goto operator.
13. Embed the mingw compiler into the system for writing C++ code in the form of plug-in dll plugin modules. This will give a boost in speed if the developer requires it.
14. Clicker scripts will be stored in DomModel. XML Schema
15. XML schemas can be nested within each other.
16. In the XML schema, you can include script code in Python and BASIC
17. To edit a script in Python or BASIC, Notepad ++ will be used in the first couple
18. That is, I will still build the Python interpreter into the plate. That is, there will be a type of calculated or interpreted cells.
19. The program will have three types of export. XML Schema. A set of scripts. And export to a single Python script that works regardless of the clicker.
20. The script tag <script> </script> needs to be reparsed so that you can see the lines without zaparok with tabs in the case of a Paton.
21. Obfuscate strings if required by the developer
22. Make a binary export
23. When importing from an xml schema, all <script> tags are saved in separate .py files in the scripts directory
24. OCR of all areas found by ButtonDetector, for example, using the transformer https://huggingface.co/docs/transformers/model_doc/trocr

## Screenshots 
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/screenshots/buttons_detector_screenshot.png)

fig.1 Button detector

![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/screenshots/delay_widget.png)

fig.2 Widget for setting delays

![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/screenshots/xml_editor_screenshot.png)

Fig.3 Clicker program editor in the form of an xml tree.

![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/screenshots/mainwindow_0.92.png)

fig.4 The editor of the clicker program in the form of an xml tree with pictures on the right.

![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/screenshots/testform_0.92.png)

fig.5 Cool test program

# This is my scetches for cv part of UsefulClicker.
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/galaxy_cluster_shitt.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/path_matcher_idea.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/quad_tree_clustering.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/spiral_idea.png)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/cnn_for_button_detection.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/page_segmentor.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/button_cnn_clasifer.jpg)
![image](https://github.com/Kvazikot/UsefulMacro/blob/master/UsefulClicker/cv/sketches/android_port_qpython.jpg)

  
## References
* THE MATHEMATICAL THEORY OF COMMUNICATION CLAUDE E. SHANNON, WARREN WEAVER
* Engineering a Compiler (Keith Cooper, Linda Torczon) 
* CS 61B - Data Structures - Jonathan Shewchuk
