int ENA = 5;              
int ENB = 6;              
int IN1 = A4;              
int IN2 = 12;  
int IN3 = 8;              
int IN4 = 4;      
int t = 20;
        
void setup() 
{
  pinMode(ENA,OUTPUT);    
  pinMode(ENB,OUTPUT);    
  pinMode(IN1,OUTPUT);    
  pinMode(IN2,OUTPUT);   
  pinMode(IN3,OUTPUT);    
  pinMode(IN4,OUTPUT);   
  digitalWrite(ENA,1);   
  digitalWrite(ENB,1);   
}

void loop()               //死循环体
{
 digitalWrite(IN1,0);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,1);  
 delay(t);  
            
 digitalWrite(IN1,0);  
 digitalWrite(IN2,0);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,1);  
 delay(t);  
            
 digitalWrite(IN1,1);  
 digitalWrite(IN2,0);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,1);  
 delay(t);  
            
 digitalWrite(IN1,1);  
 digitalWrite(IN2,0);  
 digitalWrite(IN3,0);  
 digitalWrite(IN4,1);  
 delay(t);  
 
 digitalWrite(IN1,1);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,0);  
 digitalWrite(IN4,1);  
 delay(t);  
            
 digitalWrite(IN1,1);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,0);  
 digitalWrite(IN4,0);  
 delay(t);
   
 digitalWrite(IN1,1);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,0);  
 delay(t);  
            
 digitalWrite(IN1,0);  
 digitalWrite(IN2,1);  
 digitalWrite(IN3,1);  
 digitalWrite(IN4,0);  
 delay(t);  
           
}
