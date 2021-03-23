int Rnbits[]={
/*space*/
0x0,
/*exclam*/
0xf8f8f8f8,0xf8f8f8f8,0x70707070,0x20202070,0xf8f80000,0xf800f8f8,
/*quotedbl*/
0x80e380e3,0x80e380e3,0x80e380e3,0x4180e3,0x410000,
/*numbersign*/
0x7000e07,0xe07000e,0xe0700,0x7000e07,0xc06000e,
0x80ff7f00,0xc80ff7f,0x180c001c,0x180c00,0xff00181c,0xffff00ff,
0x301800,0x38007038,0x70380070,0x703800,0x38007038,0x70,0x0,
/*dollar*/
0x30003,0xf07ac01f,0x10e23072,0x10e210e2,0xfa00f2,
0x3f007e,0xe007c01f,0xf802f003,0x78027802,0x38823882,0x70c278c2,
0xc07fe0f2,0x60006,0x6,
/*percent*/
0xc0810f,0xc0c71d,0x80ff38,0x4370,0x43f0,
0xc6e0,0xcee0,0xcce0,0x98c1,0x18c1,0xf830e3,
0xdc717e,0x8c6300,0x4e700,0x4cf00,0xc8e01,0xc8e03,
0x80e03,0x180c07,0x300c06,0x600e0c,0xc0070c,0x0,
/*ampersand*/
0xf801,0xdc03,0x8e07,0x607,0x607,
0x8e07,0x8e07,0xbc07,0xfef107,0x7cc007,0x70e01f,
0xe0f039,0xc0f070,0xc0f9f0,0x807de0,0x3fe0,0x1ff0,
0x11ff0,0xe33ff8,0xfef7fc,0xfce37f,0xf8803f,0x0,
/*quoteright*/
0x78f8f8f0,0x40603018,0x40603000,
/*parenleft*/
0x30001,0xc0006,0x380018,0x700030,0xf00070,
0xe000f0,0xe000e0,0xe000e0,0xe000e0,0xf000f0,0x700070,
0x380070,0x1c0018,0x6000c,0x1,
/*parenright*/
0xc00080,0x300060,0x1c0018,0xe000c,0xf000e,
0xf000f,0x70007,0x70007,0x70007,0xf000f,0xe000e,
0x1c000c,0x380018,0x600030,0x80,
/*asterisk*/
0x70007,0x38e738e7,0xe03ff8f7,0xe03f0007,0x78e778f6,
0x738e7,0x7,
/*plus*/
0x1008001,0x80010080,0x800100,0x1008001,0x80010080,
0xffff00,0x100ffff,0x80010080,0x800100,0x1008001,0x80010080,
0x800100,0x0,
/*comma*/
0xf8f8f8f0,0x60303018,0x60300040,
/*hyphen*/
0x80ff80ff,0x80ff0000,
/*period*/
0xf0f0f0f0,0xf0f0f000,
/*slash*/
0xe000e000,0xc001e000,0xc001c001,0x80038003,0x78003,
0x70007,0xe000e,0x1c000e,0x1c001c,0x380038,0x700038,
0x700070,0xe000e0,0xe0,
/*zero*/
0x781ee007,0x1c383c3c,0x1e781e78,0xff81ff8,0xff00ff0,
0xff00ff0,0xff00ff0,0x1ff80ff8,0x1e781e78,0x3c3c1c38,0xe007781e,0xe0070000,
/*one*/
0x1e0006,0xce007e,0xe000e,0xe000e,0xe000e,
0xe000e,0xe000e,0xe000e,0xe000e,0xe000e,0xc07f000e,0xc07f0000,
/*two*/
0xe03fc00f,0xf871f07f,0x78c078c0,0x380038c0,0x78003800,
0xe0007000,0xc001e000,0x78003,0x21c000e,0xfc7f0e38,0xfcfffcff,0xfcff0000,
/*three*/
0xf03fc00f,0x7840f879,0x38007880,0x70003800,0xf003e000,
0xf801f80f,0x3c003c00,0x1c001c00,0x1c001c00,0x30e03800,0x807fe0f8,0x807f0000,
/*four*/
0x78003800,0xf8007800,0xb803f801,0x38063807,0x381c380c,
0x38303838,0x3fe03860,0xffffffff,0x38003800,0x38003800,0x38003800,0x38000000,
/*five*/
0xf80ffc0f,0x18f81f,0x3c0038,0xe07fc07f,0xf803f07f,
0x3c00fc00,0x3c003c00,0x1c001c00,0x38001c00,0x70f03800,0x807fe0f9,0x807f0000,
/*six*/
0xf0037c00,0xf8007,0x3c001e,0xe07f0078,0xfcfcf8ff,
0x1ee03cf0,0xee01ee0,0xee00ee0,0x1e700ef0,0x1c381c78,0xe00f781e,0xe00f0000,
/*seven*/
0xfe7ffe7f,0x1cc00e70,0x1c001c80,0x38003800,0x70003800,
0x70007000,0xe000e000,0xc001e000,0xc001c001,0x80038003,0x8003,
/*eight*/
0xe079801f,0x70e0e070,0x70e070e0,0xe0f8f0f0,0x3fc07f,
0xe03fc01f,0xf8f0f073,0x78e078e0,0x38f038e0,0x707078f0,0xc01fe038,0xc01f0000,
/*nine*/
0xf83ce00f,0x3c703c70,0x1ee03ef0,0x1ee01ee0,0x1ef01ee0,
0x3e701ef0,0xfc3f7e7c,0x7800bc1f,0xe000f000,0x8003c001,0x7c001f,0x7c0000,
/*colon*/
0xf0f0f0f0,0x0,0x0,0xf0f00000,0xf000f0f0,
/*semicolon*/
0xf0f0f0f0,0x0,0x0,0xf8f00000,0x3018f8f8,
0x406030,
/*less*/
0x800000,0xf008003,0x803f0080,0x700fc00,0xc01f00f0,
0x7f00,0xf00000fc,0xfc0000,0x7f00,0x700c01f,0xfc0000f0,
0x803f0000,0x800f00,0x8003,0x80,
/*equal*/
0xff80ffff,0x80ff,0x0,0x0,0xffff0000,
0x80ffff80,0x80000000,
/*greater*/
0xf80000e0,0xfe0000,0x803f00,0x100e007,0x7f0000fc,
0x801f0000,0x800700,0x7f00801f,0xfc0100,0x3f00e007,0xfe0080,
0xf800,0xe0,0x0,
/*question*/
0xc073803f,0xe0c0e0c1,0xe0e0e0e0,0xe001e0e0,0xc001c001,
0x38003,0x30003,0x20002,0x0,0x1f000e,0xe001f,0xe0000,
/*at*/
0xf01f00,0xfeff00,0x1ffc01,0x8003c007,0xc001000f,
0xc000001e,0x60c0073c,0x60fc0f78,0x707c3e78,0x307c3cf0,0x303878f0,
0x3038f0f0,0x3078f0e0,0x7078f0e0,0x7070e0e0,0x6070e0e0,0xc0f0e0f0,
0xc0e1e1f0,0x80f3f370,0x7f7f78,0x3e3e38,0x3c,0x1e,
0x6800f,0x3ef003,0xf8ff00,0xe03f00,0x0,
/*A*/
0x3000,0x78000070,0xf80000,0x100fc00,0xbe0100fc,
0xbe0300,0x3001e03,0xf06001f,0x800f0600,0xf80070c,0xff0fc0ff,
0xe0030cc0,0x18e00118,0x138f001,0xf80030f0,0xfcfc0178,0xfe03,0xfe00,
/*B*/
0x3f00feff,0x1f1e00ff,0xc0071e80,0x1ec0031e,0x31ec003,
0xc0031ec0,0x1e80071e,0xfe1f001f,0x80ff1f00,0x1ec01f1e,0x31ee007,
0xe0011ee0,0x1ee0011e,0x31ee001,0xc0071ee0,0xff801f3f,0xfe,0x0,
/*C*/
0xf30ff03,0xc31ff0ff,0x70003ef0,0x7830003c,0x783000,
0xf810,0xf00000f8,0xf00000,0xf000,0xf00000f0,0xf80000,
0x7800,0x3c000078,0x3e1000,0xe0c31f70,0x3c0ff0f,0xff,0x0,
/*D*/
0x7f00feff,0x1f1ec0ff,0xf8011ee0,0x1e78001e,0x1e7c00,
0x3e001e3e,0x1e3e001e,0x1e1e00,0x1e001e1e,0x1e1e001e,0x1e3e00,
0x3e001e3e,0x1e7c001e,0x11e7800,0xe00f1ef8,0xffc0ff7f,0xff,0x0,
/*E*/
0x7fc0ffff,0x11fc0ff,0xc0001ec0,0x1e40001e,0x1e0000,
0x11e00,0x1e00031e,0xff1f0007,0xff1f00,0x1e00071e,0x11e0003,
0x1e00,0x1e30001e,0x1e3000,0xe0011e70,0xffe0ff7f,0xe0ff,0xe000,
/*F*/
0x7fc0ffff,0x11ec0ff,0xc0001ec0,0x1ec0001e,0x1e0000,
0x11e00,0x1e00031e,0xff1f0007,0xff1f00,0x1e00071e,0x11e0003,
0x1e00,0x1e00001e,0x1e0000,0x1e00,0xff00003f,0xc0,0x0,
/*G*/
0xf30ff01,0x831ff0ff,0xf0003ef0,0x7870007c,0xf83000,
0xf830,0xf00000f8,0x7f00000,0xfc03f0fe,0xf8f000f0,0xf8f000,
0xf000f8f0,0x7cf00078,0x3ef000,0xf0c31ff0,0x1e0ff0f,0xff,0x0,
/*H*/
0x7fffc3ff,0x1efe81,0x78001e78,0x1e78001e,0x1e7800,
0x78001e78,0x1e78001e,0xff1f7800,0xf8ff1ff8,0x1e78001e,0x1e7800,
0x78001e78,0x1e78001e,0x1e7800,0x78001e78,0xfffe817f,0xffc3,0xff00,
/*I*/
0x3fc0ff,0x1e001e,0x1e001e,0x1e001e,0x1e001e,
0x1e001e,0x1e001e,0x1e001e,0x1e001e,0x1e001e,0xc0ff003f,0xc0ff0000,
/*J*/
0xe007f81f,0xc003c003,0xc003c003,0xc003c003,0xc003c003,
0xc003c003,0xc003c003,0xc003c003,0xc003c003,0xc0f7c0f3,0x7e80ff,0x7e0000,
/*K*/
0x3ffcc7ff,0x11ef001,0x80031ec0,0x1e00071e,0x1c1e000e,
0x381e00,0x1f00701e,0xf01f00e0,0xf81f00,0x1e00fc1e,0x3f1e007e,
0x801f1e00,0x1e800f1e,0x31ec007,0xf0031ee0,0xfffc013f,0xffc7,0xff00,
/*L*/
0x7f00c0ff,0x1e0080,0x1e00,0x1e00001e,0x1e0000,
0x1e00,0x1e00001e,0x1e0000,0x1e00,0x1e00001e,0x1e0000,
0x1e00,0x1e30001e,0x1e3000,0xe0031f70,0xffe0ff3f,0xe0ff,0xe000,
/*M*/
0xf80300fe,0xe007003f,0xc007001f,0xc00f801f,0xc00f801f,
0xc01bc01f,0xc01bc01b,0xc033e01b,0xc033e019,0xc073f019,0xc063f019,
0xc0e3f818,0xc0c3f818,0xc0c37818,0xc0837d18,0xc0833f18,0xc0033f18,
0xc0031f18,0xc0031e18,0xc0030e18,0xe0070e3c,0xf81f04ff,0x0,
/*N*/
0x3fff00fe,0x801f3c00,0x18801f18,0x1b18c01f,0xf01918e0,
0x18f81918,0x1818fc18,0x3e18187c,0x181f1818,0x18981f18,0x718d80f,
0xf80318d8,0x18f80118,0x18f801,0x780018f8,0xff38003c,0x1800,0x1800,
/*O*/
0xf00ff03,0x11ec0cf,0xf0003ce0,0x78f8003c,0x787800,
0x7c00f87c,0xf07c00f0,0xf03c00,0x3c00f03c,0xf03c00f0,0xf87c00,
0x7c00787c,0x3c780078,0x3cf800,0xe0011ef0,0x3c08f0f,0xff,0x0,
/*P*/
0x7f00fcff,0x3f1e00ff,0x80071e80,0x1ec0071e,0x31ec003,
0xc0031ec0,0x1ec0071e,0x3f1e8007,0xff1f80,0x1e00fc1f,0x1e0000,
0x1e00,0x1e00001e,0x1e0000,0x1e00,0xff00807f,0xc0,0x0,
/*Q*/
0x700ff03,0x11ec0cf,0xf0003ce0,0x78f0003c,0x787800,
0x7c00f878,0xf07c00f0,0xf03c00,0x3c00f03c,0xf03c00f0,0xf83c00,
0x7c00f87c,0x78780078,0x3c7800,0xf0003cf0,0x7e0011e,0xfe0180cf,
0xfe0000,0x7f00,0x700801f,0xfc0100e0,0xfc000000,
/*R*/
0x7f00fcff,0x1f1e00ff,0xc0071e80,0x1ec0031e,0x31ec003,
0xc0031ec0,0x1ec0071e,0xff1f803f,0xf81f00,0x1e00781e,0x3e1e007c,
0x1f1e00,0x1e800f1e,0x71ec007,0xe0031ec0,0xfff8817f,0xfcc0,0xfc00,
/*S*/
0x1f00ec0f,0x7e3c00fe,0xe7800,0x70000e70,0x6780006,
0x7e00,0x3f00803f,0xf00f00c0,0xfc0700,0xfe01,0x1f00007f,
0xfc000,0xe0000fc0,0x1ef0000f,0x3efc00,0x6f00f87f,0xf0,0x0,
/*T*/
0xfff0ffff,0xf0f0f0ff,0x30f0c070,0x8030f0c0,0xf00010f0,
0xf00000,0xf000,0xf00000f0,0xf00000,0xf000,0xf00000f0,
0xf00000,0xf000,0xf00000f0,0xf00000,0x700f801,0xfe,0x0,
/*U*/
0x3fffc0ff,0x1e3c00,0x18001e18,0x1e18001e,0x1e1800,
0x18001e18,0x1e18001e,0x1e1800,0x18001e18,0x1e18001e,0x1e1800,
0x18001e18,0x1f38001f,0xf3800,0xe0e00730,0xc0ff03,0x80ff,0x8000,
/*V*/
0x7efc80ff,0x3e7800,0x70003e30,0x1f60001e,0xf6000,
0xc0800fc0,0x7c08107,0xc10380c1,0xe30380,0x100e301,0xf60100f6,
0xfe0000,0xfc00,0x7800007c,0x380000,0x3800,0x10,0x0,
/*W*/
0xf8c13fff,0xf0801f7e,0x60000f3c,0xe080073e,0xc080071e,
0xc080071e,0xc0c0031f,0x80c1070f,0x80c1070f,0xe38f07,0xe38d07,
0xe38d07,0xf6d803,0xf6d803,0xf6f803,0x7cf001,0x7cf001,
0x7cf001,0x38e000,0x38e000,0x38e000,0x104000,0x0,
/*X*/
0x3ffec3ff,0x1ff800,0xe0000f60,0x7c0810f,0xc7038083,
0xee0300,0xfc01,0x780000f8,0x7c0000,0x7c00,0x9f0100fe,
0x808f0300,0xe800707,0x31cc007,0xf00138e0,0xfef8037c,0xfe0f,0xfe00,
/*Y*/
0x7fffc0ff,0x3f7f80,0x38801f1c,0x770c00f,0xe00360c0,
0xc0f103c0,0x80fb01,0x7e0000fb,0x7e0000,0x3c00,0x3c00003c,
0x3c0000,0x3c00,0x3c00003c,0x3c0000,0x1007e00,0x80ff,0x8000,
/*Z*/
0x7ff0ff7f,0x37ce0ff,0xc00760c0,0x60800f60,0x1f00001f,
0x3e0000,0x7c00,0xf8000078,0xf00100,0x300e003,0xc00700c0,
0x800f00,0x1f10001f,0x3e3000,0xf0017c30,0xfff0ffff,0xf0ff,0xf000,
/*bracketleft*/
0xf000ff,0xe000e0,0xe000e0,0xe000e0,0xe000e0,
0xe000e0,0xe000e0,0xe000e0,0xe000e0,0xe000e0,0xe000e0,
0xe000e0,0xff00f0,0xff0000,
/*backslash*/
0x700000f0,0x380000,0x3800,0x1c00001c,0xe0000,
0xf00,0x7000007,0x80030080,0xc00100,0xc001,0xe00000e0,
0x700000,0x7800,0x3c000038,0x1c0000,0xe00,0xe,0x0,
/*bracketright*/
0xf00ff,0x70007,0x70007,0x70007,0x70007,
0x70007,0x70007,0x70007,0x70007,0x70007,0x70007,
0x70007,0xff000f,0xff0000,
/*asciicircum*/
0xc0078003,0xe00fc007,0xf01ee00e,0x783c701c,0x38383838,
0x1c701c70,0xee00ee0,0xee00000,
/*underscore*/
0xff80ffff,0x80ff,0x8000,
/*quoteleft*/
0x60701808,0xf8f8f8c0,0xf8f80078,
/*a*/
0xc039801f,0xe070e071,0xe001e070,0xe03ce00f,0xe0e0e070,
0xe0f0e0e0,0xfcffe4f3,0x787c,
/*b*/
0xf80078,0x380038,0x380038,0xf8390038,0x3e3efc3f,
0xf380f3c,0x7380f38,0x7380738,0xf380738,0xe3c0e38,0xf00f3c3e,0xf00f0000,
/*c*/
0xf03ce00f,0x78707870,0xe038f0,0xe000e0,0x8f000f0,
0x307c18f0,0xe03ff07f,0x800f,
/*d*/
0xf8007800,0x38003800,0x38003800,0xf81f3800,0x7870f83c,
0x38f038f0,0x38e038e0,0x38e038e0,0x38f038f0,0xfe7c78f0,0x201fbc3f,0x201f0000,
/*e*/
0xf038e00f,0x7c707870,0xfcff3ce0,0xe000e0,0x4f000f0,
0x1c780cf0,0xf03f387e,0xe00f,
/*f*/
0x780ef003,0x1c380c,0x1c001c,0xc0ff001c,0x1cc0ff,
0x1c001c,0x1c001c,0x1c001c,0x1c001c,0x1c001c,0x80ff003e,0x80ff0000,
/*g*/
0xfe0ef007,0x78387e1c,0x38383838,0x703c383c,0xc00f601e,
0x300018,0xf83f003c,0xfe37fe1f,0x2e00270,0x1cfc06e0,0xe01ff87f,0xe01f0000,
/*h*/
0xfc001c,0x3c00fc,0x3c003c,0xf83d003c,0x3c3ffc3f,
0x1c381c3c,0x1c381c38,0x1c381c38,0x1c381c38,0x1c381c38,0x7ffe3e7c,0x7ffe0000,
/*i*/
0x3c003c,0x3c,0x0,0x1c0000,0x1c007c,
0x1c001c,0x1c001c,0x1c001c,0x1c001c,0x1c001c,0x80ff001c,0x80ff0000,
/*j*/
0x80038003,0x8003,0x0,0x80030000,0x8007800f,
0x80038003,0x80038003,0x80038003,0x80038003,0x80038003,0x80038003,
0x80038003,0x80038003,0xf700e3,0x7e,
/*k*/
0x7e00003e,0x1e0000,0x1e00,0x1e00001e,0x1c0000,
0x803f1c00,0x1c001e1c,0xe01c0038,0xc01d00,0x1f00801f,0xc01f00c0,
0xe01f00,0x1e00f01e,0x7c1e00f8,0x3e1e00,0xff001f3e,0xc0bf,0xc000,
/*l*/
0x3838f838,0x38383838,0x38383838,0x38383838,0x38383838,0x3800fe38,
/*m*/
0xf8f83d,0xfcfbff,0x1e3f7e,0xe1c38,0xe1c38,
0xe1c38,0xe1c38,0xe1c38,0xe1c38,0xe1c38,0xe1c38,
0xe1c38,0xe1c38,0x1f3e7c,0x803f7ffe,0x0,
/*n*/
0xfcfff83d,0x1c383c7e,0x1c381c38,0x1c381c38,0x1c381c38,
0x1c381c38,0x3e7c1c38,0x7ffe,
/*o*/
0xf03cc00f,0x38707870,0x3ce03cf0,0x1ce01ce0,0x1cf01ce0,
0x38703cf0,0xf03c3878,0xc00f,
/*p*/
0xff00fc1e,0x1f3f00fe,0x800f1e00,0x1c80071c,0x31c8007,
0x80031c80,0x1c80031c,0x71c8003,0x71c80,0x1f000f1e,0xf81f009e,
0x1e00,0x1e00001e,0x1e0000,0x1e00,0xff00003e,0x80,0x0,
/*q*/
0x3c00d80f,0x787000f8,0x387000,0xe00038f0,0x38e00038,
0x38e000,0xf00038e0,0x38f00038,0x78f000,0x3f00f87c,0x781f00f8,
0x780000,0x3800,0x38000038,0x380000,0x1007c00,0xff,0x0,
/*r*/
0xf0fdf03c,0x1cf03f,0x1c001c,0x1c001c,0x1c001c,
0x1c001c,0x3e001c,0x80ff,
/*s*/
0x8073803f,0x80c180c1,0xf880e0,0x7f00fe,0xc087801f,
0xc0c1c083,0x80f3c0c1,0xff,
/*t*/
0x180008,0x380018,0xff007f,0x380038,0x380038,
0x380038,0x380038,0x380038,0x803d0038,0x1e003f,0x1e0000,
/*u*/
0x1c007efc,0xe1c001e,0xe1c00,0x1c000e1c,0xe1c000e,
0xe1c00,0x1c000e1c,0xe1c000e,0xe1c00,0x1f003f1e,0xce0f80ef,
0x0,
/*v*/
0x3c800ffe,0x63c0006,0xc1e00,0xf000c1e,0x180f0018,
0xb80700,0x700b007,0xe00300f0,0xe00300,0x100c001,0x800000c0,
0x0,
/*w*/
0x780f7ffe,0x1e38061c,0xc1e3c0e,0x1e0c1e1c,0x1f0e181f,
0x18370f18,0x7b03707,0xe303b0b3,0xe0e303e0,0x1e0e101,0x8000c0c1,
0x80,
/*x*/
0x703cfcfe,0xc01ec01e,0x8007c00f,0x80078007,0xc00fc007,
0xe018e00d,0x7830f038,0xfef8,
/*y*/
0x63c1fff,0xc1e0e3e,0x180f0c1e,0x180f180f,0xb007b007,
0xe003e007,0xc001e003,0x8001c000,0x80038001,0x7f007b,0x3c007e,0x3c0000,
/*z*/
0xf060f87f,0xe041f041,0xc007c003,0x800f8007,0x1e000f,
0x83c083e,0x38f81878,0xf8ff,
/*braceleft*/
0x3c001e,0x380038,0x380038,0x380038,0x380038,
0x380038,0xe00070,0x380070,0x380038,0x380038,0x380038,
0x380038,0x3c0038,0x1e,
/*bar*/
0xc0c0c0c0,0xc0c0c0c0,0xc0c0c0c0,0xc0c0c0c0,0xc0c0c0c0,0xc000c0c0,
/*braceright*/
0x7800f0,0x380038,0x380038,0x380038,0x380038,
0x380038,0xe001c,0x38001c,0x380038,0x380038,0x380038,
0x380038,0x780038,0xf0,
/*asciitilde*/
0x7fc0801f,0xff71c0f3,0x7fe080,0xc0,0x0,
/*exclamdown*/
0xf8f8f8f8,0x20200000,0x70707020,0xf8f87070,0xf8f8f8f8,0xf800f8f8,
/*cent*/
0x30003000,0x60006000,0xf01ce00f,0xf870f838,0x80e1f8f0,
0x80e180e1,0xf300f3,0x187e08fb,0xf03f383e,0xc01fe01f,0x180018,
0x300030,0x300000,
/*sterling*/
0x3c07f003,0x3c1c3c0e,0x1c1c1c,0x1c001c,0xe0ff001e,
0xe0ffe0ff,0x1e001e,0xe000e,0x23c000e,0xfcdf8eff,0xf0f3f8df,0xf0f30000,
/*fraction*/
0x800100,0x7008003,0x60000,0xc00,0x1800001c,
0x300000,0x7000,0xc0000060,0xc00100,0x3008001,0x70000,
0xe00,0x1800000c,0x380000,0x3000,0xe0000060,0x0,0x0,
/*yen*/
0x7ee00fff,0x13cc007,0x31e80,0xf00071f,0x8e0f0006,
0x8c0700,0x300d803,0xfc2f00f8,0x80ff3f80,0x80ff3f,0xff3f00e0,
0x80ff3f80,0xe000,0xe00000e0,0xe00000,0x700f803,0xfc,0x0,
/*florin*/
0x77003e00,0xe7006700,0xe001e000,0xc001c001,0xc003fc1f,
0xc003c003,0x8003c003,0x80078007,0x80078007,0x80078007,0x78007,
0x70007,0xe600e6,0x7800ec,0x780000,
/*section*/
0xc031801f,0xe061e061,0x78e071,0x1f003e,0xe077c03f,
0xf8c0f0e1,0x38e078c0,0x187c18f0,0xc01f703e,0xc007800f,0xe070e001,
0x6070e070,0xc0386070,0x801f,
/*currency*/
0xff00f147,0xff7f80ff,0x3f7e00,0xf0000f78,0x7f08007,
0x8003e080,0xe08003e0,0x7f08003,0x8007f080,0x7e000f78,0xff7f003f,
0x80ffff00,0xf147,0x0,
/*quotesingle*/
0xe0e0e0e0,0x40e0e0e0,0x40e0e000,
/*quotedblleft*/
0x18180808,0x60607070,0xf8f8c0c0,0xf8f8f8f8,0x7878,
/*guillemotleft*/
0x18060802,0x6018300c,0xc071e038,0xc07180e3,0x6018e038,
0x1806300c,0x802,
/*guilsinglleft*/
0x60002,0x18000c,0x700038,0x7000e0,0x180038,
0x6000c,0x2,
/*guilsinglright*/
0xc00080,0x300060,0x1c0038,0x1c000e,0x300038,
0xc00060,0x80,
/*fi*/
0xe00f803,0x1c1c003c,0x1c1c00,0x38000038,0x1cb80000,
0xfcff00,0x38003c38,0x1c38001c,0x1c3800,0x38001c38,0x1c38001c,
0x1c3800,0x38001c38,0x1c38001c,0x1c3800,0xfe001c38,0x7f,0x0,
/*fl*/
0xc00ec07,0x7c1c00fc,0x3c3800,0x38001c38,0x1c38001c,
0xfcff00,0x38001c38,0x1c38001c,0x1c3800,0x38001c38,0x1c38001c,
0x1c3800,0x38001c38,0x1c38001c,0x1c3800,0xfe001c38,0x7f,0x0,
/*endash*/
0xff80ffff,0x80ff,0x8000,
/*dagger*/
0x70007,0x70007,0x20007,0xf8fff8fa,0x2f8fa,
0x70002,0x70007,0x70007,0x70007,0x70007,0x20002,
0x20002,0x20002,0x2,
/*daggerdbl*/
0x70007,0x70007,0x20007,0xf8fff8fa,0x2f8fa,
0x70003,0x70007,0x70007,0x20007,0xf8fff8fa,0x2f8fa,
0x70007,0x70007,0x7,
/*periodcentered*/
0xf0f0f0f0,0xf0f0f000,
/*paragraph*/
0xf03ff01f,0x607e607e,0x60fe60fe,0x60fe60fe,0x60fe60fe,
0x607e60fe,0x601e603e,0x60066006,0x60066006,0x60066006,0x60066006,
0x60066006,0x60066006,0x60066006,0x6006,
/*bullet*/
0x7f003e,0x80ff80ff,0x80ff80ff,0x3e007f,0x3e0000,
/*quotesinglbase*/
0xf800f0,0x7800f8,0x300018,0xc00060,0xc00000,
/*quotedblbase*/
0xf8f8f0f0,0x7878f8f8,0x30301818,0x40406060,0x40400000,
/*quotedblright*/
0xf8f8f0f0,0x7878f8f8,0x30301818,0x40406060,0x40400000,
/*guillemotright*/
0xc30082,0xc0308061,0x701ce038,0x701c380e,0xc030e038,
0xc38061,0x82,
/*ellipsis*/
0xc0031ef0,0xc0031ef0,0xc0031ef0,0xc0031ef0,0x0,
/*perthousand*/
0x80031f,0x80cf3b00,0xff700000,0x70000000,0x87,
0x86f0,0x8ce100,0x9ce10000,0xe1000000,0x98,0x38e3,
0x306600,0x617c0000,0x3ef0,0x73b863,0xe108c700,0x9ce0100,
0x9e0100c1,0x300c10b,0x831b1c,0x831b1c03,0x131c0600,0x180e0082,
0xc000633,0xc6318,0xd8c31e1c,0x810f1800,0xf0,0x0,
/*questiondown*/
0xf000f,0xf000f,0x20000,0x60002,0xc0006,
0x38001c,0x700078,0xe0e000f0,0xe0e0e0e0,0x60f060f0,0x803fc079,0x803f0000,
/*grave*/
0xf000e0,0x3c0078,0x7000e,0x70000,
/*acute*/
0xf0007,0x3c001e,0xe00070,0xe00000,
/*circumflex*/
0x1f000e,0xc071803f,0x60c0c060,0x60c00000,
/*tilde*/
0xe0ff607e,0xc0cf,
/*macron*/
0xe0ffe0ff,0xe0ff0000,
/*breve*/
0x80c180c1,0x7f80e7,0x3e,
/*dotaccent*/
0xf0f0f0f0,0xf0f0f000,
/*dieresis*/
0xe0f1e0f1,0xe0f1e0f1,0xe0f10000,
/*ring*/
0x7e003c,0xc300e7,0x7e00e7,0x3c,
/*cedilla*/
0x380018,0x3f003e,0xff0007,0xfe,
/*hungarumlaut*/
0x780f3807,0xe03df01e,0xe78073,0xe70000,
/*ogonek*/
0x78ecc0e0,0x78ecc000,
/*caron*/
0xc071e0e0,0x803f803b,0xe001f,0xe0000,
/*emdash*/
0xffffffff,0xffffffc0,0xc0ff,0x0,
/*AE*/
0xe0ffff01,0xe0ff7f00,0xe0003f00,0x60006f00,0x20006f00,
0x8000cf00,0x8000cf00,0x8001cf01,0x80038f01,0x80ff8f03,0x80ff0f03,
0x80030f03,0x8001ff07,0x8000ff07,0x80000f0c,0xf0c,0x10000f18,
0x30000f18,0x70000f38,0xe0810f30,0xe0ff3f78,0xe0ff7ffc,0x0,
/*ordfeminine*/
0xce007c,0x1e00c6,0xe6007e,0xee00c6,0xff,
0xff0000,0xff0000,
/*Lslash*/
0x7f00c0ff,0x1e0080,0x1e00,0x1e00001e,0x301e0000,
0xf01e00,0x1f00e01f,0x1e0080,0x7e00,0xde0000fe,0x1e0000,
0x1e00,0x1e30001e,0x1e3000,0xe0031f70,0xffe0ff3f,0xe0ff,0xe000,
/*Oslash*/
0x180000,0xfe033800,0xe0cf0770,0x1ec0030f,0x13ce001,
0xf80378f0,0xf8780778,0xcf07c0e,0x3c18f07c,0xf03c38f0,0x60f03c70,
0x3cc0f03c,0x797cc0f9,0x7b7880,0xf0003f78,0xfe0011e,0xcf1fc003,
0xff3b80,0x60000070,0x0,0x0,
/*OE*/
0xe0ffff03,0xe0ffff0f,0x60c01f1f,0x6080073c,0x2080077c,
0x800778,0x8007f8,0x408007f8,0xc08007f8,0xc08107f0,0xc0ff07f0,
0xc0ff07f0,0xc08107f0,0xc08007f0,0x408007f8,0x8007f8,0x18800778,
0x18800778,0x3880073c,0xf0c00f1e,0xf0ff9f0f,0xf0ffff03,0x0,
/*ordmasculine*/
0x67003e,0x80c180e3,0x80c180c1,0x6380e3,0x3e,
0x80ff0000,0x80ff0000,
/*ae*/
0x39c09f1f,0xf070e0f9,0x70e070f0,0x170e070,0xe00ff0ff,
0xe03f00,0xe100e071,0xf0e008f0,0x307cf018,0x7fe0fff9,0xf3ec03f,
0x80,
/*dotlessi*/
0x7c001c,0x1c001c,0x1c001c,0x1c001c,0x1c001c,
0x1c001c,0x1c001c,0x80ff,
/*lslash*/
0x3878f838,0x3e3a3838,0xf878383c,0x387878f8,0x38383838,0x3800fe38,
/*oslash*/
0xc000c00,0x18001800,0xf03cf80f,0x7c707870,0xdee1def0,
0x8ee39ee1,0xef60ee3,0x1c7c1ef6,0x781e1c3c,0x30e03f,0x600060,0x600000,
/*oe*/
0x38f0c71f,0x7c7078ee,0x3c78703c,0xe01c38f0,0x38e0fc3f,
0x38e000,0xf00038e0,0x3cf0003c,0xc7e7004,0x3c1c7f78,0xc71ff8ef,
0xf0,
/*germandbls*/
0x781ef007,0x1c383c3c,0x1c381c38,0x38381c38,0xe0397838,
0x1c38f838,0x1e381e38,0xe380e38,0xe380e38,0x9c3b9e3b,0xf0f99c7b,0xf0f90000,
};
