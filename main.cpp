#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "Globals.h"
#include <list>

#include "GameObject.h"
#include "Tank.h"
#include "Round.h"
#include "Soldier.h"
#include "Globals.h"

//*Globals*//
const int  FPS = 60;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
bool keys[5] = { false, false, false, false, false };

std::list<GameObject *> gameObjects;
std::list<GameObject *>::iterator iter;
std::list<GameObject *>::iterator iter2;

int main()
{
   //*Game Variable*//
   const int  FPS = 60;
   bool redraw = false;
   bool finished = false;

   //*Allegro variables*//
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_EVENT event;

   //*Initialization Functions*//
    if( !al_init() )
	   return -1;

   display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT); //create display object

   //*Allegro addons*//
   al_init_primitives_addon();
   al_install_keyboard();

   //*Initiate tank*//
   Tank *tank;
   tank = new Tank();
   tank -> initiate();
   gameObjects.push_back(tank);

   //*Initate timer*//
   timer = al_create_timer(1.0 / FPS );
   srand(time(NULL));
   al_start_timer(timer);

   //*Create event queue & register sources*//
   event_queue =  al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_timer_event_source(timer));



//*Game Loop*//
   while(!finished)
   {
	   //*Wait until event queue is not empty*//
	   //*copy first event in queue to event variable*//
	   al_wait_for_event(event_queue, &event );

	   //*Check Input events*//
	   if(event.type == ALLEGRO_EVENT_KEY_DOWN)
	   {
		   switch(event.keyboard.keycode)
		   {
		   case ALLEGRO_KEY_ESCAPE:
			   finished = true;
			   break;
		   case ALLEGRO_KEY_UP:
			   keys[UP] = true;
			   break;
		   case ALLEGRO_KEY_DOWN:
			   keys[DOWN] = true;
			   break;
		   case ALLEGRO_KEY_LEFT:
			   keys[LEFT] = true;
			   break;
		   case ALLEGRO_KEY_RIGHT:
			   keys[RIGHT] = true;
			   break;
		   case ALLEGRO_KEY_SPACE:
			   keys[SPACE] = true;
			   //*Fire Round*//
			   Round *round = new Round( tank->getX(), tank->getY() - 50);
			   gameObjects.push_back(round);
			   break;
		   }
	   }
	   else if(event.type == ALLEGRO_EVENT_KEY_UP)
	   {
		   switch(event.keyboard.keycode)
		   {
		   case ALLEGRO_KEY_ESCAPE:
			   finished = false;
			   break;
		   case ALLEGRO_KEY_UP:
			   keys[UP] = false;
			   break;
		   case ALLEGRO_KEY_DOWN:
			   keys[DOWN] = false;
			   break;
		   case ALLEGRO_KEY_LEFT:
			   keys[LEFT] = false;
			   break;
		   case ALLEGRO_KEY_RIGHT:
			   keys[RIGHT] = false;
			   break;
		   case ALLEGRO_KEY_SPACE:
			   keys[SPACE] = false;
			   break;
		   }
	   }

	   //*Move Tank*//
	   if(event.type == ALLEGRO_EVENT_TIMER)
	   {
		   redraw = true;
		    if(keys[UP])
			    tank -> moveUp();
		    else if(keys[DOWN])
			    tank -> moveDown();
		    if(keys[LEFT])
			    tank -> moveLeft();
		    else if(keys[RIGHT])
			    tank -> moveRight();

		   //*Init Soldier*//
		   if(rand() % 100 == 0)
		   {
			Soldier *soldier = new Soldier( rand() % (SCREEN_WIDTH - 20), 0);
			   gameObjects.push_back(soldier);
		   }

		   //*Update all objects in gameObject Array*//
		   for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
			   (*iter)->update();

		   //*Check for collisions, if two objects of different IDs*//
		   //*have collided, then call each objects collided func*//
		   for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
		   {
			   if( ! (*iter) -> collidable() ) continue;

			   for(iter2 = iter; iter2 != gameObjects.end(); iter2++)
			   {
				   if( !(*iter2)->collidable() ) continue;
				   if( (*iter)->getID() == (*iter2)->getID() ) continue;

				   if( (*iter)->checkCollisions ( (* iter2)))
				   {
					   (*iter)->collided (	(*iter2)->getID() );
					   (*iter2)->collided( (*iter)->getID() );
				   }
			   }
		    }

		   /*If object is not alive, destroy it*/
		   for(iter = gameObjects.begin(); iter != gameObjects.end();)
		   {
			   if(! (*iter) -> getAlive())
			   {
				   delete (*iter);
				   iter = gameObjects.erase(iter);
			    }
			   else
				   iter++;
		   }
	   }

	   //*render all objects, and flip the buffer to the screen*//
	   if(redraw &&  al_is_event_queue_empty(event_queue))
	   {
		   redraw = false;

		   for(iter = gameObjects.begin(); iter != gameObjects.end(); iter++ )
			   (*iter)->render();

		   al_flip_display();
		   al_clear_to_color(al_map_rgb(206,186,142));
	   }
   }

   //*delete all objects in gameObject array*//
   for(iter = gameObjects.begin(); iter != gameObjects.end();)
   {
	   delete (*iter);
	   iter = gameObjects.erase(iter);
   }

   //*destroy Allegro variables*//
   al_destroy_event_queue(event_queue);
   al_destroy_timer(timer);
   al_destroy_display(display);

   return 0;
}

