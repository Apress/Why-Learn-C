##
#	"Why Learn C"
#	Makefile.am
#
#	Copyright (C) 2025  Paul J. Lucas
#
#	This program is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

bin_PROGRAMS=			acquire_release \
				alloc2d \
				args \
				c23_strtol \
				call_once \
				cas_impl \
				c_exception \
				check_strtol \
				cnd_example \
				consume \
				cp-v1 cp-v2 cp-v3 cp-v4 \
				fatal_error \
				fl_print_error \
				hash_table \
				islist islist_lf islist_lf-v2 \
				itoken \
				lineno_stack \
				ls-v1 \
				mstrcat \
				mtx_lockall \
				orbits \
				orbits-fgets orbits-fscanf orbits-struct \
				print_csi \
				PRINTF_FORMAT \
				print_hist \
				print_mcsi \
				putubin \
				qsort_example \
				sample_assert \
				setjmp_error_codes \
				setjmp_example \
				shrd_obj \
				slist-v1 slist-v1-mtx slist-v2 \
				stat \
				strbuf \
				strcat-hard \
				strcpy-v1 strcpy-v2 \
				strings \
				string-v1 string-v2 \
				str_is_any \
				swap16of32 \
				swap_bytes \
				swapi-v1 swapi-v2 swapi-v3 \
				tabs_spaces-v1 tabs_spaces-v2 \
				thrd_hello_world \
				token-v1 token-v2 token-v3 \
				tss_example \
				type_traits \
				user \
				vnsum \
				vstr_is_any \
				wlc_string \
				wrap_setjmp

check_PROGRAMS=			c23_strtol \
				c_exception \
				hash_table \
				islist \
				mtx_lockall \
				orbits-fgets orbits-fscanf \
				qsort_example \
				shrd_obj \
				slist-v1 slist-v1-mtx slist-v2 \
				str_is_any \
				strbuf \
				string-v2 \
				swap16of32 \
				swap_bytes \
				type_traits \
				vnsum \
				vstr_is_any

AM_CFLAGS=			$(WHY_C_CFLAGS)
AM_CPPFLAGS= 			-I$(top_srcdir)/lib -I$(top_builddir)/lib
LDADD=				$(top_builddir)/lib/libgnu.a -lm

STDC_THREADS=			stdc_threads.h
if HAVE___STDC_NO_THREADS__
STDC_THREADS+=			stdc_threads.c config.h
LDADD+=				-lpthread
endif

UTIL=				util.h util.c
UNIT_TEST=			unit_test.h unit_test.c $(UTIL)

acquire_release_SOURCES=	acquire_release.c \
				acquire_release.d/consumer.h \
				acquire_release.d/producer.h \
				acquire_release.d/work.h \
				islist.d/functions.h \
				islist.d/struct.h

alloc2d_SOURCES=		alloc2d.c \
				alloc2d.d/alloc2d.h

args_SOURCES=			args.c

c23_strtol_SOURCES=		c23_strtol.c $(UNIT_TEST) \
				c23_strtol.d/c23_strtol.h

call_once_SOURCES=		call_once.c $(STDC_THREADS) \
				call_once.d/call_once.h

cas_impl_SOURCES=		cas_impl.c \
				cas_impl.d/cas_impl.h

c_exception_SOURCES=		c_exception.c $(UNIT_TEST) \
				c_exception.d/cx_catch.h \
				c_exception.d/cx_exception.h \
				c_exception.d/cx_finally.h \
				c_exception.d/cx_impl_catch.h \
				c_exception.d/cx_impl_state-v2.h \
				c_exception.d/cx_impl_state-v3.h \
				c_exception.d/cx_impl_throw-v1.h \
				c_exception.d/cx_impl_throw-v2.h \
				c_exception.d/cx_impl_try_block-v1.h \
				c_exception.d/cx_impl_try_block-v2.h \
				c_exception.d/cx_impl_try_block-v3.h \
				c_exception.d/cx_impl_try_cond-v1.h \
				c_exception.d/cx_impl_try_cond-v2.h \
				c_exception.d/cx_impl_try_cond-v3.h \
				c_exception.d/cx_terminate.h \
				c_exception.d/cx_throw.h \
				c_exception.d/cx_try-v1.h \
				c_exception.d/cx_try-v2.h \
				c_exception.d/read_file.h \
				c_exception.d/requirements.h

check_strtol_SOURCES=		check_strtol.c \
				check_strtol.d/check_strtol.h

cnd_example_SOURCES=		cnd_example.c $(STDC_THREADS) \
				cnd_example.d/consumer_main.h \
				cnd_example.d/producer_main.h

consume_SOURCES=		consume.c \
				consume.d/consumer.h \
				consume.d/producer.h \
				consume.d/work_avail.h \
				islist.d/functions.h \
				islist.d/struct.h

cp_v1_SOURCES=			cp-v1.c \
				cp-v1.d/cp-v1.h

cp_v2_SOURCES=			cp-v2.c \
				cp-v2.d/cp-v2.h

