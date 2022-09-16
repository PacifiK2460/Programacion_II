#include <stdio.h>

int main(){
    // Given start and end time print the duration of the game
    int startHour, endHour;
    scanf("%d %d", &startHour, &endHour);
    if(startHour > endHour)
        printf("%d", (24 - startHour) + endHour);
    else if(startHour < endHour)
        printf("%d", endHour - startHour);
    else if(startHour == endHour)
        printf("%d", 24);

}