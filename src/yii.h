#include "php.h"
#include "zend.h"
#include <stddef.h>

#ifndef graphdat_sdk_php_yii_h
#define graphdat_sdk_php_yii_h

int hasYii(TSRMLS_D);
char* getYiiPath(size_t *slen TSRMLS_DC);

#endif