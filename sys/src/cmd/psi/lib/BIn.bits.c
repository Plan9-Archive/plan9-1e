int BInbits[]={
/*Aacute*/
0x1c00,0x3c00,0x7c00,0xf800,0x1e000,
0x3c000,0x70000,0x0,0x38000,0x38000,0x78000,
0xf8000,0xf8000,0x1fc000,0x3fc000,0x3fc000,0x77c000,
0x67c000,0xc7e000,0xc7e000,0x187e000,0x383e000,0x3ffe000,
0x603f000,0x603f000,0xc03f000,0x1c01f000,0x3801f000,0x7803f800,
0xfe0ffe00,0x0,
/*Acircumflex*/
0x3c000,0x7e000,0xfe000,0x1ef000,0x3c7000,
0x703800,0x0,0x30000,0x38000,0x78000,0xf8000,
0xf8000,0x1f8000,0x3fc000,0x3fc000,0x77c000,0x67c000,
0xc7e000,0xc7e000,0x187e000,0x383e000,0x3ffe000,0x603f000,
0x603f000,0xc03f000,0x1c01f000,0x1801f000,0x7803f800,0xfe0ffe00,
0x0,
/*Adieresis*/
0x1c1c00,0x3e3e00,0x3e3e00,0x3e3e00,0x1c1c00,
0x0,0x0,0x38000,0x38000,0x78000,0xf8000,
0xf8000,0x1fc000,0x3fc000,0x3fc000,0x77c000,0x67c000,
0xc7e000,0xc7e000,0x187e000,0x383e000,0x3ffe000,0x603f000,
0x603f000,0xc03f000,0x1c01f000,0x1801f000,0x7803f800,0xfe0ffe00,
0x0,
/*Agrave*/
0x1c0000,0x1e0000,0x1f0000,0xf0000,0x78000,
0x3c000,0xe000,0x0,0x30000,0x38000,0x78000,
0xf8000,0xf8000,0x1fc000,0x3fc000,0x3fc000,0x77c000,
0x67c000,0xc7e000,0xc7e000,0x187e000,0x383e000,0x3ffe000,
0x603f000,0x603f000,0xc03f000,0x1c01f000,0x1801f000,0x7803f800,
0xfe0ffe00,0x0,
/*Atilde*/
0xfc600,0x1ffe00,0x3bfc00,0x30f800,0x0,
0x0,0x38000,0x38000,0x78000,0xf8000,0xf8000,
0x1fc000,0x3fc000,0x3fc000,0x77c000,0x67c000,0xc7e000,
0xc7e000,0x187e000,0x383e000,0x3ffe000,0x603f000,0x603f000,
0xc03f000,0x1c01f000,0x3801f000,0x7803f800,0xfe0ffe00,0x0,
/*Eacute*/
0x7000,0xf00001,0xf00003e0,0x78000,0xe000000,
0x0,0x7fffe01,0xf8fe01f8,0x1e03f00c,0x3f00c03,0xf00c03e0,
0xc007e0c0,0x7e1c007,0xe78007ff,0x800fcf80,0xfc3000f,0xc3000f83,
0x1f8030,0x1f80301f,0x80703f80,0xf03f01e0,0x3f8fe0ff,0xffe00000,0xe00000,
/*Ecircumflex*/
0x3c000,0x7c0000f,0xe0001ee0,0x3c7000,0x70700000,
0x0,0x7fffe01,0xf8fe01f8,0x1e03f00c,0x3f00c03,0xf00c03e0,
0xc007e0c0,0x7e1c007,0xe78007ff,0x800fcf80,0xfc3800f,0xc3000f83,
0x1f8018,0x1f80181f,0x80383f80,0x703f01f0,0x3f8ff0ff,0xffe00000,0xe00000,
/*Edieresis*/
0x306000,0x78f00078,0xf00078f0,0x38e000,0x0,
0x7fffe,0x1f8fe01,0xf81e03f0,0xc03f00c,0x3f00c03,0xe0c007e0,
0xc007e1c0,0x7e78007,0xff800fcf,0x800fc300,0xfc3000f,0x83001f80,
0x301f8030,0x1f80703f,0x80f03f01,0xe03f8fe0,0xffffe000,0xe000,
/*Egrave*/
0x380000,0x3c00003e,0x1f00,0x70000,0x3800000,
0x0,0x7fffe01,0xf8fe01f8,0x1e03f00c,0x3f00c03,0xf00c03e0,
0xc007e0c0,0x7e1c007,0xe78007ff,0x800fcf80,0xfc3800f,0xc3000f83,
0x1f8018,0x1f80181f,0x80383f80,0x703f00f0,0x3f8ff0ff,0xffe00000,0xe00000,
/*Iacute*/
0x70000,0xf00001f,0x3e00,0x780000,0xe0000000,
0x0,0x7fe0003,0xfc0001f8,0x3f000,0x3f00003,0xf00003f0,
0x7e000,0x7e00007,0xe00007e0,0xfc000,0xfc0000f,0xc0000f80,
0x1f8000,0x1f80001f,0x80003f00,0x3f0000,0x7f8000ff,0xc0000000,0x0,
/*Icircumflex*/
0x7800f8,0x1fc03dc,0x78e0e06,0x0,0x7fe03fc,
0x1f803f0,0x3f003f0,0x3f007e0,0x7e007e0,0x7e00fc0,0xfc00fc0,
0xf801f80,0x1f801f80,0x3f003f00,0x7f80ffc0,0xffc0,
/*Idieresis*/
0x3060007,0x8f00078f,0x78f00,0x3060000,0x0,
0x7fe00,0x3fc0001,0xf80003f0,0x3f000,0x3f00003,0xf00007e0,
0x7e000,0x7e00007,0xe0000fc0,0xfc000,0xfc0000f,0x80001f80,
0x1f8000,0x1f80003f,0x3f00,0x7f8000,0xffc00000,0x0,
/*Igrave*/
0x38003c0,0x3e001e0,0x700038,0x0,0x7fe03fc,
0x1f803f0,0x3f003f0,0x3f007e0,0x7e007e0,0x7e00fc0,0xfc00fc0,
0xf801f80,0x1f801f80,0x3f003f00,0x7f80ffc0,0xffc0,
/*Oacute*/
0xe000,0x1e00003,0xe00007c0,0xf8000,0xe00001c,
0x0,0x7fc001,0xf1f003c0,0xf807c078,0xf807c1f,0x7c3f00,
0x7c3f00fc,0x7e00fc7e,0xfcfc00,0xfcfc01fc,0xfc01f8fc,0x1f8fc03,
0xf0fc03e0,0xf807e0f8,0x7c0780f,0x807c1f00,0x3f7c000f,0xf0000000,0x0,
/*Ocircumflex*/
0xf0000,0x1f80003f,0x80007bc0,0xf1c001,0xc0e00000,
0x7fc0,0x1f1f003,0xc0f807c0,0x780f807c,0x1f007c3f,0x7c3f00,
0xfc7e00fc,0x7e00fcfc,0xfcfc01,0xfcfc01f8,0xfc01f8fc,0x3f0fc03,
0xe0f807e0,0xf807c078,0xf807c1f,0x3f7c00,0xff00000,0x0,
/*Odieresis*/
0x30c000,0x79e00079,0xe00079e0,0x31c000,0x0,
0x7fc0,0x1f1f003,0xc0f807c0,0x780f807c,0x1f007c3f,0x7c3f00,
0xfc7e00fc,0x7e00fcfc,0xfcfc01,0xfcfc01f8,0xfc01f8fc,0x3f0fc03,
0xe0f807e0,0xf807c078,0xf807c1f,0x3f7c00,0xff00000,0x0,
/*Ograve*/
0x380000,0x3c00003e,0x1f00,0x70000,0x3800000,
0x7fc0,0x1f1f003,0xc0f807c0,0x780f807c,0x1f007c3f,0x7c3f00,
0xfc7e00fc,0x7e00fcfc,0xfcfc01,0xfcfc01f8,0xfc01f8fc,0x3f0fc03,
0xe0f807e0,0xf807c078,0xf807c1f,0x3f7c00,0xff00000,0x0,
/*Otilde*/
0x7e3000,0xfff001df,0xe00187c0,0x0,0x7f,
0xc001f1f0,0x3c0f807,0xc0780f80,0x7c1f007c,0x3f007c3f,0xfc7e00,
0xfc7e00fc,0xfc00fcfc,0x1fcfc01,0xf8fc01f8,0xfc03f0fc,0x3e0f807,
0xe0f807c0,0x780f807c,0x1f003f3c,0xff000,0x0,
/*Scaron*/
0xc1c000,0xe3c00077,0x80007f00,0x7e0000,0x3c000000,
0x1fcc0,0x7cfc00f,0x3c01e03,0x801e0380,0x1f01801f,0x81801fc0,
0x1fe000,0xff00007,0xfc0003fe,0xfe00,0x7f0000,0x3f00601f,
0x600f00,0x600f00e0,0x1f00f01e,0xfc7c00,0xdff80000,0x0,
/*Uacute*/
0x1c000,0x3c000,0x7c000,0xf8000,0x1e0000,
0x380000,0x0,0x0,0x7ff1fe00,0x3fe0fc00,0xf803800,
0x1f803000,0x1f807000,0x1f007000,0x3f006000,0x3f006000,0x3f00e000,
0x7e00e000,0x7e00c000,0x7e00c000,0x7c01c000,0xfc018000,0xfc018000,
0xfc038000,0xf8030000,0xf8030000,0xfc060000,0x7f1e0000,0x3ffc0000,
0x1ff00000,0x0,
/*Ucircumflex*/
0xf0000,0x1f0000,0x3f8000,0x7b8000,0xf1c000,
0x1c1c000,0x0,0x0,0x7ff0fe00,0x3fe07c00,0xf803800,
0x1f803000,0x1f807000,0x1f007000,0x3f006000,0x3f006000,0x3f00e000,
0x7e00e000,0x7e00c000,0x7e00c000,0x7c01c000,0xfc018000,0xfc018000,
0xfc038000,0xf8030000,0xf8030000,0xfc060000,0x7f1e0000,0x3ffc0000,
0x1ff00000,0x0,
/*Udieresis*/
0xe1c000,0x1f3e000,0x1f3e000,0x1f3e000,0xe1c000,
0x0,0x0,0x7ff1fe00,0x3fe0fc00,0xf803800,0x1f803000,
0x1f807000,0x1f007000,0x3f006000,0x3f006000,0x3f00e000,0x7e00e000,
0x7e00c000,0x7e00c000,0x7c01c000,0xfc018000,0xfc018000,0xfc038000,
0xf8030000,0xf8030000,0xfc060000,0x7f1e0000,0x3ffc0000,0x1ff00000,
0x0,
/*Ugrave*/
0xe00000,0xf00000,0xf80000,0x7c0000,0x1e0000,
0xe0000,0x0,0x0,0x7ff1fe00,0x3fe0fc00,0xf803800,
0x1f803000,0x1f807000,0x1f807000,0x3f006000,0x3f006000,0x3f00e000,
0x7e00e000,0x7e00c000,0x7e00c000,0x7c01c000,0xfc018000,0xfc018000,
0xfc038000,0xf8030000,0xf8030000,0xfc060000,0x7f1e0000,0x3ffc0000,
0x1ff00000,0x0,
/*Ydieresis*/
0x1860003,0xcf0003cf,0x3cf00,0x1860000,0x0,
0xff8fe0,0x7f07c03e,0x3803f07,0x3f0700,0x1f0e001f,0x8c001f98,
0xfb800,0xff0000f,0xe00007e0,0xfc000,0xfc0000f,0xc0001f80,
0x1f8000,0x1f80003f,0x80003f00,0x7f8000,0xffc00000,0x0,
/*Zcaron*/
0xe07000,0x71e0007b,0xc0003f80,0x3f0000,0x1e000000,
0x0,0xffff01f,0xe3f01e07,0xe01c0fc0,0x380fc030,0x1f80003f,
0x7e00,0x7e0000,0xfc0001f8,0x1f000,0x3f00007,0xe0000fc0,
0xfc060,0x1f80603f,0xe07e01,0xc07e03c0,0xfc3fc0ff,0xff800000,0x800000,
/*Eth*/
0x7ffe000,0x1f8f800,0x1f03c00,0x3f03e00,0x3f03e00,
0x3f01f00,0x3f01f00,0x3f01f00,0x1ffe1f00,0x3ffe3f00,0x3ffe3f00,
0x3ffc3f00,0xfc03f00,0xfc03f00,0xfc07e00,0xf807e00,0x1f80fc00,
0x1f80f800,0x1f81f000,0x3f03e000,0x7f1f8000,0xfffe0000,0x0,
/*Thorn*/
0x7fe0001,0xf80001f8,0x3f800,0x3ffc003,0xf3f007e1,
0xf807e1f8,0x7e0f807,0xe0f80fc1,0xf80fc1f8,0xfc3f00f,0xc3e00f8f,
0xc01fff80,0x1f80001f,0x80003f00,0x3f0000,0x7f0000ff,0xc0000000,0x0,
/*space*/
0x0,
/*exclam*/
0x38007c0,0x7c007c0,0x7c00f80,0xf800f00,0xf000e00,
0xe001c00,0x1c001c00,0x18001800,0x0,0x7800f800,0xf800f800,0xf800,
/*quotedbl*/
0x707800f8,0xf800f8f8,0xf8f800,0xf8f800f0,0xf000f0f0,
0xe0e000,0xe0e000c0,0xc000c0c0,0x0,
/*numbersign*/
0x38e0007,0x8e00079e,0x79e00,0x79e0007,0x1c007fff,
0x807fff80,0x7f1f800f,0x3c000f3c,0x8e3f00,0xffff00ff,0xff001e38,
0x1e7800,0x1e78001e,0x78001e78,0x1e7800,0x1c700000,0x0,
/*dollar*/
0xc0000,0xc00007c,0x1ff00,0x79bc00f,0x39c01e39,
0xc03e39c0,0x3e31803f,0x71803ff0,0x1ff000,0xff80007,0xfc0003fe,
0x1ff00,0x1ff0001,0x9f00639f,0x638f00,0xe30f00e7,0x1e00e71c,
0xf77800,0x3ff0001f,0x80001c00,0x1c0000,0x18000000,0x0,
/*percent*/
0xff0f800,0x1ffff000,0x3e3ee000,0x7c30c000,0xfc31c000,
0xf8718000,0xf8738000,0xf8670000,0xf0c60000,0xf1ce3e00,0x7b9c7f00,
0x3f1cf980,0x39f080,0x31f080,0x73e180,0xe7e180,0xe7e180,
0x1c7c380,0x187c300,0x387c600,0x703fc00,0x701f800,0x0,
/*ampersand*/
0x1f8000,0x79c00078,0xe000f0e0,0xf1e000,0xf1e000f3,
0xc000ff00,0xfe0001,0xf80007fc,0xfe1ffc7c,0x3c7c387c,0x7c70f87e,
0x60f83ec0,0xf83fc0fc,0x1f80fc1f,0xc07f1fe6,0x3ffffe1f,0xf1fc0000,0xfc0000,
/*quoteright*/
0x3c007e00,0x7e007e00,0x1e000e00,0x1c003800,0xf000c000,0xc000,
/*parenleft*/
0xc00180,0x3000600,0xe001c00,0x3c003800,0x78007800,
0x7000f000,0xf000f000,0xf000f000,0xe000e000,0xe000e000,0xe000e000,
0x70007000,0x30003000,0x18000800,0x800,
/*parenright*/
0x8000c00,0x6000600,0x7000700,0x3000380,0x3800380,
0x3800380,0x7800780,0x7800780,0x7800780,0x7000f00,0xf000e00,
0x1e001c00,0x38007000,0xe000c000,0xc000,
/*asterisk*/
0x7000700,0xe738f778,0xfef87ff0,0x7007ff0,0xfbf8f778,
0xe7380700,0x7000000,
/*plus*/
0x1c00001,0xc00001c0,0x1c000,0x1c00001,0xc00001c0,
0xffff80,0xffff80ff,0xff8001c0,0x1c000,0x1c00001,0xc00001c0,
0x1c000,0x1c00000,0x0,
/*comma*/
0x3e3e3e3e,0xe0c1c38,0xf0e00038,
/*hyphen*/
0xff80ff80,0xff80ff80,0xff80,
/*period*/
0x70f8f870,0xf8f870,
/*slash*/
0x1c00180,0x3800380,0x3000700,0x7000600,0xe000e00,
0xc001c00,0x1c001800,0x38003800,0x30007000,0x70006000,0xe000e000,0xe000,
/*zero*/
0x1f803de,0x78e0f8f,0x1f0f1f1f,0x3e1f3e1f,0x7e1f7c1f,
0xfc3ffc3f,0xfc3ff87e,0xf87ef87c,0xf87cf0f8,0xf0f071f0,0x39e01f80,0x1f80,
/*one*/
0x1fc0ffc,0x1f800f8,0x1f801f0,0x1f003f0,0x3e003e0,
0x3e007e0,0x7c007c0,0x7c00fc0,0xf800f80,0x1f801f00,0x7f80ffe0,0xffe0,
/*two*/
0x1f80007,0xfc000ffe,0x1e7f00,0x183f0000,0x1f00001f,
0x1f00,0x3e0000,0x3e00007c,0x7800,0xf00001,0xe00003c0,
0x78000,0x606000c,0xc001ffc,0x7ffc00,0xfff800ff,0xf8000000,0x0,
/*three*/
0x1fc0007,0xfe00063f,0xc3f00,0x1f0000,0x1f00003f,
0x3e00,0xf80007,0xfc0007fc,0xfe00,0x7e0000,0x7e00003e,
0x3e00,0x3e0000,0x3c00f078,0xf87000,0xf9e0007f,0x80000000,0x0,
/*four*/
0x1c000,0x7c0000f,0x80001f80,0x3f8000,0x7f0000ff,
0x1df00,0x39f0007,0x1e000e3e,0x1c3e00,0x383e0070,0x7e007fff,
0xffff00,0xfffe0000,0xfe0001f8,0x1f000,0x1f00001,0xf0000000,0x0,
/*five*/
0x3ff07ff,0x7fe0e00,0xc001e00,0x1fc03fe0,0x3ff00ff8,
0xfc007c,0x7c003c,0x3c003c,0x78e078,0xf0f0fbc0,0x7f800000,
/*six*/
0x1f0000,0x7e0001f8,0x3e000,0xfc0000f,0x80001f00,
0x3fc000,0x7ff0007e,0x78007c3c,0xfc3c00,0xf83c00f8,0x7c00f87c,
0xf87c00,0xf0fc00f0,0xf800f0f8,0x71f000,0x79e0001f,0xc0000000,0x0,
/*seven*/
0x1fff003f,0xfe003ffe,0x7ffc00,0x703c00c0,0x38000078,
0xf000,0xe00001,0xe00001c0,0x3c000,0x7800007,0xf00,
0x1e0000,0x1e00003c,0x3800,0x780000,0xf0000000,0x0,
/*eight*/
0x1fc0003,0xcf000787,0x800f0380,0xf03800f,0x83800f87,
0x800fcf00,0xffe0007,0xf80003fc,0xffc00,0x3cfe0078,0x3e00f83e,
0xf01e00,0xf01e00f0,0x1e00f83c,0x783c00,0x3c78000f,0xe0000000,0x0,
/*nine*/
0x3f807dc,0xf0e1f0f,0x1f0f3e1f,0x3e1f3e1f,0x3e1f3c3f,
0x3c3f3c3e,0x1e7e0ffc,0x7fc00f8,0x1f003e0,0x7c01f80,0x7e00f000,0xf000,
/*colon*/
0x1f001f00,0x1f001f00,0x0,0x0,0x0,
0x7800f800,0xf800f800,0xf800,
/*semicolon*/
0xf800f80,0xf800f80,0x0,0x0,0x0,
0x3e003e00,0x3e003e00,0xe000c00,0x1c003800,0xf000e000,0xe000,
/*less*/
0x8000,0x380000f,0x80003f80,0x1ff0007,0xfc001fe0,
0xff8000,0xfc0000f0,0xfc00,0xff8000,0x1fe00007,0xfc0001ff,
0x3f80,0xf8000,0x3800000,0x80000000,
/*equal*/
0xffff80ff,0xff80ffff,0x80000000,0x0,0xffff,
0x80ffff80,0xffff8000,0x8000,
/*greater*/
0x800000e0,0xf800,0xfe0000,0x7fc0000f,0xf00003fc,
0xff80,0x1f8000,0x780001f,0x8000ff80,0x3fc000f,0xf0007fc0,
0xfe0000,0xf80000e0,0x8000,0x0,
/*question*/
0x1fc039e0,0x79f078f0,0x78f079f0,0x31f001f0,0x3e007c0,
0xf801e00,0x1c003800,0x30003000,0x0,0x7000f800,0xf8007000,0x7000,
/*at*/
0x3ff000,0xfffc00,0x3f83f00,0x7c00380,0xf0001c0,
0x1e0000e0,0x3e07bc60,0x3c0ffc60,0x781efc70,0x783c7830,0xf8787830,
0xf878f830,0xf0f0f830,0xf0f0f070,0xf1f0f060,0xf1f0f060,0xf1e1f0c0,
0xf1e1f1c0,0xf9e3e380,0x79f7ef00,0x78fffc00,0x3cfcf800,0x3e000000,
0x1f000000,0x7c00000,0x3f87c00,0x7ff800,0x0,
/*A*/
0x30000,0x38000,0x78000,0xf8000,0xf8000,
0x1fc000,0x3fc000,0x3fc000,0x77c000,0x67c000,0xc7e000,
0xc7e000,0x187e000,0x383e000,0x3ffe000,0x603f000,0x603f000,
0xc03f000,0x1c01f000,0x1801f000,0x7803f800,0xfe0ffe00,0x0,
/*B*/
0x7ffe001,0xf9f001f0,0xf803f07c,0x3f07c03,0xf07c03f0,
0x7c03f0fc,0x7f1f807,0xe7f007ff,0x8007e7c0,0xfc3e00f,0xc1f00fc1,
0xf00fc1f0,0x1f83f01f,0x83f01f83,0xf03f07e0,0x3f9fc0ff,0xff000000,0x0,
/*C*/
0xffd803,0xf9f807e0,0x780f8078,0x1f80303f,0x307e00,
0x307e0030,0x7c0000fc,0xfc00,0xfc0000,0xf80000f8,0xf800,
0xf80000,0xf80000fc,0xc07c01,0xc03f0f80,0x1fff0007,0xfc000000,0x0,
/*D*/
0x7ffe000,0x1f8f800,0x1f83c00,0x3f03e00,0x3f03e00,
0x3f01f00,0x3f01f00,0x7e01f00,0x7e01f00,0x7e03f00,0x7e03f00,
0xfc03f00,0xfc03f00,0xfc03f00,0xfc07e00,0x1f807e00,0x1f80fc00,
0x1f80f800,0x1f81f000,0x3f03e000,0x3f1f8000,0xfffe0000,0x0,
/*E*/
0x7fffe01,0xf8fe01f8,0x1e03f00c,0x3f00c03,0xf00c03e0,
0xc007e0c0,0x7e1c007,0xe78007ff,0x800fcf80,0xfc3800f,0xc3000f83,
0x1f8018,0x1f80181f,0x80381f80,0x703f00f0,0x3f8ff0ff,0xffe00000,0xe00000,
/*F*/
0x7fffe01,0xf87e01f8,0x1e03f00c,0x3f00c03,0xf00c03e0,
0xc007e0c0,0x7e1c007,0xe7800fff,0x800fcf80,0xfc3800f,0xc3000f83,
0x1f8300,0x1f80001f,0x80001f80,0x3f0000,0x7f8000ff,0xc0000000,0x0,
/*G*/
0x7fec01,0xfcfc03e0,0x3c07c01c,0xf80181f,0x80183f00,
0x183f0000,0x7e00007e,0xfe00,0xfe03fe,0xfe01fcfc,0xf8fc01,
0xf8fc01f8,0xfc01f87e,0x1f07e01,0xf03f03f0,0x1fcfe007,0xff800000,0x800000,
/*H*/
0xfff3fe0,0xfff3fe0,0x1f80f80,0x3f01f80,0x3f01f80,
0x3f01f80,0x7e01f00,0x7e03f00,0x7e03f00,0x7ffff00,0xffffe00,
0xfc03e00,0xfc07e00,0xfc07e00,0x1f807c00,0x1f80fc00,0x1f80fc00,
0x1f80fc00,0x1f01fc00,0x3f01f800,0xffcfff00,0xffcfff00,0x0,
/*I*/
0x7fe03fc,0x1f803f0,0x3f003f0,0x3f007e0,0x7e007e0,
0x7e00fc0,0xfc00fc0,0xf801f80,0x1f801f80,0x3f003f00,0x7f80ffc0,0xffc0,
/*J*/
0x3fe000,0x1fc0000f,0x80001f80,0x1f8000,0x1f00001f,
0x3f00,0x3f0000,0x3e00007e,0x7e00,0x7e0000,0x7c0000fc,
0xfc00,0xfc0001,0xf80001f8,0x1f800,0xf9f000fb,0xf000fbe0,
0x77c000,0x3f800000,0x0,
/*K*/
0x7fcfe03,0xf87c01f0,0x3803f070,0x3f0e003,0xe1c003e3,
0x7ee00,0x7dc0007,0xf8000ffc,0xffc00,0xffe000f,0x7e001f3f,
0x1f3f00,0x1f1f803f,0xf803f0f,0xc03e07c0,0x7f0fe0ff,0x9ff00000,0xf00000,
/*L*/
0xffe0003,0xf80001f0,0x3f000,0x3f00003,0xf00003e0,
0x7e000,0x7e00007,0xe00007e0,0x7c000,0xfc0000f,0xc0000fc0,
0xf8000,0x1f80181f,0x80381f80,0x703f00f0,0x3f8ff0ff,0xffe00000,0xe00000,
/*M*/
0x7f801fe,0x1f801fc,0x3f803f8,0x3f807f8,0x3f807f0,
0x3f80ff0,0x7f81ff0,0x6f81bf0,0x6fc37e0,0x6fc77e0,0xcfc67e0,
0xcfce7e0,0xcfccfc0,0x1c7d8fc0,0x187f8fc0,0x187f1f80,0x187e1f80,
0x387e1f80,0x307c1f80,0x30381f00,0x7c383fc0,0xfe30ffe0,0x0,
/*N*/
0xff03fc0,0x7f81f80,0x3f80600,0x1f80600,0x3fc0600,
0x37c0e00,0x37c0c00,0x73e0c00,0x63e1c00,0x63f1800,0xe1f1800,
0xc1f3800,0xc0fb000,0x1c0fb000,0x1c0ff000,0x1807f000,0x3807e000,
0x3803e000,0x3003e000,0x7001e000,0x7c01c000,0xfe00c000,0x0,
/*O*/
0x7fc001,0xf1f003c0,0xf807c078,0xf807c1f,0x7c3f00,
0x7c3f00fc,0x7e00fc7e,0xfcfc00,0xfcfc01fc,0xfc01f8fc,0x1f8fc03,
0xf0fc03e0,0xf807e0f8,0x7c0780f,0x807c1f00,0x3f7c000f,0xf0000000,0x0,
/*P*/
0x7ffc001,0xfbf001f1,0xf003f0f8,0x3f0f803,0xe0f803e1,
0xf807e1f8,0x7e1f007,0xe3f007c7,0xc00fff00,0xfc0000f,0xc0000f80,
0x1f8000,0x1f80001f,0x80001f00,0x3f0000,0x7f0000ff,0xc0000000,0x0,
/*Q*/
0x7fc001,0xf1f003c0,0xf807c078,0xf807c1f,0x7c3f00,
0x7c3e00fc,0x7e00fc7e,0xfcfc00,0xfcfc01fc,0xfc01f8fc,0x1f8fc03,
0xf0f803f0,0xf803e0f8,0x7c0780f,0x807c1f00,0x3e3e001f,0xf8000700,
0xf8018,0x1ffc783f,0xfff0ffff,0xc0e3ff80,0xff0000,0x0,
/*R*/
0x7ffe001,0xf9f801f1,0xf803f0fc,0x3f0fc03,0xf0fc07e1,
0xfc07e1f8,0x7e3f007,0xefe00fff,0xfff00,0xfdf000f,0xdf001f9f,
0x801f8f80,0x1f8f801f,0x8fc01f07,0xc03f07c0,0x7f87e0ff,0xc3f80000,0xf80000,
/*S*/
0x1fcc007,0xcfc00f03,0xc01e0380,0x1e03801f,0x1801f81,
0x801fc000,0x1fe0000f,0xf00007fc,0x3fe00,0xfe0000,0x7f00003f,
0x601f00,0x600f0060,0xf00e01f,0xf01e00,0xfc7c00df,0xf8000000,0x0,
/*T*/
0x7ffff07c,0xf9f0f1f8,0xf0e1f870,0xc1f870c3,0xf06003f0,
0x6003f000,0x3e00007,0xe00007e0,0x7e000,0x7c0000f,0xc0000fc0,
0xf8000,0xf80001f,0x80001f80,0x1f0000,0x3f8000ff,0xe0000000,0x0,
/*U*/
0x7ff0fe00,0x3fe07c00,0xf803800,0x1f803000,0x1f807000,
0x1f007000,0x3f006000,0x3f006000,0x3f00e000,0x7e00e000,0x7e00c000,
0x7e00c000,0x7c01c000,0xfc018000,0xfc018000,0xfc038000,0xf8030000,
0xf8030000,0xfc060000,0x7f1e0000,0x3ffc0000,0x1ff00000,0x0,
/*V*/
0xff81f87f,0xf03e00,0x603e00e0,0x3f00c03f,0x1803f03,
0x803f0300,0x3f06001f,0xe001f0c,0x1f1800,0x1f38001f,0xb0001fe0,
0x1fe000,0xfc0000f,0x80000f80,0xf0000,0xe00000e,0x0,0x0,
/*W*/
0xff9ff1f8,0x7f0fe0f0,0x3e07c060,0x3e07c0c0,0x3f0fe1c0,
0x3f0fe180,0x3f0fe180,0x3f1fe300,0x3f1be300,0x1f33e600,0x1f33e600,
0x1fe3fc00,0x1fe3fc00,0x1fc3fc00,0x1fc3f800,0x1fc3f800,0xf83f000,
0xf01e000,0xf01e000,0xe01c000,0xe01c000,0xc018000,0x0,
/*X*/
0xffc7f00,0x7f83e00,0x3f03c00,0x1f87800,0x1f8f000,
0x1f9c000,0xfb8000,0xff0000,0xfe0000,0x7c0000,0x7e0000,
0x7e0000,0x7e0000,0xff0000,0x1ff0000,0x39f0000,0x71f8000,
0xe1f8000,0x1c0f8000,0x380fc000,0x7c1fe000,0xfe3ff000,0x0,
/*Y*/
0xff87f07f,0x3e03e01,0xc03f0380,0x3f03001f,0x7001f8e,
0x1f9c00,0xf98000f,0xf0000ff0,0x7e000,0xfc0000f,0xc0000fc0,
0xf8000,0x1f80001f,0x80001f80,0x1f0000,0x7f8000ff,0xe0000000,0x0,
/*Z*/
0xffff01f,0xe3f01e07,0xe01c0fc0,0x380fc030,0x1f80003f,
0x7e00,0x7e0000,0xfc0001f8,0x1f000,0x3f00007,0xe0000fc0,
0xfc060,0x1f80603f,0xe07e01,0xc07e03c0,0xfc3fc0ff,0xff800000,0x800000,
/*bracketleft*/
0x1fc01fc,0x3c003c0,0x3c00380,0x7800780,0x7800f00,
0xf000f00,0xf001e00,0x1e001e00,0x1e003c00,0x3c003c00,0x3c007800,
0x78007800,0x7000ff00,0xff000000,
/*backslash*/
0xf0007800,0x78003c00,0x3c001e00,0xe000f00,0x7000780,
0x3c003c0,0x1e001e0,0xf00070,0x78003c,0x3c001e,0x1e000f,0xf,
/*bracketright*/
0x7f807f8,0x7000f0,0xf000f0,0xf001e0,0x1e001e0,
0x1e001c0,0x3c003c0,0x3c003c0,0x7800780,0x7800780,0x7000f00,
0xf000f00,0xf00fe00,0xfe000000,
/*asciicircum*/
0x3e00007,0xf00007f0,0xff800,0xf78001f,0x7c001e3c,
0x3c1e00,0x3c1e0078,0xf00780f,0xf00780,0xf0078000,0x8000,
/*underscore*/
0xffff8000,0x8000,
/*quoteleft*/
0x6000e00,0x3c007000,0x6000e000,0xf800fc00,0xfc00fc00,
0x78000000,
/*a*/
0x1ef07ff,0xfbf1f1e,0x3e1e3c3e,0x7c3ef83c,0xf87cf87c,
0xf0fcf0f9,0xfbff7f7e,0x3e7c0000,
/*b*/
0x1fc01fc0,0x7800f80,0xf800f00,0xf001f7c,0x1ffe1fbe,
0x3e1e3e1e,0x3e1e3c3e,0x7c3e783c,0x787cf878,0xf8f0f8e0,0xf3c07f80,0x7f80,
/*c*/
0x1f807bc,0xf3c1e3c,0x3e3c3c00,0x7c00fc00,0xf800f800,
0xf800f830,0xfc707fc0,0x3f800000,
/*d*/
0x1fc000,0x1fc00007,0xc0000780,0xf8000,0xf80000f,
0x8001ff00,0x7ff000f,0xbf001f1f,0x3e3e00,0x3e3e007c,0x3e007c3e,
0xfc7c00,0xf87c00f8,0x7c00f8fd,0xfdfb00,0xfffe007e,0x7c000000,0x0,
/*e*/
0x1f8079c,0xf1c1e3c,0x3e3c7c78,0x7cf0ffe0,0xff80f800,
0xf800f830,0xfc607fe0,0x3f800000,
/*f*/
0x7e000,0xff000,0x1ef000,0x1e7000,0x3c0000,
0x7c0000,0x7c0000,0x7f0000,0x1ff0000,0x1f80000,0xf80000,
0xf80000,0xf80000,0xf80000,0xf00000,0x1f00000,0x1f00000,
0x1f00000,0x1e00000,0x3e00000,0x3e00000,0x3e00000,0x3c00000,
0x3c00000,0xf7800000,0xf7800000,0xf7000000,0xfe000000,0x7c000000,
0x0,
/*g*/
0x3f80007,0xbfc00f9f,0xc01f1f00,0x1f1f001f,0x3f001e3e,
0x1e3c00,0xf780007,0xf0001c00,0x3e0000,0x3fe0003f,0xf8001ff8,
0x7bfc00,0xf07c00e0,0x3c00f038,0x78f000,0x3fe00000,0x0,
/*h*/
0xfc0001f,0xc0000fc0,0x78000,0xf80000f,0x80000f80,
0xf1e00,0x1f3f001f,0x7f001fef,0x1f8f00,0x1f9f003f,0x1e003e3e,
0x3e3e00,0x7c3c007c,0x7c007c7d,0x80f87b80,0xf87f00f8,0x7c000000,0x0,
/*i*/
0xf000f00,0xf000f00,0x0,0x3e00,0x7e007e00,
0x3c007c00,0x7c007c00,0x78007800,0xf800f800,0xf200f600,0xfc00f800,0xf800,
/*j*/
0x1e0000,0x1e00001e,0x1e00,0x0,0x0,
0x7c00,0x1fc0001,0xfc000078,0xf800,0xf80000,0xf80000f0,
0x1f000,0x1f00001,0xf00001e0,0x3e000,0x3e00003,0xc00003c0,
0x7c000,0x78000e7,0x8000f700,0xee0000,0x7c000000,0x0,
/*k*/
0xfe0000f,0xe00003e0,0x3c000,0x7c00007,0xc0000780,
0xfbf80,0xf9f000f,0x9c000f18,0x1f3000,0x1fe0001f,0xf0003ff0,
0x3ff000,0x3df0007c,0xf0007cf9,0x78fb00,0xf87e00f8,0x3c000000,0x0,
/*l*/
0x3fc03fc0,0x7c00f80,0xf800f80,0x1f001f00,0x1f003e00,
0x3e003e00,0x3c007c00,0x7c007800,0xf800f800,0xfb00f600,0xfc00f800,0xf800,
/*m*/
0x3f9f1f3f,0xbf3f1f7f,0x7f1fefef,0x1fdfdf1f,0x9f9e3f1f,
0x1e3e3e3e,0x3e3e3e7c,0x3c3c7c7c,0x7c787c7f,0xf8787ff8,0xf87ef8f8,
0x3c000000,
/*n*/
0x1fcf003f,0xdf801fbf,0x800ff780,0x1fef801f,0xcf801f8f,
0x3f1f00,0x3e1f003e,0x3e007c3e,0x7c3f80,0x7c3d80f8,0x3f00f81e,
0x0,
/*o*/
0x3f80fbc,0x1e1e3e1e,0x3c1e7c3e,0xf83ef83e,0xf87cf87c,
0xf078f0f0,0xf1f079e0,0x3f800000,
/*p*/
0x3f7c007,0xffe003ff,0xf001f9f0,0x3f1f003,0xe1f003e3,
0xf003e3f0,0x7c3e007,0xc3e007c7,0xc007c7c0,0xf8f800f,0x9f000ffc,
0xf8000,0x1f00001f,0x1f00,0x1e0000,0x3f0000ff,0xc0000000,0x0,
/*q*/
0x7fe0f7e,0x1e3e3e3c,0x3c7c7c7c,0x787cf878,0xf8f8f0f8,
0xf0f8f1f0,0xf3f0fff0,0x7df001f0,0x3e003e0,0x3e007e0,0xfe01ff0,0x1ff0,
/*r*/
0x3fbc3ffc,0xffc0ffc,0x1f801f00,0x1f003e00,0x3e003e00,
0x7c007c00,0x7c00f800,0xf8000000,
/*s*/
0x7d80ef8,0x1c381e30,0x1e301f00,0x1f800f80,0xfc007c0,
0x63c0e3c0,0xe1c0f380,0xff000000,
/*t*/
0x3000700,0x7000f00,0x3f807f80,0x7e803e00,0x3e003c00,
0x7c007c00,0x78007800,0xf800f800,0xf200fe00,0xfc00f800,0xf800,
/*u*/
0x3f8f807f,0x8f807f0f,0x801f1f00,0x3f1f003e,0x3f003e3e,
0x7c3e00,0x7c7e007c,0xfc00f9fc,0xfbfd80,0xff7b80fe,0x7f00fc7e,
0x0,
/*v*/
0xfc78fc78,0x7c787c78,0x7c303c70,0x3c603ce0,0x3dc03f80,
0x3f003e00,0x3c003800,0x30000000,
/*w*/
0xfc1c78fe,0x1c783e3c,0x783e7c78,0x3e7c383e,0xfc301efc,
0x601ffce0,0x1fbcc01f,0x3f801f3f,0x801e3f00,0x1c3e001c,0x3c001838,
0x0,
/*x*/
0x3f87803f,0x8f800f9f,0x8007f780,0x7e00007,0xe00007c0,
0x3e000,0x3e00007,0xe00007e0,0xfe600,0xfdfe00f9,0xfc00f0f8,
0x0,
/*y*/
0x1f8f001f,0x8f0007cf,0x7cf00,0x7c70003,0xc30003e6,
0x3e600,0x3e60001,0xec0001fc,0x1f800,0x1f80000,0xf00000e0,
0xe000,0x1c00001,0x8000f300,0xfe0000,0xfc0000f8,0x0,0x0,
/*z*/
0x1ffc1ffc,0x3ff83870,0x30e001c0,0x1800300,0x6000c00,
0x1c003e00,0x7f3cffbc,0xcfbc03f8,0x3f8,
/*braceleft*/
0x1e003c0,0x7800700,0xf000f00,0xf000e00,0x1e001e00,
0x1e003c00,0x3c00f000,0x38003800,0x78007800,0x78007800,0xf000f000,
0xf000e000,0xe000e000,0x78000000,
/*bar*/
0xe0e0e0e0,0xe0e0e0e0,0xe0e0e0e0,0xe0e0e0e0,0xe0e0e0e0,0xe0e000e0,
/*braceright*/
0x3c000e0,0xe001e0,0x1e001e0,0x1e003c0,0x3c003c0,
0x3c00380,0x3c001e0,0x3800780,0x7000f00,0xf000f00,0xe001e00,
0x1e001e00,0x1c003c00,0xf0000000,
/*asciitilde*/
0x1f01003f,0x83807fe7,0x80ffff80,0xf3ff00e0,0xfe00403c,
0x0,
/*aacute*/
0xf001f,0x3f007c,0xf00000,0x1ef,0x7ff0fbf,
0x1f1e3e1e,0x3c3e7c3e,0xf83cf87c,0xf87cf0fc,0xf0f9fbff,0x7f7e3e7c,0x3e7c,
/*acircumflex*/
0x7c00fe,0x1fe03cf,0x7870000,0x1ef,0x7ff0fbf,
0x1f1e3e1e,0x3c3e7c3e,0xf83cf87c,0xf87cf0fc,0xf0f9fbff,0x7f7e3e7c,0x3e7c,
/*adieresis*/
0x30e0007,0x8f00078f,0x78f00,0x3060000,0x0,
0x3de00,0xffe001f,0x7e003e3c,0x3c3c00,0x7c7c0078,0x7c00f878,
0xf8f800,0xf8f800f0,0xf800f1f2,0xfbfe00,0xfefc007c,0x78000000,0x0,
/*agrave*/
0x1c001e0,0x1f00078,0x1c0000,0x1ef,0x7ff0fbf,
0x1f1e3e1e,0x3c3e7c3e,0xf83cf87c,0xf87cf0fc,0xf0f9fbff,0x7f7e3e7c,0x3e7c,
/*aring*/
0x7800fc,0x1ce0186,0x1ce00fc,0x7801ef,0x7ff0fbf,
0x1f1e3e1e,0x3c3e7c3e,0xf83cf87c,0xf87cf0fc,0xf0f9fbff,0x7f7e3e7c,0x3e7c,
/*atilde*/
0x3f18007,0xff800fff,0xc7e00,0x0,0x3ef,
0x7ff00,0xfbf001f,0x1e003e1e,0x3c3e00,0x7c3e00f8,0x3c00f87c,
0xf87c00,0xf0fc00f0,0xf900fbff,0x7f7e00,0x3e7c0000,0x0,
/*eacute*/
0xe003e,0x7e00f8,0x1e00000,0x1f8,0x79c0f1c,
0x1e3c3e3c,0x7c787cf0,0xffe0ff80,0xf800f800,0xf830fc70,0x7fe03f80,0x3f80,
/*ecircumflex*/
0xf801fc,0x3fc079e,0xe0e0000,0x1f8,0x79c0f1c,
0x1e3c3e3c,0x7c787cf0,0xffe0ff80,0xf800f800,0xf830fc70,0x7fe03f80,0x3f80,
/*edieresis*/
0x61c0f1e,0xf1e0f1e,0x60c0000,0x3f0,0xfb81e38,
0x3e783c78,0x7c707ce0,0xffc0ff00,0xf800f800,0xf860fce0,0x7fc03f80,0x3f80,
/*egrave*/
0x7000780,0x7c001e0,0x700000,0x3f0,0xfb81e38,
0x3e783c78,0x7c707ce0,0xffc0ff00,0xf800f800,0xf860fce0,0x7fc03f80,0x3f80,
/*iacute*/
0x7800f8,0x1f803c0,0x7000000,0x7f00,0x7f001f00,
0x1e003e00,0x3e003e00,0x3c003c00,0x7c007c00,0x7900fb00,0xfe00fc00,0xfc00,
/*icircumflex*/
0x7c00fe0,0x1fe03cf0,0x78700000,0x7f00,0x7f001f00,
0x1e003e00,0x3e003e00,0x3c003c00,0x7c007c00,0x7900fb00,0xfe00fc00,0xfc00,
/*idieresis*/
0x38707cf8,0x7cf87cf8,0x38700000,0x7f00,0x7f003f00,
0x1e003e00,0x3e003e00,0x3c003c00,0x7c007c00,0x7900fb00,0xfe00fc00,0xfc00,
/*igrave*/
0x1c001e00,0x1f000780,0x1c00000,0x3f00,0x7f007f00,
0x1e003e00,0x3e003e00,0x3c003c00,0x7c007c00,0x7900fb00,0xfe00fc00,0xfc00,
/*oacute*/
0xf0000,0x1f00003f,0x7800,0xe00000,0x0,
0x3f000,0xfbc001e,0x1e003e1e,0x3c1e00,0x7c3e00f8,0x3e00f83e,
0xf87c00,0xf87c00f0,0x7800f0f0,0xf0f000,0x79e0001f,0x80000000,0x0,
/*ocircumflex*/
0xf801fc,0x3fc079e,0xf0e0000,0x3f8,0xfbc1e1e,
0x3e1e3c1e,0x7c3ef83e,0xf83ef87e,0xf87cf078,0xf0f0f0f0,0x79e03f80,0x3f80,
/*odieresis*/
0x30e0007,0x8f00078f,0x78f00,0x30e0000,0x0,
0x3f800,0xfbc001e,0x1e003e1e,0x3c1e00,0x7c3e00f8,0x3e00f83e,
0xf87c00,0xf87c00f0,0x7800f0f0,0xf0f000,0x79e0003f,0x80000000,0x0,
/*ograve*/
0x38003c0,0x3e000f0,0x380000,0x3f8,0xfbc1e1e,
0x3e1e3c1e,0x7c3ef83e,0xf83ef87c,0xf87cf078,0xf0f0f1f0,0x79e03f80,0x3f80,
/*otilde*/
0x3f30007,0xff000ffe,0xc7c00,0x0,0x3f0,
0xfbc00,0x1e1e003e,0x1e003c1e,0x7c3e00,0xf83e00f8,0x3e00f87c,
0xf87c00,0xf07800f0,0xf000f1f0,0x7be000,0x3f800000,0x0,
/*scaron*/
0x60f079e,0x3f803f0,0x1e00000,0x7d8,0xef81c38,
0x1e301e30,0x1f001f80,0xfc00fc0,0x7e063e0,0xe3e0e1e0,0xf3c0ff80,0xff80,
/*uacute*/
0x78000,0xf80001f,0x80007c00,0xf00000,0x0,
0x3f8f80,0x7f8f807f,0xf801f1f,0x3f1f00,0x3e3f003e,0x3e007c7e,
0x7c7e00,0x7cfc00f9,0xfc00fbfd,0x80ff7b80,0xfe7f00fc,0x7e000000,0x0,
/*ucircumflex*/
0xf80001,0xf80003fc,0x79e00,0xf0e0000,0x0,
0x7f1f00,0x7f1f007e,0x1f003e3e,0x7e3e00,0x7c3e007c,0x7c007c7c,
0x78fc00,0xf9f800f3,0xf800f7fb,0xfefe00,0xfcfc00f8,0xf8000000,0x0,
/*udiresis*/
0x78f0007,0x8f00078f,0x78f00,0x0,0x3f1e,
0x7f1e00,0x7e3e003e,0x3e007e3c,0x7c7c00,0x7c7c0078,0xfc0078f8,
0xf9f800,0xf3f800f7,0xfb00fefe,0xfcfc00,0xf8f80000,0x0,
/*ugrave*/
0x1c00001,0xe00001f0,0x7800,0x1c0000,0x0,
0x3f8f80,0x7f8f803f,0xf801f1f,0x3f1f00,0x3e3f003e,0x3e007c7e,
0x7c7e00,0x7cfc00f9,0xfc00fbfd,0x80ff7b80,0xfe7f00fc,0x7e000000,0x0,
/*ydieresis*/
0xc18001,0xe3c001e3,0xc001e3c0,0xc18000,0x0,
0x1f8f00,0x1f8f0007,0x8f0007cf,0x7c700,0x3c30003,0xc60003e6,
0x3e600,0x1ec0001,0xfc0001f8,0x1f800,0xf00000,0xe00000e0,
0x1c000,0x18000f3,0xfe00,0xfc0000,0xf8000000,0x0,
/*zcaron*/
0x3878003,0xcf0001fe,0x1fc00,0xf80000,0x0,
0x1ffc00,0x1ffc003f,0xf8003870,0x30e000,0x1c00001,0x80000300,
0x60000,0xe00001c,0x3e00,0x7f3c00,0xffbc00cf,0xbc0001f8,
0x0,
/*eth*/
0x1f00000f,0xde0007ff,0xfff00,0x1ff8000f,0xf800007c,
0x3fc00,0xfbe001e,0x1e003e1e,0x3c1e00,0x7c3e00f8,0x3e00f83e,
0xf87c00,0xf87c00f0,0x7800f0f8,0xf0f000,0x79e0001f,0x80000000,0x0,
/*thorn*/
0x3f80003,0xf80000f8,0x1f000,0x1f00001,0xf00001e0,
0x3ef80,0x3ffc003,0xf7c003e3,0xc007c3c0,0x7c3c007,0x87c00787,
0xc00f8780,0xf0f800f,0xf000f1f,0x1f1e00,0x1e7c001f,0xf0001e00,
0x3e0000,0x3e00003e,0x3c00,0x7e0000,0xff000000,0x0,
/*exclamdown*/
0xf800f80,0xf800f00,0x0,0xc000c00,0xc001c00,
0x1c003c00,0x3c007800,0x7800f800,0xf800f800,0xf800f800,0x70000000,
/*cent*/
0xc000c,0x180078,0x3f807bc,0xf7c1e7c,0x3e7c7c78,
0x7cc0fcc0,0xf9c0f980,0xf980fb30,0xff707fe0,0x3fc00f80,0xc000c00,
0xc000c00,0xc00,
/*sterling*/
0x1f8000,0x7bc00073,0xc000f3c0,0x1f3c001,0xe00003e0,
0x3e000,0x3e0003f,0xfc003ffc,0x3ffc00,0x3c00007,0xc00007c0,
0x78000,0x3f8000ff,0x600cfce,0x8ffc00,0xcffc007d,0xf8000000,0x0,
/*fraction*/
0x60000,0xe00000c,0x1800,0x380000,0x30000060,
0xe000,0xc00001,0x80000380,0x30000,0x600000e,0xc00,
0x1c0000,0x18000030,0x7000,0x600000,0xc0000000,0x0,
/*yen*/
0xff87f07f,0x3e03e01,0xc03f0380,0x3f03001f,0x6001f8e,
0x1f9c00,0xf98000f,0xf0000ff0,0x3ffc00,0x7ffc007f,0xfc000fc0,
0xfc000,0xfff800ff,0xf8001f00,0x1f0000,0x7fc000ff,0xe0000000,0x0,
/*florin*/
0x3f000,0xf78000f,0x78001e78,0x3e0000,0x3e00003e,
0x7c00,0x3ffc003,0xffc000fc,0xfc00,0xfc0000,0xf80000f8,
0x1f800,0x1f80001,0xf00001f0,0x1f000,0x3e00003,0xe000f3e0,
0xf3c000,0xf78000f7,0x7e00,0x0,
/*section*/
0x3f8071c,0xe1e0e1e,0xf1e0f80,0x78007c0,0x1fe03bf0,
0x70f87078,0x787c783c,0x7c3c3c1c,0x3e1c1fb8,0xff007e0,0x3c003e0,
0xf1e0f0e0,0xf0e073c0,0x3f800000,
/*currency*/
0x67f300ff,0xff80ffff,0x807e3f00,0x780f00f0,0x780f007,
0x80e00380,0xe00380f0,0x780f007,0x80780f00,0x7e3f00ff,0xff80ffff,
0x8067f300,0x0,
/*quotesingle*/
0x7800fc00,0xfc00fc00,0xfc00f800,0xf000f000,0xe000e000,
0xc0000000,
/*quotedblleft*/
0x603000e,0x7003c1e,0x703800,0x703000e0,0x7000f87c,
0xfc7e00,0xfc7e00fc,0x7e00783c,0x0,
/*guillemotleft*/
0x186038e,0x71c1e78,0x3cf079e0,0xfbc0fbe0,0x79e03cf0,
0x1c700c30,0xc300000,
/*guilsinglleft*/
0x1800380,0x7001e00,0x3c007800,0xf000f800,0x78003c00,
0x1c000c00,0xc000000,
/*guilsinglright*/
0x18001c00,0x1e000f00,0xf000780,0xf001e00,0x3c007800,
0x7000e000,0xc0000000,
/*fi*/
0x3f000,0xfb800,0x1e3c00,0x3e3c00,0x3c0000,
0x7c0000,0x7c0c00,0x3fffc00,0x3fffc00,0x2f87800,0xf8f800,
0xf8f800,0xf0f800,0xf0f000,0x1f0f000,0x1f1f000,0x1e1f000,
0x1e1f000,0x3e1e400,0x3e1fc00,0x3c1f800,0x3c1f000,0x3c00000,
0x7800000,0x7800000,0xe7000000,0xef000000,0xee000000,0x7c000000,
0x0,
/*fl*/
0x3ff00,0xfbf00,0x1e3f00,0x1e3e00,0x3c1e00,
0x3c3e00,0x7c3e00,0x783c00,0x3fffc00,0x3f87c00,0xf8fc00,
0xf8f800,0xf8f800,0xf0f800,0x1f0f800,0x1f1f000,0x1f1f000,
0x1e1f000,0x3e1e600,0x3e1ec00,0x3c1f800,0x3c1f000,0x7c00000,
0x7800000,0xe7800000,0xef000000,0xef000000,0x7e000000,0x78000000,
0x0,
/*endash*/
0xffff80ff,0xff80ffff,0x80000000,
/*dagger*/
0x3800380,0x3800380,0x3800300,0xfef8fff8,0xfef80600,
0x6000e00,0x1f001e00,0x1e001e00,0x1c001c00,0x1c001800,0x18003800,
0x30003000,0x30003000,0x20000000,
/*daggerdbl*/
0xf000f0,0xf000e0,0xe000c0,0x3efe3ffe,0x3efe0180,
0x1800180,0x3c003c0,0x3800380,0x3000300,0xfaf8fff8,0xfaf80600,
0xe001e00,0x1f001e00,0xe000000,
/*periodcentered*/
0x70f8f8f8,0x7000f8f8,
/*paragraph*/
0x3ffc00f,0xffc01fff,0xc03fcc00,0x3fdc007f,0x9c00ff98,
0xff9800,0xffb800ff,0x3800ff30,0xff7000,0xff7000fe,0x70007e60,
0x7ee000,0x3ce0000c,0xc0001cc0,0x1dc000,0x19c00039,0x80003b80,
0x3b8000,0x33800073,0x7700,0x670000,0x0,
/*bullet*/
0x3e007f00,0xff80ff80,0xff80ff80,0x7f003e00,0x3e00,
/*quotesinglbase*/
0x38007c00,0x7c007c00,0x3c001c00,0x38007000,0xe000c000,0xc000,
/*quotedblbase*/
0x1c0c007e,0x3f007e3f,0x7e3f00,0x3e3f000e,0xf000e06,
0x1c0e00,0x383c00f0,0x7000c060,0x0,
/*quotedblright*/
0x3c3e007e,0x3f007e3f,0x7e3f00,0x1e1f000e,0x6001c0e,
0x381c00,0xf07800c0,0x60000000,0x0,
/*guillemotright*/
0x18601c70,0x1e780f3c,0xf3c07be,0xf3c1e78,0x3cf079e0,
0x71c0e380,0xc3000000,
/*ellipsis*/
0x781e03e0,0xf81f03e0,0xf81f03e0,0xf81e03e0,0x0,
/*perthousand*/
0xe000,0x1f07c0,0x7fff,0x80000078,0xf3000000,
0xf0c70000,0xf08600,0xf18e,0xe1,0x9c000000,0xe19c0000,
0xe33800,0x7630,0x3c,0x70000000,0xe3f03f,0xe790,
0x790001cf,0x18f18001,0x9f09f080,0x39e09e0,0x80071e19,0xe180071e,
0x19e1800e,0x1c11c100,0xc1c31c3,0x1c0e60,0xe6001807,0xc07c0038,
0x0,0x0,0x0,
/*questiondown*/
0x7000f8,0xf80070,0x0,0xc000c0,0x1c00180,
0x7800f00,0x1e007e00,0x7c00f8f0,0xf8f0f0f0,0xf0f07860,0x7ce01f80,0x1f80,
/*grave*/
0xe000f000,0xf8003c00,0xe000000,
/*acute*/
0x7001f00,0x3f007c00,0xf0000000,
/*circumflex*/
0xf801fc0,0x3fc079e0,0xf0600000,
/*tilde*/
0x3f307ff0,0xffe0c7c0,0xc7c0,
/*macron*/
0xfff0fff0,0xfff00000,
/*breve*/
0xc060e1e0,0xffc07f80,0x3f000000,
/*dotaccent*/
0x7000f800,0xf800f800,0x70000000,
/*dieresis*/
0x70e0f9f0,0xf9f0f9f0,0x70e00000,
/*ring*/
0x3c007e00,0xe700c300,0xe7007e00,0x3c000000,
/*cedilla*/
0x1c001800,0x3e003f00,0xf000f00,0xfe000000,
/*hungarumlaut*/
0x38e039e0,0x79e071c0,0x71c0e380,0xe3800000,
/*ogonek*/
0x30007000,0x6000e000,0xf000ff00,0xfe007c00,0x7c00,
/*caron*/
0xe1e0f3c0,0x7f807e00,0x3c000000,
/*emdash*/
0xffffffff,0xe0ffffff,0xffe0ffff,0xffffe000,0x0,
/*divide*/
0x1c00003,0xe00003e0,0x3e000,0x1c00000,0x0,
0xffff80,0xffff80ff,0xff800000,0x0,0x1c00003,0xe00003e0,
0x3e000,0x1c00000,0x0,
/*mu*/
0x7f1f00f,0xf1f00fe1,0xf003e3e0,0x7e3e007,0xc7e007c7,
0xc007c7c0,0xf8fc00f,0x9f800f9f,0x800f3fb0,0x1f7f601f,0xefe01f8f,
0xc0380000,0x30000070,0x7000,0xf00000,0xf00000e0,0x0,0x0,
/*onehalf*/
0x7c0001f,0xc0380380,0x70078060,0x780e007,0x1c00f01,
0x800f0380,0xe073e1e,0x67f1e0e,0xef3c1c87,0xff980700,0x380f0070,
0xe00601e,0xe01c01,0xc0300380,0x600380c2,0x701fe0e,0x3fc0000,0xfc0000,
/*onequarter*/
0x3c0000f,0xc0380380,0x30078070,0x780e007,0xe00f01,
0xc00f0380,0xe03801e,0x7071e0e,0xf1c0e1e,0xff9c3e00,0x187e0038,
0xdc0071bc,0x633c00,0xe63e01c7,0xfe0187fe,0x3807807,0x780000,0x780000,
/*threequarters*/
0xf80001f,0xc07033c0,0x6001c0e0,0x3c1c00f,0x1801f83,
0x80078700,0x7870003,0x8e0e039c,0x1ee71c3c,0xe6387cfc,0x30fc0071,
0xb800e378,0xc67801,0xcc7c038f,0xfc030ffc,0x700f00e,0xf00000,0xf00000,
/*onesuperior*/
0x1c00fc0,0x3800780,0x7800700,0xf000f00,0xe001e00,
0x1e001c00,0xff800000,
/*twosuperior*/
0xf801fc0,0x33c021c0,0x1c003c0,0x3800700,0xc0018c0,
0x3f807f80,0xff800000,
/*threesuperior*/
0x1f8033c0,0x1c001c0,0x3c00f00,0x1f800780,0x7800380,
0x380c700,0xe600fc00,0xfc00,
/*copyright*/
0xff8000,0x3ffe000,0xfe3f800,0x1f007c00,0x3c001e00,
0x387f8e00,0x78f3cf00,0xf1e1c700,0xf3e0c780,0xe3c00380,0xe3c00380,
0xe3c00380,0xe3e00380,0xf3e00780,0xf1e0c780,0x70fbcf00,0x387f8e00,
0x3c001e00,0x1f007c00,0xfe3f800,0x3ffe000,0xff8000,0x0,
/*registered*/
0x1ff8007,0xffe00fc3,0xf01e0078,0x3c003c79,0xff1e70e7,
0x8ef0e38f,0xf0e38fe0,0xe387e0e7,0x7e0fe07,0xe0ef07f0,0xe78ff0e7,
0x8f70e3ce,0x79f3de3c,0x3c1e00,0x780fc3f0,0x7ffe001,0xff800000,0x800000,
/*plusminus*/
0x1c00001,0xc00001c0,0x1c000,0x1c00001,0xc00001c0,
0xffff80,0xffff80ff,0xff8001c0,0x1c000,0x1c00001,0xc00001c0,
0x1c000,0x1c00000,0x0,0xffff80,0xffff80ff,0xff800000,0x800000,
/*brokenbar*/
0xe0e0e0e0,0xe0e0e0e0,0xe0000000,0xe0e0e0,0xe0e0e0e0,0xe0e000e0,
/*degree*/
0x3f007f80,0xf3c0e1c0,0xc0c0c0c0,0xe1c0f3c0,0x7f803f00,0x3f00,
/*logicalnot*/
0xffff80ff,0xff80ffff,0x80000380,0x38000,0x3800003,
0x80000380,0x38000,0x8000,
/*multiply*/
0x20020070,0x700f80f,0x807c1f00,0x3e3e001f,0x7c000ff8,
0x7f000,0x3e00007,0xf0000ff8,0x1f7c00,0x3e3e007c,0x1f00f80f,
0x80700700,0x20020000,0x0,
/*trademark*/
0xfffbf83f,0x80e738f8,0x3e00c718,0xfc7e00c7,0x18fc7e00,
0x700dc6e,0x700de,0xee000700,0xdeee0007,0xcfce00,0x700cfce,
0x700c7,0x8e000700,0xc78e000f,0x80e78f00,0x1fc3f33f,0x80000000,0x0,
/*AE*/
0x7ffff,0x800000ff,0x1f800001,0xff038000,0x1bf0380,
0x33e03,0x77e,0x300000e,0x7e180000,0x1c7c1800,0x18fc38,
0x30fc,0xf0000070,0xfff00000,0xe1f9f000,0xfff860,0x181f8,
0x60000383,0xf0600007,0x3f00600,0x603f006,0xe03f0,0xe001c03,
0xf01c0038,0x7e03c00,0x7807e1fc,0xfe1fff,0xf8000000,0x0,
/*ordfeminine*/
0xfc03dc0,0x79c07380,0xf380e780,0xef40ffc0,0x73800000,
0xff00,0xff000000,
/*Ntilde*/
0x1f8c00,0x1ffc00,0x3bf800,0x30f000,0x0,
0x0,0xff01fe0,0x7f80fc0,0x3f80300,0x1f80300,0x3fc0700,
0x37c0700,0x33e0600,0x73e0600,0x63f0e00,0x61f0c00,0xe1f0c00,
0xc0f9c00,0xc0f9800,0x1c07d800,0x1c07f800,0x1803f800,0x3803f000,
0x3801f000,0x3001f000,0x7001e000,0x7c00e000,0xfe00e000,0x0,
/*ntilde*/
0xfcc001,0xffc003ff,0x80031f00,0x0,0x1fcf,
0x3fdf80,0x1fbf800f,0xf7801fef,0x801fcf80,0x1f8f003f,0x1f003e1f,
0x3e3e00,0x7c3e007c,0x3f807c3d,0x80f83f00,0xf81e0000,0x0,
/*Yacute*/
0x70000,0xf00001f,0x3e00,0x780000,0xe0000000,
0x0,0xff8fe07f,0x7c03e03,0x803f0700,0x3f07001f,0xe001f9c,
0x1f9800,0xfb8000f,0xf0000fe0,0x7e000,0xfc0000f,0xc0000fc0,
0xf8000,0x1f80001f,0x80001f80,0x1f0000,0x7fc000ff,0xe0000000,0x0,
/*yacute*/
0x38000,0xf80001f,0x80003e00,0x780000,0x0,
0x1f8f00,0x1f8f0007,0xcf0007cf,0x7c700,0x3c30003,0xe60003e6,
0x3e600,0x1ec0001,0xfc0001f8,0x1f800,0xf00000,0xe00000e0,
0x1c000,0x18000f3,0xfe00,0xfc0000,0xf8000000,0x0,
/*Lslash*/
0xffe0003,0xf80001f0,0x3f000,0x3f00003,0xf00007e0,
0x7ec00,0x7fc000f,0xf8000fe0,0x1fc000,0x7f80007f,0x80005f80,
0x1f8000,0x1f80181f,0x80381f80,0x703f00f0,0x3f8ff0ff,0xffe00000,0xe00000,
/*Oslash*/
0x3000,0x700000,0x60007fe0,0x1f9f003,0xe1f807c3,
0xf80f837c,0x1f067c3f,0xe7c3e0c,0xfc7e1cfc,0x7e18fcfc,0x30fcfc71,
0xfcfc61f8,0xfce1f8fc,0xc3f0f983,0xf0fb83e0,0xfb07c07f,0xf807e1f,
0x3e7e00,0x1ff80018,0x3800,0x300000,0x60000000,0x0,
/*OE*/
0x3fffff,0xf8fe7f,0x1e07c0f,0x7c07c06,0xf80fc06,
0x1f80fc04,0x1f00f860,0x3f01f860,0x7e01f8e0,0x7e01f3c0,0x7e01ffc0,
0xfc03f3c0,0xfc03e1c0,0xfc03e180,0xfc07e180,0xf807e018,0xf807c018,
0xf80fc038,0x7c0fc070,0x3c0f80f0,0x1f1f87f0,0xfffffe0,0x0,
/*ordmasculine*/
0xfc01ce0,0x38e039e0,0x79e071e0,0x73c07380,0x3f000000,
0xff80,0xff800000,
/*minus*/
0xff80ff80,0xff80ff80,0xff80,
/*ae*/
0x3fff80f,0xbf9c1f1f,0x1c3e1e1c,0x3c3e3c7c,0x3e38783c,
0xf0f87fe0,0xf87f80f0,0xfc00f0f8,0xf1f830,0xfb7c70ff,0x7fe07c1f,
0x80000000,
/*dotlessi*/
0x3e7e7e3c,0x3c7c7c78,0x78f8f8f2,0xf6fcf800,
/*lslash*/
0x1fe01fe0,0x7c007c0,0x7c00f80,0xfa00fe0,0x1fe03f80,
0xfe00fe00,0xbe003e00,0x3c003c00,0x7c007c00,0x79807b00,0x7e003c00,0x3c00,
/*oslash*/
0xc000c,0x180078,0x3f80f3c,0x1e7e3e7e,0x3cfe7cfe,
0x79befbbe,0xfb3efe7c,0xfe7cfcf8,0xfcf079e0,0x3fc03e00,0x6000e000,
0xc0000000,
/*oe*/
0x3f1f80f,0x3fbc1e1f,0x1c3e1f3c,0x3c1e3c7c,0x3e38f83e,
0x70f83fe0,0xf87f80f8,0x7c00f078,0xf0f830,0x70fc7079,0xffe01f8f,
0xc0000000,
/*germandbls*/
0x7e000,0xe7000,0x1e3800,0x1c3800,0x3c7800,
0x3c7800,0x787800,0x78f000,0x7be000,0xfb8000,0xf1e000,
0xf0f000,0xf0f000,0x1f0f000,0x1f0f000,0x1e1f000,0x1e1f000,
0x3e1f000,0x3e1e000,0x3c3c000,0x3d3c000,0x3df0000,0x7800000,
0x7800000,0x7800000,0xe7000000,0xef000000,0xee000000,0x7c000000,
0x0,
};