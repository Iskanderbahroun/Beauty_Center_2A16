#include "qrcode.h"

class QRCODEData : public QSharedData
{
public:

};

QRCODE::QRCODE() : data(new QRCODEData)
{

}

QRCODE::QRCODE(const QRCODE &rhs) : data(rhs.data)
{

}

QRCODE &QRCODE::operator=(const QRCODE &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

QRCODE::~QRCODE()
{

}
