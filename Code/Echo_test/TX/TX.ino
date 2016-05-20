#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 10;
uint8_t data[RH_RF22_MAX_MESSAGE_LEN];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
uint8_t randomData[10][255];
int i, j, k, counter, aciertos, msn_size, aciertosTotales, msgsTotales;

// Singleton instance of the radio driver.
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, CLIENT_ADDRESS);

/**
 * The transceiver is initialized and some parameters are selected,
 */
void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(1500);
    if (!rf22.init()) {
        Serial.println("Fallo la inicializacion");
    }
    Serial.println("Echo test (TX)");
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 

    aciertosTotales = 0;

    Serial.println("Set configuration = FSK_Rb2Fd5");
 
    Test();    

    Serial.print("\n Aciertos totales: ");
    Serial.print(aciertosTotales);
    Serial.print(" de ");
    Serial.print(k*10);
    
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
void Test() {
    rf22.setRetries(3);
    driver.setTxPower(RH_RF22_TXPOW_20DBM);    
    Serial.println("Set Tx Power = RH_RF22_TXPOW_20DB");
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
            Serial.print("   Aciertos: ");
            Serial.print(aciertos);
            Serial.print(" de ");
            Serial.print(i);
            Serial.print("       Aciertos parciales: ");
            Serial.print(aciertosTotales);
            Serial.print(" de ");
            Serial.println(msgsTotales);
            Serial.print("\n");  
            aciertos = 0; 
        }   
        
    }
    else {
        Serial.println("Error de configuracion");
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
            Serial.println("Fallo el eco");
        }
    }
    else {
      Serial.println("Fallo la confirmacion");
    }
}
