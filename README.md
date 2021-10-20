# SeaLion

The project SeaLion is a C++ implementation of a RTSG (<i>Real Time Strategy Game</i>) naval battles using the SFML library (see SFML repository: https://github.com/SFML/SFML.git).
## Intro
Sealion in a videogame project realized in order to learn modern C++11 featured of design pattern like Factory,Observer,Strategy,Model-View-Controller, some functional paradigm,  object-oriented paradigm, generic template, smart-pointers, interface-oriented and polymorphic programming.To achive code stabilty and code reliability we surrounded our project with Unit Testing code choosing Google Test engine for it.Finally we have runned Google Sanitizer for detecting and eliminating eventual memory leak.
## Gameplay and Functionalities

### Basics
SeaLion starts with a random generated map and two fleets, each of wich can be Italian, American, English or Japanese. The objective is to destroy all the enemy 
ships using the weaponry at your dose, in particular: battleships, crusaders, destroyers, aircraft carriers and submarines. You can select a ship just clicking on it, and then move it selecting the destination point, 
but be aware of the obstacles spread on the map!
Some ships have special weapons, just click the button and select the enemy ship to attack it. 
As for combat, ships have cannons capable of hitting the nearest ship automatically, but only if the target is within range.
As regards the menu and the selection of your and enemy fleet will be added as soon as possible like enemy algoritmic intelligence and the possibility to shoot torpedoes from submarines.
### Movement Mechanics and Obstacles
Firstly click on one of your ships and then click on the destination point and it can happen that:


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
