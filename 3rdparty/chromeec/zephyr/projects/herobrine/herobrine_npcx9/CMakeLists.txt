# Copyright 2021 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(herobrine_npcx9)

zephyr_library_include_directories(include)

# Board specific implementation
zephyr_library_sources_ifdef(CONFIG_PLATFORM_EC_USBC
  "src/usbc_config.c"
  "src/usb_pd_policy.c")
zephyr_library_sources_ifdef(CONFIG_PLATFORM_EC_LED_COMMON
  "src/led.c")
zephyr_library_sources_ifdef(CONFIG_PLATFORM_EC_I2C
  "src/i2c.c")
zephyr_library_sources_ifdef(CONFIG_PLATFORM_EC_USBC
  "src/alt_dev_replacement.c")
