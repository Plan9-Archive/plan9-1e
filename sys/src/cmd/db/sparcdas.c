#include "defs.h"
#include "fns.h"

struct opcode {
	char	*mnemonic;
	void	(*f)(struct instr*, char*);
	int	flag;
};

typedef struct instr Instr;

struct instr {
	uchar	op;		/* bits 31-30 */
	uchar	rd;		/* bits 29-25 */
	uchar	op2;		/* bits 24-22 */
	uchar	a;		/* bit  29    */
	uchar	cond;		/* bits 28-25 */
	uchar	op3;		/* bits 24-19 */
	uchar	rs1;		/* bits 18-14 */
	uchar	i;		/* bit  13    */
	uchar	asi;		/* bits 12-05 */
	uchar	rs2;		/* bits 04-00 */
	short	simm13;		/* bits 12-00, signed */
	ushort	opf;		/* bits 13-05 */
	ulong	immdisp22;	/* bits 21-00 */
	ulong	simmdisp22;	/* bits 21-00, signed */
	ulong	disp30;		/* bits 30-00 */
	ulong	imm32;		/* SETHI+ADD constant */
	int	target;		/* SETHI+ADD dest reg */
	WORD	w0;
	WORD	w1;
};

static void	mkinstr(Instr*);
static void	bra1(Instr*, char*, char*[]);
static void	bra(Instr*, char*);
static void	fbra(Instr*, char*);
static void	cbra(Instr*, char*);
static void	unimp(Instr*, char*);
static void	fpop(Instr*, char*);
static void	shift(Instr*, char*);
static void	sethi(Instr*, char*);
static void	load(Instr*, char*);
static void	loada(Instr*, char*);
static void	store(Instr*, char*);
static void	storea(Instr*, char*);
static void	add(Instr*, char*);
static void	cmp(Instr*, char*);
static void	wr(Instr*, char*);
static void	jmpl(Instr*, char*);
static void	rd(Instr*, char*);
static void	loadf(Instr*, char*);
static void	storef(Instr*, char*);
static void	loadc(Instr*, char*);
static void	loadcsr(Instr*, char*);
static void	trap(Instr*, char*);

static struct opcode sparcop0[8] = {
	[0]	"UNIMP",	unimp,	0,	/* page 137 */
	[2]	"B",		bra,	0,	/* page 119 */
	[4]	"SETHI",	sethi,	0,	/* page 104 */
	[6]	"FB",		fbra,	0,	/* page 121 */
	[7]	"CB",		cbra,	0,	/* page 123 */
};

static struct opcode sparcop2[64] = {
	[0x00]	"ADD",		add,	0,	/* page 108 */
	[0x10]	"ADDCC",	add,	0,
	[0x08]	"ADDX",		add,	0,
	[0x18]	"ADDXCC",	add,	0,

	[0x20]	"TADD",		add,	0,	/* page 109 */
	[0x22]	"TADDCCTV",	add,	0,

	[0x04]	"SUB",		add,	0,	/* page 110 */
	[0x14]	"SUBCC",	cmp,	0,
	[0x0C]	"SUBX",		add,	0,
	[0x1C]	"SUBXCC",	add,	0,

	[0x21]	"TSUB",		add,	0,	/* page 111 */
	[0x23]	"TSUBCCTV",	add,	0,

	[0x24]	"MULSCC",	add,	0,	/* page 112 */

	[0x0A]	"UMUL",		add,	0,	/* page 113 */
	[0x0B]	"SMUL",		add,	0,
	[0x1A]	"UMULCC",	add,	0,
	[0x1B]	"SMULCC",	add,	0,

	[0x0E]	"UDIV",		add,	0,	/* page 115 */
	[0x0F]	"SDIV",		add,	0,
	[0x1E]	"UDIVCC",	add,	0,
	[0x1F]	"SDIVCC",	add,	0,

