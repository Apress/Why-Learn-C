/*
**      PJL Library
**      stdc_threads.h
**
**      Copyright (C) 2025  Paul J. Lucas
**
**      This program is free software: you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation, either version 3 of the License, or
**      (at your option) any later version.
**
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**
**      You should have received a copy of the GNU General Public License
**      along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#else

#ifndef pjl_stdc_threads_H
#define pjl_stdc_threads_H

/**
 * @file
 * Declares types, constants, and function wrappers around POSIX threads for
 * standard C11 threads when __STDC_NO_THREADS__ is defined to 1.
 */

// local
#include "config.h"

// standard
#include <errno.h>
#include <pthread.h>
#include <sched.h>
#include <stdint.h>
#include <time.h>

///////////////////////////////////////////////////////////////////////////////

#define ONCE_FLAG_INIT            PTHREAD_ONCE_INIT

enum {
  mtx_plain     = 0,
  mtx_timed     = 1 << 0,
  mtx_recursive = 1 << 1
};

enum {
  thrd_success,
  thrd_busy     = EBUSY,
  thrd_nomem    = ENOMEM,
  thrd_timedout = ETIMEDOUT,
  thrd_error
};

typedef pthread_cond_t  cnd_t;
typedef pthread_mutex_t mtx_t;
typedef pthread_once_t  once_flag;
typedef int           (*thrd_start_t)( void* );
typedef pthread_t       thrd_t;
typedef void          (*tss_dtor_t)( void* );
typedef pthread_key_t   tss_t;

///////////////////////////////////////////////////////////////////////////////

void call_once( once_flag *flag, void (*once_fn)() );

int cnd_init( cnd_t *c );

inline int cnd_broadcast( cnd_t *c ) {
  return pthread_cond_broadcast( c ) == 0 ? thrd_success : thrd_error;
}

void cnd_destroy( cnd_t *c );

inline int cnd_signal( cnd_t *c ) {
  return pthread_cond_signal( c ) == 0 ? thrd_success : thrd_error;
}

int cnd_timedwait( cnd_t *c, mtx_t *m, struct timespec const *ts );

inline int cnd_wait( cnd_t *c, mtx_t *m ) {
  return pthread_cond_wait( c, m ) == 0 ? thrd_success : thrd_error;
}

void mtx_destroy( mtx_t *m );

int mtx_init( mtx_t *m, int type );

inline int mtx_lock( mtx_t *m ) {
  return pthread_mutex_lock( m ) == 0 ? thrd_success : thrd_error;
}

#ifdef HAVE_PTHREAD_MUTEX_TIMEDLOCK
int mtx_timedlock( mtx_t *m, struct timespec const *ts );
#endif /* HAVE_PTHREAD_MUTEX_TIMEDLOCK */

int mtx_trylock( mtx_t *m );

inline int mtx_unlock( mtx_t *m ) {
  return pthread_mutex_unlock( m ) == 0 ? thrd_success : thrd_error;
}

int thrd_create( thrd_t *t, thrd_start_t start_fn, void *user_data );

inline thrd_t thrd_current() {
  return pthread_self();
}

inline int thrd_detach( thrd_t t ) {
  return pthread_detach( t ) == 0 ? thrd_success : thrd_error;
}

inline int thrd_equal( thrd_t t1, thrd_t t2 ) {
  return pthread_equal( t1, t2 );
}

[[noreturn]] inline void thrd_exit( int status ) {
  pthread_exit( (void*)(intptr_t)status );
}

int thrd_join( thrd_t t, int *pexit_value );

int thrd_sleep( struct timespec const *duration, struct timespec *remaining );

inline void thrd_yield() {
  sched_yield();
}

inline int tss_create( tss_t *key, tss_dtor_t dtor ) {
  return pthread_key_create( key, dtor ) == 0 ? thrd_success : thrd_error;
}

void tss_delete( tss_t key );

inline void* tss_get( tss_t key ) {
  return pthread_getspecific( key );
}

inline int tss_set( tss_t key, void *value ) {
  return pthread_setspecific( key, value ) == 0 ? thrd_success : thrd_error;
}

///////////////////////////////////////////////////////////////////////////////
#endif /* pjl_stdc_threads_H */
#endif /* __STDC_NO_THREADS__ */
