#pragma once

enum gameStates {		// Les états du jeu
	ready,
	playing,
	gameOver
};

enum directions {		// Les directions des entités
	RIGHT,
	TOP,
	LEFT,
	BOTTOM
};

enum entityStates {		// Les états des entités
	WALKING,
	IDLE,
	ATTACKING,
	DYING,
	DEAD
};

//------ Écran ------//
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define LOGO_STATE_SHOW_TIME 3.0

//------ Splash Screen ------//
#define SPLASH_STATE_BACKGROUND_FILEPATH "Ressources/Menu/SplashScreen.png"
#define SPLASH_STATE_MEOW "Ressources/Menu/SplashScreenMeow.png"
#define SPLASH_STATE_MEOW "Ressources/Menu/SplashScreenMeow.png"
#define PIXEL_ART_FONT "Ressources/Fonts/Pixeled.ttf"

//------ Main menu ------//
#define MAIN_MENU_BACKGROUND "Ressources/Menu/background.png"
#define MAIN_MENU_FONT "Ressources/Fonts/Stranger back in the Night.ttf"
#define PLAY_BUTTON_FILEPATH "Ressources/Menu/playButton.png"
#define STOP_BUTTON_FILEPATH "Ressources/Menu/stopButton.png"

//------ Loading ------//
#define LOADING_TIME 3.0f
#define LOADING_FRAME_1 "Ressources/UI/Loading/1.png"
#define LOADING_FRAME_2 "Ressources/UI/Loading/2.png"
#define LOADING_FRAME_3 "Ressources/UI/Loading/3.png"

//------ Game ------//
	// Murs
#define GAME_BACKGROUND_TEMP "Ressources/Map/Contour_map.png"
#define GAME_FOREGROUND_LEFT_RIGHT_TEMP "Ressources/Map/wall.png"
#define GAME_FOREGROUND_UP_DOWN_TEMP "Ressources/Map/wall_back.png"
	// Hud
#define GAME_HEARTS_FILEPATH "Ressources/UI/hearts.png"
	// Porte
#define GAME_DOOR_CLOSED "Ressources/Objects/door_closed.png"
#define GAME_DOOR_OPEN "Ressources/Objects/door_open.png"

//------ Main character ------//
#define NBR_LIVES 5
#define SKELETON_WALK_TIME 0.6f
#define SKELETON_IDLE_TIME 1.0f
#define SKELETE_ATTACK_TIME 1.2f

	// Walk right
#define SKELETON_WALK_FRAME_RIGHT_1 "Ressources/MC/Walk/Right/1.png"
#define SKELETON_WALK_FRAME_RIGHT_2 "Ressources/MC/Walk/Right/2.png"
#define SKELETON_WALK_FRAME_RIGHT_3 "Ressources/MC/Walk/Right/3.png"
#define SKELETON_WALK_FRAME_RIGHT_4 "Ressources/MC/Walk/Right/4.png"
#define SKELETON_WALK_FRAME_RIGHT_5 "Ressources/MC/Walk/Right/5.png"
#define SKELETON_WALK_FRAME_RIGHT_6 "Ressources/MC/Walk/Right/6.png"
#define SKELETON_WALK_FRAME_RIGHT_7 "Ressources/MC/Walk/Right/7.png"
#define SKELETON_WALK_FRAME_RIGHT_8 "Ressources/MC/Walk/Right/8.png"
#define SKELETON_WALK_FRAME_RIGHT_9 "Ressources/MC/Walk/Right/9.png"
#define SKELETON_WALK_FRAME_RIGHT_10 "Ressources/MC/Walk/Right/10.png"
#define SKELETON_WALK_FRAME_RIGHT_11 "Ressources/MC/Walk/Right/11.png"
#define SKELETON_WALK_FRAME_RIGHT_12 "Ressources/MC/Walk/Right/12.png"

	// Walk left
