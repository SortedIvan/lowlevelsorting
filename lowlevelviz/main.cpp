#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include <stdio.h>
#include <iostream>
#include <random>
using sf::RectangleShape;


void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color);
int* GenerateRandomNumbers(int min, int max, int size);
void DrawAllBars(int* arrayPointer, int arraySize, sf::RenderWindow& window);

int main()
{
    // Const variables for utility:
    const sf::Vector2i screenSize = sf::Vector2i(1500, 1000);

    sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Bubble Sort");
    sf::Event event;
    const int arraySize = 1500;
    int* randomArrayPtr = GenerateRandomNumbers(5, 100, arraySize);

    for (int i = 0; i < 50; i++) {
        std::cout << randomArrayPtr[i] << std::endl;
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }
        // Drawing
        
        window.clear(sf::Color::Black);
        // Set position in start of the screen
       // Between 1400 and 800
        DrawAllBars(randomArrayPtr, arraySize, window);
        window.display();
    }
    
    return 0;
}

void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color) {
    RectangleShape bar(size);
    bar.setPosition(position);
    bar.setFillColor(color);
    window.draw(bar);
}

int* GenerateRandomNumbers(int min, int max, int size) {
    int* randomNumbers = new int[size];

    for (int i = 0; i < size; i++) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
        randomNumbers[i] = dist6(rng);
    }
    return randomNumbers;
}

void DrawAllBars(int* arrayPointer, const int arraySize, sf::RenderWindow& window) {
    for (int i = 0; i < arraySize - 1; i++) {
        DrawBar(window, sf::Vector2f((sf::VideoMode::getDesktopMode().width - 100) / arraySize, (float)arrayPointer[i] * -10), sf::Vector2f((float)(i * ((sf::VideoMode::getDesktopMode().width - 100 ) / arraySize)), sf::VideoMode::getDesktopMode().height), sf::Color::White);
    }
}














