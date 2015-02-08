#define GPBCON      (*(volatile unsigned long *)0x56000010)
#define GPBDAT      (*(volatile unsigned long *)0x56000014)

#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

#define GPGCON      (*(volatile unsigned long *)0x56000060)
#define GPGDAT      (*(volatile unsigned long *)0x56000064)

/*
 * LED1-4对应GPB5、GPB6、GPB7、GPB8
 */
#define GPB5_out        (1<<(5*2))
#define GPB6_out        (1<<(6*2))
#define GPB7_out        (1<<(7*2))
#define GPB8_out        (1<<(8*2))

/*
 * K1-K4对应GPG11、GPG3、GPF2、GPF0
 */
#define GPG11_in    ~(3<<(11*2))
#define GPG3_in     ~(3<<(3*2))
#define GPF2_in     ~(3<<(2*2))
#define GPF0_in     ~(3<<(0*2))

int main()
{
        unsigned long dwDat;
        // LED1-LED4对应的4根引脚设为输出
        GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out ;

        // K1-K2对应的2根引脚设为输入
        GPGCON = GPG11_in & GPG3_in ;
        
        // K3-K4对应的2根引脚设为输入
        GPFCON = GPF2_in & GPF0_in ;

        while(1){
            //若Kn为0(表示按下)，则令LEDn为0(表示点亮)
            dwDat = GPGDAT;             // 读取GPG管脚电平状态
        
            if (dwDat & (1<<11))        // K1没有按下
                GPBDAT |= (1<<5);       // LED1熄灭
            else    
                GPBDAT &= ~(1<<5);      // LED1点亮
                
            if (dwDat & (1<<3))         // K2没有按下
                GPBDAT |= (1<<6);       // LED2熄灭
            else    
                GPBDAT &= ~(1<<6);      // LED2点亮
    
            dwDat = GPFDAT;             // 读取GPF管脚电平状态
            
            if (dwDat & (1<<2))         // K3没有按下
                GPBDAT |= (1<<7);       // LED3熄灭
            else    
                GPBDAT &= ~(1<<7);      // LED3点亮
    
            if (dwDat & (1<<0))         // K4没有按下
                GPBDAT |= (1<<8);       // LED4熄灭
            else    
                GPBDAT &= ~(1<<8);      // LED4点亮
    }

    return 0;
}