#define SKELETON_WALK_FRAME_LEFT_1 "Ressources/MC/Walk/Left/1.png"
#define SKELETON_WALK_FRAME_LEFT_2 "Ressources/MC/Walk/Left/2.png"
#define SKELETON_WALK_FRAME_LEFT_3 "Ressources/MC/Walk/Left/3.png"
#define SKELETON_WALK_FRAME_LEFT_4 "Ressources/MC/Walk/Left/4.png"
#define SKELETON_WALK_FRAME_LEFT_5 "Ressources/MC/Walk/Left/5.png"
#define SKELETON_WALK_FRAME_LEFT_6 "Ressources/MC/Walk/Left/6.png"
#define SKELETON_WALK_FRAME_LEFT_7 "Ressources/MC/Walk/Left/7.png"
#define SKELETON_WALK_FRAME_LEFT_8 "Ressources/MC/Walk/Left/8.png"
#define SKELETON_WALK_FRAME_LEFT_9 "Ressources/MC/Walk/Left/9.png"
#define SKELETON_WALK_FRAME_LEFT_10 "Ressources/MC/Walk/Left/10.png"
#define SKELETON_WALK_FRAME_LEFT_11 "Ressources/MC/Walk/Left/11.png"
#define SKELETON_WALK_FRAME_LEFT_12 "Ressources/MC/Walk/Left/12.png"

	// Idle right
#define SKELETON_IDLE_FRAME_RIGHT_1 "Ressources/MC/Idle/Right/1.png"
#define SKELETON_IDLE_FRAME_RIGHT_2 "Ressources/MC/Idle/Right/2.png"
#define SKELETON_IDLE_FRAME_RIGHT_3 "Ressources/MC/Idle/Right/3.png"
#define SKELETON_IDLE_FRAME_RIGHT_4 "Ressources/MC/Idle/Right/4.png"
#define SKELETON_IDLE_FRAME_RIGHT_5 "Ressources/MC/Idle/Right/5.png"
#define SKELETON_IDLE_FRAME_RIGHT_6 "Ressources/MC/Idle/Right/6.png"
#define SKELETON_IDLE_FRAME_RIGHT_7 "Ressources/MC/Idle/Right/7.png"
#define SKELETON_IDLE_FRAME_RIGHT_8 "Ressources/MC/Idle/Right/8.png"
#define SKELETON_IDLE_FRAME_RIGHT_9 "Ressources/MC/Idle/Right/9.png"
#define SKELETON_IDLE_FRAME_RIGHT_10 "Ressources/MC/Idle/Right/10.png"
#define SKELETON_IDLE_FRAME_RIGHT_11 "Ressources/MC/Idle/Right/11.png"

	// Idle left
#define SKELETON_IDLE_FRAME_LEFT_1 "Ressources/MC/Idle/Left/1.png"
#define SKELETON_IDLE_FRAME_LEFT_2 "Ressources/MC/Idle/Left/2.png"
#define SKELETON_IDLE_FRAME_LEFT_3 "Ressources/MC/Idle/Left/3.png"
#define SKELETON_IDLE_FRAME_LEFT_4 "Ressources/MC/Idle/Left/4.png"
#define SKELETON_IDLE_FRAME_LEFT_5 "Ressources/MC/Idle/Left/5.png"
#define SKELETON_IDLE_FRAME_LEFT_6 "Ressources/MC/Idle/Left/6.png"
#define SKELETON_IDLE_FRAME_LEFT_7 "Ressources/MC/Idle/Left/7.png"
#define SKELETON_IDLE_FRAME_LEFT_8 "Ressources/MC/Idle/Left/8.png"
#define SKELETON_IDLE_FRAME_LEFT_9 "Ressources/MC/Idle/Left/9.png"
#define SKELETON_IDLE_FRAME_LEFT_10 "Ressources/MC/Idle/Left/10.png"
#define SKELETON_IDLE_FRAME_LEFT_11 "Ressources/MC/Idle/Left/11.png"

	// Attack right
#define SKELETON_ATTAQUE_FRAME_RIGHT_1 "Ressources/MC/Attack/Right/1.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_2 "Ressources/MC/Attack/Right/2.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_3 "Ressources/MC/Attack/Right/3.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_4 "Ressources/MC/Attack/Right/4.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_5 "Ressources/MC/Attack/Right/5.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_6 "Ressources/MC/Attack/Right/6.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_7 "Ressources/MC/Attack/Right/7.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_8 "Ressources/MC/Attack/Right/8.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_9 "Ressources/MC/Attack/Right/9.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_10 "Ressources/MC/Attack/Right/10.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_11 "Ressources/MC/Attack/Right/11.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_12 "Ressources/MC/Attack/Right/12.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_13 "Ressources/MC/Attack/Right/13.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_14 "Ressources/MC/Attack/Right/14.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_15 "Ressources/MC/Attack/Right/15.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_16 "Ressources/MC/Attack/Right/16.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_17 "Ressources/MC/Attack/Right/17.png"
#define SKELETON_ATTAQUE_FRAME_RIGHT_18 "Ressources/MC/Attack/Right/18.png"

	// Attack left
