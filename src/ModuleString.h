#ifndef _STRING_H_
#define _STRING_H_

#include "Module.h"
#include "Macros.h"

#include <lua.hpp>

#include <codecvt>
#include <locale>
#include <string>

class ModuleString : public Module
{
public:
	static ModuleString& Instance();
	~ModuleString() {};

private:
	ModuleString();

};

class EncodingConversion
{
public:
	EncodingConversion() = delete;
	EncodingConversion(const EncodingConversion&) = delete;
	EncodingConversion(EncodingConversion&&) = delete;
	~EncodingConversion() = delete;
	EncodingConversion& operator=(const EncodingConversion&) = delete;
	EncodingConversion& operator=(EncodingConversion&&) = delete;

	static std::string    ToString(const std::wstring& wstr);
	static std::wstring   ToWString(const std::string& str);
	static std::string    GBKToUTF8(const std::string& str);
	static std::string    UTF8ToGBK(const std::string& str);
	static std::u16string UTF8toUTF16(const std::string& str);
	static std::u32string UTF8toUTF32(const std::string& str);
	static std::string    UTF16toUTF8(const std::u16string& str);
	static std::u32string UTF16toUTF32(const std::u16string& str);
	static std::string    UTF32toUTF8(const std::u32string& str);
	static std::u16string UTF32toUTF16(const std::u32string& str);
private:
	static std::string    ToGBK(const std::wstring& wstr);
	static std::wstring   FromGBK(const std::string& str);
	static std::string    ToUTF8(const std::wstring& wstr);
	static std::wstring   FromUTF8(const std::string& str);
private:
	static const char* GBK_LOCALE_NAME;
};

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

#endif // !_STRING_H_
