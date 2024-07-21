#include <iostream>
#include <SFML\Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280,720),"Pong bien chidori");

    sf::Font fuente;
    if (!fuente.loadFromFile("Arial.ttf"))
        return -1;

    int leftScore = 0;
    int rightScore = 0;

    sf::Text leftScoreText;
    leftScoreText.setFont(fuente);
    leftScoreText.setCharacterSize(50);
    leftScoreText.setFillColor(sf::Color::White);
    leftScoreText.setPosition(300.f, 20.f);

    sf::Text rightScoreText;
    rightScoreText.setFont(fuente);
    rightScoreText.setCharacterSize(50);
    rightScoreText.setFillColor(sf::Color::White);
    rightScoreText.setPosition(900.f, 20.f);

    sf::RectangleShape player1(sf::Vector2f(20,300));
    player1.setFillColor(sf::Color::White);
    player1.setPosition(10,150);

    sf::RectangleShape player2(sf::Vector2f(20,300));
    player2.setFillColor(sf::Color::White);
    player2.setPosition(1250,150);

    sf::RectangleShape midLine(sf::Vector2f(6,150));
    midLine.setFillColor(sf::Color::White);
    midLine.setPosition(637,10);

    sf::RectangleShape midLine1(sf::Vector2f(6,150));
    midLine1.setFillColor(sf::Color::White);
    midLine1.setPosition(637,190);

    sf::RectangleShape midLine2(sf::Vector2f(6,150));
    midLine2.setFillColor(sf::Color::White);
    midLine2.setPosition(637,370);

    sf::RectangleShape midLine3(sf::Vector2f(6,150));
    midLine3.setFillColor(sf::Color::White);
    midLine3.setPosition(637,550);

    sf::CircleShape pelota(15);
    pelota.setFillColor(sf::Color::White);

    sf::Vector2f posicion(100.f, 100.f);
    sf::Vector2f velocidadBall(400.0f, 400.0f);
    sf::Vector2f velocidad(200.0f, 200.0f);
    sf::Clock tiempo1;


    while(window.isOpen()){
        sf::Event evento;
        while(window.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                window.close();
            }
        }
        pelota.setPosition(posicion);
        sf::Time elapsed = tiempo1.restart();
        float tiempo = elapsed.asSeconds();
        posicion += velocidadBall * elapsed.asSeconds();


        if (posicion.y < 0 || posicion.y + pelota.getGlobalBounds().height > 720)
        {
            velocidadBall.y = -velocidadBall.y;
        }


        if (posicion.x < 0)
        {
            posicion = sf::Vector2f(640.0f,360.0f);
            rightScore++;
        }
        if (posicion.x + pelota.getGlobalBounds().height > 1280)
        {
            posicion = sf::Vector2f(640.0f,360.0f);
            leftScore++;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player1.getPosition().y > 0)
        {
            player1.move(0.f, -velocidad.y * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player1.getPosition().y + 300 < 720)
        {
            player1.move(0.f, velocidad.y * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player2.getPosition().y > 0)
        {
            player2.move(0.f, -velocidad.y * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player2.getPosition().y + 300 < 720)
        {
            player2.move(0.f, velocidad.y * tiempo);
        }


        if (pelota.getGlobalBounds().intersects(player1.getGlobalBounds()))
        {
            velocidadBall.x = 400;
        }
        if (pelota.getGlobalBounds().intersects(player2.getGlobalBounds()))
        {
            velocidadBall.x = -400;
        }


        leftScoreText.setString(std::to_string(leftScore));
        rightScoreText.setString(std::to_string(rightScore));

        window.clear(sf::Color::Black);
        window.draw(player1);
        window.draw(player2);
        window.draw(pelota);
        window.draw(rightScoreText);
        window.draw(leftScoreText);
        window.draw(midLine);
        window.draw(midLine1);
        window.draw(midLine2);
        window.draw(midLine3);
        window.display();
    }
    return 0;
}
