#include <iostream>
#include <string>
#include "read_file.hpp"
#include "ndisasm.hpp"
//#include "func_test.hpp"

void argc_check(int argc){
   if( argc ==2){
	return;
   }else if( argc >=3){
	std::cout << "argv check"<<std::endl;
	exit(0);
   }
}

int HEY_GIVE_ME_SHELL;
int main(int argc , char** argv ){
//   std::string hoge = "FIND";
   argc_check(argc);
   read_binary read_bin(argv[1]);
//   read_bin.file_obj.read( moji , 4);
//   std::cout << moji << std::endl;
//   my::findF( hoge , "N");
   read_bin.check_file_type();
   my_objdump obj_dump;
   read_bin.copy_bss_symbol(obj_dump.getter_bss());
//   obj_dump( );
   read_bin.copy_text1(&obj_dump.strip_flag , &obj_dump.size ,&obj_dump.top_addr);
   obj_dump.all_code_new();
//std::cout << "AAA"<< std::endl;
   read_bin.copy_text2( obj_dump.all_code , &obj_dump.bit);
//std::cout << "EEE" << std::endl;
   if( !obj_dump.strip_flag ){
	read_bin.copy_text_sym( &obj_dump.function );
   }
   obj_dump.arch();
}

