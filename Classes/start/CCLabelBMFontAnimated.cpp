#include "CCLabelBMFontAnimated.h"

//CREATE FUNCTIONS

CCLabelBMFontAnimated* CCLabelBMFontAnimated::createWithBMFont(const std::string& bmfontFilePath, const std::string& text, const cocos2d::TextHAlignment& alignment /* = TextHAlignment::LEFT */, int maxLineWidth /* = 0 */, const cocos2d::Vec2& imageOffset /* = Vec2::ZERO */)
{
	auto ret = new CCLabelBMFontAnimated();

	if (ret && ret->setBMFontFilePath(bmfontFilePath, imageOffset))
	{
		ret->setMaxLineWidth(maxLineWidth);
		ret->setString(text);
		ret->autorelease();

		return ret;
	}

	delete ret;
	return nullptr;
}

CCLabelBMFontAnimated* CCLabelBMFontAnimated::createWithTTF(const std::string& text, const std::string& fontFile, float fontSize, const cocos2d::Size& dimensions /* = Size::ZERO */, cocos2d::TextHAlignment hAlignment /* = TextHAlignment::LEFT */, cocos2d::TextVAlignment vAlignment /* = TextVAlignment::TOP */)
{
	auto ret = new (std::nothrow) CCLabelBMFontAnimated();

	if (ret && cocos2d::FileUtils::getInstance()->isFileExist(fontFile))
	{
		cocos2d::TTFConfig ttfConfig(fontFile.c_str(), fontSize, cocos2d::GlyphCollection::DYNAMIC);
		if (ret->setTTFConfig(ttfConfig))
		{
			ret->setAlignment(hAlignment, vAlignment);
			ret->setDimensions(dimensions.width, dimensions.height);
			ret->setString(text);

			ret->autorelease();

			return ret;
		}
	}

	delete ret;
	return nullptr;
}

#pragma mark - Set Basic Character Properties

void CCLabelBMFontAnimated::setCharScale(int index, float s) {

	if (index >= numLetters()) {
		cocos2d::log("CCLabelBMFontAnimated - Could not set character sprite scale, index out of bounds");
		return;
	}

	cocos2d::Sprite *charSprite = getLetter(index);
	charSprite->setScale(s);
}

void CCLabelBMFontAnimated::setCharOpacity(int index, float o) {

	if (index >= numLetters()) {
		cocos2d::log("CCLabelBMFontAnimated - Could not set character sprite opacity, index out of bounds");
		return;
	}

	GLubyte opacity = o;
	cocos2d::Sprite *charSprite = getLetter(index);
	charSprite->setOpacity(opacity);
}

void CCLabelBMFontAnimated::setCharRotation(int index, float r) {

	if (index >= numLetters()) {
		cocos2d::log("CCLabelBMFontAnimated - Could not set character sprite rotation, index out of bounds");
		return;
	}

	cocos2d::Sprite *charSprite = getLetter(index);
	charSprite->setRotation(r);
}


void CCLabelBMFontAnimated::setAllCharsScale(float s) {

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Sprite *charSprite = getLetter(i);
		if (charSprite == nullptr)
		{
			continue;
		}
		charSprite->setScale(s);
	}
}


void CCLabelBMFontAnimated::setAllCharsOpacity(float o) {

	GLubyte opacity = o;

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Sprite *charSprite = getLetter(i);
		charSprite->setOpacity(opacity);
	}
}

void CCLabelBMFontAnimated::setAllCharsRotation(float r) {

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Sprite *charSprite = getLetter(i);
		charSprite->setRotation(r);
	}
}

void CCLabelBMFontAnimated::offsetAllCharsPositionBy(cocos2d::Point offset) {

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Sprite *charSprite = getLetter(i);
		charSprite->setPosition(cocos2d::Point(charSprite->getPosition().x + offset.x, charSprite->getPosition().y + offset.y));
	}
}

int CCLabelBMFontAnimated::numLetters() {

	int index = 0;

	for (; ; ) {

		if (getLetter(index) == nullptr) {
			index++;
			if (getLetter(index) == nullptr) {
				return index;
			}
		}
		index++;
	}

	return index;
}

#pragma mark - Run Custom Actions

void CCLabelBMFontAnimated::runActionOnSpriteAtIndex(int index, cocos2d::FiniteTimeAction* action) {

	if (index >= numLetters() || index < 0) {
		cocos2d::log("CCLabelBMFontAnimated::runActionOnSpriteAtIndex - index out of bounds");
		return;
	}

	cocos2d::Sprite *charSprite = getLetter(index);
	charSprite->runAction(action);

}


