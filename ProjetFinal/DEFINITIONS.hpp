/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: DEFINITIONS.hpp																*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

enum gameStates {		// Les �tats du jeu
	loading,
	ready,
	playing,
	gameOver
};

enum directions {		// Les directions des entit�s
	RIGHT,
	TOP,
	LEFT,
	BOTTOM
};

enum entityStates {		// Les �tats des entit�s
	WALKING,
	IDLE,
	ATTACKING,
	HIT,
	DYING,
	DEAD
};

enum itemTypes {		// Les types d'item qu'on peut acqu�rir
	bigLifePotion,
	smallLifePotion
};

//------ �cran ------//
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

//----- Intro -----//
#define NEXT_BUTTON_FILEPATH "Ressources/Menu/suivantButton.png"

//------ Loading ------//
#define LOADING_TIME 3.0f
#define LOADING_FRAME_1 "Ressources/UI/Loading/1.png"
#define LOADING_FRAME_2 "Ressources/UI/Loading/2.png"
#define LOADING_FRAME_3 "Ressources/UI/Loading/3.png"
#define LOADING_FRAME_4 "Ressources/UI/Loading/4.png"

//----- Skeleton Loading ------//
#define LOADING_SKELETON_TIME 1.0f
#define LOADING_SKELETON_FAME_1 "Ressources/UI/LoadingSkeleton/1.png"
#define LOADING_SKELETON_FAME_2 "Ressources/UI/LoadingSkeleton/2.png"
#define LOADING_SKELETON_FAME_3 "Ressources/UI/LoadingSkeleton/3.png"
#define LOADING_SKELETON_FAME_4 "Ressources/UI/LoadingSkeleton/4.png"
#define LOADING_SKELETON_FAME_5 "Ressources/UI/LoadingSkeleton/5.png"
#define LOADING_SKELETON_FAME_6 "Ressources/UI/LoadingSkeleton/6.png"
#define LOADING_SKELETON_FAME_7 "Ressources/UI/LoadingSkeleton/7.png"
#define LOADING_SKELETON_FAME_8 "Ressources/UI/LoadingSkeleton/8.png"


//------ Game ------//
	// Murs
#define GAME_BACKGROUND_TEMP_1 "Ressources/Map/Contour_map.png"
#define GAME_FOREGROUND_LEFT_RIGHT_TEMP_1 "Ressources/Map/wall.png"
#define GAME_FOREGROUND_UP_DOWN_TEMP_1 "Ressources/Map/wall_back.png"
#define GAME_BACKGROUND_TEMP_2 "Ressources/Map/Contour_map_3.png"
#define GAME_FOREGROUND_LEFT_RIGHT_TEMP_2 "Ressources/Map/wall_3.png"
#define GAME_FOREGROUND_UP_DOWN_TEMP_2 "Ressources/Map/wall_back_3.png"
#define POP_UP "Ressources/UI/pop_up.png"
#define ACCEPT_PURCHASE "Ressources/UI/accept.png"
	// Hud
#define GAME_HEARTS_FILEPATH "Ressources/UI/hearts.png"
#define GAME_COIN_FILEPATH "Ressources/UI/coin.png"
#define GAME_KILLS_FILEPATH "Ressources/UI/kills.png"
	// Porte
#define GAME_DOOR_CLOSED_1 "Ressources/Objects/door_closed.png"
#define GAME_DOOR_CLOSED_2 "Ressources/Objects/door_closed_1.png"
#define GAME_DOOR_OPEN "Ressources/Objects/door_open.png"
	// Items
#define PRICE_BIG_LIFE_POTION 5
#define BIG_LIFE_POTION "Ressources/Objects/flask_big_red.png"
#define PRICE_SMALL_LIFE_POTION 3
#define BIG_LIFE_POTION "Ressources/Objects/flask_big_red.png"

//------ Store ------//
	// Hi
#define TALKING_SHOP_OWNER "Ressources/Map/Shop/shopHi.png"
	// Carpet
#define CARPET_STORE "Ressources/Map/Shop/tapis.png"
	// Cat
#define CAT_IDLE_TIME 1.0f
#define CAT_FRAME_1 "Ressources/Map/Shop/Cat/1.png"
#define CAT_FRAME_2 "Ressources/Map/Shop/Cat/2.png"
#define CAT_FRAME_3 "Ressources/Map/Shop/Cat/3.png"
	// Torches
#define TORCH_ANIMATION_TIME 1.0f
#define TORCH_FRAME_1 "Ressources/Objects/Torch/1.png"
#define TORCH_FRAME_2 "Ressources/Objects/Torch/2.png"
#define TORCH_FRAME_3 "Ressources/Objects/Torch/3.png"
#define TORCH_FRAME_4 "Ressources/Objects/Torch/4.png"

