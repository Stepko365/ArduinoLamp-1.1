uint32_t effTimer;
byte ind;
void effectsTick() {
  {
    if (ONflag && millis() - effTimer >= ((currentMode < 2 || currentMode > 9) ? modes[currentMode].Speed : 50) ) {
      effTimer = millis(); switch (currentMode) {
        //|номер   |название функции эффекта     |тоже надо|
        case 0 : sparklesRoutine();             break;
        case 1 : RainbowRoutine();              break;
        case 2 : fireRoutine();                 break;
        case 3 : LavaLampRoutine();             break;
        case 4 : PrismataRoutine();             break;
        case 5 : MetaBallsRoutine();            break;
        case 6 : madnessNoise();                break;
        case 7 : noise3D();                     break;
        case 8 : whiteLampRoutine();            break;
        case 9 : colorRoutine();                break;
        case 10: colorsRoutine();               break;
        case 11: matrixRoutine();               break;
        case 12: snowRoutine();                 break;
        case 13: stormRoutine();                break;
        case 14: ballRoutine();                 break;
        case 15: ballsRoutine();                break;
        case 16: MunchRoutine();                break;


      }
#ifdef INDICATOR
      switch (numHold) {    // индикатор уровня яркости/скорости/масштаба
        case 1:
          ind = sqrt(modes[currentMode].Brightness + 1);
          for (byte y = 0; y < HEIGHT ; y++) {
            if (ind > y) drawPixelXY(0, y, CHSV(10, 255, 255));
            else drawPixelXY(0, y,  0);
          }
          break;
        case 2:
          ind = sqrt(modes[currentMode].Speed - 1);
          for (byte y = 0; y <= HEIGHT ; y++) {
            if (ind <= y) drawPixelXY(0, 15 - y, CHSV(100, 255, 255));
            else drawPixelXY(0, 15 - y,  0);
          }
          break;
        case 3:
          ind = sqrt(modes[currentMode].Scale + 1);
          for (byte y = 0; y < HEIGHT ; y++) {
            if (ind > y) drawPixelXY(0, y, CHSV(150, 255, 255));
            else drawPixelXY(0, y,  0);
          }
          break;
#endif
      }
      FastLED.show();
    }
  }
}

void changePower() {    // плавное включение/выключение
  if (ONflag) {
    effectsTick();
    for (int i = 0; i < modes[currentMode].Brightness; i += 8) {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    FastLED.setBrightness(modes[currentMode].Brightness);
    delay(2);
    FastLED.show();
  } else {
    effectsTick();
    for (int i = modes[currentMode].Brightness; i > 8; i -= 8) {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    memset8( leds, 0, NUM_LEDS * 3);
    delay(2);
    FastLED.show();
  }
}

 void demoTick(){
  if (isDemo && ONflag && millis() >= DemTimer){
    if(RANDOM_DEMO)
    currentMode = random8(MODE_AMOUNT); // если нужен следующий случайный эффект
    else 
    currentMode = currentMode + 1U < MODE_AMOUNT ? currentMode + 1U : 0U; // если нужен следующий по списку эффект
    memset8( leds, 0, NUM_LEDS * 3);
    DemTimer = millis() + DEMOTIMELIMIT;
    loadingFlag = true;}
}
