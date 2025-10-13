/*
** EPITECH PROJECT, 2022
** MyQuadtree
** File description:
** main
*/

#include "include/Quadtree.hpp"

int main()
{
	sf::RenderWindow app( sf::VideoMode( 800, 600, 32 ), "Quadtree" );
	app.setFramerateLimit( 60 );


	sfge::Quadtree quadtree( 0.0f, 0.0f, 800.0f, 600.0f, 0, 3 );

	Object obj1(0, 10, 10, 30, 30);
	Object obj2(1, 41, 10, 30, 30);
	Object obj3(2, 721, 400, 30, 30);
	Object obj4(3, 750, 400, 30, 30);

	std::vector<std::shared_ptr<Object>> ents = {std::make_shared<Object>(obj1), std::make_shared<Object>(obj2), std::make_shared<Object>(obj3), std::make_shared<Object>(obj4)};
	while( app.isOpen() ) {
		sf::Event event;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(app);
		while(app.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if ( event.key.code == sf::Keyboard::Escape ) {
					app.close();
				}
			}
		}
		quadtree.AddObject(ents);
		quadtree.detectCollision();
		app.clear();

		quadtree.Draw( app );
		obj1.Draw(app);
		obj2.Draw(app);
		obj3.Draw(app);
		obj4.Draw(app);
		quadtree.clearQuadtree();

		app.display();
	}

	return 0;
}