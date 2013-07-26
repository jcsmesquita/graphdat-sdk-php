#include "yii.h"
#include "ext/standard/php_var.h"
#include "zend.h"

// This bit of code is to detect the presence of Yii
// and extract the abstract path

int hasYii(TSRMLS_D)
{
    if(zend_hash_exists(EG(class_table), "chttprequest", sizeof("chttprequest")) 
        && zend_hash_exists(EG(class_table), "capplication", sizeof("capplication")) 
        && zend_hash_exists(EG(class_table), "yiibase", sizeof("yiibase")) )
    {
        return 1;
    }
    return 0;
}

char* getYiiPath(size_t *slen TSRMLS_DC)
{
    char* result;
    zval retval;
    if(zend_eval_string("Yii::app()->request->getUrl();", &retval, "graphdat yii" TSRMLS_CC) == FAILURE)
    {
        return NULL;
    }
    result = Z_STRVAL_P(&retval);
    *slen = Z_STRLEN_P(&retval);
    return result;
}