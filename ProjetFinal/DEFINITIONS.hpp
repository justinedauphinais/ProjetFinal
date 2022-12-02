#pragma once

enum gameStates {
	ready,
	playing,
	gameOver
};

enum directions {
	RIGHT,
	TOP,
	LEFT,
	BOTTOM
};

// Écran
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define LOGO_STATE_SHOW_TIME 3.0

// Ressources
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/res/SplashBackground.png"
#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

// Main menu
#define MAIN_MENU_BACKGROUND "Ressources/Menu/background.png"
#define MAIN_MENU_FONT "Ressources/Fonts/Stranger back in the Night.ttf"

// Game
#define GAME_BACKGROUND_TEMP "Ressources/Map/Contour_map.png"
#define GAME_FOREGROUND_TEMP "Ressources/Map/Contour_map_avant.png"

// Main character
	// Walk
#define SKELETON_WALK_TIME 0.05
#define SKELETON_WALK_FRAME_RIGHT_1 "Ressources/MC/Skeleton/Walk/Right/1.png"
#define SKELETON_WALK_FRAME_RIGHT_2 "Ressources/MC/Skeleton/Walk/Right/2.png"
#define SKELETON_WALK_FRAME_RIGHT_3 "Ressources/MC/Skeleton/Walk/Right/3.png"
#define SKELETON_WALK_FRAME_RIGHT_4 "Ressources/MC/Skeleton/Walk/Right/4.png"
#define SKELETON_WALK_FRAME_RIGHT_5 "Ressources/MC/Skeleton/Walk/Right/5.png"
#define SKELETON_WALK_FRAME_RIGHT_6 "Ressources/MC/Skeleton/Walk/Right/6.png"
#define SKELETON_WALK_FRAME_RIGHT_7 "Ressources/MC/Skeleton/Walk/Right/7.png"
#define SKELETON_WALK_FRAME_RIGHT_8 "Ressources/MC/Skeleton/Walk/Right/8.png"
#define SKELETON_WALK_FRAME_RIGHT_9 "Ressources/MC/Skeleton/Walk/Right/9.png"
#define SKELETON_WALK_FRAME_RIGHT_10 "Ressources/MC/Skeleton/Walk/Right/10.png"
#define SKELETON_WALK_FRAME_RIGHT_11 "Ressources/MC/Skeleton/Walk/Right/11.png"
#define SKELETON_WALK_FRAME_RIGHT_12 "Ressources/MC/Skeleton/Walk/Right/12.png"
#define SKELETON_WALK_FRAME_LEFT_1 "Ressources/MC/Skeleton/Walk/Left/1.png"
#define SKELETON_WALK_FRAME_LEFT_2 "Ressources/MC/Skeleton/Walk/Left/2.png"
#define SKELETON_WALK_FRAME_LEFT_3 "Ressources/MC/Skeleton/Walk/Left/3.png"
#define SKELETON_WALK_FRAME_LEFT_4 "Ressources/MC/Skeleton/Walk/Left/4.png"
#define SKELETON_WALK_FRAME_LEFT_5 "Ressources/MC/Skeleton/Walk/Left/5.png"
#define SKELETON_WALK_FRAME_LEFT_6 "Ressources/MC/Skeleton/Walk/Left/6.png"
#define SKELETON_WALK_FRAME_LEFT_7 "Ressources/MC/Skeleton/Walk/Left/7.png"
#define SKELETON_WALK_FRAME_LEFT_8 "Ressources/MC/Skeleton/Walk/Left/8.png"
#define SKELETON_WALK_FRAME_LEFT_9 "Ressources/MC/Skeleton/Walk/Left/9.png"
#define SKELETON_WALK_FRAME_LEFT_10 "Ressources/MC/Skeleton/Walk/Left/10.png"
#define SKELETON_WALK_FRAME_LEFT_11 "Ressources/MC/Skeleton/Walk/Left/11.png"
#define SKELETON_WALK_FRAME_LEFT_12 "Ressources/MC/Skeleton/Walk/Left/12.png"