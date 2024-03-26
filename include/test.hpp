#include <hardware/clocks.h>

void test_function(void) {
	printf("RP2040:\n");

	uint32_t clock_hz = clock_get_hz(clk_sys);
	float clock_mhz = clock_hz / 1000000.0f;
	printf("System clock: %.2f MHz\n", clock_mhz);
}