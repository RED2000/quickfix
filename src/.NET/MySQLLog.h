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

#ifdef HAVE_MYSQL
#pragma once

using namespace System;

#include "quickfix_net.h"

#include "CPPLog.h"
#include "LogFactory.h"
#include "MessageStore.h"
#include "SessionID.h"
#include "SessionSettings.h"
#include "quickfix/MySQLLog.h"
#include "quickfix/Settings.h"
#include "vcclr.h"

namespace QuickFix
{
public __gc class MySQLLog : public CPPLog
{
public:
  MySQLLog( FIX::Log* pUnmanaged )
  {
    m_pUnmanaged = pUnmanaged;
  }
};

public __gc class MySQLLogFactory : public LogFactory
{
public:
  MySQLLogFactory( SessionSettings* settings )
  {
    m_pUnmanaged = new FIX::MySQLLogFactory(settings->unmanaged());
  }

  ~MySQLLogFactory() { delete m_pUnmanaged; }

  Log* create()
  {
    return new MySQLLog(m_pUnmanaged->create());
  }

  Log* create( SessionID* sessionID )
  {
    return new MySQLLog(m_pUnmanaged->create(sessionID->unmanaged()));
  }

private:
  FIX::MySQLLogFactory* m_pUnmanaged;
};
}

#endif //HAVE_MYSQL
