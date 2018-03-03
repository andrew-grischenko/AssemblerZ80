#include <c:\borlandc\projects\assm\assm.h>

char LbTbl::check(char const *str){
for(i=0;i<used;i++){
	if(strcmp(str,lb[i])==0)
		if(defined[i])
			return 1;
		else
			return 0;
	};
strcpy(lb[used],str);
defined[used++]=0;
return 0;
};

char LbTbl::put(char const *str, unsigned int znach){
for(i=0;i<used;i++){
	if(strcmp(str,lb[i])==0){
		val[i]=znach;
		defined[i]=1;
		return 1;
		};
	};
strcpy(lb[used],str);
val[used]=znach;
defined[used++]=1;
if(used>256)
	return 0;
return 1;
};

unsigned int LbTbl::get(char const *str){
for(i=0;i<used;i++){
	if(strcmp(str,lb[i])==0)
		if(defined[i])
			return val[i];
	};
return 0xffff;
};

void LbTbl::fprint(void){
fprintf(f_map,"\n");
fprintf(f_map,"\n\tTable of labels :  %d elements.",used);
fprintf(f_map,"\n   Label\t\t\t   Value \n  --------------------------------------------");
for(i=0;i<used;i++)
	if(defined[i])
		fprintf(f_map,(strlen(lb[i])<5) ? "\n   %s\t\t\t\t   %04X" : "\n   %s\t\t\t   %04X",lb[i],val[i]);
	else
		fprintf(f_map,(strlen(lb[i])<5) ? "\n   %s\t\t\t\t   ????" : "\n   %s\t\t\t   ????",lb[i]);

};
