# SeaLion

The project SeaLion is a C++ implementation of a RTSG (<i>Real Time Strategy Game</i>) naval battles using the SFML library (see SFML repository: https://github.com/SFML/SFML.git).

## Gameplay and Functionalities

### Basics
SeaLion starts with a random generated map and two fleets, each of wich can be Italian, American, English or Japanese. The objective is to destroy all the enemy 
ships using the weaponry at your dose, in particular: battleships, crusaders, destroyers, aircraft carriers and submarines. You can select a ship just clicking on it, and then move it selecting the destination point, 
but be aware of the obstacles spread on the map!
Some ships have special weapons, just click the button and select the enemy ship to attack it. 
As for combat, ships have cannons capable of hitting the nearest ship automatically, but only if the target is within range.
### Movement Mechanics and Obstacles
Firstly click on one of your ships and then click on the destination point and it can happen that:
<br>
<br>
<b> • </b> Two of your ships collide
<p>
      <img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="200" height="200" > </img> 
</p>

<b> • </b> Your ship collides an island
<p>
      <img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="200" height="200"> </img> 
</p>

<b> • </b> Your ship runs into a whirlpool 
<p>
      <img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="200" height="200"> </img> 
</p>

<b> • </b> Your ship runs into rough sea
<p>
      <img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="200" height="200"> </img> 
</p>

<b> • </b> Your ship hides into fog bank
<p>
      <img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="200" height="200"> </img> 
</p>

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
