#include "PlayFieldController.h"

PlayFieldController* PlayFieldController::create(PlayFieldModel* model, UndoModel* undo) {
    PlayFieldController* ret = new (std::nothrow) PlayFieldController();
    if (ret && ret->init(model, undo)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    ret = nullptr;
    return nullptr;
}

bool PlayFieldController::init(PlayFieldModel* model, UndoModel* undo) {
    _model = model;
    _undo = undo;

    // ע�����ص�
    /*_view->setOnCardClickedCallback([this](CardView* cardView) {
        this->onCardClicked(cardView);
        });*/
    auto playFieldView = PlayFieldView::create(_model);
    if (!playFieldView) {
        return false;
    }
    _model->initCurHandCard();
    _view = playFieldView;
    // ��ʼ��չʾ��ǰģ���еĿ���
    // ���õ���¼��ص������� View �� Controller
    //_view->setOnCardClickedCallback(CC_CALLBACK_1(PlayFieldController::onCardClicked, this));
    _view->setOnCardClickedCallback([this](CardView* cardView) {
        this->onCardClicked(cardView);
        });
    _view->refresh();
    return true;
}

void PlayFieldController::onCardClicked(CardView* cardView) {
    CardModel* clickedModel = cardView->getModel();
    CardModel* handCard = _model->getCurHandCard();

    CCLOG("Controller got click on %s", clickedModel->getCardFaceString());
    //if (_model->isCardPlayable(clickedModel)) {
        // ��¼��ǰλ�ú�״̬
        cocos2d::Vec2 originalPos = cardView->getPosition();
        printf("%s %s is clicked!", clickedModel->getSuitName(), clickedModel->getCardFaceString());

        // �滻����
        //_undo->recordUndo(clickedModel, handCard, "PlayField", originalPos);
        //_model->setCurHandCard(clickedModel);

        // ��ͼ����
        _view->refresh();
    //}
}

void PlayFieldController::addCard(CardModel* card) {
    if (_model) {
        _model->addCard(card);
        _view->refresh();
    }
}

void PlayFieldController::removeCard(CardModel* card) {
    if (_model) {
        _model->removeCard(card);
        _view->refresh();
    }
}
