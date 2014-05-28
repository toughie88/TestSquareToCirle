/**
*@file S2CSprite.h
*@brief ʵ�־������Ӿ��ε�Բ�μ以��ת��
*
*��ϸ����
*
*@author DionysosLai��email: 906391500@qq.com
*@version 1.0
*@data 2014-5-26 16:14
*/

#ifndef __S2C_SPRITE_H__
#define __S2C_SPRITE_H__

#include "cocos2d.h"

class S2CSprite : public cocos2d::CCSprite
{
public:  
	S2CSprite();  
	~S2CSprite();  

	static S2CSprite* create(const char* squareName, const char* circleName, float duration);  
	virtual bool init(const char* squareName, const char* circleName, float duration);  

private:
	enum
	{
		TAGSPRITE,
	};
private:  
	bool m_bShape;		///< true---���� false---Բ��  
	cocos2d::CCActionInterval* m_circleAction;		///< ת����Բ�ζ���
	cocos2d::CCActionInterval* m_squareAction;		///< ת����Բ�ζ���
	cocos2d::CCTexture2D* m_textureSquare;			///< ��������
	cocos2d::CCTexture2D* m_textureCircle;			///< Բ������

	void initData(const char* squareName, const char* circleName, float duration);  


public:  
	void changeShape(); 
	void change();
};
#endif // (__S2C_SPRITE_H__)