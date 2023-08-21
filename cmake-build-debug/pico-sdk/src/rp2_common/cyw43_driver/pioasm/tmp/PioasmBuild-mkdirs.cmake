# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "G:/PRI-RP2/pico-sdk/tools/pioasm"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pioasm"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/tmp"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src"
  "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "G:/PRI-RP2/DIY-Led-segment-displays/cmake-build-debug/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
