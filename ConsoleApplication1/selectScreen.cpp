
sf::Sprite spriteSel;

int sel(){
	
}

void loadSel(){
	sel();

	
	
	while (window->isOpen())
	{
	    sf::Event event;
	    while (window->pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	        {
	            window->close();
	            break;
	        }
	    }
	}
}