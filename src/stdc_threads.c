/*
**      PJL Library
**      stdc_threads.c
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

// local
#include "config.h"                     /* must go first */
#include "stdc_threads.h"

// standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Data passed from thrd_create() to pthread_start_fn_thunk().
 */
struct pthread_start_fn_data {
  thrd_start_t  start_fn;               ///< C11 thread start function.
  void         *user_data;              ///< Thread user data.
};

////////// local functions ////////////////////////////////////////////////////

#ifndef NDEBUG
static void assert_is_0( char const *file, int line,
                         int expr, char const *expr_str ) {
  if ( expr == 0 )
    return;
  fprintf( stderr,
    "%s:%d: '%s' non-zero value %d: %s\n",
    file, line, expr_str, expr, strerror( expr )
  );
  abort();
}
#define ASSERT_IS_0(EXPR)     assert_is_0( __FILE__, __LINE__, (EXPR), #EXPR )
#else
#define ASSERT_IS_0(EXPR)     (EXPR)
#endif /* NDEBUG */

static void* pthread_start_fn_thunk( void *p ) {
  struct pthread_start_fn_data const data = *(struct pthread_start_fn_data*)p;
  free( p );
  return (void*)(intptr_t)data.start_fn( data.user_data );
}

////////// extern functions ///////////////////////////////////////////////////

void call_once( once_flag *flag, void (*once_fn)() ) {
  ASSERT_IS_0( pthread_once( flag, once_fn ) );
}

void cnd_destroy( cnd_t *c ) {
  ASSERT_IS_0( pthread_cond_destroy( c ) );
}

int cnd_init( cnd_t *c ) {
  switch ( pthread_cond_init( c, /*attr=*/nullptr ) ) {
    case 0      : return thrd_success;
    case ENOMEM : return thrd_nomem;
    default     : return thrd_error;
  }
}

int cnd_timedwait( cnd_t *c, mtx_t *m, struct timespec const *ts ) {
  switch ( pthread_cond_timedwait( c, m, ts ) ) {
    case 0        : return thrd_success;
    case ETIMEDOUT: return thrd_timedout;
    default       : return thrd_error;
  }
}

void mtx_destroy( mtx_t *m ) {
  ASSERT_IS_0( pthread_mutex_destroy( m ) );
}

int mtx_init( mtx_t *m, int type ) {
  pthread_mutexattr_t attr, *pattr = nullptr;

  if ( (type & mtx_recursive) != 0 ) {
    pthread_mutexattr_init( &attr );
    pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE );
    pattr = &attr;
  }

  int const mutex_init_rv = pthread_mutex_init( m, pattr );

  if ( pattr != nullptr )
    pthread_mutexattr_destroy( &attr );

  switch ( mutex_init_rv ) {
    case 0      : return thrd_success;
    case ENOMEM : return thrd_nomem;
    default     : return thrd_error;
  }
}

#if HAVE_PTHREAD_MUTEX_TIMEDLOCK
int mtx_timedlock( mtx_t *m, struct timespec const *ts ) {
  switch ( pthread_mutex_timedlock( m, ts ) ) {
    case 0        : return thrd_success;
    case ETIMEDOUT: return thrd_timedout;
    default       : return thrd_error;
  }
}
#endif /* HAVE_PTHREAD_MUTEX_TIMEDLOCK */

int mtx_trylock( mtx_t *m ) {
  switch ( pthread_mutex_trylock( m ) ) {
    case 0    : return thrd_success;
    case EBUSY: return thrd_busy;
    default   : return thrd_error;
  }
}

int thrd_create( thrd_t *t, thrd_start_t start_fn, void *user_data ) {
  struct pthread_start_fn_data *const data =
    malloc( sizeof( struct pthread_start_fn_data ) );
  *data = (struct pthread_start_fn_data){ start_fn, user_data };

  int const create_rv =
    pthread_create( t, /*attr=*/nullptr, &pthread_start_fn_thunk, data );
  if ( create_rv == 0 )
    return thrd_success;

  free( data );
  return create_rv == EAGAIN ? thrd_nomem : thrd_error;
}

int thrd_join( thrd_t t, int *pthrd_value ) {
  void *pthread_value;
  int const join_rv = pthread_join( t, &pthread_value );
  if ( pthrd_value != nullptr )
    *pthrd_value = (int)(intptr_t)pthread_value;
  return join_rv == 0 ? thrd_success : thrd_error;
}

int thrd_sleep( struct timespec const *duration, struct timespec *remaining ) {
  int const sleep_rv = nanosleep( duration, remaining );
  switch ( sleep_rv ) {
    case  0:
    case -1:
      return sleep_rv;
    default:
      return -2;
  }
}

void tss_delete( tss_t key ) {
  ASSERT_IS_0( pthread_key_delete( key ) );
}

///////////////////////////////////////////////////////////////////////////////

extern inline int     cnd_broadcast( cnd_t* );
extern inline int     cnd_signal( cnd_t* );
extern inline int     cnd_wait( cnd_t*, mtx_t* );
extern inline int     mtx_lock( mtx_t* );
extern inline int     mtx_unlock( mtx_t* );
extern inline thrd_t  thrd_current();
extern inline int     thrd_detach( thrd_t );
extern inline int     thrd_equal( thrd_t, thrd_t );
extern inline void    thrd_exit( int );
extern inline void    thrd_yield();
extern inline int     tss_create( tss_t*, tss_dtor_t );
extern inline void*   tss_get( tss_t );
extern inline int     tss_set( tss_t, void* );

///////////////////////////////////////////////////////////////////////////////
/* vim:set et sw=2 ts=2: */
