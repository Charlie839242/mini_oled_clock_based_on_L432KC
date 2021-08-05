# mini_oled_clock_based_on_L432KC
The oled screen can display time, humidity and temperature on the basis of a multi-thread OS, RT-Thread.

![image](https://github.com/Charlie839242/mini_oled_clock_based_on_L432KC/blob/main/video/mini_oled_clock.gif)

  5 things were used: L432KC, SHT30(Temeprature Sensor), ESP8266(WIFI modular), OLED screen(1306 driver), CH340(UART communication with computer)  
	1.SHT30：  
		SHT30 communicates through I2C. occupying the I2C1 on L432KC.  
		That is, the sda of SHT30 connects to PB7(D4),scl connects to PB6(D5).      	
	2.CH340:  
		CH340 occuplys UART1 on L432KC.  
		That is, RXD connetcs to PA9(D1)，TXD connects to PA10(D0).  
	3.ESP8266：  
		ESP8266 communicates through UART，occupying the UART2 on L432KC.  
		That is, TXD connects to PA3(A2)，RXD connects to PA2(A7)。  
	4.OLED screen：  
		OLED communicates through I2C，occupying the I2C3 on L432KC.  
		That is, sda connects to PB4(D12)，scl connects to PA7(A6).  
    
# How to use
  The 'application' folder is where codes are written.
  
  Open the BSP folder by 'RT-Thread Studio'. To run it on your own L432KC or other things, there is one thing that should be modified before compiling and downloading.  
    1.Configure the ESP8266.  
      Since a new WIFI is used, some information about the WIFI name and WIFI code should be updated.  
      Click RT-Thread Settings. See tlhe packages and find "at_device". Go to the configuration of the "at_device" and you will the place to update the information.  
      
  Then compile and download it in L432KC.
  
