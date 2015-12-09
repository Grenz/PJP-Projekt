#include "header.h"
int main(void)
{
	int tab[8][8];
	int width = 400;
	int height = 400;
	bool done = false;
	bool mousemovment = false;
	bool plansza = true;
	int x1 = 10, x2 = 10,y1 = 10, y2 = 10;
	int TabA,TabB;
	int posofmouseX = 0;
	int posofmouseY = 0;


	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *pierwszy = NULL;
	ALLEGRO_BITMAP *drugi = NULL;
	ALLEGRO_BITMAP *trzeci = NULL;
	ALLEGRO_BITMAP *czwarty = NULL;
	ALLEGRO_BITMAP *piaty = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;

	srand(time(NULL));
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	display = al_create_display(width,height);
	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, NULL);
		return -1;
	}
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();


	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));

	generowanie_tablicy(tab);
	pierwszy = al_load_bitmap("pierwszy.png");
	drugi = al_load_bitmap("drugi.png");
	trzeci = al_load_bitmap("trzeci.png");
	czwarty = al_load_bitmap("czwarty.png");
	piaty = al_load_bitmap("piec.png");

	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
/*---------------------------STEROWANIE MYSZA---------------------------------*/
		if (!(event.type==ALLEGRO_EVENT_TIMER))
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				if (event.mouse.x > 0 && event.mouse.x < 400 && event.mouse.y < 400 && event.mouse.y>0)
				{
					posofmouseX = event.mouse.x;
					posofmouseY = event.mouse.y;
				}
			}
			else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button & 1)
				{
					x2 = 10;
					y2 = 10;

					mousemovment = true;
				}
			}
			else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				if (event.mouse.button & 1)
				{
					x2 = 10;
					y2 = 10;
					mousemovment = false;
				}
			}
		}
/*------------------------------------------------------------------------------*/
/*-------------------------------Wyswietlanie---------------------------------*/
			for (int j = 0; j < 8; j++)
				for (int i = 0; i < 8; i++)
				switch (tab[i][j])
				{
				case 0:
					al_draw_bitmap(pierwszy, i * 50, j * 50, NULL);
					break;
				case 1:
					al_draw_bitmap(drugi, i * 50, j * 50, NULL);
					break;
				case 2:
					al_draw_bitmap(trzeci, i * 50, j * 50, NULL);
					break;
				case 3:
					al_draw_bitmap(czwarty, i * 50, j * 50, NULL);
					break;
				case 4:
					al_draw_bitmap(piaty, i * 50, j * 50, NULL);
					break;
				}	
			if (mousemovment==true)
			{
				elementtablicy(posofmouseX,posofmouseY, &x1, &y1);
				switch (tab[x1][y1])
				{
				case 0:
					al_draw_bitmap(pierwszy, posofmouseX, posofmouseY, NULL);
					break;
				case 1:
					al_draw_bitmap(drugi, posofmouseX, posofmouseY, NULL);
					break;
				case 2:
					al_draw_bitmap(trzeci, posofmouseX, posofmouseY, NULL);
					break;
				case 3:
					al_draw_bitmap(czwarty, posofmouseX, posofmouseY, NULL);
					break;
				}
				if ((!(x1 == x2) && !(x2 == 10) && !(y2 == 10)) || (!(y1 == y2) && !(x2 == 10) && !(y2 == 10)))
				{
					TabA = tab[x1][y1];
					TabB = tab[x2][y2];
					tab[x2][y2] = TabA;
					tab[x1][y1] = TabB;
				}
				x2 = x1;
				y2 = y1;
			}
			if (event.type==ALLEGRO_EVENT_TIMER)
			{
				sprawdzanie_tablicy(tab);
				al_flip_display();
			}
		}

		al_rest(5.0);
		al_destroy_display(display);

		return 0;
	}
