#ifndef CONFIG_H
#define CONFIG_H

// Tên bàn phím
#define KEYBOARD_NAME Ubmk65

// Thời gian phím tự đi vào trạng thái ngủ sau một khoảng thời gian không thao tác, đặt = 0 nếu không cần sleep
#define SLEEP_DELAY         600  // (giây)

// Tốc độ phản hồi BLE của phím, giá trị từ 1 -> 5, càng cao tốc độ càng nhanh, thời lượng sử dụng pin càng giảm
#define HID_BLE_SPEED       5

#include "system.h"

#endif
