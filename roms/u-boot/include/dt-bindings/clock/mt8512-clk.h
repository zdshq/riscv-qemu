/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef _DT_BINDINGS_CLK_MT8512_H
#define _DT_BINDINGS_CLK_MT8512_H

/* TOPCKGEN */

#define CLK_TOP_CLK_NULL		0
#define CLK_TOP_CLK32K			1
#define CLK_TOP_SYSPLL1_D2		2
#define CLK_TOP_SYSPLL1_D4		3
#define CLK_TOP_SYSPLL1_D8		4
#define CLK_TOP_SYSPLL1_D16		5
#define CLK_TOP_SYSPLL_D3		6
#define CLK_TOP_SYSPLL2_D2		7
#define CLK_TOP_SYSPLL2_D4		8
#define CLK_TOP_SYSPLL2_D8		9
#define CLK_TOP_SYSPLL_D5		10
#define CLK_TOP_SYSPLL3_D4		11
#define CLK_TOP_SYSPLL_D7		12
#define CLK_TOP_SYSPLL4_D2		13
#define CLK_TOP_UNIVPLL			14
#define CLK_TOP_UNIVPLL_D2		15
#define CLK_TOP_UNIVPLL1_D2		16
#define CLK_TOP_UNIVPLL1_D4		17
#define CLK_TOP_UNIVPLL1_D8		18
#define CLK_TOP_UNIVPLL_D3		19
#define CLK_TOP_UNIVPLL2_D2		20
#define CLK_TOP_UNIVPLL2_D4		21
#define CLK_TOP_UNIVPLL2_D8		22
#define CLK_TOP_UNIVPLL_D5		23
#define CLK_TOP_UNIVPLL3_D2		24
#define CLK_TOP_UNIVPLL3_D4		25
#define CLK_TOP_TCONPLL_D2		26
#define CLK_TOP_TCONPLL_D4		27
#define CLK_TOP_TCONPLL_D8		28
#define CLK_TOP_TCONPLL_D16		29
#define CLK_TOP_TCONPLL_D32		30
#define CLK_TOP_TCONPLL_D64		31
#define CLK_TOP_USB20_192M		32
#define CLK_TOP_USB20_192M_D2		33
#define CLK_TOP_USB20_192M_D4_T		34
#define CLK_TOP_APLL1			35
#define CLK_TOP_APLL1_D2		36
#define CLK_TOP_APLL1_D3		37
#define CLK_TOP_APLL1_D4		38
#define CLK_TOP_APLL1_D8		39
#define CLK_TOP_APLL1_D16		40
#define CLK_TOP_APLL2			41
#define CLK_TOP_APLL2_D2		42
#define CLK_TOP_APLL2_D3		43
#define CLK_TOP_APLL2_D4		44
#define CLK_TOP_APLL2_D8		45
#define CLK_TOP_APLL2_D16		46
#define CLK_TOP_CLK26M			47
#define CLK_TOP_SYS_26M_D2		48
#define CLK_TOP_MSDCPLL			49
#define CLK_TOP_MSDCPLL_D2		50
#define CLK_TOP_DSPPLL			51
#define CLK_TOP_DSPPLL_D2		52
#define CLK_TOP_DSPPLL_D4		53
#define CLK_TOP_DSPPLL_D8		54
#define CLK_TOP_IPPLL			55
#define CLK_TOP_IPPLL_D2		56
#define CLK_TOP_NFI2X_CK_D2		57
#define CLK_TOP_AXI_SEL			58
#define CLK_TOP_MEM_SEL			59
#define CLK_TOP_UART_SEL		60
#define CLK_TOP_SPI_SEL			61
#define CLK_TOP_SPIS_SEL		62
#define CLK_TOP_MSDC50_0_HC_SEL		63
#define CLK_TOP_MSDC2_2_HC_SEL		64
#define CLK_TOP_MSDC50_0_SEL		65
#define CLK_TOP_MSDC50_2_SEL		66
#define CLK_TOP_MSDC30_1_SEL		67
#define CLK_TOP_AUDIO_SEL		68
#define CLK_TOP_AUD_INTBUS_SEL		69
#define CLK_TOP_HAPLL1_SEL		70
#define CLK_TOP_HAPLL2_SEL		71
#define CLK_TOP_A2SYS_SEL		72
#define CLK_TOP_A1SYS_SEL		73
#define CLK_TOP_ASM_L_SEL		74
#define CLK_TOP_ASM_M_SEL		75
#define CLK_TOP_ASM_H_SEL		76
#define CLK_TOP_AUD_SPDIF_SEL		77
#define CLK_TOP_AUD_1_SEL		78
#define CLK_TOP_AUD_2_SEL		79
#define CLK_TOP_SSUSB_SYS_SEL		80
#define CLK_TOP_SSUSB_XHCI_SEL		81
#define CLK_TOP_SPM_SEL			82
#define CLK_TOP_I2C_SEL			83
#define CLK_TOP_PWM_SEL			84
#define CLK_TOP_DSP_SEL			85
#define CLK_TOP_NFI2X_SEL		86
#define CLK_TOP_SPINFI_SEL		87
#define CLK_TOP_ECC_SEL			88
#define CLK_TOP_GCPU_SEL		89
#define CLK_TOP_GCPU_CPM_SEL		90
#define CLK_TOP_MBIST_DIAG_SEL		91
#define CLK_TOP_IP0_NNA_SEL		92
#define CLK_TOP_IP1_NNA_SEL		93
#define CLK_TOP_IP2_WFST_SEL		94
#define CLK_TOP_SFLASH_SEL		95
#define CLK_TOP_SRAM_SEL		96
#define CLK_TOP_MM_SEL			97
#define CLK_TOP_DPI0_SEL		98
#define CLK_TOP_DBG_ATCLK_SEL		99
#define CLK_TOP_OCC_104M_SEL		100
#define CLK_TOP_OCC_68M_SEL		101
#define CLK_TOP_OCC_182M_SEL		102

