#include "helper.h"

Helper::Helper()
{
    hexList << "0" << "1" << "2" << "3" << "4" << "5" << "6" <<
                       "7" << "8" << "9" << "A" << "B" << "C" <<
                       "D" << "E" << "F";
};


/***
    Helper *helper = new Helper();
    QString convertito = helper->decToHex(toConvert);
 */
QString Helper::decToHex(int decimal) const {
    QString hexVal = "";
    while (decimal > 15) {
        int rest = decimal % 16;
        decimal = decimal / 16;
        hexVal = Helper::hexList.at(rest) + hexVal;
    }
    hexVal = Helper::hexList.at(decimal) + hexVal;
    return hexVal;
}
