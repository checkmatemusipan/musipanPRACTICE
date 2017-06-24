#ifndef __print_help
#define __print_help
#include <iostream>
#include <iomanip>
#include <exception>
#include <cxxabi.h>
#include <string>

template <typename Type>
struct _my_setfill{
	Type character;
	std::streamsize w;
	_my_setfill( Type character, std::streamsize w) :w(w) , character(character) {}
};

template <typename Type>
inline _my_setfill<Type> my_setfillH( Type character , std::streamsize w){
	return _my_setfill<Type>( character ,w );
}

template <typename Type>
inline std::ostream& operator << (std::ostream& os,const _my_setfill<Type>& manip)
{
	return os << std::hex  << std::setw(manip.w ) << std::setfill(manip.character);
}


template <typename TypeDEX>
struct _my_setfillD{
        TypeDEX character;
        std::streamsize w;
        _my_setfillD( TypeDEX character, std::streamsize w) :w(w) , character(character) {}
};

template <typename TypeDEX>
inline _my_setfillD<TypeDEX> my_setfillD( TypeDEX character , std::streamsize w){
        return _my_setfillD<TypeDEX>( character ,w );
}

template <typename TypeDEX>
inline std::ostream& operator << (std::ostream& os,const _my_setfillD<TypeDEX>& manip)
{
        return os << std::dec << std::setw(manip.w ) << std::setfill(manip.character);
}

//注意メモリリークする
//開放できない
std::string cxx_demangle(const char* mangle){
	std::string ret="";
	char* temp;
	int status;
	temp = abi::__cxa_demangle(mangle , 0, 0 , &status);
	ret = temp;
	free(temp);
	return ret;
}

#endif
