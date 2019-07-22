FFFFFFFFFFFFFFFFFFFFFFlllllll                                          SSSSSSSSSSSSSSS IIIIIIIIIIMMMMMMMM               MMMMMMMM
F::::::::::::::::::::Fl:::::l                                        SS:::::::::::::::SI::::::::IM:::::::M             M:::::::M
F::::::::::::::::::::Fl:::::l                                       S:::::SSSSSS::::::SI::::::::IM::::::::M           M::::::::M
FF::::::FFFFFFFFF::::Fl:::::l                                       S:::::S     SSSSSSSII::::::IIM:::::::::M         M:::::::::M
  F:::::F       FFFFFF l::::l     eeeeeeeeeeee  xxxxxxx      xxxxxxxS:::::S              I::::I  M::::::::::M       M::::::::::M
  F:::::F              l::::l   ee::::::::::::ee x:::::x    x:::::x S:::::S              I::::I  M:::::::::::M     M:::::::::::M
  F::::::FFFFFFFFFF    l::::l  e::::::eeeee:::::eex:::::x  x:::::x   S::::SSSS           I::::I  M:::::::M::::M   M::::M:::::::M
  F:::::::::::::::F    l::::l e::::::e     e:::::e x:::::xx:::::x     SS::::::SSSSS      I::::I  M::::::M M::::M M::::M M::::::M
  F:::::::::::::::F    l::::l e:::::::eeeee::::::e  x::::::::::x        SSS::::::::SS    I::::I  M::::::M  M::::M::::M  M::::::M
  F::::::FFFFFFFFFF    l::::l e:::::::::::::::::e    x::::::::x            SSSSSS::::S   I::::I  M::::::M   M:::::::M   M::::::M
  F:::::F              l::::l e::::::eeeeeeeeeee     x::::::::x                 S:::::S  I::::I  M::::::M    M:::::M    M::::::M
  F:::::F              l::::l e:::::::e             x::::::::::x                S:::::S  I::::I  M::::::M     MMMMM     M::::::M
FF:::::::FF           l::::::le::::::::e           x:::::xx:::::x   SSSSSSS     S:::::SII::::::IIM::::::M               M::::::M
F::::::::FF           l::::::l e::::::::eeeeeeee  x:::::x  x:::::x  S::::::SSSSSS:::::SI::::::::IM::::::M               M::::::M
F::::::::FF           l::::::l  ee:::::::::::::e x:::::x    x:::::x S:::::::::::::::SS I::::::::IM::::::M               M::::::M
FFFFFFFFFFF           llllllll    eeeeeeeeeeeeeexxxxxxx      xxxxxxx SSSSSSSSSSSSSSS   IIIIIIIIIIMMMMMMMM               MMMMMMMM
// By bmgjet 2019
//
// Description: ThisPin(D6) outputs 2 different duty cycles for ethanol 10 and 99%.
//              Also cycles up and down of the tempture scale
//

const int thisPin = 6;
void setup() {
    pinMode(thisPin, OUTPUT);
}

void loop() {
  
      setPwmFrequency(thisPin, 256);
      //10% scale
      //194 <- 0
      int i = 194;
      while (i != 0)
      {
       analogWrite(thisPin, i);
      i--;
      delay(20);
      }
      
            
      setPwmFrequency(thisPin, 1024);
      //99% scale
      //240 -> 171
      i = 170;
      while (i <= 240)
      {
       analogWrite(thisPin, i);
      i++;
      delay(5);
      }
      
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
