#include "header.h"
int main(void)
{
	/* Zmienne Z Gry*/
	int tab[8][8];
	int wiersz = 6;
	int menu = 2;
	kamienie kamienietab[8][8];
	int czasgry = 0;
	int width = 400;
	int height = 700;
	int plansza_x = 0;
	int plansza_y = 150;
	int score = 0;
	bool przesuwaniee = false;
	bool done = false;
	bool mousemovment = false;
	bool plansza = true;
	bool sprawdzanieplanszy = false;
	bool redraw = true;
	int x1 = 10, x2 = 10, y1 = 10, y2 = 10;
	int TabA, TabB, wspolrzedneTabA_x, wspolrzedneTabA_y, wspolrzedneTabB_x, wspolrzedneTabB_y;
	int posofmouseX = 0;
	int posofmouseY = 0;
	/* Zmienne z Menu*/
	bool redrawmenu = true;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *pierwszy = NULL;
	ALLEGRO_BITMAP *drugi = NULL;
	ALLEGRO_BITMAP *trzeci = NULL;
	ALLEGRO_BITMAP *czwarty = NULL;
	ALLEGRO_BITMAP *piaty = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *backgroundmenu = NULL;
	ALLEGRO_BITMAP *button = NULL;
	ALLEGRO_BITMAP *ranking = NULL;
	ALLEGRO_BITMAP *rankingbutton = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;
	ALLEGRO_SAMPLE *song=NULL;
	ALLEGRO_SAMPLE *dzwiekprzesuwania = NULL;
	ALLEGRO_SAMPLE_INSTANCE  *SoundIstance = NULL;


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
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_FONT *font24 = al_load_font("fontscore.ttf", 48, 0);


	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));

	generowanie_tablicy(kamienietab, plansza_x, plansza_y);
	pierwszy = al_load_bitmap("pierwszy.png");
	drugi = al_load_bitmap("drugi.png");
	trzeci = al_load_bitmap("trzeci.png");
	czwarty = al_load_bitmap("czwarty.png");
	piaty = al_load_bitmap("piec.png");
	background = al_load_bitmap("background.png");
	backgroundmenu = al_load_bitmap("backgroundmenu.png");
	button = al_load_bitmap("button.png");
	ranking = al_load_bitmap("ranking.png");
	rankingbutton = al_load_bitmap("rankingbuttonv2.png");
	al_convert_mask_to_alpha(pierwszy, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(drugi, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(trzeci, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(czwarty, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(piaty, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(button, al_map_rgb(250, 10, 220));
	al_convert_mask_to_alpha(ranking, al_map_rgb(250, 10, 230));
	al_convert_mask_to_alpha(rankingbutton, al_map_rgb(250, 10, 220));
	
	al_reserve_samples(50);
	song = al_load_sample("song.ogg");
	dzwiekprzesuwania = al_load_sample("getruby.flac");

	SoundIstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(SoundIstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(SoundIstance, al_get_default_mixer());

	al_start_timer(timer);
	while (!done)
	{
		al_play_sample_instance(SoundIstance);
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		if (menu == 1) //Gra
		{
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
						przesuwaniee = false;
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
						przesuwaniee = false;
					}
				}
				if (event.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					{
						menu = 2;
					}
				}
			}
			/*------------------------------------------------------------------------------*/
			/*-------------------------------Wyswietlanie---------------------------------*/
			if (redraw == true)
			{
				czasgry++;
				if (sprawdzanieplanszy == true&&przesuwaniee==false)
				{
					if (czasgry % 60 == 0)
						sprawdzanie_tablicy(kamienietab, &score, &sprawdzanieplanszy,&przesuwaniee);
				}
				else if (sprawdzanieplanszy==false&&przesuwaniee==true)
				{
					przesuwanie(kamienietab, &sprawdzanieplanszy, &przesuwaniee, &wiersz);
				}
				redraw = false;
				al_draw_bitmap(background, 0, 0, NULL);
				al_draw_textf(font24, al_map_rgb(0, 0, 0), 120, 0, 0, "Score : %i", score);
				rysowanietablicy(kamienietab, plansza_x, plansza_y, pierwszy, drugi, trzeci, czwarty, piaty);
				// CURSOR
				if (mousemovment == true)
				{
					elementtablicy(posofmouseX, posofmouseY, &x1, &y1, plansza_x, plansza_y);
					switch (kamienietab[x1][y1].wartosc)
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
						al_play_sample(dzwiekprzesuwania,0.5,0,1,ALLEGRO_PLAYMODE_ONCE,0);
						TabB = kamienietab[x2][y2].wartosc;
						wspolrzedneTabB_x = kamienietab[x2][y2].bitmapax;
						wspolrzedneTabB_y = kamienietab[x2][y2].bitmapay;
						TabA = kamienietab[x1][y1].wartosc;
						wspolrzedneTabA_x = kamienietab[x1][y1].bitmapax;
						wspolrzedneTabA_y = kamienietab[x1][y1].bitmapay;

						/*kamienietab[x2][y2].bitmapax = wspolrzedneTabA_x;
						kamienietab[x2][y2].bitmapay = wspolrzedneTabA_y;
						kamienietab[x2][y2].docelowabitmapax = wspolrzedneTabB_x;
						kamienietab[x2][y2].docelowabitmapay = wspolrzedneTabB_y;
						*/
						kamienietab[x2][y2].bitmapax = wspolrzedneTabA_x;
						kamienietab[x2][y2].bitmapay = wspolrzedneTabA_y;
						kamienietab[x2][y2].wartosc = TabA;
						kamienietab[x1][y1].wartosc = TabB;
					}
					x2 = x1;
					y2 = y1;
				}
				al_flip_display();
			}
		}
		else if (menu == 2)//Menu
		{
			al_stop_sample_instance(SoundIstance);
			if ((event.type == ALLEGRO_EVENT_TIMER))
			{
				redraw = true;
			}
			else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
					done = true;
				}
			}
			//MYSZ
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button & 1)
				{
					if (event.mouse.x > 75 && event.mouse.x < 325 && event.mouse.y>100 && event.mouse.y < 170)
					{
						menu = 1;
					}
					else if (event.mouse.x>75 && event.mouse.x < 325 && event.mouse.y>250 && event.mouse.y < 320)
					{
						menu = 3;
					}
					else if (event.mouse.x>75 && event.mouse.x < 325 && event.mouse.y>400 && event.mouse.y <470)
					{
						done = true;
					}
				}
				}

				if (redraw = true)
				{
					al_draw_bitmap(backgroundmenu, 0, 0, NULL);
					al_draw_bitmap(button, 75, 100, NULL);
					al_draw_bitmap(button, 75, 250, NULL);
					al_draw_bitmap(button, 75, 400, NULL);
					al_draw_textf(font24, al_map_rgb(235, 190, 107), 165, 105, 0, "Play");
					al_draw_textf(font24, al_map_rgb(235, 190, 107), 135, 255, 0, "Ranking");
					al_draw_textf(font24, al_map_rgb(235, 190, 107), 170, 405, 0, "Exit");
					redraw = false;
					al_flip_display();
				}
			}
		
		else if (menu==3) // RAnking
		{ 
			al_stop_sample_instance(SoundIstance);
			if ((event.type == ALLEGRO_EVENT_TIMER))
			{
				redraw = true;
			}
			else if (event.type==ALLEGRO_EVENT_KEY_DOWN)
			{
				if (event.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
				{
					menu = 2;
				}
			}
			if (redraw = true)
			{
				al_draw_bitmap(backgroundmenu, 0, 0, NULL);
				al_draw_bitmap(rankingbutton, 7, 0, NULL);
				al_draw_bitmap(ranking, 25, 100, NULL);
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 130, 5, 0, "Ranking");
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 60, 150, 0, "1 miejsce");
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 60, 225, 0, "2 miejsce");
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 60, 300, 0, "3 miejsce");
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 60, 375, 0, "4 miejsce");
				al_draw_textf(font24, al_map_rgb(235, 190, 107), 60, 450, 0, "5 miejsce");
				redraw = false;
				al_flip_display();
			}
		}
		}
		al_destroy_display(display);

		return 0;
	}