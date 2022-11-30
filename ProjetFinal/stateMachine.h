#pragma once

#include <memory>
#include <stack>
#include "state.hpp"

using namespace std;

typedef unique_ptr<state> stateRef;		// Un smartPointer de state
class stateMachine {
private:
	stack<stateRef> _states;			// Pile de pointeur pour empiler les fen�tres du jeu
	stateRef _newState;					// La fen�tre active
	bool _isRemoving;					// Flag pour savoir ce qui se passe ds la fen�tre
	bool _isAdding;
	bool _isReplacing;

public:
	void addState(stateRef newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();
	stateRef& getActiveState();			// Pas de const pour ce getteur, car il est setteur aussi
};