cp_v3_SOURCES=			cp-v3.c \
				cp-v3.d/cp-v3.h

cp_v4_SOURCES=			cp-v4.c \
				cp-v4.d/check_open.h \
				cp-v4.d/main.h \
				cp-v4.d/perror_exit.h \
				cp-v4.d/usage.h

fatal_error_SOURCES=		fatal_error.c \
				fatal_error.d/fatal_error.h

fl_print_error_SOURCES=		fl_print_error.c \
				fl_print_error.d/fl_print_error.h

hash_table_SOURCES=		hash_table.c $(UNIT_TEST) \
				handy/ARRAY_SIZE.h \
				hash_table.d/DINT-DPTR.h \
				hash_table.d/HT_PRIME.h \
				hash_table.d/fnv1a.h \
				hash_table.d/ht_cleanup.h \
				hash_table.d/ht_delete.h \
				hash_table.d/ht_empty.h \
				hash_table.d/ht_find.h \
				hash_table.d/ht_grow.h \
				hash_table.d/ht_init.h \
				hash_table.d/ht_insert.h \
				hash_table.d/ht_insert_rv.h \
				hash_table.d/ht_iter.h \
				hash_table.d/ht_next.h \
				hash_table.d/insert_example.h \
				hash_table.d/types.h

islist_SOURCES=			islist.c $(UNIT_TEST) \
				islist.d/functions.h \
				islist.d/struct.h

islist_lf_SOURCES=		islist_lf.c \
				islist.d/struct.h \
				islist_lf.d/islist_lfpop.h \
				islist_lf.d/islist_lfpush.h

islist_lf_v2_SOURCES=		islist_lf-v2.c \
				islist.d/struct.h \
				islist_lf-v2.d/islist_lf-v2.h

itoken_SOURCES=			itoken.c \
				itoken.d/itoken.h

lineno_stack_SOURCES=		lineno_stack.c \
				handy/ARRAY_SIZE.h \
				lineno_stack.d/lineno_stack.h

ls_v1_SOURCES=			ls-v1.c \
				ls-v1.d/ls-v1.h

mstrcat_SOURCES=		mstrcat.c \
				mstrcat.d/mstrcat.h

mtx_lockall_SOURCES=		mtx_lockall.c $(STDC_THREADS) \
				handy/VA_ARGS_COUNT.h \
				mtx_lockall.d/mtx_lockall.h \
				mtx_lockall.d/mtx_lockall-macro.h

orbits_SOURCES=			orbits.c \
				orbits.d/orbits.h

orbits_fgets_SOURCES=		orbits-fgets.c $(UNIT_TEST) \
				orbits-fgets.d/orbits-fgets.h

orbits_fscanf_SOURCES=		orbits-fscanf.c $(UNIT_TEST) \
				orbits-fscanf.d/read_planet_data.h

orbits_struct_SOURCES=		orbits-struct.c \
				orbits-struct.d/orbits-struct.h

print_csi_SOURCES=		print_csi.c \
				print_csi.d/print_csi.h

PRINTF_FORMAT_SOURCES=		PRINTF_FORMAT.c \
				PRINTF_FORMAT.d/PRINTF_FORMAT.h \
				PRINTF_FORMAT.d/example.h

print_hist_SOURCES=		print_hist.c \
				handy/ARRAY_SIZE.h \
				print_hist.d/print_hist.h

print_mcsi_SOURCES=		print_mcsi.c \
				print_mcsi.d/print_mcsi.h

putubin_SOURCES=		putubin.c \
				putubin.d/putubin.h

qsort_example_SOURCES=		qsort_example.c $(UNIT_TEST) \
				qsort_example.d/qsort_example.h

sample_assert_SOURCES=		sample_assert.c \
				sample_assert.d/sample_assert.h

setjmp_error_codes_SOURCES=	setjmp_error_codes.c \
				setjmp_error_codes.d/setjmp_error_codes.h

setjmp_example_SOURCES=		setjmp_example.c \
				setjmp_example.d/setjmp_example.h

shrd_obj_SOURCES=		shrd_obj.c $(UNIT_TEST) \
				shrd_obj.d/shrd_dec.h \
				shrd_obj.d/shrd_inc.h \
				shrd_obj.d/shrd_new.h \
				shrd_obj.d/shrd_obj.h

slist_v1_SOURCES=		slist-v1.c $(UNIT_TEST) \
				slist-v1.d/const_slist_find.h \
				slist-v1.d/functions.h \
				slist-v1.d/slist_find.h \
				slist-v1.d/struct.h \
				user.d/slist_find.h

slist_v1_mtx_SOURCES=		slist-v1-mtx.c $(STDC_THREADS) $(UNIT_TEST) \
				slist-v1-mtx.d/slist-v1-mtx.h

