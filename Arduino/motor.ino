int ENA = 5;              
int ENB = 6;              
int IN1 = A4;              
int IN2 = 12;              
int IN3 = 8;              
int IN4 = 4;    

void setup() 
{
  pinMode(ENA,OUTPUT);    
  pinMode(ENB,OUTPUT);    
  pinMode(IN1,OUTPUT);    
  pinMode(IN2,OUTPUT);   
  pinMode(IN3,OUTPUT);    
  pinMode(IN4,OUTPUT);   
  analogWrite(ENA,160);   
  analogWrite(ENB,160);   
}

void loop()               //死循环体
{
 digitalWrite(IN1,1);  
 digitalWrite(IN2,0);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,0);  
 delay(5000);  
         
 digitalWrite(IN1,0);  
 digitalWrite(IN2,0);  
 digitalWrite(IN3,0);  
 digitalWrite(IN4,0);  
 delay(2000);          
    
 digitalWrite(IN1,0);  
 digitalWrite(IN2,1);    
 digitalWrite(IN3,0);  
 digitalWrite(IN4,1);    
 delay(5000);   
 
 digitalWrite(IN1,1);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,1);  
 delay(2000);   
           
}