//------ Main character ------//
#define NBR_LIVES 5
#define SKELETON_WALK_TIME 0.6f
#define SKELETON_IDLE_TIME 1.0f
#define SKELETE_ATTACK_TIME 1.2f
#define MOVEMENT_DISTANCE 20

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

//------ Store owner ------//
#define STOREOWNER_IDLE_TIME 1.3f
	// Idle
#define STOREOWNER_IDLE_1 "Ressources/Map/Shop/NPC/1.png"
#define STOREOWNER_IDLE_2 "Ressources/Map/Shop/NPC/2.png"
#define STOREOWNER_IDLE_3 "Ressources/Map/Shop/NPC/3.png"
#define STOREOWNER_IDLE_4 "Ressources/Map/Shop/NPC/4.png"
#define STOREOWNER_IDLE_5 "Ressources/Map/Shop/NPC/5.png"
#define STOREOWNER_IDLE_6 "Ressources/Map/Shop/NPC/6.png"
#define STOREOWNER_IDLE_7 "Ressources/Map/Shop/NPC/7.png"
#define STOREOWNER_IDLE_8 "Ressources/Map/Shop/NPC/8.png"
#define STOREOWNER_IDLE_9 "Ressources/Map/Shop/NPC/9.png"

//------ Guard Enemy ------//
#define LIVE_ENEMY 3.0f
#define ENEMY_IDLE_TIME 1.0f
#define ENEMY_WALK_TIME 0.8f
#define AGRO_RANGE 500
#define LIFE_BAR_FILEPATH "Ressources/UI/enemy_life_bar.png"
#define NBR_LIVES_GARD 2

#define ENEMY_ATTACK_TIME 1.0f
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
#define ENEMY_ATTACK_FRAME_RIGHT_7 "Ressources/Enemies/Mud Guard/Attack 1/Right/7.png"

	// Attack left
#define ENEMY_ATTACK_FRAME_LEFT_1 "Ressources/Enemies/Mud Guard/Attack 1/Left/1.png"
#define ENEMY_ATTACK_FRAME_LEFT_2 "Ressources/Enemies/Mud Guard/Attack 1/Left/2.png"
#define ENEMY_ATTACK_FRAME_LEFT_3 "Ressources/Enemies/Mud Guard/Attack 1/Left/3.png"
#define ENEMY_ATTACK_FRAME_LEFT_4 "Ressources/Enemies/Mud Guard/Attack 1/Left/4.png"
#define ENEMY_ATTACK_FRAME_LEFT_5 "Ressources/Enemies/Mud Guard/Attack 1/Left/5.png"
#define ENEMY_ATTACK_FRAME_LEFT_6 "Ressources/Enemies/Mud Guard/Attack 1/Left/6.png"
#define ENEMY_ATTACK_FRAME_LEFT_7 "Ressources/Enemies/Mud Guard/Attack 1/Left/7.png"

	// Walking left
#define ENEMY_WALKING_FRAME_LEFT_1 "Ressources/Enemies/Mud Guard/Run/Left/1.png"
#define ENEMY_WALKING_FRAME_LEFT_2 "Ressources/Enemies/Mud Guard/Run/Left/2.png"
#define ENEMY_WALKING_FRAME_LEFT_3 "Ressources/Enemies/Mud Guard/Run/Left/3.png"
#define ENEMY_WALKING_FRAME_LEFT_4 "Ressources/Enemies/Mud Guard/Run/Left/4.png"
#define ENEMY_WALKING_FRAME_LEFT_5 "Ressources/Enemies/Mud Guard/Run/Left/5.png"
#define ENEMY_WALKING_FRAME_LEFT_6 "Ressources/Enemies/Mud Guard/Run/Left/6.png"

	// Walking right
#define ENEMY_WALKING_FRAME_RIGHT_1 "Ressources/Enemies/Mud Guard/Run/Right/1.png"
#define ENEMY_WALKING_FRAME_RIGHT_2 "Ressources/Enemies/Mud Guard/Run/Right/2.png"
#define ENEMY_WALKING_FRAME_RIGHT_3 "Ressources/Enemies/Mud Guard/Run/Right/3.png"
#define ENEMY_WALKING_FRAME_RIGHT_4 "Ressources/Enemies/Mud Guard/Run/Right/4.png"
#define ENEMY_WALKING_FRAME_RIGHT_5 "Ressources/Enemies/Mud Guard/Run/Right/5.png"
#define ENEMY_WALKING_FRAME_RIGHT_6 "Ressources/Enemies/Mud Guard/Run/Right/6.png"

	// Hit left
#define ENEMY_HIT_TIME 0.5f
#define ENEMY_HIT_LEFT_1 "Ressources/Enemies/Mud Guard/Damaged/Left/1.png"
#define ENEMY_HIT_LEFT_2 "Ressources/Enemies/Mud Guard/Damaged/Left/2.png"

	// Hit right
