#ifndef DBJ_LOCK_UNLOCK_INC_
#define DBJ_LOCK_UNLOCK_INC_

#ifdef __clang__
#pragma clang system_header
#endif

#include "ccommon.h"
#include "dbj_windows_include.h"

DBJ_EXTERN_C_BEGIN
/*
Following is not using some global CRITICAL_SECTION. 
This is function level locking not process level locking.

Usage : 

void fun ( void)
{
    dbjcs_function_lock_unlock()  ;
    //
    // do something
    //
    clean_exit:
    dbjcs_function_lock_unlock() ;
}

NOTE: do not leave the function without unlocking!
Or simply use <dbj_capi/macro_begin_end_defer.h>

void fun ( void)
{
    beginend( dbjcs_function_lock_unlock(), dbjcs_function_lock_unlock() )
    {
    // do something here
    // unlocking guaranteed
    }
}
 */
    static inline void dbjcapi_function_lock_unlock(void) 
    {                                                 
        static  struct dbj_crit_sect_ {
           bool initialized_and_entered_ ;
            CRITICAL_SECTION CRITSECT_; 
        } CS_ = { .initialized_and_entered_ = false } ;

        if (! CS_.initialized_and_entered_)                                     
        {                                             
            InitializeCriticalSection(&CS_.CRITSECT_);          
            EnterCriticalSection(&CS_.CRITSECT_);  
            CS_.initialized_and_entered_ = true ;             
        }                                             
        else                                          
        {                                             
            LeaveCriticalSection(&CS_.CRITSECT_);               
            DeleteCriticalSection(&CS_.CRITSECT_);              
            CS_.initialized_and_entered_ = false ;
        }                                             
    }
/*
declare and define a function for compilation unit level lock/unlock
using this locking can be done only on the level of one compilation unit 
aka C or C++ file.

Obviuously stay very aware; if you lock with this "everything everywhere" inside
the same compilation unit will wait at the "locking gate" before
unlock happens, hence the long and descriptive name of the function
Same as above advice is to use dbj_capi begiend macro

static struct dbj_crit_sect_ gloabl_cs = { false } ;

void fun ( void)
{
    beginend( dbjcs_comp_unit_lock_unlock(&gloabl_cs), dbjcs_comp_unit_lock_unlock(&gloabl_cs) )
    {
    // do something here
    // unlocking at the compilation unit level is guaranteed
    }
}
*/

    struct dbj_crit_sect_ {
        bool initialized_and_entered_ ;
        CRITICAL_SECTION CRITSECT_; 
    } ;

    static inline void dbjcapi_unit_lock_unlock(dbj_crit_sect_ * crit_sect_ )                    
    {      
        DBJ_ASSERT(crit_sect_);                                                               ;
        if (! crit_sect_->initialized_and_entered_)
        {                                                                 
            InitializeCriticalSection(&crit_sect_->CRITSECT_); 
            EnterCriticalSection(&crit_sect_->CRITSECT_);  
            crit_sect_->initialized_and_entered_ = true ;    
        }                                                                 
        else                                                              
        {                                                                 
            LeaveCriticalSection(&crit_sect_->CRITSECT_);      
            DeleteCriticalSection(&crit_sect_->CRITSECT_);     
            crit_sect_->initialized_and_entered_ = false ;    
        }                                                                 
    }

DBJ_EXTERN_C_END

#endif // DBJ_LOCK_UNLOCK_INC_
