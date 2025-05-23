#include "StackCardView.h"

USING_NS_CC;

StackCardView* StackCardView::create(const StackCardModel* model, const CardDirectType cardDirect) {
    StackCardView* view = new (std::nothrow) StackCardView();
    if (view && view->init(model,cardDirect)) {
        view->autorelease();
        return view;
    }
    CC_SAFE_DELETE(view);
    return nullptr;
}

bool StackCardView::init(const StackCardModel* model, const CardDirectType cardDirect) {
    if (!Node::init()) {
        return false;
    }

    _model = model;
    _cardDirect = cardDirect;

    createCardViews();

    return true;
}

void StackCardView::createCardViews() {
    // �������ͼ
    for (auto cardView : _cardViews) {
        this->removeChild(cardView);
    }
    _cardViews.clear();

    // ���� model ��������� CardView
    const auto& cards = _model->getCards();
    for (size_t i = 0; i < cards.size(); ++i) {
        CardView* cardView = CardView::create(cards[i]);
        if (cardView) {
            // ���ÿ���λ�ã�б�����Ų���
            float spacingX = _cardDirect == CardDirectType::CDT_LEFT ? -60.0f:60.0f; // ������
            float spacingY = -200.0f; // �����ࣨ������ʾ���£�
            cardView->setPosition(Vec2(i * spacingX, i * spacingY));

            this->addChild(cardView);
            _cardViews.push_back(cardView);

        }

        //// ���õ���¼�
        //cardView->setOnClickCallback([this, cardView]() {
        //    if (_onCardClicked) {
        //        _onCardClicked(cardView);
        //    }
        //    });
    }
}

void StackCardView::refresh() {
    createCardViews();
}

void StackCardView::addCard(CardView* cardView) {
    _cardViews.push_back(cardView);
    this->addChild(cardView);
    refresh();
}

void StackCardView::removeCard(CardView* cardView) {
    auto it = std::find(_cardViews.begin(), _cardViews.end(), cardView);
    if (it != _cardViews.end()) {
        this->removeChild(cardView);
        _cardViews.erase(it);
        refresh();
    }
}

// ע�⣺��Ҫ���� setOnCardClickedCallback ʵ��
// ���� .cpp �ļ�β��
//void PlayFieldView::setOnCardClickedCallback(const std::function<void(CardView*)>& callback) {
//    _onCardClicked = callback;
//}
