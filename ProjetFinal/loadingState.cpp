#include "loadingState.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
loadingState::loadingState(gameDataRef data) : _data(data)
{
	_frameIterator = 0;
}

/// <summary>
/// 
/// </summary>
loadingState::~loadingState()
{
}

/// <summary>
/// 
/// </summary>
void loadingState::init()
{
	srand(time(NULL));

	// Progress bar
	_data->assets.loadTexture("progress bar 1", LOADING_FRAME_1);
	_data->assets.loadTexture("progress bar 2", LOADING_FRAME_2);
	_data->assets.loadTexture("progress bar 3", LOADING_FRAME_3);
	_data->assets.loadTexture("progress bar 4", LOADING_FRAME_4);

	for (int i = 1; i <= 4; i++) {
		_animationProgressBar.push_back(_data->assets.getTexture("progress bar " + to_string(i)));
	}

	_progressBarSprite.setTexture(_animationProgressBar[0]);
	_progressBarSprite.setScale(5.0f, 5.0f);
	_progressBarSprite.setPosition((SCREEN_WIDTH / 2) - (_progressBarSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_progressBarSprite.getGlobalBounds().height / 2));

	// Background
	_data->assets.loadTexture("game background 1", GAME_BACKGROUND_TEMP_1);
	_data->assets.loadTexture("game background 2", GAME_BACKGROUND_TEMP_2);
	_data->assets.loadTexture("game background 3", GAME_BACKGROUND_TEMP_3);

	// Pop up
	_data->assets.loadTexture("pop up", POP_UP);
	_data->assets.loadTexture("accept purchase", ACCEPT_PURCHASE);

	// Walls
	_data->assets.loadTexture("wall up 1", GAME_FOREGROUND_UP_DOWN_TEMP_1);
	_data->assets.loadTexture("wall down 1", GAME_FOREGROUND_UP_DOWN_TEMP_1);
	_data->assets.loadTexture("wall left 1", GAME_FOREGROUND_LEFT_RIGHT_TEMP_1);
	_data->assets.loadTexture("wall right 1", GAME_FOREGROUND_LEFT_RIGHT_TEMP_1);
	_data->assets.loadTexture("wall up 2", GAME_FOREGROUND_UP_DOWN_TEMP_2);
	_data->assets.loadTexture("wall down 2", GAME_FOREGROUND_UP_DOWN_TEMP_2);
	_data->assets.loadTexture("wall left 2", GAME_FOREGROUND_LEFT_RIGHT_TEMP_2);
	_data->assets.loadTexture("wall right 2", GAME_FOREGROUND_LEFT_RIGHT_TEMP_2);
	_data->assets.loadTexture("wall up 3", GAME_FOREGROUND_UP_DOWN_TEMP_3);
	_data->assets.loadTexture("wall down 3", GAME_FOREGROUND_UP_DOWN_TEMP_3);
	_data->assets.loadTexture("wall left 3", GAME_FOREGROUND_LEFT_RIGHT_TEMP_3);
	_data->assets.loadTexture("wall right 3", GAME_FOREGROUND_LEFT_RIGHT_TEMP_3);

	// Hud
	_data->assets.loadTexture("life hearts", GAME_HEARTS_FILEPATH);
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);			// A ENLEVER LORSQUE LE JEU EST COMPLET
	_data->assets.loadTexture("coin", GAME_COIN_FILEPATH);
	_data->assets.loadTexture("kills", GAME_KILLS_FILEPATH);

	// Main character
	#pragma region Main Character
	// Idle
		_data->assets.loadTexture("skeleton idle frame right 1", SKELETON_IDLE_FRAME_RIGHT_1);
		_data->assets.loadTexture("skeleton idle frame right 2", SKELETON_IDLE_FRAME_RIGHT_2);
		_data->assets.loadTexture("skeleton idle frame right 3", SKELETON_IDLE_FRAME_RIGHT_3);
		_data->assets.loadTexture("skeleton idle frame right 4", SKELETON_IDLE_FRAME_RIGHT_4);
		_data->assets.loadTexture("skeleton idle frame right 5", SKELETON_IDLE_FRAME_RIGHT_5);
		_data->assets.loadTexture("skeleton idle frame right 6", SKELETON_IDLE_FRAME_RIGHT_6);
		_data->assets.loadTexture("skeleton idle frame right 7", SKELETON_IDLE_FRAME_RIGHT_7);
		_data->assets.loadTexture("skeleton idle frame right 8", SKELETON_IDLE_FRAME_RIGHT_8);
		_data->assets.loadTexture("skeleton idle frame right 9", SKELETON_IDLE_FRAME_RIGHT_9);
		_data->assets.loadTexture("skeleton idle frame right 10", SKELETON_IDLE_FRAME_RIGHT_10);
		_data->assets.loadTexture("skeleton idle frame right 11", SKELETON_IDLE_FRAME_RIGHT_11);

		_data->assets.loadTexture("skeleton idle frame left 1", SKELETON_IDLE_FRAME_LEFT_1);
		_data->assets.loadTexture("skeleton idle frame left 2", SKELETON_IDLE_FRAME_LEFT_2);
		_data->assets.loadTexture("skeleton idle frame left 3", SKELETON_IDLE_FRAME_LEFT_3);
		_data->assets.loadTexture("skeleton idle frame left 4", SKELETON_IDLE_FRAME_LEFT_4);
		_data->assets.loadTexture("skeleton idle frame left 5", SKELETON_IDLE_FRAME_LEFT_5);
		_data->assets.loadTexture("skeleton idle frame left 6", SKELETON_IDLE_FRAME_LEFT_6);
		_data->assets.loadTexture("skeleton idle frame left 7", SKELETON_IDLE_FRAME_LEFT_7);
		_data->assets.loadTexture("skeleton idle frame left 8", SKELETON_IDLE_FRAME_LEFT_8);
		_data->assets.loadTexture("skeleton idle frame left 9", SKELETON_IDLE_FRAME_LEFT_9);
		_data->assets.loadTexture("skeleton idle frame left 10", SKELETON_IDLE_FRAME_LEFT_10);
		_data->assets.loadTexture("skeleton idle frame left 11", SKELETON_IDLE_FRAME_LEFT_11);

		// Walking
		_data->assets.loadTexture("skeleton walking frame left1", SKELETON_WALK_FRAME_LEFT_1);
		_data->assets.loadTexture("skeleton walking frame left2", SKELETON_WALK_FRAME_LEFT_2);
		_data->assets.loadTexture("skeleton walking frame left3", SKELETON_WALK_FRAME_LEFT_3);
		_data->assets.loadTexture("skeleton walking frame left4", SKELETON_WALK_FRAME_LEFT_4);
		_data->assets.loadTexture("skeleton walking frame left5", SKELETON_WALK_FRAME_LEFT_5);
		_data->assets.loadTexture("skeleton walking frame left6", SKELETON_WALK_FRAME_LEFT_6);
		_data->assets.loadTexture("skeleton walking frame left7", SKELETON_WALK_FRAME_LEFT_7);
		_data->assets.loadTexture("skeleton walking frame left8", SKELETON_WALK_FRAME_LEFT_8);
		_data->assets.loadTexture("skeleton walking frame left9", SKELETON_WALK_FRAME_LEFT_9);
		_data->assets.loadTexture("skeleton walking frame left10", SKELETON_WALK_FRAME_LEFT_10);
		_data->assets.loadTexture("skeleton walking frame left11", SKELETON_WALK_FRAME_LEFT_11);
		_data->assets.loadTexture("skeleton walking frame left12", SKELETON_WALK_FRAME_LEFT_12);

		_data->assets.loadTexture("skeleton walking frame right1", SKELETON_WALK_FRAME_RIGHT_1);
		_data->assets.loadTexture("skeleton walking frame right2", SKELETON_WALK_FRAME_RIGHT_2);
		_data->assets.loadTexture("skeleton walking frame right3", SKELETON_WALK_FRAME_RIGHT_3);
		_data->assets.loadTexture("skeleton walking frame right4", SKELETON_WALK_FRAME_RIGHT_4);
		_data->assets.loadTexture("skeleton walking frame right5", SKELETON_WALK_FRAME_RIGHT_5);
		_data->assets.loadTexture("skeleton walking frame right6", SKELETON_WALK_FRAME_RIGHT_6);
		_data->assets.loadTexture("skeleton walking frame right7", SKELETON_WALK_FRAME_RIGHT_7);
		_data->assets.loadTexture("skeleton walking frame right8", SKELETON_WALK_FRAME_RIGHT_8);
		_data->assets.loadTexture("skeleton walking frame right9", SKELETON_WALK_FRAME_RIGHT_9);
		_data->assets.loadTexture("skeleton walking frame right10", SKELETON_WALK_FRAME_RIGHT_10);
		_data->assets.loadTexture("skeleton walking frame right11", SKELETON_WALK_FRAME_RIGHT_11);
		_data->assets.loadTexture("skeleton walking frame right12", SKELETON_WALK_FRAME_RIGHT_12);

		// Attacking
		_data->assets.loadTexture("skeleton attacking frame right1", SKELETON_ATTAQUE_FRAME_RIGHT_1);
		_data->assets.loadTexture("skeleton attacking frame right2", SKELETON_ATTAQUE_FRAME_RIGHT_2);
		_data->assets.loadTexture("skeleton attacking frame right3", SKELETON_ATTAQUE_FRAME_RIGHT_3);
		_data->assets.loadTexture("skeleton attacking frame right4", SKELETON_ATTAQUE_FRAME_RIGHT_4);
		_data->assets.loadTexture("skeleton attacking frame right5", SKELETON_ATTAQUE_FRAME_RIGHT_5);
		_data->assets.loadTexture("skeleton attacking frame right6", SKELETON_ATTAQUE_FRAME_RIGHT_6);
		_data->assets.loadTexture("skeleton attacking frame right7", SKELETON_ATTAQUE_FRAME_RIGHT_7);
		_data->assets.loadTexture("skeleton attacking frame right8", SKELETON_ATTAQUE_FRAME_RIGHT_8);
		_data->assets.loadTexture("skeleton attacking frame right9", SKELETON_ATTAQUE_FRAME_RIGHT_9);
		_data->assets.loadTexture("skeleton attacking frame right10", SKELETON_ATTAQUE_FRAME_RIGHT_10);
		_data->assets.loadTexture("skeleton attacking frame right11", SKELETON_ATTAQUE_FRAME_RIGHT_11);
		_data->assets.loadTexture("skeleton attacking frame right12", SKELETON_ATTAQUE_FRAME_RIGHT_12);
		_data->assets.loadTexture("skeleton attacking frame right13", SKELETON_ATTAQUE_FRAME_RIGHT_13);
		_data->assets.loadTexture("skeleton attacking frame right14", SKELETON_ATTAQUE_FRAME_RIGHT_14);
		_data->assets.loadTexture("skeleton attacking frame right15", SKELETON_ATTAQUE_FRAME_RIGHT_15);
		_data->assets.loadTexture("skeleton attacking frame right16", SKELETON_ATTAQUE_FRAME_RIGHT_16);
		_data->assets.loadTexture("skeleton attacking frame right17", SKELETON_ATTAQUE_FRAME_RIGHT_17);
		_data->assets.loadTexture("skeleton attacking frame right18", SKELETON_ATTAQUE_FRAME_RIGHT_18);

		_data->assets.loadTexture("skeleton attacking frame left1", SKELETON_ATTAQUE_FRAME_LEFT_1);
		_data->assets.loadTexture("skeleton attacking frame left2", SKELETON_ATTAQUE_FRAME_LEFT_2);
		_data->assets.loadTexture("skeleton attacking frame left3", SKELETON_ATTAQUE_FRAME_LEFT_3);
		_data->assets.loadTexture("skeleton attacking frame left4", SKELETON_ATTAQUE_FRAME_LEFT_4);
		_data->assets.loadTexture("skeleton attacking frame left5", SKELETON_ATTAQUE_FRAME_LEFT_5);
		_data->assets.loadTexture("skeleton attacking frame left6", SKELETON_ATTAQUE_FRAME_LEFT_6);
		_data->assets.loadTexture("skeleton attacking frame left7", SKELETON_ATTAQUE_FRAME_LEFT_7);
		_data->assets.loadTexture("skeleton attacking frame left8", SKELETON_ATTAQUE_FRAME_LEFT_8);
		_data->assets.loadTexture("skeleton attacking frame left9", SKELETON_ATTAQUE_FRAME_LEFT_9);
		_data->assets.loadTexture("skeleton attacking frame left10", SKELETON_ATTAQUE_FRAME_LEFT_10);
		_data->assets.loadTexture("skeleton attacking frame left11", SKELETON_ATTAQUE_FRAME_LEFT_11);
		_data->assets.loadTexture("skeleton attacking frame left12", SKELETON_ATTAQUE_FRAME_LEFT_12);
		_data->assets.loadTexture("skeleton attacking frame left13", SKELETON_ATTAQUE_FRAME_LEFT_13);
		_data->assets.loadTexture("skeleton attacking frame left14", SKELETON_ATTAQUE_FRAME_LEFT_14);
		_data->assets.loadTexture("skeleton attacking frame left15", SKELETON_ATTAQUE_FRAME_LEFT_15);
		_data->assets.loadTexture("skeleton attacking frame left16", SKELETON_ATTAQUE_FRAME_LEFT_16);
		_data->assets.loadTexture("skeleton attacking frame left17", SKELETON_ATTAQUE_FRAME_LEFT_17);
		_data->assets.loadTexture("skeleton attacking frame left18", SKELETON_ATTAQUE_FRAME_LEFT_18);

		// Hit
		_data->assets.loadTexture("skeleton hit frame right 1", SKELETON_HIT_FRAME_RIGHT_1);
		_data->assets.loadTexture("skeleton hit frame right 2", SKELETON_HIT_FRAME_RIGHT_2);
		_data->assets.loadTexture("skeleton hit frame right 3", SKELETON_HIT_FRAME_RIGHT_3);
		_data->assets.loadTexture("skeleton hit frame right 4", SKELETON_HIT_FRAME_RIGHT_4);
		_data->assets.loadTexture("skeleton hit frame right 5", SKELETON_HIT_FRAME_RIGHT_5);
		_data->assets.loadTexture("skeleton hit frame right 6", SKELETON_HIT_FRAME_RIGHT_6);
		_data->assets.loadTexture("skeleton hit frame right 7", SKELETON_HIT_FRAME_RIGHT_7);
		_data->assets.loadTexture("skeleton hit frame right 8", SKELETON_HIT_FRAME_RIGHT_8);

		_data->assets.loadTexture("skeleton hit frame left 1", SKELETON_HIT_FRAME_LEFT_1);
		_data->assets.loadTexture("skeleton hit frame left 2", SKELETON_HIT_FRAME_LEFT_2);
		_data->assets.loadTexture("skeleton hit frame left 3", SKELETON_HIT_FRAME_LEFT_3);
		_data->assets.loadTexture("skeleton hit frame left 4", SKELETON_HIT_FRAME_LEFT_4);
		_data->assets.loadTexture("skeleton hit frame left 5", SKELETON_HIT_FRAME_LEFT_5);
		_data->assets.loadTexture("skeleton hit frame left 6", SKELETON_HIT_FRAME_LEFT_6);
		_data->assets.loadTexture("skeleton hit frame left 7", SKELETON_HIT_FRAME_LEFT_7);
		_data->assets.loadTexture("skeleton hit frame left 8", SKELETON_HIT_FRAME_LEFT_8);
	#pragma endregion

	// Guard
	#pragma region Guard
		_data->assets.loadTexture("lifeBar", LIFE_BAR_FILEPATH);
		// Idle
		_data->assets.loadTexture("guard idle frame left1", GUARD_IDLE_FRAME_LEFT_1);
		_data->assets.loadTexture("guard idle frame left2", GUARD_IDLE_FRAME_LEFT_2);
		_data->assets.loadTexture("guard idle frame left3", GUARD_IDLE_FRAME_LEFT_3);
		_data->assets.loadTexture("guard idle frame left4", GUARD_IDLE_FRAME_LEFT_4);
		_data->assets.loadTexture("guard idle frame left5", GUARD_IDLE_FRAME_LEFT_5);

		_data->assets.loadTexture("guard idle frame right1", GUARD_IDLE_FRAME_RIGHT_1);
		_data->assets.loadTexture("guard idle frame right2", GUARD_IDLE_FRAME_RIGHT_2);
		_data->assets.loadTexture("guard idle frame right3", GUARD_IDLE_FRAME_RIGHT_3);
		_data->assets.loadTexture("guard idle frame right4", GUARD_IDLE_FRAME_RIGHT_4);
		_data->assets.loadTexture("guard idle frame right5", GUARD_IDLE_FRAME_RIGHT_5);

		// Attack
		_data->assets.loadTexture("guard attack frame left1", GUARD_ATTACK_FRAME_LEFT_1);
		_data->assets.loadTexture("guard attack frame left2", GUARD_ATTACK_FRAME_LEFT_2);
		_data->assets.loadTexture("guard attack frame left3", GUARD_ATTACK_FRAME_LEFT_3);
		_data->assets.loadTexture("guard attack frame left4", GUARD_ATTACK_FRAME_LEFT_4);
		_data->assets.loadTexture("guard attack frame left5", GUARD_ATTACK_FRAME_LEFT_5);
		_data->assets.loadTexture("guard attack frame left6", GUARD_ATTACK_FRAME_LEFT_6);
		_data->assets.loadTexture("guard attack frame left7", GUARD_ATTACK_FRAME_LEFT_7);

		_data->assets.loadTexture("guard attack frame right1", GUARD_ATTACK_FRAME_RIGHT_1);
		_data->assets.loadTexture("guard attack frame right2", GUARD_ATTACK_FRAME_RIGHT_2);
		_data->assets.loadTexture("guard attack frame right3", GUARD_ATTACK_FRAME_RIGHT_3);
		_data->assets.loadTexture("guard attack frame right4", GUARD_ATTACK_FRAME_RIGHT_4);
		_data->assets.loadTexture("guard attack frame right5", GUARD_ATTACK_FRAME_RIGHT_5);
		_data->assets.loadTexture("guard attack frame right6", GUARD_ATTACK_FRAME_RIGHT_6);
		_data->assets.loadTexture("guard attack frame right7", GUARD_ATTACK_FRAME_RIGHT_7);

		// Walking 
		_data->assets.loadTexture("guard walking frame left1", GUARD_WALKING_FRAME_LEFT_1);
		_data->assets.loadTexture("guard walking frame left2", GUARD_WALKING_FRAME_LEFT_2);
		_data->assets.loadTexture("guard walking frame left3", GUARD_WALKING_FRAME_LEFT_3);
		_data->assets.loadTexture("guard walking frame left4", GUARD_WALKING_FRAME_LEFT_4);
		_data->assets.loadTexture("guard walking frame left5", GUARD_WALKING_FRAME_LEFT_5);
		_data->assets.loadTexture("guard walking frame left6", GUARD_WALKING_FRAME_LEFT_6);

		_data->assets.loadTexture("guard walking frame right1", GUARD_WALKING_FRAME_RIGHT_1);
		_data->assets.loadTexture("guard walking frame right2", GUARD_WALKING_FRAME_RIGHT_2);
		_data->assets.loadTexture("guard walking frame right3", GUARD_WALKING_FRAME_RIGHT_3);
		_data->assets.loadTexture("guard walking frame right4", GUARD_WALKING_FRAME_RIGHT_4);
		_data->assets.loadTexture("guard walking frame right5", GUARD_WALKING_FRAME_RIGHT_5);
		_data->assets.loadTexture("guard walking frame right6", GUARD_WALKING_FRAME_RIGHT_6);

		// Damaged 
		_data->assets.loadTexture("guard damaged frame left1", GUARD_HIT_LEFT_1);
		_data->assets.loadTexture("guard damaged frame left2", GUARD_HIT_LEFT_2);

		_data->assets.loadTexture("guard damaged frame right1", GUARD_HIT_RIGHT_1);
		_data->assets.loadTexture("guard damaged frame right2", GUARD_HIT_RIGHT_2);

		// Dying 
		_data->assets.loadTexture("guard dying frame left1", GUARD_DYING_LEFT_1);
		_data->assets.loadTexture("guard dying frame left2", GUARD_DYING_LEFT_2);
		_data->assets.loadTexture("guard dying frame left3", GUARD_DYING_LEFT_3);
		_data->assets.loadTexture("guard dying frame left4", GUARD_DYING_LEFT_4);
		_data->assets.loadTexture("guard dying frame left5", GUARD_DYING_LEFT_5);
		_data->assets.loadTexture("guard dying frame left6", GUARD_DYING_LEFT_6);

		_data->assets.loadTexture("guard dying frame right1", GUARD_DYING_RIGHT_1);
		_data->assets.loadTexture("guard dying frame right2", GUARD_DYING_RIGHT_2);
		_data->assets.loadTexture("guard dying frame right3", GUARD_DYING_RIGHT_3);
		_data->assets.loadTexture("guard dying frame right4", GUARD_DYING_RIGHT_4);
		_data->assets.loadTexture("guard dying frame right5", GUARD_DYING_RIGHT_5);
		_data->assets.loadTexture("guard dying frame right6", GUARD_DYING_RIGHT_6);

	#pragma endregion

	// Archer
	#pragma region Archer
		// Idle
		_data->assets.loadTexture("archer idle frame right 1", ARCHER_IDLE_FRAME_RIGHT_1);
		_data->assets.loadTexture("archer idle frame right 2", ARCHER_IDLE_FRAME_RIGHT_2);
		_data->assets.loadTexture("archer idle frame right 3", ARCHER_IDLE_FRAME_RIGHT_3);
		_data->assets.loadTexture("archer idle frame right 4", ARCHER_IDLE_FRAME_RIGHT_4);
		_data->assets.loadTexture("archer idle frame right 5", ARCHER_IDLE_FRAME_RIGHT_5);
		_data->assets.loadTexture("archer idle frame right 6", ARCHER_IDLE_FRAME_RIGHT_6);

		_data->assets.loadTexture("archer idle frame left 1", ARCHER_IDLE_FRAME_LEFT_1);
		_data->assets.loadTexture("archer idle frame left 2", ARCHER_IDLE_FRAME_LEFT_2);
		_data->assets.loadTexture("archer idle frame left 3", ARCHER_IDLE_FRAME_LEFT_3);
		_data->assets.loadTexture("archer idle frame left 4", ARCHER_IDLE_FRAME_LEFT_4);
		_data->assets.loadTexture("archer idle frame left 5", ARCHER_IDLE_FRAME_LEFT_5);
		_data->assets.loadTexture("archer idle frame left 6", ARCHER_IDLE_FRAME_LEFT_6);

		// Walking
		_data->assets.loadTexture("archer walking frame right 1", ARCHER_WALKING_FRAME_RIGHT_1);
		_data->assets.loadTexture("archer walking frame right 2", ARCHER_WALKING_FRAME_RIGHT_2);
		_data->assets.loadTexture("archer walking frame right 3", ARCHER_WALKING_FRAME_RIGHT_3);
		_data->assets.loadTexture("archer walking frame right 4", ARCHER_WALKING_FRAME_RIGHT_4);
		_data->assets.loadTexture("archer walking frame right 5", ARCHER_WALKING_FRAME_RIGHT_5);
		_data->assets.loadTexture("archer walking frame right 6", ARCHER_WALKING_FRAME_RIGHT_6);

		_data->assets.loadTexture("archer walking frame left 1", ARCHER_WALKING_FRAME_LEFT_1);
		_data->assets.loadTexture("archer walking frame left 2", ARCHER_WALKING_FRAME_LEFT_2);
		_data->assets.loadTexture("archer walking frame left 3", ARCHER_WALKING_FRAME_LEFT_3);
		_data->assets.loadTexture("archer walking frame left 4", ARCHER_WALKING_FRAME_LEFT_4);
		_data->assets.loadTexture("archer walking frame left 5", ARCHER_WALKING_FRAME_LEFT_5);
		_data->assets.loadTexture("archer walking frame left 6", ARCHER_WALKING_FRAME_LEFT_6);

		// Attack
		_data->assets.loadTexture("archer attack frame right 1", ARCHER_ATTACK_FRAME_RIGHT_1);
		_data->assets.loadTexture("archer attack frame right 2", ARCHER_ATTACK_FRAME_RIGHT_2);
		_data->assets.loadTexture("archer attack frame right 3", ARCHER_ATTACK_FRAME_RIGHT_3);
		_data->assets.loadTexture("archer attack frame right 4", ARCHER_ATTACK_FRAME_RIGHT_4);
		_data->assets.loadTexture("archer attack frame right 5", ARCHER_ATTACK_FRAME_RIGHT_5);
		_data->assets.loadTexture("archer attack frame right 6", ARCHER_ATTACK_FRAME_RIGHT_6);
		_data->assets.loadTexture("archer attack frame right 7", ARCHER_ATTACK_FRAME_RIGHT_7);

		_data->assets.loadTexture("archer attack frame left 1", ARCHER_ATTACK_FRAME_LEFT_1);
		_data->assets.loadTexture("archer attack frame left 2", ARCHER_ATTACK_FRAME_LEFT_2);
		_data->assets.loadTexture("archer attack frame left 3", ARCHER_ATTACK_FRAME_LEFT_3);
		_data->assets.loadTexture("archer attack frame left 4", ARCHER_ATTACK_FRAME_LEFT_4);
		_data->assets.loadTexture("archer attack frame left 5", ARCHER_ATTACK_FRAME_LEFT_5);
		_data->assets.loadTexture("archer attack frame left 6", ARCHER_ATTACK_FRAME_LEFT_6);
		_data->assets.loadTexture("archer attack frame left 7", ARCHER_ATTACK_FRAME_LEFT_7);

		// Damaged
		_data->assets.loadTexture("archer hit frame right 1", ARCHER_HIT_RIGHT_1);
		_data->assets.loadTexture("archer hit frame right 2", ARCHER_HIT_RIGHT_2);

		_data->assets.loadTexture("archer hit frame left 1", ARCHER_HIT_LEFT_1);
		_data->assets.loadTexture("archer hit frame left 2", ARCHER_HIT_LEFT_2);

		// Dying
		_data->assets.loadTexture("archer dying frame right 1", ARCHER_DYING_RIGHT_1);
		_data->assets.loadTexture("archer dying frame right 2", ARCHER_DYING_RIGHT_2);
		_data->assets.loadTexture("archer dying frame right 3", ARCHER_DYING_RIGHT_3);
		_data->assets.loadTexture("archer dying frame right 4", ARCHER_DYING_RIGHT_4);
		_data->assets.loadTexture("archer dying frame right 5", ARCHER_DYING_RIGHT_5);

		_data->assets.loadTexture("archer dying frame left 1", ARCHER_DYING_LEFT_1);
		_data->assets.loadTexture("archer dying frame left 2", ARCHER_DYING_LEFT_2);
		_data->assets.loadTexture("archer dying frame left 3", ARCHER_DYING_LEFT_3);
		_data->assets.loadTexture("archer dying frame left 4", ARCHER_DYING_LEFT_4);
		_data->assets.loadTexture("archer dying frame left 5", ARCHER_DYING_LEFT_5);
	#pragma endregion

	// Minotaur
	#pragma region Minotaur
		// Idle
		_data->assets.loadTexture("minotaur idle frame right 1", MINOTAUR_IDLE_FRAME_RIGHT_1);
		_data->assets.loadTexture("minotaur idle frame right 2", MINOTAUR_IDLE_FRAME_RIGHT_2);
		_data->assets.loadTexture("minotaur idle frame right 3", MINOTAUR_IDLE_FRAME_RIGHT_3);
		_data->assets.loadTexture("minotaur idle frame right 4", MINOTAUR_IDLE_FRAME_RIGHT_4);
		_data->assets.loadTexture("minotaur idle frame right 5", MINOTAUR_IDLE_FRAME_RIGHT_5);

		_data->assets.loadTexture("minotaur idle frame left 1", MINOTAUR_IDLE_FRAME_LEFT_1);
		_data->assets.loadTexture("minotaur idle frame left 2", MINOTAUR_IDLE_FRAME_LEFT_2);
		_data->assets.loadTexture("minotaur idle frame left 3", MINOTAUR_IDLE_FRAME_LEFT_3);
		_data->assets.loadTexture("minotaur idle frame left 4", MINOTAUR_IDLE_FRAME_LEFT_4);
		_data->assets.loadTexture("minotaur idle frame left 5", MINOTAUR_IDLE_FRAME_LEFT_5);

		// Walking
		_data->assets.loadTexture("minotaur walking frame right 1", MINOTAUR_WALKING_FRAME_RIGHT_1);
		_data->assets.loadTexture("minotaur walking frame right 2", MINOTAUR_WALKING_FRAME_RIGHT_2);
		_data->assets.loadTexture("minotaur walking frame right 3", MINOTAUR_WALKING_FRAME_RIGHT_3);
		_data->assets.loadTexture("minotaur walking frame right 4", MINOTAUR_WALKING_FRAME_RIGHT_4);
		_data->assets.loadTexture("minotaur walking frame right 5", MINOTAUR_WALKING_FRAME_RIGHT_5);
		_data->assets.loadTexture("minotaur walking frame right 6", MINOTAUR_WALKING_FRAME_RIGHT_6);

		_data->assets.loadTexture("minotaur walking frame left 1", MINOTAUR_WALKING_FRAME_LEFT_1);
		_data->assets.loadTexture("minotaur walking frame left 2", MINOTAUR_WALKING_FRAME_LEFT_2);
		_data->assets.loadTexture("minotaur walking frame left 3", MINOTAUR_WALKING_FRAME_LEFT_3);
		_data->assets.loadTexture("minotaur walking frame left 4", MINOTAUR_WALKING_FRAME_LEFT_4);
		_data->assets.loadTexture("minotaur walking frame left 5", MINOTAUR_WALKING_FRAME_LEFT_5);
		_data->assets.loadTexture("minotaur walking frame left 6", MINOTAUR_WALKING_FRAME_LEFT_6);

		// Attack 1
		_data->assets.loadTexture("minotaur attack 1 frame right 1", MINOTAUR_ATTACK_FRAME_RIGHT_1);
		_data->assets.loadTexture("minotaur attack 1 frame right 2", MINOTAUR_ATTACK_FRAME_RIGHT_2);
		_data->assets.loadTexture("minotaur attack 1 frame right 3", MINOTAUR_ATTACK_FRAME_RIGHT_3);
		_data->assets.loadTexture("minotaur attack 1 frame right 4", MINOTAUR_ATTACK_FRAME_RIGHT_4);
		_data->assets.loadTexture("minotaur attack 1 frame right 5", MINOTAUR_ATTACK_FRAME_RIGHT_5);
		_data->assets.loadTexture("minotaur attack 1 frame right 6", MINOTAUR_ATTACK_FRAME_RIGHT_6);
		_data->assets.loadTexture("minotaur attack 1 frame right 7", MINOTAUR_ATTACK_FRAME_RIGHT_7);
		_data->assets.loadTexture("minotaur attack 1 frame right 8", MINOTAUR_ATTACK_FRAME_RIGHT_8);
		_data->assets.loadTexture("minotaur attack 1 frame right 9", MINOTAUR_ATTACK_FRAME_RIGHT_9);
		_data->assets.loadTexture("minotaur attack 1 frame right 10", MINOTAUR_ATTACK_FRAME_RIGHT_10);

		_data->assets.loadTexture("minotaur attack 1 frame left 1", MINOTAUR_ATTACK_FRAME_LEFT_1);
		_data->assets.loadTexture("minotaur attack 1 frame left 2", MINOTAUR_ATTACK_FRAME_LEFT_2);
		_data->assets.loadTexture("minotaur attack 1 frame left 3", MINOTAUR_ATTACK_FRAME_LEFT_3);
		_data->assets.loadTexture("minotaur attack 1 frame left 4", MINOTAUR_ATTACK_FRAME_LEFT_4);
		_data->assets.loadTexture("minotaur attack 1 frame left 5", MINOTAUR_ATTACK_FRAME_LEFT_5);
		_data->assets.loadTexture("minotaur attack 1 frame left 6", MINOTAUR_ATTACK_FRAME_LEFT_6);
		_data->assets.loadTexture("minotaur attack 1 frame left 7", MINOTAUR_ATTACK_FRAME_LEFT_7);
		_data->assets.loadTexture("minotaur attack 1 frame left 8", MINOTAUR_ATTACK_FRAME_LEFT_8);
		_data->assets.loadTexture("minotaur attack 1 frame left 9", MINOTAUR_ATTACK_FRAME_LEFT_9);
		_data->assets.loadTexture("minotaur attack 1 frame left 10", MINOTAUR_ATTACK_FRAME_LEFT_10);

		// Damaged
		_data->assets.loadTexture("minotaur damaged frame left 1", MINOTAUR_HIT_LEFT_1);
		_data->assets.loadTexture("minotaur damaged frame left 2", MINOTAUR_HIT_LEFT_2);
		_data->assets.loadTexture("minotaur damaged frame left 3", MINOTAUR_HIT_LEFT_3);
		_data->assets.loadTexture("minotaur damaged frame left 4", MINOTAUR_HIT_LEFT_4);

		_data->assets.loadTexture("minotaur damaged frame right 1", MINOTAUR_HIT_RIGHT_1);
		_data->assets.loadTexture("minotaur damaged frame right 2", MINOTAUR_HIT_RIGHT_2);
		_data->assets.loadTexture("minotaur damaged frame right 3", MINOTAUR_HIT_RIGHT_3);
		_data->assets.loadTexture("minotaur damaged frame right 4", MINOTAUR_HIT_RIGHT_4);

		// Dying
		_data->assets.loadTexture("minotaur dying frame left 1", MINOTAUR_DYING_LEFT_1);
		_data->assets.loadTexture("minotaur dying frame left 2", MINOTAUR_DYING_LEFT_2);
		_data->assets.loadTexture("minotaur dying frame left 3", MINOTAUR_DYING_LEFT_3);
		_data->assets.loadTexture("minotaur dying frame left 4", MINOTAUR_DYING_LEFT_4);
		_data->assets.loadTexture("minotaur dying frame left 5", MINOTAUR_DYING_LEFT_5);
		_data->assets.loadTexture("minotaur dying frame left 6", MINOTAUR_DYING_LEFT_6);
		_data->assets.loadTexture("minotaur dying frame left 7", MINOTAUR_DYING_LEFT_7);
		_data->assets.loadTexture("minotaur dying frame left 8", MINOTAUR_DYING_LEFT_8);

		_data->assets.loadTexture("minotaur dying frame right 1", MINOTAUR_DYING_RIGHT_1);
		_data->assets.loadTexture("minotaur dying frame right 2", MINOTAUR_DYING_RIGHT_2);
		_data->assets.loadTexture("minotaur dying frame right 3", MINOTAUR_DYING_RIGHT_3);
		_data->assets.loadTexture("minotaur dying frame right 4", MINOTAUR_DYING_RIGHT_4);
		_data->assets.loadTexture("minotaur dying frame right 5", MINOTAUR_DYING_RIGHT_5);
		_data->assets.loadTexture("minotaur dying frame right 6", MINOTAUR_DYING_RIGHT_6);
		_data->assets.loadTexture("minotaur dying frame right 7", MINOTAUR_DYING_RIGHT_7);
		_data->assets.loadTexture("minotaur dying frame right 8", MINOTAUR_DYING_RIGHT_8);
	#pragma endregion

	// Store owner
	#pragma region Store owner
		// Idle
		_data->assets.loadTexture("store owner idle 1", STOREOWNER_IDLE_1);
		_data->assets.loadTexture("store owner idle 2", STOREOWNER_IDLE_2);
		_data->assets.loadTexture("store owner idle 3", STOREOWNER_IDLE_3);
		_data->assets.loadTexture("store owner idle 4", STOREOWNER_IDLE_4);
		_data->assets.loadTexture("store owner idle 5", STOREOWNER_IDLE_5);
		_data->assets.loadTexture("store owner idle 6", STOREOWNER_IDLE_6);
		_data->assets.loadTexture("store owner idle 7", STOREOWNER_IDLE_7);
		_data->assets.loadTexture("store owner idle 8", STOREOWNER_IDLE_8);
		_data->assets.loadTexture("store owner idle 9", STOREOWNER_IDLE_9);

		// Talking
		_data->assets.loadTexture("talking shop owner", TALKING_SHOP_OWNER);
	#pragma endregion

	// Cat
	_data->assets.loadTexture("cat 1", CAT_FRAME_1);
	_data->assets.loadTexture("cat 2", CAT_FRAME_2);
	_data->assets.loadTexture("cat 3", CAT_FRAME_3);

	// Carpet
	_data->assets.loadTexture("tapis", CARPET_STORE);

	// Items
	_data->assets.loadTexture("big life potion", BIG_LIFE_POTION);

	// Porte
	_data->assets.loadTexture("closed door 1", GAME_DOOR_CLOSED_1);
	_data->assets.loadTexture("closed door 2", GAME_DOOR_CLOSED_2);
	_data->assets.loadTexture("opened door", GAME_DOOR_OPEN);

	// Torches
	_data->assets.loadTexture("torch frame 1", TORCH_FRAME_1);
	_data->assets.loadTexture("torch frame 2", TORCH_FRAME_2);
	_data->assets.loadTexture("torch frame 3", TORCH_FRAME_3);
	_data->assets.loadTexture("torch frame 4", TORCH_FRAME_4);

	#pragma region animation Squelette Loading
		// Skeleton loading
		_data->assets.loadTexture("animation skeleton1", LOADING_SKELETON_FAME_1);
		_data->assets.loadTexture("animation skeleton2", LOADING_SKELETON_FAME_2);
		_data->assets.loadTexture("animation skeleton3", LOADING_SKELETON_FAME_3);
		_data->assets.loadTexture("animation skeleton4", LOADING_SKELETON_FAME_4);
		_data->assets.loadTexture("animation skeleton5", LOADING_SKELETON_FAME_5);
		_data->assets.loadTexture("animation skeleton6", LOADING_SKELETON_FAME_6);
		_data->assets.loadTexture("animation skeleton7", LOADING_SKELETON_FAME_7);
		_data->assets.loadTexture("animation skeleton8", LOADING_SKELETON_FAME_8);

		for (int i = 1; i <= 8; i++)
		{
			_animationSkeletonLoading.push_back(_data->assets.getTexture("animation skeleton" + to_string(i)));
		}

		_skeletonLoadingSprite.setTexture(_animationSkeletonLoading.at(_frameSkeletonIterator));
		_skeletonLoadingSprite.setScale(7.0f, 7.0f);
		_skeletonLoadingSprite.setPosition((SCREEN_WIDTH / 2) - (_skeletonLoadingSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_skeletonLoadingSprite.getGlobalBounds().height / 2 + 80));

	#pragma endregion

	// Background
	_backgroundSprite.setFillColor(Color::Black);
	_backgroundSprite.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}

/// <summary>
/// 
/// </summary>
void loadingState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Ferme la fenêtre
			_data->window.close();
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			_data->machine.addState(stateRef(new gameState(_data)), true);
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void loadingState::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > (LOADING_TIME / _animationProgressBar.size())) {
		_clock.restart();
		_frameIterator++;
		if (_frameIterator == _animationProgressBar.size()) {
			_data->machine.addState(stateRef(new gameState(_data)), true);
		}
		else {
			_progressBarSprite.setTexture(_animationProgressBar.at(_frameIterator));
		}
	}
	
	if (_clockSkeleton.getElapsedTime().asSeconds() > (LOADING_SKELETON_TIME/_animationSkeletonLoading.size()))
	{
		_frameSkeletonIterator++;
		if (_frameSkeletonIterator == _animationSkeletonLoading.size()){
			_frameSkeletonIterator = 0;
		}
		else{
			_skeletonLoadingSprite.setTexture(_animationSkeletonLoading.at(_frameSkeletonIterator));
		}
		_clockSkeleton.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void loadingState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_backgroundSprite);
	_data->window.draw(_loadingText);
	
	_data->window.draw(_progressBarSprite);
	_data->window.draw(_skeletonLoadingSprite);
	_data->window.display();
}