	[0x01]	"AND",		add,	0,	/* page 106 */
	[0x11]	"ANDCC",	add,	0,
	[0x05]	"ANDN",		add,	0,
	[0x15]	"ANDNCC",	add,	0,
	[0x02]	"OR",		add,	0,
	[0x12]	"ORCC",		add,	0,
	[0x06]	"ORN",		add,	0,
	[0x16]	"ORNCC",	add,	0,
	[0x03]	"XOR",		add,	0,
	[0x13]	"XORCC",	add,	0,
	[0x07]	"XORN",		add,	0,
	[0x17]	"XORNCC",	add,	0,

	[0x25]	"SLL",		shift,	0,	/* page 107 */
	[0x26]	"SRL",		shift,	0,
	[0x27]	"SRA",		shift,	0,

	[0x3C]	"SAVE",		add,	0,	/* page 117 */
	[0x3D]	"RESTORE",	add,	0,

	[0x38]	"JMPL",		jmpl,	0,	/* page 126 */

	[0x39]	"RETT",		add,	0,	/* page 127 */

	[0x3A]	"T",		trap,	0,	/* page 129 */

	[0x28]	"rdy",		rd,	0,	/* page 131 */
	[0x29]	"rdpsr",	rd,	0,
	[0x2A]	"rdwim",	rd,	0,
	[0x2B]	"rdtbr",	rd,	0,

	[0x30]	"wry",		wr,	0,	/* page 133 */
	[0x31]	"wrpsr",	wr,	0,
	[0x32]	"wrwim",	wr,	0,
	[0x33]	"wrtbr",	wr,	0,

	[0x3B]	"flush",	add,	0,	/* page 138 */

	[0x34]	"FPOP",		fpop,	0,	/* page 140 */
	[0x35]	"FPOP",		fpop,	0,
};

static struct opcode sparcop3[64]={
	[0x09]	"ldsb",		load,	0,	/* page 90 */
	[0x19]	"ldsba",	loada,	0,
	[0x0A]	"ldsh",		load,	0,
	[0x1A]	"ldsha",	loada,	0,
	[0x01]	"ldub",		load,	0,
	[0x11]	"lduba",	loada,	0,
	[0x02]	"lduh",		load,	0,
	[0x12]	"lduha",	loada,	0,
	[0x00]	"ld",		load,	0,
	[0x10]	"lda",		loada,	0,
	[0x03]	"ldd",		load,	0,
	[0x13]	"ldda",		loada,	0,

	[0x20]	"ldf",		loadf,	0,	/* page 92 */
	[0x23]	"lddf",		loadf,	0,
	[0x21]	"ldfsr",	loadf,0,

	[0x30]	"ldc",		loadc,	0,	/* page 94 */
	[0x33]	"lddc",		loadc,	0,
	[0x31]	"ldcsr",	loadcsr,0,

	[0x05]	"stb",		store,	0,	/* page 95 */
	[0x15]	"stba",		storea,	0,
	[0x06]	"sth",		store,	0,
	[0x16]	"stha",		storea,	0,
	[0x04]	"st",		store,	0,
	[0x14]	"sta",		storea,	0,
	[0x07]	"std",		store,	0,
	[0x17]	"stda",		storea,	0,

	[0x24]	"stf",		storef,	0,	/* page 97 */
	[0x27]	"stdf",		storef,	0,
	[0x25]	"stfsr",	storef,0,
	[0x26]	"stdfq",	storef,0,

	[0x34]	"stc",		loadc,	0,	/* page 99 */
	[0x37]	"stdc",		loadc,	0,
	[0x35]	"stcsr",	loadcsr,0,
	[0x36]	"stdcq",	loadcsr,0,

	[0x0D]	"ldstub",	store,	0,	/* page 101 */
	[0x1D]	"ldstuba",	storea,	0,

	[0x0F]	"swap",		load,	0,	/* page 102 */
	[0x1F]	"swapa",	loada,	0,
};

