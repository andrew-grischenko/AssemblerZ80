#include "c:\borlandc\projects\assm\assm.h"

void swich(int cmd){
void putmem(char );

do {
switch (cmd){
	   case    ADC:{
			 switch(op1) {
				    case A:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
									   putmem(0x88|(op2-B));
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0x8E);
									   putmem(op3);

									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0x8E);
									   putmem(op3);
									   continue;
								case N:
									   putmem(0xCE);
									   putmem(_op2);
									   continue;

								default: error(E_INV_OP2);
								continue;
								};
				    case HL:
						  switch(op2){
								case BC:
								case DE:
								case HL:
								case SP:
									   putmem(0xED);
                                                putmem(0x4A|((op2-BC)<<4));
                                                continue;
                                        default: error(E_INV_OP2);
                                        continue;
								};
                        default: error(E_INV_OP1);
                        continue;
				    };
                    }

        case    ADD:{
                switch(op1) {
                        case A:
                                switch(op2){
								case B:
                                        case C:
								case D:
								case E:
								case H:
								case L:
                                        case _HL:
                                        case A:
                                                putmem(0x80|(op2-B));
                                                continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0x86);
									   putmem(op3);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0x86);
									   putmem(op3);
									   continue;
								case N:
                                                putmem(0xC6);
									   putmem(_op2);
									   continue;

								default: error(E_INV_OP2);
                                        continue;
                                        };
                        case HL:
                                switch(op2){
								case BC:
                                        case DE:
                                        case HL:
								case SP:
                                                putmem(0x09|((op2-BC)<<4));
                                                continue;
                                        default: error(E_INV_OP2);
                                        continue;
                                        };
                        case IX:
						  switch(op2){
                                        case BC:
								case DE:
                                        case SP:
									   putmem(0xDD);
									   putmem(0x09|((op2-BC)<<4));
                                                continue;
                                        case IX :
                                                putmem(0xDD);
                                                putmem(0x29);
									   continue;
                                        default: error(E_INV_OP2);
                                        continue;
								};
                        case IY:
                                switch(op2){
                                        case BC:
                                        case DE:
                                        case SP:
                                                putmem(0xFD);
									   putmem(0x09|((op2-BC)<<4));
                                                continue;
								case IY :
                                                putmem(0xFD);
									   putmem(0x29);
									   continue;
                                        default: error(E_INV_OP2);
                                        continue;
                                        };
                        default: error(E_INV_OP1);
				    continue;
                        };
                    }

        case    AND:
                switch(op1){
                        case B:
                        case C:
                        case D:
                        case E:
                        case H:
                        case L:
				    case _HL:
                        case A:
						  putmem(0xA0|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xA6);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xA6);
						  putmem(op3);
						  continue;
				    case N:
						  putmem(0xE6);
						  putmem(_op1);
						  continue;
				    default: error(E_INV_OP1);
				    continue;
				    };


	   case    OR:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0xB0|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xB6);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xB6);
						  putmem(op3);
						  continue;
				    case N:
						  putmem(0xF6);
						  putmem(_op1);
						  continue;
				    default: error(E_INV_OP1);
				    continue;
				    };


	   case    XOR:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0xA8|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xAE);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xAE);
						  putmem(op3);
						  continue;
				    case N:
						  putmem(0xEE);
						  putmem(_op1);
						  continue;
				    default: error(E_INV_OP1);
				    continue;
				    };


	   case    CP:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0xB8|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xBE);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xBE);
						  putmem(op3);
						  continue;
				    case N:
						  putmem(0xFE);
						  putmem(_op1);
						  continue;
				    default: error(E_INV_OP1);
				    continue;
				    };


	   case    BIT :
			 switch(op1){
				    case N:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
									   putmem(0xCB);
									   putmem(0x40|(_op1<<3)|(op2-B));
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0x40|(_op1<<3)|6);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0x40|(_op1<<3)|6);
									   continue;
								default: error(E_INV_OP2);
								continue;
						  };
				    default: error(E_INV_OP1);
				    continue;
				    };

	   case    SET :
			 switch(op1){
				    case N:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
									   putmem(0xCB);
									   putmem(0xC0|(_op1<<3)|(op2-B));
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0xC0|(_op1<<3)|6);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0xC0|(_op1<<3)|6);
									   continue;
								default: error(E_INV_OP2);
								continue;
						  };
				    default: error(E_INV_OP1);
				    continue;
				    };


	   case    RES :
			 switch(op1){
				    case N:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
									   putmem(0xCB);
									   putmem(0x80|(_op1<<3)|(op2-B));
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0x80|(_op1<<3)|6);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0xCB);
									   putmem(op3);
									   putmem(0x80|(_op1<<3)|6);
									   continue;
								default: error(E_INV_OP2);
								continue;
						  };
				    default: error(E_INV_OP1);
				    continue;
				    };


		 case    CALL :
					switch(op1){
							 case NN:
										putmem(0xCD);
										putmem(_op1);
										putmem(_op1>>8);
										continue;
							 case N:
										putmem(0xCD);
										putmem(_op1);
										putmem(0);
										continue;


				    case _Z :
				    case _NZ :
				    case _NC:
				    case _PO:
				    case _PE:
				    case _P :
				    case _M :
						switch(op2){
							case NN:
								putmem(0xC4|((op1-_NZ)<<3));
								putmem(_op2);
								putmem(_op2>>8);
								continue;
							case N:
								putmem(0xC4|((op1-_NZ)<<3));
								putmem(_op2);
								putmem(0);
								continue;
							default: error(E_INV_OP2);
							continue;
						    };
				    case C:
						switch(op2){
							case NN:
								putmem(0xDC);
								putmem(_op2);
								putmem(_op2>>8);
								continue;
							case N:
								putmem(0xDC);
								putmem(_op2);
								putmem(0);
								continue;
							default: error(E_INV_OP2);
							continue;
						    };

				    default: error(E_INV_OP1);
				    continue;
							 };

		 case EXX :
			 switch(op1){
							 case NO:
										putmem(0xD9);
										continue;
				    default: error(E_INV_OP);
				    continue;
							 };

		 case DAA :
			 switch(op1){
				    case NO:
						  putmem(0x27);
						  continue;
				    default: error(E_INV_OP);
				    continue;
				    };
	   case CPL :
			 switch(op1){
				    case NO:
						  putmem(0x2F);
						  continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case CCF :
                switch(op1){
                        case NO:
                                putmem(0x3F);
						  continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case SCF :
                switch(op1){
                        case NO:
                                putmem(0x37);
                                continue;
                        default: error(E_INV_OP);
				    continue;
                        };
	   case RLCA:
                switch(op1){
                        case NO:
                                putmem(0x07);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
	   case RLA :
			 switch(op1){
                        case NO:
                                putmem(0x17);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case RRCA:
                switch(op1){
				    case NO:
                                putmem(0x0F);
						  continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case RRA :
                switch(op1){
                        case NO:
                                putmem(0x1F);
						  continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case NOP :
                switch(op1){
                        case NO:
                                putmem(0x00);
                                continue;
                        default: error(E_INV_OP);
				    continue;
                        };
	   case HALT:
                switch(op1){
                        case NO:
                                putmem(0x76);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
	   case DI :
			 switch(op1){
                        case NO:
                                putmem(0xF3);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case EI :
                switch(op1){
				    case NO:
                                putmem(0xFB);
						  continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case OUTD:
                switch(op1){
                        case NO:
                                putmem(0xED);
						  putmem(0xAB);
						  continue;
                        default: error(E_INV_OP);
                        continue;
                        };

        case LDI:
                switch(op1){
                        case NO:
                                putmem(0xED);
						  putmem(0xA0);
                                continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case LDIR:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xB0);
						  continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case LDD:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xA8);
                                continue;
				    default: error(E_INV_OP);
                        continue;
				    };
        case LDDR:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xB8);
                                continue;
                        default: error(E_INV_OP);
				    continue;
                        };
        case CPI:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xA1);
                                continue;
                        default: error(E_INV_OP);
                        continue;
				    };
        case CPIR:
			 switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xB1);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
	   case CPD:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xA9);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case CPDR:
                switch(op1){
                        case NO:
						  putmem(0xED);
                                putmem(0xB9);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case NEG:
                switch(op1){
				    case NO:
                                putmem(0xED);
                                putmem(0x44);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case OUTI:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xA3);
						  continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case OTIR:
                switch(op1){
                        case NO:
                                putmem(0xED);
						  putmem(0xB3);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case OTDR:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xBB);
                                continue;
                        default: error(E_INV_OP);
				    continue;
                        };
        case RLD:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0x6F);
                                continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case RRD:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0x67);
						  continue;
                        default: error(E_INV_OP);
                        continue;
                        };
	   case RETI:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0x4D);
                                continue;
                        default: error(E_INV_OP);
                        continue;
				    };
        case RETN:
                switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0x45);
                                continue;
				    default: error(E_INV_OP);
                        continue;
                        };
        case INI:
                switch(op1){
				    case NO:
                                putmem(0xED);
                                putmem(0xA2);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case INIR:
			 switch(op1){
                        case NO:
                                putmem(0xED);
                                putmem(0xB2);
                                continue;
                        default: error(E_INV_OP);
				    continue;
                        };
        case IND:
                switch(op1){
                        case NO:
                                putmem(0xED);
						  putmem(0xAA);
                                continue;
                        default: error(E_INV_OP);
                        continue;
                        };
        case INDR:
                switch(op1){
                        case NO:
						  putmem(0xED);
                                putmem(0xBA);
                                continue;
				    default: error(E_INV_OP);
				    continue;
				    };
	   case LD:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
									putmem(0x40|((op1-B)<<3)|(op2-B));
									continue;
								case N:
									   putmem(0x06|((op1-B)<<3));
									   putmem(_op2);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0x40|((op1-B)<<3)|6);
									   putmem(op3);
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0x40|((op1-B)<<3)|6);
									   putmem(op3);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case _HL:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case A:
								putmem(0x70|(op2-B));
									   continue;
								case N:
									   putmem(0x36);
									   putmem(_op2);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case _IX:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case A:
									   putmem(0xDD);
									   putmem(0x70|(op2-B));
									   putmem(op3);
									   continue;
								case N:
									   putmem(0xDD);
									   putmem(0x36);
									   putmem(op3);
									   putmem(_op2);


									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case _IY:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case A:
									   putmem(0xFD);
									   putmem(0x70|(op2-B));
									   putmem(op3);
									   continue;
								case N:
									   putmem(0xFD);
									   putmem(0x36);
									   putmem(op3);
									   putmem(_op2);

									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case A:
						  switch(op2){
								case B:
								case C:
								case D:
								case E:
								case H:
								case L:
								case _HL:
								case A:
								putmem(0x40|((op1-B)<<3)|(op2-B));
									   continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0x7E);
									   putmem(op3);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0x7E);
									   putmem(op3);
									   continue;
								case N:
									   putmem(0x3E);
									   putmem(_op2);
									   continue;
								case I:
									   putmem(0xED);
									   putmem(0x57);
									   continue;
								case R:
									   putmem(0xED);
									   putmem(0x5F);
									   continue;
								case _BC:
									   putmem(0x0A);
									   continue;
								case _DE:
									   putmem(0x1A);
									   continue;
								case _NN:
									   putmem(0x3A);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _N:
									   putmem(0x3A);
									   putmem(_op2);
									   putmem(0);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case I:
						  switch(op2){
								case A:
									   putmem(0xED);
									   putmem(0x47);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case R:
						  switch(op2){
								case A:
									   putmem(0xED);
									   putmem(0x4F);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case _BC:
						  switch(op2){
								case A:
									   putmem(0x02);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case _DE:
						  switch(op2){
								case A:
									   putmem(0x12);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case _NN:
						  switch(op2){
								case A:
									   putmem(0x32);
									   putmem(_op1);
									   putmem(_op1>>8);
									   continue;
								case BC:
								case DE:
								case SP:
									   putmem(0xED);
									   putmem(0x43|((op2-BC)<<4));
									   putmem(_op1);
									   putmem(_op1>>8);
									   continue;
								case HL:
									   putmem(0x22);
									   putmem(_op1);
									   putmem(_op1>>8);
									   continue;
								case IX:
									   putmem(0xDD);
									   putmem(0x22);
									   putmem(_op1);
									   putmem(_op1>>8);
									   continue;
								case IY:
									   putmem(0xFD);
									   putmem(0x22);
									   putmem(_op1);
									   putmem(_op1>>8);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case _N:
						  switch(op2){
								case A:
									   putmem(0x32);
									   putmem(_op1);
									   putmem(0);
									   continue;
								case BC:
								case DE:
								case SP:
									   putmem(0xED);
									   putmem(0x43|((op2-BC)<<4));
									   putmem(_op1);
									   putmem(0);
									   continue;
								case HL:
									   putmem(0x22);
									   putmem(_op1);
									   putmem(0);
									   continue;
								case IX:
									   putmem(0xDD);
									   putmem(0x22);
									   putmem(_op1);
									   putmem(0);
									   continue;
								case IY:
									   putmem(0xFD);
									   putmem(0x22);
									   putmem(_op1);
									   putmem(0);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case BC:
				    case DE:
						  switch(op2){
								case NN:
									   putmem(0x01|((op1-BC)<<4));
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _NN:
									   putmem(0xED);
									   putmem(0x4B|((op1-BC)<<4));
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0x01|((op1-BC)<<4));
									   putmem(_op2);
									   putmem(0);
									   continue;
								case _N:
									   putmem(0xED);
									   putmem(0x4B|((op1-BC)<<4));
									   putmem(_op2);
									   putmem(0);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case SP:
						  switch(op2){
								case NN:
									   putmem(0x31);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _NN:
									   putmem(0xED);
									   putmem(0x7B);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0x31);
									   putmem(_op2);
									   putmem(0);
									   continue;
								case _N:
									   putmem(0xED);
									   putmem(0x7B);
									   putmem(_op2);
									   putmem(0);
									   continue;
								case HL:
									   putmem(0xF9);
									   continue;
								case IX:
									   putmem(0xDD);
									   putmem(0xF9);
									   continue;
								case IY:
									   putmem(0xFD);
									   putmem(0xF9);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case HL:
						switch(op2){
								case NN:
									   putmem(0x21);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _NN:
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0x21);
									   putmem(_op2);
									   putmem(0);
									   continue;
								case _N:
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(0);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case IX:
						  switch(op2){
								case NN:
									   putmem(0xDD);
									   putmem(0x21);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _NN:
									   putmem(0xDD);
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0xDD);
									   putmem(0x21);
									   putmem(_op2);
									   putmem(0);
									   continue;
								case _N:
									   putmem(0xDD);
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(0);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case IY:
						  switch(op2){
								case NN:
									   putmem(0xFD);
									   putmem(0x21);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case _NN:
									   putmem(0xFD);
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0xFD);
									   putmem(0x21);
									   putmem(_op2);
									   putmem(0);
									   continue;
								case _N:
									   putmem(0xFD);
									   putmem(0x2A);
									   putmem(_op2);
									   putmem(0);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    default:error(E_INV_OP1);

				    continue;
				    };

	   case PUSH:
			 switch(op1){
				    case BC:
				    case DE:
				    case HL:
						  putmem(0xC5|((op1-BC)<<4));
						  continue;
				    case AF:
						   putmem(0xF5);
						   continue;
				    case IX:
						  putmem(0xDD);
						  putmem(0xE5);
						  continue;
				    case IY:
						  putmem(0xFD);
						  putmem(0xE5);
						  continue;
				    default:error(E_INV_OP);
				    continue;
				    };
	   case POP:
			 switch(op1){
				    case BC:
				    case DE:
				    case HL:
						  putmem(0xC1|((op1-BC)<<4));
						  continue;
				    case AF:
						   putmem(0xF1);
						   continue;
				    case IX:
						  putmem(0xDD);
						  putmem(0xE1);
                                continue;
                        case IY:
                                putmem(0xFD);
                                putmem(0xE1);
                                continue;
                        default:error(E_INV_OP);
                        continue;
                        };
        case EX:
                switch(op1){
				    case DE:
                                switch(op2){
                                        case HL:
                                                putmem(0xEB);
                                                continue;
                                        default:error(E_INV_OP2);
                                        continue;
                                        };
				    case HL:
                                switch(op2){
                                        case DE:
                                                putmem(0xEB);
                                                continue;
                                        default:error(E_INV_OP2);
                                        continue;
                                        };
                        case _SB:
                                switch(op2){
                                        case HL:
                                                putmem(0xE3);
									   continue;
                                        case IX:
                                                putmem(0xDD);
                                                putmem(0xE3);
                                                continue;
                                        case IY:
                                                putmem(0xFD);
									   putmem(0xE3);
                                                continue;
                                        default:error(E_INV_OP2);
                                        continue;
                                        };

                        case AF:
                                switch(op2){
								case AF_:
                                                putmem(0x08);
                                                continue;
                                        default:error(E_INV_OP2);
                                        continue;
								};
                        default:error(E_INV_OP1);

                        continue;
                        };
        case    SUB:{
			 switch(op1) {
                        case B:
                        case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0x90|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0x96);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0x96);
						  putmem(op3);
						  continue;
				    case N:
						  putmem(0xD6);
						  putmem(_op2);
						  continue;
				    default: error(E_INV_OP1);
				    continue;
				    };
				}

	   case    SBC:{
			 switch(op1) {
                        case A:
                                switch(op2){
								case B:
                                        case C:
                                        case D:
                                        case E:
								case H:
                                        case L:
                                        case _HL:
                                        case A:
                                                putmem(0x98|(op2-B));
                                                continue;
								case _IX:
									   putmem(0xDD);
									   putmem(0x9E);
									   putmem(op3);
									   continue;
								case _IY:
									   putmem(0xFD);
									   putmem(0x9E);
									   putmem(op3);
									   continue;
								case N:
									   putmem(0xDE);
									   putmem(_op2);
									   continue;

                                        default: error(E_INV_OP2);
                                        continue;
                                        };
                        case HL:
                                switch(op2){
                                        case BC:
                                        case DE:
                                        case HL:
                                        case SP:
                                                putmem(0xED);
                                                putmem(0x42|((op2-BC)<<4));
                                                continue;
                                        default: error(E_INV_OP2);
                                        continue;
                                        };
				    default: error(E_INV_OP1);
                        continue;
				    };
                    }

        case INC:
                switch(op1){
                        case B:
                        case C:
                        case D:
                        case E:
                        case H:
                        case L:
                        case _HL:
                        case A:
                                putmem(0x04|((op1-B)<<3));
                                continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0x34);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0x34);
						  putmem(op3);
						  continue;
                       case BC:
                       case DE:
                       case HL:
                       case SP:
                                putmem(0x03|((op1-BC)<<4));
                                continue;
                       case IX:
                                putmem(0xDD);
                                putmem(0x23);
                                continue;
                       case IY:
                                putmem(0xFD);
                                putmem(0x23);
						  continue;
                       default:error(E_INV_OP);
                       continue;
				   };
	   case DEC:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0x05|((op1-B)<<3));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0x35);
						  putmem(op3);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0x35);
						  putmem(op3);
						  continue;
				   case BC:
				   case DE:
				   case HL:
				   case SP:
						  putmem(0x0B|((op1-BC)<<4));
						  continue;
				   case IX:
						  putmem(0xDD);
						  putmem(0x2B);
						  continue;
				   case IY:
						  putmem(0xFD);
						  putmem(0x2B);
						  continue;
				   default:error(E_INV_OP);
				   continue;
				   };

	   case RLC:
			 switch(op1){
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
				    case A:
						  putmem(0xCB);
						  putmem(0x00|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x06);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x06);
						  continue;
                        default:error(E_INV_OP);
                        continue;
                        };
        case RL:
                switch(op1){
                        case B:
                        case C:
				    case D:
                        case E:
                        case H:
                        case L:
				    case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x10|(op1-B));
                                continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x16);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x16);
						  continue;
                        default:error(E_INV_OP);
                        continue;
                        };
	   case RRC:
                switch(op1){
                        case B:
                        case C:
                        case D:
                        case E:
                        case H:
                        case L:
                        case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x08|(op1-B));
                                continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x0E);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x0E);
						  continue;
                        default:error(E_INV_OP);
                        continue;
                        };
        case RR:
                switch(op1){
                        case B:
                        case C:
                        case D:
				    case E:
                        case H:
                        case L:
                        case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x18|(op1-B));
						  continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x1E);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x1E);
						  continue;
				    default:error(E_INV_OP);
				    continue;
                        };
        case SLA:
                switch(op1){
                        case B:
                        case C:
				    case D:
                        case E:
                        case H:
                        case L:
				    case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x20|(op1-B));
                                continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x26);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x26);
						  continue;
                        default:error(E_INV_OP);
                        continue;
                        };
	   case SRA:
                switch(op1){
                        case B:
                        case C:
                        case D:
                        case E:
				    case H:
                        case L:
                        case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x28|(op1-B));
                                continue;
				    case _IX:
						  putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x2E);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x2E);
						  continue;
				    default:error(E_INV_OP);
                        continue;
                        };
        case SRL:
                switch(op1){
                        case B:
                        case C:
                        case D:
                        case E:
                        case H:
                        case L:
				    case _HL:
                        case A:
                                putmem(0xCB);
                                putmem(0x38|(op1-B));
						  continue;
                        case _IX:
                                putmem(0xDD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x3E);
						  continue;
				    case _IY:
						  putmem(0xFD);
						  putmem(0xCB);
						  putmem(op3);
						  putmem(0x3E);
						  continue;
                        default:error(E_INV_OP);
                        continue;
                        };
	   case IM:
			 switch(_op1){
				    case 0:
						  putmem(0xED);
						  putmem(0x46);
						  continue;
				    case 1:
						  putmem(0xED);
						  putmem(0x56);
						  continue;
				    case 2:
						  putmem(0xED);
						  putmem(0x5E);
						  continue;
				    default:error(E_INV_OP);
                        continue;
                        };
	   case RET:
                switch(op1){
                        case NO:
						  putmem(0xC9);
                                continue;
                        case _Z:
                        case _NZ:
				    case _NC:
				    case _PO:
				    case _PE:
				    case _P:
				    case _M:
						  putmem(0xC0|((op1-_NZ)<<3));
						  continue;
				    case C:
						  putmem(0xD8);
						  continue;
				    default:error(E_INV_OP);

				    continue;
				    };

	   case RST:
			 switch(_op1){
				    case 0:
				    case 8:
				    case 16:
				    case 24:
				    case 32:
				    case 40:
				    case 48:
				    case 56:
						 putmem(0xC7|_op1);
						 continue;
				    default:error(E_INV_OP);
				    continue;
				    };
	   case DJNZ:
			 switch(op1){
				    case N:
				    case NN:
						  putmem(0x10);
						  putmem(_op1-PC-1);
						  continue;
				    default:error(E_INV_OP);
				    continue;
				    };

	   case JR:
			 switch(op1){
				    case N:
				    case NN:
						  putmem(0x18);
						  putmem(_op1-PC-1);
						  continue;
				    case _Z:
				    case _NZ:
				    case _NC:
						  switch(op2){
								case N:
								case NN:
									   putmem(0x20|((op1-_NZ)<<3));
									   putmem(_op2-PC-1);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
					case C:
						   switch(op2){
								case N:
								case NN:
									   putmem(0x38);
									   putmem(_op2-PC-1);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    default: error(E_INV_OP1);
				    continue;
				    };

	   case    JP:
			 switch(op1){
				    case NN:
						  putmem(0xC3);
						  putmem(_op1);
						  putmem(_op1>>8);
						  continue;
				    case N:
						  putmem(0xC3);
						  putmem(_op1);
						  putmem(0);
						  continue;
				    case _Z :
				    case _NZ :
				    case _NC:
				    case _PO:
				    case _PE:
				    case _P :
				    case _M :
						  switch(op2){
								case NN:
									   putmem(0xC2|((op1-_NZ)<<3));
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0xC2|((op1-_NZ)<<3));
									   putmem(_op2);
									   putmem(0);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};
				    case C:
						  switch(op2){
								case NN:
									   putmem(0xDA);
									   putmem(_op2);
									   putmem(_op2>>8);
									   continue;
								case N:
									   putmem(0xDA);
									   putmem(_op2);
									   putmem(0);
									   continue;
								default: error(E_INV_OP2);
								continue;
								};

				    case _HL:
								   putmem(0xE9);
								   continue;
				    case _IX:
								   putmem(0xDD);
								   putmem(0xE9);
								   continue;
				    case _IY:
								   putmem(0xFD);
								   putmem(0xE9);
								   continue;
				    default: error(E_INV_OP1);
				    continue;
				    };

	   case IN:
			 switch(op1){
				    case A:
						  switch(op2){
								case _N:
									   putmem(0xDB);
									   putmem(_op2);
									   continue;
								case _CC:
									   putmem(0xED);
									   putmem(0x78);
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
				    case _HL:
						  switch(op2){
								case _CC:
									   putmem(0xED);
									   putmem(0x40|((op1-B)<<3));
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    default:error(E_INV_OP1);
				    continue;
				    };
	   case OUT:
			 switch(op2){
				    case A:
						  switch(op1){
								case _N:
									   putmem(0xD3);
									   putmem(_op1);
									   continue;
								case _CC:
									   putmem(0xED);
									   putmem(0x79);
									   continue;
								default:error(E_INV_OP1);
								continue;
								};
				    case B:
				    case C:
				    case D:
				    case E:
				    case H:
				    case L:
						  switch(op1){
								case _CC:
									   putmem(0xED);
									   putmem(0x41|((op2-B)<<3));
									   continue;
								default:error(E_INV_OP2);
								continue;
								};
				    default:error(E_INV_OP1);
				    continue;
				    };
	   case DEFB:
			 switch(op1){
				    case N:
						  putmem(_op1);
						  continue;
				    default:error(E_INV_OP);
				    continue;
				    };
	   case DEFW:
			 switch(op1){
				    case NN:
						  putmem(_op1);
						  putmem(_op1>>8);
						  continue;
				    case N:
						putmem(_op1);
						putmem(0);
						continue;
				    default:error(E_INV_OP);
				    continue;
				    };
	   case DEFM:
			switch(op1){
				case N:
				case NN:
					PC+=_op1;
					continue;
					};

	   case ORG:
			 switch(op1){
				    case NN:
				    case N:
						  PC=_op1;
						  continue;
				    };
	   case EQU:
		if(PASS==1)
			switch(op1){
				case N:
				case NN:
					{
					int i;
					lbltbl.check(label);
					lbltbl.put(label,_op1);
					break;
					};
				default:error(E_INV_OP1);
				continue;
				};
		break;

	   default:error(E_UND_CMD);
	   continue;
	   };    // End of Main switch
	} while(0);
};

void putmem(char c){
memory[PC++]=c;
if(PC==65535) {
	   printf("\nOut Of Memory !");
	   exit(1);
	   };
};
