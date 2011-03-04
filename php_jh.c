#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/standard/basic_functions.h"
#include "jh.c"
#include "php_jh.h"

#define JH_DEFAULT_BIT_LENGTH 512

zend_function_entry jh_functions[] = {
	PHP_FE(jh_hash, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry jh_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"jh",
	jh_functions,
	PHP_MINIT(jh),
	PHP_MSHUTDOWN(jh),
	NULL,
	NULL,
	PHP_MINFO(jh),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1",
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_JH
ZEND_GET_MODULE(jh)
#endif

PHP_MINIT_FUNCTION(jh)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(jh)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(jh)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "jh hash support", "enabled");
	php_info_print_table_end();
}

PHP_FUNCTION(jh_hash)
{
   char hash[64];
   char *buffer = NULL;
   int buffer_size;
   long hash_bit_length = JH_DEFAULT_BIT_LENGTH;

   if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l",
            &buffer, &buffer_size, &hash_bit_length) == FAILURE) 
   {
      RETURN_FALSE;
   }
  
   HashReturn result;

   if ((result = Hash((size_t) hash_bit_length, buffer, buffer_size, hash)) != HASH_SUCCESS)
   {
      if (result == BAD_HASHLEN)
      {
         php_error_docref(NULL TSRMLS_CC, E_WARNING, "Bad bit-length");
      }

      RETURN_FALSE;
   }

   RETURN_STRINGL(hash, ceil(hash_bit_length / 8), 1);
}