#define SKELETON_ATTAQUE_FRAME_LEFT_1 "Ressources/MC/Attack/Left/1.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_2 "Ressources/MC/Attack/Left/2.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_3 "Ressources/MC/Attack/Left/3.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_4 "Ressources/MC/Attack/Left/4.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_5 "Ressources/MC/Attack/Left/5.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_6 "Ressources/MC/Attack/Left/6.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_7 "Ressources/MC/Attack/Left/7.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_8 "Ressources/MC/Attack/Left/8.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_9 "Ressources/MC/Attack/Left/9.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_10 "Ressources/MC/Attack/Left/10.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_11 "Ressources/MC/Attack/Left/11.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_12 "Ressources/MC/Attack/Left/12.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_13 "Ressources/MC/Attack/Left/13.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_14 "Ressources/MC/Attack/Left/14.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_15 "Ressources/MC/Attack/Left/15.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_16 "Ressources/MC/Attack/Left/16.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_17 "Ressources/MC/Attack/Left/17.png"
#define SKELETON_ATTAQUE_FRAME_LEFT_18 "Ressources/MC/Attack/Left/18.png"

//------ Guard Enemy ------//
#define LIVE_ENEMY 3.0f
#define ENEMY_IDLE_TIME 1.0f

	// Idle left
#define ENEMY_IDLE_FRAME_LEFT_1 "Ressources/Enemies/Mud Guard/Idle/Left/1.png"
#define ENEMY_IDLE_FRAME_LEFT_2 "Ressources/Enemies/Mud Guard/Idle/Left/2.png"
#define ENEMY_IDLE_FRAME_LEFT_3 "Ressources/Enemies/Mud Guard/Idle/Left/3.png"
#define ENEMY_IDLE_FRAME_LEFT_4 "Ressources/Enemies/Mud Guard/Idle/Left/4.png"
#define ENEMY_IDLE_FRAME_LEFT_5 "Ressources/Enemies/Mud Guard/Idle/Left/5.png"

	// Idle right
#define ENEMY_IDLE_FRAME_RIGHT_1 "Ressources/Enemies/Mud Guard/Idle/Right/1.png"
#define ENEMY_IDLE_FRAME_RIGHT_2 "Ressources/Enemies/Mud Guard/Idle/Right/2.png"
#define ENEMY_IDLE_FRAME_RIGHT_3 "Ressources/Enemies/Mud Guard/Idle/Right/3.png"
#define ENEMY_IDLE_FRAME_RIGHT_4 "Ressources/Enemies/Mud Guard/Idle/Right/4.png"
#define ENEMY_IDLE_FRAME_RIGHT_5 "Ressources/Enemies/Mud Guard/Idle/Right/5.png"

	// Attack right
#define ENEMY_ATTACK_FRAME_RIGHT_1 "Ressources/Enemies/Mud Guard/Attack 1/Right/1.png"
#define ENEMY_ATTACK_FRAME_RIGHT_2 "Ressources/Enemies/Mud Guard/Attack 1/Right/2.png"
#define ENEMY_ATTACK_FRAME_RIGHT_3 "Ressources/Enemies/Mud Guard/Attack 1/Right/3.png"
#define ENEMY_ATTACK_FRAME_RIGHT_4 "Ressources/Enemies/Mud Guard/Attack 1/Right/4.png"
#define ENEMY_ATTACK_FRAME_RIGHT_5 "Ressources/Enemies/Mud Guard/Attack 1/Right/5.png"
#define ENEMY_ATTACK_FRAME_RIGHT_6 "Ressources/Enemies/Mud Guard/Attack 1/Right/6.png"

	// Attack left
#define ENEMY_ATTACK_FRAME_LEFT_1 "Ressources/Enemies/Mud Guard/Attack 1/Left/1.png"
#define ENEMY_ATTACK_FRAME_LEFT_2 "Ressources/Enemies/Mud Guard/Attack 1/Left/2.png"
#define ENEMY_ATTACK_FRAME_LEFT_3 "Ressources/Enemies/Mud Guard/Attack 1/Left/3.png"
#define ENEMY_ATTACK_FRAME_LEFT_4 "Ressources/Enemies/Mud Guard/Attack 1/Left/4.png"
#define ENEMY_ATTACK_FRAME_LEFT_5 "Ressources/Enemies/Mud Guard/Attack 1/Left/5.png"
#define ENEMY_ATTACK_FRAME_LEFT_6 "Ressources/Enemies/Mud Guard/Attack 1/Left/6.png"