void CCLabelBMFontAnimated::runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion) {

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Action *actionCopy = action->clone();
		cocos2d::Sprite *charSprite = getLetter(i);

		if (i == numChars - 1) { //if is the last character, run the call func actions

								 //cocos2d::Array *actionsArray = cocos2d::Array::create();
			cocos2d::Vector<cocos2d::FiniteTimeAction*> actionsArray;

			actionsArray.pushBack((cocos2d::FiniteTimeAction*)actionCopy);

			//actionsArray->addObject(actionCopy);

			if (callFuncOnCompletion != nullptr) {
				actionsArray.pushBack((cocos2d::FiniteTimeAction*)callFuncOnCompletion);
				//actionsArray->addObject(callFuncOnCompletion);
			}
			if (removeOnCompletion) {
				actionsArray.pushBack(cocos2d::CallFunc::create(CC_CALLBACK_0(CCLabelBMFontAnimated::removeFromParent, this)));
			}
			cocos2d::Sequence *actionsSequence = cocos2d::Sequence::create(actionsArray);
			charSprite->runAction(actionsSequence);
		}
		else { //if is not the last character, just run the action
			charSprite->runAction(actionCopy);
		}
	}
}

void CCLabelBMFontAnimated::runActionOnAllSprites(cocos2d::Action* action) {

	runActionOnAllSprites(action, false, nullptr);

}

void CCLabelBMFontAnimated::runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion) {

	runActionOnAllSprites(action, removeOnCompletion, nullptr);

}

void CCLabelBMFontAnimated::stopActionsOnAllSprites() {

	const int numChars = numLetters();

	for (int i = 0; i < numChars; i++) {
		cocos2d::Sprite *charSprite = getLetter(i);
		charSprite->stopAllActions();
	}
}


void CCLabelBMFontAnimated::runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion) {

	const int numChars = numLetters();

	if (numChars < 2) {
		cocos2d::log("CCLabelBMFontAnimated - runActionOnAllSpritesSequentially() requires at least 2 children to operate");
		return;
	}

	for (int i = 0; i < numChars; i++) {

		cocos2d::DelayTime *delay = cocos2d::DelayTime::create((duration / (numChars - 1)) *i);
		cocos2d::Action *actionCopy = action->clone();
		cocos2d::Sequence *delayAndAction = cocos2d::Sequence::create(delay, actionCopy, NULL);
		cocos2d::Sprite *charSprite = getLetter(i);

		if (i == numChars - 1) { //if is the last character, run the call func actions

			cocos2d::Vector<cocos2d::FiniteTimeAction*> actionsArray;
			actionsArray.pushBack(delayAndAction);

			if (callFuncOnCompletion != nullptr) {
				actionsArray.pushBack(callFuncOnCompletion);
			}
			if (removeOnCompletion) {
				actionsArray.pushBack(cocos2d::CallFunc::create(CC_CALLBACK_0(CCLabelBMFontAnimated::removeFromParent, this)));
			}
			cocos2d::Sequence *actionsSequence = cocos2d::Sequence::create(actionsArray);
			if (charSprite == nullptr)
			{
				continue;
			}
			charSprite->runAction(actionsSequence);
		}
		else { //if is not the last character, just run the action
			if (charSprite == nullptr)
			{
				continue;
			}
			charSprite->runAction(delayAndAction);
		}

	}
}

void CCLabelBMFontAnimated::runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion) {

	runActionOnAllSpritesSequentially(action, duration, removeOnCompletion, nullptr);

}

void CCLabelBMFontAnimated::runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration) {

	runActionOnAllSpritesSequentially(action, duration, false, nullptr);

}

void CCLabelBMFontAnimated::runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion) {

	const int numChars = numLetters();

	if (numChars < 2) {
		cocos2d::log("CCLabelBMFontAnimated - runActionOnAllSpritesSequentiallyReverse() requires at least 2 children to operate");
		return;
	}

	for (int i = 0; i < numChars; i++) {

		cocos2d::DelayTime *delay = cocos2d::DelayTime::create((duration / (numChars - 1)) *((numChars - 1) - i));
		cocos2d::Action *actionCopy = action->clone();
		cocos2d::Sequence *delayAndAction = cocos2d::Sequence::create(delay, actionCopy, NULL);
		cocos2d::Sprite *charSprite = getLetter(i);

		if (i == 0) { //if is the first character, run the call func actions

			cocos2d::Vector<cocos2d::FiniteTimeAction*> actionsArray;
			actionsArray.pushBack(delayAndAction);

			if (callFuncOnCompletion != nullptr) {
				actionsArray.pushBack(callFuncOnCompletion);
			}
			if (removeOnCompletion) {
				actionsArray.pushBack(cocos2d::CallFunc::create(CC_CALLBACK_0(CCLabelBMFontAnimated::removeFromParent, this)));
			}
			cocos2d::Sequence *actionsSequence = cocos2d::Sequence::create(actionsArray);
			charSprite->runAction(actionsSequence);
		}
		else { //if is not the first character, just run the action
			charSprite->runAction(delayAndAction);
		}
	}

}

void CCLabelBMFontAnimated::runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion) {

	runActionOnAllSpritesSequentiallyReverse(action, duration, removeOnCompletion, nullptr);

}

void CCLabelBMFontAnimated::runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration) {

	runActionOnAllSpritesSequentiallyReverse(action, duration, false, nullptr);

}


#pragma mark Animations

void CCLabelBMFontAnimated::animateInTypewriter(float duration) {

	//set all the characters scale to zero
	setAllCharsScale(0);

	cocos2d::ScaleTo *appear = cocos2d::ScaleTo::create(0, 1);

	runActionOnAllSpritesSequentially(appear, duration);

}
