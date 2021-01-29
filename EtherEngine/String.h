#ifndef _STRING_H_
#define _STRING_H_

#include "Moudle.h"
#include "Macros.h"
#include "util.h"

#include <lua.hpp>
#include "EncodingConversion.h"

/*
* ��GBK�����ַ���ת��ΪUTF-8����
* 1������GBK�����ַ�����string��
* 1����ֵ��UTF-8�����ַ�����string��
*/
ETHER_API gbkToUTF8(lua_State* L);

/*
* ��UTF-8�����ַ���ת��ΪGBK����
* 1������UTF-8�����ַ�����string��
* 1����ֵ��GBK�����ַ�����string��
*/
ETHER_API utf8ToGBK(lua_State* L);

class MoudleString : public Moudle
{
public:
	MoudleString(lua_State* L);
	~MoudleString() {};

};

#endif // !_STRING_H_
