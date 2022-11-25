#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols

using sf::RectangleShape;


void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position);

int main()
{
    const sf::Vector2i screenSize = sf::Vector2i(1500, 1000);
    const sf::Color& color = sf::Color(0, 0, 0, 255);
    sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Bubble Sort");
    sf::Event event;

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
        
        DrawBar(window, sf::Vector2f(100.f, 200.f), sf::Vector2f(0.f, 800.f));
        DrawBar(window, sf::Vector2f(100.f, 200.f), sf::Vector2f(110.f, 800.f));
        DrawBar(window, sf::Vector2f(100.f, 200.f), sf::Vector2f(220.f, 800.f));
        DrawBar(window, sf::Vector2f(100.f, 200.f), sf::Vector2f(330.f, 800.f));
        DrawBar(window, sf::Vector2f(100.f, 200.f), sf::Vector2f(440.f, 800.f));



        window.display();
    }
        
    return 0;
}

void DrawBar(sf::RenderWindow& window, sf::Vector2f size, sf::Vector2f position) {
    RectangleShape bar(size);
    bar.setPosition(position);
    window.draw(bar);
}










