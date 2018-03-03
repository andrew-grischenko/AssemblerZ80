#include "c:\borlandc\projects\assm\assm.h"

char far *memory;
char op1;
char op2;
unsigned int op3;
unsigned int _op1;
unsigned int _op2;
char PASS;
unsigned int PC;
char label[32];
char buffer[256];
FILE *f_lst;
FILE *f_asm;
FILE *f_bin;
FILE *f_map;
int LINE;
enum cmd cmd;
class LbTbl lbltbl;
char PAS1_ERRS;
char PAS2_ERRS;


int main(int argc, char *argv[]){
int getln(void);

char fileasm[MAXDRIVE+MAXDIR+MAXFILE+MAXEXT+5];
char filelst[MAXDRIVE+MAXDIR+MAXFILE+MAXEXT+5];
char filebin[MAXDRIVE+MAXDIR+MAXFILE+MAXEXT+5];
char filemap[MAXDRIVE+MAXDIR+MAXFILE+MAXEXT+5];


printf("\n PC to Z80 Assembler   (C) 1995 ESCO ltd.   v1.72 Betta");
void swich(int );


{//----------------Initialising *.lst, *.bin, *.map -------------------------
	char drive[ MAXDRIVE ];
	char dir[ MAXDIR ];
	char file[ MAXFILE ];
	char ext[ MAXEXT ];
	char extbin[]={"bin"};
	char extlst[]={"lst"};
	char extmap[]={"map"};

	if(argc<1){
		error(E_INV_CMDLINE);
		exit(0);
		};

	f_asm=fopen(argv[1],"rt");
	if(f_asm==NULL){
		error(E_NOFILE);
		exit(0);
		};

	fnsplit(argv[1],drive,dir,file,ext);

	fnmerge(filebin,drive,dir,file,extbin);
	fnmerge(filelst,drive,dir,file,extlst);
	fnmerge(filemap,drive,dir,file,extmap);
}//--------------------------------------------------------------------------

{//--------------- Allocating code page buffer ------------------------------
	unsigned int i;
	memory=(char far *)farmalloc(8912);
	if(memory==NULL){
		error(E_NOMEM);
		exit(0);
		};
	for(i=0;i<8912;memory[i++]=0);
}//--------------------------------------------------------------------------

//---------------- Main looop 'Pass 1 & Pass 2'-----------------------------
PAS1_ERRS=0;
PAS2_ERRS=0;

printf("\nCompiling '%s'",argv[1]);
for(PASS=1;PASS<3;PASS++){
	unsigned int PCold;
	int info;
	rewind(f_asm);

	if(PASS==2){
		struct date d;
		f_lst=fopen(filelst,"wt");
		if(f_lst==NULL){
			error(E_NOCREATE_FILE);
			exit(0);
			};
		getdate(&d);
		fprintf(f_lst,"\n Z80 for PC Assembler v2.01                   Date : %d.%d.%d",
				d.da_day,d.da_mon,d.da_year);
		fprintf(f_lst,"\n-----------------------------------------------------------------");
		fprintf(f_lst,"\n\n                            File: %s                           ",
				argv[1]);
		};

	printf("\nPass  %d",PASS);
	PC=0;
	LINE=0;

	while((info=getln())!=EOF){
		PCold=PC;
		if(info) swich(cmd);
		if(PASS==2){
{//---------------- Screen listing output------------------------------------
			printf("\n%4d  %04X  ",LINE,PCold);
			if(info)
				for(int i=PCold;i<PC;i++)
					printf("%02X ",memory[i]);
			if( (PC-PCold)<4 ) printf("\t");
			if( (PC-PCold)==1 ) printf("\t");
			if( (PC-PCold)==0 ) printf("\t");
			printf("\t %s",buffer);
}//--------------------------------------------------------------------------
{//---------------- File listing output -------------------------------------
			fprintf(f_lst,"\n%4d  %04X  ",LINE,PCold);
			if(info)
				for(int i=PCold;i<PC;i++)
					fprintf(f_lst,"%02X ",memory[i]);
			if( (PC-PCold)<4 ) fprintf(f_lst,"\t");
			if( (PC-PCold)==1 ) fprintf(f_lst,"\t");
			if( (PC-PCold)==0 ) fprintf(f_lst,"\t");
			fprintf(f_lst,"\t %s",buffer);
}//--------------------------------------------------------------------------
			};
		};
	if(PASS==1){
		printf("\nPass 1  errors %d",PAS1_ERRS);
		f_map=fopen(filemap,"wt");
		if(f_map==NULL)
			error(E_NOCREATE_FILE);
		else {
			lbltbl.fprint();
			fclose(f_map);
			};

		if( PAS1_ERRS ) break;
		};
	if(PASS==2)
		printf("\nPass 2  errors %d",PAS2_ERRS);
	};
//-------------------------------------------------------------------------

{//---------------- Epilog --------------------------------------------------
printf("\n\n Total errors found - %d\n",PAS1_ERRS+PAS2_ERRS);
if(PASS==2){
	fprintf(f_lst,"\n\n Total errors found - %d\n",PAS1_ERRS+PAS2_ERRS);
	fclose(f_lst);
	};
f_map=fopen(filemap,"wt");
if(f_map==NULL)
	error(E_NOCREATE_FILE);
else {
	lbltbl.fprint();
	fclose(f_map);
	};

fclose(f_asm);

if( ! (PAS1_ERRS+PAS2_ERRS) ){
	unsigned int i;
	f_bin=fopen(filebin,"wb");
	if(f_bin==NULL){
		error(E_NOCREATE_FILE);
		exit(0);
		};
	for(i=0;i<PC;i++)
		fputc(memory[i],f_bin);
	};
}//-------------------------------------------------------------------------

return 0;
};
//////////// End of main() //////////////////////////////////////////////////


