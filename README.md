# SeaLion

The project SeaLion is a C++ implementation of a RTSG (<i>Real Time Strategy Game</i>) naval battles using the SFML library (see SFML repository: https://github.com/SFML/SFML.git).
## Intro

Sealion is a video game project created to learn modern C ++ characterized by design models such as Factory, Observer, Strategy, Model-View-Controller, some functional paradigms, object-oriented paradigms, generic templates, smart-pointers, interface - oriented and polymorphic programming. To achieve the stability and reliability of the code we have surrounded our project with Unit Testing code by choosing the Google Test engine for it. Finally we ran Google Sanitizer.
## Gameplay and Functionalities

### Basics
SeaLion starts with a randomly generated map and two fleets, each of which can be American, British, Japanese or Italian. The goal is to destroy all the enemy
ships using the weapons at your disposal, in particular: battleships, crusaders, destroyers, aircraft carriers and submarines. You can select a ship by simply clicking on it, then move it by selecting the destination point, but watch out for the obstacles scattered on the map!
Some ships have special weapons, just click the button and select the enemy ship to attack it.
As for combat, ships have three different types of guns (light, medium, heavy) which all have a different range and different types of firing projectiles with different penetration and damage capabilities; they are able to turn in the right direction by triangulating and automatically firing at the nearest ship, but only if the target is within range.As for the menu, the selection of your and enemy fleet via menu interface, the enemy algorithmic intelligence and the possibility of firing torpedoes from submarines, will be added as soon as possible, time allow.
### Movement Mechanics and Obstacles
Firstly click on one of your ships and then click on the destination point and it can happen that:
<ul>
  <li>Two ships collide and get stranded </li>
</ul>

![SeaLion](/Res/ShipCollision.gif)

<ul>
  <li>The ship collides with an island getting stranded</li>
</ul>

![SeaLion](/Res/IsleCollision.gif)

<ul>
  <li>The ship passes over a reel, suffering damage over time  </li>
</ul>

![SeaLion](/Res/Wirpool.gif)

<ul>
  <li>The ship passes through a fog bank, so it cannot be hit by ships outside the fog but the ship itself can strike outside of it  </li>
</ul>

![SeaLion](/Res/Fog.gif)

<ul>
<li>The combat phase of the cannons is achieved thanks to projectiles and cannons that working together create an optimal balance considering the penetration of the armor and the firing dynamics such as dispersion, accuracy on the target and types of projectiles. The guns are able to detect the closest ships, so the guns rotate in the right direction to fire bullets at the enemy.</li>
</ul>

![SeaLion](/Res/Combat.gif)


<ul>
  <li>In addition to cannons, aircraft carriers are able to use airplanes to hit and sink enemy warships</li>
</ul>

![SeaLion](/Res/Airplanes.gif)



## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.




