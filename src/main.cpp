#include <hardware/clocks.h>
#include <hardware/vreg.h>
#include <pico/printf.h>
#include <pico/stdlib.h>

#include "test.hpp"

int main() {
	stdio_init_all();
	vreg_set_voltage(VREG_VOLTAGE_1_30);
	set_sys_clock_khz(420000, true);
	setup_default_uart();

	sleep_ms(1000);

	test_function();

	while (true) {
		tight_loop_contents();
	}
}
