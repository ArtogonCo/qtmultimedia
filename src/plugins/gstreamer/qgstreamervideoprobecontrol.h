/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGSTREAMERVIDEOPROBECONTROL_H
#define QGSTREAMERVIDEOPROBECONTROL_H

#include <gst/gst.h>
#include <qmediavideoprobecontrol.h>
#include <QtCore/qmutex.h>
#include "qvideoframe.h"

QT_BEGIN_NAMESPACE

class QGstreamerVideoProbeControl : public QMediaVideoProbeControl
{
    Q_OBJECT
public:
    explicit QGstreamerVideoProbeControl(QObject *parent);
    virtual ~QGstreamerVideoProbeControl();

    void bufferProbed(GstBuffer* buffer);
    void startFlushing();
    void stopFlushing();

private slots:
    void frameProbed();

private:
    bool m_flushing;
    bool m_frameProbed; // true if at least one frame was probed
    QVideoFrame m_pendingFrame;
    QMutex m_frameMutex;
};

QT_END_NAMESPACE

#endif // QGSTREAMERVIDEOPROBECONTROL_H