int myisp;
ADDR mydot;
Map *mymap;

void
mkinstr(Instr *i)
{
	WORD w;

	if (get4(mymap, dot, myisp, &w) == 0)
		chkerr();
	i->op = (w >> 30) & 0x03;
	i->rd = (w >> 25) & 0x1F;
	i->op2 = (w >> 22) & 0x07;
	i->a = (w >> 29) & 0x01;
	i->cond = (w >> 25) & 0x0F;
	i->op3 = (w >> 19) & 0x3F;
	i->rs1 = (w >> 14) & 0x1F;
	i->i = (w >> 13) & 0x01;
	i->asi = (w >> 5) & 0xFF;
	i->rs2 = (w >> 0) & 0x1F;
	i->simm13 = (w >> 0) & 0x1FFF;
	if(i->simm13 & (1<<12))
		i->simm13 |= ~((1<<13)-1);
	i->opf = (w >> 5) & 0x1FF;
	i->immdisp22 = (w >> 0) & 0x3FFFFF;
	i->simmdisp22 = i->immdisp22;
	if(i->simmdisp22 & (1<<21))
		i->simmdisp22 |= ~((1<<22)-1);
	i->disp30 = (w >> 0) & 0x3FFFFFFF;
	i->w0 = w;
	i->target = -1;

	if (myisp == SEGNONE)
		return;
	if(i->op==0 && i->op2==4 && !dascase){	/* SETHI */
		Instr xi;

		dot += 4;
		mkinstr(&xi);
		dot -= 4;
		if(xi.op==2 && xi.op3==0)		/* ADD */
		if(xi.i == 1 && xi.rs1 == i->rd){	/* immediate to same reg */
			i->imm32 = xi.simm13 + (i->immdisp22<<10);
			i->target = xi.rd;
			i->w1 = xi.w0;
			dotinc = 8;
			return;
		}
	}
	if(i->op==2 && i->opf==1 && !dascase){	/* FMOVS */
		Instr xi;

		dot += 4;
		mkinstr(&xi);
		dot -= 4;
		if(i->op==2 && i->opf==1)		/* FMOVS */
		if(xi.rd==i->rd+1 && xi.rs2==i->rs2+1){	/* next pair */
			i->w1 = xi.w0;
			dotinc = 8;
			return;
		}
	}
	dotinc = 4;
}

void
printins(Map *map, char modifier, int isp)
{
	Instr instr;
	void (*f)(Instr*, char*);

	USED(modifier);
	mymap = map;
	myisp = isp;
	mydot = dot;
	mkinstr(&instr);
	switch(instr.op){
	case 0:
		f = sparcop0[instr.op2].f;
		if(f)
			(*f)(&instr, sparcop0[instr.op2].mnemonic);
		else
			dprint("unknown %lux", instr.w0);
		break;

	case 1:
		dprint("%S", "CALL\t");
		psymoff(mydot+instr.disp30*4, SEGTEXT, dascase?"":"(SB)");
		break;

	case 2:
		f = sparcop2[instr.op3].f;
		if(f)
			(*f)(&instr, sparcop2[instr.op3].mnemonic);
		else
			dprint("unknown %lux", instr.w0);
		break;

	case 3:
		f = sparcop3[instr.op3].f;
		if(f)
			(*f)(&instr, sparcop3[instr.op3].mnemonic);
		else
			dprint("unknown %lux", instr.w0);
		break;
	}
}

void
sparcprintins(Map *map, char modifier, int isp)
{
		/* a modifier of 'I' toggles the dissassembler type */
	if ((asstype == ASUNSPARC && modifier == 'i')
		|| (asstype == ASPARC && modifier == 'I'))
		dascase = 'a'-'A';
	else
		dascase = 0;
	printins(map, modifier, isp);
}

