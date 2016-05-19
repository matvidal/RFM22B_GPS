#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Instancia singleton del driver de la radio.
RH_RF22 driver(4,2);

// La clase que maneja el envio y recibo de mensajes, usando el driver
// declarado arriba.
RHReliableDatagram rf22(driver, CLIENT_ADDRESS);

uint8_t data[RH_RF22_MAX_MESSAGE_LEN];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
uint8_t randomData[10][256];
int i, j, k, counter, aciertos, msn_size, aciertosTotales, msgsTotales;

/**
 * Se inicializa el transceiver y se selecciona el flag, la frecuencia,
 * y el CRC.
 */
void setup() {
    SerialUSB.begin(38400);
    pinMode(10, OUTPUT);
    digitalWrite(10, LOW);
    driver.setCRCPolynomial(driver.CRC_CCITT);
    if (!rf22.init())
        SerialUSB.println("Fallo la inicializacion");

    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    
    delay(2000);
    aciertosTotales = 0;
    
    SerialUSB.println("Communication test");

    SerialUSB.println("Set configuration = FSK_Rb2Fd5");
 
    fixedPowerTest();    

    SerialUSB.print("\n Aciertos totales: ");
    SerialUSB.print(aciertosTotales);
    SerialUSB.print(" de ");
    SerialUSB.print(k*10);
    
} 

void loop() { 
    
}

/**
 * Genera 10 paquetes de 255 bytes de numeros aleatorios.
 */
void generateRandomData() {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < RH_RF22_MAX_MESSAGE_LEN; j++){
            randomData[i][j] = random(0,255);   
        }        
    }
}
/**
 * Esta funcion envia un total de 1000 paquetes de 255 bytes cada
 * uno con numeros aleatorios de 0 a 255. Ademas, selecciona un
 * maximo de 3 reintentos por paquete y escoge la potencia maxima
 * de salida (20 dBm).
 * En caso de existir un error al escoger el tipo de modulacion,
 * se imprime un mensaje de error en pantalla.
 * Cada 10 mensajes se muestra cuantos de ellos han llegado
 * exitosamente e imprime cuantos de los enviados hasta ese
 * momento han llegado.
 */
void fixedPowerTest() {
    rf22.setRetries(3);
    driver.setTxPower(RH_RF22_TXPOW_20DBM);    
    SerialUSB.println("Set Tx Power = RH_RF22_TXPOW_20DB");
    if (driver.setModemConfig(driver.FSK_Rb2Fd5)) { 
        for (k = 0; k < 100; k++) {
            generateRandomData();
            for (i = 0; i < 10; i++) {
                for (j = 0; j < RH_RF22_MAX_MESSAGE_LEN; j++) {
                    data[j] = randomData[i][j];
                }
                enviar(data, RH_RF22_MAX_MESSAGE_LEN);    
            }
            msgsTotales += 10;
            aciertosTotales += aciertos; 
            SerialUSB.print("   Aciertos: ");
            SerialUSB.print(aciertos);
            SerialUSB.print(" de ");
            SerialUSB.print(i);
            SerialUSB.print("       Aciertos parciales: ");
            SerialUSB.print(aciertosTotales);
            SerialUSB.print(" de ");
            SerialUSB.println(msgsTotales);
            SerialUSB.print("\n");  
            aciertos = 0; 
        }   
        
    }
    else {
        SerialUSB.println("Error de configuracion");
    }
}
/**
 * Esta funcion envia un paquete al servidor y luego espera una
 * confirmacion, si no llega imprime un error en pantalla. Si
 * llega, espera el reenvio del mismo paquete para compararlo
 * con el enviado, sumando a un contador.
 * @param data[] Datos enviados al servidor.
 * @param data_size Tamano del paquete enviado.
 */
void enviar(uint8_t data[], int data_size) {
    if (rf22.sendtoWait(data, data_size, SERVER_ADDRESS)) {
        uint8_t len = sizeof(buf);
        uint8_t from;  
        if (rf22.recvfromAckTimeout(buf, &len, 2000, &from)) {

            for (j = 0; j < data_size; j++) {
                counter += (data[j] == buf[j]);
            }
            
            aciertos += (counter == data_size);
            counter = 0; 

        }
        else {
            SerialUSB.println("Fallo el eco");
        }
    }
    else {
      SerialUSB.println("Fallo la confirmacion");
    }
}
