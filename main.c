#include "frameManager.h"
#include "getKey.h"

int main(void) {
        //Set map size
        setSize(15, 5);
        setPlayerLocation(9 ,2);
        setPlayerDesign('P');
        setLineDesign('#');
        setObject1(10 ,2 ,'1');
        setObject2(10 ,3 ,'2');
        scoreBoard(0, 0);
        frameUpdate();

        /*
         * getKey(); usage:
         *      char key = getKey();
         * Gives back the pressed key into char key;
         */
}