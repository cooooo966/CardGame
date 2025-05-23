#include"GameController.h"
#include"models/PlayFieldModel.h"
#include"models/CardModel.h"
#include"views/CardView.h"
#include"views/PlayFieldView.h"
#include"controllers/PlayFieldController.h"
#include"configs/CardConfig.h"
//#include "configs/loaders/LevelConfigLoader.h"
//#include "services/GameModelFromLevelGenerator.h"

//GameModel GameController::_model;
//GameView* GameController::_gameView = nullptr;
//UndoModel* GameController::_undoModel = nullptr;
//PlayFieldModel* GameController::_playFieldModel = nullptr;
////PlayFieldModel* GameController::_playFieldModel=nullptr;
//PlayFieldController* GameController::_playFieldController = nullptr;
//StackCardController* GameController::_leftStackCardController = nullptr;
//StackCardController* GameController::_rightStackCardController = nullptr;
//StackController GameController::_stackController;

GameController* GameController::create() {
	GameController* ret = new (std::nothrow) GameController();
	if (ret && ret->init()) {
		ret->autorelease();
		//ret->retain();
		return ret;
	}
	delete ret;
	ret = nullptr;
	return nullptr;
}

bool GameController::init() {
	if (!Node::init()) {
		return false;
	}
	return true;
}


cocos2d::Scene* GameController::startGame(int levelId) {
	// 加载配置
	//LevelConfig config = LevelConfigLoader::loadLevelConfig(levelId);
	//_model = GameModelFromLevelGenerator::generateGameModel(config);

	// 直接使用 GameView 作为场景
	_gameView = GameView::create();
	//CCLOG("create()");
	// 在 GameController 初始化场景时：
	_undoModel = UndoModel::create();
	//手牌区
	_playFieldModel = PlayFieldModel::create();
	// 初始化一些 CardModel 加入桌牌区
	_playFieldModel->addCard(CardModel::create(CST_SPADES, CFT_FIVE));
	_playFieldModel->addCard(CardModel::create(CST_HEARTS, CFT_SIX));
	_playFieldModel->addCard(CardModel::create(CST_CLUBS, CFT_ACE));

	_playFieldController = PlayFieldController::create(_playFieldModel, _undoModel);
	_playFieldController->retain();

	auto playFieldView = _playFieldController->getView();
	_gameView->addPlayFieldViewToScene(playFieldView, cocos2d::Vec2(250, 375), 0.9);

	//桌牌区
	auto leftStackCardModel = StackCardModel::create();
	// 初始化一些 CardModel 加入桌牌区
	leftStackCardModel->addCard(CardModel::create(CST_SPADES, CFT_FIVE));
	leftStackCardModel->addCard(CardModel::create(CST_HEARTS, CFT_SIX));
	leftStackCardModel->addCard(CardModel::create(CST_CLUBS, CFT_ACE));

	auto rightStackCardModel = StackCardModel::create();
	// 初始化一些 CardModel 加入桌牌区
	rightStackCardModel->addCard(CardModel::create(CST_SPADES, CFT_FIVE));
	rightStackCardModel->addCard(CardModel::create(CST_HEARTS, CFT_SIX));
	rightStackCardModel->addCard(CardModel::create(CST_CLUBS, CFT_ACE));

	_leftStackCardController = StackCardController::create(leftStackCardModel, CardDirectType::CDT_RIGHT);
	_rightStackCardController = StackCardController::create(rightStackCardModel, CardDirectType::CDT_LEFT);

	auto leftStackCardView = _leftStackCardController->getView();
	auto rightStackCardView = _rightStackCardController->getView();

	_gameView->addLeftStackCardViewToScene(leftStackCardView, cocos2d::Vec2(250, 1500), 0.9, cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
	_gameView->addRightStackCardViewToScene(rightStackCardView, cocos2d::Vec2(800, 1500), 0.9, cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);

	//_stackController.init(&_model);
	//_playFieldController.init(&_model);

	//_stackController.initView(_view);
	//_playFieldController.initView(_view);

	return _gameView;
}