#define ENEMY_HIT_RIGHT_1 "Ressources/Enemies/Mud Guard/Damaged/Right/1.png"
#define ENEMY_HIT_RIGHT_2 "Ressources/Enemies/Mud Guard/Damaged/Right/2.png"

	// Dying left
#define ENEMY_DYING_TIME 2.0f
#define ENEMY_DYING_LEFT_1 "Ressources/Enemies/Mud Guard/Death/Left/1.png"
#define ENEMY_DYING_LEFT_2 "Ressources/Enemies/Mud Guard/Death/Left/2.png"
#define ENEMY_DYING_LEFT_3 "Ressources/Enemies/Mud Guard/Death/Left/3.png"
#define ENEMY_DYING_LEFT_4 "Ressources/Enemies/Mud Guard/Death/Left/4.png"
#define ENEMY_DYING_LEFT_5 "Ressources/Enemies/Mud Guard/Death/Left/5.png"
#define ENEMY_DYING_LEFT_6 "Ressources/Enemies/Mud Guard/Death/Left/6.png"

	// Dying right
#define ENEMY_DYING_RIGHT_1 "Ressources/Enemies/Mud Guard/Death/Right/1.png"
#define ENEMY_DYING_RIGHT_2 "Ressources/Enemies/Mud Guard/Death/Right/2.png"
#define ENEMY_DYING_RIGHT_3 "Ressources/Enemies/Mud Guard/Death/Right/3.png"
#define ENEMY_DYING_RIGHT_4 "Ressources/Enemies/Mud Guard/Death/Right/4.png"
#define ENEMY_DYING_RIGHT_5 "Ressources/Enemies/Mud Guard/Death/Right/5.png"
#define ENEMY_DYING_RIGHT_6 "Ressources/Enemies/Mud Guard/Death/Right/6.png"

//------ Minotaur ------//
#define MINOTAUR_NBR_LIVES 5
#define MINOTAUR_WALK_TIME 1.0f
#define MINOTAUR_IDLE_TIME 1.0f
#define MINOTAUR_ATTACK_TIME 1.2f

	// Idle
#define MINOTAUR_IDLE_FRAME_RIGHT_1 "Ressources/Boss/Idle/Right/1.png"
#define MINOTAUR_IDLE_FRAME_RIGHT_2 "Ressources/Boss/Idle/Right/2.png"
#define MINOTAUR_IDLE_FRAME_RIGHT_3 "Ressources/Boss/Idle/Right/3.png"
#define MINOTAUR_IDLE_FRAME_RIGHT_4 "Ressources/Boss/Idle/Right/4.png"
#define MINOTAUR_IDLE_FRAME_RIGHT_5 "Ressources/Boss/Idle/Right/5.png"
#define MINOTAUR_IDLE_FRAME_LEFT_1 "Ressources/Boss/Idle/Left/1.png"
#define MINOTAUR_IDLE_FRAME_LEFT_2 "Ressources/Boss/Idle/Left/2.png"
#define MINOTAUR_IDLE_FRAME_LEFT_3 "Ressources/Boss/Idle/Left/3.png"
#define MINOTAUR_IDLE_FRAME_LEFT_4 "Ressources/Boss/Idle/Left/4.png"
#define MINOTAUR_IDLE_FRAME_LEFT_5 "Ressources/Boss/Idle/Left/5.png"

	// Walking
#define MINOTAUR_WALKING_FRAME_RIGHT_1 "Ressources/Boss/Run/Right/1.png"
#define MINOTAUR_WALKING_FRAME_RIGHT_2 "Ressources/Boss/Run/Right/2.png"
#define MINOTAUR_WALKING_FRAME_RIGHT_3 "Ressources/Boss/Run/Right/3.png"
#define MINOTAUR_WALKING_FRAME_RIGHT_4 "Ressources/Boss/Run/Right/4.png"
#define MINOTAUR_WALKING_FRAME_RIGHT_5 "Ressources/Boss/Run/Right/5.png"
#define MINOTAUR_WALKING_FRAME_RIGHT_6 "Ressources/Boss/Run/Right/6.png"
#define MINOTAUR_WALKING_FRAME_LEFT_1 "Ressources/Boss/Run/Left/1.png"
#define MINOTAUR_WALKING_FRAME_LEFT_2 "Ressources/Boss/Run/Left/2.png"
#define MINOTAUR_WALKING_FRAME_LEFT_3 "Ressources/Boss/Run/Left/3.png"
#define MINOTAUR_WALKING_FRAME_LEFT_4 "Ressources/Boss/Run/Left/4.png"
#define MINOTAUR_WALKING_FRAME_LEFT_5 "Ressources/Boss/Run/Left/5.png"
#define MINOTAUR_WALKING_FRAME_LEFT_6 "Ressources/Boss/Run/Left/6.png"