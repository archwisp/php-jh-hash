#ifndef PHP_JH_H
# define PHP_JH_H

extern zend_module_entry jh_module_entry;
# define phpext_jh_ptr &jh_module_entry

# ifdef PHP_WIN32
#  define PHP_JH_API __declspec(dllexport)
# else
#  define PHP_JH_API
# endif

# ifdef ZTS
#  include "TSRM.h"
# endif

PHP_MINIT_FUNCTION(jh);
PHP_MSHUTDOWN_FUNCTION(jh);
PHP_RINIT_FUNCTION(jh);
PHP_RSHUTDOWN_FUNCTION(jh);
PHP_MINFO_FUNCTION(jh);

PHP_FUNCTION(jh_hash);
PHP_FUNCTION(jh_hash_hex);

# ifdef ZTS
#  define JH_G(v) TSRMG(jh_globals_id, zend_jh_globals *, v)
# else
#  define JH_G(v) (jh_globals.v)
# endif

#endif