int getln(void){ ////////// G E T   L I N E /////////////////////////////////
enum cmd findc(char * );
char findop(char * ,unsigned int &);

int src;
int dest;
int prin;
int c;
char buf[128];

prin=0;
dest=0;
{//---------------- Reading line into buffer --------------------------------
while( ((c=fgetc(f_asm))!=EOF)&&(c!='\n')&&(dest<256) ){
	buffer[dest++]=c;
	if(isprint(c)) prin++;
	};
if(dest>256){
	error(E_LONGLINE);
	exit(0);
	};
buffer[dest]=0;
strupr(buffer);

if( (c==EOF)&&(!prin) ) return EOF;

LINE++;
if(prin==0){
	return 0;
	};
}//--------------------------------------------------------------------------

src=0;
dest=0;
{//---------------- Label extraction ----------------------------------------
if(!isspace(buffer[0])){
	while( (isgraph(label[dest]=buffer[src]))
		&&(dest<128)
		&&(buffer[src]!=';') ){
			dest++;
			src++;
		};
	if(dest>=128)
		error(E_LONG_LBL);

	label[dest]=0;

	if((PASS==1)&&(src)){
		if(lbltbl.check(label))
			error(E_LBL_DUP);
		else
			lbltbl.put(label,PC);
		};
	if(buffer[src]==';')
		return 0;
	};
}//--------------------------------------------------------------------------
while( isspace(buffer[src])&&buffer[src] ) src++;
if( !buffer[src]) return 0;
dest=0;

{//---------------- Command extraction --------------------------------------
char c;
while( (isgraph(c=buffer[src])) && (c!=';') && (c) )
	buf[dest++]=buffer[src++];
buf[dest]=0;
cmd=findc(buf);
if(c==';')
	return 1;
}//--------------------------------------------------------------------------
while( (!isgraph(buffer[src]))&&(buffer[src]) ) src++;
if( (!buffer[src])||(buffer[src]==';')){
	op1=NO;
	op2=NO;
	return 1;
	};
dest=0;

{//---------------- Operand 1 extraction ------------------------------------
char c;
while( ((c=buffer[src])!=';') && (c!=',') && (isgraph(c)) )
	buf[dest++]=buffer[src++];
buf[dest]=0;

op1=findop(buf,_op1);
if(c!=','){
	op2=NO;
	return 1;
	};
src++;
}//--------------------------------------------------------------------------
dest=0;

{//---------------- Operand 2 extraction ------------------------------------
char c;
while( (isgraph(c=buffer[src])) && (c!=';') && (c) )
	buf[dest++]=buffer[src++];
buf[dest]=0;

op2=findop(buf,_op2);
}//--------------------------------------------------------------------------

return 1;
};
////////////////// End of GETLN() ///////////////////////////////////////////


enum cmd findc(char *buf){///////// F I N D    C O M M A N D ////////////////////
char cmd;
int i;
static char *comands[]={ 0,
	"ADC","ADD","AND","BIT","CALL","CCF","CP","CPD","CPDR","CPI",
	"CPIR","CPL","DAA","DEC","DI","DJNZ","EI","EX","EXX","HALT",
	"IM","IN","INC","IND","INDR","INI","INIR","JP","JR","LD",
	"LDD","LDDR","LDI","LDIR","NEG","NOP","OR","OTDR","OTIR","OUT",
	"OUTD","OUTI","POP","PUSH","RES","RET","RETI","RETN","RL","RLA",
	"RLC","RLCA","RLD","RR","RRA","RRC","RRCA","RRD","RST","SBC",
	"SCF","SET","SLA","SRA","SRL","SUB","XOR","DEFB","DEFM","DEFS",
	"DEFW","END","EQU","ORG"
	};

cmd=0;
for(i=1;i<75;i++){
	if(strcmp(buf,comands[i])==0){
		cmd=i;
		break;
		};
	};
return cmd;
};
/////////////////// End of FINDC() //////////////////////////////////////////


