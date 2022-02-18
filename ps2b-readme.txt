Name: Shivang Patel

SFML.cpp and SFML.hpp was same we used in PS2a. Main file PhotoMagic.cpp takes fore arguments. 
An image, a string of 1s and 0s, and a tap location.

sf::Color p; this means program gets tree colors, the red, blue and green values as a 8 bit binary 
number for every pixel of image. Then, function Xor takes pixel 8-bit value and calls the generate 
function as arguments. Pixel get new value. This is how image can be encoded or decoded.
