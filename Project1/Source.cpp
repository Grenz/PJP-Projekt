#include "header.h"
int main(void)
{
	int tab[8][8];
	kamienie kamienietab[8][8];
	int czasgry = 0;
	int width = 400;
	int height = 600;
	int plansza_x = 0;
	int plansza_y = 100;
	int score = 0;
	bool done = false;
	bool mousemovment = false;
	bool plansza = true;
	bool sprawdzanieplanszy = false;
	bool redraw = true;
	int x1 = 10, x2 = 10, y1 = 10, y2 = 10;
	int TabA, TabB;
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
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;


	srand(time(NULL));
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	display = al_create_display(width, height);
	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize display!", NULL, NULL);
		return -1;
	}
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font24 = al_load_font("fontscore.ttf", 48, 0);


	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));

	generowanie_tablicy(tab, kamienietab);
	pierwszy = al_load_bitmap("pierwszy.png");
	drugi = al_load_bitmap("drugi.png");
	trzeci = al_load_bitmap("trzeci.png");
	czwarty = al_load_bitmap("czwarty.png");
	piaty = al_load_bitmap("piec.png");
	background = al_load_bitmap("background.png");
	al_convert_mask_to_alpha(pierwszy, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(drugi, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(trzeci, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(czwarty, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(piaty, al_map_rgb(250, 10, 220));


	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		/*---------------------------STEROWANIE MYSZA---------------------------------*/
		if ((event.type == ALLEGRO_EVENT_TIMER))
		{
			redraw = true;
		}
		else if (!(event.type == ALLEGRO_EVENT_TIMER))
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				if (event.mouse.x > 0 + plansza_x&& event.mouse.x < 400 + plansza_x && event.mouse.y < 400 + plansza_y && event.mouse.y>0 + plansza_y)
				{
					posofmouseX = event.mouse.x;
					posofmouseY = event.mouse.y;
				}
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button & 1)
				{
					x2 = 10;
					y2 = 10;

					mousemovment = true;
					sprawdzanieplanszy = false;
				}
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				if (event.mouse.button & 1)
				{
					x2 = 10;
					y2 = 10;
					mousemovment = false;
					sprawdzanieplanszy = true;
				}
			}
		}
		/*------------------------------------------------------------------------------*/
		/*-------------------------------Wyswietlanie---------------------------------*/
		if (redraw == true)
		{
			czasgry++;
			if (sprawdzanieplanszy == true)
			{
				if (czasgry % 60 == 0)
					sprawdzanie_tablicy(tab, &score, &sprawdzanieplanszy);
			}
			redraw = false;
			al_draw_bitmap(background, 0, 0, NULL);
			al_draw_textf(font24, al_map_rgb(0, 0, 0), 120, 0, 0, "Score : %i", score);
			rysowanietablicy(tab, plansza_x, plansza_y, pierwszy, drugi, trzeci, czwarty, piaty);
			// CURSOR
			if (mousemovment == true)
			{
				elementtablicy(posofmouseX, posofmouseY, &x1, &y1, plansza_x, plansza_y);
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
				// ZAMIANA WARTOSCI KLOCKOW
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
			al_flip_display();
		}
	}
	al_rest(5.0);
	al_destroy_display(display);

	return 0;
}
