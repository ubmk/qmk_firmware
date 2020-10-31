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
 * ,---------------.
 * | 00| 01| 02|   |
 * |---------------|
 * | 10| 11| 12| 13|
 * |---------------|
 * | 20| 21| 22| 23|
 * |---------------|
 * | 30| 31| 32|   |
 * |---------------|
 * | 40| 41| 42| 43|
 * |---------------|
 * | 50|   | 52|   |
 * `---------------'
 *
 * Bỏ chỉ định phím gọi dậy bằng cách đặt dấu comment (//) trước dòng #define WAKEUP_KEYS...
 * Khi không được chỉ định, bàn phím được gọi dậy bằng cách nhấn một phím bất kỳ
 */

#if defined(WAKEKUP_KEY_NUM) && (WAKEKUP_KEY_NUM == 0)
#undef WAKEKUP_KEY_NUM
#endif

#define WAKEUP_KEYS { { 0, 0 }, { 4, 3 }, { 0, 1 } }

// Tốc độ phản hồi BLE của phím, giá trị từ 1 -> 5, càng cao tốc độ càng nhanh, thời lượng sử dụng pin càng giảm
#define HID_BLE_SPEED       5

#include "system.h"

#endif
