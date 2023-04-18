// Copyright (c) Arturo Vilar Carretero
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.4

#include "Geometry.hpp"
#include "Collision_manager.hpp"

int main ()
{
    RenderWindow window(VideoMode(800, 600), "Interpolation", sf::Style::Default, ContextSettings(32));

    window.setVerticalSyncEnabled (true);

	Circle circle					(50.f, { 150.f, 240.f }, 5.f);
	Circle circle2					(50.f, { 350.f, 240.f }, 5.f);
	Wall square_left				(20.f, 1000.f, { 0.f, 0.f });
	Wall square_right				(20.f, 1000.f, { 780.f, 0.f });
	Wall square_floor				(1000.f, 20.f, { 0.f, 580.f });
	Collision_manager c_manager;

    bool running = true;

    do
    {
        // Process window events:

        Event event;

        while (window.pollEvent (event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
        }

		// Update:

		// ACTUALIZAR FÍSICA AQUÍ

		circle.update (.01666666f);
		circle2.update(.01666666f);

		c_manager.check_circle_sides(circle, square_floor, square_right, square_left);		// CIRCLE 1 FLOOR
		c_manager.check_circle_sides(circle2, square_floor, square_right, square_left);		// CIRCLE 2 FLOOR		

		c_manager.check_circle_circle(circle, circle2);										// DOUBLE CIRCLE

        // Render:

        window.clear ();

        // DIBUJAR AQUÍ

		circle.draw (window);
		circle2.draw(window);
		square_left.draw (window);
		square_right.draw(window);
		square_floor.draw(window);

        window.display ();
    }
    while (running);

    return EXIT_SUCCESS;
}