void
sparcprintdas(Map *map, int isp)
{
	Instr instr;

	mymap = map;
	myisp = isp;
	mkinstr(&instr);
	printparcel(instr.w0, 7);
	if (dotinc == 8) {
		dprint(" ");
		printparcel(instr.w1, 7);
	}
	dprint("%38t");
	dotinc = 0;
}

static void
address(Instr *i)
{
	Symbol s, s2;
	WORD off, off1;

	if(i->rs1 == 2){
		off = mach->sb+i->simm13;
		if (findsym(off, CANY, &s) && s.value-off < maxoff) {
			if (s.class == CDATA || s.class == CTEXT) {
				if(off==s.value && s.name[0]=='$'){
					get4(symmap, s.value, SEGTEXT, &off1);
					if(off1 && findsym(off1, CANY, &s2)
							&& s2.value == off1){
						dprint("$%s(SB)", s2.name);
						return;
					}
				}
				dprint("%s", s.name);
				if (s.value != off)
					dprint("+%lux", s.value-off);
				dprint("(SB)");
				return;
			}
		}
	}
	dprint("%lux(R%d)", i->simm13, i->rs1);
}

void
unimp(Instr *i, char *m)
{
	USED(i);
	dprint("%S", m);
}

static char	*bratab[16] = {	/* page 91 */
	[0X8]	"A",
	[0X0]	"N",
	[0X9]	"NE",
	[0X1]	"E",
	[0XA]	"G",
	[0X2]	"LE",
	[0XB]	"GE",
	[0X3]	"L",
	[0XC]	"GU",
	[0X4]	"LEU",
	[0XD]	"CC",
	[0X5]	"CS",
	[0XE]	"POS",
	[0X6]	"NEG",
	[0XF]	"VC",
	[0X7]	"VS",
};

static char	*fbratab[16] = {	/* page 91 */
	[0X8]	"A",
	[0X0]	"N",
	[0X7]	"U",
	[0X6]	"G",
	[0X5]	"UG",
	[0X4]	"L",
	[0X3]	"UL",
	[0X2]	"LG",
	[0X1]	"NE",
	[0X9]	"E",
	[0XA]	"UE",
	[0XB]	"GE",
	[0XC]	"UGE",
	[0XD]	"LE",
	[0XE]	"ULE",
	[0XF]	"O",
};

static char	*cbratab[16] = {	/* page 91 */
	[0X8]	"A",
	[0X0]	"N",
	[0X7]	"3",
	[0X6]	"2",
	[0X5]	"23",
	[0X4]	"1",
	[0X3]	"13",
	[0X2]	"12",
	[0X1]	"123",
	[0X9]	"0",
	[0XA]	"03",
	[0XB]	"02",
	[0XC]	"023",
	[0XD]	"01",
	[0XE]	"013",
	[0XF]	"012",
};

void
bra1(Instr *i, char *m, char *tab[])
{
	long imm;

	imm = i->simmdisp22;
	if(i->a)
		dprint("%S%S.%c\t", m, tab[i->cond], 'A'+dascase);
	else
		dprint("%S%S\t", m, tab[i->cond]);
	psymoff(mydot+4*imm, SEGTEXT, dascase? "":"(SB)");
}

void
bra(Instr *i, char *m)	/* page 91 */
{
	bra1(i, m, bratab);
}

void
fbra(Instr *i, char *m)	/* page 93 */
{
	bra1(i, m, fbratab);
}

void
cbra(Instr *i, char *m)	/* page 95 */
{
	bra1(i, m, cbratab);
}

void
trap(Instr *i, char *m)	/* page 101 */
{

	if(i->i == 0)
		dprint("%S%S\tR%d+R%d", m, bratab[i->cond], i->rs2, i->rs1);
	else
		dprint("%S%S\t$%lux+R%d", m, bratab[i->cond], i->simm13, i->rs1);
}