slist_v2_SOURCES=		slist-v2.c $(UNIT_TEST) \
				slist-v2.d/DINT-DPTR.h \
				slist-v2.d/dup_str.h \
				slist-v2.d/free_if.h \
				slist-v2.d/front-back-empty.h \
				slist-v2.d/init-cleanup.h \
				slist-v2.d/not_contains_str.h \
				slist-v2.d/pop.h \
				slist-v2.d/push.h \
				slist-v2.d/slist_front_int_example.h \
				slist-v2.d/slist_front_ptr_example.h \
				slist-v2.d/structs.h

stat_SOURCES=			stat.c \
				stat.d/stat.h

strbuf_SOURCES=			strbuf.c $(UNIT_TEST) \
				strbuf.d/cleanup.h \
				strbuf.d/printf.h \
				strbuf.d/puts.h \
				strbuf.d/reserve.h \
				strbuf.d/reset.h \
				strbuf.d/str_list.h \
				strbuf.d/struct.h \
				strbuf.d/take.h

strcat_hard_SOURCES=		strcat-hard.c \
				strcat-hard.d/strcat-hard.h

strcpy_v1_SOURCES=		strcpy-v1.c
strcpy_v2_SOURCES=		strcpy-v2.c

strings_SOURCES=		strings.c \
				strings.d/strings.h

string_v1_SOURCES=		string-v1.c \
				string-v1.d/cleanup.h \
				string-v1.d/main.h \
				string-v1.d/puts.h \
				string-v1.d/struct.h

string_v2_SOURCES=		string-v2.c $(UNIT_TEST) \
				string-v2.d/printf.h \
				string-v2.d/puts_putc.h \
				string-v2.d/putsn.h \
				string-v2.d/struct.h \
				string-v2.d/take.h

str_is_any_SOURCES=		str_is_any.c $(UNIT_TEST) \
				str_is_any.d/str_is_any.h

swap16of32_SOURCES=		swap16of32.c $(UNIT_TEST) \
				swap16of32.d/swap16of32.h

swap_bytes_SOURCES=		swap_bytes.c $(UNIT_TEST) \
				swap_bytes.d/swap_bytes.h

swapi_v1_SOURCES=		swapi-v1.c \
				swapi-v1.d/swapi-v1.h

swapi_v2_SOURCES=		swapi-v2.c \
				swapi-v2.d/swapi-v2.h

swapi_v3_SOURCES=		swapi-v3.c \
				swapi-v3.d/swapi-v3.h

tabs_spaces_v1_SOURCES=		tabs_spaces-v1.c \
				tabs_spaces-v1.d/tabs_spaces-v1.h

tabs_spaces_v2_SOURCES=		tabs_spaces-v2.c \
				tabs_spaces-v2.d/tabs_spaces-v2.h

thrd_hello_world_SOURCES=	thrd_hello_world.c $(STDC_THREADS)

token_v1_SOURCES=		token-v1.c \
				token-v1.d/token.h \
				token-v1.d/token_cpy.h

token_v2_SOURCES=		token-v2.c \
				token-v2.d/token.h

token_v3_SOURCES=		token-v3.c \
				token-v3.d/token.h

tss_example_SOURCES=		tss_example.c $(STDC_THREADS) \
				handy/FLPRINTF.h \
				tss_example.d/tss_example.h

user_SOURCES=			user.c \
				user.d/find_root.h \
				user.d/slist_find.h \
				user.d/struct-cmp.h

vnsum_SOURCES=			vnsum.c $(UNIT_TEST) \
				vnsum.d/vnsum.h

vstr_is_any_SOURCES=		vstr_is_any.c $(UNIT_TEST) \
				vstr_is_any.d/vstr_is_any.h

type_traits_SOURCES=		type_traits.c $(UNIT_TEST) \
				type_traits.d/INT_MAX_EXPR.h \
				type_traits.d/INT_MIN_EXPR.h \
				type_traits.d/IS_ARITHMETIC_EXPR.h \
				type_traits.d/IS_ARRAY_EXPR.h \
				type_traits.d/IS_C_STR_EXPR.h \
				type_traits.d/IS_FLOATING_POINT_EXPR.h \
				type_traits.d/IS_INTEGRAL_EXPR.h \
				type_traits.d/IS_POINTER_EXPR.h \
				type_traits.d/IS_SAME_TYPE.h \
				type_traits.d/IS_SIGNED_EXPR.h \
				type_traits.d/IS_SIGNED_TYPE.h \
				type_traits.d/IS_TYPE_EXPR.h \
				type_traits.d/IS_UNSIGNED_EXPR.h \
				type_traits.d/TO_SIGNED_EXPR.h \
				type_traits.d/TO_UNSIGNED_EXPR.h \
				type_traits.d/UNDERLYING_TYPE.h \
				util/STATIC_ASSERT_EXPR.h \
				util/STATIC_IF.h

wlc_string_SOURCES=		wlc_string.c \
				wlc_string.d/wlc_string.h

wrap_setjmp_SOURCES=		wrap_setjmp.c \
				wrap_setjmp.d/wrap_setjmp.h

TESTS=				$(check_PROGRAMS)

# vim:set noet sw=8 ts=8:
