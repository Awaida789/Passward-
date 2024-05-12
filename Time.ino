void timer(){
     countdown=15;
  while (countdown>=0) {
    lcd.setCursor(0, 0); 
    lcd.print("Try again in:");
    lcd.print(countdown);
    lcd.print("s");
    lastUpdateTime = currentTime; 
    countdown--;
    // Check if countdown reaches 0, reset it
delay(1000);
    }
      countdown = 15;
      i = 0;
      delay(1000);
      lcd.clear();
    }
    
