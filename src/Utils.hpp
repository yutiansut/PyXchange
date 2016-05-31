/**
 * @brief This module implements simulator of exchange
 * @file Utils.hpp
 *
 */

#ifndef UTILS
#define UTILS

#include "PyXchangeFwd.hpp"


namespace pyxchange
{


namespace log
{

const std::string debug     = "debug";
const std::string info      = "info";
const std::string warning   = "warning";
const std::string error     = "error";

} /* namespace log */


namespace message
{

const std::string createOrder        = "createOrder";
const std::string cancelOrder        = "cancelOrder";
const std::string executionReport    = "executionReport";
const std::string orderBook          = "orderbook";

} /* namespace message */


namespace format
{

const boost::format clientDoesNotExist( "Client %|| does not exists" );
const boost::format traderDoesNotExist( "Trader %|| does not exists" );
const boost::format traderAddedOrder( "Trader %|| added %|| order id %|| at price %|| of quantity %||" );
const boost::format traderCanceledAll( "Trader %|| cancelled all %|| bid orders, %|| ask orders" );
const boost::format traderSelfMatch( "Trader %|| self-match prevention rejected %|| order id %|| "
                                     "matching with %|| order id %|| at price %||" );
const boost::format logOrderAlreadyExist( "Trader %|| adding order id %||, but it already exists" );
const boost::format logOrderDoesNotExist( "Trader %|| canceling order id %||, but it does not exists" );

} /* namespace message */


namespace attr
{
    const char* const loseConnection    = "loseConnection";
    const char* const write             = "write";
}


namespace side
{

const std::string buy   = "BUY";
const std::string sell  = "SELL";

const std::string bid   = "bid";
const std::string ask   = "ask";

const side_t bid_       = 1;
const side_t ask_       = 2;


/**
 * @brief FIXME
 *
 */
inline side_t opposite( const side_t side_ )
{
    switch( side_ )
    {
        case bid_: return ask_;
        case ask_: return bid_;
        default:   throw;
    }
}


/**
 * @brief FIXME
 *
 */
inline std::string toBuySell( const side_t side_ )
{
    switch( side_ )
    {
        case bid_: return buy;
        case ask_: return sell;
        default:   throw;
    }
}


/**
 * @brief FIXME
 *
 */
inline std::string toBidAsk( const side_t side_ )
{
    switch( side_ )
    {
        case bid_: return bid;
        case ask_: return ask;
        default:   throw;
    }
}


class WrongSide: public std::exception
{

};


} /* namespace side */


namespace report
{

const std::string new_   = "NEW";
const std::string cancel = "CANCELED";
const std::string fill   = "FILL";
const std::string err    = "ERROR";

} /* namespace report */


namespace strings
{

const std::string orderDoesNotExist     = "order does not exists";
const std::string orderAlreadyExist     = "order already exists";
const std::string orderInvalid          = "order is invalid";
const std::string orderSelfMatch        = "order self-match rejected";

const std::string jsonError             = "json decode error";

const std::string unknownMessage        = "unknown message";
const std::string unknownSide           = "unknown side";

} /* namespace strings */



namespace keys
{

const std::string message   = "message";
const std::string report    = "report";
const std::string price     = "price";
const std::string orderId   = "orderId";
const std::string quantity  = "quantity";
const std::string side      = "side";
const std::string text      = "text";

} /* namespace keys */


} /* namespace pyxchange */


#endif /* UTILS */


/* EOF */

