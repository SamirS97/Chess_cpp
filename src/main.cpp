#include "Game.hh"
#include <vector>
using namespace sf;
using namespace std;




int main()
{
    RenderWindow window(VideoMode(1276, 1276), "MAIN Chess");

	int clic = 1;
	pair<int,int> Start;
	pair<int,int> Target;
	
	Game G;
	G.Set_Board();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {

					if (clic == 1) 
					{
						Start = G.Change_Scale(event.mouseButton.y,event.mouseButton.x);
						clic = 2;
					}
					
        			else {
						Target = G.Change_Scale(event.mouseButton.y,event.mouseButton.x);
						G.GetNextMove(Start,Target);
        				clic = 1;
        			}
    			}
			}
                  
		}
	window.clear();
	G.Set_Board();
	G.Draw_Chess(window);
 	window.display();
	}


    return 0;
}

