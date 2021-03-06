/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) quickfixengine.org  All rights reserved.
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifdef HAVE_ODBC
#pragma once

using namespace System;

#include "quickfix_net.h"

#include "CPPLog.h"
#include "LogFactory.h"
#include "MessageStore.h"
#include "SessionID.h"
#include "SessionSettings.h"
#include "quickfix/OdbcLog.h"
#include "quickfix/Settings.h"
#include "vcclr.h"

namespace QuickFix
{
public __gc class OdbcLog : public CPPLog
{
public:
  OdbcLog( FIX::Log* pUnmanaged )
  {
    m_pUnmanaged = pUnmanaged;
  }
};

public __gc class OdbcLogFactory : public LogFactory
{
public:
  OdbcLogFactory( SessionSettings* settings )
  {
    m_pUnmanaged = new FIX::OdbcLogFactory(settings->unmanaged());
  }

  ~OdbcLogFactory() { delete m_pUnmanaged; }

  Log* create()
  {
    return new OdbcLog(m_pUnmanaged->create());
  }

  Log* create( SessionID* sessionID )
  {
    return new OdbcLog(m_pUnmanaged->create(sessionID->unmanaged()));
  }

private:
  FIX::OdbcLogFactory* m_pUnmanaged;
};
}

#endif //HAVE_Odbc
