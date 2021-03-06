/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Damjan Marion <damjan.marion@gmail.com>
 * Copyright (C) 2011 Mark Panajotovic <marko@electrontube.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void clock_setup(void)
{
    /* If OSC clock = MCO from st-link */
	//rcc_clock_setup_in_hse_8mhz_out_72mhz();
	//rcc_osc_bypass_enable(HSE);

	/* Enable GPIOA clock. */
	rcc_periph_clock_enable(RCC_GPIOA);
}

static void gpio_setup(void)
{
    	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);
}

int main(void)
{
    clock_setup();
    gpio_setup();

    int i;

	while (1) {
        gpio_toggle(GPIOA, GPIO5);
		for (i = 0; i < 800000; i++)
			__asm__("nop");
	}

	return 0;
}
