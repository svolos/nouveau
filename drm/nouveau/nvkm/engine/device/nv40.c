/*
 * Copyright 2012 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include "priv.h"

int
nv40_identify(struct nvkm_device *device)
{
	switch (device->chipset) {
	case 0x40:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv40_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv04_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv40_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x41:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv41_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv40_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x42:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv41_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv40_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x43:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv41_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv40_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x45:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv40_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv04_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x47:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv47_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x49:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv49_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x4b:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv40_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv49_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv41_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x44:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv44_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv44_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x46:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv46_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x4a:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv44_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv44_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x4c:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv46_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x4e:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv4e_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv4e_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x63:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv46_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x67:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv46_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	case 0x68:
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nv10_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nv04_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nv40_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nv40_therm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nv1a_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nv4c_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nv31_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nv46_fb_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv40_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nv44_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nv04_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv40_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv40_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv44_mpeg_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nv04_disp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] =  nv40_pm_oclass;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}