char findop(char *buf,unsigned int &op){/////////// F I N D   O P E R A N D S /////////
char getname(char *,unsigned int &);

static char *ops[]={ 0,
	"B","C","D","E","H","L","(HL)","A",
	"BC","DE","HL","SP","IX","IY","(SP)","(IX)","(IY)",
	"I","R","(BC)","(DE)","AF","AF'",
	"NZ","Z","NC","C","PO","PE","P","M","(C)"
	};
{//---------------- Try identify as not simbol ------------------------------
int i;
for(i=0;i<33;i++){
	if(strcmp(buf,ops[i])==0){
		if((i==_IX)||(i==_IY)){
			op3=0;
			return i;
			};
		return i;
		};
	};
}//--------------------------------------------------------------------------

{//--------------- (IX+-delta), (IY+-delta) ---------------------------------
if(strncmp(buf,"(IX+",4)==0){
	if(!getname(buf+4,op3)){
		error(E_SYNTAX);
		return 0;
		};
	if(op3>256){
		error(E_OP3_INV);
		return 0;
		};
	return _IX;
	};

if(strncmp(buf,"(IX-",4)==0){
	if(!getname(buf+4,op3)){
		error(E_SYNTAX);
		return 0;
		};
	if( op3>256 ){
		error(E_OP3_INV);
		return 0;
		};
	op3=-op3;
	return _IX;
	};

if(strncmp(buf,"(IY+",4)==0){
	if(!getname(buf+4,op3)){
		error(E_SYNTAX);
		return 0;
		};
	if( op3>256 ){
		error(E_OP3_INV);
		return 0;
		};
	return _IY;
	};

if(strncmp(buf,"(IY-",4)==0){
	if(!getname(buf+4,op3)){
		error(E_SYNTAX);
		return 0;
		};
	if( op3>256){
		error(E_OP3_INV);
		return 0;
		};
	op3=-op3;
	return _IY;
	};
}//--------------------------------------------------------------------------

{//---------------- Get as N or _N ------------------------------------------
if(buf[0]=='('){
	if(getname(buf+1,op)){
		if(op<256)
			return _N;
		else
			return _NN;
		};
	error(E_INV_OP);
	return 0;
	};

if(getname(buf,op)){
	if(op<256)
		return N;
	else
		return NN;
	};
}//--------------------------------------------------------------------------

error(E_INV_OP);
return 0;
};

char getname(char *src, unsigned int &op){
int i;
unsigned int ret=0;
unsigned char end=0;

while( isgraph(src[end])&&(src[end]!=')') )
	end++;
end--;

if(isdigit(src[0]))
{//---------------- Digit ---------------------------------------------------
	while( isgraph(src[end])&&(src[end]!=')') )
		end++;
	end--;
	if(end>10){
		error(E_LONG_NUM);
		return 0;
		};
	switch(src[end]){
		case 'H':
			for(i=0;i<end;i++){
				switch(src[i]){
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						ret=16*ret+(src[i]-'0');
						break;
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
						ret=16*ret+(src[i]-'A'+10);
						break;
					default:
						error(E_INV_EXPR);
						return 0;
					};
				};
			op=ret;
			return 1;

		case 'B':
			for(i=0;i<end;i++){
				switch(src[i]){
					case '1':
					case '0':
						ret=2*ret+(src[i]-'0');
						break;
					default:
						error(E_INV_EXPR);
						return 0;
						};
				    };
			op=ret;
			return 1;
		default:
			for(i=0;i<end+1;i++){
				switch(src[i]){
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						ret=10*ret+src[i]-'0';
						break;
					default:
						error(E_INV_EXPR);
						return 0;
					};
				};
			op=ret;
			return 1;
		};
	};//--------------------------------------------------------------------
if(PASS==1){
	char locbuf[32];
	strncpy(locbuf,src,end+1);
	locbuf[end+1]='\0';
	lbltbl.check(locbuf);
	op=0;
	return 1;
	};
{//---------------- Label ---------------------------------------------------
char locbuf[32];
strncpy(locbuf,src,end+1);
locbuf[end+1]='\0';
if(lbltbl.check(locbuf)){
	op=lbltbl.get(locbuf);
	return 1;
	};

}//--------------------------------------------------------------------------
error(E_LBL_NF);
return 0;
};

void error(char ern){
char *errmsg[]={
	" ",
	"Invald operand 1 ",
	"Invalid operand 2",
	"Invalid operand",
	"Unrecognized command",
	"Label not found",
	"Duplicate of lable",
	"Invalid expression",
	"Invalid command line",
	"Can`t open file...",
	"No memory ...",
	"Can`t create file...",
	"Too long line",
	"Too long identifier",
	"Too big number",
	"Syntax bad",
	"Invalid operand 3"
	};

printf("\n> ERROR [%2d]   %s",ern,errmsg[ern]);
printf("\n> Line N%d",LINE);
printf("\n%s",buffer);
if(PASS==1)
	PAS1_ERRS++;
else
	{
	PAS2_ERRS++;
	fprintf(f_lst,"\n> ERROR [%2d]:  %s",ern,errmsg[ern]);
	fprintf(f_lst,"\n%s\n",buffer);
	};
if( (PAS1_ERRS>20)||(PAS2_ERRS>20) ){
	printf("\n\n> Fatal ERROR: Too many errors...");
	exit(0);
	};
};

