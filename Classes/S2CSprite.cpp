/**
*@file S2CSprite.cpp
*@brief ʵ�־������Ӿ��ε�Բ�μ以��ת�� ����ʵ�ַ�ʽ
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-5-26 16:24
*/
#include "S2CSprite.h"  

USING_NS_CC;

S2CSprite::S2CSprite()  
{  

}  

S2CSprite::~S2CSprite()  
{  
 	m_squareAction->release();
	m_textureCircle->release();
	m_textureSquare->release();
// 	m_openAnimOut->release();  
}  

///@brief �����������
///@param[in] squareName--����������� circleName----Բ��������� duration--ת��ʱ��
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-5-27 9:52
S2CSprite* S2CSprite::create(const char* squareName, const char* circleName, float duration)  
{  
	S2CSprite *pSprite = new S2CSprite();  
	if (pSprite && pSprite->init(squareName, circleName, duration))  
	{  
		pSprite->autorelease();  
		return pSprite;  
	}  
	CC_SAFE_DELETE(pSprite);  
	return NULL;  
}  

bool S2CSprite::init(const char* squareName, const char* circleName, float duration)  
{  
	if (!CCSprite::init())  
	{  
		return false;  
	}  
	initData(squareName, circleName, duration);  
	return true;  
}  

void S2CSprite::initData(const char* squareName, const char* circleName, float duration)  
{  
	m_bShape = true;	///< Ĭ����Ϊ����  

	m_textureSquare = CCTextureCache::sharedTextureCache()->addImage(squareName);
	m_textureSquare->retain();

	m_textureCircle = CCTextureCache::sharedTextureCache()->addImage(circleName);
	m_textureCircle->retain();

	CCSprite* sprite = CCSprite::createWithTexture(m_textureSquare);  
	sprite->setPosition(ccp(0, 0));  
	sprite->setVisible(true);  
	this->addChild(sprite, 1, TAGSPRITE);

	m_squareAction = (CCActionInterval*)CCSequence::create(CCDelayTime::create(duration * .5),  
		CCRotateTo::create(duration * .5, 360*4), 
		CCCallFunc::create(this, callfunc_selector(S2CSprite::change)),
		NULL);  
	
	m_squareAction->retain(); 

}  

///@brief ����ִ����ת����
///@param[in] 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-5-27 9:55
void S2CSprite::changeShape()
{
	CCSprite* sprite = (CCSprite*)getChildByTag(TAGSPRITE); 
	/// û��stop�Ļ����ٴ�openCard�����
	sprite->stopAllActions() ;

	sprite->runAction(m_squareAction); 
}

///@brief ��ת�������ı侫���������
///@param[in] 
///@return 
///@author DionysosLai,906391500@qq.com 
///@retval  
///@post 
///@version 1.0 
///@data 2014-5-27 9:54
void S2CSprite::change()
{
	if (m_bShape)
	{
		m_bShape = false;
		/// ���������ᱣ��ǰ��ĳ��Ϳ�Ҳ����sprite->setTexture(m_textureCircle);�������õ��������������Ҫ�������飬�����´����������
// 		CCSprite* sprite = (CCSprite*)getChildByTag(1); 
// 		sprite->setTexture(m_textureCircle);
		this->removeChildByTag(TAGSPRITE, true);
		CCSprite* sprite = CCSprite::createWithTexture(m_textureCircle);  
		sprite->setPosition(ccp(0, 0));  
		sprite->setVisible(true);  
		this->addChild(sprite, 1, TAGSPRITE);
	}
	else
	{		
		m_bShape = true;
// 		CCSprite* sprite = (CCSprite*)getChildByTag(1); 
// 		sprite->setTexture(m_textureSquare);
		this->removeChildByTag(TAGSPRITE, true);
		CCSprite* sprite = CCSprite::createWithTexture(m_textureSquare);  
		sprite->setPosition(ccp(0, 0));  
		sprite->setVisible(true);  
		this->addChild(sprite, 1, TAGSPRITE);
	}
}
