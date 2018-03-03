#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dir.h>
#include <dos.h>
#include <alloc.h>


class LbTbl {
		char lb[300][32];
		unsigned int val[300];
		char defined[300];
		int i;
		int used;
	public:
		char check(char const *);
		char put(char const *, unsigned int );
		unsigned int get(char const *);
		void fprint(void);
		};



enum cmd {ADC=1,ADD,AND,BIT,CALL,CCF,CP,CPD,CPDR,CPI,CPIR,CPL,DAA,DEC,
	   DI,DJNZ,EI,EX,EXX,HALT,IM,IN,INC,IND,INDR,INI,INIR,JP,JR,LD,LDD,
	   LDDR,LDI,LDIR,NEG,NOP,OR,OTDR,OTIR,OUT,OUTD,OUTI,POP,PUSH,RES,
	   RET,RETI,RETN,RL,RLA,RLC,RLCA,RLD,RR,RRA,RRC,RRCA,RRD,RST,SBC,SCF,
	   SET,SLA,SRA,SRL,SUB,XOR,
	   DEFB,DEFM,DEFS,DEFW,END,EQU,ORG};
enum err {E_INV_OP1=1,
	E_INV_OP2,
	E_INV_OP,
	E_UND_CMD,
	E_LBL_NF,
	E_LBL_DUP,
	E_INV_EXPR,
	E_INV_CMDLINE,
     E_NOFILE,
	E_NOMEM,
	E_NOCREATE_FILE,
	E_LONGLINE,
	E_LONG_LBL,
	E_LONG_NUM,
	E_SYNTAX,
	E_OP3_INV
	};
enum reg8 {NO=0,B,C,D,E,H,L,_HL,A};
enum reg16 {BC=9,DE,HL,SP,IX,IY,_SB,_IX,_IY,I,R,_BC,_DE,AF,AF_};
enum cc {_NZ=24,_Z,_NC,_C,_PO,_PE,_P,_M,_CC};
enum d {N=50,NN,_N,_NN};

void error(char );

extern char far *memory;
extern char op1;
extern char op2;
extern unsigned int op3;
extern unsigned int _op1;
extern unsigned int _op2;
extern char PASS;
extern unsigned int PC;
extern char label[32];
extern char buffer[256];
extern FILE *f_lst;
extern FILE *f_asm;
extern FILE *f_bin;
extern FILE *f_map;
extern int LINE;
extern class LbTbl lbltbl;