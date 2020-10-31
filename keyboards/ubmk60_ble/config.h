#ifndef CONFIG_H
#define CONFIG_H

// Tên bàn phím
#define KEYBOARD_NAME Ubmk60

// Thời gian phím tự đi vào trạng thái ngủ sau một khoảng thời gian không thao tác, đặt = 0 nếu không cần sleep
#define SLEEP_DELAY         600  // (giây)

/* Gọi bàn phím từ trạng thái ngủ
 * Chọn phím theo sơ đồ bên dưới tương ứng với layout
 * Giả sử chọn phím 56 để gọi dậy, hãy đặt giá trị là { 5, 6 }
 *
 * ,-----------------------------------------------------------.
 * | 00| 10| 01| 11| 02| 12| 03| 13| 04| 14| 05| 15| 06|    16 |
 * |-----------------------------------------------------------|
 * | 20  | 30| 21| 31| 22| 32| 23| 33| 24| 34| 25| 35| 26|  36 |
 * |-----------------------------------------------------------|
 * | 40   | 50| 41| 52| 42| 52| 43| 53| 44| 54| 45| 55|     46 |
 * |-----------------------------------------------------------|
 * | 60     | 70| 61| 71| 62| 72| 63| 73| 64| 74| 65|       75 |
 * |-----------------------------------------------------------|
 * | 80 | 81 | 82 |           83           | 84 | 85 | 86 | 76 |
 * `-----------------------------------------------------------'
 *
 * Bỏ chỉ định phím gọi dậy bằng cách đặt dấu comment (//) trước dòng #define WAKEUP_KEYS...
 * Khi không được chỉ định, bàn phím được gọi dậy bằng cách nhấn một phím bất kỳ
 */

#if defined(WAKEKUP_KEY_NUM) && (WAKEKUP_KEY_NUM == 0)
#undef WAKEKUP_KEY_NUM
#endif

#define WAKEUP_KEYS { { 0, 0 }, { 4, 6 }, { 1, 6 } }

// Tốc độ phản hồi BLE của phím, giá trị từ 1 -> 5, càng cao tốc độ càng nhanh, thời lượng sử dụng pin càng giảm
#define HID_BLE_SPEED       5

#include "system.h"

#endif
