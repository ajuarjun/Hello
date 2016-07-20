//General Menu structure for any program using kbhit

int8 selectTopMenu(void)
{
   char data_in;
   int8 cmd;
   int16 tempVal,ii;

//   disable_interrupts(INT_RDA);
//   clear_interrupt(INT_RDA);
    
   while(1)
   {
      fprintf(SERIAL_ADAPTER, "\r\nTest Menu\r\n");   
      fprintf(SERIAL_ADAPTER, "0. \r\n");
      fprintf(SERIAL_ADAPTER, "1. \r\n");
      fprintf(SERIAL_ADAPTER, "2. \r\n");
      fprintf(SERIAL_ADAPTER, "3. \r\n");
      fprintf(SERIAL_ADAPTER, "4. \r\n");
      fprintf(SERIAL_ADAPTER, "5. \r\n");
      fprintf(SERIAL_ADAPTER, "6. \r\n");
      fprintf(SERIAL_ADAPTER, "7. \r\n");
      fprintf(SERIAL_ADAPTER, "8. \r\n");    
      fprintf(SERIAL_ADAPTER, "9. \r\n");
      fprintf(SERIAL_ADAPTER, "A. \r\n");
      fprintf(SERIAL_ADAPTER, "B. \r\n");
      fprintf(SERIAL_ADAPTER, "C. \r\n");      
      fprintf(SERIAL_ADAPTER, "D. \r\n");
      fprintf(SERIAL_ADAPTER, "E. \r\n");
      fprintf(SERIAL_ADAPTER, "F. \r\n");
      fprintf(SERIAL_ADAPTER, "G. \r\n");
      fprintf(SERIAL_ADAPTER, "H. \r\n");
      
      fprintf(SERIAL_ADAPTER, "x.  Return to Main Program\r\n");

      while(1)
      {
          while( !kbhit(SERIAL_ADAPTER));
          data_in = fgetc(SERIAL_ADAPTER);
          //cmd = data_in-0x30;
          cmd = data_in;
          fprintf(SERIAL_ADAPTER,"Selected %c\r\n",data_in);
          if( (cmd>='0' && cmd<='9') || (cmd>='A' && cmd<='H') || cmd=='x') break;
            else fprintf(SERIAL_ADAPTER,"invalid selection, select again\r\n");
      }
      switch(cmd)
      {
            case '0':   //
               fprintf(SERIAL_ADAPTER, "\r\nSELECTED 0: \r\n");
               //OUTPUT_LOW(ENABLE_MAXON);
               motorSetting=0;
               break; 
            case '1':   //
               fprintf(SERIAL_ADAPTER, "\r\nSELECTED 1: \r\n");               
               OUTPUT_HIGH(ENABLE_MAXON);
               break; 
            case '2':   //
               fprintf(SERIAL_ADAPTER, "\r\nSELECTED 2: \r\n");               
               OUTPUT_LOW(DIRECTION_MAXON);
               break;
            case '3':   //
               fprintf(SERIAL_ADAPTER, "\r\nSELECTED 3: \r\n");               
               OUTPUT_HIGH(DIRECTION_MAXON);
               break;
            case '4':   //
               fprintf(SERIAL_ADAPTER, "\r\nSELECTED 4: \r\n");               
               motorSetting=0;
               //fprintf(SERIAL_ADAPTER, "MOTOR SETTING = %ld\r\n",motorSetting);               
               dacWrite(motorSetting);
               break;
            case '5':   //
               break;
            case '6':   //
               break;
            case '7':   //
               break;
            case '8':   //Read Voltage In
               set_adc_channel(3);
               delay_us(100);
               tempVal=read_adc();
               //tempVal=temVal*some factor                            //MIK
               fprintf(SERIAL_ADAPTER, "\n\rRead Input Voltage\r\n");
               fprintf(SERIAL_ADAPTER,"Vin=%f VDC, Counts=%ld\r\n",tempVal*0.041436,tempVal);
					updateVoltageIn();
               fprintf(SERIAL_ADAPTER,"Vin=%f VDC  Calulated from updateCurrent function\r\n",voltageIn);   				               
               break;  
            case '9':   //Read Current In                                 //MIK - hardware not implemented - do I have the parts?
               set_adc_channel(0);
               delay_us(100);
               tempVal=read_adc();                          
               //tempVal=temVal*some factor                              //MIK
               fprintf(SERIAL_ADAPTER,"Iin=%f A, Counts=%ld\r\n",tempVal*0.002976,tempVal);   //Real calc. value = 1/328.25, calibrated value = 1/344.37, used mid value
               updateCurrentIn();
               fprintf(SERIAL_ADAPTER,"Iin=%f A  Calulated from updateCurrent function\r\n",currentIn);   //Real calc. value = 1/328.25, calibrated value = 1/344.37, used mid value
               break;
            case 'A':   //
               break;    
            case 'B':   //Read Temperature
               fprintf(SERIAL_ADAPTER,"Temperature = %f deg C\r\n",getTemperature());          
               break;
            case 'C':   //
               break;
            case 'D':   //
               break;
            case 'E':   //
               break;
            case 'F':	//
               break;
            case 'G':	//
               break;      		               
            case 'H':	//
               break;         		               
            case 'x':   //break
               fprintf(SERIAL_ADAPTER,"Exit from menu\r\n");
               delay_ms(10);
               return('x');
               break;
            default:
               fprintf(SERIAL_ADAPTER,"Invalid Input\r\n");
               break;         
      }
   }                 
}
