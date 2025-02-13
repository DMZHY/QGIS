/***************************************************************************
    qgsdamengconnpool.cpp
    ---------------------
    begin                : 2025/01/14
    copyright            : ( C ) 2025 by Haiyang Zhao
    email                : zhaohaiyang@dameng.com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   ( at your option ) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsdamengconnpool.h"
#include "qgsdamengconn.h"
#include "qgslogger.h"

QgsDamengConnPool *QgsDamengConnPool::sInstance = nullptr;

QgsDamengConnPool *QgsDamengConnPool::instance()
{
  if ( !sInstance )
    sInstance = new QgsDamengConnPool();
  return sInstance;
}

void QgsDamengConnPool::cleanupInstance()
{
  delete sInstance;
  sInstance = nullptr;
}

QgsDamengConnPool::QgsDamengConnPool() : QgsConnectionPool< QgsDamengConn *, QgsDamengConnPoolGroup >()
{
  QgsDebugCall;
}

QgsDamengConnPool::~QgsDamengConnPool()
{
  QgsDebugCall;
}

