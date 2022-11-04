#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;
bool gameover = false , win = false;
float speed = 0,angle =0,pi=180;
float movementx,movementy,dy=0.5;;
int main()
{   Texture plane1,plane2,shape1;
    plane1.loadFromFile("C:/Users/moham/OneDrive/Desktop/rocket_1f680 (1).png");
    plane2.loadFromFile("C:/Users/moham/OneDrive/Desktop/rocket_1f680 (1).png");
    shape1.loadFromFile("C:/Users/moham/OneDrive/Desktop/moreearthfromspace.jpg");
    Sprite Rocket(plane1),background(shape1);
    RenderWindow app(VideoMode(1187,641), "Space");
    app.setFramerateLimit(60);
    Rocket.setPosition(rand()%1200,rand()%150);
    Rocket.setOrigin(50,87.5);

    while (app.isOpen())
    {
        Event e;

        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                {app.close();}
            if (Keyboard::isKeyPressed(Keyboard::Right) && angle <=44) {
                    angle=angle+1;
                    Rocket.rotate(+1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) && angle >=-44) {
                    angle=angle-1;
                    Rocket.rotate(-1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)&& speed <0.5) speed=speed+0.15;

            if (Keyboard::isKeyPressed(Keyboard::Down)&& speed >0) speed=speed-0.15;
        }

        //logic
        if(speed == 0) {Rocket.setTexture(plane1);}
        if(speed >= 0.15) {Rocket.setTexture(plane2);}
        Rocket.move(0,dy);
        movementx= +abs(speed*sin((180/3.14)*angle));
        movementy= -abs(speed*cos((180/3.14)*angle));
        if (Rocket.getPosition().x<=0-100) {Rocket.setPosition(sf::Vector2f(50,Rocket.getPosition().y));}
        if (Rocket.getPosition().y<=0+87.5) {Rocket.setPosition(sf::Vector2f(Rocket.getPosition().x,87.5));}
        if (Rocket.getPosition().y>=640-87.5) {Rocket.setPosition(sf::Vector2f(Rocket.getPosition().x,640-87.5));}
        if (Rocket.getPosition().x>=1024-50) {Rocket.setPosition(sf::Vector2f(1024-50,Rocket.getPosition().y));}
        if(angle<=0)
        {
        Rocket.move(-movementx,movementy);
        }else{
        Rocket.move(movementx,movementy);
        }

        app.clear();


        if (gameover == true)
        {
            app.draw(background);



        } else if (win == true)
        {

        }

        else{
        app.draw(background);
        app.draw(Rocket);
        }
        app.display();


    }
    return 0;
}
