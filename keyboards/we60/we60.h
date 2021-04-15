#ifndef KEYBOARDS_WE60_H_
#define KEYBOARDS_WE60_H_

#include "quantum.h"

/* ANSI + arrow
 * ,----------------------------------------------------------.
 * | 00| 10| 01| 11| 02| 12| 03| 13| 04| 14| 05| 15| 06|  16  |
 * |----------------------------------------------------------|
 * | 20  | 30| 21| 31| 22| 32| 23| 33| 24| 34| 25| 35| 26| 36 |
 * |----------------------------------------------------------|
 * | 40   | 41| 51| 42| 52| 43| 53| 44| 54| 45| 55| 46|   56  |
 * |----------------------------------------------------------|
 * | 60     | 61| 71| 62| 72| 63| 73| 64| 74| 65|  75 | 66| 76|
 * |----------------------------------------------------------|
 * | 80 | 81 | 82 |           83          | 84| 85| 87| 67| 77|
 * `----------------------------------------------------------'
 */
#define LAYOUT_60_arrow( \
	K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16,	\
	K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36,	\
	K40,      K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K46, K56,	\
	K60,      K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76,	\
	K80,	  K81,		K82,	  K83,		K84,	  K85, K87, K67, K77	\
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06,   KC_NO }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36,   KC_NO }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   KC_NO }, \
	{ KC_NO, K51,   K52,   K53,   K54,   K55,   K56,   KC_NO }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67	 }, \
	{ KC_NO, K71,   K72,   K73,   K74,   K75,   K76,   K77	 }, \
	{ K80,   K81,   K82,   K83,   K84,   K85,   KC_NO, K87	 }  \
}


#endif /* KEYBOARDS_WE60_H_ */