static
void sethi(Instr *i, char *m)	/* page 89 */
{
	ulong imm;

	imm = i->immdisp22<<10;
	if(dascase){
		dprint("%S\t%lux, R%d", m, imm, i->rd);
		return;
	}
	if(imm==0 && i->rd==0){
		dprint("NOP");
		return;
	}
	if(i->target < 0){
		dprint("MOVW\t$%lux, R%d", imm, i->rd);
		return;
	}
	dprint("MOVW\t$%lux, R%d", i->imm32, i->target);
}

static char ldtab[] = {
	'W',
	'B',
	'H',
	'D',
};

static char*
moveinstr(int op3, char *m)
{
	char *s;
	int c;
	static char buf[8];

	if(!dascase){
		/* batshit cases */
		if(op3 == 0xF || op3 == 0x1F)
			return "SWAP";
		if(op3 == 0xD || op3 == 0x1D)
			return "TAS";	/* really LDSTUB */
		c = ldtab[op3&3];
		s = "";
		if((op3&11)==1 || (op3&11)==2)
			s="U";
		sprint(buf, "MOV%c%s", c, s);
		return buf;
	}
	return m;
}

static void
load(Instr *i, char *m)	/* page 68 */
{
	m = moveinstr(i->op3, m);
	if(i->i == 0)
		dprint("%s\t(R%d+R%d), R%d", m, i->rs1, i->rs2, i->rd);
	else{
		dprint("%s\t", m);
		address(i);
		dprint(", R%d", i->rd);
	}
}

static void
loada(Instr *i, char *m)	/* page 68 */
{
	m = moveinstr(i->op3, m);
	if(i->i == 0)
		dprint("%s\t(R%d+R%d, %d), R%d", m, i->rs1, i->rs2, i->asi, i->rd);
	else
		dprint("unknown ld asi %lux", i->w0);
}

static void
store(Instr *i, char *m)	/* page 74 */
{
	m = moveinstr(i->op3, m);
	if(i->i == 0)
		dprint("%s\tR%d, (R%d+R%d)", m, i->rd, i->rs1, i->rs2);
	else{
		dprint("%s\tR%d, ", m, i->rd);
		address(i);
	}
}

static void
storea(Instr *i, char *m)	/* page 74 */
{
	m = moveinstr(i->op3, m);
	if(i->i == 0)
		dprint("%s\tR%d, (R%d+R%d, %d)", m, i->rd, i->rs1, i->rs2, i->asi);
	else
		dprint("%s\tR%d, %d(R%d, %d), ???", m, i->rd, i->simm13, i->rs1, i->asi);
}

void
shift(Instr *i, char *m)	/* page 88 */
{
	if(i->i == 0){
		if(i->rs1 == i->rd)
			dprint("%S\tR%d, R%d", m, i->rs2, i->rs1);
		else
			dprint("%S\tR%d, R%d, R%d", m, i->rs2, i->rs1, i->rd);
	}else{
		if(i->rs1 == i->rd)
			dprint("%S\t$%d, R%d", m, i->simm13&0x1F, i->rs1);
		else
			dprint("%S\t$%d, R%d, R%d", m, i->simm13&0x1F, i->rs1, i->rd);
	}
}

static void
add(Instr *i, char *m)	/* page 82 */
{
	if(i->i == 0){
		if(!dascase && i->op3==2 && i->rs1==0 && i->rd)	/* OR R2, R0, R1 */
			dprint("MOVW\tR%d", i->rs2);
		else
			dprint("%S\tR%d, R%d", m, i->rs2, i->rs1);
	}else{
		if(!dascase && i->op3==0 && i->rd && i->rs1==0)	/* ADD $x, R0, R1 */
			dprint("MOVW\t$%lux", i->simm13);
		else if(!dascase && i->op3==0 && i->rd && i->rs1==2){
			/* ADD $x, R2, R1 -> MOVW $x(SB), R1 */
			dprint("MOVW\t$");
			address(i);
		}else
			dprint("%S\t$%lux, R%d", m, i->simm13, i->rs1);
	}
	if(i->rs1 != i->rd)
		dprint(", R%d", i->rd);
}