/* TOPCKGEN Gates */
#define CLK_TOP_CONN_32K		0
#define CLK_TOP_CONN_26M		1
#define CLK_TOP_DSP_32K			2
#define CLK_TOP_DSP_26M			3
#define CLK_TOP_USB20_48M_EN		4
#define CLK_TOP_UNIVPLL_48M_EN		5
#define CLK_TOP_SSUSB_TOP_CK_EN		6
#define CLK_TOP_SSUSB_PHY_CK_EN		7
#define CLK_TOP_I2SI1_MCK		8
#define CLK_TOP_TDMIN_MCK		9
#define CLK_TOP_I2SO1_MCK		10

/* INFRASYS */

#define CLK_INFRA_DSP_AXI		0
#define CLK_INFRA_APXGPT		1
#define CLK_INFRA_ICUSB			2
#define CLK_INFRA_GCE			3
#define CLK_INFRA_THERM			4
#define CLK_INFRA_PWM_HCLK		5
#define CLK_INFRA_PWM1			6
#define CLK_INFRA_PWM2			7
#define CLK_INFRA_PWM3			8
#define CLK_INFRA_PWM4			9
#define CLK_INFRA_PWM5			10
#define CLK_INFRA_PWM			11
#define CLK_INFRA_UART0			12
#define CLK_INFRA_UART1			13
#define CLK_INFRA_UART2			14
#define CLK_INFRA_DSP_UART		15
#define CLK_INFRA_GCE_26M		16
#define CLK_INFRA_CQDMA_FPC		17
#define CLK_INFRA_BTIF			18
#define CLK_INFRA_SPI			19
#define CLK_INFRA_MSDC0			20
#define CLK_INFRA_MSDC1			21
#define CLK_INFRA_DVFSRC		22
#define CLK_INFRA_GCPU			23
#define CLK_INFRA_TRNG			24
#define CLK_INFRA_AUXADC		25
#define CLK_INFRA_AUXADC_MD		26
#define CLK_INFRA_AP_DMA		27
#define CLK_INFRA_DEBUGSYS		28
#define CLK_INFRA_AUDIO			29
#define CLK_INFRA_FLASHIF		30
#define CLK_INFRA_PWM_FB6		31
#define CLK_INFRA_PWM_FB7		32
#define CLK_INFRA_AUD_ASRC		33
#define CLK_INFRA_AUD_26M		34
#define CLK_INFRA_SPIS			35
#define CLK_INFRA_CQ_DMA		36
#define CLK_INFRA_AP_MSDC0		37
#define CLK_INFRA_MD_MSDC0		38
#define CLK_INFRA_MSDC0_SRC		39
#define CLK_INFRA_MSDC1_SRC		40
#define CLK_INFRA_IRRX_26M		41
#define CLK_INFRA_IRRX_32K		42
#define CLK_INFRA_I2C0_AXI		43
#define CLK_INFRA_I2C1_AXI		44
#define CLK_INFRA_I2C2_AXI		45
#define CLK_INFRA_NFI			46
#define CLK_INFRA_NFIECC		47
#define CLK_INFRA_NFI_HCLK		48
#define CLK_INFRA_SUSB_133		49
#define CLK_INFRA_USB_SYS		50
#define CLK_INFRA_USB_XHCI		51
#define CLK_INFRA_NR_CLK		52

/* APMIXEDSYS */

#define CLK_APMIXED_ARMPLL		0
#define CLK_APMIXED_MAINPLL		1
#define CLK_APMIXED_UNIVPLL2		2
#define CLK_APMIXED_MSDCPLL		3
#define CLK_APMIXED_APLL1		4
#define CLK_APMIXED_APLL2		5
#define CLK_APMIXED_IPPLL		6
#define CLK_APMIXED_DSPPLL		7
#define CLK_APMIXED_TCONPLL		8
#define CLK_APMIXED_NR_CLK		9

#endif /* _DT_BINDINGS_CLK_MT8512_H */
