#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

using sf::RectangleShape;

struct Bar {
    float x_size;
    float y_size;
    float x_pos;
    float y_pos;
};

void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color);
int* GenerateRandomNumbers(int min, int max, int size);
void DrawAllBars(int* arrayPointer, int arraySize, sf::RenderWindow& window, sf::Color color, Bar* arrayWithBars);
bool CheckKeyPressed(sf::Keyboard::Key key);
void BubbleSort(int* arrayPointer, int arraySize, sf::RenderWindow& window, Bar* all_bars, bool& array_sorted);

int main()
{
    // Const variables for utility:
    const sf::Vector2i screenSize = sf::Vector2i(1500, 1000);
    sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Bubble Sort");
    sf::Event event;
    int arraySize = 200; // Array size represents the amount of numbers/bars on the screen
    int* randomArrayPtr = GenerateRandomNumbers(5, 100, arraySize);
    bool sort = false;
    bool array_sorted = false;

    Bar* all_bars = new Bar[arraySize];

    while (window.isOpen()) {
        
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (CheckKeyPressed(sf::Keyboard::Key::Enter)) {
                std::cout << "works" << std::endl;
                sort = true;
            }
        }

        if (!array_sorted) 
        {
            if (!sort) {
                DrawAllBars(randomArrayPtr, arraySize, window, sf::Color::White, all_bars);
                window.display();
                continue;
            }
            window.clear();
            BubbleSort(randomArrayPtr, arraySize, window, all_bars, array_sorted);
            DrawAllBars(randomArrayPtr, arraySize, window, sf::Color::Green, all_bars);
            window.display();
        }


    }
    
    return 0;
}

void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position, sf::Color color) {
    RectangleShape bar(size);
    bar.setPosition(position);
    bar.setFillColor(color);
    bar.setOutlineColor(sf::Color::Blue);
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

void DrawAllBars(int* arrayPointer, int arraySize, sf::RenderWindow& window, sf::Color color, Bar* arrayWithBars) {

    for (int i = 0; i < arraySize; i++) 
    {
        float screenX = 1500.f;
        float screenY = 1000.f;

        if (i == arraySize - 1) { // Last element must be a further into the screen
            DrawBar(window,
                sf::Vector2f(screenX / arraySize, -(screenY * (arrayPointer[i] / 100.f))),
                sf::Vector2f(screenX - (screenX / arraySize), screenY),
                color);
            Bar bar = { screenX / arraySize ,-(screenY * (arrayPointer[i] / 100.f)), screenX - (screenX / arraySize), screenY };
            arrayWithBars[i] = bar;
            continue;
        }
        DrawBar(window,
            sf::Vector2f(screenX / arraySize, -(screenY * (arrayPointer[i] / 100.f))),
            sf::Vector2f(i * (screenX / arraySize), screenY),
            color);
        Bar bar = { screenX / arraySize ,-(screenY * (arrayPointer[i] / 100.f)), i * (screenX / arraySize) , screenY};
        arrayWithBars[i] = bar;
    }
}

bool CheckKeyPressed(sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(key)) {
        return true;
    }
}

void BubbleSort(int* arrayPointer, int arraySize, sf::RenderWindow& window, Bar* all_bars, bool& array_sorted) {
    float screenX = 1500.f;
    float screenY = 1000.f;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < arraySize; i++) {
            DrawBar(window,
                sf::Vector2f(all_bars[i].x_size, all_bars[i].y_size),
                sf::Vector2f(all_bars[i].x_pos, all_bars[i].y_pos),
                sf::Color::Green);
            DrawBar(window,
                sf::Vector2f(all_bars[i - 1].x_size, all_bars[i - 1].y_size),
                sf::Vector2f(all_bars[i - 1].x_pos, all_bars[i - 1].y_pos),
                sf::Color::Green);
            window.display();
            if (arrayPointer[i - 1] > arrayPointer[i]) {
                sorted = false;
                int temp = arrayPointer[i];
                arrayPointer[i] = arrayPointer[i - 1];
                arrayPointer[i - 1] = temp;
                DrawBar(window,
                    sf::Vector2f(all_bars[i - 1].x_size, all_bars[i - 1].y_size),
                    sf::Vector2f(all_bars[i - 1].x_pos, all_bars[i - 1].y_pos),
                    sf::Color::Green);
                window.display();
                window.clear();
                DrawAllBars(arrayPointer, arraySize, window, sf::Color::White, all_bars);
                window.display();
                //std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
    }
    array_sorted = true;

}










