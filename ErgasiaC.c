#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ip_address_len 16 // Length of the IP address string

// Function to convert decimal to binary
char* decimal_to_binary(int decimal) {
    static char binary[9];
    int i;
    for (i = 7; i >= 0; i--) {
        binary[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binary[8] = '\0';
    return binary;
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0, i, power = 1;
    int len = strlen(binary);
    for (i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main(){
	//Create a 16 - long char storage for the ip
    char ip_address[ip_address_len],choice[2];
    int decimal;
    printf("Enter an IP address (binary or decimal): ");
    fgets(ip_address,sizeof(ip_address),stdin);
   
    // Check if the input is binary or decimal
	    if (strlen(ip_address) == 8) {
	        // Input is binary
	        decimal = binary_to_decimal(ip_address);
	        printf("The decimal representation of %s is %d\n", ip_address, decimal);
    }else{
        // Input is decimal
        decimal = atoi(ip_address);
        printf("The binary representation of %d is %s\n", decimal, decimal_to_binary(decimal));
    }
    return 0;
}
