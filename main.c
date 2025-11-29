#include <unistd.h>

#include "frameManager.h"
#include "getKey.h"

int main(void) {
    setSize(15, 5);
    setPlayerLocation(5 ,2);
    setPlayerDesign('P');
    setLineDesign('#');
    setObject1(10 ,2 ,'1');
    setObject2(10 ,3 ,'2');
    scoreBoard(1 , 1000);
    frameUpdate();
    return 5;
}