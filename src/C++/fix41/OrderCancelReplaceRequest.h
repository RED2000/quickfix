#ifndef FIX41_ORDERCANCELREPLACEREQUEST_H
#define FIX41_ORDERCANCELREPLACEREQUEST_H

#include "Message.h"

namespace FIX41
{

  class OrderCancelReplaceRequest : public Message
  {
  public:
    OrderCancelReplaceRequest() : Message(MsgType()) {}
    OrderCancelReplaceRequest(const Message& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("G"); }

    OrderCancelReplaceRequest(
      const FIX::OrigClOrdID& aOrigClOrdID,
      const FIX::ClOrdID& aClOrdID,
      const FIX::HandlInst& aHandlInst,
      const FIX::Symbol& aSymbol,
      const FIX::Side& aSide,
      const FIX::OrdType& aOrdType )
    : Message(MsgType())
    {
      set(aOrigClOrdID);
      set(aClOrdID);
      set(aHandlInst);
      set(aSymbol);
      set(aSide);
      set(aOrdType);
    }

    FIELD_SET(*this, FIX::OrderID);
    FIELD_SET(*this, FIX::ClientID);
    FIELD_SET(*this, FIX::ExecBroker);
    FIELD_SET(*this, FIX::OrigClOrdID);
    FIELD_SET(*this, FIX::ClOrdID);
    FIELD_SET(*this, FIX::ListID);
    FIELD_SET(*this, FIX::Account);
    FIELD_SET(*this, FIX::SettlmntTyp);
    FIELD_SET(*this, FIX::FutSettDate);
    FIELD_SET(*this, FIX::HandlInst);
    FIELD_SET(*this, FIX::ExecInst);
    FIELD_SET(*this, FIX::MinQty);
    FIELD_SET(*this, FIX::MaxFloor);
    FIELD_SET(*this, FIX::ExDestination);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::SymbolSfx);
    FIELD_SET(*this, FIX::SecurityID);
    FIELD_SET(*this, FIX::IDSource);
    FIELD_SET(*this, FIX::SecurityType);
    FIELD_SET(*this, FIX::MaturityMonthYear);
    FIELD_SET(*this, FIX::MaturityDay);
    FIELD_SET(*this, FIX::PutOrCall);
    FIELD_SET(*this, FIX::StrikePrice);
    FIELD_SET(*this, FIX::OptAttribute);
    FIELD_SET(*this, FIX::SecurityExchange);
    FIELD_SET(*this, FIX::Issuer);
    FIELD_SET(*this, FIX::SecurityDesc);
    FIELD_SET(*this, FIX::Side);
    FIELD_SET(*this, FIX::OrderQty);
    FIELD_SET(*this, FIX::CashOrderQty);
    FIELD_SET(*this, FIX::OrdType);
    FIELD_SET(*this, FIX::Price);
    FIELD_SET(*this, FIX::StopPx);
    FIELD_SET(*this, FIX::PegDifference);
    FIELD_SET(*this, FIX::Currency);
    FIELD_SET(*this, FIX::TimeInForce);
    FIELD_SET(*this, FIX::ExpireTime);
    FIELD_SET(*this, FIX::Commission);
    FIELD_SET(*this, FIX::CommType);
    FIELD_SET(*this, FIX::Rule80A);
    FIELD_SET(*this, FIX::ForexReq);
    FIELD_SET(*this, FIX::SettlCurrency);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::FutSettDate2);
    FIELD_SET(*this, FIX::OrderQty2);
    FIELD_SET(*this, FIX::OpenClose);
    FIELD_SET(*this, FIX::CoveredOrUncovered);
    FIELD_SET(*this, FIX::CustomerOrFirm);
    FIELD_SET(*this, FIX::MaxShow);
    FIELD_SET(*this, FIX::LocateReqd);
  };

}

#endif
