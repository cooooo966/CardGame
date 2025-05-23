#include "StackCardController.h"

StackCardController* StackCardController::create(StackCardModel* model, CardDirectType cardDirect) {
    StackCardController* ret = new (std::nothrow) StackCardController();
    if (ret && ret->init(model,cardDirect)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    ret = nullptr;
    return nullptr;
}

bool StackCardController::init(StackCardModel* model, CardDirectType cardDirect) {
    _model = model;

    // ע�����ص�
    /*_view->setOnCardClickedCallback([this](CardView* cardView) {
        this->onCardClicked(cardView);
        });*/
    auto stackCardView = StackCardView::create(_model, cardDirect);
    if (!stackCardView) {
        return false;
    }
    _view = stackCardView;
    // ��ʼ��չʾ��ǰģ���еĿ���
    _view->refresh();
    return true;
}

void StackCardController::onCardClicked(CardView* cardView) {
    // ʾ������ӡ����Ŀ�����Ϣ
    //const CardModel* model = cardView->getModel();
    //CCLOG("Card clicked: suit=%d, face=%d", model->getSuit(), model->getFace());

    // ʵ��ҵ���߼�������Ҫ����
}

void StackCardController::addCard(CardModel* card) {
    if (_model) {
        _model->addCard(card);
        _view->refresh();
    }
}

void StackCardController::removeCard(CardModel* card) {
    if (_model) {
        _model->removeCard(card);
        _view->refresh();
    }
}
