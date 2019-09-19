/*
 * pino=> define o pino que o sensor esta connetado
 * v0=> voltagem entre o termometro e o resistor
 * n=> número de massas, na temperatura ideal
 * logR2=> calcula o logaritmo de r2
 * r2=> resistência do termometro
 * t=> pressão sobe o sensor (temperatura)
 * tc=> temperatura, convertida em graus celsius
 * r1=> valor do resistor
 * 
 */
int pino = 0, vo, n=0;
float logR2, r2, t, tc, r1 = 10000, c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {
  while(n<25){
    vo = analogRead(pino);
    r2 = r1 * (1023.0 / (float)vo - 1.0);
    logR2 = log(r2);
    t = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    tc = t - 273.15; 

    if(tc>=26 && tc<=27){
       n++;
    }
    
    Serial.print("Temperatura: "); 
    Serial.print(tc);
    Serial.println(" C");
    Serial.print("Massas prontas: ");
    Serial.println(n);  

     if(n==25){
      Serial.println("Forno cheio, aguarde as próximas massas.");
     }
  
    delay(2000);
  }
}
