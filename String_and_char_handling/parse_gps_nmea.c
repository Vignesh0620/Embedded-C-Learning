/*Parse GPS String for Time and Coordinates
You are given a $GPRMC NMEA string from a GPS module in the following simplified format:

$GPRMC,<time>,<status>,<lat>,<NS>,<long>,<EW>,...
Your task is to:

Extract and print:
 
UTC time in HH:MM:SS format (first field after $GPRMC)
Latitude with direction (lat NS) : NS- North South
Longitude with direction (long EW) : EW- East West
Assume:

Input will always follow this format
You only need to extract and print the first 7 fields
Do not validate checksum or GPS fix status
 
Example-1

Input:
$GPRMC,123519,A,4807.038,N,01131.000,E
Output:
Time: 12:35:19  
Latitude: 4807.038 N  
Longitude: 01131.000 E

Example-2

Input:
$GPRMC,083559,A,3745.678,N,12227.890,W
Output:
Time: 08:35:59  
Latitude: 3745.678 N  
Longitude: 12227.890 W
*/


#include <stdio.h>
#include <string.h>

void parse_gprmc(char *nmea) {
    // Your logic here
    char *fields[7];
    int index=0;

    char *token = strtok(nmea,",");
    while(token != NULL  && index<7)
    {
        fields[index++]=token;
        token=strtok(NULL,",");
    }

    //Extract time values from fields[]
    char *t=fields[1];
    printf("Time: %.2s:%.2s:%.2s\n",t,t+2,t+4);

    //Latitude
    printf("Latitude: %s %s\n",fields[3],fields[4]);

    //Longitude
    printf("Longitude: %s %s\n",fields[5],fields[6]);
}

int main() {
    char nmea[100];
    fgets(nmea, sizeof(nmea), stdin);
    parse_gprmc(nmea);
    return 0;
}