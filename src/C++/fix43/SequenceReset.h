#ifndef FIX43_SEQUENCERESET_H
#define FIX43_SEQUENCERESET_H

#include "Message.h"

namespace FIX43
{

  class SequenceReset : public Message
  {
  public:
    SequenceReset() : Message(MsgType()) {}
    SequenceReset(const Message& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("4"); }

    SequenceReset(
      const FIX::NewSeqNo& aNewSeqNo )
    : Message(MsgType())
    {
      set(aNewSeqNo);
    }

    FIELD_SET(*this, FIX::GapFillFlag);
    FIELD_SET(*this, FIX::NewSeqNo);
  };

}

#endif