static void
cmp(Instr *i, char *m)
{
	if(dascase || i->rd){
		add(i, m);
		return;
	}
	if(i->i == 0)
		dprint("CMP\tR%d, R%d", i->rs1, i->rs2);
	else
		dprint("CMP\tR%d, $%lux", i->rs1, i->simm13);
}

static char *regtab[4] = {
	"Y",
	"PSR",
	"WIM",
	"TBR",
};

static void
wr(Instr *i, char *m)	/* page 82 */
{
	if(dascase){
		if(i->i == 0)
			dprint("%s\tR%d, R%d", m, i->rs2, i->rs1);
		else
			dprint("%s\t$%lux, R%d", m, i->simm13, i->rs1);
	}else{
		if(i->i && i->simm13==0)
			dprint("MOVW\tR%d", i->rs1);
		else if(i->i == 0)
			dprint("wr\tR%d, R%d", i->rs2, i->rs1);
		else
			dprint("wr\t$%lux, R%d", i->simm13, i->rs1);
	}
	dprint(", %s", regtab[i->op3&3]);
}

static void
rd(Instr *i, char *m)	/* page 103 */
{
	if(i->rs1==15 && i->rd==0){
		m = "stbar";
		if(!dascase)
			m = "STBAR";
		dprint("%s", m);
	}else{
		if(!dascase)
			m = "MOVW";
		dprint("%s\t%s, R%d", m, regtab[i->op3&3], i->rd);
	}
}

static void
jmpl(Instr *i, char *m)	/* page 82 */
{
	if(i->i == 0){
		if(i->rd == 15)
			dprint("%S\t(R%d+R%d)", "CALL", i->rs2, i->rs1);
		else
			dprint("%S\t(R%d+R%d), R%d", m, i->rs2, i->rs1, i->rd);
	}else{
		if(!dascase && i->simm13==8 && i->rs1==15 && i->rd==0)
			dprint("RETURN");
		else{
			dprint("%S\t", m);
			address(i);
			dprint(", R%d", i->rd);
		}
	}
}

static
void loadf(Instr *i, char *m)	/* page 70 */
{
	if(!dascase){
		m = "FMOVD";
		if(i->op3 == 0x20)
			m = "FMOVF";
		else if(i->op3 == 0x21)
			m = "MOVW";
	}
	if(i->i == 0)
		dprint("%s\t(R%d+R%d)", m, i->rs1, i->rs2);
	else{
		dprint("%s\t", m);
		address(i);
	}
	if(i->op3 == 0x21)
		dprint(", FSR");
	else
		dprint(", R%d", i->rd);
}

static
void storef(Instr *i, char *m)	/* page 70 */
{
	if(!dascase){
		m = "FMOVD";
		if(i->op3 == 0x25 || i->op3 == 0x26)
			m = "MOVW";
		else if(i->op3 == 0x20)
			m = "FMOVF";
	}
	dprint("%s\t", m);
	if(i->op3 == 0x25)
		dprint("FSR, ");
	else if(i->op3 == 0x26)
		dprint("FQ, ");
	else
		dprint("R%d, ", i->rd);
	if(i->i == 0)
		dprint("(R%d+R%d)", i->rs1, i->rs2);
	else
		address(i);
}

static
void loadc(Instr *i, char *m)	/* page 72 */
{
	if(i->i == 0)
		dprint("%s\t(R%d+R%d), C%d", m, i->rs1, i->rs2, i->rd);
	else{
		dprint("%s\t", m);
		address(i);
		dprint(", C%d", i->rd);
	}
}

static
void loadcsr(Instr *i, char *m)	/* page 72 */
{
	if(i->i == 0)
		dprint("%s\t(R%d+R%d), CSR", m, i->rs1, i->rs2);
	else{
		dprint("%s\t", m);
		address(i);
		dprint(", CSR");
	}
}

