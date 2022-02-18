#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.hpp"


int Xor(int value, int tap);
std::string toBinaryString(int n);

int main(int argc, char *argv[]) {
  sf::Image image;
  if (!image.loadFromFile(argv[1]))
    return -1;
  sf::Image Scrambled = image;

  LFSR lfsr(argv[3], atoi(argv[4]));

  // p is a pixel
  sf::Color p;

  sf::Vector2u size = image.getSize();
  sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original Image");
  sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "After LFSR Image");

  int X = size.x;
  int Y = size.y;

  for (int x = 0; x<X; x++) 
  {
    for (int y = 0; y<Y; y++) 
    {
      p = Scrambled.getPixel(x, y);
      p.r = Xor(p.r, lfsr.generate(8));
      p.g = Xor(p.g, lfsr.generate(8)); 
      p.b = Xor(p.b, lfsr.generate(8));
      Scrambled.setPixel(x, y, p);
    }
  }

  sf::Texture texture1;
  texture1.loadFromImage(image);
  sf::Texture texture2;
  texture2.loadFromImage(Scrambled);
  sf::Sprite sprite;
  sprite.setTexture(texture1);
  sf::Sprite sprite2;
  sprite2.setTexture(texture2);

  while (window1.isOpen() && window2.isOpen()) {
    sf::Event event;
    while (window1.pollEvent(event)) 
    {
      if (event.type == sf::Event::Closed)
        window1.close();
    }

  while (window2.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window2.close();
  }

  window1.clear(sf::Color::White);
  window1.draw(sprite);
  window1.display();
  window2.clear(sf::Color::White);
  window2.draw(sprite2);
  window2.display();
  }
	
  if (!Scrambled.saveToFile(argv[2]))
    return -1;
    return 0;
}

int Xor(int value, int tap) {
  std::string Value = toBinaryString(value);
  std::string Tap = toBinaryString(tap);
  int j = 7;
  int num = 0;

  for (int i = 0; i<8; i++) 
  {
    if (Value[i] != Tap[i]) 
    {
      num = num + pow(2, j);
    }
    j--;
  }
  return num;
}

std::string toBinaryString(int n) {
  std::string binary_str = "";
  int number1 = 1;
  for (int i = 0; i < 8; i++) {
    if ((number1 & n) >= 1)
      binary_str = "1" + binary_str;
    else
      binary_str = "0" + binary_str;
    number1 <<= 1;
  }
  return binary_str;
}
