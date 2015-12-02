#include "header.h"
int main(void)
{
	int tab[8][8];
	int width = 400;
	int height = 400;
	bool done = false, start = false, start2 = false;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *pierwszy = NULL;
	ALLEGRO_BITMAP *drugi = NULL;
	ALLEGRO_BITMAP *trzeci = NULL;
	ALLEGRO_BITMAP *czwarty = NULL;

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


	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 40);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	int x = 0;
	int y = 0;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	generowanie_tablicy(tab);
	pierwszy = al_load_bitmap("pierwszy.png");
	drugi = al_load_bitmap("drugi.png");
	trzeci = al_load_bitmap("trzeci.png");
	czwarty = al_load_bitmap("czwarty.png");



	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (tab[i][j] == 0)
				{
					al_draw_bitmap(pierwszy, i * 50, j * 50, NULL);
					al_flip_display();
				}
				else if (tab[i][j] == 1)
				{
					al_draw_bitmap(drugi, i * 50, j * 50, NULL);
					al_flip_display();
				}
				else if (tab[i][j] == 2)
				{
					al_draw_bitmap(trzeci, i * 50, j * 50, NULL);
					al_flip_display();
				}
				else if (tab[i][j] == 3)
				{
					al_draw_bitmap(czwarty, i * 50, j * 50, NULL);
					al_flip_display();
				}
			}
		}
		al_flip_display();
	}

	al_rest(5.0);
	al_destroy_display(display);

	return 0;
}