#pragma once
#include"cocos2d.h"
#include"views/GameView.h"
#include"models/PlayFieldModel.h"
#include"controllers/PlayFieldController.h"
#include"controllers/StackCardController.h"

class GameController :public cocos2d::Node
{
public:
	cocos2d::Scene* startGame(int levelId);

    static GameController* create();
    bool init();

private:
    //static void initControllers();
    //static void initViews();

    //static GameModel _model;
    GameView* _gameView;

    UndoModel* _undoModel;
    PlayFieldModel* _playFieldModel;

    //static PlayFieldModel* _playFieldModel;
    PlayFieldController* _playFieldController;
    StackCardController* _leftStackCardController;
    StackCardController* _rightStackCardController;
};
