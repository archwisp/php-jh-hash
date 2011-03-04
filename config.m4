PHP_ARG_ENABLE(jh, whether to enable JH support,
[  --enable-jh          Enable JH support])

if test "$PHP_JH" != "no"; then
  PHP_NEW_EXTENSION(jh, php_jh.c, $ext_shared)
fi