static struct{
	int	opf;
	char	*name;
} fptab1[] = {			/* ignores rs1 */
	0xC4,	"FITOS",	/* page 109 */
	0xC8,	"FITOD",
	0xCC,	"FITOX",

	0xD1,	"FSTOI",	/* page 110 */
	0xD2,	"FDTOI",
	0xD3,	"FXTOI",

	0xC9,	"FSTOD",	/* page 111 */
	0xCD,	"FSTOX",
	0xC6,	"FDTOS",
	0xCE,	"FDTOX",
	0xC7,	"FXTOS",
	0xCB,	"FXTOD",

	0x01,	"FMOVS",	/* page 112 */
	0x05,	"FNEGS",
	0x09,	"FABSS",

	0x29,	"FSQRTS", 	/* page 113 */
	0x2A,	"FSQRTD",
	0x2B,	"FSQRTX",

	0,	0,
};

static struct{
	int	opf;
	char	*name;
} fptab2[] = {			/* uses rs1 */

	0x41,	"FADDS",	/* page 114 */
	0x42,	"FADDD",
	0x43,	"FADDX",
	0x45,	"FSUBS",
	0x46,	"FSUBD",
	0x47,	"FSUBX",

	0x49,	"FMULS",	/* page 115 */
	0x4A,	"FMULD",
	0x4B,	"FMULX",
	0x4D,	"FDIVS",
	0x4E,	"FDIVD",
	0x4F,	"FDIVX",

	0x51,	"FCMPS",	/* page 116 */
	0x52,	"FCMPD",
	0x53,	"FCMPX",
	0x55,	"FCMPES",
	0x56,	"FCMPED",
	0x57,	"FCMPEX",

	0, 0
};

void fpop(Instr *i, char *m)	/* page 108-116 */
{
	int j;

	if(dascase==0 && dotinc==8){
		dprint("FMOVD\tF%d, F%d", i->rs2, i->rd);
		return;
	}
	for(j=0; fptab1[j].name; j++)
		if(fptab1[j].opf == i->opf){
			dprint("%S\tF%d, F%d", fptab1[j].name, i->rs2, i->rd);
			return;
		}
	for(j=0; fptab2[j].name; j++)
		if(fptab2[j].opf == i->opf){
			dprint("%S\tF%d, F%d, F%d", fptab2[j].name, i->rs1, i->rs2, i->rd);
			return;
		}
	dprint("%S%ux\tF%d, F%d, F%d", m, i->opf, i->rs1, i->rs2, i->rd);
}

int
sparcfoll(ulong pc, ulong *foll)
{
	ulong w, r1, r2;
	char buf[8];
	Instr i;

	mymap = cormap;
	myisp = SEGDATA;
	mkinstr(&i);
	w = i.w0;
	switch(w & 0xC1C00000){
	case 0x00800000:		/* branch on int cond */
	case 0x01800000:		/* branch on fp cond */
	case 0x01C00000:		/* branch on copr cond */
		foll[0] = pc+8;
		foll[1] = pc + (i.simmdisp22<<2);
		return 2;
	}

	if((w&0xC0000000) == 0x40000000){	/* CALL */
		foll[0] = pc + (i.disp30<<2);
		return 1;
	}

	if((w&0xC1F80000) == 0x81C00000){	/* JMPL */
		sprint(buf, "R%d", (w>>14)&0xF);
		r1 = rget(rname(buf));
		if(w & 0x2000)			/* JMPL R1+simm13 */
			r2 = i.simm13;
		else{				/* JMPL R1+R2 */
			sprint(buf, "R%d", w&0xF);
			r2 = rget(rname(buf));
		}
		foll[0] = r1 + r2;
		return 1;
	}
	foll[0] = pc+dotinc;
	return 1;
}
