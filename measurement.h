#ifndef VGA_MEASUREMENT_H
#define VGA_MEASUREMENT_H

#include "etl/attribute_macros.h"
#include "etl/armv7m/sys_tick.h"
#include "etl/stm32f4xx/gpio.h"

namespace vga {

void msigs_init();

ETL_INLINE void msig_a_set() {
  etl::stm32f4xx::gpioc.set(etl::stm32f4xx::Gpio::p9);
}

ETL_INLINE void msig_a_clear() {
  etl::stm32f4xx::gpioc.clear(etl::stm32f4xx::Gpio::p9);
}

ETL_INLINE void msig_a_toggle() {
  etl::stm32f4xx::gpioc.toggle(etl::stm32f4xx::Gpio::p9);
}

ETL_INLINE void msig_b_set() {
  etl::stm32f4xx::gpioc.set(etl::stm32f4xx::Gpio::p8);
}

ETL_INLINE void msig_b_clear() {
  etl::stm32f4xx::gpioc.clear(etl::stm32f4xx::Gpio::p8);
}

ETL_INLINE void msig_b_toggle() {
  etl::stm32f4xx::gpioc.toggle(etl::stm32f4xx::Gpio::p8);
}

ETL_INLINE void msig_e_set(unsigned index) {
  etl::stm32f4xx::gpioe.set((1 << index) & 0xFF);
}

ETL_INLINE void msig_e_clear(unsigned index) {
  etl::stm32f4xx::gpioe.clear((1 << index) & 0xFF);
}


void mtim_init();

ETL_INLINE unsigned mtim_get() {
  return etl::armv7m::sys_tick.read_cvr().get_current();
}

}  // namespace vga

#endif  // VGA_MEASUREMENT_H
